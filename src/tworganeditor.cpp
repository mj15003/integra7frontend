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
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider16);

    QObject::connect(ui->Slider513,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider513);

    QObject::connect(ui->Slider8,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider8);

    QObject::connect(ui->Slider4,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider4);

    QObject::connect(ui->Slider223,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider223);

    QObject::connect(ui->Slider2,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider2);

    QObject::connect(ui->Slider135,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider135);

    QObject::connect(ui->Slider113,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider113);

    QObject::connect(ui->Slider1,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider1);

    QObject::connect(ui->LeakageLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganLeakageLevel);

    QObject::connect(ui->PercussionSwitchBtn,&QAbstractButton::toggled,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionSwitch);

    QObject::connect(ui->PercussionSoftBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionSoft);

    QObject::connect(ui->PercussionSoftLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionSoftLevel);

    QObject::connect(ui->PercussionNormalLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionNormalLevel);

    QObject::connect(ui->PercussionSlowBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionSlow);

    QObject::connect(ui->PercussionSlowTimeBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionSlowTime);

    QObject::connect(ui->PercussionFastTimeBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionFastTime);

    QObject::connect(ui->PercussionHarmonicBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionHarmonic);

    QObject::connect(ui->PercussionRechargeTimeBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionRechargeTime);

    QObject::connect(ui->PercussionHBarLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionHBarLevel);

    QObject::connect(ui->KeyOnClickLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganKeyOnClick);

    QObject::connect(ui->KeyOffClickLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganKeyOffClick);

    /* Reverse connections */

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider16,
                     ui->Slider16,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider513,
                     ui->Slider513,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider8,
                     ui->Slider8,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider4,
                     ui->Slider4,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider223,
                     ui->Slider223,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider2,
                     ui->Slider2,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider135,
                     ui->Slider135,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider113,
                     ui->Slider113,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider1,
                     ui->Slider1,&QSlider::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganLeakageLevel,
                     ui->LeakageLevelBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionSwitch,
                     ui->PercussionSwitchBtn,&QAbstractButton::setChecked);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionSoft,
                     ui->PercussionSoftBox,&QComboBox::setCurrentIndex);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionSoftLevel,
                     ui->PercussionSoftLevelBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionNormalLevel,
                     ui->PercussionNormalLevelBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionSlow,
                     ui->PercussionSlowBox,&QComboBox::setCurrentIndex);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionSlowTime,
                     ui->PercussionSlowTimeBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionFastTime,
                     ui->PercussionFastTimeBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionHarmonic,
                     ui->PercussionHarmonicBox,&QComboBox::setCurrentIndex);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionRechargeTime,
                     ui->PercussionRechargeTimeBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionHBarLevel,
                     ui->PercussionHBarLevelBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganKeyOnClick,
                     ui->KeyOnClickLevelBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::TWOrganKeyOffClick,
                     ui->KeyOffClickLevelBox,&QSpinBox::setValue);
}

void TWOrganEditor::DisconnectSignals(Integra7Tone *tone)
{
    if (tone == NULL) return;

    Integra7SNAcousticToneCommon *snat = tone->SNAcousticToneCommon;

    QObject::disconnect(ui->Slider16,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider16);

    QObject::disconnect(ui->Slider513,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider513);

    QObject::disconnect(ui->Slider8,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider8);

    QObject::disconnect(ui->Slider4,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider4);

    QObject::disconnect(ui->Slider223,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider223);

    QObject::disconnect(ui->Slider2,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider2);

    QObject::disconnect(ui->Slider135,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider135);

    QObject::disconnect(ui->Slider113,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider113);

    QObject::disconnect(ui->Slider1,&QSlider::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganSlider1);

    QObject::disconnect(ui->LeakageLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganLeakageLevel);

    QObject::disconnect(ui->PercussionSwitchBtn,&QAbstractButton::toggled,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionSwitch);

    QObject::disconnect(ui->PercussionSoftBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionSoft);

    QObject::disconnect(ui->PercussionSoftLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionSoftLevel);

    QObject::disconnect(ui->PercussionNormalLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionNormalLevel);

    QObject::disconnect(ui->PercussionSlowBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionSlow);

    QObject::disconnect(ui->PercussionSlowTimeBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionSlowTime);

    QObject::disconnect(ui->PercussionFastTimeBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionFastTime);

    QObject::disconnect(ui->PercussionHarmonicBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionHarmonic);

    QObject::disconnect(ui->PercussionRechargeTimeBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionRechargeTime);

    QObject::disconnect(ui->PercussionHBarLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganPercussionHBarLevel);

    QObject::disconnect(ui->KeyOnClickLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganKeyOnClick);

    QObject::disconnect(ui->KeyOffClickLevelBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setTWOrganKeyOffClick);

    /* Reverse connections */

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider16,
                     ui->Slider16,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider513,
                     ui->Slider513,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider8,
                     ui->Slider8,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider4,
                     ui->Slider4,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider223,
                     ui->Slider223,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider2,
                     ui->Slider2,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider135,
                     ui->Slider135,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider113,
                     ui->Slider113,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganSlider1,
                     ui->Slider1,&QSlider::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganLeakageLevel,
                     ui->LeakageLevelBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionSwitch,
                     ui->PercussionSwitchBtn,&QAbstractButton::setChecked);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionSoft,
                     ui->PercussionSoftBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionSoftLevel,
                     ui->PercussionSoftLevelBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionNormalLevel,
                     ui->PercussionNormalLevelBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionSlow,
                     ui->PercussionSlowBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionSlowTime,
                     ui->PercussionSlowTimeBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionFastTime,
                     ui->PercussionFastTimeBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionHarmonic,
                     ui->PercussionHarmonicBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionRechargeTime,
                     ui->PercussionRechargeTimeBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganPercussionHBarLevel,
                     ui->PercussionHBarLevelBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganKeyOnClick,
                     ui->KeyOnClickLevelBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::TWOrganKeyOffClick,
                     ui->KeyOffClickLevelBox,&QSpinBox::setValue);
}
