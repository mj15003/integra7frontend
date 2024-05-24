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
#include "./ui_integra7mainwindow.h"

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

    void TypeBoxChangeLogic(QComboBox *TypeBox, QComboBox *BankBox, QComboBox *ToneBox);
    void BankBoxChangeLogic(QComboBox *TypeBox, QComboBox *BankBox, QComboBox *ToneBox);
    void ToneBoxChangeLogic(uint8_t part, int index, QComboBox *TypeBox, QComboBox *BankBox);

    void TypeBoxChange(int part);
    void BankBoxChange(int part);
    void ToneBoxChange(int part);

private slots:    
    void PartBtnToggled(int id, bool checked);
    void ShowStudioSet();
    void ShowEffects();
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
    void ShowVirtualSlotsCard();
    void ShowUtilityCard();

    void SoloButtonsLogic(int id, bool checked);

    void MidiConnectBtn_clicked();
    void VSlotBox_currentIndexChanged(int index);
    void VSlotLoadBtn_clicked();

};

class ReadRequest : public QRunnable
{
public:
    explicit ReadRequest(Integra7Device *i7dev);
private:
    Integra7Device *dev;
    void run() override;
};

class DumpFileReader : public QRunnable
{
public:
    explicit DumpFileReader(Integra7Device *pdev, integra7MainWindow *pwin, QString& fname);
private:
    QString fileName;    
    integra7MainWindow *win;
    Integra7Device *dev;
    void run() override;
};
#endif // INTEGRA7MAINWINDOW_H
