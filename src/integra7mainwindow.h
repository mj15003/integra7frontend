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

#ifndef INTEGRA7MAINWINDOW_H
#define INTEGRA7MAINWINDOW_H

#include "integra7device.h"
#include "integra7tone.h"
#include "./ui_integra7mainwindow.h"
#include "tworganeditor.h"

#include <QButtonGroup>
#include <QMainWindow>
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui { class integra7MainWindow;}
QT_END_NAMESPACE

class integra7MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    integra7MainWindow(QWidget *parent = nullptr);
    ~integra7MainWindow();

public slots:
    void BulkDumpRequest();
    void ShowStatusValue(int val);
    void ShowStatusMsg(const QString msg) {ui->statusbar->showMessage(msg);}
    void DisplayPartTonePreset(int part, int bank, int p);
    void SelectPreview(bool checked);
    void UpdateStudioSetName(QString name);
    void ReadDumpFromFile();
    void WriteDumpToFile();

private:
    Ui::integra7MainWindow *ui;
    TWOrganEditor *TWOrganEditorW;

    MidiEngine *pMidiEngine;

    Integra7Device *pI7d;

    QButtonGroup MainHeaderBtnGrp;
    QButtonGroup PartBtnGrp;
    QButtonGroup SoloPartBtnGrp;
    QButtonGroup SoloPartBtnGrp1;

    QComboBox *TypeBoxes[16][2];
    QComboBox *BankBoxes[16][2];
    QComboBox *ToneBoxes[16][2];    

    bool BlockToneChangeSignal = 0;

    Integra7ToneMFX *MFXTarget;
    Integra7DrumCompEQ *CompEQTarget;
    Integra7Tone *PCMSTarget;
    Integra7Tone *PCMDKTarget;
    Integra7PCMDrumKitPartial *PCMDKPartialTarget;
    Integra7Tone *SNATarget;
    Integra7Tone *SNSTarget;
    Integra7Tone *SNDKTarget;
    Integra7SNDrumKitNote *SNDKNoteTarget;

    void TypeBoxChangeLogic(QComboBox *TypeBox, QComboBox *BankBox, QComboBox *ToneBox);
    void BankBoxChangeLogic(QComboBox *TypeBox, QComboBox *BankBox, QComboBox *ToneBox);
    void ToneBoxChangeLogic(uint8_t part, int index, QComboBox *TypeBox, QComboBox *BankBox);

    void ConnectPCMSynthTone(Integra7Tone *tone);
    void DisconnectPCMSynthTone(Integra7Tone *tone);

    void ConnectPCMDrumKit(Integra7Tone *tone);
    void ConnectPCMDrumKitPartial(Integra7PCMDrumKitPartial *partial);

    void DisconnectPCMDrumKit(Integra7Tone *tone);
    void DisconnectPCMDrumKitPartial(Integra7PCMDrumKitPartial *partial);

    void ConnectSNAcousticTone(Integra7Tone *tone);
    void DisconnectSNAcousticTone(Integra7Tone *tone);

    void ConnectSNSynthTone(Integra7Tone *tone);
    void DisconnectSNSynthTone(Integra7Tone *tone);

    void ConnectSNDrumKit(Integra7Tone *tone);
    void ConnectSNDrumKitNote(Integra7SNDrumKitNote *note);
    void DisconnectSNDrumKit(Integra7Tone *tone);
    void DisconnectSNDrumKitNote(Integra7SNDrumKitNote *note);

    void ConnectMFX(Integra7ToneMFX *mfxd);
    void DisconnectMFX(Integra7ToneMFX *mfxd);

    void ConnectDrumCompEQ(Integra7DrumCompEQ *compeqd);
    void DisconnectDrumCompEQ(Integra7DrumCompEQ *compeqd);

private slots:    
    void PartBtnToggled(int id, bool checked);
    void ShowStudioSet();
    void ShowEffects();
    void ShowTone();
    void ShowPartViewCard() {ui->RightContent->setCurrentWidget(ui->PartViewCard);}
    void ShowPartLevelCard() {ui->RightContent->setCurrentWidget(ui->PartLevelCard);}
    void ShowPartEQCard(){ui->RightContent->setCurrentWidget(ui->PartEQCard);}
    void ShowPartKeyboardCard(){ui->RightContent->setCurrentWidget(ui->PartKeyboardCard);}
    void ShowPartMidiCard(){ui->RightContent->setCurrentWidget(ui->PartMidiCard);}
    void ShowPartOffsetCard(){ui->RightContent->setCurrentWidget(ui->PartOffsetCard);}
    void ShowPartPitchCard(){ui->RightContent->setCurrentWidget(ui->PartPitchCard);}
    void ShowPartScaleCard(){ui->RightContent->setCurrentWidget(ui->PartScaleCard);}
    void ShowPartToneCard() {ui->RightContent->setCurrentWidget(ui->PartToneCard);}
    void ShowMasterEQCard() {ui->RightContent->setCurrentWidget(ui->MasterEQCard);}
    void ShowSystemCard() {ui->RightContent->setCurrentWidget(ui->SystemCard);}
    void ShowChorusCard() {ui->RightContent->setCurrentWidget(ui->ChorusCard);}
    void ShowChorusParams(QString tp);
    void ShowReverbCard() {ui->RightContent->setCurrentWidget(ui->ReverbCard);}
    void ShowReverbParams(int tp);
    void ShowPCMSynthCommon(){ui->RightContent->setCurrentWidget(ui->PCMSynthToneCommonCard);}
    void ShowPCMSynthMFX();
    void ShowPCMSynthPMT(){ui->RightContent->setCurrentWidget(ui->PCMSynthTonePMTCard);}
    void ShowPCMSynthPartial(){ui->RightContent->setCurrentWidget(ui->PCMSynthTonePartialCard);}
    void ShowSNSynthCommon(){ui->RightContent->setCurrentWidget(ui->SNSynthToneCommonCard);}
    void ShowSNSynthMFX();
    void ShowSNSynthPartial(){ui->RightContent->setCurrentWidget(ui->SNSynthTonePartialCard);}
    void ShowSNAcousticCommon(){ui->RightContent->setCurrentWidget(ui->SNAcousticToneCard);}
    void ShowSNAcousticMFX();
    void ShowSNAcousticParameters(int n);
    void ShowSNDrumKitCommon(){ui->RightContent->setCurrentWidget(ui->SNDrumKitCommonCard);}
    void ShowSNDrumKitMFX();
    void ShowSNDrumKitCompEQ();
    void ShowSNDrumKitNote(){ui->RightContent->setCurrentWidget(ui->SNDrumKitNoteCard);}
    void ShowPCMDrumKitCommon(){ui->RightContent->setCurrentWidget(ui->PCMDrumKitCommonCard);}
    void ShowPCMDrumKitMFX();
    void ShowPCMDrumKitCompEQ();
    void ShowPCMDrumKitPartial(){ui->RightContent->setCurrentWidget(ui->PCMDrumKitPartialCard);}
    void ShowVirtualSlotsCard();
    void ShowUtilityCard();

    void SoloButtonsLogic(int id, bool checked);

    void MidiConnectBtn_clicked();
    void VSlotBox_currentIndexChanged(int index);
    void VSlotLoadBtn_clicked();

    void PCMDrumKitNoteSelect(int note);
    void SNDrumKitNoteSelect(int note);
};


#endif // INTEGRA7MAINWINDOW_H
