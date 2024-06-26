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

#include "integra7reverb.h"

Integra7Reverb::Integra7Reverb(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
    : Integra7ParameterSet{parent,o1,o2,o3}{}

QStringList &Integra7Reverb::TimeList()
{
    static QList<QString> list(100);
    double v1 = 0.0;

    if (list.at(0).isEmpty()) {
        for (int i=0;i<list.size();i++) list[i] = QString::number(v1+=0.1,'f',1);
    }

    return list;
}

void Integra7Reverb::EmitSignal(uint8_t a, int v)
{
    if (a < 0x3) {
        //General parameters
        switch (a) {
        case 0x0:
            emit Type(v);
            break;
        case 0x1:
            emit Level(v);
            break;
        case 0x2:
            emit OutputAssign(v);
            break;
        default:
            break;
        }
    } else if (data[0] < 6) {
        //Room,Hall,Plate section
        switch (a) {
        case 0x07:
            emit PreDelay(getPreDelay());
            break;
        case 0x0B:
            emit Time(getTime());
            break;
        case 0x0F:
            emit Density(getDensity());
            break;
        case 0x13:
            emit Diffusion(getDiffusion());
            break;
        case 0x17:
            emit LFDamp(getLFDamp());
            break;
        case 0x1B:
            emit HFDamp(getHFDamp());
            break;
        case 0x1F:
            emit Spread(getSpread());
            break;
        case 0x23:
            emit Tone(getTone());
            break;
        default:
            break;
        }
    } else {
        switch (a) {
        case 0x03:
            emit GM2Character(v);
            break;
        case 0x0F:
            emit GM2Time(getGM2Time());
            break;
        default:
            break;
        }
    }
}

void Integra7Reverb::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a < 0x03){
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
