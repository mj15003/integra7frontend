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

#ifndef INTEGRA7PCMDRUMKITCOMMON_H
#define INTEGRA7PCMDRUMKITCOMMON_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7PCMDrumKitCommon : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7PCMDrumKitCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getKitName1() {return data[0x00];}
    int getKitName2() {return data[0x01];}
    int getKitName3() {return data[0x02];}
    int getKitName4() {return data[0x03];}
    int getKitName5() {return data[0x04];}
    int getKitName6() {return data[0x05];}
    int getKitName7() {return data[0x06];}
    int getKitName8() {return data[0x07];}
    int getKitName9() {return data[0x08];}
    int getKitName10() {return data[0x09];}
    int getKitName11() {return data[0x0A];}
    int getKitName12() {return data[0x0B];}
    int getKitLevel() {return data[0x0C];}

    QLatin1StringView getKitName() {return QLatin1StringView((char*)&data[0],(char*)&data[0x0B]);}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x12;}
    int GetItemsNumber() {return 2;}

public slots:

    void setKitName(const QString name);
    void setKitName1(int v) {DataSet(0x00,v);}
    void setKitName2(int v) {DataSet(0x01,v);}
    void setKitName3(int v) {DataSet(0x02,v);}
    void setKitName4(int v) {DataSet(0x03,v);}
    void setKitName5(int v) {DataSet(0x04,v);}
    void setKitName6(int v) {DataSet(0x05,v);}
    void setKitName7(int v) {DataSet(0x06,v);}
    void setKitName8(int v) {DataSet(0x07,v);}
    void setKitName9(int v) {DataSet(0x08,v);}
    void setKitName10(int v) {DataSet(0x09,v);}
    void setKitName11(int v) {DataSet(0x0A,v);}
    void setKitName12(int v) {DataSet(0x0B,v);}
    void setKitLevel(int v) {DataSet(0x0C,v);}

signals:

    void KitName1(int v);
    void KitName2(int v);
    void KitName3(int v);
    void KitName4(int v);
    void KitName5(int v);
    void KitName6(int v);
    void KitName7(int v);
    void KitName8(int v);
    void KitName9(int v);
    void KitName10(int v);
    void KitName11(int v);
    void KitName12(int v);
    void KitName(QString v);
    void KitLevel(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7PCMDRUMKITCOMMON_H
