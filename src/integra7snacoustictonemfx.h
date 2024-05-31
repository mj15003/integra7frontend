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

#ifndef INTEGRA7SNACOUSTICTONEMFX_H
#define INTEGRA7SNACOUSTICTONEMFX_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7SNAcousticToneMFX : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7SNAcousticToneMFX(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 145;}
    int GetItemsNumber() {return 49;}

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7SNACOUSTICTONEMFX_H
