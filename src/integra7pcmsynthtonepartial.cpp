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
: Integra7ParameterSet{parent,o1,o2,o3}
{
    /* Put correct initialization value into certain fields which does not allow zero */
    data[0x00] = 0;
    data[0x01] = 64;
    data[0x02] = 64;
    data[0x03] = 0;
    data[0x04] = 0;
    data[0x05] = 64;
    data[0x06] = 0;
    data[0x07] = 64;
    data[0x08] = 0;
    data[0x09] = 0;
    data[0x0A] = 0;
    data[0x0B] = 0;
    data[0x0C] = 0;
    data[0x0F] = 0;
    data[0x10] = 0;
    data[0x12] = 0;
    data[0x13] = 0;
    data[0x14] = 0;
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
    data[0x39] = 64;
    data[0x3A] = 64;
    data[0x3B] = 64;
    data[0x3C] = 64;
    data[0x3D] = 64;
    data[0x3E] = 64;
    data[0x3F] = 0;
    data[0x40] = 0;
    data[0x41] = 0;
    data[0x42] = 0;
    data[0x43] = 64;
    data[0x44] = 64;
    data[0x45] = 64;
    data[0x46] = 64;
    data[0x47] = 64;
    data[0x48] = 0;
    data[0x49] = 0;
    data[0x4A] = 64;
    data[0x4B] = 0;
    data[0x4C] = 64;
    data[0x4D] = 0;
    data[0x4E] = 64;
    data[0x4F] = 64;
    data[0x50] = 0;
    data[0x51] = 64;
    data[0x52] = 64;
    data[0x53] = 64;
    data[0x54] = 64;
    data[0x55] = 0;
    data[0x56] = 0;
    data[0x57] = 0;
    data[0x58] = 0;
    data[0x59] = 0;
    data[0x5A] = 0;
    data[0x5B] = 0;
    data[0x5C] = 0;
    data[0x5D] = 0;
    data[0x5E] = 64;
    data[0x5F] = 0;
    data[0x60] = 0;
    data[0x61] = 0;
    data[0x62] = 64;
    data[0x63] = 64;
    data[0x64] = 64;
    data[0x65] = 64;
    data[0x66] = 0;
    data[0x67] = 0;
    data[0x68] = 0;
    data[0x69] = 0;
    data[0x6A] = 0;
    data[0x6B] = 0;
    data[0x6C] = 0;
    data[0x6D] = 0;
    data[0x6E] = 0;
    data[0x6F] = 0;
    data[0x70] = 0;
    data[0x71] = 0;
    data[0x72] = 0;
    data[0x73] = 64;
    data[0x74] = 0;
    data[0x75] = 0;
    data[0x76] = 0;
    data[0x77] = 64;
    data[0x78] = 64;
    data[0x79] = 64;
    data[0x7A] = 64;
    data[0x7B] = 0;
    data[0x7C] = 0;
    data[0x7D] = 0;
    data[0x7E] = 0;
    data[0x7F] = 0;
    data[0x80] = 0;
    data[0x81] = 64;
    data[0x82] = 0;
    data[0x83] = 0;
    data[0x84] = 0;
    data[0x85] = 64;
    data[0x86] = 64;
    data[0x87] = 64;
    data[0x88] = 64;
    data[0x89] = 0;
    data[0x8A] = 64;
    data[0x8B] = 64;
    data[0x8C] = 64;
    data[0x8D] = 64;
    data[0x8E] = 64;
    data[0x8F] = 64;
    data[0x90] = 64;
    data[0x91] = 64;
    data[0x92] = 64;
    data[0x93] = 64;
    data[0x94] = 64;
    data[0x95] = 64;
    data[0x96] = 64;
    data[0x97] = 64;
    data[0x98] = 64;
    data[0x99] = 64;
}

void Integra7PCMSynthTonePartial::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit PartialLevel(v);
        break;
    case 0x01:
        emit PartialCoarseTune(getPartialCoarseTune());
        break;
    case 0x02:
        emit PartialFineTune(getPartialFineTune());
        break;
    case 0x03:
        emit PartialRandomPitchDepth(v);
        break;
    case 0x04:
        emit PartialPan(getPartialPan());
        break;
    case 0x05:
        emit PartialPanKeyfollow(getPartialPanKeyfollow());
        break;
    case 0x06:
        emit PartialRandomPanDepth(v);
        break;
    case 0x07:
        emit PartialAlternatePanDepth(getPartialAlternatePanDepth());
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
    case 0x14:
        emit PartialReceiveHold(v);
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
        emit WavePitchKeyfollow(getWavePitchKeyfollow());
        break;
    case 0x3A:
        emit PitchEnvDepth(getPitchEnvDepth());
        break;
    case 0x3B:
        emit PitchEnvVelocitySens(getPitchEnvVelocitySens());
        break;
    case 0x3C:
        emit PitchEnvTime1VelocitySens(getPitchEnvTime1VelocitySens());
        break;
    case 0x3D:
        emit PitchEnvTime4VelocitySens(getPitchEnvTime4VelocitySens());
        break;
    case 0x3E:
        emit PitchEnvTimeKeyfollow(getPitchEnvTimeKeyfollow());
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
        emit PitchEnvLevel0(getPitchEnvLevel0());
        break;
    case 0x44:
        emit PitchEnvLevel1(getPitchEnvLevel1());
        break;
    case 0x45:
        emit PitchEnvLevel2(getPitchEnvLevel2());
        break;
    case 0x46:
        emit PitchEnvLevel3(getPitchEnvLevel3());
        break;
    case 0x47:
        emit PitchEnvLevel4(getPitchEnvLevel4());
        break;
    case 0x48:
        emit TVFFilterType(v);
        break;
    case 0x49:
        emit TVFCutoffFrequency(v);
        break;
    case 0x4A:
        emit TVFCutoffKeyfollow(getTVFCutoffKeyfollow());
        break;
    case 0x4B:
        emit TVFCutoffVelocityCurve(v);
        break;
    case 0x4C:
        emit TVFCutoffVelocitySens(getTVFCutoffVelocitySens());
        break;
    case 0x4D:
        emit TVFResonance(v);
        break;
    case 0x4E:
        emit TVFResonanceVelocitySens(getTVFResonanceVelocitySens());
        break;
    case 0x4F:
        emit TVFEnvDepth(getTVFEnvDepth());
        break;
    case 0x50:
        emit TVFEnvVelocityCurve(v);
        break;
    case 0x51:
        emit TVFEnvVelocitySens(getTVFEnvVelocitySens());
        break;
    case 0x52:
        emit TVFEnvTime1VelocitySens(getTVFEnvTime1VelocitySens());
        break;
    case 0x53:
        emit TVFEnvTime4VelocitySens(getTVFEnvTime4VelocitySens());
        break;
    case 0x54:
        emit TVFEnvTimeKeyfollow(getTVFEnvTimeKeyfollow());
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
        emit BiasLevel(getBiasLevel());
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
        emit TVALevelVelocitySens(getTVALevelVelocitySens());
        break;
    case 0x63:
        emit TVAEnvTime1VelocitySens(getTVAEnvTime1VelocitySens());
        break;
    case 0x64:
        emit TVAEnvTime4VelocitySens(getTVAEnvTime4VelocitySens());
        break;
    case 0x65:
        emit TVAEnvTimeKeyfollow(getTVAEnvTimeKeyfollow());
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
        emit LFO1DelayTimeKeyfollow(getLFO1DelayTimeKeyfollow());
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
        emit LFO1PitchDepth(getLFO1PitchDepth());
        break;
    case 0x78:
        emit LFO1TVFDepth(getLFO1TVFDepth());
        break;
    case 0x79:
        emit LFO1TVADepth(getLFO1TVADepth());
        break;
    case 0x7A:
        emit LFO1PanDepth(getLFO1PanDepth());
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
        emit LFO2DelayTimeKeyfollow(getLFO2DelayTimeKeyfollow());
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
        emit LFO2PitchDepth(getLFO2PitchDepth());
        break;
    case 0x86:
        emit LFO2TVFDepth(getLFO2TVFDepth());
        break;
    case 0x87:
        emit LFO2TVADepth(getLFO2TVADepth());
        break;
    case 0x88:
        emit LFO2PanDepth(getLFO2PanDepth());
        break;
    case 0x89:
        emit LFOStepType(v);
        break;
    case 0x8A:
        emit LFOStep1(getLFOStep1());
        break;
    case 0x8B:
        emit LFOStep2(getLFOStep2());
        break;
    case 0x8C:
        emit LFOStep3(getLFOStep3());
        break;
    case 0x8D:
        emit LFOStep4(getLFOStep4());
        break;
    case 0x8E:
        emit LFOStep5(getLFOStep5());
        break;
    case 0x8F:
        emit LFOStep6(getLFOStep6());
        break;
    case 0x90:
        emit LFOStep7(getLFOStep7());
        break;
    case 0x91:
        emit LFOStep8(getLFOStep8());
        break;
    case 0x92:
        emit LFOStep9(getLFOStep9());
        break;
    case 0x93:
        emit LFOStep10(getLFOStep10());
        break;
    case 0x94:
        emit LFOStep11(getLFOStep11());
        break;
    case 0x95:
        emit LFOStep12(getLFOStep12());
        break;
    case 0x96:
        emit LFOStep13(getLFOStep13());
        break;
    case 0x97:
        emit LFOStep14(getLFOStep14());
        break;
    case 0x98:
        emit LFOStep15(getLFOStep15());
        break;
    case 0x99:
        emit LFOStep16(getLFOStep16());
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
        if (a == 0x0A) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x0A,getPartialDelayTime());
        } else if (a == 0x28) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x28,getWaveGroupID());
        } else if (a == 0x2C) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x2C,getWaveNumberL());
        } else if (a == 0x30) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x30,getWaveNumberR());
        } else if (a == 0x6E) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x6E,getLFO1Rate());
        } else if (a == 0x7C) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x7C,getLFO2Rate());
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}
