/*************************************************************************
   Copyright (C) 2024  Miroslav Kovac

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <https://www.gnu.org/licenses/>
*************************************************************************/

#include "tworganeditor.h"
#include "ui_tworganeditor.h"

TWOrganEditor::TWOrganEditor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TWOrganEditor)
{
    ui->setupUi(this);

    ui->PercussionSoftBox->addItem("NORM");
    ui->PercussionSoftBox->addItem("SOFT");

    ui->PercussionSlowBox->addItem("FAST");
    ui->PercussionSlowBox->addItem("SLOW");

    ui->PercussionHarmonicBox->addItem("2ND");
    ui->PercussionHarmonicBox->addItem("3RD");
}

TWOrganEditor::~TWOrganEditor()
{
    delete ui;
}

void TWOrganEditor::ConnectSignals(Integra7Tone *tone)
{
    if (tone == NULL) return;

    Integra7SNAcousticToneCommon *snat = tone->SNAcousticToneCommon;

    QObject::connect(ui->Slider16,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter1);

    QObject::connect(ui->Slider513,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter2);

    QObject::connect(ui->Slider8,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter3);

    QObject::connect(ui->Slider4,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter4);

    QObject::connect(ui->Slider223,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter5);

    QObject::connect(ui->Slider2,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter6);

    QObject::connect(ui->Slider135,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter7);

    QObject::connect(ui->Slider113,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter8);

    QObject::connect(ui->Slider1,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter9);

    QObject::connect(ui->LeakageLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter22);

    QObject::connect(ui->PercussionSwitchBtn,&QAbstractButton::toggled,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter10);

    QObject::connect(ui->PercussionSoftBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter21);

    QObject::connect(ui->PercussionSoftLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter15);

    QObject::connect(ui->PercussionNormalLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter16);

    QObject::connect(ui->PercussionSlowBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter12);

    QObject::connect(ui->PercussionSlowTimeBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter17);

    QObject::connect(ui->PercussionFastTimeBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter18);

    QObject::connect(ui->PercussionHarmonicBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter11);

    QObject::connect(ui->PercussionRechargeTimeBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter19);

    QObject::connect(ui->PercussionHBarLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter20);

    QObject::connect(ui->KeyOnClickLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter13);

    QObject::connect(ui->KeyOffClickLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter14);

    /* Reverse connections */

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter1,
                     ui->Slider16,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter2,
                     ui->Slider513,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter3,
                     ui->Slider8,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter4,
                     ui->Slider4,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter5,
                     ui->Slider223,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter6,
                     ui->Slider2,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter7,
                     ui->Slider135,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter8,
                     ui->Slider113,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter9,
                     ui->Slider1,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter22,
                     ui->LeakageLevelBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter10,
                     ui->PercussionSwitchBtn,&QAbstractButton::setChecked);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter21,
                     ui->PercussionSoftBox,&QComboBox::setCurrentIndex);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter15,
                     ui->PercussionSoftLevelBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter16,
                     ui->PercussionNormalLevelBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter12,
                     ui->PercussionSlowBox,&QComboBox::setCurrentIndex);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter17,
                     ui->PercussionSlowTimeBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter18,
                     ui->PercussionFastTimeBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter11,
                     ui->PercussionHarmonicBox,&QComboBox::setCurrentIndex);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter19,
                     ui->PercussionRechargeTimeBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter20,
                     ui->PercussionHBarLevelBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter13,
                     ui->KeyOnClickLevelBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter14,
                     ui->KeyOffClickLevelBox,&QSpinBox::setValue);
}

void TWOrganEditor::DisconnectSignals(Integra7Tone *tone)
{
    if (tone == NULL) return;

    Integra7SNAcousticToneCommon *snat = tone->SNAcousticToneCommon;

    QObject::disconnect(ui->Slider16,&QSlider::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter1);

    QObject::disconnect(ui->Slider513,&QSlider::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter2);

    QObject::disconnect(ui->Slider8,&QSlider::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter3);

    QObject::disconnect(ui->Slider4,&QSlider::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter4);

    QObject::disconnect(ui->Slider223,&QSlider::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter5);

    QObject::disconnect(ui->Slider2,&QSlider::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter6);

    QObject::disconnect(ui->Slider135,&QSlider::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter7);

    QObject::disconnect(ui->Slider113,&QSlider::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter8);

    QObject::disconnect(ui->Slider1,&QSlider::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter9);

    QObject::disconnect(ui->LeakageLevelBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter22);

    QObject::disconnect(ui->PercussionSwitchBtn,&QAbstractButton::toggled,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter10);

    QObject::disconnect(ui->PercussionSoftBox,&QComboBox::currentIndexChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter21);

    QObject::disconnect(ui->PercussionSoftLevelBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter15);

    QObject::disconnect(ui->PercussionNormalLevelBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter16);

    QObject::disconnect(ui->PercussionSlowBox,&QComboBox::currentIndexChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter12);

    QObject::disconnect(ui->PercussionSlowTimeBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter17);

    QObject::disconnect(ui->PercussionFastTimeBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter18);

    QObject::disconnect(ui->PercussionHarmonicBox,&QComboBox::currentIndexChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter11);

    QObject::disconnect(ui->PercussionRechargeTimeBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter19);

    QObject::disconnect(ui->PercussionHBarLevelBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter20);

    QObject::disconnect(ui->KeyOnClickLevelBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter13);

    QObject::disconnect(ui->KeyOffClickLevelBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter14);

    /* Reverse connections */

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter1,
                        ui->Slider16,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter2,
                        ui->Slider513,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter3,
                        ui->Slider8,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter4,
                        ui->Slider4,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter5,
                        ui->Slider223,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter6,
                        ui->Slider2,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter7,
                        ui->Slider135,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter8,
                        ui->Slider113,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter9,
                        ui->Slider1,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter22,
                        ui->LeakageLevelBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter10,
                        ui->PercussionSwitchBtn,&QAbstractButton::setChecked);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter21,
                        ui->PercussionSoftBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter15,
                        ui->PercussionSoftLevelBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter16,
                        ui->PercussionNormalLevelBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter12,
                        ui->PercussionSlowBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter17,
                        ui->PercussionSlowTimeBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter18,
                        ui->PercussionFastTimeBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter11,
                        ui->PercussionHarmonicBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter19,
                        ui->PercussionRechargeTimeBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter20,
                        ui->PercussionHBarLevelBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter13,
                        ui->KeyOnClickLevelBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter14,
                        ui->KeyOffClickLevelBox,&QSpinBox::setValue);
}
