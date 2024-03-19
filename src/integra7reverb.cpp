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
            emit PreDelay(v);
            break;
        case 0x0B:
            emit Time(v);
            break;
        case 0x0F:
            emit Density(v);
            break;
        case 0x13:
            emit Diffusion(v);
            break;
        case 0x17:
            emit LFDamp(v);
            break;
        case 0x1B:
            emit HFDamp(v);
            break;
        case 0x1F:
            emit Spread(v);
            break;
        case 0x23:
            emit Tone(v);
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
            emit GM2Time(v);
            break;
        default:
            break;
        }
    }
}
