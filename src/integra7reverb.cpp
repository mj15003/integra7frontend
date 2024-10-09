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
    : Integra7ParameterSet{parent,o1,o2,o3}
{
    data[0x00] = 0;
    data[0x01] = 0;
    data[0x02] = 0;
    data[0x03] = 8;
    data[0x04] = 0;
    data[0x05] = 0;
    data[0x06] = 0;
    data[0x07] = 8;
    data[0x08] = 0;
    data[0x09] = 0;
    data[0x0A] = 0;
    data[0x0B] = 8;
    data[0x0C] = 0;
    data[0x0D] = 0;
    data[0x0E] = 0;
    data[0x0F] = 8;
    data[0x10] = 0;
    data[0x11] = 0;
    data[0x12] = 0;
    data[0x13] = 8;
    data[0x14] = 0;
    data[0x15] = 0;
    data[0x16] = 0;
    data[0x17] = 8;
    data[0x18] = 0;
    data[0x19] = 0;
    data[0x1A] = 0;
    data[0x1B] = 8;
    data[0x1C] = 0;
    data[0x1D] = 0;
    data[0x1E] = 0;
    data[0x1F] = 8;
    data[0x20] = 0;
    data[0x21] = 0;
    data[0x22] = 0;
    data[0x23] = 8;
    data[0x24] = 0;
    data[0x25] = 0;
    data[0x26] = 0;
    data[0x27] = 8;
    data[0x28] = 0;
    data[0x29] = 0;
    data[0x2A] = 0;
    data[0x2B] = 8;
    data[0x2C] = 0;
    data[0x2C] = 0;
    data[0x2D] = 0;
    data[0x2E] = 0;
    data[0x2F] = 8;
    data[0x30] = 0;
    data[0x31] = 0;
    data[0x32] = 0;
    data[0x33] = 8;
    data[0x34] = 0;
    data[0x35] = 0;
    data[0x36] = 0;
    data[0x37] = 8;
    data[0x38] = 0;
    data[0x39] = 0;
    data[0x3A] = 0;
    data[0x3B] = 8;
    data[0x3C] = 0;
    data[0x3D] = 0;
    data[0x3E] = 0;
    data[0x3F] = 8;
    data[0x40] = 0;
    data[0x41] = 0;
    data[0x42] = 0;
    data[0x43] = 8;
    data[0x44] = 0;
    data[0x45] = 0;
    data[0x46] = 0;
    data[0x47] = 8;
    data[0x48] = 0;
    data[0x49] = 0;
    data[0x4A] = 0;
    data[0x4B] = 8;
    data[0x4C] = 0;
    data[0x4D] = 0;
    data[0x4E] = 0;
    data[0x4F] = 8;
    data[0x50] = 0;
    data[0x51] = 0;
    data[0x52] = 0;
    data[0x53] = 8;
    data[0x54] = 0;
    data[0x55] = 0;
    data[0x56] = 0;
    data[0x57] = 8;
    data[0x58] = 0;
    data[0x59] = 0;
    data[0x5A] = 0;
    data[0x5B] = 8;
    data[0x5C] = 0;
    data[0x5D] = 0;
    data[0x5E] = 0;
    data[0x5F] = 8;
    data[0x60] = 0;
    data[0x61] = 0;
    data[0x62] = 0;
}

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
