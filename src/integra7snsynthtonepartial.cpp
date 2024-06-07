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

#include "integra7snsynthtonepartial.h"

Integra7SNSynthTonePartial::Integra7SNSynthTonePartial(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}{}

void Integra7SNSynthTonePartial::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit OSCWave(v);
        break;
    case 0x01:
        emit OSCWaveVariation(v);
        break;
    case 0x03:
        emit OSCPitch(v);
        break;
    case 0x04:
        emit OSCDetune(v);
        break;
    case 0x05:
        emit OSCPulseWidthModDepth(v);
        break;
    case 0x06:
        emit OSCPulseWidth(v);
        break;
    case 0x07:
        emit OSCPitchEnvAttackTime(v);
        break;
    case 0x08:
        emit OSCPitchEnvDecay(v);
        break;
    case 0x09:
        emit OSCPitchEnvDepth(v);
        break;
    case 0x0A:
        emit FILTERMode(v);
        break;
    case 0x0B:
        emit FILTERSlope(v);
        break;
    case 0x0C:
        emit FILTERCutoff(v);
        break;
    case 0x0D:
        emit FILTERCutoffKeyfollow(v);
        break;
    case 0x0E:
        emit FILTEREnvVelocitySens(v);
        break;
    case 0x0F:
        emit FILTERResonance(v);
        break;
    case 0x10:
        emit FILTEREnvAttackTime(v);
        break;
    case 0x11:
        emit FILTEREnvDecayTime(v);
        break;
    case 0x12:
        emit FILTEREnvSustainLevel(v);
        break;
    case 0x13:
        emit FILTEREnvReleaseTime(v);
        break;
    case 0x14:
        emit FILTEREnvDepth(v);
        break;
    case 0x15:
        emit AMPLevel(v);
        break;
    case 0x16:
        emit AMPLevelVelocitySens(v);
        break;
    case 0x17:
        emit AMPEnvAttackTime(v);
        break;
    case 0x18:
        emit AMPEnvDecayTime(v);
        break;
    case 0x19:
        emit AMPEnvSustainLevel(v);
        break;
    case 0x1A:
        emit AMPEnvReleaseTime(v);
        break;
    case 0x1B:
        emit AMPPan(v);
        break;
    case 0x1C:
        emit LFOShape(v);
        break;
    case 0x1D:
        emit LFORate(v);
        break;
    case 0x1E:
        emit LFOTempoSyncSwitch(v);
        break;
    case 0x1F:
        emit LFOTempoSyncNote(v);
        break;
    case 0x20:
        emit LFOFadeTime(v);
        break;
    case 0x21:
        emit LFOKeyTrigger(v);
        break;
    case 0x22:
        emit LFOPitchDepth(v);
        break;
    case 0x23:
        emit LFOFilterDepth(v);
        break;
    case 0x24:
        emit LFOAmpDepth(v);
        break;
    case 0x25:
        emit LFOPanDepth(v);
        break;
    case 0x26:
        emit ModulationLFOShape(v);
        break;
    case 0x27:
        emit ModulationLFORate(v);
        break;
    case 0x28:
        emit ModulationLFOTempoSyncSwitch(v);
        break;
    case 0x29:
        emit ModulationLFOTempoSyncNote(v);
        break;
    case 0x2A:
        emit OSCPulseWidthShift(v);
        break;
    case 0x2C:
        emit ModulationLFOPitchDepth(v);
        break;
    case 0x2D:
        emit ModulationLFOFilterDepth(v);
        break;
    case 0x2E:
        emit ModulationLFOAmpDepth(v);
        break;
    case 0x2F:
        emit ModulationLFOPanDepth(v);
        break;
    case 0x30:
        emit CutoffAftertouchSens(v);
        break;
    case 0x31:
        emit LevelAftertouchSens(v);
        break;
    case 0x34:
        emit WaveGain(v);
        break;
    case 0x35:
        emit WaveNumber(getWaveNumber());
        break;
    case 0x39:
        emit HPFCutoff(v);
        break;
    case 0x3A:
        emit SuperSawDetune(v);
        break;
    case 0x3B:
        emit ModulationLFORateControl(v);
        break;
    case 0x3C:
        emit AMPLevelKeyfollow(v);
        break;
    default:
        break;
    }
}

void Integra7SNSynthTonePartial::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        data[a] = rdata[r++];
        EmitSignal(a,data[a]);
        ++a;
    }
}
