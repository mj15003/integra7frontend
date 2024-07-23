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

#ifndef INTEGRA7MASTEREQ_H
#define INTEGRA7MASTEREQ_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7MasterEQ : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7MasterEQ(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 7;}
    int GetItemsNumber() {return 7;}

    int GetEQLowFreq() {return data[0];}
    int GetEQLowGain() {return data[1]-15;}
    int GetEQMidFreq() {return data[2];}
    int GetEQMidGain() {return data[3]-15;}
    int GetEQMidQ() {return data[4];}
    int GetEQHighFreq() {return data[5];}
    int GetEQHighGain() {return data[6]-15;}

    static QStringList& LowFreqList() {
        static QStringList list = { "200","400" };
        return list;
    }

    static QStringList& MidFreqList() {
        static QStringList list = { "200","250","315","400","500","630","800","1000","1250","1600",
                                   "2000","2500","3150","4000","5000","6300","8000" };
        return list;
    }

    static QStringList& MidQList() {
        static QStringList list = { "0.5","1.0","2.0","4.0","8.0" };
        return list;
    }

    static QStringList& HighFreqList() {
        static QStringList list = { "2000","4000","8000" };
        return list;
    }

public slots:
    void setEQLowFreq(int v) {DataSet(0,v);}
    void setEQLowGain(int v) {DataSetOffset(1,v,15);}
    void setEQMidFreq(int v) {DataSet(2,v);}
    void setEQMidGain(int v) {DataSetOffset(3,v,15);}
    void setEQMidQ(int v) {DataSet(4,v);}
    void setEQHighFreq(int v) {DataSet(5,v);}
    void setEQHighGain(int v) {DataSetOffset(6,v,15);}

signals:
    void EQLowFreq(int v);
    void EQLowGain(int v);
    void EQMidFreq(int v);
    void EQMidGain(int v);
    void EQMidQ(int v);
    void EQHighFreq(int v);
    void EQHighGain(int v);

private:    
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7MASTEREQ_H
