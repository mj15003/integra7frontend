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
    uint16_t GetLength() {return 0x2F;}
    uint16_t GetItemsNumber() {return 19;}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    uint8_t getMasterTune() {return data[0x0];}
    uint8_t getMasterKeyShift() {return data[0x04];}
    uint8_t getMasterLevel() {return data[0x05];}
    uint8_t getScaleTuneSwitch() {return data[0x06];}
    uint8_t getStudioSetControlChannel() {return data[0x11];}
    uint8_t getSystemControl1Source() {return data[0x20];}
    uint8_t getSystemControl2Source() {return data[0x21];}
    uint8_t getSystemControl3Source() {return data[0x22];}
    uint8_t getSystemControl4Source() {return data[0x23];}
    uint8_t getControlSource() {return data[0x24];}
    uint8_t getSystemClockSource() {return data[0x25];}
    uint8_t getSystemTempo() {return data[0x26];}
    uint8_t getTempoAssignSource() {return data[0x28];}
    uint8_t getReceiveProgramChange() {return data[0x29];}
    uint8_t getReceiveBankSelect() {return data[0x2A];}
    uint8_t get51CHCenterSpeakerSwitch() {return data[0x2B];}
    uint8_t get51CHSubWooferSwitch() {return data[0x2C];}
    uint8_t get2CHOutputMode() {return data[0x2D];}

public slots:
    void setMasterTune(int v) { DataSet(0x0,v); }
    void setMasterKeyShift(int v) { DataSet(0x04,v); }
    void setMasterLevel(int v) { DataSet(0x05,v); }
    void setScaleTuneSwitch(int v) { DataSet(0x06,v); }
    void setStudioSetControlChannel(int v) { DataSet(0x11,v); }
    void setSystemControl1Source(int v) { DataSet(0x20,v); }
    void setSystemControl2Source(int v) { DataSet(0x21,v); }
    void setSystemControl3Source(int v) { DataSet(0x22,v); }
    void setSystemControl4Source(int v) { DataSet(0x23,v); }
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
    void MasterTune(uint8_t v);
    void MasterKeyShift(uint8_t v);
    void MasterLevel(uint8_t v);
    void ScaleTuneSwitch(uint8_t v);
    void StudioSetControlChannel(uint8_t v);
    void SystemControl1Source(uint8_t v);
    void SystemControl2Source(uint8_t v);
    void SystemControl3Source(uint8_t v);
    void SystemControl4Source(uint8_t v);
    void ControlSource(uint8_t v);
    void SystemClockSource(uint8_t v);
    void SystemTempo(uint8_t v);
    void TempoAssignSource(uint8_t v);
    void ReceiveProgramChange(uint8_t v);
    void ReceiveBankSelect(uint8_t v);
    void sig51CHCenterSpeakerSwitch(uint8_t v);
    void sig51CHSubWooferSwitch(uint8_t v);
    void sig2CHOutputMode(uint8_t v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7SYSTEMCOMMON_H
