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

#include "integra7pcmsynthtonecommon2.h"

Integra7PCMSynthToneCommon2::Integra7PCMSynthToneCommon2(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}
{
    data[0x10] = 0;
    data[0x13] = 64;
    data[0x33] = 0;
    data[0x38] = 0;
    data[0x39] = 0;
    data[0x3A] = 0;
    data[0x3B] = 0;
}

void Integra7PCMSynthToneCommon2::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x10:
        emit ToneCategory(v);
        break;
    case 0x13:
        emit PhraseOctaveShift(getPhraseOctaveShift());
        break;
    case 0x33:
        emit TFXSwitch(v);
        break;
    case 0x38:
        emit PhraseNumber(getPhraseNumber());
        break;
    default:
        break;
    }
}

void Integra7PCMSynthToneCommon2::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a == 0x38) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x38,getPhraseNumber());
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}
