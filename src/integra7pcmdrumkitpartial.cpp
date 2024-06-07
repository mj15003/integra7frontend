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
: Integra7ParameterSet{parent,o1,o2,o3}{}

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
        emit PartialFineTune(v);
        break;
    case 0x11:
        emit PartialRandomPitchDepth(v);
        break;
    case 0x12:
        emit PartialPan(v);
        break;
    case 0x13:
        emit PartialRandomPanDepth(v);
        break;
    case 0x14:
        emit PartialAlternatePanDepth(v);
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
        emit WMT1WaveCoarseTune(v);
        break;
    case 0x35:
        emit WMT1WaveFineTune(v);
        break;
    case 0x36:
        emit WMT1WavePan(v);
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
        emit WMT2WaveCoarseTune(v);
        break;
    case 0x52:
        emit WMT2WaveFineTune(v);
        break;
    case 0x53:
        emit WMT2WavePan(v);
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
        emit WMT3WaveCoarseTune(v);
        break;
    case 0x6F:
        emit WMT3WaveFineTune(v);
        break;
    case 0x70:
        emit WMT3WavePan(v);
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
        emit WMT4WaveCoarseTune(v);
        break;
    case 0x8C:
        emit WMT4WaveFineTune(v);
        break;
    case 0x8D:
        emit WMT4WavePan(v);
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
        emit PitchEnvDepth(v);
        break;
    case 0x96:
        emit PitchEnvVelocitySens(v);
        break;
    case 0x97:
        emit PitchEnvTime1VelocitySens(v);
        break;
    case 0x98:
        emit PitchEnvTime4VelocitySens(v);
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
        emit PitchEnvLevel0(v);
        break;
    case 0x9E:
        emit PitchEnvLevel1(v);
        break;
    case 0x9F:
        emit PitchEnvLevel2(v);
        break;
    case 0xA0:
        emit PitchEnvLevel3(v);
        break;
    case 0xA1:
        emit PitchEnvLevel4(v);
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
        emit TVFCutoffVelocitySens(v);
        break;
    case 0xA6:
        emit TVFResonance(v);
        break;
    case 0xA7:
        emit TVFResonanceVelocitySens(v);
        break;
    case 0xA8:
        emit TVFEnvDepth(v);
        break;
    case 0xA9:
        emit TVFEnvVelocityCurveType(v);
        break;
    case 0xAA:
        emit TVFEnvVelocitySens(v);
        break;
    case 0xAB:
        emit TVFEnvTime1VelocitySens(v);
        break;
    case 0xAC:
        emit TVFEnvTime4VelocitySens(v);
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
        emit TVALevelVelocitySens(v);
        break;
    case 0xB8:
        emit TVAEnvTime1VelocitySens(v);
        break;
    case 0xB9:
        emit TVAEnvTime4VelocitySens(v);
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
        data[a] = rdata[r++];
        EmitSignal(a,data[a]);
        ++a;
    }
}
