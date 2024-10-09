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

#include "integra7pcmsynthtonecommon.h"

Integra7PCMSynthToneCommon::Integra7PCMSynthToneCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}
{
    /* Put correct initialization value into certain fields which does not allow zero */
    data[0x0B] = 0;
    data[0x0E] = 0;
    data[0x0F] = 0;
    data[0x10] = 0;
    data[0x11] = 64;
    data[0x12] = 64;
    data[0x13] = 64;
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
    data[0x1F] = 0;
    data[0x22] = 64;
    data[0x23] = 64;
    data[0x24] = 64;
    data[0x25] = 64;
    data[0x26] = 64;
    data[0x28] = 0;
    data[0x29] = 0;
    data[0x2A] = 0;
    data[0x2B] = 0;
    data[0x2C] = 0;
    data[0x2D] = 64;
    data[0x2E] = 0;
    data[0x2F] = 64;
    data[0x30] = 0;
    data[0x31] = 64;
    data[0x32] = 0;
    data[0x33] = 64;
    data[0x34] = 0;
    data[0x35] = 0;
    data[0x36] = 64;
    data[0x37] = 0;
    data[0x38] = 64;
    data[0x39] = 0;
    data[0x3A] = 64;
    data[0x3B] = 0;
    data[0x3C] = 64;
    data[0x3D] = 0;
    data[0x3E] = 0;
    data[0x3F] = 64;
    data[0x40] = 0;
    data[0x41] = 64;
    data[0x42] = 0;
    data[0x43] = 64;
    data[0x44] = 0;
    data[0x45] = 64;
    data[0x46] = 0;
    data[0x47] = 0;
    data[0x48] = 64;
    data[0x49] = 0;
    data[0x4A] = 64;
    data[0x4B] = 0;
    data[0x4C] = 64;
    data[0x4D] = 0;
    data[0x4E] = 64;
}

void Integra7PCMSynthToneCommon::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit PCMSynthToneName1(v);
        break;
    case 0x01:
        emit PCMSynthToneName2(v);
        break;
    case 0x02:
        emit PCMSynthToneName3(v);
        break;
    case 0x03:
        emit PCMSynthToneName4(v);
        break;
    case 0x04:
        emit PCMSynthToneName5(v);
        break;
    case 0x05:
        emit PCMSynthToneName6(v);
        break;
    case 0x06:
        emit PCMSynthToneName7(v);
        break;
    case 0x07:
        emit PCMSynthToneName8(v);
        break;
    case 0x08:
        emit PCMSynthToneName9(v);
        break;
    case 0x09:
        emit PCMSynthToneName10(v);
        break;
    case 0x0A:
        emit PCMSynthToneName11(v);
        break;
    case 0x0B:
        emit PCMSynthToneName12(v);
        emit PCMSynthToneName(getPCMSynthToneName());
        break;
    case 0x0E:
        emit PCMSynthToneLevel(v);
        break;
    case 0x0F:
        emit PCMSynthTonePan(getPCMSynthTonePan());
        break;
    case 0x10:
        emit PCMSynthTonePriority(v);
        break;
    case 0x11:
        emit PCMSynthToneCoarseTune(getPCMSynthToneCoarseTune());
        break;
    case 0x12:
        emit PCMSynthToneFineTune(getPCMSynthToneFineTune());
        break;
    case 0x13:
        emit OctaveShift(getOctaveShift());
        break;
    case 0x14:
        emit StretchTuneDepth(v);
        break;
    case 0x15:
        emit AnalogFeel(v);
        break;
    case 0x16:
        emit MonoPoly(v);
        break;
    case 0x17:
        emit LegatoSwitch(v);
        break;
    case 0x18:
        emit LegatoRetrigger(v);
        break;
    case 0x19:
        emit PortamentoSwitch(v);
        break;
    case 0x1A:
        emit PortamentoMode(v);
        break;
    case 0x1B:
        emit PortamentoType(v);
        break;
    case 0x1C:
        emit PortamentoStart(v);
        break;
    case 0x1D:
        emit PortamentoTime(v);
        break;
    case 0x22:
        emit CutoffOffset(getCutoffOffset());
        break;
    case 0x23:
        emit ResonanceOffset(getResonanceOffset());
        break;
    case 0x24:
        emit AttackTimeOffset(getAttackTimeOffset());
        break;
    case 0x25:
        emit ReleaseTimeOffset(getReleaseTimeOffset());
        break;
    case 0x26:
        emit VelocitySensOffset(getVelocitySensOffset());
        break;
    case 0x28:
        emit PMTControlSwitch(v);
        break;
    case 0x29:
        emit PitchBendRangeUp(v);
        break;
    case 0x2A:
        emit PitchBendRangeDown(v);
        break;
    case 0x2B:
        emit MatrixControl1Source(v);
        break;
    case 0x2C:
        emit MatrixControl1Destination1(v);
        break;
    case 0x2D:
        emit MatrixControl1Sens1(getMatrixControl1Sens1());
        break;
    case 0x2E:
        emit MatrixControl1Destination2(v);
        break;
    case 0x2F:
        emit MatrixControl1Sens2(getMatrixControl1Sens2());
        break;
    case 0x30:
        emit MatrixControl1Destination3(v);
        break;
    case 0x31:
        emit MatrixControl1Sens3(getMatrixControl1Sens3());
        break;
    case 0x32:
        emit MatrixControl1Destination4(v);
        break;
    case 0x33:
        emit MatrixControl1Sens4(getMatrixControl1Sens4());
        break;
    case 0x34:
        emit MatrixControl2Source(v);
        break;
    case 0x35:
        emit MatrixControl2Destination1(v);
        break;
    case 0x36:
        emit MatrixControl2Sens1(getMatrixControl2Sens1());
        break;
    case 0x37:
        emit MatrixControl2Destination2(v);
        break;
    case 0x38:
        emit MatrixControl2Sens2(getMatrixControl2Sens2());
        break;
    case 0x39:
        emit MatrixControl2Destination3(v);
        break;
    case 0x3A:
        emit MatrixControl2Sens3(getMatrixControl2Sens3());
        break;
    case 0x3B:
        emit MatrixControl2Destination4(v);
        break;
    case 0x3C:
        emit MatrixControl2Sens4(getMatrixControl2Sens4());
        break;
    case 0x3D:
        emit MatrixControl3Source(v);
        break;
    case 0x3E:
        emit MatrixControl3Destination1(v);
        break;
    case 0x3F:
        emit MatrixControl3Sens1(getMatrixControl3Sens1());
        break;
    case 0x40:
        emit MatrixControl3Destination2(v);
        break;
    case 0x41:
        emit MatrixControl3Sens2(getMatrixControl3Sens2());
        break;
    case 0x42:
        emit MatrixControl3Destination3(v);
        break;
    case 0x43:
        emit MatrixControl3Sens3(getMatrixControl3Sens3());
        break;
    case 0x44:
        emit MatrixControl3Destination4(v);
        break;
    case 0x45:
        emit MatrixControl3Sens4(getMatrixControl3Sens4());
        break;
    case 0x46:
        emit MatrixControl4Source(v);
        break;
    case 0x47:
        emit MatrixControl4Destination1(v);
        break;
    case 0x48:
        emit MatrixControl4Sens1(getMatrixControl4Sens1());
        break;
    case 0x49:
        emit MatrixControl4Destination2(v);
        break;
    case 0x4A:
        emit MatrixControl4Sens2(getMatrixControl4Sens2());
        break;
    case 0x4B:
        emit MatrixControl4Destination3(v);
        break;
    case 0x4C:
        emit MatrixControl4Sens3(getMatrixControl4Sens3());
        break;
    case 0x4D:
        emit MatrixControl4Destination4(v);
        break;
    case 0x4E:
        emit MatrixControl4Sens4(getMatrixControl4Sens4());
        break;
    default:
        break;
    }
}

void Integra7PCMSynthToneCommon::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a == 0x0){
            while (r<0x0C) data[a++] = rdata[r++];
            emit PCMSynthToneName(getPCMSynthToneName());
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}

void Integra7PCMSynthToneCommon::setToneName(const QString name)
{
    uint8_t c = 0;
    while (c < name.length() && c < 0xC){
        data[c] = name.at(c).toLatin1();
        c++;
    }
}
