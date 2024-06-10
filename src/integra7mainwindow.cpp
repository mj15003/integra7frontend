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

#include <QFileDialog>
#include <QThreadPool>

#include "integra7mainwindow.h"
#include "./ui_integra7mainwindow.h"
#include "integra7part.h"
#include "integra7parteq.h"
#include "integra7mastereq.h"
#include "integra7studiosetcommon.h"
#include "integra7systemcommon.h"
#include "integra7setup.h"
#include "integra7chorus.h"
#include "integra7reverb.h"
#include "integra7tone.h"

integra7MainWindow::integra7MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::integra7MainWindow)
{
    ui->setupUi(this);

    TypeBoxes[0][0] = ui->Ch1TypeBox;
    TypeBoxes[1][0] = ui->Ch2TypeBox;
    TypeBoxes[2][0] = ui->Ch3TypeBox;
    TypeBoxes[3][0] = ui->Ch4TypeBox;
    TypeBoxes[4][0] = ui->Ch5TypeBox;
    TypeBoxes[5][0] = ui->Ch6TypeBox;
    TypeBoxes[6][0] = ui->Ch7TypeBox;
    TypeBoxes[7][0] = ui->Ch8TypeBox;
    TypeBoxes[8][0] = ui->Ch9TypeBox;
    TypeBoxes[9][0] = ui->Ch10TypeBox;
    TypeBoxes[10][0] = ui->Ch11TypeBox;
    TypeBoxes[11][0] = ui->Ch12TypeBox;
    TypeBoxes[12][0] = ui->Ch13TypeBox;
    TypeBoxes[13][0] = ui->Ch14TypeBox;
    TypeBoxes[14][0] = ui->Ch15TypeBox;
    TypeBoxes[15][0] = ui->Ch16TypeBox;

    BankBoxes[0][0] = ui->Ch1BankBox;
    BankBoxes[1][0] = ui->Ch2BankBox;
    BankBoxes[2][0] = ui->Ch3BankBox;
    BankBoxes[3][0] = ui->Ch4BankBox;
    BankBoxes[4][0] = ui->Ch5BankBox;
    BankBoxes[5][0] = ui->Ch6BankBox;
    BankBoxes[6][0] = ui->Ch7BankBox;
    BankBoxes[7][0] = ui->Ch8BankBox;
    BankBoxes[8][0] = ui->Ch9BankBox;
    BankBoxes[9][0] = ui->Ch10BankBox;
    BankBoxes[10][0] = ui->Ch11BankBox;
    BankBoxes[11][0] = ui->Ch12BankBox;
    BankBoxes[12][0] = ui->Ch13BankBox;
    BankBoxes[13][0] = ui->Ch14BankBox;
    BankBoxes[14][0] = ui->Ch15BankBox;
    BankBoxes[15][0] = ui->Ch16BankBox;

    ToneBoxes[0][0] = ui->Ch1ToneBox;
    ToneBoxes[1][0] = ui->Ch2ToneBox;
    ToneBoxes[2][0] = ui->Ch3ToneBox;
    ToneBoxes[3][0] = ui->Ch4ToneBox;
    ToneBoxes[4][0] = ui->Ch5ToneBox;
    ToneBoxes[5][0] = ui->Ch6ToneBox;
    ToneBoxes[6][0] = ui->Ch7ToneBox;
    ToneBoxes[7][0] = ui->Ch8ToneBox;
    ToneBoxes[8][0] = ui->Ch9ToneBox;
    ToneBoxes[9][0] = ui->Ch10ToneBox;
    ToneBoxes[10][0] = ui->Ch11ToneBox;
    ToneBoxes[11][0] = ui->Ch12ToneBox;
    ToneBoxes[12][0] = ui->Ch13ToneBox;
    ToneBoxes[13][0] = ui->Ch14ToneBox;
    ToneBoxes[14][0] = ui->Ch15ToneBox;
    ToneBoxes[15][0] = ui->Ch16ToneBox;

    TypeBoxes[0][1] = ui->Ch1TypeBox1;
    TypeBoxes[1][1] = ui->Ch2TypeBox1;
    TypeBoxes[2][1] = ui->Ch3TypeBox1;
    TypeBoxes[3][1] = ui->Ch4TypeBox1;
    TypeBoxes[4][1] = ui->Ch5TypeBox1;
    TypeBoxes[5][1] = ui->Ch6TypeBox1;
    TypeBoxes[6][1] = ui->Ch7TypeBox1;
    TypeBoxes[7][1] = ui->Ch8TypeBox1;
    TypeBoxes[8][1] = ui->Ch9TypeBox1;
    TypeBoxes[9][1] = ui->Ch10TypeBox1;
    TypeBoxes[10][1] = ui->Ch11TypeBox1;
    TypeBoxes[11][1] = ui->Ch12TypeBox1;
    TypeBoxes[12][1] = ui->Ch13TypeBox1;
    TypeBoxes[13][1] = ui->Ch14TypeBox1;
    TypeBoxes[14][1] = ui->Ch15TypeBox1;
    TypeBoxes[15][1] = ui->Ch16TypeBox1;

    BankBoxes[0][1] = ui->Ch1BankBox1;
    BankBoxes[1][1] = ui->Ch2BankBox1;
    BankBoxes[2][1] = ui->Ch3BankBox1;
    BankBoxes[3][1] = ui->Ch4BankBox1;
    BankBoxes[4][1] = ui->Ch5BankBox1;
    BankBoxes[5][1] = ui->Ch6BankBox1;
    BankBoxes[6][1] = ui->Ch7BankBox1;
    BankBoxes[7][1] = ui->Ch8BankBox1;
    BankBoxes[8][1] = ui->Ch9BankBox1;
    BankBoxes[9][1] = ui->Ch10BankBox1;
    BankBoxes[10][1] = ui->Ch11BankBox1;
    BankBoxes[11][1] = ui->Ch12BankBox1;
    BankBoxes[12][1] = ui->Ch13BankBox1;
    BankBoxes[13][1] = ui->Ch14BankBox1;
    BankBoxes[14][1] = ui->Ch15BankBox1;
    BankBoxes[15][1] = ui->Ch16BankBox1;

    ToneBoxes[0][1] = ui->Ch1ToneBox1;
    ToneBoxes[1][1] = ui->Ch2ToneBox1;
    ToneBoxes[2][1] = ui->Ch3ToneBox1;
    ToneBoxes[3][1] = ui->Ch4ToneBox1;
    ToneBoxes[4][1] = ui->Ch5ToneBox1;
    ToneBoxes[5][1] = ui->Ch6ToneBox1;
    ToneBoxes[6][1] = ui->Ch7ToneBox1;
    ToneBoxes[7][1] = ui->Ch8ToneBox1;
    ToneBoxes[8][1] = ui->Ch9ToneBox1;
    ToneBoxes[9][1] = ui->Ch10ToneBox1;
    ToneBoxes[10][1] = ui->Ch11ToneBox1;
    ToneBoxes[11][1] = ui->Ch12ToneBox1;
    ToneBoxes[12][1] = ui->Ch13ToneBox1;
    ToneBoxes[13][1] = ui->Ch14ToneBox1;
    ToneBoxes[14][1] = ui->Ch15ToneBox1;
    ToneBoxes[15][1] = ui->Ch16ToneBox1;

    /* Setup Custom SpinBoxes */
    ui->Ch1BendRangeBox->SetMaxText("TONE");
    ui->Ch1PortaTimeBox->SetMaxText("TONE");
    ui->Ch2BendRangeBox->SetMaxText("TONE");
    ui->Ch2PortaTimeBox->SetMaxText("TONE");
    ui->Ch3BendRangeBox->SetMaxText("TONE");
    ui->Ch3PortaTimeBox->SetMaxText("TONE");
    ui->Ch4BendRangeBox->SetMaxText("TONE");
    ui->Ch4PortaTimeBox->SetMaxText("TONE");
    ui->Ch5BendRangeBox->SetMaxText("TONE");
    ui->Ch5PortaTimeBox->SetMaxText("TONE");
    ui->Ch6BendRangeBox->SetMaxText("TONE");
    ui->Ch6PortaTimeBox->SetMaxText("TONE");
    ui->Ch7BendRangeBox->SetMaxText("TONE");
    ui->Ch7PortaTimeBox->SetMaxText("TONE");
    ui->Ch8BendRangeBox->SetMaxText("TONE");
    ui->Ch8PortaTimeBox->SetMaxText("TONE");
    ui->Ch9BendRangeBox->SetMaxText("TONE");
    ui->Ch9PortaTimeBox->SetMaxText("TONE");
    ui->Ch10BendRangeBox->SetMaxText("TONE");
    ui->Ch10PortaTimeBox->SetMaxText("TONE");
    ui->Ch11BendRangeBox->SetMaxText("TONE");
    ui->Ch11PortaTimeBox->SetMaxText("TONE");
    ui->Ch12BendRangeBox->SetMaxText("TONE");
    ui->Ch12PortaTimeBox->SetMaxText("TONE");
    ui->Ch13BendRangeBox->SetMaxText("TONE");
    ui->Ch13PortaTimeBox->SetMaxText("TONE");
    ui->Ch14BendRangeBox->SetMaxText("TONE");
    ui->Ch14PortaTimeBox->SetMaxText("TONE");
    ui->Ch15BendRangeBox->SetMaxText("TONE");
    ui->Ch15PortaTimeBox->SetMaxText("TONE");
    ui->Ch16BendRangeBox->SetMaxText("TONE");
    ui->Ch16PortaTimeBox->SetMaxText("TONE");

    /* Setup UI Button coloring */
    MainHeaderBtnGrp.addButton(ui->StudioSetBtn);
    MainHeaderBtnGrp.addButton(ui->ToneBtn);
    MainHeaderBtnGrp.addButton(ui->MotionalSurroundBtn);
    MainHeaderBtnGrp.addButton(ui->EffectsBtn);
    MainHeaderBtnGrp.addButton(ui->SystemBtn);
    MainHeaderBtnGrp.addButton(ui->ExpansionBtn);
    MainHeaderBtnGrp.addButton(ui->UtilityBtn);

    PartBtnGrp.addButton(ui->Ch1Btn);
    PartBtnGrp.addButton(ui->Ch2Btn);
    PartBtnGrp.addButton(ui->Ch3Btn);
    PartBtnGrp.addButton(ui->Ch4Btn);
    PartBtnGrp.addButton(ui->Ch5Btn);
    PartBtnGrp.addButton(ui->Ch6Btn);
    PartBtnGrp.addButton(ui->Ch7Btn);
    PartBtnGrp.addButton(ui->Ch8Btn);
    PartBtnGrp.addButton(ui->Ch9Btn);
    PartBtnGrp.addButton(ui->Ch10Btn);
    PartBtnGrp.addButton(ui->Ch11Btn);
    PartBtnGrp.addButton(ui->Ch12Btn);
    PartBtnGrp.addButton(ui->Ch13Btn);
    PartBtnGrp.addButton(ui->Ch14Btn);
    PartBtnGrp.addButton(ui->Ch15Btn);
    PartBtnGrp.addButton(ui->Ch16Btn);

    PartBtnGrp.setId(ui->Ch1Btn,0);
    PartBtnGrp.setId(ui->Ch2Btn,1);
    PartBtnGrp.setId(ui->Ch3Btn,2);
    PartBtnGrp.setId(ui->Ch4Btn,3);
    PartBtnGrp.setId(ui->Ch5Btn,4);
    PartBtnGrp.setId(ui->Ch6Btn,5);
    PartBtnGrp.setId(ui->Ch7Btn,6);
    PartBtnGrp.setId(ui->Ch8Btn,7);
    PartBtnGrp.setId(ui->Ch9Btn,8);
    PartBtnGrp.setId(ui->Ch10Btn,9);
    PartBtnGrp.setId(ui->Ch11Btn,10);
    PartBtnGrp.setId(ui->Ch12Btn,11);
    PartBtnGrp.setId(ui->Ch13Btn,12);
    PartBtnGrp.setId(ui->Ch14Btn,13);
    PartBtnGrp.setId(ui->Ch15Btn,14);
    PartBtnGrp.setId(ui->Ch16Btn,15);

    SoloPartBtnGrp.addButton(ui->Ch1SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch2SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch3SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch4SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch5SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch6SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch7SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch8SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch9SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch10SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch11SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch12SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch13SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch14SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch15SoloBtn);
    SoloPartBtnGrp.addButton(ui->Ch16SoloBtn);

    SoloPartBtnGrp.setId(ui->Ch1SoloBtn,1);
    SoloPartBtnGrp.setId(ui->Ch2SoloBtn,2);
    SoloPartBtnGrp.setId(ui->Ch3SoloBtn,3);
    SoloPartBtnGrp.setId(ui->Ch4SoloBtn,4);
    SoloPartBtnGrp.setId(ui->Ch5SoloBtn,5);
    SoloPartBtnGrp.setId(ui->Ch6SoloBtn,6);
    SoloPartBtnGrp.setId(ui->Ch7SoloBtn,7);
    SoloPartBtnGrp.setId(ui->Ch8SoloBtn,8);
    SoloPartBtnGrp.setId(ui->Ch9SoloBtn,9);
    SoloPartBtnGrp.setId(ui->Ch10SoloBtn,10);
    SoloPartBtnGrp.setId(ui->Ch11SoloBtn,11);
    SoloPartBtnGrp.setId(ui->Ch12SoloBtn,12);
    SoloPartBtnGrp.setId(ui->Ch13SoloBtn,13);
    SoloPartBtnGrp.setId(ui->Ch14SoloBtn,14);
    SoloPartBtnGrp.setId(ui->Ch15SoloBtn,15);
    SoloPartBtnGrp.setId(ui->Ch16SoloBtn,16);

    SoloPartBtnGrp.setExclusive(false);

    SoloPartBtnGrp1.addButton(ui->Ch1SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch2SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch3SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch4SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch5SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch6SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch7SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch8SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch9SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch10SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch11SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch12SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch13SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch14SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch15SoloBtn1);
    SoloPartBtnGrp1.addButton(ui->Ch16SoloBtn1);

    SoloPartBtnGrp1.setId(ui->Ch1SoloBtn1,1);
    SoloPartBtnGrp1.setId(ui->Ch2SoloBtn1,2);
    SoloPartBtnGrp1.setId(ui->Ch3SoloBtn1,3);
    SoloPartBtnGrp1.setId(ui->Ch4SoloBtn1,4);
    SoloPartBtnGrp1.setId(ui->Ch5SoloBtn1,5);
    SoloPartBtnGrp1.setId(ui->Ch6SoloBtn1,6);
    SoloPartBtnGrp1.setId(ui->Ch7SoloBtn1,7);
    SoloPartBtnGrp1.setId(ui->Ch8SoloBtn1,8);
    SoloPartBtnGrp1.setId(ui->Ch9SoloBtn1,9);
    SoloPartBtnGrp1.setId(ui->Ch10SoloBtn1,10);
    SoloPartBtnGrp1.setId(ui->Ch11SoloBtn1,11);
    SoloPartBtnGrp1.setId(ui->Ch12SoloBtn1,12);
    SoloPartBtnGrp1.setId(ui->Ch13SoloBtn1,13);
    SoloPartBtnGrp1.setId(ui->Ch14SoloBtn1,14);
    SoloPartBtnGrp1.setId(ui->Ch15SoloBtn1,15);
    SoloPartBtnGrp1.setId(ui->Ch16SoloBtn1,16);

    SoloPartBtnGrp1.setExclusive(false);

    QObject::connect(&SoloPartBtnGrp,&QButtonGroup::idToggled,
                     this,&integra7MainWindow::SoloButtonsLogic);

    QObject::connect(&SoloPartBtnGrp,&QButtonGroup::idToggled,this,
                     [this](int id, bool checked)
                     {SoloPartBtnGrp1.button(id)->setChecked(checked);});

    QObject::connect(&SoloPartBtnGrp1,&QButtonGroup::idToggled,this,
                     [this](int id, bool checked)
                     {SoloPartBtnGrp.button(id)->setChecked(checked);});

    QObject::connect(&PartBtnGrp,
                     &QButtonGroup::idToggled,this,
                     &integra7MainWindow::PartBtnToggled);

    /* Setup UI buttons clicking logic*/
    QObject::connect(ui->StudioSetBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowStudioSet);

    QObject::connect(ui->UtilityBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowUtilityCard);

    QObject::connect(ui->EffectsBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowEffects);

    QObject::connect(ui->SystemBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowSystemCard);

    QObject::connect(ui->PartViewOpenBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowPartViewCard);

    QObject::connect(ui->ExpansionBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowVirtualSlotsCard);

    QObject::connect(ui->MidiConnectBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::MidiConnectBtn_clicked);

    QObject::connect(ui->PartViewOpenBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowPartViewCard);

    QObject::connect(ui->PartToneBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowPartToneCard);

    QObject::connect(ui->LevelChOpenBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowPartLevelCard);

    QObject::connect(ui->PartEQOpenBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowPartEQCard);

    QObject::connect(ui->KeyboardOpenBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowPartKeyboardCard);

    QObject::connect(ui->PitchOpenBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowPartPitchCard);

    QObject::connect(ui->ScaleOpenBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowPartScaleCard);

    QObject::connect(ui->OffsetOpenBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowPartOffsetCard);

    QObject::connect(ui->PartMidiOpenBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowPartMidiCard);

    QObject::connect(ui->MasterEQBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowMasterEQCard);

    QObject::connect(ui->ChorusBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowChorusCard);

    QObject::connect(ui->ReverbBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ShowReverbCard);

    QObject::connect(ui->WriteToFileBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::WriteDumpToFile);

    QObject::connect(ui->ReadFromFileBtn,
                     &QAbstractButton::clicked,this,
                     &integra7MainWindow::ReadDumpFromFile);

    /* Setup Main Combo box lists*/
    ui->StudioSetBox->addItems(Integra7Device::NumberedCustomList(64,":INIT"));
    ui->TypeBox->addItems(Integra7Device::TypeLabels());
    ui->BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->ToneBox->addItems(Integra7Device::SNAcousticPresets());

    QObject::connect(ui->TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->TypeBox,ui->BankBox,ui->ToneBox);});

    QObject::connect(ui->BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->TypeBox,ui->BankBox,ui->ToneBox);});

    QObject::connect(ui->ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(PartBtnGrp.checkedId(),
                                                 ui->ToneBox->currentIndex(),
                                                 ui->TypeBox,
                                                 ui->BankBox);});

    /* Setup Virtual Slots lists*/
    ui->VSlotABox->addItems(Integra7Device::ExpansionNames());
    ui->VSlotBBox->addItems(Integra7Device::ExpansionNames());
    ui->VSlotCBox->addItems(Integra7Device::ExpansionNames());
    ui->VSlotDBox->addItems(Integra7Device::ExpansionNames());

    QObject::connect(ui->VSlotABox,
                     &QComboBox::currentIndexChanged,this,
                     &integra7MainWindow::VSlotBox_currentIndexChanged);
    QObject::connect(ui->VSlotBBox,
                     &QComboBox::currentIndexChanged,this,
                     &integra7MainWindow::VSlotBox_currentIndexChanged);
    QObject::connect(ui->VSlotCBox,
                     &QComboBox::currentIndexChanged,this,
                     &integra7MainWindow::VSlotBox_currentIndexChanged);
    QObject::connect(ui->VSlotDBox,
                     &QComboBox::currentIndexChanged,this,
                     &integra7MainWindow::VSlotBox_currentIndexChanged);
    QObject::connect(ui->VSlotLoadBtn,
                     &QPushButton::clicked,this,
                     &integra7MainWindow::VSlotLoadBtn_clicked);

    /* Setup Part View Combo boxes */
    ui->Ch1TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch2TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch3TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch4TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch5TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch6TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch7TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch8TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch9TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch10TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch11TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch12TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch13TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch14TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch15TypeBox->addItems(Integra7Device::TypeLabels());
    ui->Ch16TypeBox->addItems(Integra7Device::TypeLabels());

    ui->Ch1BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch2BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch3BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch4BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch5BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch6BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch7BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch8BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch9BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch10BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch11BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch12BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch13BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch14BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch15BankBox->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch16BankBox->addItems(Integra7Device::SNAcousticBanks());

    ui->Ch1ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch2ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch3ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch4ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch5ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch6ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch7ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch8ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch9ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch10ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch11ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch12ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch13ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch14ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch15ToneBox->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch16ToneBox->addItems(Integra7Device::SNAcousticPresets());

    /* Setup Part Tone Combo boxes */
    ui->Ch1TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch2TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch3TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch4TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch5TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch6TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch7TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch8TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch9TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch10TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch11TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch12TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch13TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch14TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch15TypeBox1->addItems(Integra7Device::TypeLabels());
    ui->Ch16TypeBox1->addItems(Integra7Device::TypeLabels());

    ui->Ch1BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch2BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch3BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch4BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch5BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch6BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch7BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch8BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch9BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch10BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch11BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch12BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch13BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch14BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch15BankBox1->addItems(Integra7Device::SNAcousticBanks());
    ui->Ch16BankBox1->addItems(Integra7Device::SNAcousticBanks());

    ui->Ch1ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch2ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch3ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch4ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch5ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch6ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch7ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch8ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch9ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch10ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch11ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch12ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch13ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch14ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch15ToneBox1->addItems(Integra7Device::SNAcousticPresets());
    ui->Ch16ToneBox1->addItems(Integra7Device::SNAcousticPresets());

    ui->Ch1OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch2OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch3OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch4OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch5OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch6OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch7OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch8OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch9OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch10OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch11OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch12OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch13OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch14OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch15OutputBox->addItems(Integra7Device::OutputList());
    ui->Ch16OutputBox->addItems(Integra7Device::OutputList());

    ui->Ch1RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch2RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch3RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch4RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch5RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch6RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch7RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch8RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch9RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch10RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch11RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch12RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch13RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch14RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch15RxChBox->addItems(Integra7Device::MIDIChList());
    ui->Ch16RxChBox->addItems(Integra7Device::MIDIChList());

    ui->Ch1MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch2MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch3MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch4MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch5MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch6MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch7MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch8MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch9MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch10MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch11MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch12MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch13MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch14MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch15MonoPolyBox->addItems(Integra7Device::MonoPolyList());
    ui->Ch16MonoPolyBox->addItems(Integra7Device::MonoPolyList());

    ui->Ch1LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch2LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch3LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch4LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch5LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch6LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch7LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch8LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch9LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch10LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch11LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch12LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch13LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch14LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch15LegatoBox->addItems(Integra7Device::LegatoSwitchList());
    ui->Ch16LegatoBox->addItems(Integra7Device::LegatoSwitchList());

    ui->MEQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->MEQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->MEQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->MEQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch1EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch1EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch1EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch1EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch2EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch2EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch2EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch2EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch3EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch3EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch3EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch3EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch4EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch4EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch4EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch4EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch5EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch5EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch5EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch5EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch6EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch6EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch6EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch6EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch7EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch7EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch7EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch7EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch8EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch8EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch8EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch8EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch9EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch9EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch9EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch9EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch10EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch10EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch10EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch10EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch11EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch11EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch11EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch11EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch12EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch12EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch12EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch12EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch13EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch13EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch13EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch13EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch14EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch14EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch14EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch14EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch15EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch15EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch15EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch15EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    ui->Ch16EQLFFreqBox->addItems(Integra7Device::EQLowFreqList());
    ui->Ch16EQMFFreqBox->addItems(Integra7Device::EQMidFreqList());
    ui->Ch16EQMFQBox->addItems(Integra7Device::EQMidQList());
    ui->Ch16EQHFFreqBox->addItems(Integra7Device::EQHighFreqList());

    /* Chorus and Reverb Combo boxes */
    ui->ChorusTypeBox->addItems(Integra7Chorus::TypeList());
    ui->ChorusOutSelectBox->addItems(Integra7Chorus::OutputSelectList());
    ui->ChorusOutAssignBox->addItems(Integra7Device::OutputAssignList());

    ui->ChorusFilterTypeBox->addItems(Integra7Chorus::FilterTypeList());
    ui->ChorusFilterCutoffBox->addItems(Integra7Chorus::FilterFreqList());
    ui->ChorusPreDelayBox->addItems(Integra7Chorus::PreDelayList());
    ui->ChorusRateTypeBox->addItems(Integra7Chorus::RateTypeList());
    ui->ChorusHzRateBox->addItems(Integra7Chorus::RateHzList());
    ui->ChorusNoteRateBox->addItems(Integra7Chorus::NoteList());
    ui->ChorusGM2PreLPFBox->addItems(Integra7Chorus::GM2PreLPFList());

    ui->DelayLeftTypeBox->addItems(Integra7Chorus::DelayTypeList());
    ui->DelayLeftNoteBox->addItems(Integra7Chorus::NoteList());
    ui->DelayRightTypeBox->addItems(Integra7Chorus::DelayTypeList());
    ui->DelayRightNoteBox->addItems(Integra7Chorus::NoteList());
    ui->DelayCenterTypeBox->addItems(Integra7Chorus::DelayTypeList());
    ui->DelayCenterNoteBox->addItems(Integra7Chorus::NoteList());
    ui->DelayHFDampBox->addItems(Integra7Chorus::HFDumpList());

    ui->ReverbTypeBox->addItems(Integra7Reverb::TypeList());
    ui->ReverbOutputAssignBox->addItems(Integra7Device::OutputAssignList());
    ui->ReverbTimeBox->addItems(Integra7Reverb::TimeList());
    ui->ReverbGM2CharBox->addItems(Integra7Reverb::GM2CharacterList());

    ui->ChorusParams->setCurrentWidget(ui->ChorusEmptyPage);
    ui->ReverbParams->setCurrentWidget(ui->ReverbEmptyPage);

    ui->SysCtrl1SrcBox->addItems(Integra7Device::ControlSourceList());
    ui->SysCtrl2SrcBox->addItems(Integra7Device::ControlSourceList());
    ui->SysCtrl3SrcBox->addItems(Integra7Device::ControlSourceList());
    ui->SysCtrl4SrcBox->addItems(Integra7Device::ControlSourceList());

    ui->SystemControlSourceBox->addItems(Integra7SystemCommon::SystemStudioSetList());
    ui->SystemClockSourceBox->addItems(Integra7SystemCommon::SystemClockSourceList());
    ui->SystemTempoAssignSourceBox->addItems(Integra7SystemCommon::SystemStudioSetList());
    ui->StudioSetCtrlChBox->addItems(Integra7SystemCommon::MIDIChListOff());
    ui->SpkOutModeBox->addItems(Integra7SystemCommon::SpeakerPhonesList());
    ui->SoundModeBox->addItems(Integra7Setup::SoundModeLabels());

    /* ComboBoxes change value logic connections */
    QObject::connect(ui->Ch1TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch1TypeBox,ui->Ch1BankBox,ui->Ch1ToneBox);});

    QObject::connect(ui->Ch1BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch1TypeBox,ui->Ch1BankBox,ui->Ch1ToneBox);});

    QObject::connect(ui->Ch1ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(0,ui->Ch1ToneBox->currentIndex(),
                                                   ui->Ch1TypeBox,
                                                   ui->Ch1BankBox);});

    QObject::connect(ui->Ch2TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch2TypeBox,ui->Ch2BankBox,ui->Ch2ToneBox);});

    QObject::connect(ui->Ch2BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch2TypeBox,ui->Ch2BankBox,ui->Ch2ToneBox);});

    QObject::connect(ui->Ch2ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(1,ui->Ch2ToneBox->currentIndex(),
                                                   ui->Ch2TypeBox,
                                                   ui->Ch2BankBox);});

    QObject::connect(ui->Ch3TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch3TypeBox,ui->Ch3BankBox,ui->Ch3ToneBox);});

    QObject::connect(ui->Ch3BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch3TypeBox,ui->Ch3BankBox,ui->Ch3ToneBox);});

    QObject::connect(ui->Ch3ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(2,ui->Ch3ToneBox->currentIndex(),
                                                   ui->Ch3TypeBox,
                                                   ui->Ch3BankBox);});

    QObject::connect(ui->Ch4TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch4TypeBox,ui->Ch4BankBox,ui->Ch4ToneBox);});

    QObject::connect(ui->Ch4BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch4TypeBox,ui->Ch4BankBox,ui->Ch4ToneBox);});

    QObject::connect(ui->Ch4ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(3,ui->Ch4ToneBox->currentIndex(),
                                                   ui->Ch4TypeBox,
                                                   ui->Ch4BankBox);});

    QObject::connect(ui->Ch5TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch5TypeBox,ui->Ch5BankBox,ui->Ch5ToneBox);});

    QObject::connect(ui->Ch5BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch5TypeBox,ui->Ch5BankBox,ui->Ch5ToneBox);});

    QObject::connect(ui->Ch5ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(4,ui->Ch5ToneBox->currentIndex(),
                                                   ui->Ch5TypeBox,
                                                   ui->Ch5BankBox);});

    QObject::connect(ui->Ch6TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch6TypeBox,ui->Ch6BankBox,ui->Ch6ToneBox);});

    QObject::connect(ui->Ch6BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch6TypeBox,ui->Ch6BankBox,ui->Ch6ToneBox);});

    QObject::connect(ui->Ch6ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(5,ui->Ch6ToneBox->currentIndex(),
                                                   ui->Ch6TypeBox,
                                                   ui->Ch6BankBox);});

    QObject::connect(ui->Ch7TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch7TypeBox,ui->Ch7BankBox,ui->Ch7ToneBox);});

    QObject::connect(ui->Ch7BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch7TypeBox,ui->Ch7BankBox,ui->Ch7ToneBox);});

    QObject::connect(ui->Ch7ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(6,ui->Ch7ToneBox->currentIndex(),
                                                   ui->Ch7TypeBox,
                                                   ui->Ch7BankBox);});

    QObject::connect(ui->Ch8TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch8TypeBox,ui->Ch8BankBox,ui->Ch8ToneBox);});

    QObject::connect(ui->Ch8BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch8TypeBox,ui->Ch8BankBox,ui->Ch8ToneBox);});

    QObject::connect(ui->Ch8ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(7,ui->Ch8ToneBox->currentIndex(),
                                                   ui->Ch8TypeBox,
                                                   ui->Ch8BankBox);});

    QObject::connect(ui->Ch9TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch9TypeBox,ui->Ch9BankBox,ui->Ch9ToneBox);});

    QObject::connect(ui->Ch9BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch9TypeBox,ui->Ch9BankBox,ui->Ch9ToneBox);});

    QObject::connect(ui->Ch9ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(8,ui->Ch9ToneBox->currentIndex(),
                                                   ui->Ch9TypeBox,
                                                   ui->Ch9BankBox);});

    QObject::connect(ui->Ch10TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch10TypeBox,ui->Ch10BankBox,ui->Ch10ToneBox);});

    QObject::connect(ui->Ch10BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch10TypeBox,ui->Ch10BankBox,ui->Ch10ToneBox);});

    QObject::connect(ui->Ch10ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(9,ui->Ch10ToneBox->currentIndex(),
                                                   ui->Ch10TypeBox,
                                                   ui->Ch10BankBox);});

    QObject::connect(ui->Ch11TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch11TypeBox,ui->Ch11BankBox,ui->Ch11ToneBox);});

    QObject::connect(ui->Ch11BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch11TypeBox,ui->Ch11BankBox,ui->Ch11ToneBox);});

    QObject::connect(ui->Ch11ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(10,ui->Ch11ToneBox->currentIndex(),
                                                   ui->Ch11TypeBox,
                                                   ui->Ch11BankBox);});

    QObject::connect(ui->Ch12TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch12TypeBox,ui->Ch12BankBox,ui->Ch12ToneBox);});

    QObject::connect(ui->Ch12BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch12TypeBox,ui->Ch12BankBox,ui->Ch12ToneBox);});

    QObject::connect(ui->Ch12ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(11,ui->Ch12ToneBox->currentIndex(),
                                                   ui->Ch12TypeBox,
                                                   ui->Ch12BankBox);});

    QObject::connect(ui->Ch13TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch13TypeBox,ui->Ch13BankBox,ui->Ch13ToneBox);});

    QObject::connect(ui->Ch13BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch13TypeBox,ui->Ch13BankBox,ui->Ch13ToneBox);});

    QObject::connect(ui->Ch13ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(12,ui->Ch13ToneBox->currentIndex(),
                                                   ui->Ch13TypeBox,
                                                   ui->Ch13BankBox);});

    QObject::connect(ui->Ch14TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch14TypeBox,ui->Ch14BankBox,ui->Ch14ToneBox);});

    QObject::connect(ui->Ch14BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch14TypeBox,ui->Ch14BankBox,ui->Ch14ToneBox);});

    QObject::connect(ui->Ch14ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(13,ui->Ch14ToneBox->currentIndex(),
                                                   ui->Ch14TypeBox,
                                                   ui->Ch14BankBox);});

    QObject::connect(ui->Ch15TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch15TypeBox,ui->Ch15BankBox,ui->Ch15ToneBox);});

    QObject::connect(ui->Ch15BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch15TypeBox,ui->Ch15BankBox,ui->Ch15ToneBox);});

    QObject::connect(ui->Ch15ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(14,ui->Ch15ToneBox->currentIndex(),
                                                   ui->Ch15TypeBox,
                                                   ui->Ch15BankBox);});

    QObject::connect(ui->Ch16TypeBox,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch16TypeBox,ui->Ch16BankBox,ui->Ch16ToneBox);});

    QObject::connect(ui->Ch16BankBox,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch16TypeBox,ui->Ch16BankBox,ui->Ch16ToneBox);});

    QObject::connect(ui->Ch16ToneBox,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(15,ui->Ch16ToneBox->currentIndex(),
                                                   ui->Ch16TypeBox,
                                                   ui->Ch16BankBox);});

    QObject::connect(ui->Ch1TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch1TypeBox1,ui->Ch1BankBox1,ui->Ch1ToneBox1);});

    QObject::connect(ui->Ch1BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch1TypeBox1,ui->Ch1BankBox1,ui->Ch1ToneBox1);});

    QObject::connect(ui->Ch1ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(0,ui->Ch1ToneBox1->currentIndex(),
                                                   ui->Ch1TypeBox1,
                                                   ui->Ch1BankBox1);});

    QObject::connect(ui->Ch2TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch2TypeBox1,ui->Ch2BankBox1,ui->Ch2ToneBox1);});

    QObject::connect(ui->Ch2BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch2TypeBox1,ui->Ch2BankBox1,ui->Ch2ToneBox1);});

    QObject::connect(ui->Ch2ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(1,ui->Ch2ToneBox1->currentIndex(),
                                                   ui->Ch2TypeBox1,
                                                   ui->Ch2BankBox1);});

    QObject::connect(ui->Ch3TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch3TypeBox1,ui->Ch3BankBox1,ui->Ch3ToneBox1);});

    QObject::connect(ui->Ch3BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch3TypeBox1,ui->Ch3BankBox1,ui->Ch3ToneBox1);});

    QObject::connect(ui->Ch3ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(2,ui->Ch3ToneBox1->currentIndex(),
                                                   ui->Ch3TypeBox1,
                                                   ui->Ch3BankBox1);});

    QObject::connect(ui->Ch4TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch4TypeBox1,ui->Ch4BankBox1,ui->Ch4ToneBox1);});

    QObject::connect(ui->Ch4BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch4TypeBox1,ui->Ch4BankBox1,ui->Ch4ToneBox1);});

    QObject::connect(ui->Ch4ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(3,ui->Ch4ToneBox1->currentIndex(),
                                                   ui->Ch4TypeBox1,
                                                   ui->Ch4BankBox1);});

    QObject::connect(ui->Ch5TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch5TypeBox1,ui->Ch5BankBox1,ui->Ch5ToneBox1);});

    QObject::connect(ui->Ch5BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch5TypeBox1,ui->Ch5BankBox1,ui->Ch5ToneBox1);});

    QObject::connect(ui->Ch5ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(4,ui->Ch5ToneBox1->currentIndex(),
                                                   ui->Ch5TypeBox1,
                                                   ui->Ch5BankBox1);});

    QObject::connect(ui->Ch6TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch6TypeBox1,ui->Ch6BankBox1,ui->Ch6ToneBox1);});

    QObject::connect(ui->Ch6BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch6TypeBox1,ui->Ch6BankBox1,ui->Ch6ToneBox1);});

    QObject::connect(ui->Ch6ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(5,ui->Ch6ToneBox1->currentIndex(),
                                                   ui->Ch6TypeBox1,
                                                   ui->Ch6BankBox1);});

    QObject::connect(ui->Ch7TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch7TypeBox1,ui->Ch7BankBox1,ui->Ch7ToneBox1);});

    QObject::connect(ui->Ch7BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch7TypeBox1,ui->Ch7BankBox1,ui->Ch7ToneBox1);});

    QObject::connect(ui->Ch7ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(6,ui->Ch7ToneBox1->currentIndex(),
                                                   ui->Ch7TypeBox1,
                                                   ui->Ch7BankBox1);});

    QObject::connect(ui->Ch8TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch8TypeBox1,ui->Ch8BankBox1,ui->Ch8ToneBox1);});

    QObject::connect(ui->Ch8BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch8TypeBox1,ui->Ch8BankBox1,ui->Ch8ToneBox1);});

    QObject::connect(ui->Ch8ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(7,ui->Ch8ToneBox1->currentIndex(),
                                                   ui->Ch8TypeBox1,
                                                   ui->Ch8BankBox1);});

    QObject::connect(ui->Ch9TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch9TypeBox1,ui->Ch9BankBox1,ui->Ch9ToneBox1);});

    QObject::connect(ui->Ch9BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch9TypeBox1,ui->Ch9BankBox1,ui->Ch9ToneBox1);});

    QObject::connect(ui->Ch9ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(8,ui->Ch9ToneBox1->currentIndex(),
                                                   ui->Ch9TypeBox1,
                                                   ui->Ch9BankBox1);});

    QObject::connect(ui->Ch10TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch10TypeBox1,ui->Ch10BankBox1,ui->Ch10ToneBox1);});

    QObject::connect(ui->Ch10BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch10TypeBox1,ui->Ch10BankBox1,ui->Ch10ToneBox1);});

    QObject::connect(ui->Ch10ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(9,ui->Ch10ToneBox1->currentIndex(),
                                                   ui->Ch10TypeBox1,
                                                   ui->Ch10BankBox1);});

    QObject::connect(ui->Ch11TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch11TypeBox1,ui->Ch11BankBox1,ui->Ch11ToneBox1);});

    QObject::connect(ui->Ch11BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch11TypeBox1,ui->Ch11BankBox1,ui->Ch11ToneBox1);});

    QObject::connect(ui->Ch11ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(10,ui->Ch11ToneBox1->currentIndex(),
                                                   ui->Ch11TypeBox1,
                                                   ui->Ch11BankBox1);});

    QObject::connect(ui->Ch12TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch12TypeBox1,ui->Ch12BankBox1,ui->Ch12ToneBox1);});

    QObject::connect(ui->Ch12BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch12TypeBox1,ui->Ch12BankBox1,ui->Ch12ToneBox1);});

    QObject::connect(ui->Ch12ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(11,ui->Ch12ToneBox1->currentIndex(),
                                                   ui->Ch12TypeBox1,
                                                   ui->Ch12BankBox1);});

    QObject::connect(ui->Ch13TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch13TypeBox1,ui->Ch13BankBox1,ui->Ch13ToneBox1);});

    QObject::connect(ui->Ch13BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch13TypeBox1,ui->Ch13BankBox1,ui->Ch13ToneBox1);});

    QObject::connect(ui->Ch13ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(12,ui->Ch13ToneBox1->currentIndex(),
                                                   ui->Ch13TypeBox1,
                                                   ui->Ch13BankBox1);});

    QObject::connect(ui->Ch14TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch14TypeBox1,ui->Ch14BankBox1,ui->Ch14ToneBox1);});

    QObject::connect(ui->Ch14BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch14TypeBox1,ui->Ch14BankBox1,ui->Ch14ToneBox1);});

    QObject::connect(ui->Ch14ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(13,ui->Ch14ToneBox1->currentIndex(),
                                                   ui->Ch14TypeBox1,
                                                   ui->Ch14BankBox1);});

    QObject::connect(ui->Ch15TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch15TypeBox1,ui->Ch15BankBox1,ui->Ch15ToneBox1);});

    QObject::connect(ui->Ch15BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch15TypeBox1,ui->Ch15BankBox1,ui->Ch15ToneBox1);});

    QObject::connect(ui->Ch15ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(14,ui->Ch15ToneBox1->currentIndex(),
                                                   ui->Ch15TypeBox1,
                                                   ui->Ch15BankBox1);});

    QObject::connect(ui->Ch16TypeBox1,&QComboBox::currentIndexChanged,this,
                     [this](){TypeBoxChangeLogic(ui->Ch16TypeBox1,ui->Ch16BankBox1,ui->Ch16ToneBox1);});

    QObject::connect(ui->Ch16BankBox1,&QComboBox::currentIndexChanged,this,
                     [this](){BankBoxChangeLogic(ui->Ch16TypeBox1,ui->Ch16BankBox1,ui->Ch16ToneBox1);});

    QObject::connect(ui->Ch16ToneBox1,&QComboBox::currentIndexChanged,this,
                     [this](){ToneBoxChangeLogic(15,ui->Ch16ToneBox1->currentIndex(),
                                                   ui->Ch16TypeBox1,
                                                   ui->Ch16BankBox1);});

    /* Setup MIDI Engine */
    pMidiEngine = new MidiEngine();
    pMidiEngine->Init();

    if (pMidiEngine->IsInitialized())
    {
        ui->MidiPortBox->addItems(pMidiEngine->getSeqPortNames());
        ui->statusbar->showMessage(QString("Ready!"));
    } else {
        ui->statusbar->showMessage(QString("MIDI Engine failure!"));
    }

    /* Setup INTEGRA7 Device */
    pI7d = new Integra7Device(this, pMidiEngine);
    ui->DeviceIdBox->addItems(Integra7Device::DeviceIdList());

    QObject::connect(pMidiEngine->pMidiInputThread,&MidiInputThread::dataReady,
                     pI7d,&Integra7Device::ReceiveIntegraSysEx);

    pMidiEngine->pMidiInputThread->start();

    QObject::connect(ui->StudioSetBox,&QComboBox::currentIndexChanged,
                     pI7d->Setup,&Integra7Setup::setStudioSet_PC);

    QObject::connect(ui->DeviceIdBox,&QComboBox::currentIndexChanged,
                     pI7d,&Integra7Device::setDeviceId);

    QObject::connect(ui->MidiMsgDelayBox,&QSpinBox::valueChanged,
                     pI7d,&Integra7Device::setMsgDelay);

    QObject::connect(ui->PreviewBtn,&QAbstractButton::clicked,
                     this,&integra7MainWindow::SelectPreview);

    QObject::connect(ui->ReadBtn,&QAbstractButton::clicked,
                     this,&integra7MainWindow::BulkDumpRequest);

    QObject::connect(ui->Ch1TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[0],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch2TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[1],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch3TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[2],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch4TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[3],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch5TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[4],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch6TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[5],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch7TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[6],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch8TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[7],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch9TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[8],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch10TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[9],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch11TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[10],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch12TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[11],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch13TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[12],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch14TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[13],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch15TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[14],&Integra7Tone::setToneType);

    QObject::connect(ui->Ch16TypeBox,&QComboBox::currentTextChanged,
                     pI7d->Tones[15],&Integra7Tone::setToneType);

    /* Master EQ Connections */
    QObject::connect(ui->MEQSwBtn,&QPushButton::toggled,
                     pI7d->StudioSetCommon,&Integra7StudioSetCommon::setMasterEQSwitch);

    QObject::connect(ui->MEQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->MasterEQ,&Integra7MasterEQ::setEQLowFreq);

    QObject::connect(ui->MEQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->MasterEQ,&Integra7MasterEQ::setEQLowGain);

    QObject::connect(ui->MEQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->MasterEQ,&Integra7MasterEQ::setEQMidFreq);

    QObject::connect(ui->MEQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->MasterEQ,&Integra7MasterEQ::setEQMidGain);

    QObject::connect(ui->MEQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->MasterEQ,&Integra7MasterEQ::setEQMidQ);

    QObject::connect(ui->MEQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->MasterEQ,&Integra7MasterEQ::setEQHighFreq);

    QObject::connect(ui->MEQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->MasterEQ,&Integra7MasterEQ::setEQHighGain);


    /* Part View Card Levels connections */
    QObject::connect(ui->Ch1LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch1PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch1ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch1ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch1MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch2LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch2PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch2ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch2ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch2MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch3LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch3PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch3ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch3ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch3MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch4LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch4PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch4ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch4ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch4MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch5LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch5PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch5ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch5ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch5MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch6LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch6PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch6ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch6ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch6MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch7LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch7PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch7ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch7ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch7MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch8LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch8PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch8ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch8ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch8MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch9LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch9PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch9ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch9ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch9MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch10LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch10PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch10ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch10ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch10MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch11LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch11PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch11ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch11ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch11MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch12LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch12PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch12ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch12ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch12MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch13LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch13PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch13ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch13ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch13MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch14LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch14PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch14ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch14ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch14MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch15LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch15PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch15ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch15ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch15MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch16LevelBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch16PanBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch16ChorusBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch16ReverbBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch16MuteBtn,&QPushButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->ExMuteBtn,&QPushButton::toggled,
                     pI7d->StudioSetCommon,&Integra7StudioSetCommon::setExtPartMuteSwitch);

    QObject::connect(ui->ExLevelBox,&QSpinBox::valueChanged,
                     pI7d->StudioSetCommon,&Integra7StudioSetCommon::setExtPartLevel);

    QObject::connect(ui->ExChorusBox,&QSpinBox::valueChanged,
                     pI7d->StudioSetCommon,&Integra7StudioSetCommon::setExtPartChorusSendLevel);

    QObject::connect(ui->ExReverbBox,&QSpinBox::valueChanged,
                     pI7d->StudioSetCommon,&Integra7StudioSetCommon::setExtPartReverbSendLevel);

    QObject::connect(ui->Ch1OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[0],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch1RxBtn,&QPushButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch1RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[0],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch1MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[0],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch1LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[0],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch2OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[1],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch2RxBtn,&QPushButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch2RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[1],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch2MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[1],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch2LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[1],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch3OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[2],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch3RxBtn,&QPushButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch3RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[2],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch3MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[2],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch3LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[2],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch4OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[3],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch4RxBtn,&QPushButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch4RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[3],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch4MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[3],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch4LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[3],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch5OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[4],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch5RxBtn,&QPushButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch5RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[4],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch5MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[4],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch5LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[4],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch6OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[5],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch6RxBtn,&QPushButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch6RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[5],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch6MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[5],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch6LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[5],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch7OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[6],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch7RxBtn,&QPushButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch7RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[6],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch7MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[6],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch7LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[6],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch8OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[7],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch8RxBtn,&QPushButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch8RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[7],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch8MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[7],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch8LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[7],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch9OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[8],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch9RxBtn,&QPushButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch9RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[8],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch9MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[8],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch9LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[8],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch10OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[9],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch10RxBtn,&QPushButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch10RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[9],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch10MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[9],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch10LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[9],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch11OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[10],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch11RxBtn,&QPushButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch11RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[10],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch11MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[10],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch11LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[10],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch12OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[11],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch12RxBtn,&QPushButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch12RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[11],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch12MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[11],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch12LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[11],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch13OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[12],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch13RxBtn,&QPushButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch13RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[12],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch13MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[12],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch13LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[12],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch14OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[13],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch14RxBtn,&QPushButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch14RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[13],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch14MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[13],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch14LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[13],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch15OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[14],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch15RxBtn,&QPushButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch15RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[14],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch15MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[14],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch15LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[14],&Integra7Part::setPartLegatoSwitch);

    QObject::connect(ui->Ch16OutputBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[15],&Integra7Part::setPartOutputAssign);

    QObject::connect(ui->Ch16RxBtn,&QPushButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceiveSwitch);

    QObject::connect(ui->Ch16RxChBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[15],&Integra7Part::setReceiveChannel);

    QObject::connect(ui->Ch16MonoPolyBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[15],&Integra7Part::setPartMonoPoly);

    QObject::connect(ui->Ch16LegatoBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[15],&Integra7Part::setPartLegatoSwitch);

    /* Part EQ connections */
    QObject::connect(ui->Ch1EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[0],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch1EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[0],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch1EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[0],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch1EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[0],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch1EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[0],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch1EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[0],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch1EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[0],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch1EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[0],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch2EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[1],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch2EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[1],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch2EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[1],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch2EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[1],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch2EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[1],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch2EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[1],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch2EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[1],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch2EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[1],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch3EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[2],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch3EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[2],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch3EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[2],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch3EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[2],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch3EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[2],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch3EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[2],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch3EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[2],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch3EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[2],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch4EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[3],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch4EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[3],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch4EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[3],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch4EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[3],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch4EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[3],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch4EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[3],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch4EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[3],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch4EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[3],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch5EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[4],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch5EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[4],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch5EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[4],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch5EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[4],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch5EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[4],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch5EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[4],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch5EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[4],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch5EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[4],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch6EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[5],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch6EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[5],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch6EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[5],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch6EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[5],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch6EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[5],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch6EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[5],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch6EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[5],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch6EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[5],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch7EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[6],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch7EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[6],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch7EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[6],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch7EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[6],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch7EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[6],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch7EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[6],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch7EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[6],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch7EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[6],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch8EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[7],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch8EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[7],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch8EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[7],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch8EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[7],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch8EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[7],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch8EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[7],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch8EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[7],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch8EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[7],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch9EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[8],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch9EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[8],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch9EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[8],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch9EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[8],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch9EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[8],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch9EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[8],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch9EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[8],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch9EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[8],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch10EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[9],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch10EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[9],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch10EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[9],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch10EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[9],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch10EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[9],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch10EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[9],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch10EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[9],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch10EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[9],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch11EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[10],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch11EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[10],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch11EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[10],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch11EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[10],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch11EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[10],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch11EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[10],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch11EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[10],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch11EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[10],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch12EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[11],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch12EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[11],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch12EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[11],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch12EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[11],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch12EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[11],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch12EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[11],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch12EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[11],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch12EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[11],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch13EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[12],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch13EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[12],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch13EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[12],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch13EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[12],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch13EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[12],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch13EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[12],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch13EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[12],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch13EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[12],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch14EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[13],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch14EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[13],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch14EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[13],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch14EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[13],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch14EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[13],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch14EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[13],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch14EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[13],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch14EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[13],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch15EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[14],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch15EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[14],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch15EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[14],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch15EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[14],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch15EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[14],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch15EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[14],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch15EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[14],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch15EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[14],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch16EQSwBtn,&QPushButton::toggled,
                     pI7d->PartsEQ[15],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch16EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[15],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch16EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[15],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch16EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[15],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch16EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[15],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch16EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[15],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch16EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->PartsEQ[15],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch16EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->PartsEQ[15],&Integra7PartEQ::setEQHighGain);

    /* Part Keyboard Connections */
    QObject::connect(ui->Ch1KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch1KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch1KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch1KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch1VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch1VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch1VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch1VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch1VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch2KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch2KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch2KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch2KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch2VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch2VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch2VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch2VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch2VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch3KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch3KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch3KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch3KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch3VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch3VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch3VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch3VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch3VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch4KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch4KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch4KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch4KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch4VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch4VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch4VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch4VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch4VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch5KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch5KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch5KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch5KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch5VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch5VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch5VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch5VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch5VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch6KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch6KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch6KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch6KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch6VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch6VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch6VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch6VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch6VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch7KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch7KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch7KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch7KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch7VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch7VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch7VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch7VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch7VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch8KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch8KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch8KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch8KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch8VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch8VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch8VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch8VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch8VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch9KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch9KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch9KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch9KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch9VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch9VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch9VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch9VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch9VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch10KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch10KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch10KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch10KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch10VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch10VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch10VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch10VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch10VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch11KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch11KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch11KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch11KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch11VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch11VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch11VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch11VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch11VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch12KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch12KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch12KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch12KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch12VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch12VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch12VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch12VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch12VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch13KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch13KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch13KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch13KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch13VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch13VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch13VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch13VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch13VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch14KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch14KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch14KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch14KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch14VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch14VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch14VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch14VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch14VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch15KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch15KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch15KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch15KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch15VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch15VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch15VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch15VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch15VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch16KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch16KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch16KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch16KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch16VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch16VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch16VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch16VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch16VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setPartVelocitySensOffset);

    /* Create Part Pitch connections */
    QObject::connect(ui->Ch1OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch1CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch1FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch1BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch1PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[0],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch1PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[0],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch2OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch2CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch2FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch2BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch2PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[1],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch2PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[1],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch3OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch3CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch3FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch3BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch3PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[2],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch3PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[2],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch4OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch4CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch4FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch4BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch4PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[3],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch4PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[3],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch5OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch5CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch5FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch5BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch5PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[4],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch5PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[4],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch6OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch6CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch6FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch6BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch6PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[5],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch6PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[5],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch7OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch7CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch7FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch7BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch7PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[6],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch7PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[6],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch8OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch8CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch8FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch8BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch8PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[7],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch8PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[7],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch9OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch9CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch9FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch9BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch9PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[8],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch9PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[8],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch10OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch10CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch10FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch10BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch10PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[9],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch10PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[9],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch11OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch11CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch11FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch11BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch11PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[10],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch11PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[10],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch12OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch12CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch12FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch12BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch12PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[11],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch12PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[11],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch13OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch13CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch13FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch13BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch13PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[12],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch13PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[12],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch14OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch14CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch14FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch14BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch14PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[13],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch14PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[13],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch15OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch15CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch15FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch15BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch15PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[14],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch15PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[14],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch16OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch16CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch16FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch16BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch16PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->Parts[15],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch16PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->Parts[15],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch1RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch1RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch1RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch1RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch1RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch1RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch1RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch1RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch1RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch1RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[0],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch2RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch2RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch2RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch2RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch2RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch2RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch2RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch2RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch2RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch2RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[1],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch3RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch3RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch3RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch3RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch3RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch3RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch3RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch3RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch3RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch3RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[2],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch4RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch4RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch4RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch4RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch4RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch4RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch4RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch4RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch4RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch4RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[3],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch5RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch5RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch5RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch5RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch5RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch5RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch5RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch5RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch5RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch5RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[4],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch6RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch6RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch6RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch6RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch6RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch6RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch6RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch6RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch6RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch6RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[5],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch7RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch7RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch7RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch7RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch7RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch7RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch7RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch7RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch7RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch7RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[6],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch8RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch8RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch8RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch8RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch8RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch8RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch8RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch8RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch8RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch8RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[7],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch9RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch9RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch9RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch9RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch9RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch9RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch9RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch9RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch9RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch9RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[8],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch10RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch10RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch10RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch10RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch10RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch10RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch10RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch10RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch10RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch10RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[9],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch11RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch11RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch11RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch11RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch11RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch11RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch11RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch11RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch11RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch11RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[10],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch12RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch12RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch12RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch12RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch12RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch12RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch12RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch12RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch12RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch12RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[11],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch13RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch13RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch13RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch13RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch13RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch13RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch13RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch13RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch13RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch13RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[12],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch14RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch14RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch14RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch14RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch14RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch14RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch14RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch14RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch14RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch14RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[13],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch15RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch15RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch15RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch15RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch15RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch15RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch15RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch15RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch15RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch15RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[14],&Integra7Part::setReceiveHold);

    QObject::connect(ui->Ch16RPCBtn,&QAbstractButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceiveProgramChange);

    QObject::connect(ui->Ch16RBSBtn,&QAbstractButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceiveBankSelect);

    QObject::connect(ui->Ch16RPBBtn,&QAbstractButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceivePitchBend);

    QObject::connect(ui->Ch16RPPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceivePolyphonicKeyPressure);

    QObject::connect(ui->Ch16RCPBtn,&QAbstractButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceiveChannelPressure);

    QObject::connect(ui->Ch16RModBtn,&QAbstractButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceiveModulation);

    QObject::connect(ui->Ch16RVolBtn,&QAbstractButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceiveVolume);

    QObject::connect(ui->Ch16RPanBtn,&QAbstractButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceivePan);

    QObject::connect(ui->Ch16RExpBtn,&QAbstractButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceiveExpression);

    QObject::connect(ui->Ch16RHoldBtn,&QAbstractButton::toggled,
                     pI7d->Parts[15],&Integra7Part::setReceiveHold);

    /* Chorus and Reverb connections */
    QObject::connect(ui->ChorusSwBtn,&QAbstractButton::toggled,
                     pI7d->StudioSetCommon,&Integra7StudioSetCommon::setChorusSwitch);

    QObject::connect(ui->ChorusTypeBox,&QComboBox::currentTextChanged,
                     this,&integra7MainWindow::ShowChorusParams);

    QObject::connect(ui->ChorusTypeBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusType);

    QObject::connect(ui->ChorusLvlBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusLevel);

    QObject::connect(ui->ChorusOutSelectBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusOutputSelect);

    QObject::connect(ui->ChorusFilterTypeBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusFilterType);

    QObject::connect(ui->ChorusFilterCutoffBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusCutoffFreq);

    QObject::connect(ui->ChorusPreDelayBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusPreDelay);

    QObject::connect(ui->ChorusRateTypeBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusRateType);

    QObject::connect(ui->ChorusHzRateBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusRateHz);

    QObject::connect(ui->ChorusNoteRateBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusRateNote);

    QObject::connect(ui->ChorusDepthBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusDepth);

    QObject::connect(ui->ChorusPhaseBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusPhase);

    QObject::connect(ui->ChorusFbBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setChorusFeedback);

    QObject::connect(ui->DelayLeftTypeBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayDelayLeft);

    QObject::connect(ui->DelayLeftBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayDelayLeftMS);

    QObject::connect(ui->DelayLeftNoteBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayDelayLeftNote);

    QObject::connect(ui->DelayRightTypeBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayDelayRight);

    QObject::connect(ui->DelayRightBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayDelayRightMS);

    QObject::connect(ui->DelayRightNoteBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayDelayRightNote);

    QObject::connect(ui->DelayCenterTypeBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayDelayCenter);

    QObject::connect(ui->DelayCenterBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayDelayCenterMS);

    QObject::connect(ui->DelayCenterNoteBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayDelayCenterNote);

    QObject::connect(ui->DelayFBBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayFeedback);

    QObject::connect(ui->DelayHFDampBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayHFDamp);

    QObject::connect(ui->DelayLeftLvlBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayLeftLevel);

    QObject::connect(ui->DelayRightLvlBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayRightLevel);

    QObject::connect(ui->DelayCenterLvlBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setDelayCenterLevel);

    QObject::connect(ui->ChorusGM2PreLPFBox,&QComboBox::currentIndexChanged,
                     pI7d->Chorus,&Integra7Chorus::setGM2ChorusPreLPF);

    QObject::connect(ui->ChorusGM2LevelBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setGM2ChorusLevel);

    QObject::connect(ui->ChorusGM2FBBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setGM2ChorusFeedback);

    QObject::connect(ui->ChorusGM2DelayBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setGM2ChorusDelay);

    QObject::connect(ui->ChorusGM2RateBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setGM2ChorusRate);

    QObject::connect(ui->ChorusGM2DepthBox,&QSpinBox::valueChanged,
                     pI7d->Chorus,&Integra7Chorus::setGM2ChorusDepth);

    /*************************************************************/

    QObject::connect(ui->ReverbSwBtn,&QAbstractButton::toggled,
                     pI7d->StudioSetCommon,&Integra7StudioSetCommon::setReverbSwitch);

    QObject::connect(ui->ReverbTypeBox,&QComboBox::currentIndexChanged,
                     this,&integra7MainWindow::ShowReverbParams);

    QObject::connect(ui->ReverbTypeBox,&QComboBox::currentIndexChanged,
                     pI7d->Reverb,&Integra7Reverb::setType);

    QObject::connect(ui->ReverbLevelBox,&QSpinBox::valueChanged,
                     pI7d->Reverb,&Integra7Reverb::setLevel);

    QObject::connect(ui->ReverbOutputAssignBox,&QComboBox::currentIndexChanged,
                     pI7d->Reverb,&Integra7Reverb::setOutputAssign);

    QObject::connect(ui->ReverbPreDelayBox,&QSpinBox::valueChanged,
                     pI7d->Reverb,&Integra7Reverb::setPreDelay);

    QObject::connect(ui->ReverbTimeBox,&QComboBox::currentIndexChanged,
                     pI7d->Reverb,&Integra7Reverb::setTime);

    QObject::connect(ui->ReverbDensityBox,&QSpinBox::valueChanged,
                     pI7d->Reverb,&Integra7Reverb::setDensity);

    QObject::connect(ui->ReverbDiffusionBox,&QSpinBox::valueChanged,
                     pI7d->Reverb,&Integra7Reverb::setDiffusion);

    QObject::connect(ui->ReverbLFDampBox,&QSpinBox::valueChanged,
                     pI7d->Reverb,&Integra7Reverb::setLFDamp);

    QObject::connect(ui->ReverbHFDampBox,&QSpinBox::valueChanged,
                     pI7d->Reverb,&Integra7Reverb::setHFDamp);

    QObject::connect(ui->ReverbSpreadBox,&QSpinBox::valueChanged,
                     pI7d->Reverb,&Integra7Reverb::setSpread);

    QObject::connect(ui->ReverbToneBox,&QSpinBox::valueChanged,
                     pI7d->Reverb,&Integra7Reverb::setTone);

    QObject::connect(ui->ReverbGM2CharBox,&QComboBox::currentIndexChanged,
                     pI7d->Reverb,&Integra7Reverb::setGM2Character);

    QObject::connect(ui->ReverbGM2TimeBox,&QSpinBox::valueChanged,
                     pI7d->Reverb,&Integra7Reverb::setGM2Time);

    /* System Common connections */
    QObject::connect(ui->MasterLevelBox,&QSpinBox::valueChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setMasterLevel);

    QObject::connect(ui->MasterTuneSld,&QSlider::valueChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setMasterTune);

    QObject::connect(ui->MasterTuneBoxC,&QDoubleSpinBox::valueChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setMasterTuneCents);

    QObject::connect(ui->MasterKeyShiftBox,&QSpinBox::valueChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setMasterKeyShift);

    QObject::connect(ui->ScaleTuneSwitchBtn,&QAbstractButton::toggled,
                     pI7d->SystemCommon,&Integra7SystemCommon::setScaleTuneSwitch);

    QObject::connect(ui->SysCtrl1SrcBox,&QComboBox::currentIndexChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setSystemControl1Source);

    QObject::connect(ui->SysCtrl2SrcBox,&QComboBox::currentIndexChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setSystemControl2Source);

    QObject::connect(ui->SysCtrl3SrcBox,&QComboBox::currentIndexChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setSystemControl3Source);

    QObject::connect(ui->SysCtrl4SrcBox,&QComboBox::currentIndexChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setSystemControl4Source);

    QObject::connect(ui->SystemControlSourceBox,&QComboBox::currentIndexChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setControlSource);

    QObject::connect(ui->SystemClockSourceBox,&QComboBox::currentIndexChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setSystemClockSource);

    QObject::connect(ui->SystemTempoBox,&QSpinBox::valueChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setSystemTempo);

    QObject::connect(ui->SystemTempoAssignSourceBox,&QComboBox::currentIndexChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setTempoAssignSource);

    QObject::connect(ui->SysRcvPrgChangeBtn,&QAbstractButton::toggled,
                     pI7d->SystemCommon,&Integra7SystemCommon::setReceiveProgramChange);

    QObject::connect(ui->SysRcvBankSelBtn,&QAbstractButton::toggled,
                     pI7d->SystemCommon,&Integra7SystemCommon::setReceiveBankSelect);

    QObject::connect(ui->StudioSetCtrlChBox,&QComboBox::currentIndexChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::setStudioSetControlChannel);

    QObject::connect(ui->CenterSpkSwBtn,&QAbstractButton::toggled,
                     pI7d->SystemCommon,&Integra7SystemCommon::set51CHCenterSpeakerSwitch);

    QObject::connect(ui->SubwooferSpkSwBtn,&QAbstractButton::toggled,
                     pI7d->SystemCommon,&Integra7SystemCommon::set51CHSubWooferSwitch);

    QObject::connect(ui->SpkOutModeBox,&QComboBox::currentIndexChanged,
                     pI7d->SystemCommon,&Integra7SystemCommon::set2CHOutputMode);

    QObject::connect(ui->SoundModeBox,&QComboBox::currentIndexChanged,
                     pI7d->Setup,&Integra7Setup::setSoundMode);

    /* Reverse connections */
    for (int i=0;i<16;i++) {
        QObject::connect(pI7d->Parts[i],&Integra7Part::ToneBankProgram,
                         this,&integra7MainWindow::DisplayPartTonePreset);
    }

    QObject::connect(pI7d->StudioSetCommon,&Integra7StudioSetCommon::StudioSetName,
                     this,&integra7MainWindow::UpdateStudioSetName);

    QObject::connect(pI7d->StudioSetCommon,&Integra7StudioSetCommon::MasterEQSwitch,
                     ui->MEQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->MasterEQ,&Integra7MasterEQ::EQLowFreq,
                     ui->MEQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->MasterEQ,&Integra7MasterEQ::EQLowGain,
                     ui->MEQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->MasterEQ,&Integra7MasterEQ::EQMidFreq,
                     ui->MEQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->MasterEQ,&Integra7MasterEQ::EQMidGain,
                     ui->MEQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->MasterEQ,&Integra7MasterEQ::EQMidQ,
                     ui->MEQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->MasterEQ,&Integra7MasterEQ::EQHighFreq,
                     ui->MEQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->MasterEQ,&Integra7MasterEQ::EQHighGain,
                     ui->MEQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartLevel,
                     ui->Ch1LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartPan,
                     ui->Ch1PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartChorusSendLevel,
                     ui->Ch1ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartReverbSendLevel,
                     ui->Ch1ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::MuteSwitch,
                     ui->Ch1MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartLevel,
                     ui->Ch2LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartPan,
                     ui->Ch2PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartChorusSendLevel,
                     ui->Ch2ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartReverbSendLevel,
                     ui->Ch2ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::MuteSwitch,
                     ui->Ch2MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartLevel,
                     ui->Ch3LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartPan,
                     ui->Ch3PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartChorusSendLevel,
                     ui->Ch3ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartReverbSendLevel,
                     ui->Ch3ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::MuteSwitch,
                     ui->Ch3MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartLevel,
                     ui->Ch4LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartPan,
                     ui->Ch4PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartChorusSendLevel,
                     ui->Ch4ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartReverbSendLevel,
                     ui->Ch4ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::MuteSwitch,
                     ui->Ch4MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartLevel,
                     ui->Ch5LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartPan,
                     ui->Ch5PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartChorusSendLevel,
                     ui->Ch5ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartReverbSendLevel,
                     ui->Ch5ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::MuteSwitch,
                     ui->Ch5MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartLevel,
                     ui->Ch6LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartPan,
                     ui->Ch6PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartChorusSendLevel,
                     ui->Ch6ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartReverbSendLevel,
                     ui->Ch6ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::MuteSwitch,
                     ui->Ch6MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartLevel,
                     ui->Ch7LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartPan,
                     ui->Ch7PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartChorusSendLevel,
                     ui->Ch7ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartReverbSendLevel,
                     ui->Ch7ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::MuteSwitch,
                     ui->Ch7MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartLevel,
                     ui->Ch8LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartPan,
                     ui->Ch8PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartChorusSendLevel,
                     ui->Ch8ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartReverbSendLevel,
                     ui->Ch8ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::MuteSwitch,
                     ui->Ch8MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartLevel,
                     ui->Ch9LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartPan,
                     ui->Ch9PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartChorusSendLevel,
                     ui->Ch9ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartReverbSendLevel,
                     ui->Ch9ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::MuteSwitch,
                     ui->Ch9MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartLevel,
                     ui->Ch10LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartPan,
                     ui->Ch10PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartChorusSendLevel,
                     ui->Ch10ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartReverbSendLevel,
                     ui->Ch10ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::MuteSwitch,
                     ui->Ch10MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartLevel,
                     ui->Ch11LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartPan,
                     ui->Ch11PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartChorusSendLevel,
                     ui->Ch11ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartReverbSendLevel,
                     ui->Ch11ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::MuteSwitch,
                     ui->Ch11MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartLevel,
                     ui->Ch12LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartPan,
                     ui->Ch12PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartChorusSendLevel,
                     ui->Ch12ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartReverbSendLevel,
                     ui->Ch12ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::MuteSwitch,
                     ui->Ch12MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartLevel,
                     ui->Ch13LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartPan,
                     ui->Ch13PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartChorusSendLevel,
                     ui->Ch13ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartReverbSendLevel,
                     ui->Ch13ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::MuteSwitch,
                     ui->Ch13MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartLevel,
                     ui->Ch14LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartPan,
                     ui->Ch14PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartChorusSendLevel,
                     ui->Ch14ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartReverbSendLevel,
                     ui->Ch14ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::MuteSwitch,
                     ui->Ch14MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartLevel,
                     ui->Ch15LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartPan,
                     ui->Ch15PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartChorusSendLevel,
                     ui->Ch15ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartReverbSendLevel,
                     ui->Ch15ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::MuteSwitch,
                     ui->Ch15MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartLevel,
                     ui->Ch16LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartPan,
                     ui->Ch16PanBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartChorusSendLevel,
                     ui->Ch16ChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartReverbSendLevel,
                     ui->Ch16ReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::MuteSwitch,
                     ui->Ch16MuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->StudioSetCommon,&Integra7StudioSetCommon::ExtPartMuteSwitch,
                     ui->ExMuteBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->StudioSetCommon,&Integra7StudioSetCommon::ExtPartLevel,
                     ui->ExLevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->StudioSetCommon,&Integra7StudioSetCommon::ExtPartChorusSendLevel,
                     ui->ExChorusBox,&QSpinBox::setValue);

    QObject::connect(pI7d->StudioSetCommon,&Integra7StudioSetCommon::ExtPartReverbSendLevel,
                     ui->ExReverbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartOutputAssign,
                     ui->Ch1OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceiveSwitch,
                     ui->Ch1RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceiveChannel,
                     ui->Ch1RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartMonoPoly,
                     ui->Ch1MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartLegatoSwitch,
                     ui->Ch1LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartOutputAssign,
                     ui->Ch2OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceiveSwitch,
                     ui->Ch2RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceiveChannel,
                     ui->Ch2RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartMonoPoly,
                     ui->Ch2MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartLegatoSwitch,
                     ui->Ch2LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartOutputAssign,
                     ui->Ch3OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceiveSwitch,
                     ui->Ch3RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceiveChannel,
                     ui->Ch3RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartMonoPoly,
                     ui->Ch3MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartLegatoSwitch,
                     ui->Ch3LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartOutputAssign,
                     ui->Ch4OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceiveSwitch,
                     ui->Ch4RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceiveChannel,
                     ui->Ch4RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartMonoPoly,
                     ui->Ch4MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartLegatoSwitch,
                     ui->Ch4LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartOutputAssign,
                     ui->Ch5OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceiveSwitch,
                     ui->Ch5RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceiveChannel,
                     ui->Ch5RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartMonoPoly,
                     ui->Ch5MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartLegatoSwitch,
                     ui->Ch5LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartOutputAssign,
                     ui->Ch6OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceiveSwitch,
                     ui->Ch6RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceiveChannel,
                     ui->Ch6RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartMonoPoly,
                     ui->Ch6MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartLegatoSwitch,
                     ui->Ch6LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartOutputAssign,
                     ui->Ch7OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceiveSwitch,
                     ui->Ch7RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceiveChannel,
                     ui->Ch7RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartMonoPoly,
                     ui->Ch7MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartLegatoSwitch,
                     ui->Ch7LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartOutputAssign,
                     ui->Ch8OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceiveSwitch,
                     ui->Ch8RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceiveChannel,
                     ui->Ch8RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartMonoPoly,
                     ui->Ch8MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartLegatoSwitch,
                     ui->Ch8LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartOutputAssign,
                     ui->Ch9OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceiveSwitch,
                     ui->Ch9RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceiveChannel,
                     ui->Ch9RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartMonoPoly,
                     ui->Ch9MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartLegatoSwitch,
                     ui->Ch9LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartOutputAssign,
                     ui->Ch10OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceiveSwitch,
                     ui->Ch10RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceiveChannel,
                     ui->Ch10RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartMonoPoly,
                     ui->Ch10MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartLegatoSwitch,
                     ui->Ch10LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartOutputAssign,
                     ui->Ch11OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceiveSwitch,
                     ui->Ch11RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceiveChannel,
                     ui->Ch11RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartMonoPoly,
                     ui->Ch11MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartLegatoSwitch,
                     ui->Ch11LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartOutputAssign,
                     ui->Ch12OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceiveSwitch,
                     ui->Ch12RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceiveChannel,
                     ui->Ch12RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartMonoPoly,
                     ui->Ch12MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartLegatoSwitch,
                     ui->Ch12LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartOutputAssign,
                     ui->Ch13OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceiveSwitch,
                     ui->Ch13RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceiveChannel,
                     ui->Ch13RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartMonoPoly,
                     ui->Ch13MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartLegatoSwitch,
                     ui->Ch13LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartOutputAssign,
                     ui->Ch14OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceiveSwitch,
                     ui->Ch14RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceiveChannel,
                     ui->Ch14RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartMonoPoly,
                     ui->Ch14MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartLegatoSwitch,
                     ui->Ch14LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartOutputAssign,
                     ui->Ch15OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceiveSwitch,
                     ui->Ch15RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceiveChannel,
                     ui->Ch15RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartMonoPoly,
                     ui->Ch15MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartLegatoSwitch,
                     ui->Ch15LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartOutputAssign,
                     ui->Ch16OutputBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceiveSwitch,
                     ui->Ch16RxBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceiveChannel,
                     ui->Ch16RxChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartMonoPoly,
                     ui->Ch16MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartLegatoSwitch,
                     ui->Ch16LegatoBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[0],&Integra7PartEQ::EQSwitch,
                     ui->Ch1EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[0],&Integra7PartEQ::EQLowFreq,
                     ui->Ch1EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[0],&Integra7PartEQ::EQLowGain,
                     ui->Ch1EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[0],&Integra7PartEQ::EQMidFreq,
                     ui->Ch1EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[0],&Integra7PartEQ::EQMidGain,
                     ui->Ch1EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[0],&Integra7PartEQ::EQMidQ,
                     ui->Ch1EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[0],&Integra7PartEQ::EQHighFreq,
                     ui->Ch1EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[0],&Integra7PartEQ::EQHighGain,
                     ui->Ch1EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[1],&Integra7PartEQ::EQSwitch,
                     ui->Ch2EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[1],&Integra7PartEQ::EQLowFreq,
                     ui->Ch2EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[1],&Integra7PartEQ::EQLowGain,
                     ui->Ch2EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[1],&Integra7PartEQ::EQMidFreq,
                     ui->Ch2EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[1],&Integra7PartEQ::EQMidGain,
                     ui->Ch2EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[1],&Integra7PartEQ::EQMidQ,
                     ui->Ch2EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[1],&Integra7PartEQ::EQHighFreq,
                     ui->Ch2EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[1],&Integra7PartEQ::EQHighGain,
                     ui->Ch2EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[2],&Integra7PartEQ::EQSwitch,
                     ui->Ch3EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[2],&Integra7PartEQ::EQLowFreq,
                     ui->Ch3EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[2],&Integra7PartEQ::EQLowGain,
                     ui->Ch3EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[2],&Integra7PartEQ::EQMidFreq,
                     ui->Ch3EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[2],&Integra7PartEQ::EQMidGain,
                     ui->Ch3EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[2],&Integra7PartEQ::EQMidQ,
                     ui->Ch3EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[2],&Integra7PartEQ::EQHighFreq,
                     ui->Ch3EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[2],&Integra7PartEQ::EQHighGain,
                     ui->Ch3EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[3],&Integra7PartEQ::EQSwitch,
                     ui->Ch4EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[3],&Integra7PartEQ::EQLowFreq,
                     ui->Ch4EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[3],&Integra7PartEQ::EQLowGain,
                     ui->Ch4EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[3],&Integra7PartEQ::EQMidFreq,
                     ui->Ch4EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[3],&Integra7PartEQ::EQMidGain,
                     ui->Ch4EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[3],&Integra7PartEQ::EQMidQ,
                     ui->Ch4EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[3],&Integra7PartEQ::EQHighFreq,
                     ui->Ch4EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[3],&Integra7PartEQ::EQHighGain,
                     ui->Ch4EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[4],&Integra7PartEQ::EQSwitch,
                     ui->Ch5EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[4],&Integra7PartEQ::EQLowFreq,
                     ui->Ch5EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[4],&Integra7PartEQ::EQLowGain,
                     ui->Ch5EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[4],&Integra7PartEQ::EQMidFreq,
                     ui->Ch5EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[4],&Integra7PartEQ::EQMidGain,
                     ui->Ch5EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[4],&Integra7PartEQ::EQMidQ,
                     ui->Ch5EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[4],&Integra7PartEQ::EQHighFreq,
                     ui->Ch5EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[4],&Integra7PartEQ::EQHighGain,
                     ui->Ch5EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[5],&Integra7PartEQ::EQSwitch,
                     ui->Ch6EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[5],&Integra7PartEQ::EQLowFreq,
                     ui->Ch6EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[5],&Integra7PartEQ::EQLowGain,
                     ui->Ch6EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[5],&Integra7PartEQ::EQMidFreq,
                     ui->Ch6EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[5],&Integra7PartEQ::EQMidGain,
                     ui->Ch6EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[5],&Integra7PartEQ::EQMidQ,
                     ui->Ch6EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[5],&Integra7PartEQ::EQHighFreq,
                     ui->Ch6EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[5],&Integra7PartEQ::EQHighGain,
                     ui->Ch6EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[6],&Integra7PartEQ::EQSwitch,
                     ui->Ch7EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[6],&Integra7PartEQ::EQLowFreq,
                     ui->Ch7EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[6],&Integra7PartEQ::EQLowGain,
                     ui->Ch7EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[6],&Integra7PartEQ::EQMidFreq,
                     ui->Ch7EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[6],&Integra7PartEQ::EQMidGain,
                     ui->Ch7EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[6],&Integra7PartEQ::EQMidQ,
                     ui->Ch7EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[6],&Integra7PartEQ::EQHighFreq,
                     ui->Ch7EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[6],&Integra7PartEQ::EQHighGain,
                     ui->Ch7EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[7],&Integra7PartEQ::EQSwitch,
                     ui->Ch8EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[7],&Integra7PartEQ::EQLowFreq,
                     ui->Ch8EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[7],&Integra7PartEQ::EQLowGain,
                     ui->Ch8EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[7],&Integra7PartEQ::EQMidFreq,
                     ui->Ch8EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[7],&Integra7PartEQ::EQMidGain,
                     ui->Ch8EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[7],&Integra7PartEQ::EQMidQ,
                     ui->Ch8EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[7],&Integra7PartEQ::EQHighFreq,
                     ui->Ch8EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[7],&Integra7PartEQ::EQHighGain,
                     ui->Ch8EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[8],&Integra7PartEQ::EQSwitch,
                     ui->Ch9EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[8],&Integra7PartEQ::EQLowFreq,
                     ui->Ch9EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[8],&Integra7PartEQ::EQLowGain,
                     ui->Ch9EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[8],&Integra7PartEQ::EQMidFreq,
                     ui->Ch9EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[8],&Integra7PartEQ::EQMidGain,
                     ui->Ch9EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[8],&Integra7PartEQ::EQMidQ,
                     ui->Ch9EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[8],&Integra7PartEQ::EQHighFreq,
                     ui->Ch9EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[8],&Integra7PartEQ::EQHighGain,
                     ui->Ch9EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[9],&Integra7PartEQ::EQSwitch,
                     ui->Ch10EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[9],&Integra7PartEQ::EQLowFreq,
                     ui->Ch10EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[9],&Integra7PartEQ::EQLowGain,
                     ui->Ch10EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[9],&Integra7PartEQ::EQMidFreq,
                     ui->Ch10EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[9],&Integra7PartEQ::EQMidGain,
                     ui->Ch10EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[9],&Integra7PartEQ::EQMidQ,
                     ui->Ch10EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[9],&Integra7PartEQ::EQHighFreq,
                     ui->Ch10EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[9],&Integra7PartEQ::EQHighGain,
                     ui->Ch10EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[10],&Integra7PartEQ::EQSwitch,
                     ui->Ch11EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[10],&Integra7PartEQ::EQLowFreq,
                     ui->Ch11EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[10],&Integra7PartEQ::EQLowGain,
                     ui->Ch11EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[10],&Integra7PartEQ::EQMidFreq,
                     ui->Ch11EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[10],&Integra7PartEQ::EQMidGain,
                     ui->Ch11EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[10],&Integra7PartEQ::EQMidQ,
                     ui->Ch11EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[10],&Integra7PartEQ::EQHighFreq,
                     ui->Ch11EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[10],&Integra7PartEQ::EQHighGain,
                     ui->Ch11EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[11],&Integra7PartEQ::EQSwitch,
                     ui->Ch12EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[11],&Integra7PartEQ::EQLowFreq,
                     ui->Ch12EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[11],&Integra7PartEQ::EQLowGain,
                     ui->Ch12EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[11],&Integra7PartEQ::EQMidFreq,
                     ui->Ch12EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[11],&Integra7PartEQ::EQMidGain,
                     ui->Ch12EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[11],&Integra7PartEQ::EQMidQ,
                     ui->Ch12EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[11],&Integra7PartEQ::EQHighFreq,
                     ui->Ch12EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[11],&Integra7PartEQ::EQHighGain,
                     ui->Ch12EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[12],&Integra7PartEQ::EQSwitch,
                     ui->Ch13EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[12],&Integra7PartEQ::EQLowFreq,
                     ui->Ch13EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[12],&Integra7PartEQ::EQLowGain,
                     ui->Ch13EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[12],&Integra7PartEQ::EQMidFreq,
                     ui->Ch13EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[12],&Integra7PartEQ::EQMidGain,
                     ui->Ch13EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[12],&Integra7PartEQ::EQMidQ,
                     ui->Ch13EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[12],&Integra7PartEQ::EQHighFreq,
                     ui->Ch13EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[12],&Integra7PartEQ::EQHighGain,
                     ui->Ch13EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[13],&Integra7PartEQ::EQSwitch,
                     ui->Ch14EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[13],&Integra7PartEQ::EQLowFreq,
                     ui->Ch14EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[13],&Integra7PartEQ::EQLowGain,
                     ui->Ch14EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[13],&Integra7PartEQ::EQMidFreq,
                     ui->Ch14EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[13],&Integra7PartEQ::EQMidGain,
                     ui->Ch14EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[13],&Integra7PartEQ::EQMidQ,
                     ui->Ch14EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[13],&Integra7PartEQ::EQHighFreq,
                     ui->Ch14EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[13],&Integra7PartEQ::EQHighGain,
                     ui->Ch14EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[14],&Integra7PartEQ::EQSwitch,
                     ui->Ch15EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[14],&Integra7PartEQ::EQLowFreq,
                     ui->Ch15EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[14],&Integra7PartEQ::EQLowGain,
                     ui->Ch15EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[14],&Integra7PartEQ::EQMidFreq,
                     ui->Ch15EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[14],&Integra7PartEQ::EQMidGain,
                     ui->Ch15EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[14],&Integra7PartEQ::EQMidQ,
                     ui->Ch15EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[14],&Integra7PartEQ::EQHighFreq,
                     ui->Ch15EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[14],&Integra7PartEQ::EQHighGain,
                     ui->Ch15EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[15],&Integra7PartEQ::EQSwitch,
                     ui->Ch16EQSwBtn,&QPushButton::setChecked);

    QObject::connect(pI7d->PartsEQ[15],&Integra7PartEQ::EQLowFreq,
                     ui->Ch16EQLFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[15],&Integra7PartEQ::EQLowGain,
                     ui->Ch16EQLFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[15],&Integra7PartEQ::EQMidFreq,
                     ui->Ch16EQMFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[15],&Integra7PartEQ::EQMidGain,
                     ui->Ch16EQMFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->PartsEQ[15],&Integra7PartEQ::EQMidQ,
                     ui->Ch16EQMFQBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[15],&Integra7PartEQ::EQHighFreq,
                     ui->Ch16EQHFFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->PartsEQ[15],&Integra7PartEQ::EQHighGain,
                     ui->Ch16EQHFGainBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch1KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::KeyboardRangeLower,
                     ui->Ch1KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch1KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch1KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch1VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::VelocityRangeLower,
                     ui->Ch1VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::VelocityRangeUpper,
                     ui->Ch1VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch1VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch1VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch2KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::KeyboardRangeLower,
                     ui->Ch2KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch2KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch2KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch2VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::VelocityRangeLower,
                     ui->Ch2VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::VelocityRangeUpper,
                     ui->Ch2VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch2VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch2VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch3KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::KeyboardRangeLower,
                     ui->Ch3KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch3KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch3KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch3VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::VelocityRangeLower,
                     ui->Ch3VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::VelocityRangeUpper,
                     ui->Ch3VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch3VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch3VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch4KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::KeyboardRangeLower,
                     ui->Ch4KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch4KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch4KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch4VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::VelocityRangeLower,
                     ui->Ch4VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::VelocityRangeUpper,
                     ui->Ch4VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch4VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch4VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch5KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::KeyboardRangeLower,
                     ui->Ch5KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch5KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch5KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch5VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::VelocityRangeLower,
                     ui->Ch5VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::VelocityRangeUpper,
                     ui->Ch5VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch5VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch5VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch6KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::KeyboardRangeLower,
                     ui->Ch6KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch6KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch6KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch6VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::VelocityRangeLower,
                     ui->Ch6VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::VelocityRangeUpper,
                     ui->Ch6VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch6VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch6VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch7KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::KeyboardRangeLower,
                     ui->Ch7KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch7KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch7KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch7VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::VelocityRangeLower,
                     ui->Ch7VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::VelocityRangeUpper,
                     ui->Ch7VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch7VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch7VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch8KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::KeyboardRangeLower,
                     ui->Ch8KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch8KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch8KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch8VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::VelocityRangeLower,
                     ui->Ch8VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::VelocityRangeUpper,
                     ui->Ch8VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch8VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch8VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch9KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::KeyboardRangeLower,
                     ui->Ch9KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch9KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch9KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch9VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::VelocityRangeLower,
                     ui->Ch9VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::VelocityRangeUpper,
                     ui->Ch9VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch9VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch9VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch10KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::KeyboardRangeLower,
                     ui->Ch10KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch10KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch10KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch10VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::VelocityRangeLower,
                     ui->Ch10VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::VelocityRangeUpper,
                     ui->Ch10VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch10VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch10VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch11KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::KeyboardRangeLower,
                     ui->Ch11KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch11KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch11KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch11VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::VelocityRangeLower,
                     ui->Ch11VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::VelocityRangeUpper,
                     ui->Ch11VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch11VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch11VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch12KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::KeyboardRangeLower,
                     ui->Ch12KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch12KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch12KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch12VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::VelocityRangeLower,
                     ui->Ch12VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::VelocityRangeUpper,
                     ui->Ch12VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch12VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch12VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch13KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::KeyboardRangeLower,
                     ui->Ch13KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch13KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch13KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch13VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::VelocityRangeLower,
                     ui->Ch13VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::VelocityRangeUpper,
                     ui->Ch13VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch13VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch13VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch14KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::KeyboardRangeLower,
                     ui->Ch14KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch14KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch14KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch14VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::VelocityRangeLower,
                     ui->Ch14VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::VelocityRangeUpper,
                     ui->Ch14VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch14VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch14VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch15KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::KeyboardRangeLower,
                     ui->Ch15KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch15KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch15KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch15VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::VelocityRangeLower,
                     ui->Ch15VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::VelocityRangeUpper,
                     ui->Ch15VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch15VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch15VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::KeyboardFadeWidthLower,
                     ui->Ch16KeyFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::KeyboardRangeLower,
                     ui->Ch16KeyRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::KeyboardRangeUpper,
                     ui->Ch16KeyRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::KeyboardFadeWidthUpper,
                     ui->Ch16KeyFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::VelocityFadeWidthLower,
                     ui->Ch16VeloFadeLowerBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::VelocityRangeLower,
                     ui->Ch16VeloRangeLower,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::VelocityRangeUpper,
                     ui->Ch16VeloRangeUpper,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::VelocityFadeWidthUpper,
                     ui->Ch16VeloFadeUpperBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartVelocitySensOffset,
                     ui->Ch16VeloSensOffsetBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartOctaveShift,
                     ui->Ch1OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartCoarseTune,
                     ui->Ch1CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartFineTune,
                     ui->Ch1FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartPitchBendRange,
                     ui->Ch1BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch1PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[0],&Integra7Part::PartPortamentoTime,
                     ui->Ch1PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartOctaveShift,
                     ui->Ch2OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartCoarseTune,
                     ui->Ch2CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartFineTune,
                     ui->Ch2FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartPitchBendRange,
                     ui->Ch2BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch2PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[1],&Integra7Part::PartPortamentoTime,
                     ui->Ch2PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartOctaveShift,
                     ui->Ch3OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartCoarseTune,
                     ui->Ch3CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartFineTune,
                     ui->Ch3FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartPitchBendRange,
                     ui->Ch3BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch3PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[2],&Integra7Part::PartPortamentoTime,
                     ui->Ch3PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartOctaveShift,
                     ui->Ch4OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartCoarseTune,
                     ui->Ch4CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartFineTune,
                     ui->Ch4FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartPitchBendRange,
                     ui->Ch4BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch4PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[3],&Integra7Part::PartPortamentoTime,
                     ui->Ch4PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartOctaveShift,
                     ui->Ch5OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartCoarseTune,
                     ui->Ch5CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartFineTune,
                     ui->Ch5FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartPitchBendRange,
                     ui->Ch5BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch5PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[4],&Integra7Part::PartPortamentoTime,
                     ui->Ch5PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartOctaveShift,
                     ui->Ch6OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartCoarseTune,
                     ui->Ch6CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartFineTune,
                     ui->Ch6FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartPitchBendRange,
                     ui->Ch6BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch6PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[5],&Integra7Part::PartPortamentoTime,
                     ui->Ch6PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartOctaveShift,
                     ui->Ch7OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartCoarseTune,
                     ui->Ch7CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartFineTune,
                     ui->Ch7FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartPitchBendRange,
                     ui->Ch7BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch7PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[6],&Integra7Part::PartPortamentoTime,
                     ui->Ch7PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartOctaveShift,
                     ui->Ch8OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartCoarseTune,
                     ui->Ch8CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartFineTune,
                     ui->Ch8FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartPitchBendRange,
                     ui->Ch8BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch8PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[7],&Integra7Part::PartPortamentoTime,
                     ui->Ch8PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartOctaveShift,
                     ui->Ch9OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartCoarseTune,
                     ui->Ch9CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartFineTune,
                     ui->Ch9FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartPitchBendRange,
                     ui->Ch9BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch9PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[8],&Integra7Part::PartPortamentoTime,
                     ui->Ch9PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartOctaveShift,
                     ui->Ch10OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartCoarseTune,
                     ui->Ch10CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartFineTune,
                     ui->Ch10FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartPitchBendRange,
                     ui->Ch10BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch10PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[9],&Integra7Part::PartPortamentoTime,
                     ui->Ch10PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartOctaveShift,
                     ui->Ch11OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartCoarseTune,
                     ui->Ch11CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartFineTune,
                     ui->Ch11FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartPitchBendRange,
                     ui->Ch11BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch11PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[10],&Integra7Part::PartPortamentoTime,
                     ui->Ch11PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartOctaveShift,
                     ui->Ch12OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartCoarseTune,
                     ui->Ch12CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartFineTune,
                     ui->Ch12FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartPitchBendRange,
                     ui->Ch12BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch12PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[11],&Integra7Part::PartPortamentoTime,
                     ui->Ch12PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartOctaveShift,
                     ui->Ch13OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartCoarseTune,
                     ui->Ch13CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartFineTune,
                     ui->Ch13FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartPitchBendRange,
                     ui->Ch13BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch13PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[12],&Integra7Part::PartPortamentoTime,
                     ui->Ch13PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartOctaveShift,
                     ui->Ch14OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartCoarseTune,
                     ui->Ch14CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartFineTune,
                     ui->Ch14FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartPitchBendRange,
                     ui->Ch14BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch14PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[13],&Integra7Part::PartPortamentoTime,
                     ui->Ch14PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartOctaveShift,
                     ui->Ch15OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartCoarseTune,
                     ui->Ch15CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartFineTune,
                     ui->Ch15FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartPitchBendRange,
                     ui->Ch15BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch15PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[14],&Integra7Part::PartPortamentoTime,
                     ui->Ch15PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartOctaveShift,
                     ui->Ch16OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartCoarseTune,
                     ui->Ch16CoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartFineTune,
                     ui->Ch16FineTuneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartPitchBendRange,
                     ui->Ch16BendRangeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartPortamentoSwitch,
                     ui->Ch16PortaSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Parts[15],&Integra7Part::PartPortamentoTime,
                     ui->Ch16PortaTimeBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceiveProgramChange,
                     ui->Ch1RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceiveBankSelect,
                     ui->Ch1RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceivePitchBend,
                     ui->Ch1RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch1RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch1RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceiveModulation,
                     ui->Ch1RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceiveVolume,
                     ui->Ch1RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceivePan,
                     ui->Ch1RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceiveExpression,
                     ui->Ch1RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[0],&Integra7Part::ReceiveHold,
                     ui->Ch1RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceiveProgramChange,
                     ui->Ch2RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceiveBankSelect,
                     ui->Ch2RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceivePitchBend,
                     ui->Ch2RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch2RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch2RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceiveModulation,
                     ui->Ch2RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceiveVolume,
                     ui->Ch2RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceivePan,
                     ui->Ch2RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceiveExpression,
                     ui->Ch2RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[1],&Integra7Part::ReceiveHold,
                     ui->Ch2RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceiveProgramChange,
                     ui->Ch3RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceiveBankSelect,
                     ui->Ch3RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceivePitchBend,
                     ui->Ch3RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch3RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch3RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceiveModulation,
                     ui->Ch3RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceiveVolume,
                     ui->Ch3RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceivePan,
                     ui->Ch3RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceiveExpression,
                     ui->Ch3RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[2],&Integra7Part::ReceiveHold,
                     ui->Ch3RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceiveProgramChange,
                     ui->Ch4RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceiveBankSelect,
                     ui->Ch4RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceivePitchBend,
                     ui->Ch4RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch4RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch4RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceiveModulation,
                     ui->Ch4RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceiveVolume,
                     ui->Ch4RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceivePan,
                     ui->Ch4RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceiveExpression,
                     ui->Ch4RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[3],&Integra7Part::ReceiveHold,
                     ui->Ch4RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceiveProgramChange,
                     ui->Ch5RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceiveBankSelect,
                     ui->Ch5RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceivePitchBend,
                     ui->Ch5RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch5RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch5RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceiveModulation,
                     ui->Ch5RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceiveVolume,
                     ui->Ch5RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceivePan,
                     ui->Ch5RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceiveExpression,
                     ui->Ch5RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[4],&Integra7Part::ReceiveHold,
                     ui->Ch5RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceiveProgramChange,
                     ui->Ch6RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceiveBankSelect,
                     ui->Ch6RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceivePitchBend,
                     ui->Ch6RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch6RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch6RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceiveModulation,
                     ui->Ch6RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceiveVolume,
                     ui->Ch6RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceivePan,
                     ui->Ch6RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceiveExpression,
                     ui->Ch6RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[5],&Integra7Part::ReceiveHold,
                     ui->Ch6RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceiveProgramChange,
                     ui->Ch7RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceiveBankSelect,
                     ui->Ch7RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceivePitchBend,
                     ui->Ch7RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch7RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch7RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceiveModulation,
                     ui->Ch7RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceiveVolume,
                     ui->Ch7RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceivePan,
                     ui->Ch7RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceiveExpression,
                     ui->Ch7RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[6],&Integra7Part::ReceiveHold,
                     ui->Ch7RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceiveProgramChange,
                     ui->Ch8RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceiveBankSelect,
                     ui->Ch8RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceivePitchBend,
                     ui->Ch8RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch8RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch8RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceiveModulation,
                     ui->Ch8RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceiveVolume,
                     ui->Ch8RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceivePan,
                     ui->Ch8RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceiveExpression,
                     ui->Ch8RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[7],&Integra7Part::ReceiveHold,
                     ui->Ch8RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceiveProgramChange,
                     ui->Ch9RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceiveBankSelect,
                     ui->Ch9RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceivePitchBend,
                     ui->Ch9RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch9RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch9RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceiveModulation,
                     ui->Ch9RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceiveVolume,
                     ui->Ch9RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceivePan,
                     ui->Ch9RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceiveExpression,
                     ui->Ch9RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[8],&Integra7Part::ReceiveHold,
                     ui->Ch9RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceiveProgramChange,
                     ui->Ch10RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceiveBankSelect,
                     ui->Ch10RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceivePitchBend,
                     ui->Ch10RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch10RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch10RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceiveModulation,
                     ui->Ch10RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceiveVolume,
                     ui->Ch10RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceivePan,
                     ui->Ch10RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceiveExpression,
                     ui->Ch10RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[9],&Integra7Part::ReceiveHold,
                     ui->Ch10RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceiveProgramChange,
                     ui->Ch11RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceiveBankSelect,
                     ui->Ch11RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceivePitchBend,
                     ui->Ch11RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch11RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch11RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceiveModulation,
                     ui->Ch11RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceiveVolume,
                     ui->Ch11RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceivePan,
                     ui->Ch11RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceiveExpression,
                     ui->Ch11RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[10],&Integra7Part::ReceiveHold,
                     ui->Ch11RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceiveProgramChange,
                     ui->Ch12RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceiveBankSelect,
                     ui->Ch12RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceivePitchBend,
                     ui->Ch12RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch12RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch12RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceiveModulation,
                     ui->Ch12RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceiveVolume,
                     ui->Ch12RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceivePan,
                     ui->Ch12RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceiveExpression,
                     ui->Ch12RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[11],&Integra7Part::ReceiveHold,
                     ui->Ch12RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceiveProgramChange,
                     ui->Ch13RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceiveBankSelect,
                     ui->Ch13RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceivePitchBend,
                     ui->Ch13RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch13RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch13RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceiveModulation,
                     ui->Ch13RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceiveVolume,
                     ui->Ch13RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceivePan,
                     ui->Ch13RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceiveExpression,
                     ui->Ch13RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[12],&Integra7Part::ReceiveHold,
                     ui->Ch13RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceiveProgramChange,
                     ui->Ch14RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceiveBankSelect,
                     ui->Ch14RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceivePitchBend,
                     ui->Ch14RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch14RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch14RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceiveModulation,
                     ui->Ch14RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceiveVolume,
                     ui->Ch14RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceivePan,
                     ui->Ch14RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceiveExpression,
                     ui->Ch14RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[13],&Integra7Part::ReceiveHold,
                     ui->Ch14RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceiveProgramChange,
                     ui->Ch15RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceiveBankSelect,
                     ui->Ch15RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceivePitchBend,
                     ui->Ch15RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch15RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch15RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceiveModulation,
                     ui->Ch15RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceiveVolume,
                     ui->Ch15RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceivePan,
                     ui->Ch15RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceiveExpression,
                     ui->Ch15RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[14],&Integra7Part::ReceiveHold,
                     ui->Ch15RHoldBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceiveProgramChange,
                     ui->Ch16RPCBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceiveBankSelect,
                     ui->Ch16RBSBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceivePitchBend,
                     ui->Ch16RPBBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceivePolyphonicKeyPressure,
                     ui->Ch16RPPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceiveChannelPressure,
                     ui->Ch16RCPBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceiveModulation,
                     ui->Ch16RModBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceiveVolume,
                     ui->Ch16RVolBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceivePan,
                     ui->Ch16RPanBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceiveExpression,
                     ui->Ch16RExpBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Parts[15],&Integra7Part::ReceiveHold,
                     ui->Ch16RHoldBtn,&QAbstractButton::setChecked);

    /*****************************************************************/

    QObject::connect(pI7d->StudioSetCommon,&Integra7StudioSetCommon::ChorusSwitch,
                     ui->ChorusSwBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusType,
                     ui->ChorusTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusLevel,
                     ui->ChorusLvlBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusOutputSelect,
                     ui->ChorusOutSelectBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusFilterType,
                     ui->ChorusFilterTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusCutoffFreq,
                     ui->ChorusFilterCutoffBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusPreDelay,
                     ui->ChorusPreDelayBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusRateType,
                     ui->ChorusRateTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusRateHz,
                     ui->ChorusHzRateBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusRateNote,
                     ui->ChorusNoteRateBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusDepth,
                     ui->ChorusDepthBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusPhase,
                     ui->ChorusPhaseBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::ChorusFeedback,
                     ui->ChorusFbBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayDelayLeft,
                     ui->DelayLeftTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayDelayLeftMS,
                     ui->DelayLeftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayDelayLeftNote,
                     ui->DelayLeftNoteBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayDelayRight,
                     ui->DelayRightTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayDelayRightMS,
                     ui->DelayRightBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayDelayRightNote,
                     ui->DelayRightNoteBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayDelayCenter,
                     ui->DelayCenterTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayDelayCenterMS,
                     ui->DelayCenterBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayDelayCenterNote,
                     ui->DelayCenterNoteBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayFeedback,
                     ui->DelayFBBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayHFDamp,
                     ui->DelayHFDampBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayLeftLevel,
                     ui->DelayLeftLvlBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayRightLevel,
                     ui->DelayRightLvlBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::DelayCenterLevel,
                     ui->DelayCenterLvlBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::GM2ChorusPreLPF,
                     ui->ChorusGM2PreLPFBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::GM2ChorusLevel,
                     ui->ChorusGM2LevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::GM2ChorusFeedback,
                     ui->ChorusGM2FBBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::GM2ChorusDelay,
                     ui->ChorusGM2DelayBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::GM2ChorusRate,
                     ui->ChorusGM2RateBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Chorus,&Integra7Chorus::GM2ChorusDepth,
                     ui->ChorusGM2DepthBox,&QSpinBox::setValue);

    QObject::connect(pI7d->StudioSetCommon,&Integra7StudioSetCommon::ReverbSwitch,
                     ui->ReverbSwBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::Type,
                     ui->ReverbTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::Level,
                     ui->ReverbLevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::OutputAssign,
                     ui->ReverbOutputAssignBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::PreDelay,
                     ui->ReverbPreDelayBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::Time,
                     ui->ReverbTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::Density,
                     ui->ReverbDensityBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::Diffusion,
                     ui->ReverbDiffusionBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::LFDamp,
                     ui->ReverbLFDampBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::HFDamp,
                     ui->ReverbHFDampBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::Spread,
                     ui->ReverbSpreadBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::Tone,
                     ui->ReverbToneBox,&QSpinBox::setValue);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::GM2Character,
                     ui->ReverbGM2CharBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Reverb,&Integra7Reverb::GM2Time,
                     ui->ReverbGM2TimeBox,&QSpinBox::setValue);

    /*************************************************/

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::MasterLevel,
                     ui->MasterLevelBox,&QSpinBox::setValue);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::MasterTune,
                     ui->MasterTuneSld,&QSlider::setValue);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::MasterTuneCents,
                     ui->MasterTuneBoxC,&QDoubleSpinBox::setValue);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::MasterTuneHz,
                     ui->MasterTuneBox,&QDoubleSpinBox::setValue);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::MasterKeyShift,
                     ui->MasterKeyShiftBox,&QSpinBox::setValue);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::ScaleTuneSwitch,
                     ui->ScaleTuneSwitchBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::SystemControl1Source,
                     ui->SysCtrl1SrcBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::SystemControl2Source,
                     ui->SysCtrl2SrcBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::SystemControl3Source,
                     ui->SysCtrl3SrcBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::SystemControl4Source,
                     ui->SysCtrl4SrcBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::ControlSource,
                     ui->SystemControlSourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::SystemClockSource,
                     ui->SystemClockSourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::SystemTempo,
                     ui->SystemTempoBox,&QSpinBox::setValue);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::TempoAssignSource,
                     ui->SystemTempoAssignSourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::ReceiveProgramChange,
                     ui->SysRcvPrgChangeBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::ReceiveBankSelect,
                     ui->SysRcvBankSelBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::StudioSetControlChannel,
                     ui->StudioSetCtrlChBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::sig51CHCenterSpeakerSwitch,
                     ui->CenterSpkSwBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::sig51CHSubWooferSwitch,
                     ui->SubwooferSpkSwBtn,&QAbstractButton::setChecked);

    QObject::connect(pI7d->SystemCommon,&Integra7SystemCommon::sig2CHOutputMode,
                     ui->SpkOutModeBox,&QComboBox::setCurrentIndex);

    QObject::connect(pI7d->Setup,&Integra7Setup::SoundMode,
                     ui->SoundModeBox,&QComboBox::setCurrentIndex);

    ui->Ch1Btn->setChecked(true);

    ShowUtilityCard();
}

integra7MainWindow::~integra7MainWindow()
{
    delete pI7d;

    pMidiEngine->Stop();
    delete pMidiEngine;

    delete ui;
}

void integra7MainWindow::ShowStatusValue(int val)
{
    QString msg = QString::number(val);
    ui->statusbar->showMessage(msg);
}

void integra7MainWindow::DisplayPartTonePreset(int part, int bank, int p)
{
    QString tp;
    QString bk;

    if (Integra7Device::getBankName(tp,bk,bank) < 0) return;

    BlockToneChangeSignal = true;

    if (TypeBoxes[part][0]->currentText() != tp)
        TypeBoxes[part][0]->setCurrentText(tp);

    if (BankBoxes[part][0]->currentText() != bk)
        BankBoxes[part][0]->setCurrentText(bk);

    if (ToneBoxes[part][0]->currentIndex() != p)
        ToneBoxes[part][0]->setCurrentIndex(p);

    BlockToneChangeSignal = false;
}

void integra7MainWindow::SelectPreview(bool checked)
{
    if (checked)
        pI7d->SetPreview(PartBtnGrp.checkedId()+1);
    else
        pI7d->SetPreview(0);
}

void integra7MainWindow::UpdateStudioSetName(QString name)
{
    ui->StudioSetBox->setItemText(ui->StudioSetBox->currentIndex(),name);
}

void integra7MainWindow::ReadDumpFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Load SysEx Dump from a file",
                               "","SysEx Dump (*.syx)");
    ShowStatusMsg("Sending " % fileName % " to device ...");

    DumpFileReader *DFR = new DumpFileReader(pI7d,this,fileName);
    QThreadPool::globalInstance()->start(DFR);
}

void integra7MainWindow::WriteDumpToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save SysEx Dump to a file",
                               "Integra7.syx","SysEx Dump (*.syx)");
    int len = pI7d->BulkDumpWriteFile(fileName);
    ShowStatusMsg("Dump file of size " % QString::number(len) % " bytes written to : " % fileName);
}

void integra7MainWindow::PartBtnToggled(int id, bool checked)
{
    if (checked) {

        ui->TypeBox->setCurrentIndex(TypeBoxes[id][0]->currentIndex());
        ui->BankBox->setCurrentIndex(BankBoxes[id][0]->currentIndex());
        ui->ToneBox->setCurrentIndex(ToneBoxes[id][0]->currentIndex());

        QObject::connect(ui->TypeBox,&QComboBox::currentIndexChanged,
                         TypeBoxes[id][0],&QComboBox::setCurrentIndex);

        QObject::connect(ui->BankBox,&QComboBox::currentIndexChanged,
                         BankBoxes[id][0],&QComboBox::setCurrentIndex);

        QObject::connect(ui->ToneBox,&QComboBox::currentIndexChanged,
                         ToneBoxes[id][0],&QComboBox::setCurrentIndex);

        QObject::connect(TypeBoxes[id][0],&QComboBox::currentIndexChanged,
                         ui->TypeBox,&QComboBox::setCurrentIndex);

        QObject::connect(BankBoxes[id][0],&QComboBox::currentIndexChanged,
                         ui->BankBox,&QComboBox::setCurrentIndex);

        QObject::connect(ToneBoxes[id][0],&QComboBox::currentIndexChanged,
                         ui->ToneBox,&QComboBox::setCurrentIndex);

    } else {
        QObject::disconnect(ui->TypeBox,&QComboBox::currentIndexChanged,
                         TypeBoxes[id][0],&QComboBox::setCurrentIndex);

        QObject::disconnect(ui->BankBox,&QComboBox::currentIndexChanged,
                         BankBoxes[id][0],&QComboBox::setCurrentIndex);

        QObject::disconnect(ui->ToneBox,&QComboBox::currentIndexChanged,
                         ToneBoxes[id][0],&QComboBox::setCurrentIndex);

        QObject::disconnect(TypeBoxes[id][0],&QComboBox::currentIndexChanged,
                         ui->TypeBox,&QComboBox::setCurrentIndex);

        QObject::disconnect(BankBoxes[id][0],&QComboBox::currentIndexChanged,
                         ui->BankBox,&QComboBox::setCurrentIndex);

        QObject::disconnect(ToneBoxes[id][0],&QComboBox::currentIndexChanged,
                         ui->ToneBox,&QComboBox::setCurrentIndex);
    }
}

void integra7MainWindow::ShowStudioSet()
{
    ui->LeftMenu->setCurrentWidget(ui->StudioSetMenu);
    ui->RightContent->setCurrentWidget(ui->PartViewCard);
}

void integra7MainWindow::ShowEffects()
{
    ui->LeftMenu->setCurrentWidget(ui->EffectsMenu);
    ui->RightContent->setCurrentWidget(ui->MasterEQCard);
}

void integra7MainWindow::ShowChorusParams(QString tp)
{
    if (tp == "Chorus") {
        ui->ChorusParams->setCurrentWidget(ui->ChorusParamCard);
    } else if (tp == "Delay") {
        ui->ChorusParams->setCurrentWidget(ui->DelayParamCard);
    } else if (tp == "GM2 Chorus") {
        ui->ChorusParams->setCurrentWidget(ui->GM2ChorusParamCard);
    } else
        ui->ChorusParams->setCurrentWidget(ui->ChorusEmptyPage);
}

void integra7MainWindow::ShowReverbParams(int tp)
{
    switch (tp) {
    case 1:
        ui->ReverbParams->setCurrentWidget(ui->RoomHallPlate);
        break;
    case 2:
        ui->ReverbParams->setCurrentWidget(ui->RoomHallPlate);
        break;
    case 3:
        ui->ReverbParams->setCurrentWidget(ui->RoomHallPlate);
        break;
    case 4:
        ui->ReverbParams->setCurrentWidget(ui->RoomHallPlate);
        break;
    case 5:
        ui->ReverbParams->setCurrentWidget(ui->RoomHallPlate);
        break;
    case 6:
        ui->ReverbParams->setCurrentWidget(ui->GM2Reverb);
        break;
    default:
        ui->ReverbParams->setCurrentWidget(ui->ReverbEmptyPage);
        break;
    }
}

void integra7MainWindow::ShowVirtualSlotsCard()
{
    ui->LeftMenu->setCurrentWidget(ui->EmptyMenu);
    ui->RightContent->setCurrentWidget(ui->VirtualSlotsCard);
}

void integra7MainWindow::ShowUtilityCard()
{
    ui->LeftMenu->setCurrentWidget(ui->EmptyMenu);
    ui->RightContent->setCurrentWidget(ui->UtilityCard);
}

void integra7MainWindow::SoloButtonsLogic(int id, bool checked)
{
    if (SoloPartBtnGrp.checkedId() < 0) {
        //no solo channel selected
        pI7d->StudioSetCommon->setSoloPart(0);
    } else if (checked) {
        pI7d->StudioSetCommon->setSoloPart(id);
        for (int i=1;i<17;i++) {
            if (i != id && SoloPartBtnGrp.button(i)->isChecked())
                SoloPartBtnGrp.button(i)->setChecked(false);
        }
    }
}

void integra7MainWindow::MidiConnectBtn_clicked()
{
    pI7d->setDeviceId(ui->DeviceIdBox->currentIndex());
    pMidiEngine->SelectALSAClient(ui->MidiPortBox->currentIndex());
    pI7d->SendIdentityRequest();
}

void integra7MainWindow::VSlotBox_currentIndexChanged(int index)
{
    if (index == 19)
    {
        ui->VSlotABox->setCurrentIndex(19);
        ui->VSlotBBox->setCurrentIndex(19);
        ui->VSlotCBox->setCurrentIndex(19);
        ui->VSlotDBox->setCurrentIndex(19);
    } else {
        if (ui->VSlotABox->currentIndex()==19) ui->VSlotABox->setCurrentIndex(0);
        if (ui->VSlotBBox->currentIndex()==19) ui->VSlotBBox->setCurrentIndex(0);
        if (ui->VSlotCBox->currentIndex()==19) ui->VSlotCBox->setCurrentIndex(0);
        if (ui->VSlotDBox->currentIndex()==19) ui->VSlotDBox->setCurrentIndex(0);
    }    
}

void integra7MainWindow::TypeBoxChangeLogic(QComboBox *TypeBox, QComboBox *BankBox, QComboBox *ToneBox)
{
    BankBox->clear();
    BankBox->addItems(Integra7Device::GetBankList(TypeBox->currentText()));
}

void integra7MainWindow::BankBoxChangeLogic(QComboBox *TypeBox, QComboBox *BankBox, QComboBox *ToneBox)
{
    if (BankBox->count() < 1) return;

    ToneBox->clear();
    ToneBox->addItems(Integra7Device::GetToneList(TypeBox->currentText(),BankBox->currentText()));
}

void integra7MainWindow::ToneBoxChangeLogic(uint8_t part, int index, QComboBox *TypeBox, QComboBox *BankBox)
{
    if (BlockToneChangeSignal) return;

    if (index < 0) return;

    QString type = TypeBox->currentText();
    QString bank = BankBox->currentText();

    int bi = Integra7Device::getBankIndex(type,bank);

    if (bi < 0) return;

    QString mTone = ToneBoxes[part][0]->currentText();

    if (PartBtnGrp.checkedId() == part)
        mTone = ui->ToneBox->currentText();

    if (ToneBoxes[part][0]->currentText() == ToneBoxes[part][1]->currentText() &&
        ToneBoxes[part][0]->currentText() == mTone)
        pI7d->Parts[part]->setToneBankProgram(bi,index);

}

void integra7MainWindow::VSlotLoadBtn_clicked()
{
    pI7d->LoadVirtualSlots(ui->VSlotABox->currentIndex(),
                           ui->VSlotBBox->currentIndex(),
                           ui->VSlotCBox->currentIndex(),
                           ui->VSlotDBox->currentIndex());
}

void integra7MainWindow::BulkDumpRequest()
{
    /* Bulk dump request needs to run in an separate thread because of
       waiting between particular calls for data transmission */
    ReadRequest *RR = new ReadRequest(pI7d);
    QThreadPool::globalInstance()->start(RR);
}

DumpFileReader::DumpFileReader(Integra7Device *pdev, integra7MainWindow *pwin, QString &fname)
{    
    dev = pdev;
    win = pwin;
    fileName = fname;
}

void DumpFileReader::run()
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);

    uint8_t *rdata = new uint8_t[file.size()];

    //read the content of file at once into array
    //split into SysExes and send each separately into the device with defined delay
    //then request dump read from device to synchornize UI

    int nrd = file.read((char*)rdata,file.size());
    int len = 0;
    int start = 0;

    for (int c=0;c<nrd;++c) {
        if (rdata[c] == 0xF0)
        {
            len = 1;
            start = c;
        }
        else if (rdata[c] == 0xF7)
        {
            ++len;
            dev->SendFullSysEx(rdata+start,len);
            QThread::msleep(dev->GetMsgDelay());
        }
        else ++len;
    }

    file.close();
    delete[] rdata;

    win->BulkDumpRequest();
}

ReadRequest::ReadRequest(Integra7Device *i7dev)
{
    dev = i7dev;
}

void ReadRequest::run()
{
    uint8_t req[8];

    dev->Setup->GetRequestArray(req);
    dev->DataRequest(req);

    QThread::msleep(dev->GetMsgDelay()); //give it a time to process the response

    dev->SystemCommon->GetRequestArray(req);
    dev->DataRequest(req);

    QThread::msleep(dev->GetMsgDelay()); //give it a time to process the response

    //Request whole StudioSet in single call
    req[0] = 0x18;
    req[1] = 0;
    req[2] = 0;
    req[3] = 0;

    req[4] = 0;
    req[5] = 0;
    req[6] = 0x60;
    req[7] = 0;

    dev->DataRequest(req);
}
