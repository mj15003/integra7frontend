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

#ifndef INTEGRA7PCMDRUMKITCOMMON2_H
#define INTEGRA7PCMDRUMKITCOMMON2_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7PCMDrumKitCommon2 : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7PCMDrumKitCommon2(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getPhraseNumber() {return data[0x10]<<4|data[0x11];}
    int getTFXSwitch() {return data[0x31];}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x32;}
    int GetItemsNumber() {return 2;}

public slots:

    void setPhraseNumber(int v) {DataSet2x4B(0x10,v);}
    void setTFXSwitch(int v) {DataSet(0x31,v);}

signals:

    void PhraseNumber(int v);
    void TFXSwitch(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7PCMDRUMKITCOMMON2_H
