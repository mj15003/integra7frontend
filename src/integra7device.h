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

#ifndef INTEGRA7DEVICE_H
#define INTEGRA7DEVICE_H

#include "midiengine.h"

#include <QObject>
#include <QStringList>

/* Forward Declarations */
class Integra7Setup;
class integra7MainWindow;
class Integra7Part;
class Integra7StudioSetCommon;
class Integra7SystemCommon;
class Integra7MasterEQ;
class Integra7PartEQ;
class Integra7Chorus;
class Integra7Reverb;

class Integra7Device : public QObject
{
    Q_OBJECT
public:
    explicit Integra7Device(integra7MainWindow *parent, MidiEngine *midi);
    ~Integra7Device();

    void DataSet(const uint8_t *data,int len);
    void DataRequest(const uint8_t *data);
    void SendIdentityRequest();
    void DisplayStatsMsg();

    integra7MainWindow *uiWin;

    Integra7Setup *Setup;

    Integra7SystemCommon *SystemCommon;

    Integra7StudioSetCommon *StudioSetCommon;

    Integra7MasterEQ *MasterEQ;

    Integra7Chorus *Chorus;

    Integra7Reverb *Reverb;

    Integra7Part *Parts[16];
    Integra7PartEQ *PartsEQ[16];

    static QStringList& DeviceIdList() {
        static QStringList list = {"17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32"};
        return list;
    }

    static QStringList& TypeLabels() {
        static QStringList list = {"SN-A","SN-S","SN-D","PCM-S","PCM-D","ExPCM","ExPCM-Drums","GM2-Tone","GM2-Drums","GS"};
        return list;
    }

    static QStringList& PresetBank() {
        static QStringList list = {"PRESET"};
        return list;
    }

    static QStringList& SNAcousticBanks() {
        static QStringList list = {"PRESET","USER",
                                   "ExSN1:Ethnic","ExSN2:WoodWinds","ExSN3:Session","ExSN4:A.Guitar","ExSN5:Brass"};
        return list;
    }

    static QStringList& SNSynthBanks() {
        static QStringList list = {"PRESET","USER"};
        return list;
    }

    static QStringList& SNDrumBanks() {
        static QStringList list = {"PRESET","USER","ExSN6:SFX"};
        return list;
    }

    static QStringList& PCMSynthBanks() {
        static QStringList list = {"PRESET","USER",
                                   "SRX-01:Dynamic Drum Kits","SRX-02:Concert Piano","SRX-03:Studio SRX",
                                   "SRX-04:Symphonique Strings","SRX-05:Supreme Dance","SRX-06:Complete Orchestra",
                                   "SRX-07:Ultimate Keys","SRX-08:Platinum Trax","SRX-09:World Collection",
                                   "SRX-10:Big Brass Ensemble","SRX-11:Complete Piano","SRX-12:Classic EPs"};
        return list;
    }

    static QStringList& PCMDrumBanks() {
        static QStringList list = {"PRESET","USER","SRX-01:Dynamic Drum Kits","SRX-03:Studio SRX",
                                   "SRX-05:Supreme Dance","SRX-06:Complete Orchestra",
                                   "SRX-07:Ultimate Keys","SRX-08:Platinum Trax","SRX-09:World Collection"};
        return list;
    }

    static QStringList& GM2Banks() {
        static QStringList list = {"Base","Var #1","Var #2","Var #3","Var #4","Var #5","Var #6","Var #7","Var #8","Var #9"};
        return list;
    }

    static int getBankIndex(QString& type, QString& bank);
    static int getBankName(QString& type, QString& bank, int index);

    static QStringList& CategoryNames() {
        static QStringList list = {"Ac.Piano","E.Piano","Organ","E.Guitar","Dist.Guitar","Ac.Bass","E.Bass","Ac.Guitar",
                "Accordeon/Harmonica","Bell/Mallet","Percussion","Plucked/Stroke","Strings","Vox/Choir",
                "Brass","Sax","Wind","Flute","Synth Pad/Strings","Pulsating","Synth Brass","Synth Polykey",
                "Synth BellPad","Synth Seq/Pop","Synth Bass","Synth Lead","FX","Drum","Hit","Other Keyboards"
        };
        return list;
    }

    static QStringList& ExpansionNames() {
        static QStringList list = {"",
                "SRX-01:Dynamic Drum Kits","SRX-02:Concert Piano","SRX-03:Studio SRX",
                "SRX-04:Symphonique Strings","SRX-05:Supreme Dance","SRX-06:Complete Orchestra",
                "SRX-07:Ultimate Keys","SRX-08:Platinum Trax","SRX-09:World Collection",
                "SRX-10:Big Brass Ensemble","SRX-11:Complete Piano","SRX-12:Classic EPs",
                "ExSN1:Ethnic","ExSN2:WoodWinds","ExSN3:Session","ExSN4:A.Guitar","ExSN5:Brass","ExSN6:SFX",
                "ExPCM:HQ GM2 + HQ PCM Sound Collection"
        };
        return list;
    }

    static QStringList& SNAcousticPresets() {
        static QStringList list = {
            #include "presets/SNAcoustic.inc"
        };
        return list;
    }

    static QStringList& SNDrumPresets() {
        static QStringList list = {
            #include "presets/SNDrums.inc"
        };
        return list;
    }

    static QStringList& ExSN1Presets() {
        static QStringList list = {
            #include "presets/ExSN1.inc"
        };
        return list;
    }

    static QStringList& ExSN2Presets() {
        static QStringList list = {
            #include "presets/ExSN2.inc"
        };
        return list;
    }

    static QStringList& ExSN3Presets() {
        static QStringList list = {
            #include "presets/ExSN3.inc"
        };
        return list;
    }

    static QStringList& ExSN4Presets() {
        static QStringList list = {
            #include "presets/ExSN4.inc"
        };
        return list;
    }

    static QStringList& ExSN5Presets() {
        static QStringList list = {
            #include "presets/ExSN5.inc"
        };
        return list;
    }

    static QStringList& ExSN6Presets() {
        static QStringList list = {"1:SFX 1","2:SFX 2","3:SFX 1 Mono","4:SFX 2 Mono",
                                   "5:SFX Menu 1","6:SFX Menu 2","7:SFX Menu 3"};
        return list;
    }

    static QStringList& SNSynthPresets() {
        static QStringList list = {
            #include "presets/SNSynth.inc"
        };
        return list;
    }

    static QStringList& PCMSynthPresets() {
        static QStringList list = {
            #include "presets/PCMSynth.inc"
        };
        return list;
    }

    static QStringList& PCMDrumPresets() {
        static QStringList list = {
            #include "presets/PCMDrum.inc"
        };
        return list;
    }

    static QStringList& SRX01Presets() {
        static QStringList list = {
            #include "presets/SRX-01.inc"
        };
        return list;
    }

    static QStringList& SRX01DrumPresets() {
        static QStringList list = {
            #include "presets/SRX-01Drum.inc"
        };
        return list;
    }

    static QStringList& SRX02Presets() {
        static QStringList list = {
            #include "presets/SRX-02.inc"
        };
        return list;
    }

    static QStringList& SRX03Presets() {
        static QStringList list = {
            #include "presets/SRX-03.inc"
        };
        return list;
    }

    static QStringList& SRX03DrumPresets() {
        static QStringList list = {
            #include "presets/SRX-03Drum.inc"
        };
        return list;
    }

    static QStringList& SRX04Presets() {
        static QStringList list = {
            #include "presets/SRX-04.inc"
        };
        return list;
    }

    static QStringList& SRX05Presets() {
        static QStringList list = {
            #include "presets/SRX-05.inc"
        };
        return list;
    }

    static QStringList& SRX05DrumPresets() {
        static QStringList list = {
            #include "presets/SRX-05Drum.inc"
        };
        return list;
    }

    static QStringList& SRX06Presets() {
        static QStringList list = {
            #include "presets/SRX-06.inc"
        };
        return list;
    }

    static QStringList& SRX06DrumPresets() {
        static QStringList list = {
            #include "presets/SRX-06Drum.inc"
        };
        return list;
    }

    static QStringList& SRX07Presets() {
        static QStringList list = {
            #include "presets/SRX-07.inc"
        };
        return list;
    }

    static QStringList& SRX07DrumPresets() {
        static QStringList list = {
            #include "presets/SRX-07Drums.inc"
        };
        return list;
    }

    static QStringList& SRX08Presets() {
        static QStringList list = {
            #include "presets/SRX-08.inc"
        };
        return list;
    }

    static QStringList& SRX08DrumPresets() {
        static QStringList list = {
            #include "presets/SRX-08Drums.inc"
        };
        return list;
    }

    static QStringList& SRX09Presets() {
        static QStringList list = {
            #include "presets/SRX-09.inc"
        };
        return list;
    }

    static QStringList& SRX09DrumPresets() {
        static QStringList list = {
            #include "presets/SRX-09Drums.inc"
        };
        return list;
    }

    static QStringList& SRX10Presets() {
        static QStringList list = {
            #include "presets/SRX-10.inc"
        };
        return list;
    }

    static QStringList& SRX11Presets() {
        static QStringList list = {
            #include "presets/SRX-11.inc"
        };
        return list;
    }

    static QStringList& SRX12Presets() {
        static QStringList list = {
            #include "presets/SRX-12.inc"
        };
        return list;
    }

    static QStringList& ExPCMPresets() {
        static QStringList list = {
            #include "presets/ExPCM.inc"
        };
        return list;
    }

    static QStringList& ExPCMDrumPresets() {
        static QStringList list = {
            #include "presets/ExPCMDrums.inc"
        };
        return list;
    }

    static QStringList& GM2Presets() {
        static QStringList list = {
            #include "presets/GM2.inc"
        };
        return list;
    }

    static QStringList& GM2Presets1() {
        static QStringList list = {
            #include "presets/GM2_1.inc"
        };
        return list;
    }

    static QStringList& GM2Presets2() {
        static QStringList list = {
            #include "presets/GM2_2.inc"
        };
        return list;
    }

    static QStringList& GM2Presets3() {
        static QStringList list = {
            #include "presets/GM2_3.inc"
        };
        return list;
    }

    static QStringList& GM2Presets4() {
        static QStringList list = {
            #include "presets/GM2_4.inc"
        };
        return list;
    }

    static QStringList& GM2Presets5() {
        static QStringList list = {"Bubble","Wind Chimes","Siren","Footsteps"};
        return list;
    }

    static QStringList& GM2Presets6() {
        static QStringList list = {"Train"};
        return list;
    }

    static QStringList& GM2Presets7() {
        static QStringList list = {"Jetplane"};
        return list;
    }

    static QStringList& GM2Presets8() {
        static QStringList list = {"Starship"};
        return list;
    }

    static QStringList& GM2Presets9() {
        static QStringList list = {"Burst Noise"};
        return list;
    }

    static QStringList& GM2DrumPresets() {
        static QStringList list = {
            #include "presets/GM2Drums.inc"
        };
        return list;
    }

    static QStringList& EQLowFreqList() {
        static QStringList list = { "200","400" };
        return list;
    }

    static QStringList& EQMidFreqList() {
        static QStringList list = { "200","250","315","400","500","630","800","1000","1250","1600",
                                    "2000","2500","3150","4000","5000","6300","8000" };
        return list;
    }

    static QStringList& EQMidQList() {
        static QStringList list = { "0.5","1.0","2.0","4.0","8.0" };
        return list;
    }

    static QStringList& EQHighFreqList() {
        static QStringList list = { "2000","4000","8000" };
        return list;
    }

    static QStringList& OutputList() {
        static QStringList list = { "A","B","C","D","1","2","3","4","5","6","7","8" };
        return list;
    }

    static QStringList& OutputAssignList() {
        static QStringList list = { "A","B","C","D" };
        return list;
    }

    static QStringList& MIDIChList() {
        static QStringList list = { "1","2","3","4","5","6","7","8",
                                   "9","10","11","12","13","14","15","16" };
        return list;
    }

    static QStringList& MonoPolyList() {
        static QStringList list = { "MONO","POLY","TONE"};
        return list;
    }

    static QStringList& LegatoSwitchList() {
        static QStringList list = { "OFF","ON","TONE"};
        return list;
    }

    static QStringList& UserPresets(int n);

    void LoadVirtualSlots(uint8_t s1,uint8_t s2,uint8_t s3,uint8_t s4);

    static QStringList& GetBankList(QString type);
    static QStringList& GetToneList(QString type, QString bank);

public slots:
    void BulkDumpRequest();
    void setDeviceId(uint8_t Id);
    void SetPreview(uint8_t state);
    void ReceiveIntegraSysEx(const uint8_t *data, int len);

private:
    uint8_t cDeviceId = 0x10;
    uint8_t OutputData[BUFFER_SIZE];
    uint8_t VirtualSlots[8] = {0x0F, 0x00, 0x30, 0x00, 0, 0, 0, 0};

    size_t ReceivedSysExCounter = 0;
    size_t SentSysExCounter = 0;

    size_t ReceivedBytesCounter = 0;
    size_t SentBytesCounter = 0;

    MidiEngine *pMidiEngine;

    uint8_t Checksum(const uint8_t *msg);
    void SendIntegraSysEx(const uint8_t *data, int len);    
};

#endif // INTEGRA7DEVICE_H
