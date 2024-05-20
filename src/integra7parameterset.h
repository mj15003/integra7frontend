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

#ifndef INTEGRA7PARAMETERSET_H
#define INTEGRA7PARAMETERSET_H

#include <QObject>
#include "integra7device.h"

class Integra7ParameterSet : public QObject
{

public:
    explicit Integra7ParameterSet(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);
    virtual int GetLength() = 0;
    virtual int GetItemsNumber() = 0;
    uint8_t GetAddress(uint8_t i) const { return address[i]; };
    void GetRequestArray(uint8_t *req);
    int OutputDump(uint8_t *dump);
    virtual void DataReceive(const uint8_t *rdata, uint8_t a, int len) = 0;

protected:    
    Integra7Device *pIntegraDev;
    uint8_t address[3];
    uint8_t data[256];//data store

    void DataSet(uint8_t a, int v);
    void DataSetOffset(uint8_t a, int v, int offset);
    void DataSet2x7B(uint8_t a, int v);
    void DataSet2x4B(uint8_t a, int v);
    void DataSet4x4B(uint8_t a, int v);    
    virtual void EmitSignal(uint8_t a, int v) = 0;
};

#endif // INTEGRA7PARAMETERSET_H
