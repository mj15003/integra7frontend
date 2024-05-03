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

#ifndef INTEGRA7SYSTEMCOMMON_H
#define INTEGRA7SYSTEMCOMMON_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7SystemCommon : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7SystemCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);
    int GetLength() {return 0x2F;}
    int GetItemsNumber() {return 19;}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int getMasterTune() {return data[0x1]<<8|data[0x2]<<4|data[0x3];}
    double getMasterTuneCents() {return Tune2Cents(getMasterTune());}
    double getMasterTuneHz() {return Cents2Hz(getMasterTuneCents());}
    int getMasterKeyShift() {return data[0x04]-64;}
    int getMasterLevel() {return data[0x05];}
    int getScaleTuneSwitch() {return data[0x06];}
    int getStudioSetControlChannel() {return data[0x11];}
    int getSystemControl1Source() {return data[0x20];}
    int getSystemControl2Source() {return data[0x21];}
    int getSystemControl3Source() {return data[0x22];}
    int getSystemControl4Source() {return data[0x23];}
    int getControlSource() {return data[0x24];}
    int getSystemClockSource() {return data[0x25];}
    int getSystemTempo() {return data[0x26]<<4|data[0x27];}
    int getTempoAssignSource() {return data[0x28];}
    int getReceiveProgramChange() {return data[0x29];}
    int getReceiveBankSelect() {return data[0x2A];}
    int get51CHCenterSpeakerSwitch() {return data[0x2B];}
    int get51CHSubWooferSwitch() {return data[0x2C];}
    int get2CHOutputMode() {return data[0x2D];}

    static QStringList& MIDIChListOff() {
        static QStringList list = { "1","2","3","4","5","6","7","8",
                                   "9","10","11","12","13","14","15","16","OFF" };
        return list;
    }

    static QStringList& SystemStudioSetList() {
        static QStringList list = { "SYSTEM","STUDIO SET" };
        return list;
    }

    static QStringList& SystemClockSourceList() {
        static QStringList list = { "MIDI","USB" };
        return list;
    }

    static QStringList& SpeakerPhonesList() {
        static QStringList list = { "SPEAKER","PHONES" };
        return list;
    }

public slots:
    void setMasterTune(int v) { DataSet4x4B(0x0,v); }
    void setMasterTuneCents(double v) { DataSet4x4B(0x0,Cents2Tune(v)); }
    void setMasterKeyShift(int v) { DataSetOffset(0x04,v,64); }
    void setMasterLevel(int v) { DataSet(0x05,v); }
    void setScaleTuneSwitch(int v) { DataSet(0x06,v); }
    void setStudioSetControlChannel(int v) { DataSet(0x11,v); }
    void setSystemControl1Source(int v) { v<32?DataSet(0x20,v):DataSet(0x20,v+1); }
    void setSystemControl2Source(int v) { v<32?DataSet(0x21,v):DataSet(0x21,v+1); }
    void setSystemControl3Source(int v) { v<32?DataSet(0x22,v):DataSet(0x22,v+1); }
    void setSystemControl4Source(int v) { v<32?DataSet(0x23,v):DataSet(0x23,v+1); }
    void setControlSource(int v) { DataSet(0x24,v); }
    void setSystemClockSource(int v) { DataSet(0x25,v); }
    void setSystemTempo(int v) { DataSet2x4B(0x26,v); }
    void setTempoAssignSource(int v) { DataSet(0x28,v); }
    void setReceiveProgramChange(int v) { DataSet(0x29,v); }
    void setReceiveBankSelect(int v) { DataSet(0x2A,v); }
    void set51CHCenterSpeakerSwitch(int v) { DataSet(0x2B,v); }
    void set51CHSubWooferSwitch(int v) { DataSet(0x2C,v); }
    void set2CHOutputMode(int v) { DataSet(0x2D,v); }

signals:
    void MasterTune(int v);
    void MasterTuneCents(double v);
    void MasterTuneHz(double v);
    void MasterKeyShift(int v);
    void MasterLevel(int v);
    void ScaleTuneSwitch(int v);
    void StudioSetControlChannel(int v);
    void SystemControl1Source(int v);
    void SystemControl2Source(int v);
    void SystemControl3Source(int v);
    void SystemControl4Source(int v);
    void ControlSource(int v);
    void SystemClockSource(int v);
    void SystemTempo(int v);
    void TempoAssignSource(int v);
    void ReceiveProgramChange(int v);
    void ReceiveBankSelect(int v);
    void sig51CHCenterSpeakerSwitch(int v);
    void sig51CHSubWooferSwitch(int v);
    void sig2CHOutputMode(int v);

private:
    void EmitSignal(uint8_t a, int v);
    double Tune2Cents(int v) { return (v-1024)/10.0;}
    double Cents2Hz(double c) { return 440*pow(2,c/1200);}    
    int Cents2Tune(double c) { return round(c*10+1024);}
};

#endif // INTEGRA7SYSTEMCOMMON_H
