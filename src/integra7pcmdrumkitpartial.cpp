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

#include "integra7pcmdrumkitpartial.h"

Integra7PCMDrumKitPartial::Integra7PCMDrumKitPartial(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}
{
    data[0x0B] = 0;
    data[0x0C] = 0;
    data[0x0D] = 0;
    data[0x0E] = 0;
    data[0x0F] = 0;
    data[0x10] = 64;
    data[0x11] = 0;
    data[0x12] = 0;
    data[0x13] = 0;
    data[0x14] = 64;
    data[0x15] = 0;
    data[0x16] = 0;
    data[0x19] = 0;
    data[0x1A] = 0;
    data[0x1B] = 0;
    data[0x1C] = 0;
    data[0x1D] = 0;
    data[0x1E] = 0;
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
    data[0x34] = 64;
    data[0x35] = 64;
    data[0x36] = 0;
    data[0x37] = 0;
    data[0x38] = 0;
    data[0x39] = 0;
    data[0x3A] = 64;
    data[0x3B] = 64;
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
    data[0x51] = 64;
    data[0x52] = 64;
    data[0x53] = 0;
    data[0x54] = 0;
    data[0x55] = 0;
    data[0x56] = 0;
    data[0x57] = 64;
    data[0x58] = 64;
    data[0x59] = 0;
    data[0x5A] = 0;
    data[0x5B] = 0;
    data[0x5C] = 0;
    data[0x5D] = 0;
    data[0x5E] = 0;
    data[0x5F] = 0;
    data[0x60] = 0;
    data[0x61] = 0;
    data[0x62] = 0;
    data[0x63] = 0;
    data[0x64] = 0;
    data[0x65] = 0;
    data[0x66] = 0;
    data[0x67] = 0;
    data[0x68] = 0;
    data[0x69] = 0;
    data[0x6A] = 0;
    data[0x6B] = 0;
    data[0x6C] = 0;
    data[0x6D] = 0;
    data[0x6E] = 64;
    data[0x6F] = 64;
    data[0x70] = 0;
    data[0x71] = 0;
    data[0x72] = 0;
    data[0x73] = 0;
    data[0x74] = 64;
    data[0x75] = 64;
    data[0x76] = 0;
    data[0x77] = 0;
    data[0x78] = 0;
    data[0x79] = 0;
    data[0x7A] = 0;
    data[0x7B] = 0;
    data[0x7C] = 0;
    data[0x7D] = 0;
    data[0x7E] = 0;
    data[0x7F] = 0;
    data[0x80] = 0;
    data[0x81] = 0;
    data[0x82] = 0;
    data[0x83] = 0;
    data[0x84] = 0;
    data[0x85] = 0;
    data[0x86] = 0;
    data[0x87] = 0;
    data[0x88] = 0;
    data[0x89] = 0;
    data[0x8A] = 0;
    data[0x8B] = 64;
    data[0x8C] = 64;
    data[0x8D] = 0;
    data[0x8E] = 0;
    data[0x8F] = 0;
    data[0x90] = 0;
    data[0x91] = 64;
    data[0x92] = 64;
    data[0x93] = 0;
    data[0x94] = 0;
    data[0x95] = 64;
    data[0x96] = 64;
    data[0x97] = 64;
    data[0x98] = 64;
    data[0x99] = 0;
    data[0x9A] = 0;
    data[0x9B] = 0;
    data[0x9C] = 0;
    data[0x9D] = 64;
    data[0x9E] = 64;
    data[0x9F] = 64;
    data[0xA0] = 64;
    data[0xA1] = 64;
    data[0xA2] = 0;
    data[0xA3] = 0;
    data[0xA4] = 0;
    data[0xA5] = 64;
    data[0xA6] = 0;
    data[0xA7] = 64;
    data[0xA8] = 64;
    data[0xA9] = 0;
    data[0xAA] = 64;
    data[0xAB] = 64;
    data[0xAC] = 64;
    data[0xAD] = 0;
    data[0xAE] = 0;
    data[0xAF] = 0;
    data[0xB0] = 0;
    data[0xB1] = 0;
    data[0xB2] = 0;
    data[0xB3] = 0;
    data[0xB4] = 0;
    data[0xB5] = 0;
    data[0xB6] = 0;
    data[0xB7] = 64;
    data[0xB8] = 64;
    data[0xB9] = 64;
    data[0xBA] = 0;
    data[0xBB] = 0;
    data[0xBC] = 0;
    data[0xBD] = 0;
    data[0xBE] = 0;
    data[0xBF] = 0;
    data[0xC0] = 0;
    data[0xC1] = 0;
}

void Integra7PCMDrumKitPartial::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit PartialName1(v);
        break;
    case 0x01:
        emit PartialName2(v);
        break;
    case 0x02:
        emit PartialName3(v);
        break;
    case 0x03:
        emit PartialName4(v);
        break;
    case 0x04:
        emit PartialName5(v);
        break;
    case 0x05:
        emit PartialName6(v);
        break;
    case 0x06:
        emit PartialName7(v);
        break;
    case 0x07:
        emit PartialName8(v);
        break;
    case 0x08:
        emit PartialName9(v);
        break;
    case 0x09:
        emit PartialName10(v);
        break;
    case 0x0A:
        emit PartialName11(v);
        break;
    case 0x0B:
        emit PartialName12(v);
        emit PartialName(getPartialName());
        break;
    case 0x0C:
        emit AssignType(v);
        break;
    case 0x0D:
        emit MuteGroup(v);
        break;
    case 0x0E:
        emit PartialLevel(v);
        break;
    case 0x0F:
        emit PartialCoarseTune(v);
        break;
    case 0x10:
        emit PartialFineTune(getPartialFineTune());
        break;
    case 0x11:
        emit PartialRandomPitchDepth(v);
        break;
    case 0x12:
        emit PartialPan(getPartialPan());
        break;
    case 0x13:
        emit PartialRandomPanDepth(v);
        break;
    case 0x14:
        emit PartialAlternatePanDepth(getPartialAlternatePanDepth());
        break;
    case 0x15:
        emit PartialEnvMode(v);
        break;
    case 0x16:
        emit PartialOutputLevel(v);
        break;
    case 0x19:
        emit PartialChorusSendLevel(v);
        break;
    case 0x1A:
        emit PartialReverbSendLevel(v);
        break;
    case 0x1B:
        emit PartialOutputAssign(v);
        break;
    case 0x1C:
        emit PartialPitchBendRange(v);
        break;
    case 0x1D:
        emit PartialReceiveExpression(v);
        break;
    case 0x1E:
        emit PartialReceiveHold(v);
        break;
    case 0x20:
        emit WMTVelocityControl(v);
        break;
    case 0x21:
        emit WMT1WaveSwitch(v);
        break;
    case 0x22:
        emit WMT1WaveGroupType(v);
        break;
    case 0x23:
        emit WMT1WaveGroupID(getWMT1WaveGroupID());
        break;
    case 0x27:
        emit WMT1WaveNumberL(getWMT1WaveNumberL());
        break;
    case 0x2B:
        emit WMT1WaveNumberR(getWMT1WaveNumberR());
        break;
    case 0x2F:
        emit WMT1WaveGain(v);
        break;
    case 0x30:
        emit WMT1WaveFXMSwitch(v);
        break;
    case 0x31:
        emit WMT1WaveFXMColor(v);
        break;
    case 0x32:
        emit WMT1WaveFXMDepth(v);
        break;
    case 0x33:
        emit WMT1WaveTempoSync(v);
        break;
    case 0x34:
        emit WMT1WaveCoarseTune(getWMT1WaveCoarseTune());
        break;
    case 0x35:
        emit WMT1WaveFineTune(getWMT1WaveFineTune());
        break;
    case 0x36:
        emit WMT1WavePan(getWMT1WavePan());
        break;
    case 0x37:
        emit WMT1WaveRandomPanSwitch(v);
        break;
    case 0x38:
        emit WMT1WaveAlternatePanSwitch(v);
        break;
    case 0x39:
        emit WMT1WaveLevel(v);
        break;
    case 0x3A:
        emit WMT1VelocityRangeLower(v);
        break;
    case 0x3B:
        emit WMT1VelocityRangeUpper(v);
        break;
    case 0x3C:
        emit WMT1VelocityFadeWidthLower(v);
        break;
    case 0x3D:
        emit WMT1VelocityFadeWidthUpper(v);
        break;
    case 0x3E:
        emit WMT2WaveSwitch(v);
        break;
    case 0x3F:
        emit WMT2WaveGroupType(v);
        break;
    case 0x40:
        emit WMT2WaveGroupID(getWMT2WaveGroupID());
        break;
    case 0x44:
        emit WMT2WaveNumberL(getWMT2WaveNumberL());
        break;
    case 0x48:
        emit WMT2WaveNumberR(getWMT2WaveNumberR());
        break;
    case 0x4C:
        emit WMT2WaveGain(v);
        break;
    case 0x4D:
        emit WMT2WaveFXMSwitch(v);
        break;
    case 0x4E:
        emit WMT2WaveFXMColor(v);
        break;
    case 0x4F:
        emit WMT2WaveFXMDepth(v);
        break;
    case 0x50:
        emit WMT2WaveTempoSync(v);
        break;
    case 0x51:
        emit WMT2WaveCoarseTune(getWMT2WaveCoarseTune());
        break;
    case 0x52:
        emit WMT2WaveFineTune(getWMT2WaveFineTune());
        break;
    case 0x53:
        emit WMT2WavePan(getWMT2WavePan());
        break;
    case 0x54:
        emit WMT2WaveRandomPanSwitch(v);
        break;
    case 0x55:
        emit WMT2WaveAlternatePanSwitch(v);
        break;
    case 0x56:
        emit WMT2WaveLevel(v);
        break;
    case 0x57:
        emit WMT2VelocityRangeLower(v);
        break;
    case 0x58:
        emit WMT2VelocityRangeUpper(v);
        break;
    case 0x59:
        emit WMT2VelocityFadeWidthLower(v);
        break;
    case 0x5A:
        emit WMT2VelocityFadeWidthUpper(v);
        break;
    case 0x5B:
        emit WMT3WaveSwitch(v);
        break;
    case 0x5C:
        emit WMT3WaveGroupType(v);
        break;
    case 0x5D:
        emit WMT3WaveGroupID(getWMT3WaveGroupID());
        break;
    case 0x61:
        emit WMT3WaveNumberL(getWMT3WaveNumberL());
        break;
    case 0x65:
        emit WMT3WaveNumberR(getWMT3WaveNumberR());
        break;
    case 0x69:
        emit WMT3WaveGain(v);
        break;
    case 0x6A:
        emit WMT3WaveFXMSwitch(v);
        break;
    case 0x6B:
        emit WMT3WaveFXMColor(v);
        break;
    case 0x6C:
        emit WMT3WaveFXMDepth(v);
        break;
    case 0x6D:
        emit WMT3WaveTempoSync(v);
        break;
    case 0x6E:
        emit WMT3WaveCoarseTune(getWMT3WaveCoarseTune());
        break;
    case 0x6F:
        emit WMT3WaveFineTune(getWMT3WaveFineTune());
        break;
    case 0x70:
        emit WMT3WavePan(getWMT3WavePan());
        break;
    case 0x71:
        emit WMT3WaveRandomPanSwitch(v);
        break;
    case 0x72:
        emit WMT3WaveAlternatePanSwitch(v);
        break;
    case 0x73:
        emit WMT3WaveLevel(v);
        break;
    case 0x74:
        emit WMT3VelocityRangeLower(v);
        break;
    case 0x75:
        emit WMT3VelocityRangeUpper(v);
        break;
    case 0x76:
        emit WMT3VelocityFadeWidthLower(v);
        break;
    case 0x77:
        emit WMT3VelocityFadeWidthUpper(v);
        break;
    case 0x78:
        emit WMT4WaveSwitch(v);
        break;
    case 0x79:
        emit WMT4WaveGroupType(v);
        break;
    case 0x7A:
        emit WMT4WaveGroupID(getWMT4WaveGroupID());
        break;
    case 0x7E:
        emit WMT4WaveNumberL(getWMT4WaveNumberL());
        break;
    case 0x82:
        emit WMT4WaveNumberR(getWMT4WaveNumberR());
        break;
    case 0x86:
        emit WMT4WaveGain(v);
        break;
    case 0x87:
        emit WMT4WaveFXMSwitch(v);
        break;
    case 0x88:
        emit WMT4WaveFXMColor(v);
        break;
    case 0x89:
        emit WMT4WaveFXMDepth(v);
        break;
    case 0x8A:
        emit WMT4WaveTempoSync(v);
        break;
    case 0x8B:
        emit WMT4WaveCoarseTune(getWMT4WaveCoarseTune());
        break;
    case 0x8C:
        emit WMT4WaveFineTune(getWMT4WaveFineTune());
        break;
    case 0x8D:
        emit WMT4WavePan(getWMT4WavePan());
        break;
    case 0x8E:
        emit WMT4WaveRandomPanSwitch(v);
        break;
    case 0x8F:
        emit WMT4WaveAlternatePanSwitch(v);
        break;
    case 0x90:
        emit WMT4WaveLevel(v);
        break;
    case 0x91:
        emit WMT4VelocityRangeLower(v);
        break;
    case 0x92:
        emit WMT4VelocityRangeUpper(v);
        break;
    case 0x93:
        emit WMT4VelocityFadeWidthLower(v);
        break;
    case 0x94:
        emit WMT4VelocityFadeWidthUpper(v);
        break;
    case 0x95:
        emit PitchEnvDepth(getPitchEnvDepth());
        break;
    case 0x96:
        emit PitchEnvVelocitySens(getPitchEnvVelocitySens());
        break;
    case 0x97:
        emit PitchEnvTime1VelocitySens(getPitchEnvTime1VelocitySens());
        break;
    case 0x98:
        emit PitchEnvTime4VelocitySens(getPitchEnvTime4VelocitySens());
        break;
    case 0x99:
        emit PitchEnvTime1(v);
        break;
    case 0x9A:
        emit PitchEnvTime2(v);
        break;
    case 0x9B:
        emit PitchEnvTime3(v);
        break;
    case 0x9C:
        emit PitchEnvTime4(v);
        break;
    case 0x9D:
        emit PitchEnvLevel0(getPitchEnvLevel0());
        break;
    case 0x9E:
        emit PitchEnvLevel1(getPitchEnvLevel1());
        break;
    case 0x9F:
        emit PitchEnvLevel2(getPitchEnvLevel2());
        break;
    case 0xA0:
        emit PitchEnvLevel3(getPitchEnvLevel3());
        break;
    case 0xA1:
        emit PitchEnvLevel4(getPitchEnvLevel4());
        break;
    case 0xA2:
        emit TVFFilterType(v);
        break;
    case 0xA3:
        emit TVFCutoffFrequency(v);
        break;
    case 0xA4:
        emit TVFCutoffVelocityCurve(v);
        break;
    case 0xA5:
        emit TVFCutoffVelocitySens(getTVFCutoffVelocitySens());
        break;
    case 0xA6:
        emit TVFResonance(v);
        break;
    case 0xA7:
        emit TVFResonanceVelocitySens(getTVFResonanceVelocitySens());
        break;
    case 0xA8:
        emit TVFEnvDepth(getTVFEnvDepth());
        break;
    case 0xA9:
        emit TVFEnvVelocityCurveType(v);
        break;
    case 0xAA:
        emit TVFEnvVelocitySens(getTVFEnvVelocitySens());
        break;
    case 0xAB:
        emit TVFEnvTime1VelocitySens(getTVFEnvTime1VelocitySens());
        break;
    case 0xAC:
        emit TVFEnvTime4VelocitySens(getTVFEnvTime4VelocitySens());
        break;
    case 0xAD:
        emit TVFEnvTime1(v);
        break;
    case 0xAE:
        emit TVFEnvTime2(v);
        break;
    case 0xAF:
        emit TVFEnvTime3(v);
        break;
    case 0xB0:
        emit TVFEnvTime4(v);
        break;
    case 0xB1:
        emit TVFEnvLevel0(v);
        break;
    case 0xB2:
        emit TVFEnvLevel1(v);
        break;
    case 0xB3:
        emit TVFEnvLevel2(v);
        break;
    case 0xB4:
        emit TVFEnvLevel3(v);
        break;
    case 0xB5:
        emit TVFEnvLevel4(v);
        break;
    case 0xB6:
        emit TVALevelVelocityCurve(v);
        break;
    case 0xB7:
        emit TVALevelVelocitySens(getTVALevelVelocitySens());
        break;
    case 0xB8:
        emit TVAEnvTime1VelocitySens(getTVAEnvTime1VelocitySens());
        break;
    case 0xB9:
        emit TVAEnvTime4VelocitySens(getTVAEnvTime4VelocitySens());
        break;
    case 0xBA:
        emit TVAEnvTime1(v);
        break;
    case 0xBB:
        emit TVAEnvTime2(v);
        break;
    case 0xBC:
        emit TVAEnvTime3(v);
        break;
    case 0xBD:
        emit TVAEnvTime4(v);
        break;
    case 0xBE:
        emit TVAEnvLevel1(v);
        break;
    case 0xBF:
        emit TVAEnvLevel2(v);
        break;
    case 0xC0:
        emit TVAEnvLevel3(v);
        break;
    case 0xC1:
        emit OneShotMode(v);
        break;
    default:
        break;
    }
}

void Integra7PCMDrumKitPartial::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        if (a == 0x23) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x23,getWMT1WaveGroupID());
        } else if (a == 0x27) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x27,getWMT1WaveNumberL());
        } else if (a == 0x2B) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x2B,getWMT1WaveNumberR());
        } else if (a == 0x40) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x40,getWMT2WaveGroupID());
        } else if (a == 0x44) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x44,getWMT2WaveNumberL());
        } else if (a == 0x48) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x48,getWMT2WaveNumberR());
        } else if (a == 0x5D) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x5D,getWMT3WaveGroupID());
        } else if (a == 0x61) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x61,getWMT3WaveNumberL());
        } else if (a == 0x65) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x65,getWMT3WaveNumberR());
        } else if (a == 0x7A) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x7A,getWMT4WaveGroupID());
        } else if (a == 0x7E) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x7E,getWMT4WaveNumberL());
        } else if (a == 0x82) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x82,getWMT4WaveNumberR());
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}
