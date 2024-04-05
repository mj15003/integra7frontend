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
    int GetLength() {return 0x54;}
    int GetItemsNumber() {return 37;}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    QLatin1StringView getStudioSetName();

    int getVoiceReserve1() {return data[0x18];}
    int getVoiceReserve2() {return data[0x19];}
    int getVoiceReserve3() {return data[0x1A];}
    int getVoiceReserve4() {return data[0x1B];}
    int getVoiceReserve5() {return data[0x1C];}
    int getVoiceReserve6() {return data[0x1D];}
    int getVoiceReserve7() {return data[0x1E];}
    int getVoiceReserve8() {return data[0x1F];}
    int getVoiceReserve9() {return data[0x20];}
    int getVoiceReserve10() {return data[0x21];}
    int getVoiceReserve11() {return data[0x22];}
    int getVoiceReserve12() {return data[0x23];}
    int getVoiceReserve13() {return data[0x24];}
    int getVoiceReserve14() {return data[0x25];}
    int getVoiceReserve15() {return data[0x26];}
    int getVoiceReserve16() {return data[0x27];}
    int getToneControl1Source() {return data[0x39];}
    int getToneControl2Source() {return data[0x3A];}
    int getToneControl3Source() {return data[0x3B];}
    int getToneControl4Source() {return data[0x3C];}
    int getStudioSetTempo() {return data[0x3D]<<4|data[0x3E];}
    int getSoloPart() {return data[0x3F];}
    int getReverbSwitch() {return data[0x40];}
    int getChorusSwitch() {return data[0x41];}
    int getMasterEQSwitch() {return data[0x42];}
    int getDrumCompEQSwitch() {return data[0x43];}
    int getDrumCompEQPart() {return data[0x44];}
    int getDrumCompEQ1OutputAssign() {return data[0x45];}
    int getDrumCompEQ2OutputAssign() {return data[0x46];}
    int getDrumCompEQ3OutputAssign() {return data[0x47];}
    int getDrumCompEQ4OutputAssign() {return data[0x48];}
    int getDrumCompEQ5OutputAssign() {return data[0x49];}
    int getDrumCompEQ6OutputAssign() {return data[0x4A];}
    int getExtPartLevel() {return data[0x4C];}
    int getExtPartChorusSendLevel() {return data[0x4D];}
    int getExtPartReverbSendLevel() {return data[0x4E];}
    int getExtPartMuteSwitch() {return data[0x4F];}

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
    void VoiceReserve1(int v);
    void VoiceReserve2(int v);
    void VoiceReserve3(int v);
    void VoiceReserve4(int v);
    void VoiceReserve5(int v);
    void VoiceReserve6(int v);
    void VoiceReserve7(int v);
    void VoiceReserve8(int v);
    void VoiceReserve9(int v);
    void VoiceReserve10(int v);
    void VoiceReserve11(int v);
    void VoiceReserve12(int v);
    void VoiceReserve13(int v);
    void VoiceReserve14(int v);
    void VoiceReserve15(int v);
    void VoiceReserve16(int v);
    void ToneControl1Source(int v);
    void ToneControl2Source(int v);
    void ToneControl3Source(int v);
    void ToneControl4Source(int v);
    void StudioSetTempo(int v);
    void SoloPart(int v);
    void ReverbSwitch(int v);
    void ChorusSwitch(int v);
    void MasterEQSwitch(int v);
    void DrumCompEQSwitch(int v);
    void DrumCompEQPart(int v);
    void DrumCompEQ1OutputAssign(int v);
    void DrumCompEQ2OutputAssign(int v);
    void DrumCompEQ3OutputAssign(int v);
    void DrumCompEQ4OutputAssign(int v);
    void DrumCompEQ5OutputAssign(int v);
    void DrumCompEQ6OutputAssign(int v);
    void ExtPartLevel(int v);
    void ExtPartChorusSendLevel(int v);
    void ExtPartReverbSendLevel(int v);
    void ExtPartMuteSwitch(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7STUDIOSETCOMMON_H
