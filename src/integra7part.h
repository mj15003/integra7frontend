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

#ifndef INTEGRA7PART_H
#define INTEGRA7PART_H

#include <QObject>

#include "integra7parameterset.h"

class Integra7Part : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7Part(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x4D;}

    int GetItemsNumber() {return 65;}

    int getReceiveChannel() {return data[0x00];}
    int getReceiveSwitch() {return data[0x01];}
    int getToneBankSelectMSB() {return data[0x06];}
    int getToneBankSelectLSB() {return data[0x07];}
    int getToneBankSelect() {return data[0x06]<<7|data[0x07];}
    int getToneProgramNumber() {return data[0x08];}
    int getPartLevel() {return data[0x09];}
    int getPartPan() {return data[0x0A]-64;}
    int getPartCoarseTune() {return data[0x0B]-64;}
    int getPartFineTune() {return data[0x0C]-64;}
    int getPartMonoPoly() {return data[0x0D];}
    int getPartLegatoSwitch() {return data[0x0E];}
    int getPartPitchBendRange() {return data[0x0F];}
    int getPartPortamentoSwitch() {return data[0x10];}
    int getPartPortamentoTime() {return data[0x11]<<4|data[0x12];}
    int getPartCutoffOffset() {return data[0x13]-64;}
    int getPartResonanceOffset() {return data[0x14]-64;}
    int getPartAttackTimeOffset() {return data[0x15]-64;}
    int getPartDecayTimeOffset() {return data[0x16]-64;}
    int getPartReleaseTimeOffset() {return data[0x17]-64;}
    int getPartVibratoRate() {return data[0x18]-64;}
    int getPartVibratoDepth() {return data[0x19]-64;}
    int getPartVibratoDelay() {return data[0x1A]-64;}
    int getPartOctaveShift() {return data[0x1B]-3;}
    int getPartVelocitySensOffset() {return data[0x1C]-64;}
    int getKeyboardRangeLower() {return data[0x1D];}
    int getKeyboardRangeUpper() {return data[0x1E];}
    int getKeyboardFadeWidthLower() {return data[0x1F];}
    int getKeyboardFadeWidthUpper() {return data[0x20];}
    int getVelocityRangeLower() {return data[0x21];}
    int getVelocityRangeUpper() {return data[0x22];}
    int getVelocityFadeWidthLower() {return data[0x23];}
    int getVelocityFadeWidthUpper() {return data[0x24];}
    int getMuteSwitch() {return data[0x25];}
    int getPartChorusSendLevel() {return data[0x27];}
    int getPartReverbSendLevel() {return data[0x28];}
    int getPartOutputAssign() {return data[0x29];}
    int getPartScaleTuneType() {return data[0x2B];}
    int getPartScaleTuneKey() {return data[0x2C];}
    int getPartScaleTuneforC() {return data[0x2D]-64;}
    int getPartScaleTuneforCs() {return data[0x2E]-64;}
    int getPartScaleTuneforD() {return data[0x2F]-64;}
    int getPartScaleTuneforDs() {return data[0x30]-64;}
    int getPartScaleTuneforE() {return data[0x31]-64;}
    int getPartScaleTuneforF() {return data[0x32]-64;}
    int getPartScaleTuneforFs() {return data[0x33]-64;}
    int getPartScaleTuneforG() {return data[0x34]-64;}
    int getPartScaleTuneforGs() {return data[0x35]-64;}
    int getPartScaleTuneforA() {return data[0x36]-64;}
    int getPartScaleTuneforAs() {return data[0x37]-64;}
    int getPartScaleTuneforB() {return data[0x38]-64;}
    int getReceiveProgramChange() {return data[0x39];}
    int getReceiveBankSelect() {return data[0x3A];}
    int getReceivePitchBend() {return data[0x3B];}
    int getReceivePolyphonicKeyPressure() {return data[0x3C];}
    int getReceiveChannelPressure() {return data[0x3D];}
    int getReceiveModulation() {return data[0x3E];}
    int getReceiveVolume() {return data[0x3F];}
    int getReceivePan() {return data[0x40];}
    int getReceiveExpression() {return data[0x41];}
    int getReceiveHold() {return data[0x42];}
    int getVelocityCurveType() {return data[0x43];}
    int getMotionalSurroundLR() {return data[0x44]-64;}
    int getMotionalSurroundFB() {return data[0x46]-64;}
    int getMotionalSurroundWidth() {return data[0x48];}
    int getMotionalSurroundAmbienceSendLevel() {return data[0x49];}

public slots:

    void setReceiveChannel(int v) { DataSet(0x00,v); }
    void setReceiveSwitch(int v) { DataSet(0x01,v); }
    void setToneBankSelectMSB(int v) { DataSet(0x06,v); }
    void setToneBankSelectLSB(int v) { DataSet(0x07,v); }
    void setToneProgramNumber(int v) { DataSet(0x08,v); }
    void setToneBankProgram(int b, int p);
    void setPartLevel(int v) { DataSet(0x09,v); }
    void setPartPan(int v) { DataSetOffset(0x0A,v,64); }
    void setPartCoarseTune(int v) { DataSetOffset(0x0B,v,64); }
    void setPartFineTune(int v) { DataSetOffset(0x0C,v,64); }
    void setPartMonoPoly(int v) { DataSet(0x0D,v); }
    void setPartLegatoSwitch(int v) { DataSet(0x0E,v); }
    void setPartPitchBendRange(int v) { DataSet(0x0F,v); }
    void setPartPortamentoSwitch(int v) { DataSet(0x10,v); }
    void setPartPortamentoTime(int v) { DataSet2x4B(0x11,v);}
    void setPartCutoffOffset(int v) { DataSetOffset(0x13,v,64); }
    void setPartResonanceOffset(int v) { DataSetOffset(0x14,v,64); }
    void setPartAttackTimeOffset(int v) { DataSetOffset(0x15,v,64); }
    void setPartDecayTimeOffset(int v) { DataSetOffset(0x16,v,64); }
    void setPartReleaseTimeOffset(int v) { DataSetOffset(0x17,v,64); }
    void setPartVibratoRate(int v) { DataSetOffset(0x18,v,64); }
    void setPartVibratoDepth(int v) { DataSetOffset(0x19,v,64); }
    void setPartVibratoDelay(int v) { DataSetOffset(0x1A,v,64); }
    void setPartOctaveShift(int v) { DataSetOffset(0x1B,v,3); }
    void setPartVelocitySensOffset(int v) { DataSetOffset(0x1C,v,64); }
    void setKeyboardRangeLower(int v) { DataSet(0x1D,v); }
    void setKeyboardRangeUpper(int v) { DataSet(0x1E,v); }
    void setKeyboardFadeWidthLower(int v) { DataSet(0x1F,v); }
    void setKeyboardFadeWidthUpper(int v) { DataSet(0x20,v); }
    void setVelocityRangeLower(int v) { DataSet(0x21,v); }
    void setVelocityRangeUpper(int v) { DataSet(0x22,v); }
    void setVelocityFadeWidthLower(int v) { DataSet(0x23,v); }
    void setVelocityFadeWidthUpper(int v) { DataSet(0x24,v); }
    void setMuteSwitch(int v) { DataSet(0x25,v); }
    void setPartChorusSendLevel(int v) { DataSet(0x27,v); }
    void setPartReverbSendLevel(int v) { DataSet(0x28,v); }
    void setPartOutputAssign(int v) { DataSet(0x29,v); }
    void setPartScaleTuneType(int v) { DataSet(0x2B,v); }
    void setPartScaleTuneKey(int v) { DataSet(0x2C,v); }
    void setPartScaleTuneforC(int v) { DataSetOffset(0x2D,v,64); }
    void setPartScaleTuneforCs(int v) { DataSetOffset(0x2E,v,64); }
    void setPartScaleTuneforD(int v) { DataSetOffset(0x2F,v,64); }
    void setPartScaleTuneforDs(int v) { DataSetOffset(0x30,v,64); }
    void setPartScaleTuneforE(int v) { DataSetOffset(0x31,v,64); }
    void setPartScaleTuneforF(int v) { DataSetOffset(0x32,v,64); }
    void setPartScaleTuneforFs(int v) { DataSetOffset(0x33,v,64); }
    void setPartScaleTuneforG(int v) { DataSetOffset(0x34,v,64); }
    void setPartScaleTuneforGs(int v) { DataSetOffset(0x35,v,64); }
    void setPartScaleTuneforA(int v) { DataSetOffset(0x36,v,64); }
    void setPartScaleTuneforAs(int v) { DataSetOffset(0x37,v,64); }
    void setPartScaleTuneforB(int v) { DataSetOffset(0x38,v,64); }
    void setReceiveProgramChange(int v) { DataSet(0x39,v); }
    void setReceiveBankSelect(int v) { DataSet(0x3A,v); }
    void setReceivePitchBend(int v) { DataSet(0x3B,v); }
    void setReceivePolyphonicKeyPressure(int v) { DataSet(0x3C,v); }
    void setReceiveChannelPressure(int v) { DataSet(0x3D,v); }
    void setReceiveModulation(int v) { DataSet(0x3E,v); }
    void setReceiveVolume(int v) { DataSet(0x3F,v); }
    void setReceivePan(int v) { DataSet(0x40,v); }
    void setReceiveExpression(int v) { DataSet(0x41,v); }
    void setReceiveHold(int v) { DataSet(0x42,v); }
    void setVelocityCurveType(int v) { DataSet(0x43,v); }
    void setMotionalSurroundLR(int v) { DataSetOffset(0x44,v,64); }
    void setMotionalSurroundFB(int v) { DataSetOffset(0x46,v,64); }
    void setMotionalSurroundWidth(int v) { DataSet(0x48,v); }
    void setMotionalSurroundAmbienceSendLevel(int v) { DataSet(0x49,v); }

signals:

    void ReceiveChannel(int v);
    void ReceiveSwitch(int v);
    void ToneBankSelectMSB(int v);
    void ToneBankSelectLSB(int v);
    void ToneProgramNumber(int v);
    void ToneBankProgram(int b, int p);
    void PartLevel(int v);
    void PartPan(int v);
    void PartCoarseTune(int v);
    void PartFineTune(int v);
    void PartMonoPoly(int v);
    void PartLegatoSwitch(int v);
    void PartPitchBendRange(int v);
    void PartPortamentoSwitch(int v);
    void PartPortamentoTime(int v);
    void PartCutoffOffset(int v);
    void PartResonanceOffset(int v);
    void PartAttackTimeOffset(int v);
    void PartDecayTimeOffset(int v);
    void PartReleaseTimeOffset(int v);
    void PartVibratoRate(int v);
    void PartVibratoDepth(int v);
    void PartVibratoDelay(int v);
    void PartOctaveShift(int v);
    void PartVelocitySensOffset(int v);
    void KeyboardRangeLower(int v);
    void KeyboardRangeUpper(int v);
    void KeyboardFadeWidthLower(int v);
    void KeyboardFadeWidthUpper(int v);
    void VelocityRangeLower(int v);
    void VelocityRangeUpper(int v);
    void VelocityFadeWidthLower(int v);
    void VelocityFadeWidthUpper(int v);
    void MuteSwitch(int v);
    void PartChorusSendLevel(int v);
    void PartReverbSendLevel(int v);
    void PartOutputAssign(int v);
    void PartScaleTuneType(int v);
    void PartScaleTuneKey(int v);
    void PartScaleTuneforC(int v);
    void PartScaleTuneforCs(int v);
    void PartScaleTuneforD(int v);
    void PartScaleTuneforDs(int v);
    void PartScaleTuneforE(int v);
    void PartScaleTuneforF(int v);
    void PartScaleTuneforFs(int v);
    void PartScaleTuneforG(int v);
    void PartScaleTuneforGs(int v);
    void PartScaleTuneforA(int v);
    void PartScaleTuneforAs(int v);
    void PartScaleTuneforB(int v);
    void ReceiveProgramChange(int v);
    void ReceiveBankSelect(int v);
    void ReceivePitchBend(int v);
    void ReceivePolyphonicKeyPressure(int v);
    void ReceiveChannelPressure(int v);
    void ReceiveModulation(int v);
    void ReceiveVolume(int v);
    void ReceivePan(int v);
    void ReceiveExpression(int v);
    void ReceiveHold(int v);
    void VelocityCurveType(int v);
    void MotionalSurroundLR(int v);
    void MotionalSurroundFB(int v);
    void MotionalSurroundWidth(int v);
    void MotionalSurroundAmbienceSendLevel(int v);

private:
    void BankSet(int v);
    void ProgramSet(int v);
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7PART_H
