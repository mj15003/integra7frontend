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

#ifndef INTEGRA7PCMSYNTHTONECOMMON_H
#define INTEGRA7PCMSYNTHTONECOMMON_H

#include "integra7parameterset.h"

class Integra7PCMSynthToneCommon : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7PCMSynthToneCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getPCMSynthToneName1() {return data[0x00];}
    int getPCMSynthToneName2() {return data[0x01];}
    int getPCMSynthToneName3() {return data[0x02];}
    int getPCMSynthToneName4() {return data[0x03];}
    int getPCMSynthToneName5() {return data[0x04];}
    int getPCMSynthToneName6() {return data[0x05];}
    int getPCMSynthToneName7() {return data[0x06];}
    int getPCMSynthToneName8() {return data[0x07];}
    int getPCMSynthToneName9() {return data[0x08];}
    int getPCMSynthToneName10() {return data[0x09];}
    int getPCMSynthToneName11() {return data[0x0A];}
    int getPCMSynthToneName12() {return data[0x0B];}
    QLatin1StringView getPCMSynthToneName() {return QLatin1StringView((char*)&data[0],(char*)&data[0x0B]);}
    int getPCMSynthToneLevel() {return data[0x0E];}
    int getPCMSynthTonePan() {return data[0x0F]-64;}
    int getPCMSynthTonePriority() {return data[0x10];}
    int getPCMSynthToneCoarseTune() {return data[0x11]-64;}
    int getPCMSynthToneFineTune() {return data[0x12]-64;}
    int getOctaveShift() {return data[0x13]-64;}
    int getStretchTuneDepth() {return data[0x14];}
    int getAnalogFeel() {return data[0x15];}
    int getMonoPoly() {return data[0x16];}
    int getLegatoSwitch() {return data[0x17];}
    int getLegatoRetrigger() {return data[0x18];}
    int getPortamentoSwitch() {return data[0x19];}
    int getPortamentoMode() {return data[0x1A];}
    int getPortamentoType() {return data[0x1B];}
    int getPortamentoStart() {return data[0x1C];}
    int getPortamentoTime() {return data[0x1D];}
    int getCutoffOffset() {return data[0x22]-64;}
    int getResonanceOffset() {return data[0x23]-64;}
    int getAttackTimeOffset() {return data[0x24]-64;}
    int getReleaseTimeOffset() {return data[0x25]-64;}
    int getVelocitySensOffset() {return data[0x26]-64;}
    int getPMTControlSwitch() {return data[0x28];}
    int getPitchBendRangeUp() {return data[0x29];}
    int getPitchBendRangeDown() {return data[0x2A];}
    int getMatrixControl1Source() {return data[0x2B];}
    int getMatrixControl1Destination1() {return data[0x2C];}
    int getMatrixControl1Sens1() {return data[0x2D]-64;}
    int getMatrixControl1Destination2() {return data[0x2E];}
    int getMatrixControl1Sens2() {return data[0x2F]-64;}
    int getMatrixControl1Destination3() {return data[0x30];}
    int getMatrixControl1Sens3() {return data[0x31]-64;}
    int getMatrixControl1Destination4() {return data[0x32];}
    int getMatrixControl1Sens4() {return data[0x33]-64;}
    int getMatrixControl2Source() {return data[0x34];}
    int getMatrixControl2Destination1() {return data[0x35];}
    int getMatrixControl2Sens1() {return data[0x36]-64;}
    int getMatrixControl2Destination2() {return data[0x37];}
    int getMatrixControl2Sens2() {return data[0x38]-64;}
    int getMatrixControl2Destination3() {return data[0x39];}
    int getMatrixControl2Sens3() {return data[0x3A]-64;}
    int getMatrixControl2Destination4() {return data[0x3B];}
    int getMatrixControl2Sens4() {return data[0x3C]-64;}
    int getMatrixControl3Source() {return data[0x3D];}
    int getMatrixControl3Destination1() {return data[0x3E];}
    int getMatrixControl3Sens1() {return data[0x3F]-64;}
    int getMatrixControl3Destination2() {return data[0x40];}
    int getMatrixControl3Sens2() {return data[0x41]-64;}
    int getMatrixControl3Destination3() {return data[0x42];}
    int getMatrixControl3Sens3() {return data[0x43]-64;}
    int getMatrixControl3Destination4() {return data[0x44];}
    int getMatrixControl3Sens4() {return data[0x45]-64;}
    int getMatrixControl4Source() {return data[0x46];}
    int getMatrixControl4Destination1() {return data[0x47];}
    int getMatrixControl4Sens1() {return data[0x48]-64;}
    int getMatrixControl4Destination2() {return data[0x49];}
    int getMatrixControl4Sens2() {return data[0x4A]-64;}
    int getMatrixControl4Destination3() {return data[0x4B];}
    int getMatrixControl4Sens3() {return data[0x4C]-64;}
    int getMatrixControl4Destination4() {return data[0x4D];}
    int getMatrixControl4Sens4() {return data[0x4E]-64;}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x50;}
    int GetItemsNumber() {return 0x50;}

    static QStringList& PCMSynthTonePriorityList() {
        static QStringList list = { "LAST","LOUDEST" };
        return list;
    }

    static QStringList& MonoPolyList() {
        static QStringList list = { "MONO","POLY" };
        return list;
    }

    static QStringList& PortamentoModeList() {
        static QStringList list = { "NORMAL","LEGATO" };
        return list;
    }

    static QStringList& PortamentoTypeList() {
        static QStringList list = { "RATE","TIME" };
        return list;
    }

    static QStringList& PortamentoStartList() {
        static QStringList list = { "PITCH","NOTE" };
        return list;
    }

    static QStringList& MatrixControlSourceList() {
        static QStringList list = { "OFF",
                                   "CC01","CC02","CC03","CC04","CC05","CC06","CC07","CC08","CC09",
                                   "CC10","CC11","CC12","CC13","CC14","CC15","CC16","CC17","CC18","CC19",
                                   "CC20","CC21","CC22","CC23","CC24","CC25","CC26","CC27","CC28","CC29",
                                   "CC30","CC31","CC33","CC34","CC35","CC36","CC37","CC38","CC39",
                                   "CC40","CC41","CC42","CC43","CC44","CC45","CC46","CC47","CC48","CC49",
                                   "CC50","CC51","CC52","CC53","CC54","CC55","CC56","CC57","CC58","CC59",
                                   "CC60","CC61","CC62","CC63","CC64","CC65","CC66","CC67","CC68","CC69",
                                   "CC70","CC71","CC72","CC73","CC74","CC75","CC76","CC77","CC78","CC79",
                                   "CC80","CC81","CC82","CC83","CC84","CC85","CC86","CC87","CC88","CC89",
                                   "CC90","CC91","CC92","CC93","CC94","CC95",
                                   "BEND","AFT","CTRL1-CTRL4",
                                   "VELOCITY","KEYFOLLOW","TEMPO","LFO1","LFO2",
                                   "PIT-ENV","TVF-ENV","TVA-ENV" };
        return list;
    }

    static QStringList& MatrixControlDestinationList() {
        static QStringList list = { "OFF","PCH","CUT","RES","LEV","PAN","DRY","CHO","REV",
                                   "PIT-LFO1","PIT-LFO2","TVF-LFO1","TVF-LFO2","TVA-LFO1",
                                   "TVA-LFO2","PAN-LFO1","PAN-LFO2","LFO1-RATE","LFO2-RATE",
                                   "PIT-ATK","PIT-DCY","PIT-REL","TVF-ATK","TVF-DCY","TVF-REL",
                                   "TVA-ATK","TVA-DCY","TVA-REL","PMT","FXM","---","---","---","---" };
        return list;
    }

public slots:

    void setToneName(const QString name);
    void setPCMSynthToneName1(int v) {DataSet(0x00,v);}
    void setPCMSynthToneName2(int v) {DataSet(0x01,v);}
    void setPCMSynthToneName3(int v) {DataSet(0x02,v);}
    void setPCMSynthToneName4(int v) {DataSet(0x03,v);}
    void setPCMSynthToneName5(int v) {DataSet(0x04,v);}
    void setPCMSynthToneName6(int v) {DataSet(0x05,v);}
    void setPCMSynthToneName7(int v) {DataSet(0x06,v);}
    void setPCMSynthToneName8(int v) {DataSet(0x07,v);}
    void setPCMSynthToneName9(int v) {DataSet(0x08,v);}
    void setPCMSynthToneName10(int v) {DataSet(0x09,v);}
    void setPCMSynthToneName11(int v) {DataSet(0x0A,v);}
    void setPCMSynthToneName12(int v) {DataSet(0x0B,v);}
    void setPCMSynthToneLevel(int v) {DataSet(0x0E,v);}
    void setPCMSynthTonePan(int v) {DataSetOffset(0x0F,v,64);}
    void setPCMSynthTonePriority(int v) {DataSet(0x10,v);}
    void setPCMSynthToneCoarseTune(int v) {DataSetOffset(0x11,v,64);}
    void setPCMSynthToneFineTune(int v) {DataSetOffset(0x12,v,64);}
    void setOctaveShift(int v) {DataSetOffset(0x13,v,64);}
    void setStretchTuneDepth(int v) {DataSet(0x14,v);}
    void setAnalogFeel(int v) {DataSet(0x15,v);}
    void setMonoPoly(int v) {DataSet(0x16,v);}
    void setLegatoSwitch(int v) {DataSet(0x17,v);}
    void setLegatoRetrigger(int v) {DataSet(0x18,v);}
    void setPortamentoSwitch(int v) {DataSet(0x19,v);}
    void setPortamentoMode(int v) {DataSet(0x1A,v);}
    void setPortamentoType(int v) {DataSet(0x1B,v);}
    void setPortamentoStart(int v) {DataSet(0x1C,v);}
    void setPortamentoTime(int v) {DataSet(0x1D,v);}
    void setCutoffOffset(int v) {DataSetOffset(0x22,v,64);}
    void setResonanceOffset(int v) {DataSetOffset(0x23,v,64);}
    void setAttackTimeOffset(int v) {DataSetOffset(0x24,v,64);}
    void setReleaseTimeOffset(int v) {DataSetOffset(0x25,v,64);}
    void setVelocitySensOffset(int v) {DataSetOffset(0x26,v,64);}
    void setPMTControlSwitch(int v) {DataSet(0x28,v);}
    void setPitchBendRangeUp(int v) {DataSet(0x29,v);}
    void setPitchBendRangeDown(int v) {DataSet(0x2A,v);}
    void setMatrixControl1Source(int v) {DataSet(0x2B,v);}
    void setMatrixControl1Destination1(int v) {DataSet(0x2C,v);}
    void setMatrixControl1Sens1(int v) {DataSetOffset(0x2D,v,64);}
    void setMatrixControl1Destination2(int v) {DataSet(0x2E,v);}
    void setMatrixControl1Sens2(int v) {DataSetOffset(0x2F,v,64);}
    void setMatrixControl1Destination3(int v) {DataSet(0x30,v);}
    void setMatrixControl1Sens3(int v) {DataSetOffset(0x31,v,64);}
    void setMatrixControl1Destination4(int v) {DataSet(0x32,v);}
    void setMatrixControl1Sens4(int v) {DataSetOffset(0x33,v,64);}
    void setMatrixControl2Source(int v) {DataSet(0x34,v);}
    void setMatrixControl2Destination1(int v) {DataSet(0x35,v);}
    void setMatrixControl2Sens1(int v) {DataSetOffset(0x36,v,64);}
    void setMatrixControl2Destination2(int v) {DataSet(0x37,v);}
    void setMatrixControl2Sens2(int v) {DataSetOffset(0x38,v,64);}
    void setMatrixControl2Destination3(int v) {DataSet(0x39,v);}
    void setMatrixControl2Sens3(int v) {DataSetOffset(0x3A,v,64);}
    void setMatrixControl2Destination4(int v) {DataSet(0x3B,v);}
    void setMatrixControl2Sens4(int v) {DataSetOffset(0x3C,v,64);}
    void setMatrixControl3Source(int v) {DataSet(0x3D,v);}
    void setMatrixControl3Destination1(int v) {DataSet(0x3E,v);}
    void setMatrixControl3Sens1(int v) {DataSetOffset(0x3F,v,64);}
    void setMatrixControl3Destination2(int v) {DataSet(0x40,v);}
    void setMatrixControl3Sens2(int v) {DataSetOffset(0x41,v,64);}
    void setMatrixControl3Destination3(int v) {DataSet(0x42,v);}
    void setMatrixControl3Sens3(int v) {DataSetOffset(0x43,v,64);}
    void setMatrixControl3Destination4(int v) {DataSet(0x44,v);}
    void setMatrixControl3Sens4(int v) {DataSetOffset(0x45,v,64);}
    void setMatrixControl4Source(int v) {DataSet(0x46,v);}
    void setMatrixControl4Destination1(int v) {DataSet(0x47,v);}
    void setMatrixControl4Sens1(int v) {DataSetOffset(0x48,v,64);}
    void setMatrixControl4Destination2(int v) {DataSet(0x49,v);}
    void setMatrixControl4Sens2(int v) {DataSetOffset(0x4A,v,64);}
    void setMatrixControl4Destination3(int v) {DataSet(0x4B,v);}
    void setMatrixControl4Sens3(int v) {DataSetOffset(0x4C,v,64);}
    void setMatrixControl4Destination4(int v) {DataSet(0x4D,v);}
    void setMatrixControl4Sens4(int v) {DataSetOffset(0x4E,v,64);}

signals:

    void PCMSynthToneName1(int v);
    void PCMSynthToneName2(int v);
    void PCMSynthToneName3(int v);
    void PCMSynthToneName4(int v);
    void PCMSynthToneName5(int v);
    void PCMSynthToneName6(int v);
    void PCMSynthToneName7(int v);
    void PCMSynthToneName8(int v);
    void PCMSynthToneName9(int v);
    void PCMSynthToneName10(int v);
    void PCMSynthToneName11(int v);
    void PCMSynthToneName12(int v);
    void PCMSynthToneName(QString v);
    void PCMSynthToneLevel(int v);
    void PCMSynthTonePan(int v);
    void PCMSynthTonePriority(int v);
    void PCMSynthToneCoarseTune(int v);
    void PCMSynthToneFineTune(int v);
    void OctaveShift(int v);
    void StretchTuneDepth(int v);
    void AnalogFeel(int v);
    void MonoPoly(int v);
    void LegatoSwitch(int v);
    void LegatoRetrigger(int v);
    void PortamentoSwitch(int v);
    void PortamentoMode(int v);
    void PortamentoType(int v);
    void PortamentoStart(int v);
    void PortamentoTime(int v);
    void CutoffOffset(int v);
    void ResonanceOffset(int v);
    void AttackTimeOffset(int v);
    void ReleaseTimeOffset(int v);
    void VelocitySensOffset(int v);
    void PMTControlSwitch(int v);
    void PitchBendRangeUp(int v);
    void PitchBendRangeDown(int v);
    void MatrixControl1Source(int v);
    void MatrixControl1Destination1(int v);
    void MatrixControl1Sens1(int v);
    void MatrixControl1Destination2(int v);
    void MatrixControl1Sens2(int v);
    void MatrixControl1Destination3(int v);
    void MatrixControl1Sens3(int v);
    void MatrixControl1Destination4(int v);
    void MatrixControl1Sens4(int v);
    void MatrixControl2Source(int v);
    void MatrixControl2Destination1(int v);
    void MatrixControl2Sens1(int v);
    void MatrixControl2Destination2(int v);
    void MatrixControl2Sens2(int v);
    void MatrixControl2Destination3(int v);
    void MatrixControl2Sens3(int v);
    void MatrixControl2Destination4(int v);
    void MatrixControl2Sens4(int v);
    void MatrixControl3Source(int v);
    void MatrixControl3Destination1(int v);
    void MatrixControl3Sens1(int v);
    void MatrixControl3Destination2(int v);
    void MatrixControl3Sens2(int v);
    void MatrixControl3Destination3(int v);
    void MatrixControl3Sens3(int v);
    void MatrixControl3Destination4(int v);
    void MatrixControl3Sens4(int v);
    void MatrixControl4Source(int v);
    void MatrixControl4Destination1(int v);
    void MatrixControl4Sens1(int v);
    void MatrixControl4Destination2(int v);
    void MatrixControl4Sens2(int v);
    void MatrixControl4Destination3(int v);
    void MatrixControl4Sens3(int v);
    void MatrixControl4Destination4(int v);
    void MatrixControl4Sens4(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7PCMSYNTHTONECOMMON_H
