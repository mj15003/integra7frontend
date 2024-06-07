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

#ifndef INTEGRA7SNSYNTHTONECOMMON_H
#define INTEGRA7SNSYNTHTONECOMMON_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7SNSynthToneCommon : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7SNSynthToneCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getToneName1() {return data[0x00];}
    int getToneName2() {return data[0x01];}
    int getToneName3() {return data[0x02];}
    int getToneName4() {return data[0x03];}
    int getToneName5() {return data[0x04];}
    int getToneName6() {return data[0x05];}
    int getToneName7() {return data[0x06];}
    int getToneName8() {return data[0x07];}
    int getToneName9() {return data[0x08];}
    int getToneName10() {return data[0x09];}
    int getToneName11() {return data[0x0A];}
    int getToneName12() {return data[0x0B];}
    QLatin1StringView getToneName() {return QLatin1StringView((char*)&data[0],(char*)&data[0x0B]);}
    int getToneLevel() {return data[0x0C];}
    int getPortamentoSwitch() {return data[0x12];}
    int getPortamentoTime() {return data[0x13];}
    int getMonoSwitch() {return data[0x14];}
    int getOctaveShift() {return data[0x15];}
    int getPitchBendRangeUp() {return data[0x16];}
    int getPitchBendRangeDown() {return data[0x17];}
    int getPartial1Switch() {return data[0x19];}
    int getPartial1Select() {return data[0x1A];}
    int getPartial2Switch() {return data[0x1B];}
    int getPartial2Select() {return data[0x1C];}
    int getPartial3Switch() {return data[0x1D];}
    int getPartial3Select() {return data[0x1E];}
    int getRINGSwitch() {return data[0x1F];}
    int getTFXSwitch() {return data[0x20];}
    int getUnisonSwitch() {return data[0x2E];}
    int getPortamentoMode() {return data[0x31];}
    int getLegatoSwitch() {return data[0x32];}
    int getAnalogFeel() {return data[0x34];}
    int getWaveShape() {return data[0x35];}
    int getToneCategory() {return data[0x36];}
    int getPhraseNumber() {return data[0x37]<<12|data[0x38]<<8|data[0x39]<<4|data[0x3A];}
    int getPhraseOctaveShift() {return data[0x3B];}
    int getUnisonSize() {return data[0x3C];}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x40;}
    int GetItemsNumber() {return 0x40;}

public slots:

    void setToneName1(int v) {DataSet(0x00,v);}
    void setToneName2(int v) {DataSet(0x01,v);}
    void setToneName3(int v) {DataSet(0x02,v);}
    void setToneName4(int v) {DataSet(0x03,v);}
    void setToneName5(int v) {DataSet(0x04,v);}
    void setToneName6(int v) {DataSet(0x05,v);}
    void setToneName7(int v) {DataSet(0x06,v);}
    void setToneName8(int v) {DataSet(0x07,v);}
    void setToneName9(int v) {DataSet(0x08,v);}
    void setToneName10(int v) {DataSet(0x09,v);}
    void setToneName11(int v) {DataSet(0x0A,v);}
    void setToneName12(int v) {DataSet(0x0B,v);}
    void setToneLevel(int v) {DataSet(0x0C,v);}
    void setPortamentoSwitch(int v) {DataSet(0x12,v);}
    void setPortamentoTime(int v) {DataSet(0x13,v);}
    void setMonoSwitch(int v) {DataSet(0x14,v);}
    void setOctaveShift(int v) {DataSet(0x15,v);}
    void setPitchBendRangeUp(int v) {DataSet(0x16,v);}
    void setPitchBendRangeDown(int v) {DataSet(0x17,v);}
    void setPartial1Switch(int v) {DataSet(0x19,v);}
    void setPartial1Select(int v) {DataSet(0x1A,v);}
    void setPartial2Switch(int v) {DataSet(0x1B,v);}
    void setPartial2Select(int v) {DataSet(0x1C,v);}
    void setPartial3Switch(int v) {DataSet(0x1D,v);}
    void setPartial3Select(int v) {DataSet(0x1E,v);}
    void setRINGSwitch(int v) {DataSet(0x1F,v);}
    void setTFXSwitch(int v) {DataSet(0x20,v);}
    void setUnisonSwitch(int v) {DataSet(0x2E,v);}
    void setPortamentoMode(int v) {DataSet(0x31,v);}
    void setLegatoSwitch(int v) {DataSet(0x32,v);}
    void setAnalogFeel(int v) {DataSet(0x34,v);}
    void setWaveShape(int v) {DataSet(0x35,v);}
    void setToneCategory(int v) {DataSet(0x36,v);}
    void setPhraseNumber(int v) {DataSet4x4B(0x37,v);}
    void setPhraseOctaveShift(int v) {DataSet(0x3B,v);}
    void setUnisonSize(int v) {DataSet(0x3C,v);}

signals:

    void ToneName1(int v);
    void ToneName2(int v);
    void ToneName3(int v);
    void ToneName4(int v);
    void ToneName5(int v);
    void ToneName6(int v);
    void ToneName7(int v);
    void ToneName8(int v);
    void ToneName9(int v);
    void ToneName10(int v);
    void ToneName11(int v);
    void ToneName12(int v);
    void ToneName(QString v);
    void ToneLevel(int v);
    void PortamentoSwitch(int v);
    void PortamentoTime(int v);
    void MonoSwitch(int v);
    void OctaveShift(int v);
    void PitchBendRangeUp(int v);
    void PitchBendRangeDown(int v);
    void Partial1Switch(int v);
    void Partial1Select(int v);
    void Partial2Switch(int v);
    void Partial2Select(int v);
    void Partial3Switch(int v);
    void Partial3Select(int v);
    void RINGSwitch(int v);
    void TFXSwitch(int v);
    void UnisonSwitch(int v);
    void PortamentoMode(int v);
    void LegatoSwitch(int v);
    void AnalogFeel(int v);
    void WaveShape(int v);
    void ToneCategory(int v);
    void PhraseNumber(int v);
    void PhraseOctaveShift(int v);
    void UnisonSize(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7SNSYNTHTONECOMMON_H
