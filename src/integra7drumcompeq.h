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

#ifndef INTEGRA7DRUMCOMPEQ_H
#define INTEGRA7DRUMCOMPEQ_H

#include "integra7parameterset.h"

class Integra7DrumCompEQ : public Integra7ParameterSet
{
    Q_OBJECT
public:
    Integra7DrumCompEQ(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getComp1Switch() {return data[0x00];}
    int getComp1AttackTime() {return data[0x01];}
    int getComp1ReleaseTime() {return data[0x02];}
    int getComp1Threshold() {return data[0x03];}
    int getComp1Ratio() {return data[0x04];}
    int getComp1OutputGain() {return data[0x05];}
    int getEQ1Switch() {return data[0x06];}
    int getEQ1LowFreq() {return data[0x07];}
    int getEQ1LowGain() {return data[0x08]-15;}
    int getEQ1MidFreq() {return data[0x09];}
    int getEQ1MidGain() {return data[0x0A]-15;}
    int getEQ1MidQ() {return data[0x0B];}
    int getEQ1HighFreq() {return data[0x0C];}
    int getEQ1HighGain() {return data[0x0D]-15;}
    int getComp2Switch() {return data[0x0E];}
    int getComp2AttackTime() {return data[0x0F];}
    int getComp2ReleaseTime() {return data[0x10];}
    int getComp2Threshold() {return data[0x11];}
    int getComp2Ratio() {return data[0x12];}
    int getComp2OutputGain() {return data[0x13];}
    int getEQ2Switch() {return data[0x14];}
    int getEQ2LowFreq() {return data[0x15];}
    int getEQ2LowGain() {return data[0x16]-15;}
    int getEQ2MidFreq() {return data[0x17];}
    int getEQ2MidGain() {return data[0x18]-15;}
    int getEQ2MidQ() {return data[0x19];}
    int getEQ2HighFreq() {return data[0x1A];}
    int getEQ2HighGain() {return data[0x1B]-15;}
    int getComp3Switch() {return data[0x1C];}
    int getComp3AttackTime() {return data[0x1D];}
    int getComp3ReleaseTime() {return data[0x1E];}
    int getComp3Threshold() {return data[0x1F];}
    int getComp3Ratio() {return data[0x20];}
    int getComp3OutputGain() {return data[0x21];}
    int getEQ3Switch() {return data[0x22];}
    int getEQ3LowFreq() {return data[0x23];}
    int getEQ3LowGain() {return data[0x24]-15;}
    int getEQ3MidFreq() {return data[0x25];}
    int getEQ3MidGain() {return data[0x26]-15;}
    int getEQ3MidQ() {return data[0x27];}
    int getEQ3HighFreq() {return data[0x28];}
    int getEQ3HighGain() {return data[0x29]-15;}
    int getComp4Switch() {return data[0x2A];}
    int getComp4AttackTime() {return data[0x2B];}
    int getComp4ReleaseTime() {return data[0x2C];}
    int getComp4Threshold() {return data[0x2D];}
    int getComp4Ratio() {return data[0x2E];}
    int getComp4OutputGain() {return data[0x2F];}
    int getEQ4Switch() {return data[0x30];}
    int getEQ4LowFreq() {return data[0x31];}
    int getEQ4LowGain() {return data[0x32]-15;}
    int getEQ4MidFreq() {return data[0x33];}
    int getEQ4MidGain() {return data[0x34]-15;}
    int getEQ4MidQ() {return data[0x35];}
    int getEQ4HighFreq() {return data[0x36];}
    int getEQ4HighGain() {return data[0x37]-15;}
    int getComp5Switch() {return data[0x38];}
    int getComp5AttackTime() {return data[0x39];}
    int getComp5ReleaseTime() {return data[0x3A];}
    int getComp5Threshold() {return data[0x3B];}
    int getComp5Ratio() {return data[0x3C];}
    int getComp5OutputGain() {return data[0x3D];}
    int getEQ5Switch() {return data[0x3E];}
    int getEQ5LowFreq() {return data[0x3F];}
    int getEQ5LowGain() {return data[0x40]-15;}
    int getEQ5MidFreq() {return data[0x41];}
    int getEQ5MidGain() {return data[0x42]-15;}
    int getEQ5MidQ() {return data[0x43];}
    int getEQ5HighFreq() {return data[0x44];}
    int getEQ5HighGain() {return data[0x45]-15;}
    int getComp6Switch() {return data[0x46];}
    int getComp6AttackTime() {return data[0x47];}
    int getComp6ReleaseTime() {return data[0x48];}
    int getComp6Threshold() {return data[0x49];}
    int getComp6Ratio() {return data[0x4A];}
    int getComp6OutputGain() {return data[0x4B];}
    int getEQ6Switch() {return data[0x4C];}
    int getEQ6LowFreq() {return data[0x4D];}
    int getEQ6LowGain() {return data[0x4E]-15;}
    int getEQ6MidFreq() {return data[0x4F];}
    int getEQ6MidGain() {return data[0x50]-15;}
    int getEQ6MidQ() {return data[0x51];}
    int getEQ6HighFreq() {return data[0x52];}
    int getEQ6HighGain() {return data[0x53]-15;}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x54;}
    int GetItemsNumber() {return 0x54;}

    static QStringList& CompAttackTimeList() {
        static QStringList list = { "0.05","0.06","0.07","0.08","0.09","0.1","0.2","0.3","0.4","0.5",
                                   "0.6","0.7","0.8","0.9","1.0","2.0","3.0","4.0","5.0","6.0","7.0",
                                   "8.0","9.0","10.0","15.0","20.0","25.0","30.0","35.0","40.0","45.0","50.0" };
        return list;
    }

    static QStringList& CompReleaseTimeList() {
        static QStringList list = { "0.05","0.07","0.1","0.5","1","5","10","17","25","50","75",
                                   "100","200","300","400","500","600","700","800","900",
                                   "1000","1200","1500","2000" };
        return list;
    }

    static QStringList& CompRatioList() {
        static QStringList list = { "1:1","2:1","3:1","4:1","5:1","6:1","7:1","8:1","9:1",
                                   "10:1","20:1","30:1","40:1","50:1","60:1",
                                   "70:1","80:1","90:1","100:1","inf:1" };
        return list;
    }

public slots:

    void setComp1Switch(int v) {DataSet(0x00,v);}
    void setComp1AttackTime(int v) {DataSet(0x01,v);}
    void setComp1ReleaseTime(int v) {DataSet(0x02,v);}
    void setComp1Threshold(int v) {DataSet(0x03,v);}
    void setComp1Ratio(int v) {DataSet(0x04,v);}
    void setComp1OutputGain(int v) {DataSet(0x05,v);}
    void setEQ1Switch(int v) {DataSet(0x06,v);}
    void setEQ1LowFreq(int v) {DataSet(0x07,v);}
    void setEQ1LowGain(int v) {DataSetOffset(0x08,v,15);}
    void setEQ1MidFreq(int v) {DataSet(0x09,v);}
    void setEQ1MidGain(int v) {DataSetOffset(0x0A,v,15);}
    void setEQ1MidQ(int v) {DataSet(0x0B,v);}
    void setEQ1HighFreq(int v) {DataSet(0x0C,v);}
    void setEQ1HighGain(int v) {DataSetOffset(0x0D,v,15);}
    void setComp2Switch(int v) {DataSet(0x0E,v);}
    void setComp2AttackTime(int v) {DataSet(0x0F,v);}
    void setComp2ReleaseTime(int v) {DataSet(0x10,v);}
    void setComp2Threshold(int v) {DataSet(0x11,v);}
    void setComp2Ratio(int v) {DataSet(0x12,v);}
    void setComp2OutputGain(int v) {DataSet(0x13,v);}
    void setEQ2Switch(int v) {DataSet(0x14,v);}
    void setEQ2LowFreq(int v) {DataSet(0x15,v);}
    void setEQ2LowGain(int v) {DataSetOffset(0x16,v,15);}
    void setEQ2MidFreq(int v) {DataSet(0x17,v);}
    void setEQ2MidGain(int v) {DataSetOffset(0x18,v,15);}
    void setEQ2MidQ(int v) {DataSet(0x19,v);}
    void setEQ2HighFreq(int v) {DataSet(0x1A,v);}
    void setEQ2HighGain(int v) {DataSetOffset(0x1B,v,15);}
    void setComp3Switch(int v) {DataSet(0x1C,v);}
    void setComp3AttackTime(int v) {DataSet(0x1D,v);}
    void setComp3ReleaseTime(int v) {DataSet(0x1E,v);}
    void setComp3Threshold(int v) {DataSet(0x1F,v);}
    void setComp3Ratio(int v) {DataSet(0x20,v);}
    void setComp3OutputGain(int v) {DataSet(0x21,v);}
    void setEQ3Switch(int v) {DataSet(0x22,v);}
    void setEQ3LowFreq(int v) {DataSet(0x23,v);}
    void setEQ3LowGain(int v) {DataSetOffset(0x24,v,15);}
    void setEQ3MidFreq(int v) {DataSet(0x25,v);}
    void setEQ3MidGain(int v) {DataSetOffset(0x26,v,15);}
    void setEQ3MidQ(int v) {DataSet(0x27,v);}
    void setEQ3HighFreq(int v) {DataSet(0x28,v);}
    void setEQ3HighGain(int v) {DataSetOffset(0x29,v,15);}
    void setComp4Switch(int v) {DataSet(0x2A,v);}
    void setComp4AttackTime(int v) {DataSet(0x2B,v);}
    void setComp4ReleaseTime(int v) {DataSet(0x2C,v);}
    void setComp4Threshold(int v) {DataSet(0x2D,v);}
    void setComp4Ratio(int v) {DataSet(0x2E,v);}
    void setComp4OutputGain(int v) {DataSet(0x2F,v);}
    void setEQ4Switch(int v) {DataSet(0x30,v);}
    void setEQ4LowFreq(int v) {DataSet(0x31,v);}
    void setEQ4LowGain(int v) {DataSetOffset(0x32,v,15);}
    void setEQ4MidFreq(int v) {DataSet(0x33,v);}
    void setEQ4MidGain(int v) {DataSetOffset(0x34,v,15);}
    void setEQ4MidQ(int v) {DataSet(0x35,v);}
    void setEQ4HighFreq(int v) {DataSet(0x36,v);}
    void setEQ4HighGain(int v) {DataSetOffset(0x37,v,15);}
    void setComp5Switch(int v) {DataSet(0x38,v);}
    void setComp5AttackTime(int v) {DataSet(0x39,v);}
    void setComp5ReleaseTime(int v) {DataSet(0x3A,v);}
    void setComp5Threshold(int v) {DataSet(0x3B,v);}
    void setComp5Ratio(int v) {DataSet(0x3C,v);}
    void setComp5OutputGain(int v) {DataSet(0x3D,v);}
    void setEQ5Switch(int v) {DataSet(0x3E,v);}
    void setEQ5LowFreq(int v) {DataSet(0x3F,v);}
    void setEQ5LowGain(int v) {DataSetOffset(0x40,v,15);}
    void setEQ5MidFreq(int v) {DataSet(0x41,v);}
    void setEQ5MidGain(int v) {DataSetOffset(0x42,v,15);}
    void setEQ5MidQ(int v) {DataSet(0x43,v);}
    void setEQ5HighFreq(int v) {DataSet(0x44,v);}
    void setEQ5HighGain(int v) {DataSetOffset(0x45,v,15);}
    void setComp6Switch(int v) {DataSet(0x46,v);}
    void setComp6AttackTime(int v) {DataSet(0x47,v);}
    void setComp6ReleaseTime(int v) {DataSet(0x48,v);}
    void setComp6Threshold(int v) {DataSet(0x49,v);}
    void setComp6Ratio(int v) {DataSet(0x4A,v);}
    void setComp6OutputGain(int v) {DataSet(0x4B,v);}
    void setEQ6Switch(int v) {DataSet(0x4C,v);}
    void setEQ6LowFreq(int v) {DataSet(0x4D,v);}
    void setEQ6LowGain(int v) {DataSetOffset(0x4E,v,15);}
    void setEQ6MidFreq(int v) {DataSet(0x4F,v);}
    void setEQ6MidGain(int v) {DataSetOffset(0x50,v,15);}
    void setEQ6MidQ(int v) {DataSet(0x51,v);}
    void setEQ6HighFreq(int v) {DataSet(0x52,v);}
    void setEQ6HighGain(int v) {DataSetOffset(0x53,v,15);}

signals:

    void Comp1Switch(int v);
    void Comp1AttackTime(int v);
    void Comp1ReleaseTime(int v);
    void Comp1Threshold(int v);
    void Comp1Ratio(int v);
    void Comp1OutputGain(int v);
    void EQ1Switch(int v);
    void EQ1LowFreq(int v);
    void EQ1LowGain(int v);
    void EQ1MidFreq(int v);
    void EQ1MidGain(int v);
    void EQ1MidQ(int v);
    void EQ1HighFreq(int v);
    void EQ1HighGain(int v);
    void Comp2Switch(int v);
    void Comp2AttackTime(int v);
    void Comp2ReleaseTime(int v);
    void Comp2Threshold(int v);
    void Comp2Ratio(int v);
    void Comp2OutputGain(int v);
    void EQ2Switch(int v);
    void EQ2LowFreq(int v);
    void EQ2LowGain(int v);
    void EQ2MidFreq(int v);
    void EQ2MidGain(int v);
    void EQ2MidQ(int v);
    void EQ2HighFreq(int v);
    void EQ2HighGain(int v);
    void Comp3Switch(int v);
    void Comp3AttackTime(int v);
    void Comp3ReleaseTime(int v);
    void Comp3Threshold(int v);
    void Comp3Ratio(int v);
    void Comp3OutputGain(int v);
    void EQ3Switch(int v);
    void EQ3LowFreq(int v);
    void EQ3LowGain(int v);
    void EQ3MidFreq(int v);
    void EQ3MidGain(int v);
    void EQ3MidQ(int v);
    void EQ3HighFreq(int v);
    void EQ3HighGain(int v);
    void Comp4Switch(int v);
    void Comp4AttackTime(int v);
    void Comp4ReleaseTime(int v);
    void Comp4Threshold(int v);
    void Comp4Ratio(int v);
    void Comp4OutputGain(int v);
    void EQ4Switch(int v);
    void EQ4LowFreq(int v);
    void EQ4LowGain(int v);
    void EQ4MidFreq(int v);
    void EQ4MidGain(int v);
    void EQ4MidQ(int v);
    void EQ4HighFreq(int v);
    void EQ4HighGain(int v);
    void Comp5Switch(int v);
    void Comp5AttackTime(int v);
    void Comp5ReleaseTime(int v);
    void Comp5Threshold(int v);
    void Comp5Ratio(int v);
    void Comp5OutputGain(int v);
    void EQ5Switch(int v);
    void EQ5LowFreq(int v);
    void EQ5LowGain(int v);
    void EQ5MidFreq(int v);
    void EQ5MidGain(int v);
    void EQ5MidQ(int v);
    void EQ5HighFreq(int v);
    void EQ5HighGain(int v);
    void Comp6Switch(int v);
    void Comp6AttackTime(int v);
    void Comp6ReleaseTime(int v);
    void Comp6Threshold(int v);
    void Comp6Ratio(int v);
    void Comp6OutputGain(int v);
    void EQ6Switch(int v);
    void EQ6LowFreq(int v);
    void EQ6LowGain(int v);
    void EQ6MidFreq(int v);
    void EQ6MidGain(int v);
    void EQ6MidQ(int v);
    void EQ6HighFreq(int v);
    void EQ6HighGain(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7DRUMCOMPEQ_H
