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

#include "integra7systemcommon.h"

Integra7SystemCommon::Integra7SystemCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
    : Integra7ParameterSet{parent,o1,o2,o3}
{
    data[0x00] = 0;
    data[0x01] = 4;
    data[0x02] = 0;
    data[0x03] = 0;
    data[0x04] = 64;
    data[0x05] = 0;
    data[0x06] = 0;
    data[0x11] = 0;
    data[0x20] = 0;
    data[0x21] = 0;
    data[0x22] = 0;
    data[0x23] = 0;
    data[0x24] = 0;
    data[0x25] = 0;
    data[0x26] = 8;
    data[0x27] = 7;
    data[0x28] = 0;
    data[0x29] = 0;
    data[0x2A] = 0;
    data[0x2B] = 0;
    data[0x2C] = 0;
    data[0x2D] = 0;
}

void Integra7SystemCommon::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x0:
        emit MasterTune(v);
        emit MasterTuneCents(getMasterTuneCents());
        emit MasterTuneHz(getMasterTuneHz());
        break;
    case 0x04:
        emit MasterKeyShift(getMasterKeyShift());
        break;
    case 0x05:
        emit MasterLevel(v);
        break;
    case 0x06:
        emit ScaleTuneSwitch(v);
        break;
    case 0x11:
        emit StudioSetControlChannel(v);
        break;
    case 0x20:
        v<32?emit SystemControl1Source(v):emit SystemControl1Source(v-1);
        break;
    case 0x21:
        v<32?emit SystemControl2Source(v):emit SystemControl2Source(v-1);
        break;
    case 0x22:
        v<32?emit SystemControl3Source(v):emit SystemControl3Source(v-1);
        break;
    case 0x23:
        v<32?emit SystemControl4Source(v):emit SystemControl4Source(v-1);
        break;
    case 0x24:
        emit ControlSource(v);
        break;
    case 0x25:
        emit SystemClockSource(v);
        break;
    case 0x26:
        emit SystemTempo(v);
        break;
    case 0x28:
        emit TempoAssignSource(v);
        break;
    case 0x29:
        emit ReceiveProgramChange(v);
        break;
    case 0x2A:
        emit ReceiveBankSelect(v);
        break;
    case 0x2B:
        emit sig51CHCenterSpeakerSwitch(v);
        break;
    case 0x2C:
        emit sig51CHSubWooferSwitch(v);
        break;
    case 0x2D:
        emit sig2CHOutputMode(v);
        break;
    default:
        break;
    }
}

void Integra7SystemCommon::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a == 0x0){
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x0,getMasterTune());
        } else if (a == 0x26) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x26,getSystemTempo());
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}
