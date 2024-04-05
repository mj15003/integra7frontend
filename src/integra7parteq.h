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

#ifndef INTEGRA7PARTEQ_H
#define INTEGRA7PARTEQ_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7PartEQ : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7PartEQ(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 8;}
    int GetItemsNumber() {return 8;}

    int GetEQSwitch() {return data[0];}
    int GetEQLowFreq() {return data[1];}
    int GetEQLowGain() {return data[2]-15;}
    int GetEQMidFreq() {return data[3];}
    int GetEQMidGain() {return data[4]-15;}
    int GetEQMidQ() {return data[5];}
    int GetEQHighFreq() {return data[6];}
    int GetEQHighGain() {return data[7]-15;}

public slots:
    void setEQSwitch(int v) {DataSet(0,v);}
    void setEQLowFreq(int v) {DataSet(1,v);}
    void setEQLowGain(int v) {DataSetOffset(2,v,15);}
    void setEQMidFreq(int v) {DataSet(3,v);}
    void setEQMidGain(int v) {DataSetOffset(4,v,15);}
    void setEQMidQ(int v) {DataSet(5,v);}
    void setEQHighFreq(int v) {DataSet(6,v);}
    void setEQHighGain(int v) {DataSetOffset(7,v,15);}

signals:
    void EQSwitch(int v);
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

#endif // INTEGRA7PARTEQ_H
