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
    : Integra7ParameterSet{parent,o1,o2,o3}{}

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
