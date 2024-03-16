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

#include "integra7mainwindow.h"
#include "./ui_integra7mainwindow.h"
#include "integra7part.h"
#include "integra7parteq.h"
#include "integra7mastereq.h"
#include "integra7studiosetcommon.h"

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

    /* Setup Main Combo box lists*/
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

    /* Part Keyboart Card Connection logic */
    /*QObject::connect(ui->Ch1KeyRangeLowerSld,&QSlider::valueChanged,
                     ui->Ch1KeyRangeLowerBox,&NoteNameSelector::setValue);
    QObject::connect(ui->Ch1KeyRangeLowerBox,&NoteNameSelector::valueChanged,
                     ui->Ch1KeyRangeLowerSld,&QSlider::setValue);

    QObject::connect(ui->Ch1KeyRangeUpperSld,&QSlider::valueChanged,this,
                     [this](){ui->Ch1KeyRangeUpperBox->setValue(127-ui->Ch1KeyRangeUpperSld->value());});

    QObject::connect(ui->Ch1KeyRangeUpperBox,&NoteNameSelector::valueChanged,this,
                     [this](){ui->Ch1KeyRangeUpperSld->setValue(127-ui->Ch1KeyRangeUpperBox->value());});*/

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

    QObject::connect(ui->DeviceIdBox,
                     &QComboBox::currentIndexChanged,pI7d,
                     &Integra7Device::setDeviceId);

    QObject::connect(ui->PreviewBtn,
                     &QAbstractButton::clicked,pI7d,
                     &Integra7Device::SetPreview);

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
                     pI7d->pParts[0],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch1PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch1ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch1ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch1MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[0],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch2LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch2PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch2ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch2ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch2MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[1],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch3LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch3PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch3ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch3ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch3MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[2],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch4LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch4PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch4ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch4ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch4MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[3],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch5LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch5PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch5ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch5ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch5MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[4],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch6LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch6PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch6ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch6ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch6MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[5],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch7LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch7PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch7ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch7ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch7MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[6],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch8LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch8PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch8ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch8ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch8MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[7],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch9LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch9PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch9ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch9ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch9MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[8],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch10LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch10PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch10ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch10ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch10MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[9],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch11LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch11PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch11ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch11ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch11MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[10],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch12LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch12PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch12ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch12ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch12MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[11],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch13LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch13PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch13ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch13ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch13MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[12],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch14LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch14PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch14ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch14ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch14MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[13],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch15LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch15PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch15ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch15ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch15MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[14],&Integra7Part::setMuteSwitch);

    QObject::connect(ui->Ch16LevelBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setPartLevel);

    QObject::connect(ui->Ch16PanBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setPartPan);

    QObject::connect(ui->Ch16ChorusBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setPartChorusSendLevel);

    QObject::connect(ui->Ch16ReverbBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setPartReverbSendLevel);

    QObject::connect(ui->Ch16MuteBtn,&QPushButton::toggled,
                     pI7d->pParts[15],&Integra7Part::setMuteSwitch);

    /* Part EQ connections */
    QObject::connect(ui->Ch1EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[0],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch1EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[0],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch1EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[0],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch1EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[0],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch1EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[0],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch1EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[0],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch1EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[0],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch1EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[0],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch2EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[1],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch2EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[1],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch2EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[1],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch2EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[1],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch2EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[1],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch2EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[1],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch2EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[1],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch2EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[1],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch3EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[2],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch3EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[2],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch3EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[2],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch3EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[2],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch3EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[2],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch3EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[2],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch3EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[2],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch3EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[2],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch4EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[3],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch4EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[3],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch4EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[3],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch4EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[3],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch4EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[3],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch4EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[3],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch4EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[3],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch4EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[3],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch5EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[4],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch5EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[4],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch5EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[4],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch5EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[4],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch5EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[4],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch5EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[4],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch5EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[4],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch5EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[4],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch6EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[5],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch6EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[5],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch6EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[5],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch6EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[5],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch6EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[5],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch6EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[5],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch6EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[5],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch6EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[5],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch7EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[6],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch7EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[6],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch7EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[6],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch7EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[6],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch7EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[6],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch7EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[6],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch7EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[6],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch7EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[6],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch8EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[7],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch8EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[7],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch8EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[7],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch8EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[7],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch8EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[7],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch8EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[7],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch8EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[7],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch8EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[7],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch9EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[8],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch9EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[8],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch9EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[8],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch9EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[8],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch9EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[8],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch9EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[8],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch9EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[8],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch9EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[8],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch10EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[9],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch10EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[9],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch10EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[9],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch10EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[9],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch10EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[9],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch10EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[9],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch10EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[9],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch10EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[9],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch11EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[10],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch11EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[10],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch11EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[10],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch11EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[10],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch11EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[10],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch11EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[10],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch11EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[10],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch11EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[10],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch12EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[11],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch12EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[11],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch12EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[11],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch12EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[11],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch12EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[11],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch12EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[11],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch12EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[11],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch12EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[11],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch13EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[12],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch13EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[12],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch13EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[12],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch13EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[12],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch13EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[12],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch13EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[12],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch13EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[12],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch13EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[12],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch14EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[13],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch14EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[13],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch14EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[13],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch14EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[13],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch14EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[13],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch14EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[13],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch14EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[13],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch14EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[13],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch15EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[14],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch15EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[14],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch15EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[14],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch15EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[14],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch15EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[14],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch15EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[14],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch15EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[14],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch15EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[14],&Integra7PartEQ::setEQHighGain);

    QObject::connect(ui->Ch16EQSwBtn,&QPushButton::toggled,
                     pI7d->pPartsEQ[15],&Integra7PartEQ::setEQSwitch);

    QObject::connect(ui->Ch16EQLFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[15],&Integra7PartEQ::setEQLowFreq);

    QObject::connect(ui->Ch16EQLFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[15],&Integra7PartEQ::setEQLowGain);

    QObject::connect(ui->Ch16EQMFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[15],&Integra7PartEQ::setEQMidFreq);

    QObject::connect(ui->Ch16EQMFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[15],&Integra7PartEQ::setEQMidGain);

    QObject::connect(ui->Ch16EQMFQBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[15],&Integra7PartEQ::setEQMidQ);

    QObject::connect(ui->Ch16EQHFFreqBox,&QComboBox::currentIndexChanged,
                     pI7d->pPartsEQ[15],&Integra7PartEQ::setEQHighFreq);

    QObject::connect(ui->Ch16EQHFGainBox,&QSpinBox::valueChanged,
                     pI7d->pPartsEQ[15],&Integra7PartEQ::setEQHighGain);

    /* Part Keyboard Connections */
    QObject::connect(ui->Ch1KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch1KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch1KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch1KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch1VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch1VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch1VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch1VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch1VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch2KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch2KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch2KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch2KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch2VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch2VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch2VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch2VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch2VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch3KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch3KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch3KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch3KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch3VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch3VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch3VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch3VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch3VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch4KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch4KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch4KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch4KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch4VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch4VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch4VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch4VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch4VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch5KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch5KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch5KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch5KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch5VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch5VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch5VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch5VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch5VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch6KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch6KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch6KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch6KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch6VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch6VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch6VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch6VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch6VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch7KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch7KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch7KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch7KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch7VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch7VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch7VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch7VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch7VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch8KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch8KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch8KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch8KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch8VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch8VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch8VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch8VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch8VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch9KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch9KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch9KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch9KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch9VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch9VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch9VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch9VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch9VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch10KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch10KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch10KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch10KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch10VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch10VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch10VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch10VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch10VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch11KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch11KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch11KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch11KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch11VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch11VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch11VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch11VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch11VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch12KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch12KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch12KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch12KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch12VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch12VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch12VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch12VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch12VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch13KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch13KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch13KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch13KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch13VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch13VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch13VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch13VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch13VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch14KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch14KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch14KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch14KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch14VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch14VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch14VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch14VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch14VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch15KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch15KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch15KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch15KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch15VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch15VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch15VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch15VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch15VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setPartVelocitySensOffset);

    QObject::connect(ui->Ch16KeyFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setKeyboardFadeWidthLower);

    QObject::connect(ui->Ch16KeyRangeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setKeyboardRangeLower);

    QObject::connect(ui->Ch16KeyRangeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setKeyboardRangeUpper);

    QObject::connect(ui->Ch16KeyFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setKeyboardFadeWidthUpper);

    QObject::connect(ui->Ch16VeloFadeLowerBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setVelocityFadeWidthLower);

    QObject::connect(ui->Ch16VeloRangeLower,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setVelocityRangeLower);

    QObject::connect(ui->Ch16VeloRangeUpper,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setVelocityRangeUpper);

    QObject::connect(ui->Ch16VeloFadeUpperBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setVelocityFadeWidthUpper);

    QObject::connect(ui->Ch16VeloSensOffsetBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setPartVelocitySensOffset);

    /* Create Part Pitch connections */
    QObject::connect(ui->Ch1OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch1CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch1FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch1BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch1PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[0],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch1PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[0],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch2OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch2CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch2FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch2BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch2PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[1],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch2PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[1],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch3OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch3CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch3FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch3BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch3PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[2],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch3PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[2],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch4OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch4CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch4FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch4BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch4PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[3],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch4PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[3],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch5OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch5CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch5FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch5BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch5PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[4],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch5PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[4],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch6OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch6CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch6FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch6BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch6PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[5],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch6PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[5],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch7OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch7CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch7FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch7BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch7PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[6],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch7PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[6],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch8OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch8CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch8FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch8BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch8PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[7],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch8PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[7],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch9OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch9CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch9FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch9BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch9PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[8],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch9PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[8],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch10OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch10CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch10FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch10BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch10PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[9],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch10PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[9],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch11OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch11CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch11FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch11BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch11PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[10],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch11PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[10],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch12OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch12CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch12FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch12BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch12PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[11],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch12PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[11],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch13OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch13CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch13FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch13BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch13PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[12],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch13PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[12],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch14OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch14CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch14FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch14BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch14PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[13],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch14PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[13],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch15OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch15CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch15FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch15BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch15PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[14],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch15PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[14],&Integra7Part::setPartPortamentoTime);

    QObject::connect(ui->Ch16OctaveShiftBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setPartOctaveShift);

    QObject::connect(ui->Ch16CoarseTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setPartCoarseTune);

    QObject::connect(ui->Ch16FineTuneBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setPartFineTune);

    QObject::connect(ui->Ch16BendRangeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setPartPitchBendRange);

    QObject::connect(ui->Ch16PortaSwitchBox,&QComboBox::currentIndexChanged,
                     pI7d->pParts[15],&Integra7Part::setPartPortamentoSwitch);

    QObject::connect(ui->Ch16PortaTimeBox,&QSpinBox::valueChanged,
                     pI7d->pParts[15],&Integra7Part::setPartPortamentoTime);

    ui->Ch1Btn->setChecked(true);

    ShowUtilityCard();
}

integra7MainWindow::~integra7MainWindow()
{
    delete pI7d;

    pMidiEngine->Clean();
    delete pMidiEngine;

    delete ui;
}

void integra7MainWindow::ShowStatusValue(int val)
{
    QString msg = QString::number(val);
    ui->statusbar->showMessage(msg);
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
        pI7d->pParts[part]->setToneBankProgram(bi,index);

}

void integra7MainWindow::VSlotLoadBtn_clicked()
{
    pI7d->LoadVirtualSlots(ui->VSlotABox->currentIndex(),
                           ui->VSlotBBox->currentIndex(),
                           ui->VSlotCBox->currentIndex(),
                           ui->VSlotDBox->currentIndex());
}

