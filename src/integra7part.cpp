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

#include "integra7part.h"

Integra7Part::Integra7Part(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
    : Integra7ParameterSet{parent,o1,o2,o3}
{

}

void Integra7Part::setToneBankProgram(int b, int p)
{
    /* One bank can have only 128 programs
       if there are more of them we need another bank */
    b += p >> 7;

    uint8_t msb = b >> 7;
    uint8_t lsb = b & 0x7F;
    uint8_t pc = p & 0x7F;

    if (data[0x08] == pc &&
        data[0x07] == lsb &&
        data[0x06] == msb) return;

    data[0x06] = msb;
    data[0x07] = lsb;
    data[0x08] = pc;

    uint8_t output[7];

    output[0] = address[0];
    output[1] = address[1];
    output[2] = address[2];
    output[3] = 0x06;
    output[4] = data[0x06];
    output[5] = data[0x07];
    output[6] = data[0x08];

    pIntegraDev->DataSet(output,7);
    emit ToneBankProgram(b,p);
}

void Integra7Part::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit ReceiveChannel(v);
        break;
    case 0x01:
        emit ReceiveSwitch(v);
        break;
    case 0x06:
        emit ToneBankSelectMSB(v);
        break;
    case 0x07:
        emit ToneBankSelectLSB(v);
        break;
    case 0x08:
        emit ToneProgramNumber(v);
        break;
    case 0x09:
        emit PartLevel(v);
        break;
    case 0x0A:
        emit PartPan(v);
        break;
    case 0x0B:
        emit PartCoarseTune(v);
        break;
    case 0x0C:
        emit PartFineTune(v);
        break;
    case 0x0D:
        emit PartMonoPoly(v);
        break;
    case 0x0E:
        emit PartLegatoSwitch(v);
        break;
    case 0x0F:
        emit PartPitchBendRange(v);
        break;
    case 0x10:
        emit PartPortamentoSwitch(v);
        break;
    case 0x11:
        emit PartPortamentoTime(v);
        break;
    case 0x13:
        emit PartCutoffOffset(v);
        break;
    case 0x14:
        emit PartResonanceOffset(v);
        break;
    case 0x15:
        emit PartAttackTimeOffset(v);
        break;
    case 0x16:
        emit PartDecayTimeOffset(v);
        break;
    case 0x17:
        emit PartReleaseTimeOffset(v);
        break;
    case 0x18:
        emit PartVibratoRate(v);
        break;
    case 0x19:
        emit PartVibratoDepth(v);
        break;
    case 0x1A:
        emit PartVibratoDelay(v);
        break;
    case 0x1B:
        emit PartOctaveShift(v);
        break;
    case 0x1C:
        emit PartVelocitySensOffset(v);
        break;
    case 0x1D:
        emit KeyboardRangeLower(v);
        break;
    case 0x1E:
        emit KeyboardRangeUpper(v);
        break;
    case 0x1F:
        emit KeyboardFadeWidthLower(v);
        break;
    case 0x20:
        emit KeyboardFadeWidthUpper(v);
        break;
    case 0x21:
        emit VelocityRangeLower(v);
        break;
    case 0x22:
        emit VelocityRangeUpper(v);
        break;
    case 0x23:
        emit VelocityFadeWidthLower(v);
        break;
    case 0x24:
        emit VelocityFadeWidthUpper(v);
        break;
    case 0x25:
        emit MuteSwitch(v);
        break;
    case 0x27:
        emit PartChorusSendLevel(v);
        break;
    case 0x28:
        emit PartReverbSendLevel(v);
        break;
    case 0x29:
        emit PartOutputAssign(v);
        break;
    case 0x2B:
        emit PartScaleTuneType(v);
        break;
    case 0x2C:
        emit PartScaleTuneKey(v);
        break;
    case 0x2D:
        emit PartScaleTuneforC(v);
        break;
    case 0x2E:
        emit PartScaleTuneforCs(v);
        break;
    case 0x2F:
        emit PartScaleTuneforD(v);
        break;
    case 0x30:
        emit PartScaleTuneforDs(v);
        break;
    case 0x31:
        emit PartScaleTuneforE(v);
        break;
    case 0x32:
        emit PartScaleTuneforF(v);
        break;
    case 0x33:
        emit PartScaleTuneforFs(v);
        break;
    case 0x34:
        emit PartScaleTuneforG(v);
        break;
    case 0x35:
        emit PartScaleTuneforGs(v);
        break;
    case 0x36:
        emit PartScaleTuneforA(v);
        break;
    case 0x37:
        emit PartScaleTuneforAs(v);
        break;
    case 0x38:
        emit PartScaleTuneforB(v);
        break;
    case 0x39:
        emit ReceiveProgramChange(v);
        break;
    case 0x3A:
        emit ReceiveBankSelect(v);
        break;
    case 0x3B:
        emit ReceivePitchBend(v);
        break;
    case 0x3C:
        emit ReceivePolyphonicKeyPressure(v);
        break;
    case 0x3D:
        emit ReceiveChannelPressure(v);
        break;
    case 0x3E:
        emit ReceiveModulation(v);
        break;
    case 0x3F:
        emit ReceiveVolume(v);
        break;
    case 0x40:
        emit ReceivePan(v);
        break;
    case 0x41:
        emit ReceiveExpression(v);
        break;
    case 0x42:
        emit ReceiveHold(v);
        break;
    case 0x43:
        emit VelocityCurveType(v);
        break;
    case 0x44:
        emit MotionalSurroundLR(v);
        break;
    case 0x46:
        emit MotionalSurroundFB(v);
        break;
    case 0x48:
        emit MotionalSurroundWidth(v);
        break;
    case 0x49:
        emit MotionalSurroundAmbienceSendLevel(v);
        break;
    default:
        break;
    }
}

void Integra7Part::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a == 0x11){
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x11,getPartPortamentoTime());
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}
