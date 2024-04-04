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
    if (a < 0x3) {
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
            emit ChorusCutoffFreq(v);
            break;
        case 0x0C:
            emit ChorusPreDelay(v);
            break;
        case 0x10:
            emit ChorusRateType(v);
            break;
        case 0x14:
            emit ChorusRateHz(v-1);
            break;
        case 0x18:
            emit ChorusRateNote(v);
            break;
        case 0x1C:
            emit ChorusDepth(v);
            break;
        case 0x20:
            emit ChorusPhase(v*2);
            break;
        case 0x24:
            emit ChorusFeedback(v);
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
            emit DelayDelayLeftMS(v);
            break;
        case 0x0C:
            emit DelayDelayLeftNote(v);
            break;
        case 0x10:
            emit DelayDelayRight(v);
            break;
        case 0x14:
            emit DelayDelayRightMS(v);
            break;
        case 0x18:
            emit DelayDelayRightNote(v);
            break;
        case 0x1C:
            emit DelayDelayCenter(v);
            break;
        case 0x20:
            emit DelayDelayCenterMS(v);
            break;
        case 0x24:
            emit DelayDelayCenterNote(v);
            break;
        case 0x28:
            emit DelayFeedback(v*2-98);
            break;
        case 0x2C:
            emit DelayHFDamp(v);
            break;
        case 0x30:
            emit DelayLeftLevel(v);
            break;
        case 0x34:
            emit DelayRightLevel(v);
            break;
        case 0x38:
            emit DelayCenterLevel(v);
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
            emit GM2ChorusLevel(v);
            break;
        case 0x0C:
            emit GM2ChorusFeedback(v);
            break;
        case 0x10:
            emit GM2ChorusDelay(v);
            break;
        case 0x14:
            emit GM2ChorusRate(v);
            break;
        case 0x18:
            emit GM2ChorusDepth(v);
            break;
        default:
            break;
        }
    }
}

void Integra7Chorus::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{

}
