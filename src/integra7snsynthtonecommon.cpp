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

#include "integra7snsynthtonecommon.h"

Integra7SNSynthToneCommon::Integra7SNSynthToneCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}
{
    data[0x0B] = 0;
    data[0x0C] = 0;
    data[0x12] = 0;
    data[0x13] = 0;
    data[0x14] = 0;
    data[0x15] = 64;
    data[0x16] = 0;
    data[0x17] = 0;
    data[0x19] = 0;
    data[0x1A] = 0;
    data[0x1B] = 0;
    data[0x1C] = 0;
    data[0x1D] = 0;
    data[0x1E] = 0;
    data[0x1F] = 0;
    data[0x20] = 0;
    data[0x2E] = 0;
    data[0x31] = 0;
    data[0x32] = 0;
    data[0x34] = 0;
    data[0x35] = 0;
    data[0x36] = 0;
    data[0x37] = 0;
    data[0x38] = 0;
    data[0x39] = 0;
    data[0x3A] = 0;
    data[0x3B] = 64;
    data[0x3C] = 0;
}

void Integra7SNSynthToneCommon::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit ToneName1(v);
        break;
    case 0x01:
        emit ToneName2(v);
        break;
    case 0x02:
        emit ToneName3(v);
        break;
    case 0x03:
        emit ToneName4(v);
        break;
    case 0x04:
        emit ToneName5(v);
        break;
    case 0x05:
        emit ToneName6(v);
        break;
    case 0x06:
        emit ToneName7(v);
        break;
    case 0x07:
        emit ToneName8(v);
        break;
    case 0x08:
        emit ToneName9(v);
        break;
    case 0x09:
        emit ToneName10(v);
        break;
    case 0x0A:
        emit ToneName11(v);
        break;
    case 0x0B:
        emit ToneName12(v);
        emit ToneName(getToneName());
        break;
    case 0x0C:
        emit ToneLevel(v);
        break;
    case 0x12:
        emit PortamentoSwitch(v);
        break;
    case 0x13:
        emit PortamentoTime(v);
        break;
    case 0x14:
        emit MonoSwitch(v);
        break;
    case 0x15:
        emit OctaveShift(getOctaveShift());
        break;
    case 0x16:
        emit PitchBendRangeUp(v);
        break;
    case 0x17:
        emit PitchBendRangeDown(v);
        break;
    case 0x19:
        emit Partial1Switch(v);
        break;
    case 0x1A:
        emit Partial1Select(v);
        break;
    case 0x1B:
        emit Partial2Switch(v);
        break;
    case 0x1C:
        emit Partial2Select(v);
        break;
    case 0x1D:
        emit Partial3Switch(v);
        break;
    case 0x1E:
        emit Partial3Select(v);
        break;
    case 0x1F:
        emit RINGSwitch(v);
        break;
    case 0x20:
        emit TFXSwitch(v);
        break;
    case 0x2E:
        emit UnisonSwitch(v);
        break;
    case 0x31:
        emit PortamentoMode(v);
        break;
    case 0x32:
        emit LegatoSwitch(v);
        break;
    case 0x34:
        emit AnalogFeel(v);
        break;
    case 0x35:
        emit WaveShape(v);
        break;
    case 0x36:
        emit ToneCategory(v);
        break;
    case 0x37:
        emit PhraseNumber(getPhraseNumber());
        break;
    case 0x3B:
        emit PhraseOctaveShift(getPhraseOctaveShift());
        break;
    case 0x3C:
        emit UnisonSize(v);
        break;
    default:
        break;
    }
}

void Integra7SNSynthToneCommon::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a == 0x0){
            while (r<0x0C) data[a++] = rdata[r++];
            emit ToneName(getToneName());
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}

void Integra7SNSynthToneCommon::setToneName(const QString name)
{
    uint8_t c = 0;
    while (c < name.length() && c < 0xC){
        data[c] = name.at(c).toLatin1();
        c++;
    }
}
