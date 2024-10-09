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

#include "integra7chorus.h"

Integra7Chorus::Integra7Chorus(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
    : Integra7ParameterSet{parent,o1,o2,o3}
{
    data[0x00] = 0;
    data[0x01] = 0;
    data[0x03] = 0;
    data[0x04] = 8;
    data[0x05] = 0;
    data[0x06] = 0;
    data[0x07] = 0;
    data[0x08] = 8;
    data[0x09] = 0;
    data[0x0A] = 0;
    data[0x0B] = 0;
    data[0x0C] = 8;
    data[0x0D] = 0;
    data[0x0E] = 0;
    data[0x0F] = 0;
    data[0x10] = 8;
    data[0x11] = 0;
    data[0x12] = 0;
    data[0x13] = 0;
    data[0x14] = 8;
    data[0x15] = 0;
    data[0x16] = 0;
    data[0x17] = 0;
    data[0x18] = 8;
    data[0x19] = 0;
    data[0x1A] = 0;
    data[0x1B] = 0;
    data[0x1C] = 8;
    data[0x1D] = 0;
    data[0x1E] = 0;
    data[0x1F] = 0;
    data[0x20] = 8;
    data[0x21] = 0;
    data[0x22] = 0;
    data[0x23] = 0;
    data[0x24] = 8;
    data[0x25] = 0;
    data[0x26] = 0;
    data[0x27] = 0;
    data[0x28] = 8;
    data[0x29] = 0;
    data[0x2A] = 0;
    data[0x2B] = 0;
    data[0x2C] = 8;
    data[0x2D] = 0;
    data[0x2E] = 0;
    data[0x2F] = 0;
    data[0x30] = 8;
    data[0x31] = 0;
    data[0x32] = 0;
    data[0x33] = 0;
    data[0x34] = 8;
    data[0x35] = 0;
    data[0x36] = 0;
    data[0x37] = 0;
    data[0x38] = 8;
    data[0x39] = 0;
    data[0x3A] = 0;
    data[0x3B] = 0;
    data[0x3C] = 8;
    data[0x3D] = 0;
    data[0x3E] = 0;
    data[0x3F] = 0;
    data[0x40] = 8;
    data[0x41] = 0;
    data[0x42] = 0;
    data[0x43] = 0;
    data[0x44] = 8;
    data[0x45] = 0;
    data[0x46] = 0;
    data[0x47] = 0;
    data[0x48] = 8;
    data[0x49] = 0;
    data[0x4A] = 0;
    data[0x4B] = 0;
    data[0x4C] = 8;
    data[0x4D] = 0;
    data[0x4E] = 0;
    data[0x4F] = 0;
    data[0x50] = 8;
    data[0x51] = 0;
    data[0x52] = 0;
    data[0x53] = 0;
}

QStringList &Integra7Chorus::RateHzList()
{
    static QList<QString> list(200);
    double v1 = 0.0;

    if (list.at(0).isEmpty()) {
        for (int i=0;i<list.size();i++) list[i] = QString::number(v1+=0.05,'f',2);
    }

    return list;
}

void Integra7Chorus::EmitSignal(uint8_t a, int v)
{
    if (a < 0x4) {
        //General parameters
        switch (a) {
        case 0x0:
            emit ChorusType(v);
            break;
        case 0x1:
            emit ChorusLevel(v);
            break;
        case 0x3:
            emit ChorusOutputSelect(v);
            break;
        default:
            break;
        }
    } else if (data[0] == 1) {
        //Chorus Type
        switch (a) {
        case 0x04:
            emit ChorusFilterType(v);
            break;
        case 0x08:
            emit ChorusCutoffFreq(getChorusCutoffFreq());
            break;
        case 0x0C:
            emit ChorusPreDelay(getChorusPreDelay());
            break;
        case 0x10:
            emit ChorusRateType(v);
            break;
        case 0x14:
            emit ChorusRateHz(getChorusRateHz());
            break;
        case 0x18:
            emit ChorusRateNote(getChorusRateNote());
            break;
        case 0x1C:
            emit ChorusDepth(getChorusDepth());
            break;
        case 0x20:
            emit ChorusPhase(getChorusPhase());
            break;
        case 0x24:
            emit ChorusFeedback(getChorusFeedback());
            break;
        default:
            break;
        }
    } else if (data[0] == 2) {
        //Delay Type
        switch (a) {
        case 0x04:
            emit DelayDelayLeft(v);
            break;
        case 0x08:
            emit DelayDelayLeftMS(getDelayDelayLeftMS());
            break;
        case 0x0C:
            emit DelayDelayLeftNote(getDelayDelayLeftNote());
            break;
        case 0x10:
            emit DelayDelayRight(v);
            break;
        case 0x14:
            emit DelayDelayRightMS(getDelayDelayRightMS());
            break;
        case 0x18:
            emit DelayDelayRightNote(getDelayDelayRightNote());
            break;
        case 0x1C:
            emit DelayDelayCenter(v);
            break;
        case 0x20:
            emit DelayDelayCenterMS(getDelayDelayCenterMS());
            break;
        case 0x24:
            emit DelayDelayCenterNote(getDelayDelayCenterNote());
            break;
        case 0x28:
            emit DelayFeedback(getDelayFeedback());
            break;
        case 0x2C:
            emit DelayHFDamp(getDelayHFDamp());
            break;
        case 0x30:
            emit DelayLeftLevel(getDelayLeftLevel());
            break;
        case 0x34:
            emit DelayRightLevel(getDelayRightLevel());
            break;
        case 0x38:
            emit DelayCenterLevel(getDelayCenterLevel());
            break;
        default:
            break;
        }
    } else if (data[0] == 3) {
        //GM2 Chorus
        switch (a) {
        case 0x04:
            emit GM2ChorusPreLPF(v);
            break;
        case 0x08:
            emit GM2ChorusLevel(getGM2ChorusLevel());
            break;
        case 0x0C:
            emit GM2ChorusFeedback(getGM2ChorusFeedback());
            break;
        case 0x10:
            emit GM2ChorusDelay(getGM2ChorusDelay());
            break;
        case 0x14:
            emit GM2ChorusRate(getGM2ChorusRate());
            break;
        case 0x18:
            emit GM2ChorusDepth(getChorusDepth());
            break;
        default:
            break;
        }
    }
}

void Integra7Chorus::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a < 0x04){
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        } else {
            data[a] = rdata[r++];
            data[a+1] = rdata[r++];
            data[a+2] = rdata[r++];
            data[a+3] = rdata[r++];
            EmitSignal(a,data[a+3]);
            a+=4;
        }
    }
}
