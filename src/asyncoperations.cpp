/*************************************************************************
   Copyright (C) 2024 Miroslav Kovac

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

#include "integra7setup.h"
#include "integra7systemcommon.h"
#include "asyncoperations.h"

DumpFileReader::DumpFileReader(Integra7Device *pdev, integra7MainWindow *pwin, QString &fname)
{
    dev = pdev;
    win = pwin;
    fileName = fname;
}

void DumpFileReader::run()
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);

    uint8_t *rdata = new uint8_t[file.size()];

    //read the content of file at once into array
    //split into SysExes and send each separately into the device with defined delay
    //then request dump read from device to synchornize UI

    int nrd = file.read((char*)rdata,file.size());
    int len = 0;
    int start = 0;

    for (int c=0;c<nrd;++c) {
        if (rdata[c] == 0xF0)
        {
            len = 1;
            start = c;
        }
        else if (rdata[c] == 0xF7)
        {
            ++len;
            dev->SendFullSysEx(rdata+start,len);
            QThread::msleep(dev->GetMsgDelay());
        }
        else ++len;
    }

    file.close();
    delete[] rdata;

    win->BulkDumpRequest();
}

ReadRequest::ReadRequest(Integra7Device *i7dev)
{
    dev = i7dev;
}

ReadRequest::ReadRequest(Integra7Device *i7dev, const uint8_t *rqdata)
{
    dev = i7dev;

    for (int k=0;k<8;k++) req[k] = rqdata[k];

    RequestDataSpecified = true;
}

void ReadRequest::run()
{
    if (RequestDataSpecified)
    {
        QThread::msleep(dev->GetMsgDelay());
        dev->DataRequest(req);
    }
    else
    {
        dev->Setup->GetRequestArray(req);
        dev->DataRequest(req);

        QThread::msleep(dev->GetMsgDelay()); //give it a time to process the response

        dev->SystemCommon->GetRequestArray(req);
        dev->DataRequest(req);

        QThread::msleep(dev->GetMsgDelay()); //give it a time to process the response

        //Request whole StudioSet in single call
        req[0] = 0x18;
        req[1] = 0;
        req[2] = 0;
        req[3] = 0;

        req[4] = 0;
        req[5] = 0;
        req[6] = 0x60;
        req[7] = 0;

        dev->DataRequest(req);

        QThread::msleep(dev->GetMsgDelay());

        //Request Tone data for each part

        uint8_t a1 = 0x19;
        uint8_t a2 = 0x00;

        for (int p=0;p<16;++p) {

            req[0] = a1;
            req[1] = a2;
            req[2] = 0;
            req[3] = 0;

            req[4] = 0;
            req[5] = 0x20;
            req[6] = 0;
            req[7] = 0;

            dev->DataRequest(req);

            QThread::msleep(dev->GetMsgDelay());

            if (a2 == 0x60) {
                ++a1;
                a2=0;
            } else a2+=0x20;
        }
    }
}
