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

#ifndef MIDIENGINE_H
#define MIDIENGINE_H

#include <alsa/asoundlib.h>

#include <QList>

class MidiEngine
{

public:
    MidiEngine();
    void Init();
    void Clean();

    bool IsInitialized() const {return initOK;}

    const QStringList& getSeqPortNames() const {return SeqPortNames;}

    void SelectALSAClient(int cId);
    void SendSysEx(uint8_t *data,uint8_t len) const;

private:
    // Device instance variables.
    snd_seq_t *pAlsaSeq;
    int iAlsaClient;
    int iAlsaClientPort;
    int iSelectedAlsaPort;
    bool initOK = false;

    QStringList SeqPortNames;
    QList<snd_seq_addr_t> SeqDest;

};

#endif // MIDIENGINE_H
