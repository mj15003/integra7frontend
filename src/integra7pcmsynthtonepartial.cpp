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

#include "integra7pcmsynthtonepartial.h"

Integra7PCMSynthTonePartial::Integra7PCMSynthTonePartial(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}{}

void Integra7PCMSynthTonePartial::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit PartialLevel(v);
        break;
    case 0x01:
        emit PartialCoarseTune(v);
        break;
    case 0x02:
        emit PartialFineTune(v);
        break;
    case 0x03:
        emit PartialRandomPitchDepth(v);
        break;
    case 0x04:
        emit PartialPan(v);
        break;
    case 0x05:
        emit PartialPanKeyfollow(v);
        break;
    case 0x06:
        emit PartialRandomPanDepth(v);
        break;
    case 0x07:
        emit PartialAlternatePanDepth(v);
        break;
    case 0x08:
        emit PartialEnvMode(v);
        break;
    case 0x09:
        emit PartialDelayMode(v);
        break;
    case 0x0A:
        emit PartialDelayTime(getPartialDelayTime());
        break;
    case 0x0C:
        emit PartialOutputLevel(v);
        break;
    case 0x0F:
        emit PartialChorusSendLevel(v);
        break;
    case 0x10:
        emit PartialReverbSendLevel(v);
        break;
    case 0x12:
        emit PartialReceiveBender(v);
        break;
    case 0x13:
        emit PartialReceiveExpression(v);
        break;
    case 0x16:
        emit PartialRedamperSwitch(v);
        break;
    case 0x17:
        emit PartialControl1Switch1(v);
        break;
    case 0x18:
        emit PartialControl1Switch2(v);
        break;
    case 0x19:
        emit PartialControl1Switch3(v);
        break;
    case 0x1A:
        emit PartialControl1Switch4(v);
        break;
    case 0x1B:
        emit PartialControl2Switch1(v);
        break;
    case 0x1C:
        emit PartialControl2Switch2(v);
        break;
    case 0x1D:
        emit PartialControl2Switch3(v);
        break;
    case 0x1E:
        emit PartialControl2Switch4(v);
        break;
    case 0x1F:
        emit PartialControl3Switch1(v);
        break;
    case 0x20:
        emit PartialControl3Switch2(v);
        break;
    case 0x21:
        emit PartialControl3Switch3(v);
        break;
    case 0x22:
        emit PartialControl3Switch4(v);
        break;
    case 0x23:
        emit PartialControl4Switch1(v);
        break;
    case 0x24:
        emit PartialControl4Switch2(v);
        break;
    case 0x25:
        emit PartialControl4Switch3(v);
        break;
    case 0x26:
        emit PartialControl4Switch4(v);
        break;
    case 0x27:
        emit WaveGroupType(v);
        break;
    case 0x28:
        emit WaveGroupID(getWaveGroupID());
        break;
    case 0x2C:
        emit WaveNumberL(getWaveNumberL());
        break;
    case 0x30:
        emit WaveNumberR(getWaveNumberR());
        break;
    case 0x34:
        emit WaveGain(v);
        break;
    case 0x35:
        emit WaveFXMSwitch(v);
        break;
    case 0x36:
        emit WaveFXMColor(v);
        break;
    case 0x37:
        emit WaveFXMDepth(v);
        break;
    case 0x38:
        emit WaveTempoSync(v);
        break;
    case 0x39:
        emit WavePitchKeyfollow(v);
        break;
    case 0x3A:
        emit PitchEnvDepth(v);
        break;
    case 0x3B:
        emit PitchEnvVelocitySens(v);
        break;
    case 0x3C:
        emit PitchEnvTime1VelocitySens(v);
        break;
    case 0x3D:
        emit PitchEnvTime4VelocitySens(v);
        break;
    case 0x3E:
        emit PitchEnvTimeKeyfollow(v);
        break;
    case 0x3F:
        emit PitchEnvTime1(v);
        break;
    case 0x40:
        emit PitchEnvTime2(v);
        break;
    case 0x41:
        emit PitchEnvTime3(v);
        break;
    case 0x42:
        emit PitchEnvTime4(v);
        break;
    case 0x43:
        emit PitchEnvLevel0(v);
        break;
    case 0x44:
        emit PitchEnvLevel1(v);
        break;
    case 0x45:
        emit PitchEnvLevel2(v);
        break;
    case 0x46:
        emit PitchEnvLevel3(v);
        break;
    case 0x47:
        emit PitchEnvLevel4(v);
        break;
    case 0x48:
        emit TVFFilterType(v);
        break;
    case 0x49:
        emit TVFCutoffFrequency(v);
        break;
    case 0x4A:
        emit TVFCutoffKeyfollow(v);
        break;
    case 0x4B:
        emit TVFCutoffVelocityCurve(v);
        break;
    case 0x4C:
        emit TVFCutoffVelocitySens(v);
        break;
    case 0x4D:
        emit TVFResonance(v);
        break;
    case 0x4E:
        emit TVFResonanceVelocitySens(v);
        break;
    case 0x4F:
        emit TVFEnvDepth(v);
        break;
    case 0x50:
        emit TVFEnvVelocityCurve(v);
        break;
    case 0x51:
        emit TVFEnvVelocitySens(v);
        break;
    case 0x52:
        emit TVFEnvTime1VelocitySens(v);
        break;
    case 0x53:
        emit TVFEnvTime4VelocitySens(v);
        break;
    case 0x54:
        emit TVFEnvTimeKeyfollow(v);
        break;
    case 0x55:
        emit TVFEnvTime1(v);
        break;
    case 0x56:
        emit TVFEnvTime2(v);
        break;
    case 0x57:
        emit TVFEnvTime3(v);
        break;
    case 0x58:
        emit TVFEnvTime4(v);
        break;
    case 0x59:
        emit TVFEnvLevel0(v);
        break;
    case 0x5A:
        emit TVFEnvLevel1(v);
        break;
    case 0x5B:
        emit TVFEnvLevel2(v);
        break;
    case 0x5C:
        emit TVFEnvLevel3(v);
        break;
    case 0x5D:
        emit TVFEnvLevel4(v);
        break;
    case 0x5E:
        emit BiasLevel(v);
        break;
    case 0x5F:
        emit BiasPosition(v);
        break;
    case 0x60:
        emit BiasDirection(v);
        break;
    case 0x61:
        emit TVALevelVelocityCurve(v);
        break;
    case 0x62:
        emit TVALevelVelocitySens(v);
        break;
    case 0x63:
        emit TVAEnvTime1VelocitySens(v);
        break;
    case 0x64:
        emit TVAEnvTime4VelocitySens(v);
        break;
    case 0x65:
        emit TVAEnvTimeKeyfollow(v);
        break;
    case 0x66:
        emit TVAEnvTime1(v);
        break;
    case 0x67:
        emit TVAEnvTime2(v);
        break;
    case 0x68:
        emit TVAEnvTime3(v);
        break;
    case 0x69:
        emit TVAEnvTime4(v);
        break;
    case 0x6A:
        emit TVAEnvLevel1(v);
        break;
    case 0x6B:
        emit TVAEnvLevel2(v);
        break;
    case 0x6C:
        emit TVAEnvLevel3(v);
        break;
    case 0x6D:
        emit LFO1Waveform(v);
        break;
    case 0x6E:
        emit LFO1Rate(getLFO1Rate());
        break;
    case 0x70:
        emit LFO1Offset(v);
        break;
    case 0x71:
        emit LFO1RateDetune(v);
        break;
    case 0x72:
        emit LFO1DelayTime(v);
        break;
    case 0x73:
        emit LFO1DelayTimeKeyfollow(v);
        break;
    case 0x74:
        emit LFO1FadeMode(v);
        break;
    case 0x75:
        emit LFO1FadeTime(v);
        break;
    case 0x76:
        emit LFO1KeyTrigger(v);
        break;
    case 0x77:
        emit LFO1PitchDepth(v);
        break;
    case 0x78:
        emit LFO1TVFDepth(v);
        break;
    case 0x79:
        emit LFO1TVADepth(v);
        break;
    case 0x7A:
        emit LFO1PanDepth(v);
        break;
    case 0x7B:
        emit LFO2Waveform(v);
        break;
    case 0x7C:
        emit LFO2Rate(getLFO2Rate());
        break;
    case 0x7E:
        emit LFO2Offset(v);
        break;
    case 0x7F:
        emit LFO2RateDetune(v);
        break;
    case 0x80:
        emit LFO2DelayTime(v);
        break;
    case 0x81:
        emit LFO2DelayTimeKeyfollow(v);
        break;
    case 0x82:
        emit LFO2FadeMode(v);
        break;
    case 0x83:
        emit LFO2FadeTime(v);
        break;
    case 0x84:
        emit LFO2KeyTrigger(v);
        break;
    case 0x85:
        emit LFO2PitchDepth(v);
        break;
    case 0x86:
        emit LFO2TVFDepth(v);
        break;
    case 0x87:
        emit LFO2TVADepth(v);
        break;
    case 0x88:
        emit LFO2PanDepth(v);
        break;
    case 0x89:
        emit LFOStepType(v);
        break;
    case 0x8A:
        emit LFOStep1(v);
        break;
    case 0x8B:
        emit LFOStep2(v);
        break;
    case 0x8C:
        emit LFOStep3(v);
        break;
    case 0x8D:
        emit LFOStep4(v);
        break;
    case 0x8E:
        emit LFOStep5(v);
        break;
    case 0x8F:
        emit LFOStep6(v);
        break;
    case 0x90:
        emit LFOStep7(v);
        break;
    case 0x91:
        emit LFOStep8(v);
        break;
    case 0x92:
        emit LFOStep9(v);
        break;
    case 0x93:
        emit LFOStep10(v);
        break;
    case 0x94:
        emit LFOStep11(v);
        break;
    case 0x95:
        emit LFOStep12(v);
        break;
    case 0x96:
        emit LFOStep13(v);
        break;
    case 0x97:
        emit LFOStep14(v);
        break;
    case 0x98:
        emit LFOStep15(v);
        break;
    case 0x99:
        emit LFOStep16(v);
        break;
    default:
        break;
    }
}

void Integra7PCMSynthTonePartial::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        data[a] = rdata[r++];
        EmitSignal(a,data[a]);
        ++a;
    }
}
