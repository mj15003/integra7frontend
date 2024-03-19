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

#ifndef INTEGRA7REVERB_H
#define INTEGRA7REVERB_H

#include "integra7parameterset.h"

class Integra7Reverb : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7Reverb(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    uint16_t GetLength() {return 0x63;}
    uint16_t GetItemsNumber() {return 11;}

    uint8_t getType() {return data[0x0];}
    uint8_t getLevel() {return data[0x1];}
    uint8_t getReverbOutputAssign() {return data[0x2];}

    //Room,Hall,Plate section
    uint8_t getPreDelay() {return data[0x09]<<4|data[0x0A];}
    uint8_t getTime() {return data[0x0D]<<4|data[0x0E];}
    uint8_t getDensity() {return data[0x11]<<4|data[0x12];}
    uint8_t getDiffusion() {return data[0x15]<<4|data[0x16];}
    uint8_t getLFDamp() {return data[0x19]<<4|data[0x1A];}
    uint8_t getHFDamp() {return data[0x1D]<<4|data[0x1E];}
    uint8_t getSpread() {return data[0x21]<<4|data[0x22];}
    uint8_t getTone() {return data[0x25]<<4|data[0x26];}

    //GM2Reverb
    uint8_t getGM2Character() {return data[0x03];}
    uint8_t getGM2Time() {return data[0x11]<<4|data[0x12];}

    static QStringList& TypeList() {
        static QStringList list = {"OFF","Room1","Room2","Hall 1","Hall 2","Plate","GM2 Reverb"};
        return list;
    }

public slots:
    void setType(int v) {DataSet(0x00,v);}
    void setLevel(int v) {DataSet(0x01,v);}
    void setOutputAssign(int v) {DataSet(0x02,v);}

    //Room,Hall,Plate section
    void setPreDelay(int v) {DataSet4x4B(0x07,v);}
    void setTime(int v) {DataSet4x4B(0x0B,v);}
    void setDensity(int v) {DataSet4x4B(0x0F,v);}
    void setDiffusion(int v) {DataSet4x4B(0x13,v);}
    void setLFDamp(int v) {DataSet4x4B(0x17,v);}
    void setHFDamp(int v) {DataSet4x4B(0x1B,v);}
    void setSpread(int v) {DataSet4x4B(0x1F,v);}
    void setTone(int v) {DataSet4x4B(0x23,v);}

    //GM2Reverb
    void setGM2Character(int v) {DataSet4x4B(0x03,v);}
    void setGM2Time(int v) {DataSet4x4B(0x0F,v);}

signals:
    void Type(int v);
    void Level(int v);
    void OutputAssign(int v);

    //Room,Hall,Plate section
    void PreDelay(int v);
    void Time(int v);
    void Density(int v);
    void Diffusion(int v);
    void LFDamp(int v);
    void HFDamp(int v);
    void Spread(int v);
    void Tone(int v);

    //GM2Reverb
    void GM2Character(int v);
    void GM2Time(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7REVERB_H
