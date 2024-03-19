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

#ifndef INTEGRA7CHORUS_H
#define INTEGRA7CHORUS_H

#include "integra7parameterset.h"

class Integra7Chorus : public Integra7ParameterSet
{
public:
    explicit Integra7Chorus(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    uint16_t GetLength() {return 0x54;}
    uint16_t GetItemsNumber() {return 24;}

    uint8_t getChorusType() {return data[0x0];}
    uint8_t getChorusLevel() {return data[0x1];}
    uint8_t getChorusOutputSelect() {return data[0x3];}

    //Chorus Section
    uint8_t getChorusFilterType() {return data[0x07];}
    uint8_t getChorusCutoffFreq() {return data[0x0A]<<4|data[0x0B];}
    uint8_t getChorusPreDelay() {return data[0x0E]<<4|data[0x0F];}
    uint8_t getChorusRateType() {return data[0x07];}
    uint8_t getChorusRateHz() {return data[0x16]<<4|data[0x17];}
    uint8_t getChorusRateNote() {return data[0x1A]<<4|data[0x1B];}
    uint8_t getChorusDepth() {return data[0x1E]<<4|data[0x1F];}
    uint8_t getChorusPhase() {return data[0x22]<<4|data[0x23];}
    uint8_t getChorusFeedback() {return data[0x26]<<4|data[0x27];}

    //Delay Section
    uint8_t getDelayDelayLeft() {return data[0x07];}
    uint16_t getDelayDelayLeftMS() {return data[0x09]<<8|data[0x0A]<<4|data[0x0B];}
    uint8_t getDelayDelayLeftNote() {return data[0x0E]<<4|data[0x0F];}
    uint8_t getDelayDelayRight() {return data[0x13];}
    uint16_t getDelayDelayRightMS() {return data[0x15]<<8|data[0x16]<<4|data[0x17];}
    uint8_t getDelayDelayRightNote() {return data[0x0A]<<4|data[0x0B];}
    uint8_t getDelayDelayCenter() {return data[0x1F];}
    uint16_t getDelayDelayCenterMS() {return data[0x21]<<8|data[0x22]<<4|data[0x23];}
    uint8_t getDelayDelayCenterNote() {return data[0x26]<<4|data[0x27];}
    uint8_t getDelayFeedback() {return data[0x2A]<<4|data[0x2B];}
    uint8_t getDelayHFDamp() {return data[0x2E]<<4|data[0x2F];}
    uint8_t getDelayLeftLevel() {return data[0x32]<<4|data[0x33];}
    uint8_t getDelayRightLevel() {return data[0x36]<<4|data[0x37];}
    uint8_t getDelayCenterLevel() {return data[0x3A]<<4|data[0x3B];}

    //GM2 Chorus
    uint8_t getGM2ChorusPreLPF() {return data[0x07];}
    uint8_t getGM2ChorusLevel() {return data[0x0A]<<4|data[0x0B];}
    uint8_t getGM2ChorusFeedback() {return data[0x0E]<<4|data[0x0F];}
    uint8_t getGM2ChorusDelay() {return data[0x12]<<4|data[0x13];}
    uint8_t getGM2ChorusRate() {return data[0x16]<<4|data[0x17];}
    uint8_t getGM2ChorusDepth() {return data[0x0A]<<4|data[0x0B];}

public slots:
    void setChorusType(int v) { DataSet(0x00,v); }
    void setChorusLevel(int v) { DataSet(0x01,v); }
    void setChorusOutputSelect(int v) { DataSet(0x03,v); }

    //Chorus Section
    void setChorusFilterType(int v) { DataSet4x4B(0x04,v); }
    void setChorusCutoffFreq(int v) { DataSet4x4B(0x08,v); }
    void setChorusPreDelay(int v) { DataSet4x4B(0x0C,v); }
    void setChorusRateType(int v) { DataSet4x4B(0x10,v); }
    void setChorusRateHz(int v) { DataSet4x4B(0x14,v); }
    void setChorusRateNote(int v) { DataSet4x4B(0x18,v); }
    void setChorusDepth(int v) { DataSet4x4B(0x1C,v); }
    void setChorusPhase(int v) { DataSet4x4B(0x20,v); }
    void setChorusFeedback(int v) { DataSet4x4B(0x24,v); }

    //Delay Section
    void setDelayDelayLeft(int v) { DataSet4x4B(0x04,v); }
    void setDelayDelayLeftMS(int v) { DataSet4x4B(0x08,v); }
    void setDelayDelayLeftNote(int v) { DataSet4x4B(0x0C,v); }
    void setDelayDelayRight(int v) { DataSet4x4B(0x10,v); }
    void setDelayDelayRightMS(int v) { DataSet4x4B(0x14,v); }
    void setDelayDelayRightNote(int v) { DataSet4x4B(0x18,v); }
    void setDelayDelayCenter(int v) { DataSet4x4B(0x1C,v); }
    void setDelayDelayCenterMS(int v) { DataSet4x4B(0x20,v); }
    void setDelayDelayCenterNote(int v) { DataSet4x4B(0x24,v); }
    void setDelayFeedback(int v) { DataSet4x4B(0x28,v); }
    void setDelayHFDamp(int v) { DataSet4x4B(0x2C,v); }
    void setDelayLeftLevel(int v) { DataSet4x4B(0x30,v); }
    void setDelayRightLevel(int v) { DataSet4x4B(0x34,v); }
    void setDelayCenterLevel(int v) { DataSet4x4B(0x38,v); }

    //GM2 Chorus
    void setGM2ChorusPreLPF(int v) { DataSet4x4B(0x04,v); }
    void setGM2ChorusLevel(int v) { DataSet4x4B(0x08,v); }
    void setGM2ChorusFeedback(int v) { DataSet4x4B(0x0C,v); }
    void setGM2ChorusDelay(int v) { DataSet4x4B(0x10,v); }
    void setGM2ChorusRate(int v) { DataSet4x4B(0x14,v); }
    void setGM2ChorusDepth(int v) { DataSet4x4B(0x18,v); }

signals:
    void ChorusType(int v);
    void ChorusLevel(int v);
    void ChorusOutputSelect(int v);

    //Chorus Section
    void ChorusFilterType(int v);
    void ChorusCutoffFreq(int v);
    void ChorusPreDelay(int v);
    void ChorusRateType(int v);
    void ChorusRateHz(int v);
    void ChorusRateNote(int v);
    void ChorusDepth(int v);
    void ChorusPhase(int v);
    void ChorusFeedback(int v);

    //Delay Section
    void DelayDelayLeft(int v);
    void DelayDelayLeftMS(int v);
    void DelayDelayLeftNote(int v);
    void DelayDelayRight(int v);
    void DelayDelayRightMS(int v);
    void DelayDelayRightNote(int v);
    void DelayDelayCenter(int v);
    void DelayDelayCenterMS(int v);
    void DelayDelayCenterNote(int v);
    void DelayFeedback(int v);
    void DelayHFDamp(int v);
    void DelayLeftLevel(int v);
    void DelayRightLevel(int v);
    void DelayCenterLevel(int v);

    //GM2 Chorus
    void GM2ChorusPreLPF(int v);
    void GM2ChorusLevel(int v);
    void GM2ChorusFeedback(int v);
    void GM2ChorusDelay(int v);
    void GM2ChorusRate(int v);
    void GM2ChorusDepth(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7CHORUS_H
