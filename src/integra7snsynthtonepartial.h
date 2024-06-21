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

#ifndef INTEGRA7SNSYNTHTONEPARTIAL_H
#define INTEGRA7SNSYNTHTONEPARTIAL_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7SNSynthTonePartial : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7SNSynthTonePartial(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getOSCWave() {return data[0x00];}
    int getOSCWaveVariation() {return data[0x01];}
    int getOSCPitch() {return data[0x03]-64;}
    int getOSCDetune() {return data[0x04]-64;}
    int getOSCPulseWidthModDepth() {return data[0x05];}
    int getOSCPulseWidth() {return data[0x06];}
    int getOSCPitchEnvAttackTime() {return data[0x07];}
    int getOSCPitchEnvDecay() {return data[0x08];}
    int getOSCPitchEnvDepth() {return data[0x09]-64;}
    int getFILTERMode() {return data[0x0A];}
    int getFILTERSlope() {return data[0x0B];}
    int getFILTERCutoff() {return data[0x0C];}
    int getFILTERCutoffKeyfollow() {return (data[0x0D]-64)*10;}
    int getFILTEREnvVelocitySens() {return data[0x0E]-64;}
    int getFILTERResonance() {return data[0x0F];}
    int getFILTEREnvAttackTime() {return data[0x10];}
    int getFILTEREnvDecayTime() {return data[0x11];}
    int getFILTEREnvSustainLevel() {return data[0x12];}
    int getFILTEREnvReleaseTime() {return data[0x13];}
    int getFILTEREnvDepth() {return data[0x14]-64;}
    int getAMPLevel() {return data[0x15];}
    int getAMPLevelVelocitySens() {return data[0x16]-64;}
    int getAMPEnvAttackTime() {return data[0x17];}
    int getAMPEnvDecayTime() {return data[0x18];}
    int getAMPEnvSustainLevel() {return data[0x19];}
    int getAMPEnvReleaseTime() {return data[0x1A];}
    int getAMPPan() {return data[0x1B]-64;}
    int getLFOShape() {return data[0x1C];}
    int getLFORate() {return data[0x1D];}
    int getLFOTempoSyncSwitch() {return data[0x1E];}
    int getLFOTempoSyncNote() {return data[0x1F];}
    int getLFOFadeTime() {return data[0x20];}
    int getLFOKeyTrigger() {return data[0x21];}
    int getLFOPitchDepth() {return data[0x22]-64;}
    int getLFOFilterDepth() {return data[0x23]-64;}
    int getLFOAmpDepth() {return data[0x24]-64;}
    int getLFOPanDepth() {return data[0x25]-64;}
    int getModulationLFOShape() {return data[0x26];}
    int getModulationLFORate() {return data[0x27];}
    int getModulationLFOTempoSyncSwitch() {return data[0x28];}
    int getModulationLFOTempoSyncNote() {return data[0x29];}
    int getOSCPulseWidthShift() {return data[0x2A];}
    int getModulationLFOPitchDepth() {return data[0x2C]-64;}
    int getModulationLFOFilterDepth() {return data[0x2D]-64;}
    int getModulationLFOAmpDepth() {return data[0x2E]-64;}
    int getModulationLFOPanDepth() {return data[0x2F]-64;}
    int getCutoffAftertouchSens() {return data[0x30]-64;}
    int getLevelAftertouchSens() {return data[0x31]-64;}
    int getWaveGain() {return data[0x34];}
    int getWaveNumber() {return data[0x35]<<12|data[0x36]<<8|data[0x37]<<4|data[0x38];}
    int getHPFCutoff() {return data[0x39];}
    int getSuperSawDetune() {return data[0x3A];}
    int getModulationLFORateControl() {return data[0x3B]-64;}
    int getAMPLevelKeyfollow() {return (data[0x3C]-64)*10;}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x3D;}
    int GetItemsNumber() {return 0x3A;}

public slots:

    void setOSCWave(int v) {DataSet(0x00,v);}
    void setOSCWaveVariation(int v) {DataSet(0x01,v);}
    void setOSCPitch(int v) {DataSetOffset(0x03,v,64);}
    void setOSCDetune(int v) {DataSetOffset(0x04,v,64);}
    void setOSCPulseWidthModDepth(int v) {DataSet(0x05,v);}
    void setOSCPulseWidth(int v) {DataSet(0x06,v);}
    void setOSCPitchEnvAttackTime(int v) {DataSet(0x07,v);}
    void setOSCPitchEnvDecay(int v) {DataSet(0x08,v);}
    void setOSCPitchEnvDepth(int v) {DataSetOffset(0x09,v,64);}
    void setFILTERMode(int v) {DataSet(0x0A,v);}
    void setFILTERSlope(int v) {DataSet(0x0B,v);}
    void setFILTERCutoff(int v) {DataSet(0x0C,v);}
    void setFILTERCutoffKeyfollow(int v) {DataSetOffsetGain(0x0D,v,64,10);}
    void setFILTEREnvVelocitySens(int v) {DataSetOffset(0x0E,v,64);}
    void setFILTERResonance(int v) {DataSet(0x0F,v);}
    void setFILTEREnvAttackTime(int v) {DataSet(0x10,v);}
    void setFILTEREnvDecayTime(int v) {DataSet(0x11,v);}
    void setFILTEREnvSustainLevel(int v) {DataSet(0x12,v);}
    void setFILTEREnvReleaseTime(int v) {DataSet(0x13,v);}
    void setFILTEREnvDepth(int v) {DataSetOffset(0x14,v,64);}
    void setAMPLevel(int v) {DataSet(0x15,v);}
    void setAMPLevelVelocitySens(int v) {DataSetOffset(0x16,v,64);}
    void setAMPEnvAttackTime(int v) {DataSet(0x17,v);}
    void setAMPEnvDecayTime(int v) {DataSet(0x18,v);}
    void setAMPEnvSustainLevel(int v) {DataSet(0x19,v);}
    void setAMPEnvReleaseTime(int v) {DataSet(0x1A,v);}
    void setAMPPan(int v) {DataSetOffset(0x1B,v,64);}
    void setLFOShape(int v) {DataSet(0x1C,v);}
    void setLFORate(int v) {DataSet(0x1D,v);}
    void setLFOTempoSyncSwitch(int v) {DataSet(0x1E,v);}
    void setLFOTempoSyncNote(int v) {DataSet(0x1F,v);}
    void setLFOFadeTime(int v) {DataSet(0x20,v);}
    void setLFOKeyTrigger(int v) {DataSet(0x21,v);}
    void setLFOPitchDepth(int v) {DataSetOffset(0x22,v,64);}
    void setLFOFilterDepth(int v) {DataSetOffset(0x23,v,64);}
    void setLFOAmpDepth(int v) {DataSetOffset(0x24,v,64);}
    void setLFOPanDepth(int v) {DataSetOffset(0x25,v,64);}
    void setModulationLFOShape(int v) {DataSet(0x26,v);}
    void setModulationLFORate(int v) {DataSet(0x27,v);}
    void setModulationLFOTempoSyncSwitch(int v) {DataSet(0x28,v);}
    void setModulationLFOTempoSyncNote(int v) {DataSet(0x29,v);}
    void setOSCPulseWidthShift(int v) {DataSet(0x2A,v);}
    void setModulationLFOPitchDepth(int v) {DataSetOffset(0x2C,v,64);}
    void setModulationLFOFilterDepth(int v) {DataSetOffset(0x2D,v,64);}
    void setModulationLFOAmpDepth(int v) {DataSetOffset(0x2E,v,64);}
    void setModulationLFOPanDepth(int v) {DataSetOffset(0x2F,v,64);}
    void setCutoffAftertouchSens(int v) {DataSetOffset(0x30,v,64);}
    void setLevelAftertouchSens(int v) {DataSetOffset(0x31,v,64);}
    void setWaveGain(int v) {DataSet(0x34,v);}
    void setWaveNumber(int v) {DataSet4x4B(0x35,v);}
    void setHPFCutoff(int v) {DataSet(0x39,v);}
    void setSuperSawDetune(int v) {DataSet(0x3A,v);}
    void setModulationLFORateControl(int v) {DataSetOffset(0x3B,v,64);}
    void setAMPLevelKeyfollow(int v) {DataSetOffsetGain(0x3C,v,64,10);}

signals:

    void OSCWave(int v);
    void OSCWaveVariation(int v);
    void OSCPitch(int v);
    void OSCDetune(int v);
    void OSCPulseWidthModDepth(int v);
    void OSCPulseWidth(int v);
    void OSCPitchEnvAttackTime(int v);
    void OSCPitchEnvDecay(int v);
    void OSCPitchEnvDepth(int v);
    void FILTERMode(int v);
    void FILTERSlope(int v);
    void FILTERCutoff(int v);
    void FILTERCutoffKeyfollow(int v);
    void FILTEREnvVelocitySens(int v);
    void FILTERResonance(int v);
    void FILTEREnvAttackTime(int v);
    void FILTEREnvDecayTime(int v);
    void FILTEREnvSustainLevel(int v);
    void FILTEREnvReleaseTime(int v);
    void FILTEREnvDepth(int v);
    void AMPLevel(int v);
    void AMPLevelVelocitySens(int v);
    void AMPEnvAttackTime(int v);
    void AMPEnvDecayTime(int v);
    void AMPEnvSustainLevel(int v);
    void AMPEnvReleaseTime(int v);
    void AMPPan(int v);
    void LFOShape(int v);
    void LFORate(int v);
    void LFOTempoSyncSwitch(int v);
    void LFOTempoSyncNote(int v);
    void LFOFadeTime(int v);
    void LFOKeyTrigger(int v);
    void LFOPitchDepth(int v);
    void LFOFilterDepth(int v);
    void LFOAmpDepth(int v);
    void LFOPanDepth(int v);
    void ModulationLFOShape(int v);
    void ModulationLFORate(int v);
    void ModulationLFOTempoSyncSwitch(int v);
    void ModulationLFOTempoSyncNote(int v);
    void OSCPulseWidthShift(int v);
    void ModulationLFOPitchDepth(int v);
    void ModulationLFOFilterDepth(int v);
    void ModulationLFOAmpDepth(int v);
    void ModulationLFOPanDepth(int v);
    void CutoffAftertouchSens(int v);
    void LevelAftertouchSens(int v);
    void WaveGain(int v);
    void WaveNumber(int v);
    void HPFCutoff(int v);
    void SuperSawDetune(int v);
    void ModulationLFORateControl(int v);
    void AMPLevelKeyfollow(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7SNSYNTHTONEPARTIAL_H
