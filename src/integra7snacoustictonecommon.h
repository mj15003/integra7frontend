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

#ifndef INTEGRA7SNACOUSTICTONECOMMON_H
#define INTEGRA7SNACOUSTICTONECOMMON_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7SNAcousticToneCommon : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7SNAcousticToneCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

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
    int getToneLevel() {return data[0x10];}
    int getMonoPoly() {return data[0x11];}
    int getPortamentoTimeOffset() {return data[0x12]-64;}
    int getCutoffOffset() {return data[0x13]-64;}
    int getResonanceOffset() {return data[0x14]-64;}
    int getAttackTimeOffset() {return data[0x15]-64;}
    int getReleaseTimeOffset() {return data[0x16]-64;}
    int getVibratoRate() {return data[0x17]-64;}
    int getVibratoDepth() {return data[0x18]-64;}
    int getVibratoDelay() {return data[0x19]-64;}
    int getOctaveShift() {return data[0x1A]-64;}
    int getCategory() {return data[0x1B];}
    int getPhraseNumber() {return data[0x1C]<<4|data[0x1D];}
    int getPhraseOctaveShift() {return data[0x1E]-64;}
    int getTFXSwitch() {return data[0x1F];}
    int getInstVariation() {return data[0x20];}
    int getInstNumber() {return data[0x21];}
    int getModifyParameter1() {return data[0x22];}
    int getModifyParameter2() {return data[0x23];}
    int getModifyParameter3() {return data[0x24];}
    int getModifyParameter4() {return data[0x25];}
    int getModifyParameter5() {return data[0x26];}
    int getModifyParameter6() {return data[0x27];}
    int getModifyParameter7() {return data[0x28];}
    int getModifyParameter8() {return data[0x29];}
    int getModifyParameter9() {return data[0x2A];}
    int getModifyParameter10() {return data[0x2B];}
    int getModifyParameter11() {return data[0x2C];}
    int getModifyParameter12() {return data[0x2D];}
    int getModifyParameter13() {return data[0x2E];}
    int getModifyParameter14() {return data[0x2F];}
    int getModifyParameter15() {return data[0x30];}
    int getModifyParameter16() {return data[0x31];}
    int getModifyParameter17() {return data[0x32];}
    int getModifyParameter18() {return data[0x33];}
    int getModifyParameter19() {return data[0x34];}
    int getModifyParameter20() {return data[0x35];}
    int getModifyParameter21() {return data[0x36];}
    int getModifyParameter22() {return data[0x37];}
    int getModifyParameter23() {return data[0x38];}
    int getModifyParameter24() {return data[0x39];}
    int getModifyParameter25() {return data[0x3A];}
    int getModifyParameter26() {return data[0x3B];}
    int getModifyParameter27() {return data[0x3C];}
    int getModifyParameter28() {return data[0x3D];}
    int getModifyParameter29() {return data[0x3E];}
    int getModifyParameter30() {return data[0x3F];}
    int getModifyParameter31() {return data[0x40];}
    int getModifyParameter32() {return data[0x41];}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x46;}
    int GetItemsNumber() {return 0x45;}

public slots:

    void setToneName(const QString name);
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
    void setToneLevel(int v) {DataSet(0x10,v);}
    void setMonoPoly(int v) {DataSet(0x11,v);}
    void setPortamentoTimeOffset(int v) {DataSetOffset(0x12,v,64);}
    void setCutoffOffset(int v) {DataSetOffset(0x13,v,64);}
    void setResonanceOffset(int v) {DataSetOffset(0x14,v,64);}
    void setAttackTimeOffset(int v) {DataSetOffset(0x15,v,64);}
    void setReleaseTimeOffset(int v) {DataSetOffset(0x16,v,64);}
    void setVibratoRate(int v) {DataSetOffset(0x17,v,64);}
    void setVibratoDepth(int v) {DataSetOffset(0x18,v,64);}
    void setVibratoDelay(int v) {DataSetOffset(0x19,v,64);}
    void setOctaveShift(int v) {DataSetOffset(0x1A,v,64);}
    void setCategory(int v) {DataSet(0x1B,v);}
    void setPhraseNumber(int v) {DataSet2x4B(0x1C,v);}
    void setPhraseOctaveShift(int v) {DataSetOffset(0x1E,v,64);}
    void setTFXSwitch(int v) {DataSet(0x1F,v);}
    void setInstVariation(int v) {DataSet(0x20,v);}
    void setInstNumber(int v) {DataSet(0x21,v);}
    void setModifyParameter1(int v) {DataSet(0x22,v);}
    void setModifyParameter2(int v) {DataSet(0x23,v);}
    void setModifyParameter3(int v) {DataSet(0x24,v);}
    void setModifyParameter4(int v) {DataSet(0x25,v);}
    void setModifyParameter5(int v) {DataSet(0x26,v);}
    void setModifyParameter6(int v) {DataSet(0x27,v);}
    void setModifyParameter7(int v) {DataSet(0x28,v);}
    void setModifyParameter8(int v) {DataSet(0x29,v);}
    void setModifyParameter9(int v) {DataSet(0x2A,v);}
    void setModifyParameter10(int v) {DataSet(0x2B,v);}
    void setModifyParameter11(int v) {DataSet(0x2C,v);}
    void setModifyParameter12(int v) {DataSet(0x2D,v);}
    void setModifyParameter13(int v) {DataSet(0x2E,v);}
    void setModifyParameter14(int v) {DataSet(0x2F,v);}
    void setModifyParameter15(int v) {DataSet(0x30,v);}
    void setModifyParameter16(int v) {DataSet(0x31,v);}
    void setModifyParameter17(int v) {DataSet(0x32,v);}
    void setModifyParameter18(int v) {DataSet(0x33,v);}
    void setModifyParameter19(int v) {DataSet(0x34,v);}
    void setModifyParameter20(int v) {DataSet(0x35,v);}
    void setModifyParameter21(int v) {DataSet(0x36,v);}
    void setModifyParameter22(int v) {DataSet(0x37,v);}
    void setModifyParameter23(int v) {DataSet(0x38,v);}
    void setModifyParameter24(int v) {DataSet(0x39,v);}
    void setModifyParameter25(int v) {DataSet(0x3A,v);}
    void setModifyParameter26(int v) {DataSet(0x3B,v);}
    void setModifyParameter27(int v) {DataSet(0x3C,v);}
    void setModifyParameter28(int v) {DataSet(0x3D,v);}
    void setModifyParameter29(int v) {DataSet(0x3E,v);}
    void setModifyParameter30(int v) {DataSet(0x3F,v);}
    void setModifyParameter31(int v) {DataSet(0x40,v);}
    void setModifyParameter32(int v) {DataSet(0x41,v);}

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
    void MonoPoly(int v);
    void PortamentoTimeOffset(int v);
    void CutoffOffset(int v);
    void ResonanceOffset(int v);
    void AttackTimeOffset(int v);
    void ReleaseTimeOffset(int v);
    void VibratoRate(int v);
    void VibratoDepth(int v);
    void VibratoDelay(int v);
    void OctaveShift(int v);
    void Category(int v);
    void PhraseNumber(int v);
    void PhraseOctaveShift(int v);
    void TFXSwitch(int v);
    void InstVariation(int v);
    void InstNumber(int v);
    void ModifyParameter1(int v);
    void ModifyParameter2(int v);
    void ModifyParameter3(int v);
    void ModifyParameter4(int v);
    void ModifyParameter5(int v);
    void ModifyParameter6(int v);
    void ModifyParameter7(int v);
    void ModifyParameter8(int v);
    void ModifyParameter9(int v);
    void ModifyParameter10(int v);
    void ModifyParameter11(int v);
    void ModifyParameter12(int v);
    void ModifyParameter13(int v);
    void ModifyParameter14(int v);
    void ModifyParameter15(int v);
    void ModifyParameter16(int v);
    void ModifyParameter17(int v);
    void ModifyParameter18(int v);
    void ModifyParameter19(int v);
    void ModifyParameter20(int v);
    void ModifyParameter21(int v);
    void ModifyParameter22(int v);
    void ModifyParameter23(int v);
    void ModifyParameter24(int v);
    void ModifyParameter25(int v);
    void ModifyParameter26(int v);
    void ModifyParameter27(int v);
    void ModifyParameter28(int v);
    void ModifyParameter29(int v);
    void ModifyParameter30(int v);
    void ModifyParameter31(int v);
    void ModifyParameter32(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7SNACOUSTICTONECOMMON_H
