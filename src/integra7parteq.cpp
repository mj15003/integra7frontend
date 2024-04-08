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

#include "integra7parteq.h"

Integra7PartEQ::Integra7PartEQ(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
    :Integra7ParameterSet{parent,o1,o2,o3}
{

}

void Integra7PartEQ::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0:
        emit EQSwitch(v);
        break;
    case 1:
        emit EQLowFreq(v);
        break;
    case 2:
        emit EQLowGain(GetEQLowGain());
        break;
    case 3:
        emit EQMidFreq(v);
        break;
    case 4:
        emit EQMidGain(GetEQMidGain());
        break;
    case 5:
        emit EQMidQ(v);
        break;
    case 6:
        emit EQHighFreq(v);
        break;
    case 7:
        emit EQHighGain(GetEQHighGain());
        break;
    default:
        break;
    }

}

void Integra7PartEQ::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        data[a] = rdata[r++];
        EmitSignal(a,data[a]);
        ++a;
    }
}
