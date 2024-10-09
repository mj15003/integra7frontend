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

#include "integra7sndrumkitcommon.h"

Integra7SNDrumKitCommon::Integra7SNDrumKitCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}
{
    data[0x10] = 0;
    data[0x11] = 0;
    data[0x12] = 0;
    data[0x13] = 0;
}

void Integra7SNDrumKitCommon::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit KitName1(v);
        break;
    case 0x01:
        emit KitName2(v);
        break;
    case 0x02:
        emit KitName3(v);
        break;
    case 0x03:
        emit KitName4(v);
        break;
    case 0x04:
        emit KitName5(v);
        break;
    case 0x05:
        emit KitName6(v);
        break;
    case 0x06:
        emit KitName7(v);
        break;
    case 0x07:
        emit KitName8(v);
        break;
    case 0x08:
        emit KitName9(v);
        break;
    case 0x09:
        emit KitName10(v);
        break;
    case 0x0A:
        emit KitName11(v);
        break;
    case 0x0B:
        emit KitName12(v);
        emit KitName(getKitName());
        break;
    case 0x10:
        emit KitLevel(v);
        break;
    case 0x11:
        emit AmbienceLevel(v);
        break;
    case 0x12:
        emit PhraseNumber(v);
        break;
    case 0x13:
        emit TFXSwitch(v);
        break;
    default:
        break;
    }
}

void Integra7SNDrumKitCommon::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a == 0x0){
            while (r<0x0C) data[a++] = rdata[r++];
            emit KitName(getKitName());
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}

void Integra7SNDrumKitCommon::setKitName(const QString name)
{
    uint8_t c = 0;
    while (c < name.length() && c < 0xC){
        data[c] = name.at(c).toLatin1();
        c++;
    }
}
