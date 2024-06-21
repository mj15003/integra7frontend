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

#ifndef INTEGRA7PCMSYNTHTONEPARTIAL_H
#define INTEGRA7PCMSYNTHTONEPARTIAL_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7PCMSynthTonePartial : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7PCMSynthTonePartial(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getPartialLevel() {return data[0x00];}
    int getPartialCoarseTune() {return data[0x01]-64;}
    int getPartialFineTune() {return data[0x02]-64;}
    int getPartialRandomPitchDepth() {return data[0x03];}
    int getPartialPan() {return data[0x04]-64;}
    int getPartialPanKeyfollow() {return (data[0x05]-64)*10;}
    int getPartialRandomPanDepth() {return data[0x06];}
    int getPartialAlternatePanDepth() {return data[0x07]-64;}
    int getPartialEnvMode() {return data[0x08];}
    int getPartialDelayMode() {return data[0x09];}
    int getPartialDelayTime() {return data[0x0A]<<4|data[0x0B];}
    int getPartialOutputLevel() {return data[0x0C];}
    int getPartialChorusSendLevel() {return data[0x0F];}
    int getPartialReverbSendLevel() {return data[0x10];}
    int getPartialReceiveBender() {return data[0x12];}
    int getPartialReceiveExpression() {return data[0x13];}
    int getPartialReceiveHold() {return data[0x14];}
    int getPartialRedamperSwitch() {return data[0x16];}
    int getPartialControl1Switch1() {return data[0x17];}
    int getPartialControl1Switch2() {return data[0x18];}
    int getPartialControl1Switch3() {return data[0x19];}
    int getPartialControl1Switch4() {return data[0x1A];}
    int getPartialControl2Switch1() {return data[0x1B];}
    int getPartialControl2Switch2() {return data[0x1C];}
    int getPartialControl2Switch3() {return data[0x1D];}
    int getPartialControl2Switch4() {return data[0x1E];}
    int getPartialControl3Switch1() {return data[0x1F];}
    int getPartialControl3Switch2() {return data[0x20];}
    int getPartialControl3Switch3() {return data[0x21];}
    int getPartialControl3Switch4() {return data[0x22];}
    int getPartialControl4Switch1() {return data[0x23];}
    int getPartialControl4Switch2() {return data[0x24];}
    int getPartialControl4Switch3() {return data[0x25];}
    int getPartialControl4Switch4() {return data[0x26];}
    int getWaveGroupType() {return data[0x27];}
    int getWaveGroupID() {return data[0x28]<<12|data[0x29]<<8|data[0x2A]<<4|data[0x2B];}
    int getWaveNumberL() {return data[0x2C]<<12|data[0x2D]<<8|data[0x2E]<<4|data[0x2F];}
    int getWaveNumberR() {return data[0x30]<<12|data[0x31]<<8|data[0x32]<<4|data[0x33];}
    int getWaveGain() {return data[0x34];}
    int getWaveFXMSwitch() {return data[0x35];}
    int getWaveFXMColor() {return data[0x36];}
    int getWaveFXMDepth() {return data[0x37];}
    int getWaveTempoSync() {return data[0x38];}
    int getWavePitchKeyfollow() {return (data[0x39]-64)*10;}
    int getPitchEnvDepth() {return data[0x3A]-64;}
    int getPitchEnvVelocitySens() {return data[0x3B]-64;}
    int getPitchEnvTime1VelocitySens() {return data[0x3C]-64;}
    int getPitchEnvTime4VelocitySens() {return data[0x3D]-64;}
    int getPitchEnvTimeKeyfollow() {return (data[0x3E]-64)*10;}
    int getPitchEnvTime1() {return data[0x3F];}
    int getPitchEnvTime2() {return data[0x40];}
    int getPitchEnvTime3() {return data[0x41];}
    int getPitchEnvTime4() {return data[0x42];}
    int getPitchEnvLevel0() {return data[0x43]-64;}
    int getPitchEnvLevel1() {return data[0x44]-64;}
    int getPitchEnvLevel2() {return data[0x45]-64;}
    int getPitchEnvLevel3() {return data[0x46]-64;}
    int getPitchEnvLevel4() {return data[0x47]-64;}
    int getTVFFilterType() {return data[0x48];}
    int getTVFCutoffFrequency() {return data[0x49];}
    int getTVFCutoffKeyfollow() {return (data[0x4A]-64)*10;}
    int getTVFCutoffVelocityCurve() {return data[0x4B];}
    int getTVFCutoffVelocitySens() {return data[0x4C]-64;}
    int getTVFResonance() {return data[0x4D];}
    int getTVFResonanceVelocitySens() {return data[0x4E]-64;}
    int getTVFEnvDepth() {return data[0x4F]-64;}
    int getTVFEnvVelocityCurve() {return data[0x50];}
    int getTVFEnvVelocitySens() {return data[0x51]-64;}
    int getTVFEnvTime1VelocitySens() {return data[0x52]-64;}
    int getTVFEnvTime4VelocitySens() {return data[0x53]-64;}
    int getTVFEnvTimeKeyfollow() {return (data[0x54]-64)*10;}
    int getTVFEnvTime1() {return data[0x55];}
    int getTVFEnvTime2() {return data[0x56];}
    int getTVFEnvTime3() {return data[0x57];}
    int getTVFEnvTime4() {return data[0x58];}
    int getTVFEnvLevel0() {return data[0x59];}
    int getTVFEnvLevel1() {return data[0x5A];}
    int getTVFEnvLevel2() {return data[0x5B];}
    int getTVFEnvLevel3() {return data[0x5C];}
    int getTVFEnvLevel4() {return data[0x5D];}
    int getBiasLevel() {return (data[0x5E]-64)*10;}
    int getBiasPosition() {return data[0x5F];}
    int getBiasDirection() {return data[0x60];}
    int getTVALevelVelocityCurve() {return data[0x61];}
    int getTVALevelVelocitySens() {return data[0x62]-64;}
    int getTVAEnvTime1VelocitySens() {return data[0x63]-64;}
    int getTVAEnvTime4VelocitySens() {return data[0x64]-64;}
    int getTVAEnvTimeKeyfollow() {return (data[0x65]-64)*10;}
    int getTVAEnvTime1() {return data[0x66];}
    int getTVAEnvTime2() {return data[0x67];}
    int getTVAEnvTime3() {return data[0x68];}
    int getTVAEnvTime4() {return data[0x69];}
    int getTVAEnvLevel1() {return data[0x6A];}
    int getTVAEnvLevel2() {return data[0x6B];}
    int getTVAEnvLevel3() {return data[0x6C];}
    int getLFO1Waveform() {return data[0x6D];}
    int getLFO1Rate() {return data[0x6E]<<4|data[0x6F];}
    int getLFO1Offset() {return data[0x70];}
    int getLFO1RateDetune() {return data[0x71];}
    int getLFO1DelayTime() {return data[0x72];}
    int getLFO1DelayTimeKeyfollow() {return (data[0x73]-64)*10;}
    int getLFO1FadeMode() {return data[0x74];}
    int getLFO1FadeTime() {return data[0x75];}
    int getLFO1KeyTrigger() {return data[0x76];}
    int getLFO1PitchDepth() {return data[0x77]-64;}
    int getLFO1TVFDepth() {return data[0x78]-64;}
    int getLFO1TVADepth() {return data[0x79]-64;}
    int getLFO1PanDepth() {return data[0x7A]-64;}
    int getLFO2Waveform() {return data[0x7B];}
    int getLFO2Rate() {return data[0x7C]<<4|data[0x7D];}
    int getLFO2Offset() {return data[0x7E];}
    int getLFO2RateDetune() {return data[0x7F];}
    int getLFO2DelayTime() {return data[0x80];}
    int getLFO2DelayTimeKeyfollow() {return (data[0x81]-64)*10;}
    int getLFO2FadeMode() {return data[0x82];}
    int getLFO2FadeTime() {return data[0x83];}
    int getLFO2KeyTrigger() {return data[0x84];}
    int getLFO2PitchDepth() {return data[0x85]-64;}
    int getLFO2TVFDepth() {return data[0x86]-64;}
    int getLFO2TVADepth() {return data[0x87]-64;}
    int getLFO2PanDepth() {return data[0x88]-64;}
    int getLFOStepType() {return data[0x89];}
    int getLFOStep1() {return data[0x8A]-64;}
    int getLFOStep2() {return data[0x8B]-64;}
    int getLFOStep3() {return data[0x8C]-64;}
    int getLFOStep4() {return data[0x8D]-64;}
    int getLFOStep5() {return data[0x8E]-64;}
    int getLFOStep6() {return data[0x8F]-64;}
    int getLFOStep7() {return data[0x90]-64;}
    int getLFOStep8() {return data[0x91]-64;}
    int getLFOStep9() {return data[0x92]-64;}
    int getLFOStep10() {return data[0x93]-64;}
    int getLFOStep11() {return data[0x94]-64;}
    int getLFOStep12() {return data[0x95]-64;}
    int getLFOStep13() {return data[0x96]-64;}
    int getLFOStep14() {return data[0x97]-64;}
    int getLFOStep15() {return data[0x98]-64;}
    int getLFOStep16() {return data[0x99]-64;}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 154;}
    int GetItemsNumber() {return 140;}

public slots:

    void setPartialLevel(int v) {DataSet(0x00,v);}
    void setPartialCoarseTune(int v) {DataSetOffset(0x01,v,64);}
    void setPartialFineTune(int v) {DataSetOffset(0x02,v,64);}
    void setPartialRandomPitchDepth(int v) {DataSet(0x03,v);}
    void setPartialPan(int v) {DataSetOffset(0x04,v,64);}
    void setPartialPanKeyfollow(int v) {DataSetOffsetGain(0x05,v,64,10);}
    void setPartialRandomPanDepth(int v) {DataSet(0x06,v);}
    void setPartialAlternatePanDepth(int v) {DataSetOffset(0x07,v,64);}
    void setPartialEnvMode(int v) {DataSet(0x08,v);}
    void setPartialDelayMode(int v) {DataSet(0x09,v);}
    void setPartialDelayTime(int v) {DataSet2x4B(0x0A,v);}
    void setPartialOutputLevel(int v) {DataSet(0x0C,v);}
    void setPartialChorusSendLevel(int v) {DataSet(0x0F,v);}
    void setPartialReverbSendLevel(int v) {DataSet(0x10,v);}
    void setPartialReceiveBender(int v) {DataSet(0x12,v);}
    void setPartialReceiveExpression(int v) {DataSet(0x13,v);}
    void setPartialReceiveHold(int v) {DataSet(0x14,v);}
    void setPartialRedamperSwitch(int v) {DataSet(0x16,v);}
    void setPartialControl1Switch1(int v) {DataSet(0x17,v);}
    void setPartialControl1Switch2(int v) {DataSet(0x18,v);}
    void setPartialControl1Switch3(int v) {DataSet(0x19,v);}
    void setPartialControl1Switch4(int v) {DataSet(0x1A,v);}
    void setPartialControl2Switch1(int v) {DataSet(0x1B,v);}
    void setPartialControl2Switch2(int v) {DataSet(0x1C,v);}
    void setPartialControl2Switch3(int v) {DataSet(0x1D,v);}
    void setPartialControl2Switch4(int v) {DataSet(0x1E,v);}
    void setPartialControl3Switch1(int v) {DataSet(0x1F,v);}
    void setPartialControl3Switch2(int v) {DataSet(0x20,v);}
    void setPartialControl3Switch3(int v) {DataSet(0x21,v);}
    void setPartialControl3Switch4(int v) {DataSet(0x22,v);}
    void setPartialControl4Switch1(int v) {DataSet(0x23,v);}
    void setPartialControl4Switch2(int v) {DataSet(0x24,v);}
    void setPartialControl4Switch3(int v) {DataSet(0x25,v);}
    void setPartialControl4Switch4(int v) {DataSet(0x26,v);}
    void setWaveGroupType(int v) {DataSet(0x27,v);}
    void setWaveGroupID(int v) {DataSet4x4B(0x28,v);}
    void setWaveNumberL(int v) {DataSet4x4B(0x2C,v);}
    void setWaveNumberR(int v) {DataSet4x4B(0x30,v);}
    void setWaveGain(int v) {DataSet(0x34,v);}
    void setWaveFXMSwitch(int v) {DataSet(0x35,v);}
    void setWaveFXMColor(int v) {DataSet(0x36,v);}
    void setWaveFXMDepth(int v) {DataSet(0x37,v);}
    void setWaveTempoSync(int v) {DataSet(0x38,v);}
    void setWavePitchKeyfollow(int v) {DataSetOffsetGain(0x39,v,64,10);}
    void setPitchEnvDepth(int v) {DataSetOffset(0x3A,v,64);}
    void setPitchEnvVelocitySens(int v) {DataSetOffset(0x3B,v,64);}
    void setPitchEnvTime1VelocitySens(int v) {DataSetOffset(0x3C,v,64);}
    void setPitchEnvTime4VelocitySens(int v) {DataSetOffset(0x3D,v,64);}
    void setPitchEnvTimeKeyfollow(int v) {DataSetOffsetGain(0x3E,v,64,10);}
    void setPitchEnvTime1(int v) {DataSet(0x3F,v);}
    void setPitchEnvTime2(int v) {DataSet(0x40,v);}
    void setPitchEnvTime3(int v) {DataSet(0x41,v);}
    void setPitchEnvTime4(int v) {DataSet(0x42,v);}
    void setPitchEnvLevel0(int v) {DataSetOffset(0x43,v,64);}
    void setPitchEnvLevel1(int v) {DataSetOffset(0x44,v,64);}
    void setPitchEnvLevel2(int v) {DataSetOffset(0x45,v,64);}
    void setPitchEnvLevel3(int v) {DataSetOffset(0x46,v,64);}
    void setPitchEnvLevel4(int v) {DataSetOffset(0x47,v,64);}
    void setTVFFilterType(int v) {DataSet(0x48,v);}
    void setTVFCutoffFrequency(int v) {DataSet(0x49,v);}
    void setTVFCutoffKeyfollow(int v) {DataSetOffsetGain(0x4A,v,64,10);}
    void setTVFCutoffVelocityCurve(int v) {DataSet(0x4B,v);}
    void setTVFCutoffVelocitySens(int v) {DataSetOffset(0x4C,v,64);}
    void setTVFResonance(int v) {DataSet(0x4D,v);}
    void setTVFResonanceVelocitySens(int v) {DataSetOffset(0x4E,v,64);}
    void setTVFEnvDepth(int v) {DataSetOffset(0x4F,v,64);}
    void setTVFEnvVelocityCurve(int v) {DataSet(0x50,v);}
    void setTVFEnvVelocitySens(int v) {DataSetOffset(0x51,v,64);}
    void setTVFEnvTime1VelocitySens(int v) {DataSetOffset(0x52,v,64);}
    void setTVFEnvTime4VelocitySens(int v) {DataSetOffset(0x53,v,64);}
    void setTVFEnvTimeKeyfollow(int v) {DataSetOffsetGain(0x54,v,64,10);}
    void setTVFEnvTime1(int v) {DataSet(0x55,v);}
    void setTVFEnvTime2(int v) {DataSet(0x56,v);}
    void setTVFEnvTime3(int v) {DataSet(0x57,v);}
    void setTVFEnvTime4(int v) {DataSet(0x58,v);}
    void setTVFEnvLevel0(int v) {DataSet(0x59,v);}
    void setTVFEnvLevel1(int v) {DataSet(0x5A,v);}
    void setTVFEnvLevel2(int v) {DataSet(0x5B,v);}
    void setTVFEnvLevel3(int v) {DataSet(0x5C,v);}
    void setTVFEnvLevel4(int v) {DataSet(0x5D,v);}
    void setBiasLevel(int v) {DataSetOffsetGain(0x5E,v,64,10);}
    void setBiasPosition(int v) {DataSet(0x5F,v);}
    void setBiasDirection(int v) {DataSet(0x60,v);}
    void setTVALevelVelocityCurve(int v) {DataSet(0x61,v);}
    void setTVALevelVelocitySens(int v) {DataSetOffset(0x62,v,64);}
    void setTVAEnvTime1VelocitySens(int v) {DataSetOffset(0x63,v,64);}
    void setTVAEnvTime4VelocitySens(int v) {DataSetOffset(0x64,v,64);}
    void setTVAEnvTimeKeyfollow(int v) {DataSetOffsetGain(0x65,v,64,10);}
    void setTVAEnvTime1(int v) {DataSet(0x66,v);}
    void setTVAEnvTime2(int v) {DataSet(0x67,v);}
    void setTVAEnvTime3(int v) {DataSet(0x68,v);}
    void setTVAEnvTime4(int v) {DataSet(0x69,v);}
    void setTVAEnvLevel1(int v) {DataSet(0x6A,v);}
    void setTVAEnvLevel2(int v) {DataSet(0x6B,v);}
    void setTVAEnvLevel3(int v) {DataSet(0x6C,v);}
    void setLFO1Waveform(int v) {DataSet(0x6D,v);}
    void setLFO1Rate(int v) {DataSet2x4B(0x6E,v);}
    void setLFO1Offset(int v) {DataSet(0x70,v);}
    void setLFO1RateDetune(int v) {DataSet(0x71,v);}
    void setLFO1DelayTime(int v) {DataSet(0x72,v);}
    void setLFO1DelayTimeKeyfollow(int v) {DataSetOffsetGain(0x73,v,64,10);}
    void setLFO1FadeMode(int v) {DataSet(0x74,v);}
    void setLFO1FadeTime(int v) {DataSet(0x75,v);}
    void setLFO1KeyTrigger(int v) {DataSet(0x76,v);}
    void setLFO1PitchDepth(int v) {DataSetOffset(0x77,v,64);}
    void setLFO1TVFDepth(int v) {DataSetOffset(0x78,v,64);}
    void setLFO1TVADepth(int v) {DataSetOffset(0x79,v,64);}
    void setLFO1PanDepth(int v) {DataSetOffset(0x7A,v,64);}
    void setLFO2Waveform(int v) {DataSet(0x7B,v);}
    void setLFO2Rate(int v) {DataSet2x4B(0x7C,v);}
    void setLFO2Offset(int v) {DataSet(0x7E,v);}
    void setLFO2RateDetune(int v) {DataSet(0x7F,v);}
    void setLFO2DelayTime(int v) {DataSet(0x80,v);}
    void setLFO2DelayTimeKeyfollow(int v) {DataSetOffsetGain(0x81,v,64,10);}
    void setLFO2FadeMode(int v) {DataSet(0x82,v);}
    void setLFO2FadeTime(int v) {DataSet(0x83,v);}
    void setLFO2KeyTrigger(int v) {DataSet(0x84,v);}
    void setLFO2PitchDepth(int v) {DataSetOffset(0x85,v,64);}
    void setLFO2TVFDepth(int v) {DataSetOffset(0x86,v,64);}
    void setLFO2TVADepth(int v) {DataSetOffset(0x87,v,64);}
    void setLFO2PanDepth(int v) {DataSetOffset(0x88,v,64);}
    void setLFOStepType(int v) {DataSet(0x89,v);}
    void setLFOStep1(int v) {DataSetOffset(0x8A,v,64);}
    void setLFOStep2(int v) {DataSetOffset(0x8B,v,64);}
    void setLFOStep3(int v) {DataSetOffset(0x8C,v,64);}
    void setLFOStep4(int v) {DataSetOffset(0x8D,v,64);}
    void setLFOStep5(int v) {DataSetOffset(0x8E,v,64);}
    void setLFOStep6(int v) {DataSetOffset(0x8F,v,64);}
    void setLFOStep7(int v) {DataSetOffset(0x90,v,64);}
    void setLFOStep8(int v) {DataSetOffset(0x91,v,64);}
    void setLFOStep9(int v) {DataSetOffset(0x92,v,64);}
    void setLFOStep10(int v) {DataSetOffset(0x93,v,64);}
    void setLFOStep11(int v) {DataSetOffset(0x94,v,64);}
    void setLFOStep12(int v) {DataSetOffset(0x95,v,64);}
    void setLFOStep13(int v) {DataSetOffset(0x96,v,64);}
    void setLFOStep14(int v) {DataSetOffset(0x97,v,64);}
    void setLFOStep15(int v) {DataSetOffset(0x98,v,64);}
    void setLFOStep16(int v) {DataSetOffset(0x99,v,64);}

signals:

    void PartialLevel(int v);
    void PartialCoarseTune(int v);
    void PartialFineTune(int v);
    void PartialRandomPitchDepth(int v);
    void PartialPan(int v);
    void PartialPanKeyfollow(int v);
    void PartialRandomPanDepth(int v);
    void PartialAlternatePanDepth(int v);
    void PartialEnvMode(int v);
    void PartialDelayMode(int v);
    void PartialDelayTime(int v);
    void PartialOutputLevel(int v);
    void PartialChorusSendLevel(int v);
    void PartialReverbSendLevel(int v);
    void PartialReceiveBender(int v);
    void PartialReceiveExpression(int v);
    void PartialRedamperSwitch(int v);
    void PartialControl1Switch1(int v);
    void PartialControl1Switch2(int v);
    void PartialControl1Switch3(int v);
    void PartialControl1Switch4(int v);
    void PartialControl2Switch1(int v);
    void PartialControl2Switch2(int v);
    void PartialControl2Switch3(int v);
    void PartialControl2Switch4(int v);
    void PartialControl3Switch1(int v);
    void PartialControl3Switch2(int v);
    void PartialControl3Switch3(int v);
    void PartialControl3Switch4(int v);
    void PartialControl4Switch1(int v);
    void PartialControl4Switch2(int v);
    void PartialControl4Switch3(int v);
    void PartialControl4Switch4(int v);
    void WaveGroupType(int v);
    void WaveGroupID(int v);
    void WaveNumberL(int v);
    void WaveNumberR(int v);
    void WaveGain(int v);
    void WaveFXMSwitch(int v);
    void WaveFXMColor(int v);
    void WaveFXMDepth(int v);
    void WaveTempoSync(int v);
    void WavePitchKeyfollow(int v);
    void PitchEnvDepth(int v);
    void PitchEnvVelocitySens(int v);
    void PitchEnvTime1VelocitySens(int v);
    void PitchEnvTime4VelocitySens(int v);
    void PitchEnvTimeKeyfollow(int v);
    void PitchEnvTime1(int v);
    void PitchEnvTime2(int v);
    void PitchEnvTime3(int v);
    void PitchEnvTime4(int v);
    void PitchEnvLevel0(int v);
    void PitchEnvLevel1(int v);
    void PitchEnvLevel2(int v);
    void PitchEnvLevel3(int v);
    void PitchEnvLevel4(int v);
    void TVFFilterType(int v);
    void TVFCutoffFrequency(int v);
    void TVFCutoffKeyfollow(int v);
    void TVFCutoffVelocityCurve(int v);
    void TVFCutoffVelocitySens(int v);
    void TVFResonance(int v);
    void TVFResonanceVelocitySens(int v);
    void TVFEnvDepth(int v);
    void TVFEnvVelocityCurve(int v);
    void TVFEnvVelocitySens(int v);
    void TVFEnvTime1VelocitySens(int v);
    void TVFEnvTime4VelocitySens(int v);
    void TVFEnvTimeKeyfollow(int v);
    void TVFEnvTime1(int v);
    void TVFEnvTime2(int v);
    void TVFEnvTime3(int v);
    void TVFEnvTime4(int v);
    void TVFEnvLevel0(int v);
    void TVFEnvLevel1(int v);
    void TVFEnvLevel2(int v);
    void TVFEnvLevel3(int v);
    void TVFEnvLevel4(int v);
    void BiasLevel(int v);
    void BiasPosition(int v);
    void BiasDirection(int v);
    void TVALevelVelocityCurve(int v);
    void TVALevelVelocitySens(int v);
    void TVAEnvTime1VelocitySens(int v);
    void TVAEnvTime4VelocitySens(int v);
    void TVAEnvTimeKeyfollow(int v);
    void TVAEnvTime1(int v);
    void TVAEnvTime2(int v);
    void TVAEnvTime3(int v);
    void TVAEnvTime4(int v);
    void TVAEnvLevel1(int v);
    void TVAEnvLevel2(int v);
    void TVAEnvLevel3(int v);
    void LFO1Waveform(int v);
    void LFO1Rate(int v);
    void LFO1Offset(int v);
    void LFO1RateDetune(int v);
    void LFO1DelayTime(int v);
    void LFO1DelayTimeKeyfollow(int v);
    void LFO1FadeMode(int v);
    void LFO1FadeTime(int v);
    void LFO1KeyTrigger(int v);
    void LFO1PitchDepth(int v);
    void LFO1TVFDepth(int v);
    void LFO1TVADepth(int v);
    void LFO1PanDepth(int v);
    void LFO2Waveform(int v);
    void LFO2Rate(int v);
    void LFO2Offset(int v);
    void LFO2RateDetune(int v);
    void LFO2DelayTime(int v);
    void LFO2DelayTimeKeyfollow(int v);
    void LFO2FadeMode(int v);
    void LFO2FadeTime(int v);
    void LFO2KeyTrigger(int v);
    void LFO2PitchDepth(int v);
    void LFO2TVFDepth(int v);
    void LFO2TVADepth(int v);
    void LFO2PanDepth(int v);
    void LFOStepType(int v);
    void LFOStep1(int v);
    void LFOStep2(int v);
    void LFOStep3(int v);
    void LFOStep4(int v);
    void LFOStep5(int v);
    void LFOStep6(int v);
    void LFOStep7(int v);
    void LFOStep8(int v);
    void LFOStep9(int v);
    void LFOStep10(int v);
    void LFOStep11(int v);
    void LFOStep12(int v);
    void LFOStep13(int v);
    void LFOStep14(int v);
    void LFOStep15(int v);
    void LFOStep16(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7PCMSYNTHTONEPARTIAL_H
