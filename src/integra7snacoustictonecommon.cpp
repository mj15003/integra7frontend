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

#include "integra7snacoustictonecommon.h"

Integra7SNAcousticToneCommon::Integra7SNAcousticToneCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}
{
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
    data[0x1A] = 64;
    data[0x1B] = 0;
    data[0x1C] = 0;
    data[0x1D] = 0;
    data[0x1E] = 64;
    data[0x1F] = 0;
    data[0x20] = 0;
    data[0x21] = 0;
    data[0x22] = 64;
    data[0x23] = 64;
    data[0x24] = 64;
    data[0x25] = 64;
    data[0x26] = 64;
    data[0x27] = 64;
    data[0x28] = 64;
    data[0x29] = 64;
    data[0x2A] = 64;
    data[0x2B] = 64;
    data[0x2C] = 64;
    data[0x2D] = 64;
    data[0x2E] = 64;
    data[0x2F] = 64;
    data[0x30] = 64;
    data[0x31] = 64;
    data[0x32] = 64;
    data[0x33] = 64;
    data[0x34] = 64;
    data[0x35] = 64;
    data[0x36] = 64;
    data[0x37] = 64;
    data[0x38] = 64;
    data[0x39] = 64;
    data[0x3A] = 64;
    data[0x3B] = 64;
    data[0x3C] = 64;
    data[0x3D] = 64;
    data[0x3E] = 64;
    data[0x3F] = 64;
    data[0x40] = 64;
    data[0x41] = 64;
}

void Integra7SNAcousticToneCommon::EmitSignal(uint8_t a, int v)
{
    v = data[a];

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
    case 0x10:
        emit ToneLevel(v);
        break;
    case 0x11:
        emit MonoPoly(v);
        break;
    case 0x12:
        emit PortamentoTimeOffset(getPortamentoTimeOffset());
        break;
    case 0x13:
        emit CutoffOffset(getCutoffOffset());
        break;
    case 0x14:
        emit ResonanceOffset(getResonanceOffset());
        break;
    case 0x15:
        emit AttackTimeOffset(getAttackTimeOffset());
        break;
    case 0x16:
        emit ReleaseTimeOffset(getReleaseTimeOffset());
        break;
    case 0x17:
        emit VibratoRate(getVibratoRate());
        break;
    case 0x18:
        emit VibratoDepth(getVibratoDepth());
        break;
    case 0x19:
        emit VibratoDelay(getVibratoDelay());
        break;
    case 0x1A:
        emit OctaveShift(getOctaveShift());
        break;
    case 0x1B:
        emit Category(v);
        break;
    case 0x1C:
        emit PhraseNumber(getPhraseNumber());
        break;
    case 0x1E:
        emit PhraseOctaveShift(getPhraseOctaveShift());
        break;
    case 0x1F:
        emit TFXSwitch(v);
        break;
    case 0x20:
        emit InstVariation(v);        
        break;
    case 0x21:
        emit InstNumber(v);
        emit Instrument(GetInstrumentIndex(data[0x20],data[0x21]));
        break;
    case 0x22:
        emit ModifyParameter1(v);
        emit AcPianoStringResonance(v);
        break;
    case 0x23:
        emit ModifyParameter2(v);
        emit AcPianoKeyOffResonance(v);
        break;
    case 0x24:
        emit ModifyParameter3(v);
        emit AcPianoHammerNoise(getAcPianoHammerNoise());
        break;
    case 0x25:
        emit ModifyParameter4(v);
        emit AcPianoStereoWidth(getAcPianoStereoWidth());
        break;
    case 0x26:
        emit ModifyParameter5(v);
        emit AcPianoNuance(getAcPianoNuance());
        break;
    case 0x27:
        emit ModifyParameter6(v);
        emit AcPianoToneCharacter(getAcPianoToneCharacter());
        break;
    case 0x28:
        emit ModifyParameter7(v);
        break;
    case 0x29:
        emit ModifyParameter8(v);
        break;
    case 0x2A:
        emit ModifyParameter9(v);
        break;
    case 0x2B:
        emit ModifyParameter10(v);
        break;
    case 0x2C:
        emit ModifyParameter11(v);
        break;
    case 0x2D:
        emit ModifyParameter12(v);
        break;
    case 0x2E:
        emit ModifyParameter13(v);
        break;
    case 0x2F:
        emit ModifyParameter14(v);
        break;
    case 0x30:
        emit ModifyParameter15(v);
        break;
    case 0x31:
        emit ModifyParameter16(v);
        break;
    case 0x32:
        emit ModifyParameter17(v);
        break;
    case 0x33:
        emit ModifyParameter18(v);
        break;
    case 0x34:
        emit ModifyParameter19(v);
        break;
    case 0x35:
        emit ModifyParameter20(v);
        break;
    case 0x36:
        emit ModifyParameter21(v);
        break;
    case 0x37:
        emit ModifyParameter22(v);
        break;
    case 0x38:
        emit ModifyParameter23(v);
        break;
    case 0x39:
        emit ModifyParameter24(v);
        break;
    case 0x3A:
        emit ModifyParameter25(v);
        break;
    case 0x3B:
        emit ModifyParameter26(v);
        break;
    case 0x3C:
        emit ModifyParameter27(v);
        break;
    case 0x3D:
        emit ModifyParameter28(v);
        break;
    case 0x3E:
        emit ModifyParameter29(v);
        break;
    case 0x3F:
        emit ModifyParameter30(v);
        break;
    case 0x40:
        emit ModifyParameter31(v);
        break;
    case 0x41:
        emit ModifyParameter32(v);
        break;
    default:
        break;
    }
}

void Integra7SNAcousticToneCommon::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a == 0x0) {
            while (r<0x0C) data[a++] = rdata[r++];
            emit ToneName(getToneName());
        } else if (a == 0x1C) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x1C,getPhraseNumber());
        } else if (a == 0x21) {
            data[a++] = rdata[r++];            
            emit InstNumber(data[0x21]);
            emit Instrument(GetInstrumentIndex(data[0x20],data[0x21]));
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}

int Integra7SNAcousticToneCommon::GetInstrumentIndex(int v, int n)
{
    int k = 0;

    while (k < 127) {
        if (InstrumentByteList[k][0] == v &&
            InstrumentByteList[k][1] == n)
            return k;
        k++;
    }

    return -1;
}

void Integra7SNAcousticToneCommon::setToneName(const QString &name)
{
    uint8_t c = 0;
    uint8_t buf[0xC];

    while (c < 0xC){
        if (c < name.length()) buf[c] = name.at(c).toLatin1();
        else buf[c] = 0;
        c++;
    }

    DataSetMultiB(0x0,buf,0xC);
}

void Integra7SNAcousticToneCommon::setInstrument(int v)
{
    DataSetMultiB(0x20,InstrumentByteList[v],2);
}
