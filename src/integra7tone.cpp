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

#include "integra7tone.h"
#include "asyncoperations.h"

Integra7Tone::Integra7Tone(Integra7Device *parent,uint8_t a0, uint8_t a1) {
    address[0] = a0;
    address[1] = a1;
    pIntegraDev = parent;

    PCMSynthToneCommon = new Integra7PCMSynthToneCommon(parent,a0,0,0);
    PCMSynthToneCommonMFX = new Integra7ToneMFX(parent,a0,a1,0x02);
    PCMSynthTonePMT = new Integra7PCMSynthTonePMT(parent,a0,a1,0x10);
    PCMSynthTonePartial[0] = new Integra7PCMSynthTonePartial(parent,a0,a1,0x20);
    PCMSynthTonePartial[1] = new Integra7PCMSynthTonePartial(parent,a0,a1,0x22);
    PCMSynthTonePartial[2] = new Integra7PCMSynthTonePartial(parent,a0,a1,0x24);
    PCMSynthTonePartial[3] = new Integra7PCMSynthTonePartial(parent,a0,a1,0x26);
    PCMSynthToneCommon2 = new Integra7PCMSynthToneCommon2(parent,a0,a1,0x30);

    SNSynthToneCommon = new Integra7SNSynthToneCommon(parent,a0,a1+0x01,0);
    SNSynthToneCommonMFX = new Integra7ToneMFX(parent,a0,a1+0x01,0x02);
    SNSynthTonePartial[0] = new Integra7SNSynthTonePartial(parent,a0,a1+0x01,0x20);
    SNSynthTonePartial[1] = new Integra7SNSynthTonePartial(parent,a0,a1+0x01,0x21);
    SNSynthTonePartial[2] = new Integra7SNSynthTonePartial(parent,a0,a1+0x01,0x22);

    SNAcousticToneCommon = new Integra7SNAcousticToneCommon(parent,a0,a1+2,0);
    SNAcousticToneMFX = new Integra7ToneMFX(parent,a0,a1+0x02,0x02);

    SNDrumKitCommon = new Integra7SNDrumKitCommon(parent,a0,a1+0x03,0);
    SNDrumKitMFX = new Integra7ToneMFX(parent,a0,a1+0x03,0x02);
    SNDrumKitCommonCompEQ = new Integra7DrumCompEQ(parent,a0,a1+0x03,0x08);

    uint8_t o1 = 0x10;
    for (int i=0;i<62;++i){
        SNDrumKitNote[i] = new Integra7SNDrumKitNote(parent,a0,a1+0x03,o1++);
    }

    PCMDrumKitCommon = new Integra7PCMDrumKitCommon(parent,a0,a1+0x10,0);
    PCMDrumKitCommonMFX = new Integra7ToneMFX(parent,a0,a1+0x10,0x02);
    PCMDrumKitCommonCompEQ = new Integra7DrumCompEQ(parent,a0,a1+0x10,0x08);

    o1 = 0;
    uint8_t o2 = 0x10;
    for (int i=0;i<88;++i){
        PCMDrumKitPartial[i] = new Integra7PCMDrumKitPartial(parent,a0,a1+0x10+o1,o2);
        if (o2 == 0x7E){
            ++o1;
            o2 = 0;
        } else o2+=2;
    }

    PCMDrumKitCommon2 = new Integra7PCMDrumKitCommon2(parent,a0,a1+0x12,0);
}

Integra7Tone::~Integra7Tone()
{
    delete PCMDrumKitCommon2;

    for (int i=0;i<88;++i) delete PCMDrumKitPartial[i];

    delete PCMDrumKitCommonCompEQ;
    delete PCMDrumKitCommonMFX;
    delete PCMDrumKitCommon;

    for (int i=0;i<62;++i) delete SNDrumKitNote[i];

    delete SNDrumKitCommonCompEQ;
    delete SNDrumKitMFX;
    delete SNDrumKitCommon;

    delete SNAcousticToneMFX;
    delete SNAcousticToneCommon;

    delete SNSynthTonePartial[2];
    delete SNSynthTonePartial[1];
    delete SNSynthTonePartial[0];
    delete SNSynthToneCommonMFX;
    delete SNSynthToneCommon;

    delete PCMSynthToneCommon2;
    delete PCMSynthTonePartial[3];
    delete PCMSynthTonePartial[2];
    delete PCMSynthTonePartial[1];
    delete PCMSynthTonePartial[0];
    delete PCMSynthTonePMT;
    delete PCMSynthToneCommonMFX;
    delete PCMSynthToneCommon;
}

void Integra7Tone::ReceiveData(const uint8_t *data, int len)
{
    const uint8_t *rdata = data + 11;

    uint8_t a0 = data[10];
    uint8_t a1 = data[9];

    uint8_t toff = data[8] % 0x20;

    int dlen = len - 13;

    switch (toff) {
    case 0x00:
        switch (a1) {
        case 0x00:
            PCMSynthToneCommon->DataReceive(rdata,a0,dlen);
            break;
        case 0x02:
            PCMSynthToneCommonMFX->DataReceive(rdata,a0,dlen);
            break;
        case 0x10:
            PCMSynthTonePMT->DataReceive(rdata,a0,dlen);
            break;
        case 0x20:
            PCMSynthTonePartial[0]->DataReceive(rdata,a0,dlen);
            break;
        case 0x22:
            PCMSynthTonePartial[1]->DataReceive(rdata,a0,dlen);
            break;
        case 0x24:
            PCMSynthTonePartial[2]->DataReceive(rdata,a0,dlen);
            break;
        case 0x26:
            PCMSynthTonePartial[3]->DataReceive(rdata,a0,dlen);
            break;
        case 0x30:
            PCMSynthToneCommon2->DataReceive(rdata,a0,dlen);
            break;
        default:
            break;
        }
        break;
    case 0x01:
        switch (a1) {
        case 0x00:
            SNSynthToneCommon->DataReceive(rdata,a0,dlen);
            break;
        case 0x02:
            SNSynthToneCommonMFX->DataReceive(rdata,a0,dlen);
            break;
        case 0x20:
            SNSynthTonePartial[0]->DataReceive(rdata,a0,dlen);
            break;
        case 0x21:
            SNSynthTonePartial[1]->DataReceive(rdata,a0,dlen);
            break;
        case 0x22:
            SNSynthTonePartial[2]->DataReceive(rdata,a0,dlen);
            break;
        default:
            break;
        }
        break;
    case 0x02:
        if (a1 == 0x00) SNAcousticToneCommon->DataReceive(rdata,a0,dlen);
        if (a1 == 0x02) SNAcousticToneMFX->DataReceive(rdata,a0,dlen);
        break;
    case 0x03:
        if (a1 == 0x00) SNDrumKitCommon->DataReceive(rdata,a0,dlen);
        if (a1 == 0x02) SNDrumKitMFX->DataReceive(rdata,a0,dlen);
        if (a1 == 0x08) SNDrumKitCommonCompEQ->DataReceive(rdata,a0,dlen);
        if (a1 >= 0x10 && a1 <= 0x4D)
            SNDrumKitNote[a1-0x10]->DataReceive(rdata,a0,dlen);
        break;
    case 0x10:
        if (a1 == 0x00) PCMDrumKitCommon->DataReceive(rdata,a0,dlen);
        if (a1 == 0x02) PCMDrumKitCommonMFX->DataReceive(rdata,a0,dlen);
        if (a1 == 0x08) PCMDrumKitCommonCompEQ->DataReceive(rdata,a0,dlen);
        if (a1 >= 0x10 && a1 <= 0x7E)
            PCMDrumKitPartial[(a1-0x10)/2]->DataReceive(rdata,a0,dlen);
        break;
    case 0x11:
        if (a1 <= 0x3E)
            PCMDrumKitPartial[56+a1/2]->DataReceive(rdata,a0,dlen);
        break;
    case 0x12:
        if (a1 == 0x00) PCMDrumKitCommon2->DataReceive(rdata,a0,dlen);
        break;
    default:
        break;
    }
}

int Integra7Tone::OutputDump(uint8_t *data, int *len)
{
    if (ToneType == "PCM-S") {
        switch (outcnt) {
        case 0:
            *len = PCMSynthToneCommon->OutputDump(data);
            return ++outcnt;
        case 1:
            *len = PCMSynthToneCommonMFX->OutputDump(data);
            return ++outcnt;
        case 2:
            *len = PCMSynthTonePMT->OutputDump(data);
            return ++outcnt;
        case 3:
            *len = PCMSynthTonePartial[0]->OutputDump(data);
            return ++outcnt;
        case 4:
            *len = PCMSynthTonePartial[1]->OutputDump(data);
            return ++outcnt;
        case 5:
            *len = PCMSynthTonePartial[2]->OutputDump(data);
            return ++outcnt;
        case 6:
            *len = PCMSynthTonePartial[3]->OutputDump(data);
            return ++outcnt;
        case 7:
            *len = PCMSynthToneCommon2->OutputDump(data);
            return ++outcnt;
        default:
            outcnt = 0;
            return outcnt;
        }
    } else if (ToneType == "SN-S") {
        switch (outcnt) {
        case 0:
            *len = SNSynthToneCommon->OutputDump(data);
            return ++outcnt;
        case 1:
            *len = SNSynthToneCommonMFX->OutputDump(data);
            return ++outcnt;
        case 2:
            *len = SNSynthTonePartial[0]->OutputDump(data);
            return ++outcnt;
        case 3:
            *len = SNSynthTonePartial[1]->OutputDump(data);
            return ++outcnt;
        case 4:
            *len = SNSynthTonePartial[2]->OutputDump(data);
            return ++outcnt;
        default:
            outcnt = 0;
            return outcnt;
        }
    } else if (ToneType == "SN-A") {
        switch (outcnt) {
        case 0:
            *len = SNAcousticToneCommon->OutputDump(data);
            return ++outcnt;
        case 1:
            *len = SNAcousticToneMFX->OutputDump(data);
            return ++outcnt;
        default:
            outcnt = 0;
            return outcnt;
        }
    } else if (ToneType == "SN-D") {
        switch (outcnt) {
        case 0:
            *len = SNDrumKitCommon->OutputDump(data);
            return ++outcnt;
        case 1:
            *len = SNDrumKitMFX->OutputDump(data);
            return ++outcnt;
        case 2:
            *len = SNDrumKitCommonCompEQ->OutputDump(data);
            return ++outcnt;
        default:
            *len = SNDrumKitNote[outcnt-3]->OutputDump(data);
            return ++outcnt;
        case 65:
            outcnt = 0;
            return outcnt;
        }
    } else if (ToneType == "PCM-D") {
        switch (outcnt) {
        case 0:
            *len = PCMDrumKitCommon->OutputDump(data);
            return ++outcnt;
        case 1:
            *len = PCMDrumKitCommonMFX->OutputDump(data);
            return ++outcnt;
        case 2:
            *len = PCMDrumKitCommonCompEQ->OutputDump(data);
            return ++outcnt;
        default:
            *len = PCMDrumKitPartial[outcnt-3]->OutputDump(data);
            return ++outcnt;
        case 91:
            *len = PCMDrumKitCommon2->OutputDump(data);
            return ++outcnt;
        case 92:
            outcnt = 0;
            return outcnt;
        }
    }
    return 0;
}

void Integra7Tone::TriggerSignals(const QString &type, int drumnote)
{
    if (type == "PCM-S") {

        PCMSynthToneCommon->TriggerAllSignals();
        PCMSynthToneCommonMFX->TriggerAllSignals();
        PCMSynthTonePMT->TriggerAllSignals();
        PCMSynthTonePartial[0]->TriggerAllSignals();
        PCMSynthTonePartial[1]->TriggerAllSignals();
        PCMSynthTonePartial[2]->TriggerAllSignals();
        PCMSynthTonePartial[3]->TriggerAllSignals();
        PCMSynthToneCommon2->TriggerAllSignals();

    } else if (type == "SN-S") {

        SNSynthToneCommon->TriggerAllSignals();
        SNSynthToneCommonMFX->TriggerAllSignals();
        SNSynthTonePartial[0]->TriggerAllSignals();
        SNSynthTonePartial[1]->TriggerAllSignals();
        SNSynthTonePartial[2]->TriggerAllSignals();

    } else if (type == "SN-A") {

        SNAcousticToneCommon->TriggerAllSignals();
        SNAcousticToneMFX->TriggerAllSignals();

    } else if (type == "SN-D") {

        SNDrumKitCommon->TriggerAllSignals();
        SNDrumKitMFX->TriggerAllSignals();
        SNDrumKitCommonCompEQ->TriggerAllSignals();
        SNDrumKitNote[drumnote]->TriggerAllSignals();

    } else if (type == "PCM-D") {

        PCMDrumKitCommon->TriggerAllSignals();
        PCMDrumKitCommonMFX->TriggerAllSignals();
        PCMDrumKitCommonCompEQ->TriggerAllSignals();
        PCMDrumKitPartial[drumnote]->TriggerAllSignals();
        PCMDrumKitCommon2->TriggerAllSignals();
    }
}

void Integra7Tone::RequestData()
{
    uint8_t req[8];

    req[0] = address[0];
    req[1] = address[1];
    req[2] = 0;
    req[3] = 0;

    req[4] = 0;
    req[5] = 0x20;
    req[6] = 0;
    req[7] = 0;

    ReadRequest *RR = new ReadRequest(pIntegraDev,req);
    QThreadPool::globalInstance()->start(RR);
}
void Integra7Tone::setToneType(const QString &ts)
{
    ToneType = ts;
    outcnt = 0;
}
