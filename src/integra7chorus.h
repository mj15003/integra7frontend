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
    Q_OBJECT
public:
    explicit Integra7Chorus(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    uint16_t GetLength() {return 0x54;}
    uint16_t GetItemsNumber() {return 24;}

    int getChorusType() {return data[0x0];}
    int getChorusLevel() {return data[0x1];}
    int getChorusOutputSelect() {return data[0x3];}

    //Chorus Section
    int getChorusFilterType() {return data[0x07];}
    int getChorusCutoffFreq() {return data[0x0A]<<4|data[0x0B];}
    int getChorusPreDelay() {return data[0x0E]<<4|data[0x0F];}
    int getChorusRateType() {return data[0x07];}
    int getChorusRateHz() {return (data[0x16]<<4|data[0x17])-1;}
    int getChorusRateNote() {return data[0x1A]<<4|data[0x1B];}
    int getChorusDepth() {return data[0x1E]<<4|data[0x1F];}
    int getChorusPhase() {return (data[0x22]<<4|data[0x23])*2;}
    int getChorusFeedback() {return data[0x26]<<4|data[0x27];}

    //Delay Section
    int getDelayDelayLeft() {return data[0x07];}
    int getDelayDelayLeftMS() {return data[0x09]<<8|data[0x0A]<<4|data[0x0B];}
    int getDelayDelayLeftNote() {return data[0x0E]<<4|data[0x0F];}
    int getDelayDelayRight() {return data[0x13];}
    int getDelayDelayRightMS() {return data[0x15]<<8|data[0x16]<<4|data[0x17];}
    int getDelayDelayRightNote() {return data[0x0A]<<4|data[0x0B];}
    int getDelayDelayCenter() {return data[0x1F];}
    int getDelayDelayCenterMS() {return data[0x21]<<8|data[0x22]<<4|data[0x23];}
    int getDelayDelayCenterNote() {return data[0x26]<<4|data[0x27];}
    int getDelayFeedback() {return (data[0x2A]<<4|data[0x2B])*2-98;}
    int getDelayHFDamp() {return data[0x2E]<<4|data[0x2F];}
    int getDelayLeftLevel() {return data[0x32]<<4|data[0x33];}
    int getDelayRightLevel() {return data[0x36]<<4|data[0x37];}
    int getDelayCenterLevel() {return data[0x3A]<<4|data[0x3B];}

    //GM2 Chorus
    int getGM2ChorusPreLPF() {return data[0x07];}
    int getGM2ChorusLevel() {return data[0x0A]<<4|data[0x0B];}
    int getGM2ChorusFeedback() {return data[0x0E]<<4|data[0x0F];}
    int getGM2ChorusDelay() {return data[0x12]<<4|data[0x13];}
    int getGM2ChorusRate() {return data[0x16]<<4|data[0x17];}
    int getGM2ChorusDepth() {return data[0x0A]<<4|data[0x0B];}

    static QStringList& TypeList() {
        static QStringList list = {"OFF","Chorus","Delay","GM2 Chorus"};
        return list;
    }

    static QStringList& OutputSelectList() {
        static QStringList list = {"MAIN","REV","MAIN+REV"};
        return list;
    }

    static QStringList& FilterTypeList() {
        static QStringList list = {"OFF","HPF","LPF"};
        return list;
    }

    static QStringList& RateTypeList() {
        static QStringList list = {"Hz","Note"};
        return list;
    }

    static QStringList& DelayTypeList() {
        static QStringList list = {"msec","Note"};
        return list;
    }

    static QStringList& FilterFreqList() {
        static QStringList list = {"200","250","315","400","500","630","800","1000","1250","1600",
                                   "2000","2500","3150","4000","5000","6300","8000"};
        return list;
    }

    static QStringList& HFDumpList() {
        static QStringList list = {"200","250","315","400","500","630","800","1000","1250","1600",
                                   "2000","2500","3150","4000","5000","6300","8000","BYPASS"};
        return list;
    }

    static QStringList& NoteList() {
        static QStringList list = {"1/64T","1/64","1/32T","1/32","1/16T","1/32.","1/16","1/8T","1/16.","1/8","1/4T",
                                    "1/8.","1/4","1/2T","1/4.","1/2","1/1T","1/2.","1/1","2/1T","1/1.","2/1"};
        return list;
    }

    static QStringList& PreDelayList() {
        static QStringList list = {"0.0","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9",
                                    "1.0","1.1","1.2","1.3","1.4","1.5","1.6","1.7","1.8","1.9",
                                    "2.0","2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9",
                                    "3.0","3.1","3.2","3.3","3.4","3.5","3.6","3.7","3.8","3.9",
                                    "4.0","4.1","4.2","4.3","4.4","4.5","4.6","4.7","4.8","4.9",
                                    "5.0","5.5","6.0","6.5","7.0","7.5","8.0","8.5","9.0","9.5",
                                    "10","11","12","13","14","15","16","17","18","19",
                                    "20","21","22","23","24","25","26","27","28","29",
                                    "30","31","32","33","34","35","36","37","38","39",
                                    "40","41","42","43","44","45","46","47","48","49",
                                    "50","52","54","56","58","60","62","64","68",
                                    "70","72","74","76","78","80","82","84","88",
                                    "90","92","94","96","98","100"};
        return list;
    }

    static QStringList& RateHzList();

    static QStringList& GM2PreLPFList() {
        static QStringList list = {"0","1","2","3","4","5","6","7"};
        return list;
    }

public slots:
    void setChorusType(int v) { DataSet(0x00,v); }
    void setChorusLevel(int v) { DataSet(0x01,v); }
    void setChorusOutputSelect(int v) { DataSet(0x03,v); }

    //Chorus Section
    void setChorusFilterType(int v) { DataSet4x4B(0x04,v); }
    void setChorusCutoffFreq(int v) { DataSet4x4B(0x08,v); }
    void setChorusPreDelay(int v) { DataSet4x4B(0x0C,v); }
    void setChorusRateType(int v) { DataSet4x4B(0x10,v); }
    void setChorusRateHz(int v) { DataSet4x4B(0x14,v+1); }
    void setChorusRateNote(int v) { DataSet4x4B(0x18,v); }
    void setChorusDepth(int v) { DataSet4x4B(0x1C,v); }
    void setChorusPhase(int v) { DataSet4x4B(0x20,v/2); }
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
    void setDelayFeedback(int v) { DataSet4x4B(0x28,(v+98)/2); }
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
