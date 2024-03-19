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

#include "integra7parameterset.h"

Integra7ParameterSet::Integra7ParameterSet(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
{
    pIntegraDev = parent;
    address[0]=o1;
    address[1]=o2;
    address[2]=o3;
}

void Integra7ParameterSet::DataSet(uint8_t a, int v)
{
    if (v == data[a]) return;

    data[a] = v;

    uint8_t output[5];

    output[0] = address[0];
    output[1] = address[1];
    output[2] = address[2];
    output[3] = a;
    output[4] = v;

    pIntegraDev->DataSet(output,5);
    EmitSignal(a,v);
}

void Integra7ParameterSet::DataSetOffset(uint8_t a, int v, int offset)
{
    if (v + offset == data[a]) return;

    data[a] = v + offset;

    uint8_t output[5];

    output[0] = address[0];
    output[1] = address[1];
    output[2] = address[2];
    output[3] = a;
    output[4] = data[a];

    pIntegraDev->DataSet(output,5);
    EmitSignal(a,v);
}

void Integra7ParameterSet::DataSet2x7B(uint8_t a, int v)
{
    uint8_t msb = v >> 7;
    uint8_t lsb = v & 0x7F;

    if (msb == data[a] && lsb == data[a+1]) return;

    data[a] = msb;
    data[a+1] = lsb;

    uint8_t output[6];

    output[0] = address[0];
    output[1] = address[1];
    output[2] = address[2];
    output[3] = a;
    output[4] = data[a];
    output[5] = data[a+1];

    pIntegraDev->DataSet(output,6);
    EmitSignal(a,v);
}

void Integra7ParameterSet::DataSet2x4B(uint8_t a, int v)
{
    uint8_t msb = v >> 4;
    uint8_t lsb = v & 0xF;

    if (msb == data[a] && lsb == data[a+1]) return;

    data[a] = msb;
    data[a+1] = lsb;

    uint8_t output[6];

    output[0] = address[0];
    output[1] = address[1];
    output[2] = address[2];
    output[3] = a;
    output[4] = data[a];
    output[5] = data[a+1];

    pIntegraDev->DataSet(output,6);
    EmitSignal(a,v);
}

void Integra7ParameterSet::DataSet4x4B(uint8_t a, int v)
{
    uint8_t b2 = v >> 8 & 0xF;
    uint8_t b1 = v >> 4 & 0xF;
    uint8_t b0 = v & 0xF;

    //At address 'a' should always be 0x80

    if (b2 == data[a+1] && b1 == data[a+2] && b0 == data[a+3]) return;

    data[a] = 0x80;
    data[a+1] = b2;
    data[a+2] = b1;
    data[a+3] = b0;

    uint8_t output[8];

    output[0] = address[0];
    output[1] = address[1];
    output[2] = address[2];
    output[3] = a;
    output[4] = data[a];
    output[5] = data[a+1];
    output[6] = data[a+2];
    output[7] = data[a+3];

    pIntegraDev->DataSet(output,8);
    EmitSignal(a,v);
}
