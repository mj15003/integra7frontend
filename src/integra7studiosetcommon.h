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

#ifndef INTEGRA7STUDIOSETCOMMON_H
#define INTEGRA7STUDIOSETCOMMON_H

#include <QLatin1StringView>
#include <QString>
#include "integra7parameterset.h"

class Integra7StudioSetCommon : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7StudioSetCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);
    uint16_t GetLength() {return 0x54;}
    uint16_t GetItemsNumber() {return 37;}

    QLatin1StringView getStudioSetName();

    uint8_t getVoiceReserve1() {return data[0x18];}
    uint8_t getVoiceReserve2() {return data[0x19];}
    uint8_t getVoiceReserve3() {return data[0x1A];}
    uint8_t getVoiceReserve4() {return data[0x1B];}
    uint8_t getVoiceReserve5() {return data[0x1C];}
    uint8_t getVoiceReserve6() {return data[0x1D];}
    uint8_t getVoiceReserve7() {return data[0x1E];}
    uint8_t getVoiceReserve8() {return data[0x1F];}
    uint8_t getVoiceReserve9() {return data[0x20];}
    uint8_t getVoiceReserve10() {return data[0x21];}
    uint8_t getVoiceReserve11() {return data[0x22];}
    uint8_t getVoiceReserve12() {return data[0x23];}
    uint8_t getVoiceReserve13() {return data[0x24];}
    uint8_t getVoiceReserve14() {return data[0x25];}
    uint8_t getVoiceReserve15() {return data[0x26];}
    uint8_t getVoiceReserve16() {return data[0x27];}
    uint8_t getToneControl1Source() {return data[0x39];}
    uint8_t getToneControl2Source() {return data[0x3A];}
    uint8_t getToneControl3Source() {return data[0x3B];}
    uint8_t getToneControl4Source() {return data[0x3C];}
    uint8_t getStudioSetTempo() {return (data[0x3D]<<4)+data[0x3E];}
    uint8_t getSoloPart() {return data[0x3F];}
    uint8_t getReverbSwitch() {return data[0x40];}
    uint8_t getChorusSwitch() {return data[0x41];}
    uint8_t getMasterEQSwitch() {return data[0x42];}
    uint8_t getDrumCompEQSwitch() {return data[0x43];}
    uint8_t getDrumCompEQPart() {return data[0x44];}
    uint8_t getDrumCompEQ1OutputAssign() {return data[0x45];}
    uint8_t getDrumCompEQ2OutputAssign() {return data[0x46];}
    uint8_t getDrumCompEQ3OutputAssign() {return data[0x47];}
    uint8_t getDrumCompEQ4OutputAssign() {return data[0x48];}
    uint8_t getDrumCompEQ5OutputAssign() {return data[0x49];}
    uint8_t getDrumCompEQ6OutputAssign() {return data[0x4A];}
    uint8_t getExtPartLevel() {return data[0x4C];}
    uint8_t getExtPartChorusSendLevel() {return data[0x4D];}
    uint8_t getExtPartReverbSendLevel() {return data[0x4E];}
    uint8_t getExtPartMuteSwitch() {return data[0x4F];}

public slots:
    void setStudioSetName(const QString name);
    void setVoiceReserve1(int v) { DataSet(0x18,v); }
    void setVoiceReserve2(int v) { DataSet(0x19,v); }
    void setVoiceReserve3(int v) { DataSet(0x1A,v); }
    void setVoiceReserve4(int v) { DataSet(0x1B,v); }
    void setVoiceReserve5(int v) { DataSet(0x1C,v); }
    void setVoiceReserve6(int v) { DataSet(0x1D,v); }
    void setVoiceReserve7(int v) { DataSet(0x1E,v); }
    void setVoiceReserve8(int v) { DataSet(0x1F,v); }
    void setVoiceReserve9(int v) { DataSet(0x20,v); }
    void setVoiceReserve10(int v) { DataSet(0x21,v); }
    void setVoiceReserve11(int v) { DataSet(0x22,v); }
    void setVoiceReserve12(int v) { DataSet(0x23,v); }
    void setVoiceReserve13(int v) { DataSet(0x24,v); }
    void setVoiceReserve14(int v) { DataSet(0x25,v); }
    void setVoiceReserve15(int v) { DataSet(0x26,v); }
    void setVoiceReserve16(int v) { DataSet(0x27,v); }
    void setToneControl1Source(int v) { DataSet(0x39,v); }
    void setToneControl2Source(int v) { DataSet(0x3A,v); }
    void setToneControl3Source(int v) { DataSet(0x3B,v); }
    void setToneControl4Source(int v) { DataSet(0x3C,v); }
    void setStudioSetTempo(int v) { DataSet2x4B(0x3D,v); }
    void setSoloPart(int v) { DataSet(0x3F,v); }
    void setReverbSwitch(int v) { DataSet(0x40,v); }
    void setChorusSwitch(int v) { DataSet(0x41,v); }
    void setMasterEQSwitch(int v) { DataSet(0x42,v); }
    void setDrumCompEQSwitch(int v) { DataSet(0x43,v); }
    void setDrumCompEQPart(int v) { DataSet(0x44,v); }
    void setDrumCompEQ1OutputAssign(int v) { DataSet(0x45,v); }
    void setDrumCompEQ2OutputAssign(int v) { DataSet(0x46,v); }
    void setDrumCompEQ3OutputAssign(int v) { DataSet(0x47,v); }
    void setDrumCompEQ4OutputAssign(int v) { DataSet(0x48,v); }
    void setDrumCompEQ5OutputAssign(int v) { DataSet(0x49,v); }
    void setDrumCompEQ6OutputAssign(int v) { DataSet(0x4A,v); }
    void setExtPartLevel(int v) { DataSet(0x4C,v); }
    void setExtPartChorusSendLevel(int v) { DataSet(0x4D,v); }
    void setExtPartReverbSendLevel(int v) { DataSet(0x4E,v); }
    void setExtPartMuteSwitch(int v) { DataSet(0x4F,v); }

signals:
    void StudioSetName(const QString name);
    void VoiceReserve1(uint8_t v);
    void VoiceReserve2(uint8_t v);
    void VoiceReserve3(uint8_t v);
    void VoiceReserve4(uint8_t v);
    void VoiceReserve5(uint8_t v);
    void VoiceReserve6(uint8_t v);
    void VoiceReserve7(uint8_t v);
    void VoiceReserve8(uint8_t v);
    void VoiceReserve9(uint8_t v);
    void VoiceReserve10(uint8_t v);
    void VoiceReserve11(uint8_t v);
    void VoiceReserve12(uint8_t v);
    void VoiceReserve13(uint8_t v);
    void VoiceReserve14(uint8_t v);
    void VoiceReserve15(uint8_t v);
    void VoiceReserve16(uint8_t v);
    void ToneControl1Source(uint8_t v);
    void ToneControl2Source(uint8_t v);
    void ToneControl3Source(uint8_t v);
    void ToneControl4Source(uint8_t v);
    void StudioSetTempo(uint8_t v);
    void SoloPart(uint8_t v);
    void ReverbSwitch(uint8_t v);
    void ChorusSwitch(uint8_t v);
    void MasterEQSwitch(uint8_t v);
    void DrumCompEQSwitch(uint8_t v);
    void DrumCompEQPart(uint8_t v);
    void DrumCompEQ1OutputAssign(uint8_t v);
    void DrumCompEQ2OutputAssign(uint8_t v);
    void DrumCompEQ3OutputAssign(uint8_t v);
    void DrumCompEQ4OutputAssign(uint8_t v);
    void DrumCompEQ5OutputAssign(uint8_t v);
    void DrumCompEQ6OutputAssign(uint8_t v);
    void ExtPartLevel(uint8_t v);
    void ExtPartChorusSendLevel(uint8_t v);
    void ExtPartReverbSendLevel(uint8_t v);
    void ExtPartMuteSwitch(uint8_t v);

private:
    void EmitSignal(uint8_t a, int v);    
};

#endif // INTEGRA7STUDIOSETCOMMON_H
