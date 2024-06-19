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

#include "integra7drumcompeq.h"

Integra7DrumCompEQ::Integra7DrumCompEQ(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}{}

void Integra7DrumCompEQ::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit Comp1Switch(v);
        break;
    case 0x01:
        emit Comp1AttackTime(v);
        break;
    case 0x02:
        emit Comp1ReleaseTime(v);
        break;
    case 0x03:
        emit Comp1Threshold(v);
        break;
    case 0x04:
        emit Comp1Ratio(v);
        break;
    case 0x05:
        emit Comp1OutputGain(v);
        break;
    case 0x06:
        emit EQ1Switch(v);
        break;
    case 0x07:
        emit EQ1LowFreq(v);
        break;
    case 0x08:
        emit EQ1LowGain(v);
        break;
    case 0x09:
        emit EQ1MidFreq(v);
        break;
    case 0x0A:
        emit EQ1MidGain(v);
        break;
    case 0x0B:
        emit EQ1MidQ(v);
        break;
    case 0x0C:
        emit EQ1HighFreq(v);
        break;
    case 0x0D:
        emit EQ1HighGain(v);
        break;
    case 0x0E:
        emit Comp2Switch(v);
        break;
    case 0x0F:
        emit Comp2AttackTime(v);
        break;
    case 0x10:
        emit Comp2ReleaseTime(v);
        break;
    case 0x11:
        emit Comp2Threshold(v);
        break;
    case 0x12:
        emit Comp2Ratio(v);
        break;
    case 0x13:
        emit Comp2OutputGain(v);
        break;
    case 0x14:
        emit EQ2Switch(v);
        break;
    case 0x15:
        emit EQ2LowFreq(v);
        break;
    case 0x16:
        emit EQ2LowGain(v);
        break;
    case 0x17:
        emit EQ2MidFreq(v);
        break;
    case 0x18:
        emit EQ2MidGain(v);
        break;
    case 0x19:
        emit EQ2MidQ(v);
        break;
    case 0x1A:
        emit EQ2HighFreq(v);
        break;
    case 0x1B:
        emit EQ2HighGain(v);
        break;
    case 0x1C:
        emit Comp3Switch(v);
        break;
    case 0x1D:
        emit Comp3AttackTime(v);
        break;
    case 0x1E:
        emit Comp3ReleaseTime(v);
        break;
    case 0x1F:
        emit Comp3Threshold(v);
        break;
    case 0x20:
        emit Comp3Ratio(v);
        break;
    case 0x21:
        emit Comp3OutputGain(v);
        break;
    case 0x22:
        emit EQ3Switch(v);
        break;
    case 0x23:
        emit EQ3LowFreq(v);
        break;
    case 0x24:
        emit EQ3LowGain(v);
        break;
    case 0x25:
        emit EQ3MidFreq(v);
        break;
    case 0x26:
        emit EQ3MidGain(v);
        break;
    case 0x27:
        emit EQ3MidQ(v);
        break;
    case 0x28:
        emit EQ3HighFreq(v);
        break;
    case 0x29:
        emit EQ3HighGain(v);
        break;
    case 0x2A:
        emit Comp4Switch(v);
        break;
    case 0x2B:
        emit Comp4AttackTime(v);
        break;
    case 0x2C:
        emit Comp4ReleaseTime(v);
        break;
    case 0x2D:
        emit Comp4Threshold(v);
        break;
    case 0x2E:
        emit Comp4Ratio(v);
        break;
    case 0x2F:
        emit Comp4OutputGain(v);
        break;
    case 0x30:
        emit EQ4Switch(v);
        break;
    case 0x31:
        emit EQ4LowFreq(v);
        break;
    case 0x32:
        emit EQ4LowGain(v);
        break;
    case 0x33:
        emit EQ4MidFreq(v);
        break;
    case 0x34:
        emit EQ4MidGain(v);
        break;
    case 0x35:
        emit EQ4MidQ(v);
        break;
    case 0x36:
        emit EQ4HighFreq(v);
        break;
    case 0x37:
        emit EQ4HighGain(v);
        break;
    case 0x38:
        emit Comp5Switch(v);
        break;
    case 0x39:
        emit Comp5AttackTime(v);
        break;
    case 0x3A:
        emit Comp5ReleaseTime(v);
        break;
    case 0x3B:
        emit Comp5Threshold(v);
        break;
    case 0x3C:
        emit Comp5Ratio(v);
        break;
    case 0x3D:
        emit Comp5OutputGain(v);
        break;
    case 0x3E:
        emit EQ5Switch(v);
        break;
    case 0x3F:
        emit EQ5LowFreq(v);
        break;
    case 0x40:
        emit EQ5LowGain(v);
        break;
    case 0x41:
        emit EQ5MidFreq(v);
        break;
    case 0x42:
        emit EQ5MidGain(v);
        break;
    case 0x43:
        emit EQ5MidQ(v);
        break;
    case 0x44:
        emit EQ5HighFreq(v);
        break;
    case 0x45:
        emit EQ5HighGain(v);
        break;
    case 0x46:
        emit Comp6Switch(v);
        break;
    case 0x47:
        emit Comp6AttackTime(v);
        break;
    case 0x48:
        emit Comp6ReleaseTime(v);
        break;
    case 0x49:
        emit Comp6Threshold(v);
        break;
    case 0x4A:
        emit Comp6Ratio(v);
        break;
    case 0x4B:
        emit Comp6OutputGain(v);
        break;
    case 0x4C:
        emit EQ6Switch(v);
        break;
    case 0x4D:
        emit EQ6LowFreq(v);
        break;
    case 0x4E:
        emit EQ6LowGain(v);
        break;
    case 0x4F:
        emit EQ6MidFreq(v);
        break;
    case 0x50:
        emit EQ6MidGain(v);
        break;
    case 0x51:
        emit EQ6MidQ(v);
        break;
    case 0x52:
        emit EQ6HighFreq(v);
        break;
    case 0x53:
        emit EQ6HighGain(v);
        break;
    default:
        break;
    }
}

void Integra7DrumCompEQ::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        data[a] = rdata[r++];
        EmitSignal(a,data[a]);
        ++a;
    }
}
