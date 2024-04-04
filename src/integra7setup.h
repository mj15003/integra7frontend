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

#ifndef INTEGRA7SETUP_H
#define INTEGRA7SETUP_H

#include <QStringList>

#include "integra7parameterset.h"

class Integra7Setup : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7Setup(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    uint16_t GetLength() {return 0x38;}

    uint16_t GetItemsNumber() {return 3;}

    uint8_t getSoundMode() const { return data[0]; }
    uint16_t getStudioSet_BS() const { return data[4] << 7 | data[5]; }
    uint8_t getStudioSet_PC() const { return data[6]; }

    static QStringList& SoundModeLabels() {
        static QStringList list = {"STUDIO","GM1","GM2","GS"};
        return list;
    }

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

public slots:
    void setSoundMode(int v) { DataSet(0,v);}
    void setStudioSet_BS(int v) { DataSet2x7B(4,v); }
    void setStudioSet_PC(int v) { DataSet(6,v); }

signals:
    void SoundMode(uint8_t v);
    void StudioSet_BS(uint16_t v);
    void StudioSet_PC(uint8_t v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7SETUP_H
