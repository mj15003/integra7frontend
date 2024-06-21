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

#ifndef INTEGRA7SNDRUMKITNOTE_H
#define INTEGRA7SNDRUMKITNOTE_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7SNDrumKitNote : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7SNDrumKitNote(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getInstNumber() {return data[0x00]<<12|data[0x01]<<8|data[0x02]<<4|data[0x03];}
    int getLevel() {return data[0x04];}
    int getPan() {return data[0x05]-64;}
    int getChorusSendLevel() {return data[0x06];}
    int getReverbSendLevel() {return data[0x07];}
    int getTune() {return ((data[0x08]<<12|data[0x09]<<8|data[0x0A]<<4|data[0x0B])-128)*10;}
    int getAttack() {return data[0x0C];}
    int getDecay() {return data[0x0D];}
    int getBrilliance() {return data[0x0E]-64;}
    int getVariation() {return data[0x0F];}
    int getDynamicRange() {return data[0x10];}
    int getStereoWidth() {return data[0x11];}
    int getOutputAssign() {return data[0x12];}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x13;}
    int GetItemsNumber() {return 13;}

public slots:

    void setInstNumber(int v) {DataSet4x4B(0x00,v);}
    void setLevel(int v) {DataSet(0x04,v);}
    void setPan(int v) {DataSetOffset(0x05,v,64);}
    void setChorusSendLevel(int v) {DataSet(0x06,v);}
    void setReverbSendLevel(int v) {DataSet(0x07,v);}
    void setTune(int v) {DataSet4x4B(0x08,v/10+128);}
    void setAttack(int v) {DataSet(0x0C,v);}
    void setDecay(int v) {DataSet(0x0D,v);}
    void setBrilliance(int v) {DataSetOffset(0x0E,v,64);}
    void setVariation(int v) {DataSet(0x0F,v);}
    void setDynamicRange(int v) {DataSet(0x10,v);}
    void setStereoWidth(int v) {DataSet(0x11,v);}
    void setOutputAssign(int v) {DataSet(0x12,v);}

signals:
    void InstNumber(int v);
    void Level(int v);
    void Pan(int v);
    void ChorusSendLevel(int v);
    void ReverbSendLevel(int v);
    void Tune(int v);
    void Attack(int v);
    void Decay(int v);
    void Brilliance(int v);
    void Variation(int v);
    void DynamicRange(int v);
    void StereoWidth(int v);
    void OutputAssign(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7SNDRUMKITNOTE_H
