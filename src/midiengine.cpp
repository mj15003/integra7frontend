/*************************************************************************
   Copyright (C) 2023-2024  Miroslav Kovac

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <https://www.gnu.org/licenses/>
*************************************************************************/

#include "midiengine.h"
#include "QString"

MidiEngine::MidiEngine()
{
    pAlsaSeq = nullptr;
    iAlsaClient = -1;
    iSelectedAlsaPort = -1;
}

MidiEngine::~MidiEngine()
{
    if (pMidiInputThread) delete pMidiInputThread;
}

void MidiEngine::Init()
{
    initOK = false;

    if (snd_seq_open(&pAlsaSeq, "default",
                     SND_SEQ_OPEN_DUPLEX,0) < 0)
        return;
    if (pAlsaSeq == nullptr)
        return;

    snd_seq_set_client_name(pAlsaSeq,"Integra7Frontend");

    iAlsaClient = snd_seq_client_id(pAlsaSeq);

    snd_seq_client_info_t *cinfo;
    snd_seq_port_info_t *pinfo;

    snd_seq_client_info_alloca(&cinfo);
    snd_seq_port_info_alloca(&pinfo);

    snd_seq_client_info_set_client(cinfo, -1);
    while (snd_seq_query_next_client(pAlsaSeq, cinfo) >= 0) {
        int client = snd_seq_client_info_get_client(cinfo);

        QString ClientName = snd_seq_client_info_get_name(cinfo);

        snd_seq_port_info_set_client(pinfo, client);
        snd_seq_port_info_set_port(pinfo, -1);
        while (snd_seq_query_next_port(pAlsaSeq, pinfo) >= 0) {
            /* port must understand MIDI messages */
            if (!(snd_seq_port_info_get_type(pinfo)
                  & SND_SEQ_PORT_TYPE_MIDI_GENERIC))
                continue;
            /* we need both WRITE and SUBS_WRITE */
            if ((snd_seq_port_info_get_capability(pinfo)
                 & (SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE))
                != (SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE))
                continue;

            QString PortName = snd_seq_port_info_get_name(pinfo);

            QString PortLabel = QString(ClientName) + ":" + QString(PortName);

            SeqPortNames.append(PortLabel);
            SeqDest.append(*snd_seq_port_info_get_addr(pinfo));
        }
    }

    iAlsaClientPort = snd_seq_create_simple_port(pAlsaSeq,"Port-0",
                                                 SND_SEQ_PORT_CAP_READ | SND_SEQ_PORT_CAP_SUBS_READ |
                                                 SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE |
                                                 SND_SEQ_PORT_CAP_DUPLEX,
                                                 SND_SEQ_PORT_TYPE_MIDI_GENERIC | SND_SEQ_PORT_TYPE_SOFTWARE |
                                                 SND_SEQ_PORT_TYPE_MIDI_GS);

    pMidiInputThread = new MidiInputThread(pAlsaSeq);

    initOK = true;
}

void MidiEngine::Stop()
{
    pMidiInputThread->terminate();
    pMidiInputThread->wait(100);
    snd_seq_close(pAlsaSeq);
}

void MidiEngine::SelectALSAClient(int cId)
{
    snd_seq_addr_t dest;

    if (iSelectedAlsaPort > -1)
    {
    //disconnect from previous destination
        dest = SeqDest.at(iSelectedAlsaPort);

        snd_seq_disconnect_to(pAlsaSeq,iAlsaClientPort,dest.client,dest.port);
        snd_seq_disconnect_from(pAlsaSeq,iAlsaClientPort,dest.client,dest.port);
    }

    iSelectedAlsaPort = cId;

    //connect to a new destination
    dest = SeqDest.at(iSelectedAlsaPort);
    snd_seq_connect_to(pAlsaSeq,iAlsaClientPort,dest.client,dest.port);
    snd_seq_connect_from(pAlsaSeq,iAlsaClientPort,dest.client,dest.port);    
}

void MidiEngine::SendSysEx(uint8_t *data, uint8_t len)
{
    snd_seq_event_t ev;

    snd_seq_ev_clear(&ev);
    snd_seq_ev_set_source(&ev, iAlsaClientPort);
    snd_seq_ev_set_subs(&ev);
    snd_seq_ev_set_direct(&ev);

    snd_seq_ev_set_sysex(&ev,len,data);

    snd_seq_event_output(pAlsaSeq, &ev);
    snd_seq_drain_output(pAlsaSeq);    
}

void MidiInputThread::run() {

    struct pollfd *pfds;
    int npfds;

    npfds = snd_seq_poll_descriptors_count(pAlsaSeq, POLLIN);
    pfds = (struct pollfd *)alloca(sizeof(*pfds) * npfds);

    for (;;) {
        snd_seq_poll_descriptors(pAlsaSeq, pfds, npfds, POLLIN);
        if (poll(pfds, npfds, -1) < 0)
            break;
        for (;;) {

            snd_seq_event_input(pAlsaSeq, &ev);

            if (ev->type == SND_SEQ_EVENT_SYSEX)
                emit dataReady((uint8_t *)ev->data.ext.ptr,ev->data.ext.len);
        }
    }
}
