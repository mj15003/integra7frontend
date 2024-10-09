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

#include "integra7sndrumkitnote.h"

Integra7SNDrumKitNote::Integra7SNDrumKitNote(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}
{
    data[0x00] = 0;
    data[0x01] = 0;
    data[0x02] = 0;
    data[0x03] = 0;
    data[0x04] = 0;
    data[0x05] = 0;
    data[0x06] = 0;
    data[0x07] = 0;
    data[0x08] = 0;
    data[0x09] = 0;
    data[0x0A] = 8;
    data[0x0B] = 0;
    data[0x0C] = 0;
    data[0x0D] = 32;
    data[0x0E] = 62;
    data[0x0F] = 0;
    data[0x10] = 0;
    data[0x11] = 0;
    data[0x12] = 0;
}

void Integra7SNDrumKitNote::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit InstNumber(getInstNumber());
        break;
    case 0x04:
        emit Level(v);
        break;
    case 0x05:
        emit Pan(getPan());
        break;
    case 0x06:
        emit ChorusSendLevel(v);
        break;
    case 0x07:
        emit ReverbSendLevel(v);
        break;
    case 0x08:
        emit Tune(getTune());
        break;
    case 0x0C:
        emit Attack(v);
        break;
    case 0x0D:
        emit Decay(v);
        break;
    case 0x0E:
        emit Brilliance(getBrilliance());
        break;
    case 0x0F:
        emit Variation(v);
        break;
    case 0x10:
        emit DynamicRange(v);
        break;
    case 0x11:
        emit StereoWidth(v);
        break;
    case 0x12:
        emit OutputAssign(v);
        break;
    default:
        break;
    }
}

void Integra7SNDrumKitNote::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a == 0x00) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x00,getInstNumber());
        } else if (a == 0x08) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x08,getTune());
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}
