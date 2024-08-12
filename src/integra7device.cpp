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

#include "integra7setup.h"
#include "integra7systemcommon.h"
#include "integra7part.h"
#include "integra7parteq.h"
#include "integra7mastereq.h"
#include "integra7studiosetcommon.h"
#include "integra7chorus.h"
#include "integra7reverb.h"
#include "integra7mainwindow.h"
#include "integra7tone.h"
#include "integra7device.h"

#include <QStringBuilder>
#include <QFile>

Integra7Device::Integra7Device(integra7MainWindow *parent, MidiEngine *midi)
    : QObject{parent}
{
    /* SysEx fixed data initialization */
    OutputData[0] = 0xF0;//SysEx Header
    OutputData[1] = 0x41;//Roland Manufacturer Id
    OutputData[2] = cDeviceId;
    OutputData[3] = 0x0;//INTEGRA7 Model ID number
    OutputData[4] = 0x0;//INTEGRA7 Model ID number
    OutputData[5] = 0x64;//INTEGRA7 Model ID number
    OutputData[BUFFER_SIZE-1] = 0xF7;//correctly ended SysEx

    uiWin = parent;
    pMidiEngine = midi;

    Setup = new Integra7Setup(this,0x1,0x0,0x0);
    SystemCommon = new Integra7SystemCommon(this,0x2,0,0);
    StudioSetCommon = new Integra7StudioSetCommon(this,0x18,0,0);
    MasterEQ = new Integra7MasterEQ(this,0x18,0,0x9);
    Chorus = new Integra7Chorus(this,0x18,0,0x4);
    Reverb = new Integra7Reverb(this,0x18,0,0x6);

    uint8_t offset = 0x20;
    uint8_t offset2 = 0x50;
    for (int i=0;i<16;i++){
        Parts[i] = new Integra7Part(this,0x18,0x00,offset++);
        PartsEQ[i] = new Integra7PartEQ(this,0x18,0x00,offset2++);
    }

    offset = 0x19;
    offset2 = 0x0;
    for (int i=0;i<16;i++){
        Tones[i] = new Integra7Tone(this,offset,offset2);
        if (offset2 < 0x60) offset2 += 0x20;
        else {
            ++offset;
            offset2 = 0x0;
        }
    }
}

Integra7Device::~Integra7Device()
{
    for (int i=0;i<16;i++) {
        delete Parts[i];
        delete PartsEQ[i];
        delete Tones[i];
    }

    delete Reverb;
    delete Chorus;
    delete MasterEQ;
    delete StudioSetCommon;
    delete SystemCommon;
    delete Setup;
}

int Integra7Device::BulkDumpWriteFile(const QString &fileName)
{
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);

    uint8_t buffer[PARAMETER_ARRAY_SIZE];
    int len;

    len = Setup->OutputDump(buffer);
    file.write((char*)OutputData,FillOutputDataFrame(buffer,len));

    len = SystemCommon->OutputDump(buffer);
    file.write((char*)OutputData,FillOutputDataFrame(buffer,len));

    len = StudioSetCommon->OutputDump(buffer);
    file.write((char*)OutputData,FillOutputDataFrame(buffer,len));

    len = Chorus->OutputDump(buffer);
    file.write((char*)OutputData,FillOutputDataFrame(buffer,len));

    len = Reverb->OutputDump(buffer);
    file.write((char*)OutputData,FillOutputDataFrame(buffer,len));

    len = MasterEQ->OutputDump(buffer);
    file.write((char*)OutputData,FillOutputDataFrame(buffer,len));


    for (int i=0;i<16;i++) {
        len = Parts[i]->OutputDump(buffer);
        file.write((char*)OutputData,FillOutputDataFrame(buffer,len));
    }

    for (int i=0;i<16;i++) {
        len = PartsEQ[i]->OutputDump(buffer);
        file.write((char*)OutputData,FillOutputDataFrame(buffer,len));
    }

    for (int i=0;i<16;i++) {
        while (Tones[i]->OutputDump(buffer,&len)) {
            file.write((char*)OutputData,FillOutputDataFrame(buffer,len));
        }
    }

    file.close();

    return file.size();
}

void Integra7Device::setDeviceId(uint8_t Id)
{
    if (Id >= 0 && Id <= 16) {
        cDeviceId = Id + 0x10;
        OutputData[2] = cDeviceId;
    }
}

void Integra7Device::DataSet(const uint8_t *data, int len)
{
    OutputData[6] = 0x12;//INTEGRA7 DataSet Command
    SendIntegraSysEx(FillOutputDataFrame(data,len));
}

void Integra7Device::DataRequest(const uint8_t *data)
{
    /* data array must have exactly 8 bytes -> 4 bytes address,4bytes length */
    OutputData[6] = 0x11;//INTEGRA7 DataRequest Command
    SendIntegraSysEx(FillOutputDataFrame(data,8));
}

void Integra7Device::SendIdentityRequest()
{
    uint8_t msg[] = {0xF0,0x7E,cDeviceId,0x06,0x01,0xF7};
    pMidiEngine->SendSysEx(msg,6);
}

void Integra7Device::DisplayStatsMsg()
{
    QString msg = QString("Received SysEx number : %1 | Sent SysEx number : %2 | Received bytes : %3 | Sent bytes : %4")
                      .arg(ReceivedSysExCounter).arg(SentSysExCounter)
                      .arg(ReceivedBytesCounter).arg(SentBytesCounter);
    uiWin->ShowStatusMsg(msg);
}

int Integra7Device::getBankIndex(QString& type,QString& bank)
{
    if (type == "SN-A") {

        if (bank == "PRESET")
            return 11456;
        else if (bank == "USER")
            return 11392;
        else if (bank == "ExSN1:Ethnic")
            return 11488;
        else if (bank == "ExSN2:WoodWinds")
            return 11489;
        else if (bank == "ExSN3:Session")
            return 11490;
        else if (bank == "ExSN4:A.Guitar")
            return 11491;
        else if (bank == "ExSN5:Brass")
            return 11492;

    } else if (type == "SN-S") {

        if (bank == "PRESET")
            return 12224;
        else if (bank == "USER")
            return 12160;

    } else if (type == "SN-D") {

        if (bank == "PRESET")
            return 11328;
        else if (bank == "USER")
            return 11264;
        else if (bank == "ExSN6:SFX")
            return 11365;

    } else if (type == "PCM-S") {

        if (bank == "PRESET")
            return 11200;
        else if (bank == "USER")
            return 11136;
        else if (bank == "SRX-01:Dynamic Drum Kits")
            return 11904;
        else if (bank == "SRX-02:Concert Piano")
            return 11905;
        else if (bank == "SRX-03:Studio SRX")
            return 11906;
        else if (bank == "SRX-04:Symphonique Strings")
            return 11907;
        else if (bank == "SRX-05:Supreme Dance")
            return 11908;
        else if (bank == "SRX-06:Complete Orchestra")
            return 11911;
        else if (bank == "SRX-07:Ultimate Keys")
            return 11915;
        else if (bank == "SRX-08:Platinum Trax")
            return 11919;
        else if (bank == "SRX-09:World Collection")
            return 11923;
        else if (bank == "SRX-10:Big Brass Ensemble")
            return 11927;
        else if (bank == "SRX-11:Complete Piano")
            return 11928;
        else if (bank == "SRX-12:Classic EPs")
            return 11930;

    } else if (type == "PCM-D") {

        if (bank == "PRESET")
            return 11072;
        else if (bank == "USER")
            return 11008;
        else if (bank == "SRX-01:Dynamic Drum Kits")
            return 11776;
        else if (bank == "SRX-03:Studio SRX")
            return 11778;
        else if (bank == "SRX-05:Supreme Dance")
            return 11780;
        else if (bank == "SRX-06:Complete Orchestra")
            return 11783;
        else if (bank == "SRX-07:Ultimate Keys")
            return 11787;
        else if (bank == "SRX-08:Platinum Trax")
            return 11791;
        else if (bank == "SRX-09:World Collection")
            return 11795;

    } else if (type == "ExPCM")
        return 12416;

    else if (type == "ExPCM-Drums")
        return 12288;

    else if (type == "GM2-Tone") {

        if (bank == "Base")
            return 15488;
        else if (bank == "Var #1")
            return 15489;
        else if (bank == "Var #2")
            return 15490;
        else if (bank == "Var #3")
            return 15491;
        else if (bank == "Var #4")
            return 15492;
        else if (bank == "Var #5")
            return 15493;
        else if (bank == "Var #6")
            return 15494;
        else if (bank == "Var #7")
            return 15495;
        else if (bank == "Var #8")
            return 15496;
        else if (bank == "Var #9")
            return 15497;
    } else if (type == "GM2-Drums")
        return 15360;

    return -1;
}

int Integra7Device::getBankName(QString &type, QString &bank, int index)
{
    switch (index) {
    case 11008:
        type = "PCM-D";
        bank = "USER";
        return 0;
    case 11072:
        type = "PCM-D";
        bank = "PRESET";
        return 0;
    case 11136:
        type = "PCM-S";
        bank = "USER";
        return 0;
    case 11137:
        type = "PCM-S";
        bank = "USER";
        return 0;
    case 11200:
        type = "PCM-S";
        bank = "PRESET";
        return 0;
    case 11201:
        type = "PCM-S";
        bank = "PRESET";
        return 0;
    case 11202:
        type = "PCM-S";
        bank = "PRESET";
        return 0;
    case 11203:
        type = "PCM-S";
        bank = "PRESET";
        return 0;
    case 11204:
        type = "PCM-S";
        bank = "PRESET";
        return 0;
    case 11205:
        type = "PCM-S";
        bank = "PRESET";
        return 0;
    case 11206:
        type = "PCM-S";
        bank = "PRESET";
        return 0;
    case 11264:
        type = "SN-D";
        bank = "USER";
        return 0;
    case 11328:
        type = "SN-D";
        bank = "PRESET";
        return 0;
    case 11365:
        type = "SN-D";
        bank = "ExSN6:SFX";
        return 0;
    case 11392:
        type = "SN-A";
        bank = "USER";
        return 0;
    case 11393:
        type = "SN-A";
        bank = "USER";
        return 0;
    case 11456:
        type = "SN-A";
        bank = "PRESET";
        return 0;
    case 11457:
        type = "SN-A";
        bank = "PRESET";
        return 0;
    case 11488:
        type = "SN-A";
        bank = "ExSN1:Ethnic";
        return 0;
    case 11489:
        type = "SN-A";
        bank = "ExSN2:WoodWinds";
        return 0;
    case 11490:
        type = "SN-A";
        bank = "ExSN3:Session";
        return 0;
    case 11491:
        type = "SN-A";
        bank = "ExSN4:A.Guitar";
        return 0;
    case 11492:
        type = "SN-A";
        bank = "ExSN5:Brass";
        return 0;
    case 11776:
        type = "PCM-D";
        bank = "SRX-01:Dynamic Drum Kits";
        return 0;
    case 11778:
        type = "PCM-D";
        bank = "SRX-03:Studio SRX";
        return 0;
    case 11780:
        type = "PCM-D";
        bank = "SRX-05:Supreme Dance";
        return 0;
    case 11783:
        type = "PCM-D";
        bank = "SRX-06:Complete Orchestra";
        return 0;
    case 11787:
        type = "PCM-D";
        bank = "SRX-07:Ultimate Keys";
        return 0;
    case 11791:
        type = "PCM-D";
        bank = "SRX-08:Platinum Trax";
        return 0;
    case 11795:
        type = "PCM-D";
        bank = "SRX-09:World Collection";
        return 0;
    case 11904:
        type = "PCM-S";
        bank = "SRX-01:Dynamic Drum Kits";
        return 0;
    case 11905:
        type = "PCM-S";
        bank = "SRX-02:Concert Piano";
        return 0;
    case 11906:
        type = "PCM-S";
        bank = "SRX-03:Studio SRX";
        return 0;
    case 11907:
        type = "PCM-S";
        bank = "SRX-04:Symphonique Strings";
        return 0;
    case 11908:
        type = "PCM-S";
        bank = "SRX-05:Supreme Dance";
        return 0;
    case 11909:
        type = "PCM-S";
        bank = "SRX-05:Supreme Dance";
        return 0;
    case 11910:
        type = "PCM-S";
        bank = "SRX-05:Supreme Dance";
        return 0;
    case 11911:
        type = "PCM-S";
        bank = "SRX-06:Complete Orchestra";
        return 0;
    case 11912:
        type = "PCM-S";
        bank = "SRX-06:Complete Orchestra";
        return 0;
    case 11913:
        type = "PCM-S";
        bank = "SRX-06:Complete Orchestra";
        return 0;
    case 11914:
        type = "PCM-S";
        bank = "SRX-06:Complete Orchestra";
        return 0;
    case 11915:
        type = "PCM-S";
        bank = "SRX-07:Ultimate Keys";
        return 0;
    case 11916:
        type = "PCM-S";
        bank = "SRX-07:Ultimate Keys";
        return 0;
    case 11917:
        type = "PCM-S";
        bank = "SRX-07:Ultimate Keys";
        return 0;
    case 11918:
        type = "PCM-S";
        bank = "SRX-07:Ultimate Keys";
        return 0;
    case 11919:
        type = "PCM-S";
        bank = "SRX-08:Platinum Trax";
        return 0;
    case 11920:
        type = "PCM-S";
        bank = "SRX-08:Platinum Trax";
        return 0;
    case 11921:
        type = "PCM-S";
        bank = "SRX-08:Platinum Trax";
        return 0;
    case 11922:
        type = "PCM-S";
        bank = "SRX-08:Platinum Trax";
        return 0;
    case 11923:
        type = "PCM-S";
        bank = "SRX-09:World Collection";
        return 0;
    case 11924:
        type = "PCM-S";
        bank = "SRX-09:World Collection";
        return 0;
    case 11925:
        type = "PCM-S";
        bank = "SRX-09:World Collection";
        return 0;
    case 11926:
        type = "PCM-S";
        bank = "SRX-09:World Collection";
        return 0;
    case 11927:
        type = "PCM-S";
        bank = "SRX-10:Big Brass Ensemble";
        return 0;
    case 11928:
        type = "PCM-S";
        bank = "SRX-11:Complete Piano";
        return 0;
    case 11930:
        type = "PCM-S";
        bank = "SRX-12:Classic EPs";
        return 0;
    case 12160:
        type = "SN-S";
        bank = "USER";
        return 0;
    case 12161:
        type = "SN-S";
        bank = "USER";
        return 0;
    case 12162:
        type = "SN-S";
        bank = "USER";
        return 0;
    case 12163:
        type = "SN-S";
        bank = "USER";
        return 0;
    case 12224:
        type = "SN-S";
        bank = "PRESET";
        return 0;
    case 12225:
        type = "SN-S";
        bank = "PRESET";
        return 0;
    case 12226:
        type = "SN-S";
        bank = "PRESET";
        return 0;
    case 12227:
        type = "SN-S";
        bank = "PRESET";
        return 0;
    case 12228:
        type = "SN-S";
        bank = "PRESET";
        return 0;
    case 12229:
        type = "SN-S";
        bank = "PRESET";
        return 0;
    case 12230:
        type = "SN-S";
        bank = "PRESET";
        return 0;
    case 12231:
        type = "SN-S";
        bank = "PRESET";
        return 0;
    case 12232:
        type = "SN-S";
        bank = "PRESET";
        return 0;
    case 12288:
        type = "ExPCM-Drums";
        bank = "PRESET";
        return 0;
    case 12416:
        type = "ExPCM";
        bank = "PRESET";
        return 0;
    case 12417:
        type = "ExPCM";
        bank = "PRESET";
        return 0;
    case 12418:
        type = "ExPCM";
        bank = "PRESET";
        return 0;
    case 12419:
        type = "ExPCM";
        bank = "PRESET";
        return 0;
    case 15360:
        type = "GM2-Drums";
        bank = "PRESET";
        return 0;
    case 15488:
        type = "GM2-Tone";
        bank = "Base";
        return 0;
    case 15489:
        type = "GM2-Tone";
        bank = "Var #1";
        return 0;
    case 15490:
        type = "GM2-Tone";
        bank = "Var #2";
        return 0;
    case 15491:
        type = "GM2-Tone";
        bank = "Var #3";
        return 0;
    case 15492:
        type = "GM2-Tone";
        bank = "Var #4";
        return 0;
    case 15493:
        type = "GM2-Tone";
        bank = "Var #5";
        return 0;
    case 15494:
        type = "GM2-Tone";
        bank = "Var #6";
        return 0;
    case 15495:
        type = "GM2-Tone";
        bank = "Var #7";
        return 0;
    case 15496:
        type = "GM2-Tone";
        bank = "Var #8";
        return 0;
    case 15497:
        type = "GM2-Tone";
        bank = "Var #9";
        return 0;
    }
    return -1;
}

QStringList& Integra7Device::NumberedCustomList(QString ptxt,int n1,int n2, QString atxt)
{
    static QStringList list;
    int i = n1;
    list.clear();
    list.reserve(n2-n1+1);
    if (ptxt.length() > 0 && atxt.length() > 0) {
        while (i <= n2) list.append(ptxt % QString::number(i++) % atxt);
    }
    else if (ptxt.length() > 0 && atxt.length() == 0) {
        while (i <= n2) list.append(ptxt % QString::number(i++));
    }
    else if (ptxt.length() == 0 && atxt.length() > 0) {
        while (i <= n2) list.append(QString::number(i++) % atxt);
    } else {
        while (i <= n2) list.append(QString::number(i++));
    }

    return list;
}

void Integra7Device::LoadVirtualSlots(uint8_t s1, uint8_t s2, uint8_t s3, uint8_t s4)
{
    VirtualSlots[4] = s1;
    VirtualSlots[5] = s2;
    VirtualSlots[6] = s3;
    VirtualSlots[7] = s4;
    DataRequest(VirtualSlots);
}

void Integra7Device::SetPreview(uint8_t val)
{
    uint8_t msg[5] {0x0F,0x00,0x20,0x00,val};
    DataSet(msg,5);
}

void Integra7Device::ReceiveIntegraSysEx(const uint8_t *data, int len)
{

    if (data[0] != 0xF0) return;
    if (data[len-1] != 0xF7) return; //SysEx does not contain 0xF7 at the end
    if (data[2] != cDeviceId) return;

    if (data[1] == 0x41) {
        //ROLAND specific SysEx
        if (len < 14) return;
        if (data[3] != 0x00) return;
        if (data[4] != 0x00) return;
        if (data[5] != 0x64) return;//INTEGRA-7 ID
        if (data[6] != 0x12) return;//Command Id DT1

        if (data[len-2] == Checksum(data+7)) {

            ++ReceivedSysExCounter;
            ReceivedBytesCounter += len;

            DisplayStatsMsg();

            qDebug("IntegraDevice received %u bytes at address : %02X %02X %02X %02X",len,data[7],data[8],data[9],data[10]);

            int dlen = len - 13;
            uint8_t a0 = data[10];
            uint8_t a1 = data[9];
            uint8_t a2 = data[8];
            uint8_t a3 = data[7];
            const uint8_t *rdata = data+11;

            if (a3 == 0x01) Setup->DataReceive(rdata,a0,dlen);
            else if (a3 == 0x02) SystemCommon->DataReceive(rdata,a0,dlen);
            else if (a3 == 0x18) {
                if (a1 == 0x00) StudioSetCommon->DataReceive(rdata,a0,dlen);
                else if (a1 == 0x04) Chorus->DataReceive(rdata,a0,dlen);
                else if (a1 == 0x06) Reverb->DataReceive(rdata,a0,dlen);
                else if (a1 == 0x09) MasterEQ->DataReceive(rdata,a0,dlen);
                else if (a1 >= 0x20 && a1 <= 0x2F)
                    Parts[a1-0x20]->DataReceive(rdata,a0,dlen);
                else if (a1 >= 0x50 && a1 <= 0x5F)
                    PartsEQ[a1-0x50]->DataReceive(rdata,a0,dlen);
            } else if (a3 >= 0x19 && a3 <= 0x1C) {
                int ti = (a3-0x19)*4+a2/0x20;
                Tones[ti]->ReceiveData(data,len);
            }
        }

    } else if (data[1] == 0x7E) {
        //Universal Non-Realtime
        //Identity Reply Only
        if (len < 15) return;
        if (data[3] != 0x06) return;
        if (data[4] != 0x02) return;
        if (data[5] != 0x41) return;

        QString msg = QString("Identity reply received! ") %
                      QString(" Device family code : 0x%1 0x%2").arg(data[6],0,16).arg(data[7],0,16) %
                      QString(" Software revision : 0x%1 0x%2 0x%3 0x%4").arg(data[10],0,16)
                                                                         .arg(data[11],0,16)
                                                                         .arg(data[12],0,16)
                                                                         .arg(data[13],0,16);

        uiWin->ShowStatusMsg(msg);
        ReceivedBytesCounter += len;

    }
}

QStringList& Integra7Device::GetBankList(QString type)
{
    if (type == "SN-A")
        return Integra7Device::SNAcousticBanks();
    else if (type == "SN-S")
        return Integra7Device::SNSynthBanks();
    else if (type == "SN-D")
        return Integra7Device::SNDrumBanks();
    else if (type == "PCM-S")
        return Integra7Device::PCMSynthBanks();
    else if (type == "PCM-D")
        return Integra7Device::PCMDrumBanks();
    else if (type == "GM2-Tone")
        return Integra7Device::GM2Banks();    

    return Integra7Device::PresetBank();
}

QStringList& Integra7Device::GetToneList(QString type, QString bank)
{
    if (bank == "PRESET"){
        if (type == "SN-A")
            return Integra7Device::SNAcousticPresets();
        else if (type == "SN-S")
            return Integra7Device::SNSynthPresets();
        else if (type == "SN-D")
            return Integra7Device::SNDrumPresets();
        else if (type == "PCM-S")
            return Integra7Device::PCMSynthPresets();
        else if (type == "PCM-D")
            return Integra7Device::PCMDrumPresets();
        else if (type == "ExPCM")
            return Integra7Device::ExPCMPresets();
        else if (type == "ExPCM-Drums")
            return Integra7Device::ExPCMDrumPresets();
        else if (type == "GM2-Drums")
            return Integra7Device::GM2DrumPresets();
        else if (type == "GS")
            return Integra7Device::GM2Presets();
    } else if (bank == "USER") {
        if (type == "SN-A")
            return Integra7Device::NumberedCustomList("",1,256,":USER");
        else if (type == "SN-S")
            return Integra7Device::NumberedCustomList("",1,512,":USER");
        else if (type == "SN-D")
            return Integra7Device::NumberedCustomList("",1,64,":USER");
        else if (type == "PCM-S")
            return Integra7Device::NumberedCustomList("",1,256,":USER");
        else if (type == "PCM-D")
            return Integra7Device::NumberedCustomList("",1,32,":USER");
    }
    else if (bank == "ExSN1:Ethnic")
        return Integra7Device::ExSN1Presets();
    else if (bank == "ExSN2:WoodWinds")
        return Integra7Device::ExSN2Presets();
    else if (bank == "ExSN3:Session")
        return Integra7Device::ExSN3Presets();
    else if (bank == "ExSN4:A.Guitar")
        return Integra7Device::ExSN4Presets();
    else if (bank == "ExSN5:Brass")
        return Integra7Device::ExSN5Presets();
    else if (bank == "ExSN6:SFX")
        return Integra7Device::ExSN6Presets();
    else if (bank == "SRX-01:Dynamic Drum Kits") {
        if (type == "PCM-S")
            return Integra7Device::SRX01Presets();
        else
            return Integra7Device::SRX01DrumPresets();
    }
    else if (bank == "SRX-02:Concert Piano")
        return Integra7Device::SRX02Presets();
    else if (bank == "SRX-03:Studio SRX") {
        if (type == "PCM-S")
            return Integra7Device::SRX03Presets();
        else
            return Integra7Device::SRX03DrumPresets();
    } else if (bank == "SRX-04:Symphonique Strings")
        return Integra7Device::SRX04Presets();
    else if (bank == "SRX-05:Supreme Dance") {
        if (type == "PCM-S")
            return Integra7Device::SRX05Presets();
        else
            return Integra7Device::SRX05DrumPresets();
    } else if (bank == "SRX-06:Complete Orchestra") {
        if (type == "PCM-S")
            return Integra7Device::SRX06Presets();
        else
            return Integra7Device::SRX06DrumPresets();
    } else if (bank == "SRX-07:Ultimate Keys") {
        if (type == "PCM-S")
            return Integra7Device::SRX07Presets();
        else
            return Integra7Device::SRX07DrumPresets();
    } else if (bank == "SRX-08:Platinum Trax") {
        if (type == "PCM-S")
            return Integra7Device::SRX08Presets();
        else
            return Integra7Device::SRX08DrumPresets();
    } else if (bank == "SRX-09:World Collection") {
        if (type == "PCM-S")
            return Integra7Device::SRX09Presets();
        else
            return Integra7Device::SRX09DrumPresets();
    } else if (bank == "SRX-10:Big Brass Ensemble")
        return Integra7Device::SRX10Presets();
    else if (bank == "SRX-11:Complete Piano")
        return Integra7Device::SRX11Presets();
    else if (bank == "SRX-12:Classic EPs")
        return Integra7Device::SRX12Presets();
    else if (bank == "Base")
        return Integra7Device::GM2Presets();
    else if (bank == "Var #1")
        return Integra7Device::GM2Presets1();
    else if (bank == "Var #2")
        return Integra7Device::GM2Presets2();
    else if (bank == "Var #3")
        return Integra7Device::GM2Presets3();
    else if (bank == "Var #4")
        return Integra7Device::GM2Presets4();
    else if (bank == "Var #5")
        return Integra7Device::GM2Presets5();
    else if (bank == "Var #6")
        return Integra7Device::GM2Presets6();
    else if (bank == "Var #7")
        return Integra7Device::GM2Presets7();
    else if (bank == "Var #8")
        return Integra7Device::GM2Presets8();
    else if (bank == "Var #9")
        return Integra7Device::GM2Presets9();

    return Integra7Device::GM2Presets();
}

void Integra7Device::SendFullSysEx(uint8_t *data, int len)
{
    pMidiEngine->SendSysEx(data,len);

    ++SentSysExCounter;
    SentBytesCounter += len;

    DisplayStatsMsg();
}

uint8_t Integra7Device::Checksum(const uint8_t *msg)
{
    int i = 0;
    int sum = 0;

    while (i < BUFFER_SIZE-1) {
        if (msg[i+1] == 0xF7)
            break;
        else
            sum += msg[i++];
    }

    return 128 - (sum & 0x7F);
}

int Integra7Device::FillOutputDataFrame(const uint8_t *data, int len)
{
    int t = 7; //target counter = start index of address bytes in SysEx array

    for (int s=0; s<len; s++)
    {
        OutputData[t++] = data[s];
    }

    //Reset Checksum
    OutputData[t++] = 0;

    //Add end of SysEx
    OutputData[t] = 0xF7;

    OutputData[t-1] = Checksum(OutputData+7);

    return t+1;
}

void Integra7Device::SendIntegraSysEx(int len)
{   
    pMidiEngine->SendSysEx(OutputData,len);

    ++SentSysExCounter;
    SentBytesCounter += len;

    DisplayStatsMsg();
}
