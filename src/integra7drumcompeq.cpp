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
    data[0x0A] = 0;
    data[0x0B] = 0;
    data[0x0C] = 0;
    data[0x0D] = 0;
    data[0x0E] = 0;
    data[0x0F] = 0;
    data[0x10] = 0;
    data[0x11] = 0;
    data[0x12] = 0;
    data[0x13] = 0;
    data[0x14] = 0;
    data[0x15] = 0;
    data[0x16] = 0;
    data[0x17] = 0;
    data[0x18] = 0;
    data[0x19] = 0;
    data[0x1A] = 0;
    data[0x1B] = 0;
    data[0x1C] = 0;
    data[0x1D] = 0;
    data[0x1E] = 0;
    data[0x1F] = 0;
    data[0x20] = 0;
    data[0x21] = 0;
    data[0x22] = 0;
    data[0x23] = 0;
    data[0x24] = 0;
    data[0x25] = 0;
    data[0x26] = 0;
    data[0x27] = 0;
    data[0x28] = 0;
    data[0x29] = 0;
    data[0x2A] = 0;
    data[0x2B] = 0;
    data[0x2C] = 0;
    data[0x2D] = 0;
    data[0x2E] = 0;
    data[0x2F] = 0;
    data[0x30] = 0;
    data[0x31] = 0;
    data[0x32] = 0;
    data[0x33] = 0;
    data[0x34] = 0;
    data[0x35] = 0;
    data[0x36] = 0;
    data[0x37] = 0;
    data[0x38] = 0;
    data[0x39] = 0;
    data[0x3A] = 0;
    data[0x3B] = 0;
    data[0x3C] = 0;
    data[0x3D] = 0;
    data[0x3E] = 0;
    data[0x3F] = 0;
    data[0x40] = 0;
    data[0x41] = 0;
    data[0x42] = 0;
    data[0x43] = 0;
    data[0x44] = 0;
    data[0x45] = 0;
    data[0x46] = 0;
    data[0x47] = 0;
    data[0x48] = 0;
    data[0x49] = 0;
    data[0x4A] = 0;
    data[0x4B] = 0;
    data[0x4C] = 0;
    data[0x4D] = 0;
    data[0x4E] = 0;
    data[0x4F] = 0;
    data[0x50] = 0;
    data[0x51] = 0;
    data[0x52] = 0;
    data[0x53] = 0;
}

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
        emit EQ1LowGain(getEQ1LowGain());
        break;
    case 0x09:
        emit EQ1MidFreq(v);
        break;
    case 0x0A:
        emit EQ1MidGain(getEQ1MidGain());
        break;
    case 0x0B:
        emit EQ1MidQ(v);
        break;
    case 0x0C:
        emit EQ1HighFreq(v);
        break;
    case 0x0D:
        emit EQ1HighGain(getEQ1HighGain());
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
        emit EQ2LowGain(getEQ2LowGain());
        break;
    case 0x17:
        emit EQ2MidFreq(v);
        break;
    case 0x18:
        emit EQ2MidGain(getEQ2MidGain());
        break;
    case 0x19:
        emit EQ2MidQ(v);
        break;
    case 0x1A:
        emit EQ2HighFreq(v);
        break;
    case 0x1B:
        emit EQ2HighGain(getEQ2HighGain());
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
        emit EQ3LowGain(getEQ3LowGain());
        break;
    case 0x25:
        emit EQ3MidFreq(v);
        break;
    case 0x26:
        emit EQ3MidGain(getEQ3MidGain());
        break;
    case 0x27:
        emit EQ3MidQ(v);
        break;
    case 0x28:
        emit EQ3HighFreq(v);
        break;
    case 0x29:
        emit EQ3HighGain(getEQ3HighGain());
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
        emit EQ4LowGain(getEQ4LowGain());
        break;
    case 0x33:
        emit EQ4MidFreq(v);
        break;
    case 0x34:
        emit EQ4MidGain(getEQ4MidGain());
        break;
    case 0x35:
        emit EQ4MidQ(v);
        break;
    case 0x36:
        emit EQ4HighFreq(v);
        break;
    case 0x37:
        emit EQ4HighGain(getEQ4HighGain());
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
        emit EQ5LowGain(getEQ5LowGain());
        break;
    case 0x41:
        emit EQ5MidFreq(v);
        break;
    case 0x42:
        emit EQ5MidGain(getEQ5MidGain());
        break;
    case 0x43:
        emit EQ5MidQ(v);
        break;
    case 0x44:
        emit EQ5HighFreq(v);
        break;
    case 0x45:
        emit EQ5HighGain(getEQ5HighGain());
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
        emit EQ6LowGain(getEQ6LowGain());
        break;
    case 0x4F:
        emit EQ6MidFreq(v);
        break;
    case 0x50:
        emit EQ6MidGain(getEQ6MidGain());
        break;
    case 0x51:
        emit EQ6MidQ(v);
        break;
    case 0x52:
        emit EQ6HighFreq(v);
        break;
    case 0x53:
        emit EQ6HighGain(getEQ6HighGain());
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
