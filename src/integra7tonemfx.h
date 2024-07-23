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

#ifndef INTEGRA7TONEMFX_H
#define INTEGRA7TONEMFX_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7ToneMFX : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7ToneMFX(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getMFXType() {return data[0x00];}
    int getMFXChorusSendLevel() {return data[0x02];}
    int getMFXReverbSendLevel() {return data[0x03];}
    int getMFXControl1Source() {return data[0x05];}
    int getMFXControl1Sens() {return data[0x06]-64;}
    int getMFXControl2Source() {return data[0x07];}
    int getMFXControl2Sens() {return data[0x08]-64;}
    int getMFXControl3Source() {return data[0x09];}
    int getMFXControl3Sens() {return data[0x0A]-64;}
    int getMFXControl4Source() {return data[0x0B];}
    int getMFXControl4Sens() {return data[0x0C]-64;}
    int getMFXControlAssign1() {return data[0x0D];}
    int getMFXControlAssign2() {return data[0x0E];}
    int getMFXControlAssign3() {return data[0x0F];}
    int getMFXControlAssign4() {return data[0x10];}
    int getMFXParameter1() {return (data[0x11]<<12|data[0x12]<<8|data[0x13]<<4|data[0x14])-32768;}
    int getMFXParameter2() {return (data[0x15]<<12|data[0x16]<<8|data[0x17]<<4|data[0x18])-32768;}
    int getMFXParameter3() {return (data[0x19]<<12|data[0x1A]<<8|data[0x1B]<<4|data[0x1C])-32768;}
    int getMFXParameter4() {return (data[0x1D]<<12|data[0x1E]<<8|data[0x1F]<<4|data[0x20])-32768;}
    int getMFXParameter5() {return (data[0x21]<<12|data[0x22]<<8|data[0x23]<<4|data[0x24])-32768;}
    int getMFXParameter6() {return (data[0x25]<<12|data[0x26]<<8|data[0x27]<<4|data[0x28])-32768;}
    int getMFXParameter7() {return (data[0x29]<<12|data[0x2A]<<8|data[0x2B]<<4|data[0x2C])-32768;}
    int getMFXParameter8() {return (data[0x2D]<<12|data[0x2E]<<8|data[0x2F]<<4|data[0x30])-32768;}
    int getMFXParameter9() {return (data[0x31]<<12|data[0x32]<<8|data[0x33]<<4|data[0x34])-32768;}
    int getMFXParameter10() {return (data[0x35]<<12|data[0x36]<<8|data[0x37]<<4|data[0x38])-32768;}
    int getMFXParameter11() {return (data[0x39]<<12|data[0x3A]<<8|data[0x3B]<<4|data[0x3C])-32768;}
    int getMFXParameter12() {return (data[0x3D]<<12|data[0x3E]<<8|data[0x3F]<<4|data[0x40])-32768;}
    int getMFXParameter13() {return (data[0x41]<<12|data[0x42]<<8|data[0x43]<<4|data[0x44])-32768;}
    int getMFXParameter14() {return (data[0x45]<<12|data[0x46]<<8|data[0x47]<<4|data[0x48])-32768;}
    int getMFXParameter15() {return (data[0x49]<<12|data[0x4A]<<8|data[0x4B]<<4|data[0x4C])-32768;}
    int getMFXParameter16() {return (data[0x4D]<<12|data[0x4E]<<8|data[0x4F]<<4|data[0x50])-32768;}
    int getMFXParameter17() {return (data[0x51]<<12|data[0x52]<<8|data[0x53]<<4|data[0x54])-32768;}
    int getMFXParameter18() {return (data[0x55]<<12|data[0x56]<<8|data[0x57]<<4|data[0x58])-32768;}
    int getMFXParameter19() {return (data[0x59]<<12|data[0x5A]<<8|data[0x5B]<<4|data[0x5C])-32768;}
    int getMFXParameter20() {return (data[0x5D]<<12|data[0x5E]<<8|data[0x5F]<<4|data[0x60])-32768;}
    int getMFXParameter21() {return (data[0x61]<<12|data[0x62]<<8|data[0x63]<<4|data[0x64])-32768;}
    int getMFXParameter22() {return (data[0x65]<<12|data[0x66]<<8|data[0x67]<<4|data[0x68])-32768;}
    int getMFXParameter23() {return (data[0x69]<<12|data[0x6A]<<8|data[0x6B]<<4|data[0x6C])-32768;}
    int getMFXParameter24() {return (data[0x6D]<<12|data[0x6E]<<8|data[0x6F]<<4|data[0x70])-32768;}
    int getMFXParameter25() {return (data[0x71]<<12|data[0x72]<<8|data[0x73]<<4|data[0x74])-32768;}
    int getMFXParameter26() {return (data[0x75]<<12|data[0x76]<<8|data[0x77]<<4|data[0x78])-32768;}
    int getMFXParameter27() {return (data[0x79]<<12|data[0x7A]<<8|data[0x7B]<<4|data[0x7C])-32768;}
    int getMFXParameter28() {return (data[0x7D]<<12|data[0x7E]<<8|data[0x7F]<<4|data[0x80])-32768;}
    int getMFXParameter29() {return (data[0x81]<<12|data[0x82]<<8|data[0x83]<<4|data[0x84])-32768;}
    int getMFXParameter30() {return (data[0x85]<<12|data[0x86]<<8|data[0x87]<<4|data[0x88])-32768;}
    int getMFXParameter31() {return (data[0x89]<<12|data[0x8A]<<8|data[0x8B]<<4|data[0x8C])-32768;}
    int getMFXParameter32() {return (data[0x8D]<<12|data[0x8E]<<8|data[0x8F]<<4|data[0x90])-32768;}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 145;}
    int GetItemsNumber() {return 49;}

public slots:

    void setMFXType(int v) {DataSet(0x00,v);}
    void setMFXChorusSendLevel(int v) {DataSet(0x02,v);}
    void setMFXReverbSendLevel(int v) {DataSet(0x03,v);}
    void setMFXControl1Source(int v) {DataSet(0x05,v);}
    void setMFXControl1Sens(int v) {DataSetOffset(0x06,v,64);}
    void setMFXControl2Source(int v) {DataSet(0x07,v);}
    void setMFXControl2Sens(int v) {DataSetOffset(0x08,v,64);}
    void setMFXControl3Source(int v) {DataSet(0x09,v);}
    void setMFXControl3Sens(int v) {DataSetOffset(0x0A,v,64);}
    void setMFXControl4Source(int v) {DataSet(0x0B,v);}
    void setMFXControl4Sens(int v) {DataSetOffset(0x0C,v,64);}
    void setMFXControlAssign1(int v) {DataSet(0x0D,v);}
    void setMFXControlAssign2(int v) {DataSet(0x0E,v);}
    void setMFXControlAssign3(int v) {DataSet(0x0F,v);}
    void setMFXControlAssign4(int v) {DataSet(0x10,v);}
    void setMFXParameter1(int v) {DataSet4x4B(0x11,v+32768);}
    void setMFXParameter2(int v) {DataSet4x4B(0x15,v+32768);}
    void setMFXParameter3(int v) {DataSet4x4B(0x19,v+32768);}
    void setMFXParameter4(int v) {DataSet4x4B(0x1D,v+32768);}
    void setMFXParameter5(int v) {DataSet4x4B(0x21,v+32768);}
    void setMFXParameter6(int v) {DataSet4x4B(0x25,v+32768);}
    void setMFXParameter7(int v) {DataSet4x4B(0x29,v+32768);}
    void setMFXParameter8(int v) {DataSet4x4B(0x2D,v+32768);}
    void setMFXParameter9(int v) {DataSet4x4B(0x31,v+32768);}
    void setMFXParameter10(int v) {DataSet4x4B(0x35,v+32768);}
    void setMFXParameter11(int v) {DataSet4x4B(0x39,v+32768);}
    void setMFXParameter12(int v) {DataSet4x4B(0x3D,v+32768);}
    void setMFXParameter13(int v) {DataSet4x4B(0x41,v+32768);}
    void setMFXParameter14(int v) {DataSet4x4B(0x45,v+32768);}
    void setMFXParameter15(int v) {DataSet4x4B(0x49,v+32768);}
    void setMFXParameter16(int v) {DataSet4x4B(0x4D,v+32768);}
    void setMFXParameter17(int v) {DataSet4x4B(0x51,v+32768);}
    void setMFXParameter18(int v) {DataSet4x4B(0x55,v+32768);}
    void setMFXParameter19(int v) {DataSet4x4B(0x59,v+32768);}
    void setMFXParameter20(int v) {DataSet4x4B(0x5D,v+32768);}
    void setMFXParameter21(int v) {DataSet4x4B(0x61,v+32768);}
    void setMFXParameter22(int v) {DataSet4x4B(0x65,v+32768);}
    void setMFXParameter23(int v) {DataSet4x4B(0x69,v+32768);}
    void setMFXParameter24(int v) {DataSet4x4B(0x6D,v+32768);}
    void setMFXParameter25(int v) {DataSet4x4B(0x71,v+32768);}
    void setMFXParameter26(int v) {DataSet4x4B(0x75,v+32768);}
    void setMFXParameter27(int v) {DataSet4x4B(0x79,v+32768);}
    void setMFXParameter28(int v) {DataSet4x4B(0x7D,v+32768);}
    void setMFXParameter29(int v) {DataSet4x4B(0x81,v+32768);}
    void setMFXParameter30(int v) {DataSet4x4B(0x85,v+32768);}
    void setMFXParameter31(int v) {DataSet4x4B(0x89,v+32768);}
    void setMFXParameter32(int v) {DataSet4x4B(0x8D,v+32768);}

    static QStringList& MFXControlSourceList() {
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
                                   "BEND","AFT","SYS1","SYS2","SYS3","SYS4" };
        return list;
    }

signals:

    void MFXType(int v);
    void MFXChorusSendLevel(int v);
    void MFXReverbSendLevel(int v);
    void MFXControl1Source(int v);
    void MFXControl1Sens(int v);
    void MFXControl2Source(int v);
    void MFXControl2Sens(int v);
    void MFXControl3Source(int v);
    void MFXControl3Sens(int v);
    void MFXControl4Source(int v);
    void MFXControl4Sens(int v);
    void MFXControlAssign1(int v);
    void MFXControlAssign2(int v);
    void MFXControlAssign3(int v);
    void MFXControlAssign4(int v);
    void MFXParameter1(int v);
    void MFXParameter2(int v);
    void MFXParameter3(int v);
    void MFXParameter4(int v);
    void MFXParameter5(int v);
    void MFXParameter6(int v);
    void MFXParameter7(int v);
    void MFXParameter8(int v);
    void MFXParameter9(int v);
    void MFXParameter10(int v);
    void MFXParameter11(int v);
    void MFXParameter12(int v);
    void MFXParameter13(int v);
    void MFXParameter14(int v);
    void MFXParameter15(int v);
    void MFXParameter16(int v);
    void MFXParameter17(int v);
    void MFXParameter18(int v);
    void MFXParameter19(int v);
    void MFXParameter20(int v);
    void MFXParameter21(int v);
    void MFXParameter22(int v);
    void MFXParameter23(int v);
    void MFXParameter24(int v);
    void MFXParameter25(int v);
    void MFXParameter26(int v);
    void MFXParameter27(int v);
    void MFXParameter28(int v);
    void MFXParameter29(int v);
    void MFXParameter30(int v);
    void MFXParameter31(int v);
    void MFXParameter32(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7TONEMFX_H
