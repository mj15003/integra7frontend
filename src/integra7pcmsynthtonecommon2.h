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

#ifndef INTEGRA7PCMSYNTHTONECOMMON2_H
#define INTEGRA7PCMSYNTHTONECOMMON2_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7PCMSynthToneCommon2 : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7PCMSynthToneCommon2(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getToneCategory() {return data[0x10];}
    int getPhraseOctaveShift() {return data[0x13]-64;}
    int getTFXSwitch() {return data[0x33];}
    int getPhraseNumber() {return data[0x38]<<12|data[0x39]<<8|data[0x3A]<<4|data[0x3B];}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x3C;}
    int GetItemsNumber() {return 5;}

public slots:

    void setToneCategory(int v) {DataSet(0x10,v);}
    void setPhraseOctaveShift(int v) {DataSetOffset(0x13,v,64);}
    void setTFXSwitch(int v) {DataSet(0x33,v);}
    void setPhraseNumber(int v) {DataSet4x4B(0x38,v);}

signals:

    void ToneCategory(int v);
    void PhraseOctaveShift(int v);
    void TFXSwitch(int v);
    void PhraseNumber(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7PCMSYNTHTONECOMMON2_H
