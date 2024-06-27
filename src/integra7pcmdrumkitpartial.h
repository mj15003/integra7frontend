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

#ifndef INTEGRA7PCMDRUMKITPARTIAL_H
#define INTEGRA7PCMDRUMKITPARTIAL_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7PCMDrumKitPartial : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7PCMDrumKitPartial(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getPartialName1() {return data[0x00];}
    int getPartialName2() {return data[0x01];}
    int getPartialName3() {return data[0x02];}
    int getPartialName4() {return data[0x03];}
    int getPartialName5() {return data[0x04];}
    int getPartialName6() {return data[0x05];}
    int getPartialName7() {return data[0x06];}
    int getPartialName8() {return data[0x07];}
    int getPartialName9() {return data[0x08];}
    int getPartialName10() {return data[0x09];}
    int getPartialName11() {return data[0x0A];}
    int getPartialName12() {return data[0x0B];}
    QLatin1StringView getPartialName() {return QLatin1StringView((char*)&data[0],(char*)&data[0x0B]);}
    int getAssignType() {return data[0x0C];}
    int getMuteGroup() {return data[0x0D];}
    int getPartialLevel() {return data[0x0E];}
    int getPartialCoarseTune() {return data[0x0F];}
    int getPartialFineTune() {return data[0x10]-64;}
    int getPartialRandomPitchDepth() {return data[0x11];}
    int getPartialPan() {return data[0x12]-64;}
    int getPartialRandomPanDepth() {return data[0x13];}
    int getPartialAlternatePanDepth() {return data[0x14]-64;}
    int getPartialEnvMode() {return data[0x15];}
    int getPartialOutputLevel() {return data[0x16];}
    int getPartialChorusSendLevel() {return data[0x19];}
    int getPartialReverbSendLevel() {return data[0x1A];}
    int getPartialOutputAssign() {return data[0x1B];}
    int getPartialPitchBendRange() {return data[0x1C];}
    int getPartialReceiveExpression() {return data[0x1D];}
    int getPartialReceiveHold() {return data[0x1E];}
    int getWMTVelocityControl() {return data[0x20];}
    int getWMT1WaveSwitch() {return data[0x21];}
    int getWMT1WaveGroupType() {return data[0x22];}
    int getWMT1WaveGroupID() {return data[0x23]<<12|data[0x24]<<8|data[0x25]<<4|data[0x26];}
    int getWMT1WaveNumberL() {return data[0x27]<<12|data[0x28]<<8|data[0x29]<<4|data[0x2A];}
    int getWMT1WaveNumberR() {return data[0x2B]<<12|data[0x2C]<<8|data[0x2D]<<4|data[0x2E];}
    int getWMT1WaveGain() {return data[0x2F];}
    int getWMT1WaveFXMSwitch() {return data[0x30];}
    int getWMT1WaveFXMColor() {return data[0x31];}
    int getWMT1WaveFXMDepth() {return data[0x32];}
    int getWMT1WaveTempoSync() {return data[0x33];}
    int getWMT1WaveCoarseTune() {return data[0x34]-64;}
    int getWMT1WaveFineTune() {return data[0x35]-64;}
    int getWMT1WavePan() {return data[0x36]-64;}
    int getWMT1WaveRandomPanSwitch() {return data[0x37];}
    int getWMT1WaveAlternatePanSwitch() {return data[0x38];}
    int getWMT1WaveLevel() {return data[0x39];}
    int getWMT1VelocityRangeLower() {return data[0x3A];}
    int getWMT1VelocityRangeUpper() {return data[0x3B];}
    int getWMT1VelocityFadeWidthLower() {return data[0x3C];}
    int getWMT1VelocityFadeWidthUpper() {return data[0x3D];}
    int getWMT2WaveSwitch() {return data[0x3E];}
    int getWMT2WaveGroupType() {return data[0x3F];}
    int getWMT2WaveGroupID() {return data[0x40]<<12|data[0x41]<<8|data[0x42]<<4|data[0x43];}
    int getWMT2WaveNumberL() {return data[0x44]<<12|data[0x45]<<8|data[0x46]<<4|data[0x47];}
    int getWMT2WaveNumberR() {return data[0x48]<<12|data[0x49]<<8|data[0x4A]<<4|data[0x4B];}
    int getWMT2WaveGain() {return data[0x4C];}
    int getWMT2WaveFXMSwitch() {return data[0x4D];}
    int getWMT2WaveFXMColor() {return data[0x4E];}
    int getWMT2WaveFXMDepth() {return data[0x4F];}
    int getWMT2WaveTempoSync() {return data[0x50];}
    int getWMT2WaveCoarseTune() {return data[0x51]-64;}
    int getWMT2WaveFineTune() {return data[0x52]-64;}
    int getWMT2WavePan() {return data[0x53]-64;}
    int getWMT2WaveRandomPanSwitch() {return data[0x54];}
    int getWMT2WaveAlternatePanSwitch() {return data[0x55];}
    int getWMT2WaveLevel() {return data[0x56];}
    int getWMT2VelocityRangeLower() {return data[0x57];}
    int getWMT2VelocityRangeUpper() {return data[0x58];}
    int getWMT2VelocityFadeWidthLower() {return data[0x59];}
    int getWMT2VelocityFadeWidthUpper() {return data[0x5A];}
    int getWMT3WaveSwitch() {return data[0x5B];}
    int getWMT3WaveGroupType() {return data[0x5C];}
    int getWMT3WaveGroupID() {return data[0x5D]<<12|data[0x5E]<<8|data[0x5F]<<4|data[0x60];}
    int getWMT3WaveNumberL() {return data[0x61]<<12|data[0x62]<<8|data[0x63]<<4|data[0x64];}
    int getWMT3WaveNumberR() {return data[0x65]<<12|data[0x66]<<8|data[0x67]<<4|data[0x68];}
    int getWMT3WaveGain() {return data[0x69];}
    int getWMT3WaveFXMSwitch() {return data[0x6A];}
    int getWMT3WaveFXMColor() {return data[0x6B];}
    int getWMT3WaveFXMDepth() {return data[0x6C];}
    int getWMT3WaveTempoSync() {return data[0x6D];}
    int getWMT3WaveCoarseTune() {return data[0x6E]-64;}
    int getWMT3WaveFineTune() {return data[0x6F]-64;}
    int getWMT3WavePan() {return data[0x70]-64;}
    int getWMT3WaveRandomPanSwitch() {return data[0x71];}
    int getWMT3WaveAlternatePanSwitch() {return data[0x72];}
    int getWMT3WaveLevel() {return data[0x73];}
    int getWMT3VelocityRangeLower() {return data[0x74];}
    int getWMT3VelocityRangeUpper() {return data[0x75];}
    int getWMT3VelocityFadeWidthLower() {return data[0x76];}
    int getWMT3VelocityFadeWidthUpper() {return data[0x77];}
    int getWMT4WaveSwitch() {return data[0x78];}
    int getWMT4WaveGroupType() {return data[0x79];}
    int getWMT4WaveGroupID() {return data[0x7A]<<12|data[0x7B]<<8|data[0x7C]<<4|data[0x7D];}
    int getWMT4WaveNumberL() {return data[0x7E]<<12|data[0x7F]<<8|data[0x80]<<4|data[0x81];}
    int getWMT4WaveNumberR() {return data[0x82]<<12|data[0x83]<<8|data[0x84]<<4|data[0x85];}
    int getWMT4WaveGain() {return data[0x86];}
    int getWMT4WaveFXMSwitch() {return data[0x87];}
    int getWMT4WaveFXMColor() {return data[0x88];}
    int getWMT4WaveFXMDepth() {return data[0x89];}
    int getWMT4WaveTempoSync() {return data[0x8A];}
    int getWMT4WaveCoarseTune() {return data[0x8B]-64;}
    int getWMT4WaveFineTune() {return data[0x8C]-64;}
    int getWMT4WavePan() {return data[0x8D]-64;}
    int getWMT4WaveRandomPanSwitch() {return data[0x8E];}
    int getWMT4WaveAlternatePanSwitch() {return data[0x8F];}
    int getWMT4WaveLevel() {return data[0x90];}
    int getWMT4VelocityRangeLower() {return data[0x91];}
    int getWMT4VelocityRangeUpper() {return data[0x92];}
    int getWMT4VelocityFadeWidthLower() {return data[0x93];}
    int getWMT4VelocityFadeWidthUpper() {return data[0x94];}
    int getPitchEnvDepth() {return data[0x95]-64;}
    int getPitchEnvVelocitySens() {return data[0x96]-64;}
    int getPitchEnvTime1VelocitySens() {return data[0x97]-64;}
    int getPitchEnvTime4VelocitySens() {return data[0x98]-64;}
    int getPitchEnvTime1() {return data[0x99];}
    int getPitchEnvTime2() {return data[0x9A];}
    int getPitchEnvTime3() {return data[0x9B];}
    int getPitchEnvTime4() {return data[0x9C];}
    int getPitchEnvLevel0() {return data[0x9D]-64;}
    int getPitchEnvLevel1() {return data[0x9E]-64;}
    int getPitchEnvLevel2() {return data[0x9F]-64;}
    int getPitchEnvLevel3() {return data[0xA0]-64;}
    int getPitchEnvLevel4() {return data[0xA1]-64;}
    int getTVFFilterType() {return data[0xA2];}
    int getTVFCutoffFrequency() {return data[0xA3];}
    int getTVFCutoffVelocityCurve() {return data[0xA4];}
    int getTVFCutoffVelocitySens() {return data[0xA5]-64;}
    int getTVFResonance() {return data[0xA6];}
    int getTVFResonanceVelocitySens() {return data[0xA7]-64;}
    int getTVFEnvDepth() {return data[0xA8]-64;}
    int getTVFEnvVelocityCurveType() {return data[0xA9];}
    int getTVFEnvVelocitySens() {return data[0xAA]-64;}
    int getTVFEnvTime1VelocitySens() {return data[0xAB]-64;}
    int getTVFEnvTime4VelocitySens() {return data[0xAC]-64;}
    int getTVFEnvTime1() {return data[0xAD];}
    int getTVFEnvTime2() {return data[0xAE];}
    int getTVFEnvTime3() {return data[0xAF];}
    int getTVFEnvTime4() {return data[0xB0];}
    int getTVFEnvLevel0() {return data[0xB1];}
    int getTVFEnvLevel1() {return data[0xB2];}
    int getTVFEnvLevel2() {return data[0xB3];}
    int getTVFEnvLevel3() {return data[0xB4];}
    int getTVFEnvLevel4() {return data[0xB5];}
    int getTVALevelVelocityCurve() {return data[0xB6];}
    int getTVALevelVelocitySens() {return data[0xB7]-64;}
    int getTVAEnvTime1VelocitySens() {return data[0xB8]-64;}
    int getTVAEnvTime4VelocitySens() {return data[0xB9]-64;}
    int getTVAEnvTime1() {return data[0xBA];}
    int getTVAEnvTime2() {return data[0xBB];}
    int getTVAEnvTime3() {return data[0xBC];}
    int getTVAEnvTime4() {return data[0xBD];}
    int getTVAEnvLevel1() {return data[0xBE];}
    int getTVAEnvLevel2() {return data[0xBF];}
    int getTVAEnvLevel3() {return data[0xC0];}
    int getOneShotMode() {return data[0xC1];}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 195;}
    int GetItemsNumber() {return 159;}

public slots:

    void setPartialName1(int v) {DataSet(0x00,v);}
    void setPartialName2(int v) {DataSet(0x01,v);}
    void setPartialName3(int v) {DataSet(0x02,v);}
    void setPartialName4(int v) {DataSet(0x03,v);}
    void setPartialName5(int v) {DataSet(0x04,v);}
    void setPartialName6(int v) {DataSet(0x05,v);}
    void setPartialName7(int v) {DataSet(0x06,v);}
    void setPartialName8(int v) {DataSet(0x07,v);}
    void setPartialName9(int v) {DataSet(0x08,v);}
    void setPartialName10(int v) {DataSet(0x09,v);}
    void setPartialName11(int v) {DataSet(0x0A,v);}
    void setPartialName12(int v) {DataSet(0x0B,v);}
    void setAssignType(int v) {DataSet(0x0C,v);}
    void setMuteGroup(int v) {DataSet(0x0D,v);}
    void setPartialLevel(int v) {DataSet(0x0E,v);}
    void setPartialCoarseTune(int v) {DataSet(0x0F,v);}
    void setPartialFineTune(int v) {DataSetOffset(0x10,v,64);}
    void setPartialRandomPitchDepth(int v) {DataSet(0x11,v);}
    void setPartialPan(int v) {DataSetOffset(0x12,v,64);}
    void setPartialRandomPanDepth(int v) {DataSet(0x13,v);}
    void setPartialAlternatePanDepth(int v) {DataSetOffset(0x14,v,64);}
    void setPartialEnvMode(int v) {DataSet(0x15,v);}
    void setPartialOutputLevel(int v) {DataSet(0x16,v);}
    void setPartialChorusSendLevel(int v) {DataSet(0x19,v);}
    void setPartialReverbSendLevel(int v) {DataSet(0x1A,v);}
    void setPartialOutputAssign(int v) {DataSet(0x1B,v);}
    void setPartialPitchBendRange(int v) {DataSet(0x1C,v);}
    void setPartialReceiveExpression(int v) {DataSet(0x1D,v);}
    void setPartialReceiveHold(int v) {DataSet(0x1E,v);}
    void setWMTVelocityControl(int v) {DataSet(0x20,v);}
    void setWMT1WaveSwitch(int v) {DataSet(0x21,v);}
    void setWMT1WaveGroupType(int v) {DataSet(0x22,v);}
    void setWMT1WaveGroupID(int v) {DataSet4x4B(0x23,v);}
    void setWMT1WaveNumberL(int v) {DataSet4x4B(0x27,v);}
    void setWMT1WaveNumberR(int v) {DataSet4x4B(0x2B,v);}
    void setWMT1WaveGain(int v) {DataSet(0x2F,v);}
    void setWMT1WaveFXMSwitch(int v) {DataSet(0x30,v);}
    void setWMT1WaveFXMColor(int v) {DataSet(0x31,v);}
    void setWMT1WaveFXMDepth(int v) {DataSet(0x32,v);}
    void setWMT1WaveTempoSync(int v) {DataSet(0x33,v);}
    void setWMT1WaveCoarseTune(int v) {DataSetOffset(0x34,v,64);}
    void setWMT1WaveFineTune(int v) {DataSetOffset(0x35,v,64);}
    void setWMT1WavePan(int v) {DataSetOffset(0x36,v,64);}
    void setWMT1WaveRandomPanSwitch(int v) {DataSet(0x37,v);}
    void setWMT1WaveAlternatePanSwitch(int v) {DataSet(0x38,v);}
    void setWMT1WaveLevel(int v) {DataSet(0x39,v);}
    void setWMT1VelocityRangeLower(int v) {DataSet(0x3A,v);}
    void setWMT1VelocityRangeUpper(int v) {DataSet(0x3B,v);}
    void setWMT1VelocityFadeWidthLower(int v) {DataSet(0x3C,v);}
    void setWMT1VelocityFadeWidthUpper(int v) {DataSet(0x3D,v);}
    void setWMT2WaveSwitch(int v) {DataSet(0x3E,v);}
    void setWMT2WaveGroupType(int v) {DataSet(0x3F,v);}
    void setWMT2WaveGroupID(int v) {DataSet4x4B(0x40,v);}
    void setWMT2WaveNumberL(int v) {DataSet4x4B(0x44,v);}
    void setWMT2WaveNumberR(int v) {DataSet4x4B(0x48,v);}
    void setWMT2WaveGain(int v) {DataSet(0x4C,v);}
    void setWMT2WaveFXMSwitch(int v) {DataSet(0x4D,v);}
    void setWMT2WaveFXMColor(int v) {DataSet(0x4E,v);}
    void setWMT2WaveFXMDepth(int v) {DataSet(0x4F,v);}
    void setWMT2WaveTempoSync(int v) {DataSet(0x50,v);}
    void setWMT2WaveCoarseTune(int v) {DataSetOffset(0x51,v,64);}
    void setWMT2WaveFineTune(int v) {DataSetOffset(0x52,v,64);}
    void setWMT2WavePan(int v) {DataSetOffset(0x53,v,64);}
    void setWMT2WaveRandomPanSwitch(int v) {DataSet(0x54,v);}
    void setWMT2WaveAlternatePanSwitch(int v) {DataSet(0x55,v);}
    void setWMT2WaveLevel(int v) {DataSet(0x56,v);}
    void setWMT2VelocityRangeLower(int v) {DataSet(0x57,v);}
    void setWMT2VelocityRangeUpper(int v) {DataSet(0x58,v);}
    void setWMT2VelocityFadeWidthLower(int v) {DataSet(0x59,v);}
    void setWMT2VelocityFadeWidthUpper(int v) {DataSet(0x5A,v);}
    void setWMT3WaveSwitch(int v) {DataSet(0x5B,v);}
    void setWMT3WaveGroupType(int v) {DataSet(0x5C,v);}
    void setWMT3WaveGroupID(int v) {DataSet4x4B(0x5D,v);}
    void setWMT3WaveNumberL(int v) {DataSet4x4B(0x61,v);}
    void setWMT3WaveNumberR(int v) {DataSet4x4B(0x65,v);}
    void setWMT3WaveGain(int v) {DataSet(0x69,v);}
    void setWMT3WaveFXMSwitch(int v) {DataSet(0x6A,v);}
    void setWMT3WaveFXMColor(int v) {DataSet(0x6B,v);}
    void setWMT3WaveFXMDepth(int v) {DataSet(0x6C,v);}
    void setWMT3WaveTempoSync(int v) {DataSet(0x6D,v);}
    void setWMT3WaveCoarseTune(int v) {DataSetOffset(0x6E,v,64);}
    void setWMT3WaveFineTune(int v) {DataSetOffset(0x6F,v,64);}
    void setWMT3WavePan(int v) {DataSetOffset(0x70,v,64);}
    void setWMT3WaveRandomPanSwitch(int v) {DataSet(0x71,v);}
    void setWMT3WaveAlternatePanSwitch(int v) {DataSet(0x72,v);}
    void setWMT3WaveLevel(int v) {DataSet(0x73,v);}
    void setWMT3VelocityRangeLower(int v) {DataSet(0x74,v);}
    void setWMT3VelocityRangeUpper(int v) {DataSet(0x75,v);}
    void setWMT3VelocityFadeWidthLower(int v) {DataSet(0x76,v);}
    void setWMT3VelocityFadeWidthUpper(int v) {DataSet(0x77,v);}
    void setWMT4WaveSwitch(int v) {DataSet(0x78,v);}
    void setWMT4WaveGroupType(int v) {DataSet(0x79,v);}
    void setWMT4WaveGroupID(int v) {DataSet4x4B(0x7A,v);}
    void setWMT4WaveNumberL(int v) {DataSet4x4B(0x7E,v);}
    void setWMT4WaveNumberR(int v) {DataSet4x4B(0x82,v);}
    void setWMT4WaveGain(int v) {DataSet(0x86,v);}
    void setWMT4WaveFXMSwitch(int v) {DataSet(0x87,v);}
    void setWMT4WaveFXMColor(int v) {DataSet(0x88,v);}
    void setWMT4WaveFXMDepth(int v) {DataSet(0x89,v);}
    void setWMT4WaveTempoSync(int v) {DataSet(0x8A,v);}
    void setWMT4WaveCoarseTune(int v) {DataSetOffset(0x8B,v,64);}
    void setWMT4WaveFineTune(int v) {DataSetOffset(0x8C,v,64);}
    void setWMT4WavePan(int v) {DataSetOffset(0x8D,v,64);}
    void setWMT4WaveRandomPanSwitch(int v) {DataSet(0x8E,v);}
    void setWMT4WaveAlternatePanSwitch(int v) {DataSet(0x8F,v);}
    void setWMT4WaveLevel(int v) {DataSet(0x90,v);}
    void setWMT4VelocityRangeLower(int v) {DataSet(0x91,v);}
    void setWMT4VelocityRangeUpper(int v) {DataSet(0x92,v);}
    void setWMT4VelocityFadeWidthLower(int v) {DataSet(0x93,v);}
    void setWMT4VelocityFadeWidthUpper(int v) {DataSet(0x94,v);}
    void setPitchEnvDepth(int v) {DataSetOffset(0x95,v,64);}
    void setPitchEnvVelocitySens(int v) {DataSetOffset(0x96,v,64);}
    void setPitchEnvTime1VelocitySens(int v) {DataSetOffset(0x97,v,64);}
    void setPitchEnvTime4VelocitySens(int v) {DataSetOffset(0x98,v,64);}
    void setPitchEnvTime1(int v) {DataSet(0x99,v);}
    void setPitchEnvTime2(int v) {DataSet(0x9A,v);}
    void setPitchEnvTime3(int v) {DataSet(0x9B,v);}
    void setPitchEnvTime4(int v) {DataSet(0x9C,v);}
    void setPitchEnvLevel0(int v) {DataSetOffset(0x9D,v,64);}
    void setPitchEnvLevel1(int v) {DataSetOffset(0x9E,v,64);}
    void setPitchEnvLevel2(int v) {DataSetOffset(0x9F,v,64);}
    void setPitchEnvLevel3(int v) {DataSetOffset(0xA0,v,64);}
    void setPitchEnvLevel4(int v) {DataSetOffset(0xA1,v,64);}
    void setTVFFilterType(int v) {DataSet(0xA2,v);}
    void setTVFCutoffFrequency(int v) {DataSet(0xA3,v);}
    void setTVFCutoffVelocityCurve(int v) {DataSet(0xA4,v);}
    void setTVFCutoffVelocitySens(int v) {DataSetOffset(0xA5,v,64);}
    void setTVFResonance(int v) {DataSet(0xA6,v);}
    void setTVFResonanceVelocitySens(int v) {DataSetOffset(0xA7,v,64);}
    void setTVFEnvDepth(int v) {DataSetOffset(0xA8,v,64);}
    void setTVFEnvVelocityCurveType(int v) {DataSet(0xA9,v);}
    void setTVFEnvVelocitySens(int v) {DataSetOffset(0xAA,v,64);}
    void setTVFEnvTime1VelocitySens(int v) {DataSetOffset(0xAB,v,64);}
    void setTVFEnvTime4VelocitySens(int v) {DataSetOffset(0xAC,v,64);}
    void setTVFEnvTime1(int v) {DataSet(0xAD,v);}
    void setTVFEnvTime2(int v) {DataSet(0xAE,v);}
    void setTVFEnvTime3(int v) {DataSet(0xAF,v);}
    void setTVFEnvTime4(int v) {DataSet(0xB0,v);}
    void setTVFEnvLevel0(int v) {DataSet(0xB1,v);}
    void setTVFEnvLevel1(int v) {DataSet(0xB2,v);}
    void setTVFEnvLevel2(int v) {DataSet(0xB3,v);}
    void setTVFEnvLevel3(int v) {DataSet(0xB4,v);}
    void setTVFEnvLevel4(int v) {DataSet(0xB5,v);}
    void setTVALevelVelocityCurve(int v) {DataSet(0xB6,v);}
    void setTVALevelVelocitySens(int v) {DataSetOffset(0xB7,v,64);}
    void setTVAEnvTime1VelocitySens(int v) {DataSetOffset(0xB8,v,64);}
    void setTVAEnvTime4VelocitySens(int v) {DataSetOffset(0xB9,v,64);}
    void setTVAEnvTime1(int v) {DataSet(0xBA,v);}
    void setTVAEnvTime2(int v) {DataSet(0xBB,v);}
    void setTVAEnvTime3(int v) {DataSet(0xBC,v);}
    void setTVAEnvTime4(int v) {DataSet(0xBD,v);}
    void setTVAEnvLevel1(int v) {DataSet(0xBE,v);}
    void setTVAEnvLevel2(int v) {DataSet(0xBF,v);}
    void setTVAEnvLevel3(int v) {DataSet(0xC0,v);}
    void setOneShotMode(int v) {DataSet(0xC1,v);}

signals:

    void PartialName1(int v);
    void PartialName2(int v);
    void PartialName3(int v);
    void PartialName4(int v);
    void PartialName5(int v);
    void PartialName6(int v);
    void PartialName7(int v);
    void PartialName8(int v);
    void PartialName9(int v);
    void PartialName10(int v);
    void PartialName11(int v);
    void PartialName12(int v);
    void PartialName(QString name);
    void AssignType(int v);
    void MuteGroup(int v);
    void PartialLevel(int v);
    void PartialCoarseTune(int v);
    void PartialFineTune(int v);
    void PartialRandomPitchDepth(int v);
    void PartialPan(int v);
    void PartialRandomPanDepth(int v);
    void PartialAlternatePanDepth(int v);
    void PartialEnvMode(int v);
    void PartialOutputLevel(int v);
    void PartialChorusSendLevel(int v);
    void PartialReverbSendLevel(int v);
    void PartialOutputAssign(int v);
    void PartialPitchBendRange(int v);
    void PartialReceiveExpression(int v);
    void PartialReceiveHold(int v);
    void WMTVelocityControl(int v);
    void WMT1WaveSwitch(int v);
    void WMT1WaveGroupType(int v);
    void WMT1WaveGroupID(int v);
    void WMT1WaveNumberL(int v);
    void WMT1WaveNumberR(int v);
    void WMT1WaveGain(int v);
    void WMT1WaveFXMSwitch(int v);
    void WMT1WaveFXMColor(int v);
    void WMT1WaveFXMDepth(int v);
    void WMT1WaveTempoSync(int v);
    void WMT1WaveCoarseTune(int v);
    void WMT1WaveFineTune(int v);
    void WMT1WavePan(int v);
    void WMT1WaveRandomPanSwitch(int v);
    void WMT1WaveAlternatePanSwitch(int v);
    void WMT1WaveLevel(int v);
    void WMT1VelocityRangeLower(int v);
    void WMT1VelocityRangeUpper(int v);
    void WMT1VelocityFadeWidthLower(int v);
    void WMT1VelocityFadeWidthUpper(int v);
    void WMT2WaveSwitch(int v);
    void WMT2WaveGroupType(int v);
    void WMT2WaveGroupID(int v);
    void WMT2WaveNumberL(int v);
    void WMT2WaveNumberR(int v);
    void WMT2WaveGain(int v);
    void WMT2WaveFXMSwitch(int v);
    void WMT2WaveFXMColor(int v);
    void WMT2WaveFXMDepth(int v);
    void WMT2WaveTempoSync(int v);
    void WMT2WaveCoarseTune(int v);
    void WMT2WaveFineTune(int v);
    void WMT2WavePan(int v);
    void WMT2WaveRandomPanSwitch(int v);
    void WMT2WaveAlternatePanSwitch(int v);
    void WMT2WaveLevel(int v);
    void WMT2VelocityRangeLower(int v);
    void WMT2VelocityRangeUpper(int v);
    void WMT2VelocityFadeWidthLower(int v);
    void WMT2VelocityFadeWidthUpper(int v);
    void WMT3WaveSwitch(int v);
    void WMT3WaveGroupType(int v);
    void WMT3WaveGroupID(int v);
    void WMT3WaveNumberL(int v);
    void WMT3WaveNumberR(int v);
    void WMT3WaveGain(int v);
    void WMT3WaveFXMSwitch(int v);
    void WMT3WaveFXMColor(int v);
    void WMT3WaveFXMDepth(int v);
    void WMT3WaveTempoSync(int v);
    void WMT3WaveCoarseTune(int v);
    void WMT3WaveFineTune(int v);
    void WMT3WavePan(int v);
    void WMT3WaveRandomPanSwitch(int v);
    void WMT3WaveAlternatePanSwitch(int v);
    void WMT3WaveLevel(int v);
    void WMT3VelocityRangeLower(int v);
    void WMT3VelocityRangeUpper(int v);
    void WMT3VelocityFadeWidthLower(int v);
    void WMT3VelocityFadeWidthUpper(int v);
    void WMT4WaveSwitch(int v);
    void WMT4WaveGroupType(int v);
    void WMT4WaveGroupID(int v);
    void WMT4WaveNumberL(int v);
    void WMT4WaveNumberR(int v);
    void WMT4WaveGain(int v);
    void WMT4WaveFXMSwitch(int v);
    void WMT4WaveFXMColor(int v);
    void WMT4WaveFXMDepth(int v);
    void WMT4WaveTempoSync(int v);
    void WMT4WaveCoarseTune(int v);
    void WMT4WaveFineTune(int v);
    void WMT4WavePan(int v);
    void WMT4WaveRandomPanSwitch(int v);
    void WMT4WaveAlternatePanSwitch(int v);
    void WMT4WaveLevel(int v);
    void WMT4VelocityRangeLower(int v);
    void WMT4VelocityRangeUpper(int v);
    void WMT4VelocityFadeWidthLower(int v);
    void WMT4VelocityFadeWidthUpper(int v);
    void PitchEnvDepth(int v);
    void PitchEnvVelocitySens(int v);
    void PitchEnvTime1VelocitySens(int v);
    void PitchEnvTime4VelocitySens(int v);
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
    void TVFCutoffVelocityCurve(int v);
    void TVFCutoffVelocitySens(int v);
    void TVFResonance(int v);
    void TVFResonanceVelocitySens(int v);
    void TVFEnvDepth(int v);
    void TVFEnvVelocityCurveType(int v);
    void TVFEnvVelocitySens(int v);
    void TVFEnvTime1VelocitySens(int v);
    void TVFEnvTime4VelocitySens(int v);
    void TVFEnvTime1(int v);
    void TVFEnvTime2(int v);
    void TVFEnvTime3(int v);
    void TVFEnvTime4(int v);
    void TVFEnvLevel0(int v);
    void TVFEnvLevel1(int v);
    void TVFEnvLevel2(int v);
    void TVFEnvLevel3(int v);
    void TVFEnvLevel4(int v);
    void TVALevelVelocityCurve(int v);
    void TVALevelVelocitySens(int v);
    void TVAEnvTime1VelocitySens(int v);
    void TVAEnvTime4VelocitySens(int v);
    void TVAEnvTime1(int v);
    void TVAEnvTime2(int v);
    void TVAEnvTime3(int v);
    void TVAEnvTime4(int v);
    void TVAEnvLevel1(int v);
    void TVAEnvLevel2(int v);
    void TVAEnvLevel3(int v);
    void OneShotMode(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7PCMDRUMKITPARTIAL_H
