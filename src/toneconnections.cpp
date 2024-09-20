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

#include "integra7mainwindow.h"

void integra7MainWindow::ConnectPCMSynthTone(Integra7Tone *tone)
{
    if (tone == NULL) return;

    QObject::connect(ui->PCMSynthToneNameBox,&QLineEdit::textEdited,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setToneName);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthToneName,
                     ui->PCMSynthToneNameBox,&QLineEdit::setText);

    QObject::connect(ui->PCMSynthToneLevelBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPCMSynthToneLevel);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthToneLevel,
                     ui->PCMSynthToneLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMSynthTonePanBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPCMSynthTonePan);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthTonePan,
                     ui->PCMSynthTonePanBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMSynthTonePriorityBox,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPCMSynthTonePriority);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthTonePriority,
                     ui->PCMSynthTonePriorityBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PCMSynthToneCoarseTuneBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPCMSynthToneCoarseTune);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthToneCoarseTune,
                     ui->PCMSynthToneCoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMSynthToneFineTuneBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPCMSynthToneFineTune);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthToneFineTune,
                     ui->PCMSynthToneFineTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->OctaveShiftBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setOctaveShift);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::OctaveShift,
                     ui->OctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(ui->StretchTuneDepthBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setStretchTuneDepth);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::StretchTuneDepth,
                     ui->StretchTuneDepthBox,&QSpinBox::setValue);

    QObject::connect(ui->AnalogFeelBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setAnalogFeel);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::AnalogFeel,
                     ui->AnalogFeelBox,&QSpinBox::setValue);

    QObject::connect(ui->MonoPolyBox,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMonoPoly);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MonoPoly,
                     ui->MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LegatoSwitchBtn,&QPushButton::toggled,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setLegatoSwitch);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::LegatoSwitch,
                     ui->LegatoSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->LegatoRetriggerBtn,&QPushButton::toggled,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setLegatoRetrigger);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::LegatoRetrigger,
                     ui->LegatoRetriggerBtn,&QPushButton::setChecked);

    QObject::connect(ui->PortamentoSwitchBtn,&QPushButton::toggled,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPortamentoSwitch);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PortamentoSwitch,
                     ui->PortamentoSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->PortamentoModeBox,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPortamentoMode);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PortamentoMode,
                     ui->PortamentoModeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PortamentoTypeBox,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPortamentoType);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PortamentoType,
                     ui->PortamentoTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PortamentoStartBox,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPortamentoStart);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PortamentoStart,
                     ui->PortamentoStartBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PortamentoTimeBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPortamentoTime);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PortamentoTime,
                     ui->PortamentoTimeBox,&QSpinBox::setValue);    

    QObject::connect(ui->CutoffOffsetBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setCutoffOffset);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::CutoffOffset,
                     ui->CutoffOffsetBox,&QSpinBox::setValue);

    QObject::connect(ui->ResonanceOffsetBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setResonanceOffset);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::ResonanceOffset,
                     ui->ResonanceOffsetBox,&QSpinBox::setValue);

    QObject::connect(ui->AttackTimeOffsetBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setAttackTimeOffset);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::AttackTimeOffset,
                     ui->AttackTimeOffsetBox,&QSpinBox::setValue);

    QObject::connect(ui->ReleaseTimeOffsetBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setReleaseTimeOffset);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::ReleaseTimeOffset,
                     ui->ReleaseTimeOffsetBox,&QSpinBox::setValue);

    QObject::connect(ui->VelocitySensOffsetBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setVelocitySensOffset);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::VelocitySensOffset,
                     ui->VelocitySensOffsetBox,&QSpinBox::setValue);

    QObject::connect(ui->PMTControlSwitchBtn,&QPushButton::toggled,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPMTControlSwitch);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PMTControlSwitch,
                     ui->PMTControlSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->PitchBendRangeUpBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPitchBendRangeUp);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PitchBendRangeUp,
                     ui->PitchBendRangeUpBox,&QSpinBox::setValue);

    QObject::connect(ui->PitchBendRangeDownBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPitchBendRangeDown);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PitchBendRangeDown,
                     ui->PitchBendRangeDownBox,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl1SourceBox,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Source);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Source,
                     ui->MatrixControl1SourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl1Destination1Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Destination1);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Destination1,
                     ui->MatrixControl1Destination1Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl1Sens1Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Sens1);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Sens1,
                     ui->MatrixControl1Sens1Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl1Destination2Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Destination2);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Destination2,
                     ui->MatrixControl1Destination2Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl1Sens2Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Sens2);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Sens2,
                     ui->MatrixControl1Sens2Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl1Destination3Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Destination3);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Destination3,
                     ui->MatrixControl1Destination3Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl1Sens3Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Sens3);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Sens3,
                     ui->MatrixControl1Sens3Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl1Destination4Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Destination4);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Destination4,
                     ui->MatrixControl1Destination4Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl1Sens4Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Sens4);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Sens4,
                     ui->MatrixControl1Sens4Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl2SourceBox,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Source);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Source,
                     ui->MatrixControl2SourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl2Destination1Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Destination1);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Destination1,
                     ui->MatrixControl2Destination1Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl2Sens1Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Sens1);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Sens1,
                     ui->MatrixControl2Sens1Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl2Destination2Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Destination2);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Destination2,
                     ui->MatrixControl2Destination2Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl2Sens2Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Sens2);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Sens2,
                     ui->MatrixControl2Sens2Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl2Destination3Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Destination3);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Destination3,
                     ui->MatrixControl2Destination3Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl2Sens3Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Sens3);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Sens3,
                     ui->MatrixControl2Sens3Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl2Destination4Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Destination4);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Destination4,
                     ui->MatrixControl2Destination4Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl2Sens4Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Sens4);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Sens4,
                     ui->MatrixControl2Sens4Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl3SourceBox,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Source);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Source,
                     ui->MatrixControl3SourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl3Destination1Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Destination1);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Destination1,
                     ui->MatrixControl3Destination1Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl3Sens1Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Sens1);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Sens1,
                     ui->MatrixControl3Sens1Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl3Destination2Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Destination2);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Destination2,
                     ui->MatrixControl3Destination2Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl3Sens2Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Sens2);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Sens2,
                     ui->MatrixControl3Sens2Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl3Destination3Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Destination3);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Destination3,
                     ui->MatrixControl3Destination3Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl3Sens3Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Sens3);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Sens3,
                     ui->MatrixControl3Sens3Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl3Destination4Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Destination4);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Destination4,
                     ui->MatrixControl3Destination4Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl3Sens4Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Sens4);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Sens4,
                     ui->MatrixControl3Sens4Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl4SourceBox,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Source);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Source,
                     ui->MatrixControl4SourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl4Destination1Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Destination1);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Destination1,
                     ui->MatrixControl4Destination1Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl4Sens1Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Sens1);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Sens1,
                     ui->MatrixControl4Sens1Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl4Destination2Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Destination2);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Destination2,
                     ui->MatrixControl4Destination2Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl4Sens2Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Sens2);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Sens2,
                     ui->MatrixControl4Sens2Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl4Destination3Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Destination3);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Destination3,
                     ui->MatrixControl4Destination3Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl4Sens3Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Sens3);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Sens3,
                     ui->MatrixControl4Sens3Box,&QSpinBox::setValue);

    QObject::connect(ui->MatrixControl4Destination4Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Destination4);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Destination4,
                     ui->MatrixControl4Destination4Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MatrixControl4Sens4Box,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Sens4);

    QObject::connect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Sens4,
                     ui->MatrixControl4Sens4Box,&QSpinBox::setValue);

    QObject::connect(ui->StructureType12Box,&QSpinBox::valueChanged,
                         tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setStructureType12);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::StructureType12,
                     ui->StructureType12Box,&QSpinBox::setValue);

    QObject::connect(ui->Booster12Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setBooster12);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::Booster12,
                     ui->Booster12Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->StructureType34Box,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setStructureType34);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::StructureType34,
                     ui->StructureType34Box,&QSpinBox::setValue);

    QObject::connect(ui->Booster34Box,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setBooster34);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::Booster34,
                     ui->Booster34Box,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PMTVelocityControlBox,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMTVelocityControl);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMTVelocityControl,
                     ui->PMTVelocityControlBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PMT1PartialSwitchBtn,&QPushButton::toggled,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1PartialSwitch);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1PartialSwitch,
                     ui->PMT1PartialSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->PMT1KeyboardRangeLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1KeyboardRangeLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1KeyboardRangeLower,
                     ui->PMT1KeyboardRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT1KeyboardRangeUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1KeyboardRangeUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1KeyboardRangeUpper,
                     ui->PMT1KeyboardRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT1KeyboardFadeWidthLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1KeyboardFadeWidthLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1KeyboardFadeWidthLower,
                     ui->PMT1KeyboardFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT1KeyboardFadeWidthUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1KeyboardFadeWidthUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1KeyboardFadeWidthUpper,
                     ui->PMT1KeyboardFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT1VelocityRangeLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1VelocityRangeLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1VelocityRangeLower,
                     ui->PMT1VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT1VelocityRangeUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1VelocityRangeUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1VelocityRangeUpper,
                     ui->PMT1VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT1VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1VelocityFadeWidthLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1VelocityFadeWidthLower,
                     ui->PMT1VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT1VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1VelocityFadeWidthUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1VelocityFadeWidthUpper,
                     ui->PMT1VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT2PartialSwitchBtn,&QPushButton::toggled,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2PartialSwitch);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2PartialSwitch,
                     ui->PMT2PartialSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->PMT2KeyboardRangeLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2KeyboardRangeLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2KeyboardRangeLower,
                     ui->PMT2KeyboardRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT2KeyboardRangeUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2KeyboardRangeUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2KeyboardRangeUpper,
                     ui->PMT2KeyboardRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT2KeyboardFadeWidthLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2KeyboardFadeWidthLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2KeyboardFadeWidthLower,
                     ui->PMT2KeyboardFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT2KeyboardFadeWidthUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2KeyboardFadeWidthUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2KeyboardFadeWidthUpper,
                     ui->PMT2KeyboardFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT2VelocityRangeLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2VelocityRangeLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2VelocityRangeLower,
                     ui->PMT2VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT2VelocityRangeUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2VelocityRangeUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2VelocityRangeUpper,
                     ui->PMT2VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT2VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2VelocityFadeWidthLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2VelocityFadeWidthLower,
                     ui->PMT2VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT2VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2VelocityFadeWidthUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2VelocityFadeWidthUpper,
                     ui->PMT2VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT3PartialSwitchBtn,&QPushButton::toggled,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3PartialSwitch);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3PartialSwitch,
                     ui->PMT3PartialSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->PMT3KeyboardRangeLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3KeyboardRangeLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3KeyboardRangeLower,
                     ui->PMT3KeyboardRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT3KeyboardRangeUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3KeyboardRangeUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3KeyboardRangeUpper,
                     ui->PMT3KeyboardRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT3KeyboardFadeWidthLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3KeyboardFadeWidthLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3KeyboardFadeWidthLower,
                     ui->PMT3KeyboardFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT3KeyboardFadeWidthUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3KeyboardFadeWidthUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3KeyboardFadeWidthUpper,
                     ui->PMT3KeyboardFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT3VelocityRangeLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3VelocityRangeLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3VelocityRangeLower,
                     ui->PMT3VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT3VelocityRangeUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3VelocityRangeUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3VelocityRangeUpper,
                     ui->PMT3VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT3VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3VelocityFadeWidthLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3VelocityFadeWidthLower,
                     ui->PMT3VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT3VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3VelocityFadeWidthUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3VelocityFadeWidthUpper,
                     ui->PMT3VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT4PartialSwitchBtn,&QPushButton::toggled,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4PartialSwitch);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4PartialSwitch,
                     ui->PMT4PartialSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->PMT4KeyboardRangeLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4KeyboardRangeLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4KeyboardRangeLower,
                     ui->PMT4KeyboardRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT4KeyboardRangeUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4KeyboardRangeUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4KeyboardRangeUpper,
                     ui->PMT4KeyboardRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT4KeyboardFadeWidthLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4KeyboardFadeWidthLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4KeyboardFadeWidthLower,
                     ui->PMT4KeyboardFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT4KeyboardFadeWidthUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4KeyboardFadeWidthUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4KeyboardFadeWidthUpper,
                     ui->PMT4KeyboardFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT4VelocityRangeLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4VelocityRangeLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4VelocityRangeLower,
                     ui->PMT4VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT4VelocityRangeUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4VelocityRangeUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4VelocityRangeUpper,
                     ui->PMT4VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT4VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4VelocityFadeWidthLower);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4VelocityFadeWidthLower,
                     ui->PMT4VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->PMT4VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4VelocityFadeWidthUpper);

    QObject::connect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4VelocityFadeWidthUpper,
                     ui->PMT4VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PartialLevelBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialLevel);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialLevel,
                     ui->PartialLevelBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialCoarseTuneBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialCoarseTune);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialCoarseTune,
                     ui->PartialCoarseTuneBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialFineTuneBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialFineTune);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialFineTune,
                     ui->PartialFineTuneBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialRandomPitchDepthBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialRandomPitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialRandomPitchDepth,
                     ui->PartialRandomPitchDepthBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialPanBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialPan);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialPan,
                     ui->PartialPanBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialPanKeyfollowBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialPanKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialPanKeyfollow,
                     ui->PartialPanKeyfollowBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialRandomPanDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialRandomPanDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialRandomPanDepth,
                     ui->PartialRandomPanDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialAlternatePanDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialAlternatePanDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialAlternatePanDepth,
                     ui->PartialAlternatePanDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialEnvModeBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialEnvMode);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialEnvMode,
                     ui->PartialEnvModeBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialDelayModeBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialDelayMode);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialDelayMode,
                     ui->PartialDelayModeBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialDelayTimeBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialDelayTime);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialDelayTime,
                     ui->PartialDelayTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialOutputLevelBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialOutputLevel);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialOutputLevel,
                     ui->PartialOutputLevelBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialChorusSendLevelBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialChorusSendLevel);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialChorusSendLevel,
                     ui->PartialChorusSendLevelBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialReverbSendLevelBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialReverbSendLevel);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialReverbSendLevel,
                     ui->PartialReverbSendLevelBox1,&QSpinBox::setValue);

    QObject::connect(ui->PartialReceiveBenderBtn1,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialReceiveBender);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialReceiveBender,
                     ui->PartialReceiveBenderBtn1,&QPushButton::setChecked);

    QObject::connect(ui->PartialReceiveExpressionBtn1,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialReceiveExpression);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialReceiveExpression,
                     ui->PartialReceiveExpressionBtn1,&QPushButton::setChecked);

    QObject::connect(ui->PartialReceiveHoldBtn1,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialReceiveHold);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialReceiveHold,
                     ui->PartialReceiveHoldBtn1,&QPushButton::setChecked);

    QObject::connect(ui->PartialRedamperSwitchBtn1,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialRedamperSwitch);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialRedamperSwitch,
                     ui->PartialRedamperSwitchBtn1,&QPushButton::setChecked);

    QObject::connect(ui->PartialControl1Switch1Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl1Switch1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl1Switch1,
                     ui->PartialControl1Switch1Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch2Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl1Switch2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl1Switch2,
                     ui->PartialControl1Switch2Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch3Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl1Switch3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl1Switch3,
                     ui->PartialControl1Switch3Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch4Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl1Switch4);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl1Switch4,
                     ui->PartialControl1Switch4Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch1Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl2Switch1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl2Switch1,
                     ui->PartialControl2Switch1Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch2Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl2Switch2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl2Switch2,
                     ui->PartialControl2Switch2Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch3Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl2Switch3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl2Switch3,
                     ui->PartialControl2Switch3Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch4Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl2Switch4);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl2Switch4,
                     ui->PartialControl2Switch4Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch1Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl3Switch1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl3Switch1,
                     ui->PartialControl3Switch1Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch2Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl3Switch2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl3Switch2,
                     ui->PartialControl3Switch2Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch3Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl3Switch3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl3Switch3,
                     ui->PartialControl3Switch3Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch4Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl3Switch4);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl3Switch4,
                     ui->PartialControl3Switch4Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch1Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl4Switch1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl4Switch1,
                     ui->PartialControl4Switch1Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch2Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl4Switch2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl4Switch2,
                     ui->PartialControl4Switch2Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch3Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl4Switch3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl4Switch3,
                     ui->PartialControl4Switch3Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch4Box1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl4Switch4);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl4Switch4,
                     ui->PartialControl4Switch4Box1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveGroupTypeBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveGroupType);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveGroupType,
                     ui->WaveGroupTypeBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveGroupIDBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveGroupID);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveGroupID,
                     ui->WaveGroupIDBox1,&QSpinBox::setValue);

    QObject::connect(ui->WaveNumberLBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveNumberL);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveNumberL,
                     ui->WaveNumberLBox1,&QSpinBox::setValue);

    QObject::connect(ui->WaveNumberRBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveNumberR);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveNumberR,
                     ui->WaveNumberRBox1,&QSpinBox::setValue);

    QObject::connect(ui->WaveGainBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveGain);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveGain,
                     ui->WaveGainBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveFXMSwitchBtn1,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveFXMSwitch);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveFXMSwitch,
                     ui->WaveFXMSwitchBtn1,&QPushButton::setChecked);

    QObject::connect(ui->WaveFXMColorBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveFXMColor);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveFXMColor,
                     ui->WaveFXMColorBox1,&QSpinBox::setValue);

    QObject::connect(ui->WaveFXMDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveFXMDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveFXMDepth,
                     ui->WaveFXMDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->WaveTempoSyncBtn1,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveTempoSync);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveTempoSync,
                     ui->WaveTempoSyncBtn1,&QPushButton::setChecked);

    QObject::connect(ui->WavePitchKeyfollowBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWavePitchKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WavePitchKeyfollow,
                     ui->WavePitchKeyfollowBox1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvDepth,
                     ui->PitchEnvDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvVelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvVelocitySens,
                     ui->PitchEnvVelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime1VelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime1VelocitySens,
                     ui->PitchEnvTime1VelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime4VelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime4VelocitySens,
                     ui->PitchEnvTime4VelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTimeKeyfollowBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTimeKeyfollow,
                     ui->PitchEnvTimeKeyfollowBox1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime1Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime1,
                     ui->PitchEnvTime1Box1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime2Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime2,
                     ui->PitchEnvTime2Box1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime3Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime3,
                     ui->PitchEnvTime3Box1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime4Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime4,
                     ui->PitchEnvTime4Box1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel0Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvLevel0);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvLevel0,
                     ui->PitchEnvLevel0Box1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel1Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvLevel1,
                     ui->PitchEnvLevel1Box1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel2Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvLevel2,
                     ui->PitchEnvLevel2Box1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel3Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvLevel3,
                     ui->PitchEnvLevel3Box1,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel4Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvLevel4);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvLevel4,
                     ui->PitchEnvLevel4Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVFFilterTypeBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFFilterType);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFFilterType,
                     ui->TVFFilterTypeBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->TVFCutoffFrequencyBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFCutoffFrequency);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFCutoffFrequency,
                     ui->TVFCutoffFrequencyBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffKeyfollowBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFCutoffKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFCutoffKeyfollow,
                     ui->TVFCutoffKeyfollowBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffVelocityCurveBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFCutoffVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFCutoffVelocityCurve,
                     ui->TVFCutoffVelocityCurveBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffVelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFCutoffVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFCutoffVelocitySens,
                     ui->TVFCutoffVelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFResonanceBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFResonance);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFResonance,
                     ui->TVFResonanceBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFResonanceVelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFResonanceVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFResonanceVelocitySens,
                     ui->TVFResonanceVelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvDepth,
                     ui->TVFEnvDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvVelocityCurveBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvVelocityCurve,
                     ui->TVFEnvVelocityCurveBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvVelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvVelocitySens,
                     ui->TVFEnvVelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime1VelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime1VelocitySens,
                     ui->TVFEnvTime1VelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime4VelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime4VelocitySens,
                     ui->TVFEnvTime4VelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTimeKeyfollowBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTimeKeyfollow,
                     ui->TVFEnvTimeKeyfollowBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime1Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime1,
                     ui->TVFEnvTime1Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime2Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime2,
                     ui->TVFEnvTime2Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime3Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime3,
                     ui->TVFEnvTime3Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime4Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime4,
                     ui->TVFEnvTime4Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel0Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvLevel0);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvLevel0,
                     ui->TVFEnvLevel0Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel1Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvLevel1,
                     ui->TVFEnvLevel1Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel2Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvLevel2,
                     ui->TVFEnvLevel2Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel3Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvLevel3,
                     ui->TVFEnvLevel3Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel4Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvLevel4);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvLevel4,
                     ui->TVFEnvLevel4Box1,&QSpinBox::setValue);

    QObject::connect(ui->BiasLevelBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setBiasLevel);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::BiasLevel,
                     ui->BiasLevelBox1,&QSpinBox::setValue);

    QObject::connect(ui->BiasPositionBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setBiasPosition);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::BiasPosition,
                     ui->BiasPositionBox1,&QSpinBox::setValue);

    QObject::connect(ui->BiasDirectionBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setBiasDirection);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::BiasDirection,
                     ui->BiasDirectionBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->TVALevelVelocityCurveBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVALevelVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVALevelVelocityCurve,
                     ui->TVALevelVelocityCurveBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVALevelVelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVALevelVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVALevelVelocitySens,
                     ui->TVALevelVelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime1VelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime1VelocitySens,
                     ui->TVAEnvTime1VelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime4VelocitySensBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime4VelocitySens,
                     ui->TVAEnvTime4VelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTimeKeyfollowBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTimeKeyfollow,
                     ui->TVAEnvTimeKeyfollowBox1,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime1Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime1,
                     ui->TVAEnvTime1Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime2Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime2,
                     ui->TVAEnvTime2Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime3Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime3,
                     ui->TVAEnvTime3Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime4Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime4,
                     ui->TVAEnvTime4Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel1Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvLevel1,
                     ui->TVAEnvLevel1Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel2Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvLevel2,
                     ui->TVAEnvLevel2Box1,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel3Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvLevel3,
                     ui->TVAEnvLevel3Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFO1WaveformBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1Waveform);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1Waveform,
                     ui->LFO1WaveformBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1RateBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1Rate);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1Rate,
                     ui->LFO1RateBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO1OffsetBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1Offset);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1Offset,
                     ui->LFO1OffsetBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1RateDetuneBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1RateDetune);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1RateDetune,
                     ui->LFO1RateDetuneBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO1DelayTimeBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1DelayTime);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1DelayTime,
                     ui->LFO1DelayTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO1DelayTimeKeyfollowBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1DelayTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1DelayTimeKeyfollow,
                     ui->LFO1DelayTimeKeyfollowBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO1FadeModeBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1FadeMode);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1FadeMode,
                     ui->LFO1FadeModeBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1FadeTimeBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1FadeTime);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1FadeTime,
                     ui->LFO1FadeTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO1KeyTriggerBtn1,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1KeyTrigger);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1KeyTrigger,
                     ui->LFO1KeyTriggerBtn1,&QPushButton::setChecked);

    QObject::connect(ui->LFO1PitchDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1PitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1PitchDepth,
                     ui->LFO1PitchDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO1TVFDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1TVFDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1TVFDepth,
                     ui->LFO1TVFDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO1TVADepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1TVADepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1TVADepth,
                     ui->LFO1TVADepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO1PanDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1PanDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1PanDepth,
                     ui->LFO1PanDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO2WaveformBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2Waveform);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2Waveform,
                     ui->LFO2WaveformBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2RateBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2Rate);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2Rate,
                     ui->LFO2RateBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO2OffsetBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2Offset);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2Offset,
                     ui->LFO2OffsetBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2RateDetuneBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2RateDetune);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2RateDetune,
                     ui->LFO2RateDetuneBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO2DelayTimeBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2DelayTime);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2DelayTime,
                     ui->LFO2DelayTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO2DelayTimeKeyfollowBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2DelayTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2DelayTimeKeyfollow,
                     ui->LFO2DelayTimeKeyfollowBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO2FadeModeBox1,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2FadeMode);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2FadeMode,
                     ui->LFO2FadeModeBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2FadeTimeBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2FadeTime);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2FadeTime,
                     ui->LFO2FadeTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO2KeyTriggerBtn1,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2KeyTrigger);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2KeyTrigger,
                     ui->LFO2KeyTriggerBtn1,&QPushButton::setChecked);

    QObject::connect(ui->LFO2PitchDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2PitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2PitchDepth,
                     ui->LFO2PitchDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO2TVFDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2TVFDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2TVFDepth,
                     ui->LFO2TVFDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO2TVADepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2TVADepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2TVADepth,
                     ui->LFO2TVADepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFO2PanDepthBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2PanDepth);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2PanDepth,
                     ui->LFO2PanDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStepTypeBox1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStepType);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStepType,
                     ui->LFOStepTypeBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep1Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep1);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep1,
                     ui->LFOStep1Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep2Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep2);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep2,
                     ui->LFOStep2Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep3Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep3);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep3,
                     ui->LFOStep3Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep4Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep4);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep4,
                     ui->LFOStep4Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep5Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep5);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep5,
                     ui->LFOStep5Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep6Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep6);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep6,
                     ui->LFOStep6Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep7Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep7);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep7,
                     ui->LFOStep7Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep8Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep8);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep8,
                     ui->LFOStep8Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep9Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep9);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep9,
                     ui->LFOStep9Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep10Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep10);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep10,
                     ui->LFOStep10Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep11Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep11);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep11,
                     ui->LFOStep11Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep12Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep12);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep12,
                     ui->LFOStep12Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep13Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep13);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep13,
                     ui->LFOStep13Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep14Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep14);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep14,
                     ui->LFOStep14Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep15Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep15);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep15,
                     ui->LFOStep15Box1,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep16Box1,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep16);

    QObject::connect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep16,
                     ui->LFOStep16Box1,&QSpinBox::setValue);


    QObject::connect(ui->PartialLevelBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialLevel);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialLevel,
                     ui->PartialLevelBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialCoarseTuneBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialCoarseTune);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialCoarseTune,
                     ui->PartialCoarseTuneBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialFineTuneBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialFineTune);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialFineTune,
                     ui->PartialFineTuneBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialRandomPitchDepthBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialRandomPitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialRandomPitchDepth,
                     ui->PartialRandomPitchDepthBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialPanBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialPan);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialPan,
                     ui->PartialPanBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialPanKeyfollowBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialPanKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialPanKeyfollow,
                     ui->PartialPanKeyfollowBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialRandomPanDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialRandomPanDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialRandomPanDepth,
                     ui->PartialRandomPanDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialAlternatePanDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialAlternatePanDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialAlternatePanDepth,
                     ui->PartialAlternatePanDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialEnvModeBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialEnvMode);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialEnvMode,
                     ui->PartialEnvModeBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialDelayModeBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialDelayMode);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialDelayMode,
                     ui->PartialDelayModeBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialDelayTimeBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialDelayTime);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialDelayTime,
                     ui->PartialDelayTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialOutputLevelBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialOutputLevel);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialOutputLevel,
                     ui->PartialOutputLevelBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialChorusSendLevelBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialChorusSendLevel);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialChorusSendLevel,
                     ui->PartialChorusSendLevelBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialReverbSendLevelBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialReverbSendLevel);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialReverbSendLevel,
                     ui->PartialReverbSendLevelBox2,&QSpinBox::setValue);

    QObject::connect(ui->PartialReceiveBenderBtn2,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialReceiveBender);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialReceiveBender,
                     ui->PartialReceiveBenderBtn2,&QPushButton::setChecked);

    QObject::connect(ui->PartialReceiveExpressionBtn2,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialReceiveExpression);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialReceiveExpression,
                     ui->PartialReceiveExpressionBtn2,&QPushButton::setChecked);

    QObject::connect(ui->PartialReceiveHoldBtn2,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialReceiveHold);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialReceiveHold,
                     ui->PartialReceiveHoldBtn2,&QPushButton::setChecked);

    QObject::connect(ui->PartialRedamperSwitchBtn2,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialRedamperSwitch);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialRedamperSwitch,
                     ui->PartialRedamperSwitchBtn2,&QPushButton::setChecked);

    QObject::connect(ui->PartialControl1Switch1Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl1Switch1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl1Switch1,
                     ui->PartialControl1Switch1Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch2Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl1Switch2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl1Switch2,
                     ui->PartialControl1Switch2Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch3Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl1Switch3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl1Switch3,
                     ui->PartialControl1Switch3Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch4Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl1Switch4);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl1Switch4,
                     ui->PartialControl1Switch4Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch1Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl2Switch1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl2Switch1,
                     ui->PartialControl2Switch1Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch2Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl2Switch2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl2Switch2,
                     ui->PartialControl2Switch2Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch3Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl2Switch3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl2Switch3,
                     ui->PartialControl2Switch3Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch4Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl2Switch4);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl2Switch4,
                     ui->PartialControl2Switch4Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch1Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl3Switch1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl3Switch1,
                     ui->PartialControl3Switch1Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch2Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl3Switch2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl3Switch2,
                     ui->PartialControl3Switch2Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch3Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl3Switch3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl3Switch3,
                     ui->PartialControl3Switch3Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch4Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl3Switch4);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl3Switch4,
                     ui->PartialControl3Switch4Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch1Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl4Switch1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl4Switch1,
                     ui->PartialControl4Switch1Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch2Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl4Switch2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl4Switch2,
                     ui->PartialControl4Switch2Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch3Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl4Switch3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl4Switch3,
                     ui->PartialControl4Switch3Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch4Box2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl4Switch4);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl4Switch4,
                     ui->PartialControl4Switch4Box2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveGroupTypeBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveGroupType);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveGroupType,
                     ui->WaveGroupTypeBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveGroupIDBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveGroupID);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveGroupID,
                     ui->WaveGroupIDBox2,&QSpinBox::setValue);

    QObject::connect(ui->WaveNumberLBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveNumberL);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveNumberL,
                     ui->WaveNumberLBox2,&QSpinBox::setValue);

    QObject::connect(ui->WaveNumberRBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveNumberR);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveNumberR,
                     ui->WaveNumberRBox2,&QSpinBox::setValue);

    QObject::connect(ui->WaveGainBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveGain);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveGain,
                     ui->WaveGainBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveFXMSwitchBtn2,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveFXMSwitch);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveFXMSwitch,
                     ui->WaveFXMSwitchBtn2,&QPushButton::setChecked);

    QObject::connect(ui->WaveFXMColorBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveFXMColor);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveFXMColor,
                     ui->WaveFXMColorBox2,&QSpinBox::setValue);

    QObject::connect(ui->WaveFXMDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveFXMDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveFXMDepth,
                     ui->WaveFXMDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->WaveTempoSyncBtn2,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveTempoSync);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveTempoSync,
                     ui->WaveTempoSyncBtn2,&QPushButton::setChecked);

    QObject::connect(ui->WavePitchKeyfollowBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWavePitchKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WavePitchKeyfollow,
                     ui->WavePitchKeyfollowBox2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvDepth,
                     ui->PitchEnvDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvVelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvVelocitySens,
                     ui->PitchEnvVelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime1VelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime1VelocitySens,
                     ui->PitchEnvTime1VelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime4VelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime4VelocitySens,
                     ui->PitchEnvTime4VelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTimeKeyfollowBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTimeKeyfollow,
                     ui->PitchEnvTimeKeyfollowBox2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime1Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime1,
                     ui->PitchEnvTime1Box2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime2Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime2,
                     ui->PitchEnvTime2Box2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime3Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime3,
                     ui->PitchEnvTime3Box2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime4Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime4,
                     ui->PitchEnvTime4Box2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel0Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvLevel0);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvLevel0,
                     ui->PitchEnvLevel0Box2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel1Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvLevel1,
                     ui->PitchEnvLevel1Box2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel2Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvLevel2,
                     ui->PitchEnvLevel2Box2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel3Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvLevel3,
                     ui->PitchEnvLevel3Box2,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel4Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvLevel4);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvLevel4,
                     ui->PitchEnvLevel4Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVFFilterTypeBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFFilterType);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFFilterType,
                     ui->TVFFilterTypeBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->TVFCutoffFrequencyBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFCutoffFrequency);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFCutoffFrequency,
                     ui->TVFCutoffFrequencyBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffKeyfollowBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFCutoffKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFCutoffKeyfollow,
                     ui->TVFCutoffKeyfollowBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffVelocityCurveBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFCutoffVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFCutoffVelocityCurve,
                     ui->TVFCutoffVelocityCurveBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffVelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFCutoffVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFCutoffVelocitySens,
                     ui->TVFCutoffVelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFResonanceBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFResonance);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFResonance,
                     ui->TVFResonanceBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFResonanceVelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFResonanceVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFResonanceVelocitySens,
                     ui->TVFResonanceVelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvDepth,
                     ui->TVFEnvDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvVelocityCurveBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvVelocityCurve,
                     ui->TVFEnvVelocityCurveBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvVelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvVelocitySens,
                     ui->TVFEnvVelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime1VelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime1VelocitySens,
                     ui->TVFEnvTime1VelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime4VelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime4VelocitySens,
                     ui->TVFEnvTime4VelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTimeKeyfollowBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTimeKeyfollow,
                     ui->TVFEnvTimeKeyfollowBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime1Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime1,
                     ui->TVFEnvTime1Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime2Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime2,
                     ui->TVFEnvTime2Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime3Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime3,
                     ui->TVFEnvTime3Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime4Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime4,
                     ui->TVFEnvTime4Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel0Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvLevel0);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvLevel0,
                     ui->TVFEnvLevel0Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel1Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvLevel1,
                     ui->TVFEnvLevel1Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel2Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvLevel2,
                     ui->TVFEnvLevel2Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel3Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvLevel3,
                     ui->TVFEnvLevel3Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel4Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvLevel4);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvLevel4,
                     ui->TVFEnvLevel4Box2,&QSpinBox::setValue);

    QObject::connect(ui->BiasLevelBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setBiasLevel);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::BiasLevel,
                     ui->BiasLevelBox2,&QSpinBox::setValue);

    QObject::connect(ui->BiasPositionBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setBiasPosition);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::BiasPosition,
                     ui->BiasPositionBox2,&QSpinBox::setValue);

    QObject::connect(ui->BiasDirectionBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setBiasDirection);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::BiasDirection,
                     ui->BiasDirectionBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->TVALevelVelocityCurveBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVALevelVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVALevelVelocityCurve,
                     ui->TVALevelVelocityCurveBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVALevelVelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVALevelVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVALevelVelocitySens,
                     ui->TVALevelVelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime1VelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime1VelocitySens,
                     ui->TVAEnvTime1VelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime4VelocitySensBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime4VelocitySens,
                     ui->TVAEnvTime4VelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTimeKeyfollowBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTimeKeyfollow,
                     ui->TVAEnvTimeKeyfollowBox2,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime1Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime1,
                     ui->TVAEnvTime1Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime2Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime2,
                     ui->TVAEnvTime2Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime3Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime3,
                     ui->TVAEnvTime3Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime4Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime4,
                     ui->TVAEnvTime4Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel1Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvLevel1,
                     ui->TVAEnvLevel1Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel2Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvLevel2,
                     ui->TVAEnvLevel2Box2,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel3Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvLevel3,
                     ui->TVAEnvLevel3Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFO1WaveformBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1Waveform);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1Waveform,
                     ui->LFO1WaveformBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1RateBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1Rate);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1Rate,
                     ui->LFO1RateBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO1OffsetBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1Offset);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1Offset,
                     ui->LFO1OffsetBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1RateDetuneBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1RateDetune);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1RateDetune,
                     ui->LFO1RateDetuneBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO1DelayTimeBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1DelayTime);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1DelayTime,
                     ui->LFO1DelayTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO1DelayTimeKeyfollowBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1DelayTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1DelayTimeKeyfollow,
                     ui->LFO1DelayTimeKeyfollowBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO1FadeModeBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1FadeMode);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1FadeMode,
                     ui->LFO1FadeModeBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1FadeTimeBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1FadeTime);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1FadeTime,
                     ui->LFO1FadeTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO1KeyTriggerBtn2,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1KeyTrigger);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1KeyTrigger,
                     ui->LFO1KeyTriggerBtn2,&QPushButton::setChecked);

    QObject::connect(ui->LFO1PitchDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1PitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1PitchDepth,
                     ui->LFO1PitchDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO1TVFDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1TVFDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1TVFDepth,
                     ui->LFO1TVFDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO1TVADepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1TVADepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1TVADepth,
                     ui->LFO1TVADepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO1PanDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1PanDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1PanDepth,
                     ui->LFO1PanDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO2WaveformBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2Waveform);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2Waveform,
                     ui->LFO2WaveformBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2RateBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2Rate);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2Rate,
                     ui->LFO2RateBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO2OffsetBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2Offset);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2Offset,
                     ui->LFO2OffsetBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2RateDetuneBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2RateDetune);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2RateDetune,
                     ui->LFO2RateDetuneBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO2DelayTimeBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2DelayTime);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2DelayTime,
                     ui->LFO2DelayTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO2DelayTimeKeyfollowBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2DelayTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2DelayTimeKeyfollow,
                     ui->LFO2DelayTimeKeyfollowBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO2FadeModeBox2,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2FadeMode);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2FadeMode,
                     ui->LFO2FadeModeBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2FadeTimeBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2FadeTime);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2FadeTime,
                     ui->LFO2FadeTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO2KeyTriggerBtn2,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2KeyTrigger);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2KeyTrigger,
                     ui->LFO2KeyTriggerBtn2,&QPushButton::setChecked);

    QObject::connect(ui->LFO2PitchDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2PitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2PitchDepth,
                     ui->LFO2PitchDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO2TVFDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2TVFDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2TVFDepth,
                     ui->LFO2TVFDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO2TVADepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2TVADepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2TVADepth,
                     ui->LFO2TVADepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFO2PanDepthBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2PanDepth);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2PanDepth,
                     ui->LFO2PanDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStepTypeBox2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStepType);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStepType,
                     ui->LFOStepTypeBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep1Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep1);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep1,
                     ui->LFOStep1Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep2Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep2);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep2,
                     ui->LFOStep2Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep3Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep3);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep3,
                     ui->LFOStep3Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep4Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep4);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep4,
                     ui->LFOStep4Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep5Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep5);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep5,
                     ui->LFOStep5Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep6Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep6);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep6,
                     ui->LFOStep6Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep7Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep7);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep7,
                     ui->LFOStep7Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep8Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep8);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep8,
                     ui->LFOStep8Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep9Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep9);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep9,
                     ui->LFOStep9Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep10Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep10);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep10,
                     ui->LFOStep10Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep11Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep11);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep11,
                     ui->LFOStep11Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep12Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep12);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep12,
                     ui->LFOStep12Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep13Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep13);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep13,
                     ui->LFOStep13Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep14Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep14);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep14,
                     ui->LFOStep14Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep15Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep15);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep15,
                     ui->LFOStep15Box2,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep16Box2,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep16);

    QObject::connect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep16,
                     ui->LFOStep16Box2,&QSpinBox::setValue);

    QObject::connect(ui->PartialLevelBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialLevel);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialLevel,
                     ui->PartialLevelBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialCoarseTuneBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialCoarseTune);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialCoarseTune,
                     ui->PartialCoarseTuneBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialFineTuneBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialFineTune);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialFineTune,
                     ui->PartialFineTuneBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialRandomPitchDepthBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialRandomPitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialRandomPitchDepth,
                     ui->PartialRandomPitchDepthBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialPanBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialPan);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialPan,
                     ui->PartialPanBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialPanKeyfollowBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialPanKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialPanKeyfollow,
                     ui->PartialPanKeyfollowBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialRandomPanDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialRandomPanDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialRandomPanDepth,
                     ui->PartialRandomPanDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialAlternatePanDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialAlternatePanDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialAlternatePanDepth,
                     ui->PartialAlternatePanDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialEnvModeBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialEnvMode);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialEnvMode,
                     ui->PartialEnvModeBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialDelayModeBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialDelayMode);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialDelayMode,
                     ui->PartialDelayModeBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialDelayTimeBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialDelayTime);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialDelayTime,
                     ui->PartialDelayTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialOutputLevelBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialOutputLevel);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialOutputLevel,
                     ui->PartialOutputLevelBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialChorusSendLevelBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialChorusSendLevel);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialChorusSendLevel,
                     ui->PartialChorusSendLevelBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialReverbSendLevelBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialReverbSendLevel);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialReverbSendLevel,
                     ui->PartialReverbSendLevelBox3,&QSpinBox::setValue);

    QObject::connect(ui->PartialReceiveBenderBtn3,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialReceiveBender);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialReceiveBender,
                     ui->PartialReceiveBenderBtn3,&QPushButton::setChecked);

    QObject::connect(ui->PartialReceiveExpressionBtn3,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialReceiveExpression);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialReceiveExpression,
                     ui->PartialReceiveExpressionBtn3,&QPushButton::setChecked);

    QObject::connect(ui->PartialReceiveHoldBtn3,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialReceiveHold);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialReceiveHold,
                     ui->PartialReceiveHoldBtn3,&QPushButton::setChecked);

    QObject::connect(ui->PartialRedamperSwitchBtn3,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialRedamperSwitch);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialRedamperSwitch,
                     ui->PartialRedamperSwitchBtn3,&QPushButton::setChecked);

    QObject::connect(ui->PartialControl1Switch1Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl1Switch1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl1Switch1,
                     ui->PartialControl1Switch1Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch2Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl1Switch2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl1Switch2,
                     ui->PartialControl1Switch2Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch3Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl1Switch3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl1Switch3,
                     ui->PartialControl1Switch3Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch4Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl1Switch4);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl1Switch4,
                     ui->PartialControl1Switch4Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch1Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl2Switch1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl2Switch1,
                     ui->PartialControl2Switch1Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch2Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl2Switch2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl2Switch2,
                     ui->PartialControl2Switch2Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch3Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl2Switch3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl2Switch3,
                     ui->PartialControl2Switch3Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch4Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl2Switch4);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl2Switch4,
                     ui->PartialControl2Switch4Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch1Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl3Switch1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl3Switch1,
                     ui->PartialControl3Switch1Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch2Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl3Switch2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl3Switch2,
                     ui->PartialControl3Switch2Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch3Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl3Switch3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl3Switch3,
                     ui->PartialControl3Switch3Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch4Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl3Switch4);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl3Switch4,
                     ui->PartialControl3Switch4Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch1Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl4Switch1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl4Switch1,
                     ui->PartialControl4Switch1Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch2Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl4Switch2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl4Switch2,
                     ui->PartialControl4Switch2Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch3Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl4Switch3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl4Switch3,
                     ui->PartialControl4Switch3Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch4Box3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl4Switch4);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl4Switch4,
                     ui->PartialControl4Switch4Box3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveGroupTypeBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveGroupType);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveGroupType,
                     ui->WaveGroupTypeBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveGroupIDBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveGroupID);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveGroupID,
                     ui->WaveGroupIDBox3,&QSpinBox::setValue);

    QObject::connect(ui->WaveNumberLBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveNumberL);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveNumberL,
                     ui->WaveNumberLBox3,&QSpinBox::setValue);

    QObject::connect(ui->WaveNumberRBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveNumberR);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveNumberR,
                     ui->WaveNumberRBox3,&QSpinBox::setValue);

    QObject::connect(ui->WaveGainBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveGain);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveGain,
                     ui->WaveGainBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveFXMSwitchBtn3,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveFXMSwitch);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveFXMSwitch,
                     ui->WaveFXMSwitchBtn3,&QPushButton::setChecked);

    QObject::connect(ui->WaveFXMColorBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveFXMColor);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveFXMColor,
                     ui->WaveFXMColorBox3,&QSpinBox::setValue);

    QObject::connect(ui->WaveFXMDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveFXMDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveFXMDepth,
                     ui->WaveFXMDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->WaveTempoSyncBtn3,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveTempoSync);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveTempoSync,
                     ui->WaveTempoSyncBtn3,&QPushButton::setChecked);

    QObject::connect(ui->WavePitchKeyfollowBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWavePitchKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WavePitchKeyfollow,
                     ui->WavePitchKeyfollowBox3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvDepth,
                     ui->PitchEnvDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvVelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvVelocitySens,
                     ui->PitchEnvVelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime1VelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime1VelocitySens,
                     ui->PitchEnvTime1VelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime4VelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime4VelocitySens,
                     ui->PitchEnvTime4VelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTimeKeyfollowBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTimeKeyfollow,
                     ui->PitchEnvTimeKeyfollowBox3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime1Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime1,
                     ui->PitchEnvTime1Box3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime2Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime2,
                     ui->PitchEnvTime2Box3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime3Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime3,
                     ui->PitchEnvTime3Box3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime4Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime4,
                     ui->PitchEnvTime4Box3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel0Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvLevel0);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvLevel0,
                     ui->PitchEnvLevel0Box3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel1Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvLevel1,
                     ui->PitchEnvLevel1Box3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel2Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvLevel2,
                     ui->PitchEnvLevel2Box3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel3Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvLevel3,
                     ui->PitchEnvLevel3Box3,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel4Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvLevel4);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvLevel4,
                     ui->PitchEnvLevel4Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVFFilterTypeBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFFilterType);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFFilterType,
                     ui->TVFFilterTypeBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->TVFCutoffFrequencyBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFCutoffFrequency);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFCutoffFrequency,
                     ui->TVFCutoffFrequencyBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffKeyfollowBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFCutoffKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFCutoffKeyfollow,
                     ui->TVFCutoffKeyfollowBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffVelocityCurveBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFCutoffVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFCutoffVelocityCurve,
                     ui->TVFCutoffVelocityCurveBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffVelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFCutoffVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFCutoffVelocitySens,
                     ui->TVFCutoffVelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFResonanceBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFResonance);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFResonance,
                     ui->TVFResonanceBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFResonanceVelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFResonanceVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFResonanceVelocitySens,
                     ui->TVFResonanceVelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvDepth,
                     ui->TVFEnvDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvVelocityCurveBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvVelocityCurve,
                     ui->TVFEnvVelocityCurveBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvVelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvVelocitySens,
                     ui->TVFEnvVelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime1VelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime1VelocitySens,
                     ui->TVFEnvTime1VelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime4VelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime4VelocitySens,
                     ui->TVFEnvTime4VelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTimeKeyfollowBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTimeKeyfollow,
                     ui->TVFEnvTimeKeyfollowBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime1Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime1,
                     ui->TVFEnvTime1Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime2Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime2,
                     ui->TVFEnvTime2Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime3Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime3,
                     ui->TVFEnvTime3Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime4Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime4,
                     ui->TVFEnvTime4Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel0Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvLevel0);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvLevel0,
                     ui->TVFEnvLevel0Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel1Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvLevel1,
                     ui->TVFEnvLevel1Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel2Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvLevel2,
                     ui->TVFEnvLevel2Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel3Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvLevel3,
                     ui->TVFEnvLevel3Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel4Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvLevel4);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvLevel4,
                     ui->TVFEnvLevel4Box3,&QSpinBox::setValue);

    QObject::connect(ui->BiasLevelBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setBiasLevel);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::BiasLevel,
                     ui->BiasLevelBox3,&QSpinBox::setValue);

    QObject::connect(ui->BiasPositionBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setBiasPosition);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::BiasPosition,
                     ui->BiasPositionBox3,&QSpinBox::setValue);

    QObject::connect(ui->BiasDirectionBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setBiasDirection);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::BiasDirection,
                     ui->BiasDirectionBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->TVALevelVelocityCurveBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVALevelVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVALevelVelocityCurve,
                     ui->TVALevelVelocityCurveBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVALevelVelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVALevelVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVALevelVelocitySens,
                     ui->TVALevelVelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime1VelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime1VelocitySens,
                     ui->TVAEnvTime1VelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime4VelocitySensBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime4VelocitySens,
                     ui->TVAEnvTime4VelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTimeKeyfollowBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTimeKeyfollow,
                     ui->TVAEnvTimeKeyfollowBox3,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime1Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime1,
                     ui->TVAEnvTime1Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime2Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime2,
                     ui->TVAEnvTime2Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime3Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime3,
                     ui->TVAEnvTime3Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime4Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime4,
                     ui->TVAEnvTime4Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel1Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvLevel1,
                     ui->TVAEnvLevel1Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel2Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvLevel2,
                     ui->TVAEnvLevel2Box3,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel3Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvLevel3,
                     ui->TVAEnvLevel3Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFO1WaveformBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1Waveform);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1Waveform,
                     ui->LFO1WaveformBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1RateBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1Rate);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1Rate,
                     ui->LFO1RateBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO1OffsetBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1Offset);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1Offset,
                     ui->LFO1OffsetBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1RateDetuneBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1RateDetune);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1RateDetune,
                     ui->LFO1RateDetuneBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO1DelayTimeBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1DelayTime);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1DelayTime,
                     ui->LFO1DelayTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO1DelayTimeKeyfollowBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1DelayTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1DelayTimeKeyfollow,
                     ui->LFO1DelayTimeKeyfollowBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO1FadeModeBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1FadeMode);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1FadeMode,
                     ui->LFO1FadeModeBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1FadeTimeBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1FadeTime);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1FadeTime,
                     ui->LFO1FadeTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO1KeyTriggerBtn3,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1KeyTrigger);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1KeyTrigger,
                     ui->LFO1KeyTriggerBtn3,&QPushButton::setChecked);

    QObject::connect(ui->LFO1PitchDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1PitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1PitchDepth,
                     ui->LFO1PitchDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO1TVFDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1TVFDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1TVFDepth,
                     ui->LFO1TVFDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO1TVADepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1TVADepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1TVADepth,
                     ui->LFO1TVADepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO1PanDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1PanDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1PanDepth,
                     ui->LFO1PanDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO2WaveformBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2Waveform);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2Waveform,
                     ui->LFO2WaveformBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2RateBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2Rate);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2Rate,
                     ui->LFO2RateBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO2OffsetBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2Offset);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2Offset,
                     ui->LFO2OffsetBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2RateDetuneBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2RateDetune);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2RateDetune,
                     ui->LFO2RateDetuneBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO2DelayTimeBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2DelayTime);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2DelayTime,
                     ui->LFO2DelayTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO2DelayTimeKeyfollowBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2DelayTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2DelayTimeKeyfollow,
                     ui->LFO2DelayTimeKeyfollowBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO2FadeModeBox3,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2FadeMode);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2FadeMode,
                     ui->LFO2FadeModeBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2FadeTimeBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2FadeTime);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2FadeTime,
                     ui->LFO2FadeTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO2KeyTriggerBtn3,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2KeyTrigger);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2KeyTrigger,
                     ui->LFO2KeyTriggerBtn3,&QPushButton::setChecked);

    QObject::connect(ui->LFO2PitchDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2PitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2PitchDepth,
                     ui->LFO2PitchDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO2TVFDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2TVFDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2TVFDepth,
                     ui->LFO2TVFDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO2TVADepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2TVADepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2TVADepth,
                     ui->LFO2TVADepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFO2PanDepthBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2PanDepth);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2PanDepth,
                     ui->LFO2PanDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStepTypeBox3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStepType);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStepType,
                     ui->LFOStepTypeBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep1Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep1);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep1,
                     ui->LFOStep1Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep2Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep2);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep2,
                     ui->LFOStep2Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep3Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep3);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep3,
                     ui->LFOStep3Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep4Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep4);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep4,
                     ui->LFOStep4Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep5Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep5);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep5,
                     ui->LFOStep5Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep6Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep6);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep6,
                     ui->LFOStep6Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep7Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep7);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep7,
                     ui->LFOStep7Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep8Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep8);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep8,
                     ui->LFOStep8Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep9Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep9);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep9,
                     ui->LFOStep9Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep10Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep10);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep10,
                     ui->LFOStep10Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep11Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep11);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep11,
                     ui->LFOStep11Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep12Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep12);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep12,
                     ui->LFOStep12Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep13Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep13);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep13,
                     ui->LFOStep13Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep14Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep14);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep14,
                     ui->LFOStep14Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep15Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep15);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep15,
                     ui->LFOStep15Box3,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep16Box3,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep16);

    QObject::connect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep16,
                     ui->LFOStep16Box3,&QSpinBox::setValue);

    QObject::connect(ui->PartialLevelBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialLevel);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialLevel,
                     ui->PartialLevelBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialCoarseTuneBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialCoarseTune);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialCoarseTune,
                     ui->PartialCoarseTuneBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialFineTuneBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialFineTune);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialFineTune,
                     ui->PartialFineTuneBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialRandomPitchDepthBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialRandomPitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialRandomPitchDepth,
                     ui->PartialRandomPitchDepthBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialPanBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialPan);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialPan,
                     ui->PartialPanBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialPanKeyfollowBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialPanKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialPanKeyfollow,
                     ui->PartialPanKeyfollowBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialRandomPanDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialRandomPanDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialRandomPanDepth,
                     ui->PartialRandomPanDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialAlternatePanDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialAlternatePanDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialAlternatePanDepth,
                     ui->PartialAlternatePanDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialEnvModeBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialEnvMode);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialEnvMode,
                     ui->PartialEnvModeBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialDelayModeBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialDelayMode);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialDelayMode,
                     ui->PartialDelayModeBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialDelayTimeBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialDelayTime);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialDelayTime,
                     ui->PartialDelayTimeBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialOutputLevelBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialOutputLevel);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialOutputLevel,
                     ui->PartialOutputLevelBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialChorusSendLevelBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialChorusSendLevel);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialChorusSendLevel,
                     ui->PartialChorusSendLevelBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialReverbSendLevelBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialReverbSendLevel);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialReverbSendLevel,
                     ui->PartialReverbSendLevelBox4,&QSpinBox::setValue);

    QObject::connect(ui->PartialReceiveBenderBtn4,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialReceiveBender);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialReceiveBender,
                     ui->PartialReceiveBenderBtn4,&QPushButton::setChecked);

    QObject::connect(ui->PartialReceiveExpressionBtn4,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialReceiveExpression);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialReceiveExpression,
                     ui->PartialReceiveExpressionBtn4,&QPushButton::setChecked);

    QObject::connect(ui->PartialReceiveHoldBtn4,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialReceiveHold);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialReceiveHold,
                     ui->PartialReceiveHoldBtn4,&QPushButton::setChecked);

    QObject::connect(ui->PartialRedamperSwitchBtn4,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialRedamperSwitch);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialRedamperSwitch,
                     ui->PartialRedamperSwitchBtn4,&QPushButton::setChecked);

    QObject::connect(ui->PartialControl1Switch1Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl1Switch1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl1Switch1,
                     ui->PartialControl1Switch1Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch2Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl1Switch2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl1Switch2,
                     ui->PartialControl1Switch2Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch3Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl1Switch3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl1Switch3,
                     ui->PartialControl1Switch3Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl1Switch4Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl1Switch4);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl1Switch4,
                     ui->PartialControl1Switch4Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch1Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl2Switch1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl2Switch1,
                     ui->PartialControl2Switch1Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch2Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl2Switch2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl2Switch2,
                     ui->PartialControl2Switch2Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch3Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl2Switch3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl2Switch3,
                     ui->PartialControl2Switch3Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl2Switch4Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl2Switch4);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl2Switch4,
                     ui->PartialControl2Switch4Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch1Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl3Switch1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl3Switch1,
                     ui->PartialControl3Switch1Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch2Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl3Switch2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl3Switch2,
                     ui->PartialControl3Switch2Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch3Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl3Switch3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl3Switch3,
                     ui->PartialControl3Switch3Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl3Switch4Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl3Switch4);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl3Switch4,
                     ui->PartialControl3Switch4Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch1Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl4Switch1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl4Switch1,
                     ui->PartialControl4Switch1Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch2Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl4Switch2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl4Switch2,
                     ui->PartialControl4Switch2Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch3Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl4Switch3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl4Switch3,
                     ui->PartialControl4Switch3Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialControl4Switch4Box4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl4Switch4);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl4Switch4,
                     ui->PartialControl4Switch4Box4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveGroupTypeBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveGroupType);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveGroupType,
                     ui->WaveGroupTypeBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveGroupIDBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveGroupID);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveGroupID,
                     ui->WaveGroupIDBox4,&QSpinBox::setValue);

    QObject::connect(ui->WaveNumberLBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveNumberL);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveNumberL,
                     ui->WaveNumberLBox4,&QSpinBox::setValue);

    QObject::connect(ui->WaveNumberRBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveNumberR);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveNumberR,
                     ui->WaveNumberRBox4,&QSpinBox::setValue);

    QObject::connect(ui->WaveGainBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveGain);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveGain,
                     ui->WaveGainBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveFXMSwitchBtn4,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveFXMSwitch);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveFXMSwitch,
                     ui->WaveFXMSwitchBtn4,&QPushButton::setChecked);

    QObject::connect(ui->WaveFXMColorBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveFXMColor);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveFXMColor,
                     ui->WaveFXMColorBox4,&QSpinBox::setValue);

    QObject::connect(ui->WaveFXMDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveFXMDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveFXMDepth,
                     ui->WaveFXMDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->WaveTempoSyncBtn4,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveTempoSync);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveTempoSync,
                     ui->WaveTempoSyncBtn4,&QPushButton::setChecked);

    QObject::connect(ui->WavePitchKeyfollowBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWavePitchKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WavePitchKeyfollow,
                     ui->WavePitchKeyfollowBox4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvDepth,
                     ui->PitchEnvDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvVelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvVelocitySens,
                     ui->PitchEnvVelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime1VelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime1VelocitySens,
                     ui->PitchEnvTime1VelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime4VelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime4VelocitySens,
                     ui->PitchEnvTime4VelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTimeKeyfollowBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTimeKeyfollow,
                     ui->PitchEnvTimeKeyfollowBox4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime1Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime1,
                     ui->PitchEnvTime1Box4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime2Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime2,
                     ui->PitchEnvTime2Box4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime3Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime3,
                     ui->PitchEnvTime3Box4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvTime4Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime4,
                     ui->PitchEnvTime4Box4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel0Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvLevel0);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvLevel0,
                     ui->PitchEnvLevel0Box4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel1Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvLevel1,
                     ui->PitchEnvLevel1Box4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel2Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvLevel2,
                     ui->PitchEnvLevel2Box4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel3Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvLevel3,
                     ui->PitchEnvLevel3Box4,&QSpinBox::setValue);

    QObject::connect(ui->PitchEnvLevel4Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvLevel4);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvLevel4,
                     ui->PitchEnvLevel4Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVFFilterTypeBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFFilterType);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFFilterType,
                     ui->TVFFilterTypeBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->TVFCutoffFrequencyBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFCutoffFrequency);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFCutoffFrequency,
                     ui->TVFCutoffFrequencyBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffKeyfollowBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFCutoffKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFCutoffKeyfollow,
                     ui->TVFCutoffKeyfollowBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffVelocityCurveBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFCutoffVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFCutoffVelocityCurve,
                     ui->TVFCutoffVelocityCurveBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFCutoffVelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFCutoffVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFCutoffVelocitySens,
                     ui->TVFCutoffVelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFResonanceBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFResonance);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFResonance,
                     ui->TVFResonanceBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFResonanceVelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFResonanceVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFResonanceVelocitySens,
                     ui->TVFResonanceVelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvDepth,
                     ui->TVFEnvDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvVelocityCurveBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvVelocityCurve,
                     ui->TVFEnvVelocityCurveBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvVelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvVelocitySens,
                     ui->TVFEnvVelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime1VelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime1VelocitySens,
                     ui->TVFEnvTime1VelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime4VelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime4VelocitySens,
                     ui->TVFEnvTime4VelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTimeKeyfollowBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTimeKeyfollow,
                     ui->TVFEnvTimeKeyfollowBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime1Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime1,
                     ui->TVFEnvTime1Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime2Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime2,
                     ui->TVFEnvTime2Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime3Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime3,
                     ui->TVFEnvTime3Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvTime4Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime4,
                     ui->TVFEnvTime4Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel0Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvLevel0);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvLevel0,
                     ui->TVFEnvLevel0Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel1Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvLevel1,
                     ui->TVFEnvLevel1Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel2Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvLevel2,
                     ui->TVFEnvLevel2Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel3Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvLevel3,
                     ui->TVFEnvLevel3Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvLevel4Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvLevel4);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvLevel4,
                     ui->TVFEnvLevel4Box4,&QSpinBox::setValue);

    QObject::connect(ui->BiasLevelBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setBiasLevel);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::BiasLevel,
                     ui->BiasLevelBox4,&QSpinBox::setValue);

    QObject::connect(ui->BiasPositionBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setBiasPosition);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::BiasPosition,
                     ui->BiasPositionBox4,&QSpinBox::setValue);

    QObject::connect(ui->BiasDirectionBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setBiasDirection);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::BiasDirection,
                     ui->BiasDirectionBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->TVALevelVelocityCurveBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVALevelVelocityCurve);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVALevelVelocityCurve,
                     ui->TVALevelVelocityCurveBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVALevelVelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVALevelVelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVALevelVelocitySens,
                     ui->TVALevelVelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime1VelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime1VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime1VelocitySens,
                     ui->TVAEnvTime1VelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime4VelocitySensBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime4VelocitySens);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime4VelocitySens,
                     ui->TVAEnvTime4VelocitySensBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTimeKeyfollowBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTimeKeyfollow,
                     ui->TVAEnvTimeKeyfollowBox4,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime1Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime1,
                     ui->TVAEnvTime1Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime2Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime2,
                     ui->TVAEnvTime2Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime3Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime3,
                     ui->TVAEnvTime3Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvTime4Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime4);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime4,
                     ui->TVAEnvTime4Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel1Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvLevel1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvLevel1,
                     ui->TVAEnvLevel1Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel2Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvLevel2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvLevel2,
                     ui->TVAEnvLevel2Box4,&QSpinBox::setValue);

    QObject::connect(ui->TVAEnvLevel3Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvLevel3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvLevel3,
                     ui->TVAEnvLevel3Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFO1WaveformBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1Waveform);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1Waveform,
                     ui->LFO1WaveformBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1RateBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1Rate);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1Rate,
                     ui->LFO1RateBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO1OffsetBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1Offset);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1Offset,
                     ui->LFO1OffsetBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1RateDetuneBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1RateDetune);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1RateDetune,
                     ui->LFO1RateDetuneBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO1DelayTimeBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1DelayTime);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1DelayTime,
                     ui->LFO1DelayTimeBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO1DelayTimeKeyfollowBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1DelayTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1DelayTimeKeyfollow,
                     ui->LFO1DelayTimeKeyfollowBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO1FadeModeBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1FadeMode);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1FadeMode,
                     ui->LFO1FadeModeBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO1FadeTimeBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1FadeTime);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1FadeTime,
                     ui->LFO1FadeTimeBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO1KeyTriggerBtn4,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1KeyTrigger);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1KeyTrigger,
                     ui->LFO1KeyTriggerBtn4,&QPushButton::setChecked);

    QObject::connect(ui->LFO1PitchDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1PitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1PitchDepth,
                     ui->LFO1PitchDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO1TVFDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1TVFDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1TVFDepth,
                     ui->LFO1TVFDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO1TVADepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1TVADepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1TVADepth,
                     ui->LFO1TVADepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO1PanDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1PanDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1PanDepth,
                     ui->LFO1PanDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO2WaveformBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2Waveform);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2Waveform,
                     ui->LFO2WaveformBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2RateBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2Rate);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2Rate,
                     ui->LFO2RateBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO2OffsetBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2Offset);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2Offset,
                     ui->LFO2OffsetBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2RateDetuneBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2RateDetune);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2RateDetune,
                     ui->LFO2RateDetuneBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO2DelayTimeBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2DelayTime);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2DelayTime,
                     ui->LFO2DelayTimeBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO2DelayTimeKeyfollowBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2DelayTimeKeyfollow);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2DelayTimeKeyfollow,
                     ui->LFO2DelayTimeKeyfollowBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO2FadeModeBox4,&QComboBox::currentIndexChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2FadeMode);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2FadeMode,
                     ui->LFO2FadeModeBox4,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFO2FadeTimeBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2FadeTime);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2FadeTime,
                     ui->LFO2FadeTimeBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO2KeyTriggerBtn4,&QPushButton::toggled,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2KeyTrigger);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2KeyTrigger,
                     ui->LFO2KeyTriggerBtn4,&QPushButton::setChecked);

    QObject::connect(ui->LFO2PitchDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2PitchDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2PitchDepth,
                     ui->LFO2PitchDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO2TVFDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2TVFDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2TVFDepth,
                     ui->LFO2TVFDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO2TVADepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2TVADepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2TVADepth,
                     ui->LFO2TVADepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFO2PanDepthBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2PanDepth);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2PanDepth,
                     ui->LFO2PanDepthBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStepTypeBox4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStepType);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStepType,
                     ui->LFOStepTypeBox4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep1Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep1);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep1,
                     ui->LFOStep1Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep2Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep2);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep2,
                     ui->LFOStep2Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep3Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep3);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep3,
                     ui->LFOStep3Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep4Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep4);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep4,
                     ui->LFOStep4Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep5Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep5);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep5,
                     ui->LFOStep5Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep6Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep6);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep6,
                     ui->LFOStep6Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep7Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep7);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep7,
                     ui->LFOStep7Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep8Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep8);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep8,
                     ui->LFOStep8Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep9Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep9);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep9,
                     ui->LFOStep9Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep10Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep10);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep10,
                     ui->LFOStep10Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep11Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep11);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep11,
                     ui->LFOStep11Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep12Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep12);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep12,
                     ui->LFOStep12Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep13Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep13);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep13,
                     ui->LFOStep13Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep14Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep14);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep14,
                     ui->LFOStep14Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep15Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep15);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep15,
                     ui->LFOStep15Box4,&QSpinBox::setValue);

    QObject::connect(ui->LFOStep16Box4,&QSpinBox::valueChanged,
                     tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep16);

    QObject::connect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep16,
                     ui->LFOStep16Box4,&QSpinBox::setValue);

    QObject::connect(ui->ToneCategoryBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::setToneCategory);

    QObject::connect(tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::ToneCategory,
                     ui->ToneCategoryBox,&QSpinBox::setValue);

    QObject::connect(ui->PhraseOctaveShiftBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::setPhraseOctaveShift);

    QObject::connect(tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::PhraseOctaveShift,
                     ui->PhraseOctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(ui->TFXSwitchBtn,&QPushButton::toggled,
                     tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::setTFXSwitch);

    QObject::connect(tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::TFXSwitch,
                     ui->TFXSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->PhraseNumberBox,&QSpinBox::valueChanged,
                     tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::setPhraseNumber);

    QObject::connect(tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::PhraseNumber,
                     ui->PhraseNumberBox,&QSpinBox::setValue);
}

void integra7MainWindow::DisconnectPCMSynthTone(Integra7Tone *tone)
{
    if (tone == NULL) return;

    QObject::disconnect(ui->PCMSynthToneNameBox,&QLineEdit::textEdited,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setToneName);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthToneName,
                        ui->PCMSynthToneNameBox,&QLineEdit::setText);

    QObject::disconnect(ui->PCMSynthToneLevelBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPCMSynthToneLevel);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthToneLevel,
                        ui->PCMSynthToneLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMSynthTonePanBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPCMSynthTonePan);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthTonePan,
                        ui->PCMSynthTonePanBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMSynthTonePriorityBox,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPCMSynthTonePriority);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthTonePriority,
                        ui->PCMSynthTonePriorityBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PCMSynthToneCoarseTuneBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPCMSynthToneCoarseTune);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthToneCoarseTune,
                        ui->PCMSynthToneCoarseTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMSynthToneFineTuneBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPCMSynthToneFineTune);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PCMSynthToneFineTune,
                        ui->PCMSynthToneFineTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->OctaveShiftBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setOctaveShift);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::OctaveShift,
                        ui->OctaveShiftBox,&QSpinBox::setValue);

    QObject::disconnect(ui->StretchTuneDepthBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setStretchTuneDepth);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::StretchTuneDepth,
                        ui->StretchTuneDepthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->AnalogFeelBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setAnalogFeel);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::AnalogFeel,
                        ui->AnalogFeelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->MonoPolyBox,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMonoPoly);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MonoPoly,
                        ui->MonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LegatoSwitchBtn,&QPushButton::toggled,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setLegatoSwitch);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::LegatoSwitch,
                        ui->LegatoSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->LegatoRetriggerBtn,&QPushButton::toggled,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setLegatoRetrigger);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::LegatoRetrigger,
                        ui->LegatoRetriggerBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PortamentoSwitchBtn,&QPushButton::toggled,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPortamentoSwitch);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PortamentoSwitch,
                        ui->PortamentoSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PortamentoModeBox,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPortamentoMode);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PortamentoMode,
                        ui->PortamentoModeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PortamentoTypeBox,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPortamentoType);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PortamentoType,
                        ui->PortamentoTypeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PortamentoStartBox,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPortamentoStart);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PortamentoStart,
                        ui->PortamentoStartBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PortamentoTimeBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPortamentoTime);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PortamentoTime,
                        ui->PortamentoTimeBox,&QSpinBox::setValue);

    QObject::disconnect(ui->CutoffOffsetBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setCutoffOffset);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::CutoffOffset,
                        ui->CutoffOffsetBox,&QSpinBox::setValue);

    QObject::disconnect(ui->ResonanceOffsetBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setResonanceOffset);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::ResonanceOffset,
                        ui->ResonanceOffsetBox,&QSpinBox::setValue);

    QObject::disconnect(ui->AttackTimeOffsetBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setAttackTimeOffset);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::AttackTimeOffset,
                        ui->AttackTimeOffsetBox,&QSpinBox::setValue);

    QObject::disconnect(ui->ReleaseTimeOffsetBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setReleaseTimeOffset);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::ReleaseTimeOffset,
                        ui->ReleaseTimeOffsetBox,&QSpinBox::setValue);

    QObject::disconnect(ui->VelocitySensOffsetBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setVelocitySensOffset);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::VelocitySensOffset,
                        ui->VelocitySensOffsetBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMTControlSwitchBtn,&QPushButton::toggled,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPMTControlSwitch);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PMTControlSwitch,
                        ui->PMTControlSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PitchBendRangeUpBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPitchBendRangeUp);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PitchBendRangeUp,
                        ui->PitchBendRangeUpBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchBendRangeDownBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setPitchBendRangeDown);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::PitchBendRangeDown,
                        ui->PitchBendRangeDownBox,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl1SourceBox,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Source);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Source,
                        ui->MatrixControl1SourceBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl1Destination1Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Destination1);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Destination1,
                        ui->MatrixControl1Destination1Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl1Sens1Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Sens1);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Sens1,
                        ui->MatrixControl1Sens1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl1Destination2Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Destination2);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Destination2,
                        ui->MatrixControl1Destination2Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl1Sens2Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Sens2);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Sens2,
                        ui->MatrixControl1Sens2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl1Destination3Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Destination3);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Destination3,
                        ui->MatrixControl1Destination3Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl1Sens3Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Sens3);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Sens3,
                        ui->MatrixControl1Sens3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl1Destination4Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Destination4);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Destination4,
                        ui->MatrixControl1Destination4Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl1Sens4Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl1Sens4);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl1Sens4,
                        ui->MatrixControl1Sens4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl2SourceBox,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Source);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Source,
                        ui->MatrixControl2SourceBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl2Destination1Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Destination1);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Destination1,
                        ui->MatrixControl2Destination1Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl2Sens1Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Sens1);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Sens1,
                        ui->MatrixControl2Sens1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl2Destination2Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Destination2);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Destination2,
                        ui->MatrixControl2Destination2Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl2Sens2Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Sens2);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Sens2,
                        ui->MatrixControl2Sens2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl2Destination3Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Destination3);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Destination3,
                        ui->MatrixControl2Destination3Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl2Sens3Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Sens3);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Sens3,
                        ui->MatrixControl2Sens3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl2Destination4Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Destination4);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Destination4,
                        ui->MatrixControl2Destination4Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl2Sens4Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl2Sens4);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl2Sens4,
                        ui->MatrixControl2Sens4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl3SourceBox,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Source);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Source,
                        ui->MatrixControl3SourceBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl3Destination1Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Destination1);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Destination1,
                        ui->MatrixControl3Destination1Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl3Sens1Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Sens1);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Sens1,
                        ui->MatrixControl3Sens1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl3Destination2Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Destination2);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Destination2,
                        ui->MatrixControl3Destination2Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl3Sens2Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Sens2);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Sens2,
                        ui->MatrixControl3Sens2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl3Destination3Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Destination3);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Destination3,
                        ui->MatrixControl3Destination3Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl3Sens3Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Sens3);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Sens3,
                        ui->MatrixControl3Sens3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl3Destination4Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Destination4);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Destination4,
                        ui->MatrixControl3Destination4Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl3Sens4Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl3Sens4);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl3Sens4,
                        ui->MatrixControl3Sens4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl4SourceBox,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Source);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Source,
                        ui->MatrixControl4SourceBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl4Destination1Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Destination1);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Destination1,
                        ui->MatrixControl4Destination1Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl4Sens1Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Sens1);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Sens1,
                        ui->MatrixControl4Sens1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl4Destination2Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Destination2);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Destination2,
                        ui->MatrixControl4Destination2Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl4Sens2Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Sens2);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Sens2,
                        ui->MatrixControl4Sens2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl4Destination3Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Destination3);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Destination3,
                        ui->MatrixControl4Destination3Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl4Sens3Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Sens3);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Sens3,
                        ui->MatrixControl4Sens3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MatrixControl4Destination4Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Destination4);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Destination4,
                        ui->MatrixControl4Destination4Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MatrixControl4Sens4Box,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::setMatrixControl4Sens4);

    QObject::disconnect(tone->PCMSynthToneCommon,&Integra7PCMSynthToneCommon::MatrixControl4Sens4,
                        ui->MatrixControl4Sens4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->StructureType12Box,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setStructureType12);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::StructureType12,
                        ui->StructureType12Box,&QSpinBox::setValue);

    QObject::disconnect(ui->Booster12Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setBooster12);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::Booster12,
                        ui->Booster12Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->StructureType34Box,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setStructureType34);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::StructureType34,
                        ui->StructureType34Box,&QSpinBox::setValue);

    QObject::disconnect(ui->Booster34Box,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setBooster34);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::Booster34,
                        ui->Booster34Box,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PMTVelocityControlBox,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMTVelocityControl);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMTVelocityControl,
                        ui->PMTVelocityControlBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PMT1PartialSwitchBtn,&QPushButton::toggled,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1PartialSwitch);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1PartialSwitch,
                        ui->PMT1PartialSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PMT1KeyboardRangeLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1KeyboardRangeLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1KeyboardRangeLower,
                        ui->PMT1KeyboardRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT1KeyboardRangeUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1KeyboardRangeUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1KeyboardRangeUpper,
                        ui->PMT1KeyboardRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT1KeyboardFadeWidthLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1KeyboardFadeWidthLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1KeyboardFadeWidthLower,
                        ui->PMT1KeyboardFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT1KeyboardFadeWidthUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1KeyboardFadeWidthUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1KeyboardFadeWidthUpper,
                        ui->PMT1KeyboardFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT1VelocityRangeLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1VelocityRangeLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1VelocityRangeLower,
                        ui->PMT1VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT1VelocityRangeUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1VelocityRangeUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1VelocityRangeUpper,
                        ui->PMT1VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT1VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1VelocityFadeWidthLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1VelocityFadeWidthLower,
                        ui->PMT1VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT1VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT1VelocityFadeWidthUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT1VelocityFadeWidthUpper,
                        ui->PMT1VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT2PartialSwitchBtn,&QPushButton::toggled,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2PartialSwitch);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2PartialSwitch,
                        ui->PMT2PartialSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PMT2KeyboardRangeLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2KeyboardRangeLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2KeyboardRangeLower,
                        ui->PMT2KeyboardRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT2KeyboardRangeUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2KeyboardRangeUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2KeyboardRangeUpper,
                        ui->PMT2KeyboardRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT2KeyboardFadeWidthLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2KeyboardFadeWidthLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2KeyboardFadeWidthLower,
                        ui->PMT2KeyboardFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT2KeyboardFadeWidthUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2KeyboardFadeWidthUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2KeyboardFadeWidthUpper,
                        ui->PMT2KeyboardFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT2VelocityRangeLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2VelocityRangeLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2VelocityRangeLower,
                        ui->PMT2VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT2VelocityRangeUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2VelocityRangeUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2VelocityRangeUpper,
                        ui->PMT2VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT2VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2VelocityFadeWidthLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2VelocityFadeWidthLower,
                        ui->PMT2VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT2VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT2VelocityFadeWidthUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT2VelocityFadeWidthUpper,
                        ui->PMT2VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT3PartialSwitchBtn,&QPushButton::toggled,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3PartialSwitch);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3PartialSwitch,
                        ui->PMT3PartialSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PMT3KeyboardRangeLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3KeyboardRangeLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3KeyboardRangeLower,
                        ui->PMT3KeyboardRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT3KeyboardRangeUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3KeyboardRangeUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3KeyboardRangeUpper,
                        ui->PMT3KeyboardRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT3KeyboardFadeWidthLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3KeyboardFadeWidthLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3KeyboardFadeWidthLower,
                        ui->PMT3KeyboardFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT3KeyboardFadeWidthUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3KeyboardFadeWidthUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3KeyboardFadeWidthUpper,
                        ui->PMT3KeyboardFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT3VelocityRangeLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3VelocityRangeLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3VelocityRangeLower,
                        ui->PMT3VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT3VelocityRangeUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3VelocityRangeUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3VelocityRangeUpper,
                        ui->PMT3VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT3VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3VelocityFadeWidthLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3VelocityFadeWidthLower,
                        ui->PMT3VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT3VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT3VelocityFadeWidthUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT3VelocityFadeWidthUpper,
                        ui->PMT3VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT4PartialSwitchBtn,&QPushButton::toggled,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4PartialSwitch);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4PartialSwitch,
                        ui->PMT4PartialSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PMT4KeyboardRangeLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4KeyboardRangeLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4KeyboardRangeLower,
                        ui->PMT4KeyboardRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT4KeyboardRangeUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4KeyboardRangeUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4KeyboardRangeUpper,
                        ui->PMT4KeyboardRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT4KeyboardFadeWidthLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4KeyboardFadeWidthLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4KeyboardFadeWidthLower,
                        ui->PMT4KeyboardFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT4KeyboardFadeWidthUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4KeyboardFadeWidthUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4KeyboardFadeWidthUpper,
                        ui->PMT4KeyboardFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT4VelocityRangeLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4VelocityRangeLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4VelocityRangeLower,
                        ui->PMT4VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT4VelocityRangeUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4VelocityRangeUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4VelocityRangeUpper,
                        ui->PMT4VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT4VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4VelocityFadeWidthLower);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4VelocityFadeWidthLower,
                        ui->PMT4VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PMT4VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::setPMT4VelocityFadeWidthUpper);

    QObject::disconnect(tone->PCMSynthTonePMT,&Integra7PCMSynthTonePMT::PMT4VelocityFadeWidthUpper,
                        ui->PMT4VelocityFadeWidthUpperBox,&QSpinBox::setValue);


    QObject::disconnect(ui->PartialLevelBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialLevel,
                        ui->PartialLevelBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialCoarseTuneBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialCoarseTune);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialCoarseTune,
                        ui->PartialCoarseTuneBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialFineTuneBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialFineTune);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialFineTune,
                        ui->PartialFineTuneBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialRandomPitchDepthBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialRandomPitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialRandomPitchDepth,
                        ui->PartialRandomPitchDepthBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialPanBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialPan);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialPan,
                        ui->PartialPanBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialPanKeyfollowBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialPanKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialPanKeyfollow,
                        ui->PartialPanKeyfollowBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialRandomPanDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialRandomPanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialRandomPanDepth,
                        ui->PartialRandomPanDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialAlternatePanDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialAlternatePanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialAlternatePanDepth,
                        ui->PartialAlternatePanDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialEnvModeBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialEnvMode);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialEnvMode,
                        ui->PartialEnvModeBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialDelayModeBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialDelayMode);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialDelayMode,
                        ui->PartialDelayModeBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialDelayTimeBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialDelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialDelayTime,
                        ui->PartialDelayTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialOutputLevelBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialOutputLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialOutputLevel,
                        ui->PartialOutputLevelBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialChorusSendLevelBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialChorusSendLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialChorusSendLevel,
                        ui->PartialChorusSendLevelBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialReverbSendLevelBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialReverbSendLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialReverbSendLevel,
                        ui->PartialReverbSendLevelBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialReceiveBenderBtn1,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialReceiveBender);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialReceiveBender,
                        ui->PartialReceiveBenderBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialReceiveExpressionBtn1,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialReceiveExpression);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialReceiveExpression,
                        ui->PartialReceiveExpressionBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialReceiveHoldBtn1,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialReceiveHold);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialReceiveHold,
                        ui->PartialReceiveHoldBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialRedamperSwitchBtn1,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialRedamperSwitch);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialRedamperSwitch,
                        ui->PartialRedamperSwitchBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialControl1Switch1Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl1Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl1Switch1,
                        ui->PartialControl1Switch1Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch2Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl1Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl1Switch2,
                        ui->PartialControl1Switch2Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch3Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl1Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl1Switch3,
                        ui->PartialControl1Switch3Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch4Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl1Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl1Switch4,
                        ui->PartialControl1Switch4Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch1Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl2Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl2Switch1,
                        ui->PartialControl2Switch1Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch2Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl2Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl2Switch2,
                        ui->PartialControl2Switch2Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch3Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl2Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl2Switch3,
                        ui->PartialControl2Switch3Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch4Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl2Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl2Switch4,
                        ui->PartialControl2Switch4Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch1Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl3Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl3Switch1,
                        ui->PartialControl3Switch1Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch2Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl3Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl3Switch2,
                        ui->PartialControl3Switch2Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch3Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl3Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl3Switch3,
                        ui->PartialControl3Switch3Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch4Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl3Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl3Switch4,
                        ui->PartialControl3Switch4Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch1Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl4Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl4Switch1,
                        ui->PartialControl4Switch1Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch2Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl4Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl4Switch2,
                        ui->PartialControl4Switch2Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch3Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl4Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl4Switch3,
                        ui->PartialControl4Switch3Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch4Box1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPartialControl4Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PartialControl4Switch4,
                        ui->PartialControl4Switch4Box1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveGroupTypeBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveGroupType);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveGroupType,
                        ui->WaveGroupTypeBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveGroupIDBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveGroupID);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveGroupID,
                        ui->WaveGroupIDBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveNumberLBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveNumberL);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveNumberL,
                        ui->WaveNumberLBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveNumberRBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveNumberR);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveNumberR,
                        ui->WaveNumberRBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveGainBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveGain);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveGain,
                        ui->WaveGainBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveFXMSwitchBtn1,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveFXMSwitch);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveFXMSwitch,
                        ui->WaveFXMSwitchBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->WaveFXMColorBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveFXMColor);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveFXMColor,
                        ui->WaveFXMColorBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveFXMDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveFXMDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveFXMDepth,
                        ui->WaveFXMDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveTempoSyncBtn1,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWaveTempoSync);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WaveTempoSync,
                        ui->WaveTempoSyncBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->WavePitchKeyfollowBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setWavePitchKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::WavePitchKeyfollow,
                        ui->WavePitchKeyfollowBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvDepth,
                        ui->PitchEnvDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvVelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvVelocitySens,
                        ui->PitchEnvVelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime1VelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime1VelocitySens,
                        ui->PitchEnvTime1VelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime4VelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime4VelocitySens,
                        ui->PitchEnvTime4VelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTimeKeyfollowBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTimeKeyfollow,
                        ui->PitchEnvTimeKeyfollowBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime1Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime1,
                        ui->PitchEnvTime1Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime2Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime2,
                        ui->PitchEnvTime2Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime3Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime3,
                        ui->PitchEnvTime3Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime4Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvTime4,
                        ui->PitchEnvTime4Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel0Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvLevel0);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvLevel0,
                        ui->PitchEnvLevel0Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel1Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvLevel1,
                        ui->PitchEnvLevel1Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel2Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvLevel2,
                        ui->PitchEnvLevel2Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel3Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvLevel3,
                        ui->PitchEnvLevel3Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel4Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setPitchEnvLevel4);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::PitchEnvLevel4,
                        ui->PitchEnvLevel4Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFFilterTypeBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFFilterType);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFFilterType,
                        ui->TVFFilterTypeBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->TVFCutoffFrequencyBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFCutoffFrequency);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFCutoffFrequency,
                        ui->TVFCutoffFrequencyBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffKeyfollowBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFCutoffKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFCutoffKeyfollow,
                        ui->TVFCutoffKeyfollowBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffVelocityCurveBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFCutoffVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFCutoffVelocityCurve,
                        ui->TVFCutoffVelocityCurveBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffVelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFCutoffVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFCutoffVelocitySens,
                        ui->TVFCutoffVelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFResonanceBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFResonance);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFResonance,
                        ui->TVFResonanceBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFResonanceVelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFResonanceVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFResonanceVelocitySens,
                        ui->TVFResonanceVelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvDepth,
                        ui->TVFEnvDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvVelocityCurveBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvVelocityCurve,
                        ui->TVFEnvVelocityCurveBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvVelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvVelocitySens,
                        ui->TVFEnvVelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime1VelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime1VelocitySens,
                        ui->TVFEnvTime1VelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime4VelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime4VelocitySens,
                        ui->TVFEnvTime4VelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTimeKeyfollowBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTimeKeyfollow,
                        ui->TVFEnvTimeKeyfollowBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime1Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime1,
                        ui->TVFEnvTime1Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime2Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime2,
                        ui->TVFEnvTime2Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime3Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime3,
                        ui->TVFEnvTime3Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime4Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvTime4,
                        ui->TVFEnvTime4Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel0Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvLevel0);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvLevel0,
                        ui->TVFEnvLevel0Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel1Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvLevel1,
                        ui->TVFEnvLevel1Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel2Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvLevel2,
                        ui->TVFEnvLevel2Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel3Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvLevel3,
                        ui->TVFEnvLevel3Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel4Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVFEnvLevel4);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVFEnvLevel4,
                        ui->TVFEnvLevel4Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasLevelBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setBiasLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::BiasLevel,
                        ui->BiasLevelBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasPositionBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setBiasPosition);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::BiasPosition,
                        ui->BiasPositionBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasDirectionBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setBiasDirection);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::BiasDirection,
                        ui->BiasDirectionBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->TVALevelVelocityCurveBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVALevelVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVALevelVelocityCurve,
                        ui->TVALevelVelocityCurveBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVALevelVelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVALevelVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVALevelVelocitySens,
                        ui->TVALevelVelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime1VelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime1VelocitySens,
                        ui->TVAEnvTime1VelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime4VelocitySensBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime4VelocitySens,
                        ui->TVAEnvTime4VelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTimeKeyfollowBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTimeKeyfollow,
                        ui->TVAEnvTimeKeyfollowBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime1Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime1,
                        ui->TVAEnvTime1Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime2Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime2,
                        ui->TVAEnvTime2Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime3Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime3,
                        ui->TVAEnvTime3Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime4Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvTime4,
                        ui->TVAEnvTime4Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel1Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvLevel1,
                        ui->TVAEnvLevel1Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel2Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvLevel2,
                        ui->TVAEnvLevel2Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel3Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setTVAEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::TVAEnvLevel3,
                        ui->TVAEnvLevel3Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1WaveformBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1Waveform);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1Waveform,
                        ui->LFO1WaveformBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1RateBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1Rate);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1Rate,
                        ui->LFO1RateBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1OffsetBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1Offset);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1Offset,
                        ui->LFO1OffsetBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1RateDetuneBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1RateDetune);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1RateDetune,
                        ui->LFO1RateDetuneBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1DelayTimeBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1DelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1DelayTime,
                        ui->LFO1DelayTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1DelayTimeKeyfollowBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1DelayTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1DelayTimeKeyfollow,
                        ui->LFO1DelayTimeKeyfollowBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1FadeModeBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1FadeMode);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1FadeMode,
                        ui->LFO1FadeModeBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1FadeTimeBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1FadeTime);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1FadeTime,
                        ui->LFO1FadeTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1KeyTriggerBtn1,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1KeyTrigger);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1KeyTrigger,
                        ui->LFO1KeyTriggerBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->LFO1PitchDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1PitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1PitchDepth,
                        ui->LFO1PitchDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1TVFDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1TVFDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1TVFDepth,
                        ui->LFO1TVFDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1TVADepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1TVADepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1TVADepth,
                        ui->LFO1TVADepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1PanDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO1PanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO1PanDepth,
                        ui->LFO1PanDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2WaveformBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2Waveform);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2Waveform,
                        ui->LFO2WaveformBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2RateBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2Rate);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2Rate,
                        ui->LFO2RateBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2OffsetBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2Offset);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2Offset,
                        ui->LFO2OffsetBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2RateDetuneBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2RateDetune);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2RateDetune,
                        ui->LFO2RateDetuneBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2DelayTimeBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2DelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2DelayTime,
                        ui->LFO2DelayTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2DelayTimeKeyfollowBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2DelayTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2DelayTimeKeyfollow,
                        ui->LFO2DelayTimeKeyfollowBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2FadeModeBox1,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2FadeMode);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2FadeMode,
                        ui->LFO2FadeModeBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2FadeTimeBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2FadeTime);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2FadeTime,
                        ui->LFO2FadeTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2KeyTriggerBtn1,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2KeyTrigger);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2KeyTrigger,
                        ui->LFO2KeyTriggerBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->LFO2PitchDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2PitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2PitchDepth,
                        ui->LFO2PitchDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2TVFDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2TVFDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2TVFDepth,
                        ui->LFO2TVFDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2TVADepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2TVADepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2TVADepth,
                        ui->LFO2TVADepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2PanDepthBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFO2PanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFO2PanDepth,
                        ui->LFO2PanDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStepTypeBox1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStepType);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStepType,
                        ui->LFOStepTypeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep1Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep1);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep1,
                        ui->LFOStep1Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep2Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep2);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep2,
                        ui->LFOStep2Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep3Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep3);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep3,
                        ui->LFOStep3Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep4Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep4);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep4,
                        ui->LFOStep4Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep5Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep5);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep5,
                        ui->LFOStep5Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep6Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep6);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep6,
                        ui->LFOStep6Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep7Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep7);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep7,
                        ui->LFOStep7Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep8Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep8);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep8,
                        ui->LFOStep8Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep9Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep9);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep9,
                        ui->LFOStep9Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep10Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep10);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep10,
                        ui->LFOStep10Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep11Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep11);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep11,
                        ui->LFOStep11Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep12Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep12);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep12,
                        ui->LFOStep12Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep13Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep13);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep13,
                        ui->LFOStep13Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep14Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep14);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep14,
                        ui->LFOStep14Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep15Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep15);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep15,
                        ui->LFOStep15Box1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep16Box1,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::setLFOStep16);

    QObject::disconnect(tone->PCMSynthTonePartial[0],&Integra7PCMSynthTonePartial::LFOStep16,
                        ui->LFOStep16Box1,&QSpinBox::setValue);


    QObject::disconnect(ui->PartialLevelBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialLevel,
                        ui->PartialLevelBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialCoarseTuneBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialCoarseTune);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialCoarseTune,
                        ui->PartialCoarseTuneBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialFineTuneBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialFineTune);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialFineTune,
                        ui->PartialFineTuneBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialRandomPitchDepthBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialRandomPitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialRandomPitchDepth,
                        ui->PartialRandomPitchDepthBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialPanBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialPan);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialPan,
                        ui->PartialPanBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialPanKeyfollowBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialPanKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialPanKeyfollow,
                        ui->PartialPanKeyfollowBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialRandomPanDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialRandomPanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialRandomPanDepth,
                        ui->PartialRandomPanDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialAlternatePanDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialAlternatePanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialAlternatePanDepth,
                        ui->PartialAlternatePanDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialEnvModeBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialEnvMode);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialEnvMode,
                        ui->PartialEnvModeBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialDelayModeBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialDelayMode);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialDelayMode,
                        ui->PartialDelayModeBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialDelayTimeBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialDelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialDelayTime,
                        ui->PartialDelayTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialOutputLevelBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialOutputLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialOutputLevel,
                        ui->PartialOutputLevelBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialChorusSendLevelBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialChorusSendLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialChorusSendLevel,
                        ui->PartialChorusSendLevelBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialReverbSendLevelBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialReverbSendLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialReverbSendLevel,
                        ui->PartialReverbSendLevelBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialReceiveBenderBtn2,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialReceiveBender);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialReceiveBender,
                        ui->PartialReceiveBenderBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialReceiveExpressionBtn2,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialReceiveExpression);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialReceiveExpression,
                        ui->PartialReceiveExpressionBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialReceiveHoldBtn2,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialReceiveHold);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialReceiveHold,
                        ui->PartialReceiveHoldBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialRedamperSwitchBtn2,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialRedamperSwitch);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialRedamperSwitch,
                        ui->PartialRedamperSwitchBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialControl1Switch1Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl1Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl1Switch1,
                        ui->PartialControl1Switch1Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch2Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl1Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl1Switch2,
                        ui->PartialControl1Switch2Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch3Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl1Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl1Switch3,
                        ui->PartialControl1Switch3Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch4Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl1Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl1Switch4,
                        ui->PartialControl1Switch4Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch1Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl2Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl2Switch1,
                        ui->PartialControl2Switch1Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch2Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl2Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl2Switch2,
                        ui->PartialControl2Switch2Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch3Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl2Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl2Switch3,
                        ui->PartialControl2Switch3Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch4Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl2Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl2Switch4,
                        ui->PartialControl2Switch4Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch1Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl3Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl3Switch1,
                        ui->PartialControl3Switch1Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch2Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl3Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl3Switch2,
                        ui->PartialControl3Switch2Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch3Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl3Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl3Switch3,
                        ui->PartialControl3Switch3Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch4Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl3Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl3Switch4,
                        ui->PartialControl3Switch4Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch1Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl4Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl4Switch1,
                        ui->PartialControl4Switch1Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch2Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl4Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl4Switch2,
                        ui->PartialControl4Switch2Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch3Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl4Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl4Switch3,
                        ui->PartialControl4Switch3Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch4Box2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPartialControl4Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PartialControl4Switch4,
                        ui->PartialControl4Switch4Box2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveGroupTypeBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveGroupType);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveGroupType,
                        ui->WaveGroupTypeBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveGroupIDBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveGroupID);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveGroupID,
                        ui->WaveGroupIDBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveNumberLBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveNumberL);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveNumberL,
                        ui->WaveNumberLBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveNumberRBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveNumberR);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveNumberR,
                        ui->WaveNumberRBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveGainBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveGain);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveGain,
                        ui->WaveGainBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveFXMSwitchBtn2,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveFXMSwitch);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveFXMSwitch,
                        ui->WaveFXMSwitchBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->WaveFXMColorBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveFXMColor);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveFXMColor,
                        ui->WaveFXMColorBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveFXMDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveFXMDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveFXMDepth,
                        ui->WaveFXMDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveTempoSyncBtn2,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWaveTempoSync);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WaveTempoSync,
                        ui->WaveTempoSyncBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->WavePitchKeyfollowBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setWavePitchKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::WavePitchKeyfollow,
                        ui->WavePitchKeyfollowBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvDepth,
                        ui->PitchEnvDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvVelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvVelocitySens,
                        ui->PitchEnvVelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime1VelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime1VelocitySens,
                        ui->PitchEnvTime1VelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime4VelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime4VelocitySens,
                        ui->PitchEnvTime4VelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTimeKeyfollowBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTimeKeyfollow,
                        ui->PitchEnvTimeKeyfollowBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime1Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime1,
                        ui->PitchEnvTime1Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime2Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime2,
                        ui->PitchEnvTime2Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime3Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime3,
                        ui->PitchEnvTime3Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime4Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvTime4,
                        ui->PitchEnvTime4Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel0Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvLevel0);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvLevel0,
                        ui->PitchEnvLevel0Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel1Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvLevel1,
                        ui->PitchEnvLevel1Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel2Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvLevel2,
                        ui->PitchEnvLevel2Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel3Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvLevel3,
                        ui->PitchEnvLevel3Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel4Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setPitchEnvLevel4);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::PitchEnvLevel4,
                        ui->PitchEnvLevel4Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFFilterTypeBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFFilterType);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFFilterType,
                        ui->TVFFilterTypeBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->TVFCutoffFrequencyBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFCutoffFrequency);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFCutoffFrequency,
                        ui->TVFCutoffFrequencyBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffKeyfollowBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFCutoffKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFCutoffKeyfollow,
                        ui->TVFCutoffKeyfollowBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffVelocityCurveBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFCutoffVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFCutoffVelocityCurve,
                        ui->TVFCutoffVelocityCurveBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffVelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFCutoffVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFCutoffVelocitySens,
                        ui->TVFCutoffVelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFResonanceBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFResonance);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFResonance,
                        ui->TVFResonanceBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFResonanceVelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFResonanceVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFResonanceVelocitySens,
                        ui->TVFResonanceVelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvDepth,
                        ui->TVFEnvDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvVelocityCurveBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvVelocityCurve,
                        ui->TVFEnvVelocityCurveBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvVelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvVelocitySens,
                        ui->TVFEnvVelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime1VelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime1VelocitySens,
                        ui->TVFEnvTime1VelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime4VelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime4VelocitySens,
                        ui->TVFEnvTime4VelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTimeKeyfollowBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTimeKeyfollow,
                        ui->TVFEnvTimeKeyfollowBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime1Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime1,
                        ui->TVFEnvTime1Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime2Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime2,
                        ui->TVFEnvTime2Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime3Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime3,
                        ui->TVFEnvTime3Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime4Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvTime4,
                        ui->TVFEnvTime4Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel0Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvLevel0);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvLevel0,
                        ui->TVFEnvLevel0Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel1Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvLevel1,
                        ui->TVFEnvLevel1Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel2Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvLevel2,
                        ui->TVFEnvLevel2Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel3Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvLevel3,
                        ui->TVFEnvLevel3Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel4Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVFEnvLevel4);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVFEnvLevel4,
                        ui->TVFEnvLevel4Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasLevelBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setBiasLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::BiasLevel,
                        ui->BiasLevelBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasPositionBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setBiasPosition);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::BiasPosition,
                        ui->BiasPositionBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasDirectionBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setBiasDirection);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::BiasDirection,
                        ui->BiasDirectionBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->TVALevelVelocityCurveBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVALevelVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVALevelVelocityCurve,
                        ui->TVALevelVelocityCurveBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVALevelVelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVALevelVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVALevelVelocitySens,
                        ui->TVALevelVelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime1VelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime1VelocitySens,
                        ui->TVAEnvTime1VelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime4VelocitySensBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime4VelocitySens,
                        ui->TVAEnvTime4VelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTimeKeyfollowBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTimeKeyfollow,
                        ui->TVAEnvTimeKeyfollowBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime1Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime1,
                        ui->TVAEnvTime1Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime2Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime2,
                        ui->TVAEnvTime2Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime3Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime3,
                        ui->TVAEnvTime3Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime4Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvTime4,
                        ui->TVAEnvTime4Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel1Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvLevel1,
                        ui->TVAEnvLevel1Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel2Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvLevel2,
                        ui->TVAEnvLevel2Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel3Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setTVAEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::TVAEnvLevel3,
                        ui->TVAEnvLevel3Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1WaveformBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1Waveform);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1Waveform,
                        ui->LFO1WaveformBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1RateBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1Rate);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1Rate,
                        ui->LFO1RateBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1OffsetBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1Offset);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1Offset,
                        ui->LFO1OffsetBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1RateDetuneBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1RateDetune);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1RateDetune,
                        ui->LFO1RateDetuneBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1DelayTimeBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1DelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1DelayTime,
                        ui->LFO1DelayTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1DelayTimeKeyfollowBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1DelayTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1DelayTimeKeyfollow,
                        ui->LFO1DelayTimeKeyfollowBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1FadeModeBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1FadeMode);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1FadeMode,
                        ui->LFO1FadeModeBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1FadeTimeBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1FadeTime);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1FadeTime,
                        ui->LFO1FadeTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1KeyTriggerBtn2,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1KeyTrigger);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1KeyTrigger,
                        ui->LFO1KeyTriggerBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->LFO1PitchDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1PitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1PitchDepth,
                        ui->LFO1PitchDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1TVFDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1TVFDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1TVFDepth,
                        ui->LFO1TVFDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1TVADepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1TVADepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1TVADepth,
                        ui->LFO1TVADepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1PanDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO1PanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO1PanDepth,
                        ui->LFO1PanDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2WaveformBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2Waveform);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2Waveform,
                        ui->LFO2WaveformBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2RateBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2Rate);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2Rate,
                        ui->LFO2RateBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2OffsetBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2Offset);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2Offset,
                        ui->LFO2OffsetBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2RateDetuneBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2RateDetune);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2RateDetune,
                        ui->LFO2RateDetuneBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2DelayTimeBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2DelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2DelayTime,
                        ui->LFO2DelayTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2DelayTimeKeyfollowBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2DelayTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2DelayTimeKeyfollow,
                        ui->LFO2DelayTimeKeyfollowBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2FadeModeBox2,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2FadeMode);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2FadeMode,
                        ui->LFO2FadeModeBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2FadeTimeBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2FadeTime);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2FadeTime,
                        ui->LFO2FadeTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2KeyTriggerBtn2,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2KeyTrigger);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2KeyTrigger,
                        ui->LFO2KeyTriggerBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->LFO2PitchDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2PitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2PitchDepth,
                        ui->LFO2PitchDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2TVFDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2TVFDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2TVFDepth,
                        ui->LFO2TVFDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2TVADepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2TVADepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2TVADepth,
                        ui->LFO2TVADepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2PanDepthBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFO2PanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFO2PanDepth,
                        ui->LFO2PanDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStepTypeBox2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStepType);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStepType,
                        ui->LFOStepTypeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep1Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep1);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep1,
                        ui->LFOStep1Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep2Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep2);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep2,
                        ui->LFOStep2Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep3Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep3);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep3,
                        ui->LFOStep3Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep4Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep4);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep4,
                        ui->LFOStep4Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep5Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep5);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep5,
                        ui->LFOStep5Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep6Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep6);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep6,
                        ui->LFOStep6Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep7Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep7);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep7,
                        ui->LFOStep7Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep8Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep8);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep8,
                        ui->LFOStep8Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep9Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep9);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep9,
                        ui->LFOStep9Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep10Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep10);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep10,
                        ui->LFOStep10Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep11Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep11);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep11,
                        ui->LFOStep11Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep12Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep12);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep12,
                        ui->LFOStep12Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep13Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep13);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep13,
                        ui->LFOStep13Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep14Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep14);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep14,
                        ui->LFOStep14Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep15Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep15);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep15,
                        ui->LFOStep15Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep16Box2,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::setLFOStep16);

    QObject::disconnect(tone->PCMSynthTonePartial[1],&Integra7PCMSynthTonePartial::LFOStep16,
                        ui->LFOStep16Box2,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialLevelBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialLevel,
                        ui->PartialLevelBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialCoarseTuneBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialCoarseTune);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialCoarseTune,
                        ui->PartialCoarseTuneBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialFineTuneBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialFineTune);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialFineTune,
                        ui->PartialFineTuneBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialRandomPitchDepthBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialRandomPitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialRandomPitchDepth,
                        ui->PartialRandomPitchDepthBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialPanBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialPan);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialPan,
                        ui->PartialPanBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialPanKeyfollowBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialPanKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialPanKeyfollow,
                        ui->PartialPanKeyfollowBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialRandomPanDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialRandomPanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialRandomPanDepth,
                        ui->PartialRandomPanDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialAlternatePanDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialAlternatePanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialAlternatePanDepth,
                        ui->PartialAlternatePanDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialEnvModeBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialEnvMode);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialEnvMode,
                        ui->PartialEnvModeBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialDelayModeBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialDelayMode);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialDelayMode,
                        ui->PartialDelayModeBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialDelayTimeBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialDelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialDelayTime,
                        ui->PartialDelayTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialOutputLevelBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialOutputLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialOutputLevel,
                        ui->PartialOutputLevelBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialChorusSendLevelBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialChorusSendLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialChorusSendLevel,
                        ui->PartialChorusSendLevelBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialReverbSendLevelBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialReverbSendLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialReverbSendLevel,
                        ui->PartialReverbSendLevelBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialReceiveBenderBtn3,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialReceiveBender);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialReceiveBender,
                        ui->PartialReceiveBenderBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialReceiveExpressionBtn3,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialReceiveExpression);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialReceiveExpression,
                        ui->PartialReceiveExpressionBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialReceiveHoldBtn3,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialReceiveHold);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialReceiveHold,
                        ui->PartialReceiveHoldBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialRedamperSwitchBtn3,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialRedamperSwitch);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialRedamperSwitch,
                        ui->PartialRedamperSwitchBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialControl1Switch1Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl1Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl1Switch1,
                        ui->PartialControl1Switch1Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch2Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl1Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl1Switch2,
                        ui->PartialControl1Switch2Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch3Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl1Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl1Switch3,
                        ui->PartialControl1Switch3Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch4Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl1Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl1Switch4,
                        ui->PartialControl1Switch4Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch1Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl2Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl2Switch1,
                        ui->PartialControl2Switch1Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch2Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl2Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl2Switch2,
                        ui->PartialControl2Switch2Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch3Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl2Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl2Switch3,
                        ui->PartialControl2Switch3Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch4Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl2Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl2Switch4,
                        ui->PartialControl2Switch4Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch1Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl3Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl3Switch1,
                        ui->PartialControl3Switch1Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch2Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl3Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl3Switch2,
                        ui->PartialControl3Switch2Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch3Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl3Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl3Switch3,
                        ui->PartialControl3Switch3Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch4Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl3Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl3Switch4,
                        ui->PartialControl3Switch4Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch1Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl4Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl4Switch1,
                        ui->PartialControl4Switch1Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch2Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl4Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl4Switch2,
                        ui->PartialControl4Switch2Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch3Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl4Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl4Switch3,
                        ui->PartialControl4Switch3Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch4Box3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPartialControl4Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PartialControl4Switch4,
                        ui->PartialControl4Switch4Box3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveGroupTypeBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveGroupType);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveGroupType,
                        ui->WaveGroupTypeBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveGroupIDBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveGroupID);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveGroupID,
                        ui->WaveGroupIDBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveNumberLBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveNumberL);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveNumberL,
                        ui->WaveNumberLBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveNumberRBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveNumberR);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveNumberR,
                        ui->WaveNumberRBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveGainBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveGain);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveGain,
                        ui->WaveGainBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveFXMSwitchBtn3,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveFXMSwitch);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveFXMSwitch,
                        ui->WaveFXMSwitchBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->WaveFXMColorBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveFXMColor);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveFXMColor,
                        ui->WaveFXMColorBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveFXMDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveFXMDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveFXMDepth,
                        ui->WaveFXMDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveTempoSyncBtn3,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWaveTempoSync);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WaveTempoSync,
                        ui->WaveTempoSyncBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->WavePitchKeyfollowBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setWavePitchKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::WavePitchKeyfollow,
                        ui->WavePitchKeyfollowBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvDepth,
                        ui->PitchEnvDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvVelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvVelocitySens,
                        ui->PitchEnvVelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime1VelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime1VelocitySens,
                        ui->PitchEnvTime1VelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime4VelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime4VelocitySens,
                        ui->PitchEnvTime4VelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTimeKeyfollowBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTimeKeyfollow,
                        ui->PitchEnvTimeKeyfollowBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime1Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime1,
                        ui->PitchEnvTime1Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime2Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime2,
                        ui->PitchEnvTime2Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime3Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime3,
                        ui->PitchEnvTime3Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime4Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvTime4,
                        ui->PitchEnvTime4Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel0Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvLevel0);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvLevel0,
                        ui->PitchEnvLevel0Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel1Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvLevel1,
                        ui->PitchEnvLevel1Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel2Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvLevel2,
                        ui->PitchEnvLevel2Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel3Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvLevel3,
                        ui->PitchEnvLevel3Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel4Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setPitchEnvLevel4);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::PitchEnvLevel4,
                        ui->PitchEnvLevel4Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFFilterTypeBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFFilterType);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFFilterType,
                        ui->TVFFilterTypeBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->TVFCutoffFrequencyBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFCutoffFrequency);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFCutoffFrequency,
                        ui->TVFCutoffFrequencyBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffKeyfollowBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFCutoffKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFCutoffKeyfollow,
                        ui->TVFCutoffKeyfollowBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffVelocityCurveBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFCutoffVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFCutoffVelocityCurve,
                        ui->TVFCutoffVelocityCurveBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffVelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFCutoffVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFCutoffVelocitySens,
                        ui->TVFCutoffVelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFResonanceBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFResonance);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFResonance,
                        ui->TVFResonanceBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFResonanceVelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFResonanceVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFResonanceVelocitySens,
                        ui->TVFResonanceVelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvDepth,
                        ui->TVFEnvDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvVelocityCurveBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvVelocityCurve,
                        ui->TVFEnvVelocityCurveBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvVelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvVelocitySens,
                        ui->TVFEnvVelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime1VelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime1VelocitySens,
                        ui->TVFEnvTime1VelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime4VelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime4VelocitySens,
                        ui->TVFEnvTime4VelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTimeKeyfollowBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTimeKeyfollow,
                        ui->TVFEnvTimeKeyfollowBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime1Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime1,
                        ui->TVFEnvTime1Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime2Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime2,
                        ui->TVFEnvTime2Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime3Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime3,
                        ui->TVFEnvTime3Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime4Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvTime4,
                        ui->TVFEnvTime4Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel0Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvLevel0);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvLevel0,
                        ui->TVFEnvLevel0Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel1Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvLevel1,
                        ui->TVFEnvLevel1Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel2Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvLevel2,
                        ui->TVFEnvLevel2Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel3Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvLevel3,
                        ui->TVFEnvLevel3Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel4Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVFEnvLevel4);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVFEnvLevel4,
                        ui->TVFEnvLevel4Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasLevelBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setBiasLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::BiasLevel,
                        ui->BiasLevelBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasPositionBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setBiasPosition);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::BiasPosition,
                        ui->BiasPositionBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasDirectionBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setBiasDirection);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::BiasDirection,
                        ui->BiasDirectionBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->TVALevelVelocityCurveBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVALevelVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVALevelVelocityCurve,
                        ui->TVALevelVelocityCurveBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVALevelVelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVALevelVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVALevelVelocitySens,
                        ui->TVALevelVelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime1VelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime1VelocitySens,
                        ui->TVAEnvTime1VelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime4VelocitySensBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime4VelocitySens,
                        ui->TVAEnvTime4VelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTimeKeyfollowBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTimeKeyfollow,
                        ui->TVAEnvTimeKeyfollowBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime1Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime1,
                        ui->TVAEnvTime1Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime2Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime2,
                        ui->TVAEnvTime2Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime3Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime3,
                        ui->TVAEnvTime3Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime4Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvTime4,
                        ui->TVAEnvTime4Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel1Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvLevel1,
                        ui->TVAEnvLevel1Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel2Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvLevel2,
                        ui->TVAEnvLevel2Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel3Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setTVAEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::TVAEnvLevel3,
                        ui->TVAEnvLevel3Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1WaveformBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1Waveform);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1Waveform,
                        ui->LFO1WaveformBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1RateBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1Rate);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1Rate,
                        ui->LFO1RateBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1OffsetBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1Offset);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1Offset,
                        ui->LFO1OffsetBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1RateDetuneBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1RateDetune);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1RateDetune,
                        ui->LFO1RateDetuneBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1DelayTimeBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1DelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1DelayTime,
                        ui->LFO1DelayTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1DelayTimeKeyfollowBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1DelayTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1DelayTimeKeyfollow,
                        ui->LFO1DelayTimeKeyfollowBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1FadeModeBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1FadeMode);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1FadeMode,
                        ui->LFO1FadeModeBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1FadeTimeBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1FadeTime);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1FadeTime,
                        ui->LFO1FadeTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1KeyTriggerBtn3,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1KeyTrigger);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1KeyTrigger,
                        ui->LFO1KeyTriggerBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->LFO1PitchDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1PitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1PitchDepth,
                        ui->LFO1PitchDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1TVFDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1TVFDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1TVFDepth,
                        ui->LFO1TVFDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1TVADepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1TVADepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1TVADepth,
                        ui->LFO1TVADepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1PanDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO1PanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO1PanDepth,
                        ui->LFO1PanDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2WaveformBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2Waveform);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2Waveform,
                        ui->LFO2WaveformBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2RateBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2Rate);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2Rate,
                        ui->LFO2RateBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2OffsetBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2Offset);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2Offset,
                        ui->LFO2OffsetBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2RateDetuneBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2RateDetune);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2RateDetune,
                        ui->LFO2RateDetuneBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2DelayTimeBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2DelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2DelayTime,
                        ui->LFO2DelayTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2DelayTimeKeyfollowBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2DelayTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2DelayTimeKeyfollow,
                        ui->LFO2DelayTimeKeyfollowBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2FadeModeBox3,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2FadeMode);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2FadeMode,
                        ui->LFO2FadeModeBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2FadeTimeBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2FadeTime);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2FadeTime,
                        ui->LFO2FadeTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2KeyTriggerBtn3,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2KeyTrigger);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2KeyTrigger,
                        ui->LFO2KeyTriggerBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->LFO2PitchDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2PitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2PitchDepth,
                        ui->LFO2PitchDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2TVFDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2TVFDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2TVFDepth,
                        ui->LFO2TVFDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2TVADepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2TVADepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2TVADepth,
                        ui->LFO2TVADepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2PanDepthBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFO2PanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFO2PanDepth,
                        ui->LFO2PanDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStepTypeBox3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStepType);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStepType,
                        ui->LFOStepTypeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep1Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep1);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep1,
                        ui->LFOStep1Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep2Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep2);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep2,
                        ui->LFOStep2Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep3Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep3);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep3,
                        ui->LFOStep3Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep4Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep4);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep4,
                        ui->LFOStep4Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep5Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep5);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep5,
                        ui->LFOStep5Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep6Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep6);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep6,
                        ui->LFOStep6Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep7Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep7);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep7,
                        ui->LFOStep7Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep8Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep8);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep8,
                        ui->LFOStep8Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep9Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep9);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep9,
                        ui->LFOStep9Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep10Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep10);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep10,
                        ui->LFOStep10Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep11Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep11);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep11,
                        ui->LFOStep11Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep12Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep12);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep12,
                        ui->LFOStep12Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep13Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep13);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep13,
                        ui->LFOStep13Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep14Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep14);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep14,
                        ui->LFOStep14Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep15Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep15);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep15,
                        ui->LFOStep15Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep16Box3,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::setLFOStep16);

    QObject::disconnect(tone->PCMSynthTonePartial[2],&Integra7PCMSynthTonePartial::LFOStep16,
                        ui->LFOStep16Box3,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialLevelBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialLevel,
                        ui->PartialLevelBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialCoarseTuneBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialCoarseTune);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialCoarseTune,
                        ui->PartialCoarseTuneBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialFineTuneBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialFineTune);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialFineTune,
                        ui->PartialFineTuneBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialRandomPitchDepthBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialRandomPitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialRandomPitchDepth,
                        ui->PartialRandomPitchDepthBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialPanBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialPan);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialPan,
                        ui->PartialPanBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialPanKeyfollowBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialPanKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialPanKeyfollow,
                        ui->PartialPanKeyfollowBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialRandomPanDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialRandomPanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialRandomPanDepth,
                        ui->PartialRandomPanDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialAlternatePanDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialAlternatePanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialAlternatePanDepth,
                        ui->PartialAlternatePanDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialEnvModeBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialEnvMode);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialEnvMode,
                        ui->PartialEnvModeBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialDelayModeBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialDelayMode);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialDelayMode,
                        ui->PartialDelayModeBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialDelayTimeBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialDelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialDelayTime,
                        ui->PartialDelayTimeBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialOutputLevelBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialOutputLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialOutputLevel,
                        ui->PartialOutputLevelBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialChorusSendLevelBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialChorusSendLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialChorusSendLevel,
                        ui->PartialChorusSendLevelBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialReverbSendLevelBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialReverbSendLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialReverbSendLevel,
                        ui->PartialReverbSendLevelBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialReceiveBenderBtn4,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialReceiveBender);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialReceiveBender,
                        ui->PartialReceiveBenderBtn4,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialReceiveExpressionBtn4,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialReceiveExpression);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialReceiveExpression,
                        ui->PartialReceiveExpressionBtn4,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialReceiveHoldBtn4,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialReceiveHold);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialReceiveHold,
                        ui->PartialReceiveHoldBtn4,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialRedamperSwitchBtn4,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialRedamperSwitch);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialRedamperSwitch,
                        ui->PartialRedamperSwitchBtn4,&QPushButton::setChecked);

    QObject::disconnect(ui->PartialControl1Switch1Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl1Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl1Switch1,
                        ui->PartialControl1Switch1Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch2Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl1Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl1Switch2,
                        ui->PartialControl1Switch2Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch3Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl1Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl1Switch3,
                        ui->PartialControl1Switch3Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl1Switch4Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl1Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl1Switch4,
                        ui->PartialControl1Switch4Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch1Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl2Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl2Switch1,
                        ui->PartialControl2Switch1Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch2Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl2Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl2Switch2,
                        ui->PartialControl2Switch2Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch3Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl2Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl2Switch3,
                        ui->PartialControl2Switch3Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl2Switch4Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl2Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl2Switch4,
                        ui->PartialControl2Switch4Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch1Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl3Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl3Switch1,
                        ui->PartialControl3Switch1Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch2Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl3Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl3Switch2,
                        ui->PartialControl3Switch2Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch3Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl3Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl3Switch3,
                        ui->PartialControl3Switch3Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl3Switch4Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl3Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl3Switch4,
                        ui->PartialControl3Switch4Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch1Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl4Switch1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl4Switch1,
                        ui->PartialControl4Switch1Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch2Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl4Switch2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl4Switch2,
                        ui->PartialControl4Switch2Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch3Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl4Switch3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl4Switch3,
                        ui->PartialControl4Switch3Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialControl4Switch4Box4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPartialControl4Switch4);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PartialControl4Switch4,
                        ui->PartialControl4Switch4Box4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveGroupTypeBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveGroupType);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveGroupType,
                        ui->WaveGroupTypeBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveGroupIDBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveGroupID);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveGroupID,
                        ui->WaveGroupIDBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveNumberLBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveNumberL);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveNumberL,
                        ui->WaveNumberLBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveNumberRBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveNumberR);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveNumberR,
                        ui->WaveNumberRBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveGainBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveGain);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveGain,
                        ui->WaveGainBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveFXMSwitchBtn4,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveFXMSwitch);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveFXMSwitch,
                        ui->WaveFXMSwitchBtn4,&QPushButton::setChecked);

    QObject::disconnect(ui->WaveFXMColorBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveFXMColor);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveFXMColor,
                        ui->WaveFXMColorBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveFXMDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveFXMDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveFXMDepth,
                        ui->WaveFXMDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveTempoSyncBtn4,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWaveTempoSync);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WaveTempoSync,
                        ui->WaveTempoSyncBtn4,&QPushButton::setChecked);

    QObject::disconnect(ui->WavePitchKeyfollowBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setWavePitchKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::WavePitchKeyfollow,
                        ui->WavePitchKeyfollowBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvDepth,
                        ui->PitchEnvDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvVelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvVelocitySens,
                        ui->PitchEnvVelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime1VelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime1VelocitySens,
                        ui->PitchEnvTime1VelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime4VelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime4VelocitySens,
                        ui->PitchEnvTime4VelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTimeKeyfollowBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTimeKeyfollow,
                        ui->PitchEnvTimeKeyfollowBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime1Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime1,
                        ui->PitchEnvTime1Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime2Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime2,
                        ui->PitchEnvTime2Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime3Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime3,
                        ui->PitchEnvTime3Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvTime4Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvTime4,
                        ui->PitchEnvTime4Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel0Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvLevel0);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvLevel0,
                        ui->PitchEnvLevel0Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel1Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvLevel1,
                        ui->PitchEnvLevel1Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel2Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvLevel2,
                        ui->PitchEnvLevel2Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel3Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvLevel3,
                        ui->PitchEnvLevel3Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchEnvLevel4Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setPitchEnvLevel4);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::PitchEnvLevel4,
                        ui->PitchEnvLevel4Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFFilterTypeBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFFilterType);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFFilterType,
                        ui->TVFFilterTypeBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->TVFCutoffFrequencyBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFCutoffFrequency);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFCutoffFrequency,
                        ui->TVFCutoffFrequencyBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffKeyfollowBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFCutoffKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFCutoffKeyfollow,
                        ui->TVFCutoffKeyfollowBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffVelocityCurveBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFCutoffVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFCutoffVelocityCurve,
                        ui->TVFCutoffVelocityCurveBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFCutoffVelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFCutoffVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFCutoffVelocitySens,
                        ui->TVFCutoffVelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFResonanceBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFResonance);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFResonance,
                        ui->TVFResonanceBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFResonanceVelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFResonanceVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFResonanceVelocitySens,
                        ui->TVFResonanceVelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvDepth,
                        ui->TVFEnvDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvVelocityCurveBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvVelocityCurve,
                        ui->TVFEnvVelocityCurveBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvVelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvVelocitySens,
                        ui->TVFEnvVelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime1VelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime1VelocitySens,
                        ui->TVFEnvTime1VelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime4VelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime4VelocitySens,
                        ui->TVFEnvTime4VelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTimeKeyfollowBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTimeKeyfollow,
                        ui->TVFEnvTimeKeyfollowBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime1Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime1,
                        ui->TVFEnvTime1Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime2Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime2,
                        ui->TVFEnvTime2Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime3Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime3,
                        ui->TVFEnvTime3Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvTime4Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvTime4,
                        ui->TVFEnvTime4Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel0Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvLevel0);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvLevel0,
                        ui->TVFEnvLevel0Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel1Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvLevel1,
                        ui->TVFEnvLevel1Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel2Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvLevel2,
                        ui->TVFEnvLevel2Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel3Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvLevel3,
                        ui->TVFEnvLevel3Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvLevel4Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVFEnvLevel4);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVFEnvLevel4,
                        ui->TVFEnvLevel4Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasLevelBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setBiasLevel);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::BiasLevel,
                        ui->BiasLevelBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasPositionBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setBiasPosition);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::BiasPosition,
                        ui->BiasPositionBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->BiasDirectionBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setBiasDirection);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::BiasDirection,
                        ui->BiasDirectionBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->TVALevelVelocityCurveBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVALevelVelocityCurve);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVALevelVelocityCurve,
                        ui->TVALevelVelocityCurveBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVALevelVelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVALevelVelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVALevelVelocitySens,
                        ui->TVALevelVelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime1VelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime1VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime1VelocitySens,
                        ui->TVAEnvTime1VelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime4VelocitySensBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime4VelocitySens);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime4VelocitySens,
                        ui->TVAEnvTime4VelocitySensBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTimeKeyfollowBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTimeKeyfollow,
                        ui->TVAEnvTimeKeyfollowBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime1Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime1,
                        ui->TVAEnvTime1Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime2Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime2,
                        ui->TVAEnvTime2Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime3Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime3,
                        ui->TVAEnvTime3Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvTime4Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvTime4);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvTime4,
                        ui->TVAEnvTime4Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel1Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvLevel1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvLevel1,
                        ui->TVAEnvLevel1Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel2Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvLevel2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvLevel2,
                        ui->TVAEnvLevel2Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->TVAEnvLevel3Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setTVAEnvLevel3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::TVAEnvLevel3,
                        ui->TVAEnvLevel3Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1WaveformBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1Waveform);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1Waveform,
                        ui->LFO1WaveformBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1RateBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1Rate);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1Rate,
                        ui->LFO1RateBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1OffsetBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1Offset);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1Offset,
                        ui->LFO1OffsetBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1RateDetuneBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1RateDetune);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1RateDetune,
                        ui->LFO1RateDetuneBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1DelayTimeBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1DelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1DelayTime,
                        ui->LFO1DelayTimeBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1DelayTimeKeyfollowBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1DelayTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1DelayTimeKeyfollow,
                        ui->LFO1DelayTimeKeyfollowBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1FadeModeBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1FadeMode);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1FadeMode,
                        ui->LFO1FadeModeBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO1FadeTimeBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1FadeTime);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1FadeTime,
                        ui->LFO1FadeTimeBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1KeyTriggerBtn4,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1KeyTrigger);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1KeyTrigger,
                        ui->LFO1KeyTriggerBtn4,&QPushButton::setChecked);

    QObject::disconnect(ui->LFO1PitchDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1PitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1PitchDepth,
                        ui->LFO1PitchDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1TVFDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1TVFDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1TVFDepth,
                        ui->LFO1TVFDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1TVADepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1TVADepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1TVADepth,
                        ui->LFO1TVADepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO1PanDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO1PanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO1PanDepth,
                        ui->LFO1PanDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2WaveformBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2Waveform);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2Waveform,
                        ui->LFO2WaveformBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2RateBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2Rate);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2Rate,
                        ui->LFO2RateBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2OffsetBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2Offset);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2Offset,
                        ui->LFO2OffsetBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2RateDetuneBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2RateDetune);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2RateDetune,
                        ui->LFO2RateDetuneBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2DelayTimeBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2DelayTime);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2DelayTime,
                        ui->LFO2DelayTimeBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2DelayTimeKeyfollowBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2DelayTimeKeyfollow);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2DelayTimeKeyfollow,
                        ui->LFO2DelayTimeKeyfollowBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2FadeModeBox4,&QComboBox::currentIndexChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2FadeMode);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2FadeMode,
                        ui->LFO2FadeModeBox4,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFO2FadeTimeBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2FadeTime);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2FadeTime,
                        ui->LFO2FadeTimeBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2KeyTriggerBtn4,&QPushButton::toggled,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2KeyTrigger);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2KeyTrigger,
                        ui->LFO2KeyTriggerBtn4,&QPushButton::setChecked);

    QObject::disconnect(ui->LFO2PitchDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2PitchDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2PitchDepth,
                        ui->LFO2PitchDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2TVFDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2TVFDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2TVFDepth,
                        ui->LFO2TVFDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2TVADepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2TVADepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2TVADepth,
                        ui->LFO2TVADepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFO2PanDepthBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFO2PanDepth);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFO2PanDepth,
                        ui->LFO2PanDepthBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStepTypeBox4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStepType);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStepType,
                        ui->LFOStepTypeBox4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep1Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep1);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep1,
                        ui->LFOStep1Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep2Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep2);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep2,
                        ui->LFOStep2Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep3Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep3);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep3,
                        ui->LFOStep3Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep4Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep4);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep4,
                        ui->LFOStep4Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep5Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep5);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep5,
                        ui->LFOStep5Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep6Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep6);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep6,
                        ui->LFOStep6Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep7Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep7);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep7,
                        ui->LFOStep7Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep8Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep8);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep8,
                        ui->LFOStep8Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep9Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep9);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep9,
                        ui->LFOStep9Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep10Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep10);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep10,
                        ui->LFOStep10Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep11Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep11);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep11,
                        ui->LFOStep11Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep12Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep12);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep12,
                        ui->LFOStep12Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep13Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep13);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep13,
                        ui->LFOStep13Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep14Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep14);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep14,
                        ui->LFOStep14Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep15Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep15);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep15,
                        ui->LFOStep15Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOStep16Box4,&QSpinBox::valueChanged,
                        tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::setLFOStep16);

    QObject::disconnect(tone->PCMSynthTonePartial[3],&Integra7PCMSynthTonePartial::LFOStep16,
                        ui->LFOStep16Box4,&QSpinBox::setValue);

    QObject::disconnect(ui->ToneCategoryBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::setToneCategory);

    QObject::disconnect(tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::ToneCategory,
                        ui->ToneCategoryBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PhraseOctaveShiftBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::setPhraseOctaveShift);

    QObject::disconnect(tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::PhraseOctaveShift,
                        ui->PhraseOctaveShiftBox,&QSpinBox::setValue);

    QObject::disconnect(ui->TFXSwitchBtn,&QPushButton::toggled,
                        tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::setTFXSwitch);

    QObject::disconnect(tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::TFXSwitch,
                        ui->TFXSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PhraseNumberBox,&QSpinBox::valueChanged,
                        tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::setPhraseNumber);

    QObject::disconnect(tone->PCMSynthToneCommon2,&Integra7PCMSynthToneCommon2::PhraseNumber,
                        ui->PhraseNumberBox,&QSpinBox::setValue);

}

void integra7MainWindow::ConnectPCMDrumKit(Integra7Tone *tone)
{
    if (tone == NULL) return;

    QObject::connect(ui->KitNameBox,&QLineEdit::textEdited,
         tone->PCMDrumKitCommon,&Integra7PCMDrumKitCommon::setKitName);

    QObject::connect(tone->PCMDrumKitCommon,&Integra7PCMDrumKitCommon::KitName,
         ui->KitNameBox,&QLineEdit::setText);

    QObject::connect(ui->KitLevelBox,&QSpinBox::valueChanged,
         tone->PCMDrumKitCommon,&Integra7PCMDrumKitCommon::setKitLevel);

    QObject::connect(tone->PCMDrumKitCommon,&Integra7PCMDrumKitCommon::KitLevel,
         ui->KitLevelBox,&QSpinBox::setValue);    

    QObject::connect(ui->PCMDPhraseNumberBox,&QSpinBox::valueChanged,
         tone->PCMDrumKitCommon2,&Integra7PCMDrumKitCommon2::setPhraseNumber);

    QObject::connect(tone->PCMDrumKitCommon2,&Integra7PCMDrumKitCommon2::PhraseNumber,
         ui->PCMDPhraseNumberBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTFXSwitchBtn,&QPushButton::toggled,
         tone->PCMDrumKitCommon2,&Integra7PCMDrumKitCommon2::setTFXSwitch);

    QObject::connect(tone->PCMDrumKitCommon2,&Integra7PCMDrumKitCommon2::TFXSwitch,
         ui->PCMDTFXSwitchBtn,&QPushButton::setChecked);
}

void integra7MainWindow::ConnectPCMDrumKitPartial(Integra7PCMDrumKitPartial *partial)
{
    if (partial == NULL) return;

    QObject::connect(ui->AssignTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setAssignType);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::AssignType,
         ui->AssignTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MuteGroupBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setMuteGroup);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::MuteGroup,
         ui->MuteGroupBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPartialLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialLevel);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialLevel,
         ui->PCMDPartialLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPartialCoarseTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialCoarseTune);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialCoarseTune,
         ui->PCMDPartialCoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPartialFineTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialFineTune);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialFineTune,
         ui->PCMDPartialFineTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPartialRandomPitchDepthBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialRandomPitchDepth);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialRandomPitchDepth,
         ui->PCMDPartialRandomPitchDepthBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PCMDPartialPanBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialPan);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialPan,
         ui->PCMDPartialPanBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPartialRandomPanDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialRandomPanDepth);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialRandomPanDepth,
         ui->PCMDPartialRandomPanDepthBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPartialAlternatePanDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialAlternatePanDepth);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialAlternatePanDepth,
         ui->PCMDPartialAlternatePanDepthBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPartialEnvModeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialEnvMode);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialEnvMode,
         ui->PCMDPartialEnvModeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PCMDPartialOutputLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialOutputLevel);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialOutputLevel,
         ui->PCMDPartialOutputLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPartialChorusSendLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialChorusSendLevel);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialChorusSendLevel,
         ui->PCMDPartialChorusSendLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPartialReverbSendLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialReverbSendLevel);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialReverbSendLevel,
         ui->PCMDPartialReverbSendLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->PartialOutputAssignBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialOutputAssign);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialOutputAssign,
         ui->PartialOutputAssignBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PartialPitchBendRangeBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialPitchBendRange);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialPitchBendRange,
         ui->PartialPitchBendRangeBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPartialReceiveExpressionBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setPartialReceiveExpression);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialReceiveExpression,
         ui->PCMDPartialReceiveExpressionBtn,&QPushButton::setChecked);

    QObject::connect(ui->PCMDPartialReceiveHoldBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setPartialReceiveHold);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PartialReceiveHold,
         ui->PCMDPartialReceiveHoldBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMTVelocityControlBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMTVelocityControl);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMTVelocityControl,
         ui->WMTVelocityControlBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT1WaveSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveSwitch,
         ui->WMT1WaveSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT1WaveGroupTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveGroupType);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveGroupType,
         ui->WMT1WaveGroupTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT1WaveGroupIDBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveGroupID);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveGroupID,
         ui->WMT1WaveGroupIDBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1WaveNumberLBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveNumberL);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveNumberL,
         ui->WMT1WaveNumberLBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1WaveNumberRBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveNumberR);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveNumberR,
         ui->WMT1WaveNumberRBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1WaveGainBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveGain);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveGain,
         ui->WMT1WaveGainBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT1WaveFXMSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveFXMSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveFXMSwitch,
         ui->WMT1WaveFXMSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT1WaveFXMColorBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveFXMColor);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveFXMColor,
         ui->WMT1WaveFXMColorBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1WaveFXMDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveFXMDepth);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveFXMDepth,
         ui->WMT1WaveFXMDepthBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1WaveTempoSyncBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveTempoSync);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveTempoSync,
         ui->WMT1WaveTempoSyncBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT1WaveCoarseTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveCoarseTune);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveCoarseTune,
         ui->WMT1WaveCoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1WaveFineTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveFineTune);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveFineTune,
         ui->WMT1WaveFineTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1WavePanBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WavePan);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WavePan,
         ui->WMT1WavePanBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1WaveRandomPanSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveRandomPanSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveRandomPanSwitch,
         ui->WMT1WaveRandomPanSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT1WaveAlternatePanSwitchBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveAlternatePanSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveAlternatePanSwitch,
         ui->WMT1WaveAlternatePanSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT1WaveLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveLevel);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1WaveLevel,
         ui->WMT1WaveLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1VelocityRangeLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1VelocityRangeLower);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1VelocityRangeLower,
         ui->WMT1VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1VelocityRangeUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1VelocityRangeUpper);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1VelocityRangeUpper,
         ui->WMT1VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1VelocityFadeWidthLower);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1VelocityFadeWidthLower,
         ui->WMT1VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT1VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1VelocityFadeWidthUpper);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT1VelocityFadeWidthUpper,
         ui->WMT1VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2WaveSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveSwitch,
         ui->WMT2WaveSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT2WaveGroupTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveGroupType);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveGroupType,
         ui->WMT2WaveGroupTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT2WaveGroupIDBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveGroupID);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveGroupID,
         ui->WMT2WaveGroupIDBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2WaveNumberLBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveNumberL);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveNumberL,
         ui->WMT2WaveNumberLBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2WaveNumberRBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveNumberR);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveNumberR,
         ui->WMT2WaveNumberRBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2WaveGainBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveGain);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveGain,
         ui->WMT2WaveGainBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT2WaveFXMSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveFXMSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveFXMSwitch,
         ui->WMT2WaveFXMSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT2WaveFXMColorBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveFXMColor);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveFXMColor,
         ui->WMT2WaveFXMColorBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2WaveFXMDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveFXMDepth);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveFXMDepth,
         ui->WMT2WaveFXMDepthBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2WaveTempoSyncBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveTempoSync);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveTempoSync,
         ui->WMT2WaveTempoSyncBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT2WaveCoarseTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveCoarseTune);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveCoarseTune,
         ui->WMT2WaveCoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2WaveFineTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveFineTune);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveFineTune,
         ui->WMT2WaveFineTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2WavePanBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WavePan);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WavePan,
         ui->WMT2WavePanBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2WaveRandomPanSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveRandomPanSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveRandomPanSwitch,
         ui->WMT2WaveRandomPanSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT2WaveAlternatePanSwitchBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveAlternatePanSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveAlternatePanSwitch,
         ui->WMT2WaveAlternatePanSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT2WaveLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveLevel);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2WaveLevel,
         ui->WMT2WaveLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2VelocityRangeLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2VelocityRangeLower);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2VelocityRangeLower,
         ui->WMT2VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2VelocityRangeUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2VelocityRangeUpper);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2VelocityRangeUpper,
         ui->WMT2VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2VelocityFadeWidthLower);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2VelocityFadeWidthLower,
         ui->WMT2VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT2VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2VelocityFadeWidthUpper);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT2VelocityFadeWidthUpper,
         ui->WMT2VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3WaveSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveSwitch,
         ui->WMT3WaveSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT3WaveGroupTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveGroupType);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveGroupType,
         ui->WMT3WaveGroupTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT3WaveGroupIDBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveGroupID);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveGroupID,
         ui->WMT3WaveGroupIDBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3WaveNumberLBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveNumberL);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveNumberL,
         ui->WMT3WaveNumberLBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3WaveNumberRBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveNumberR);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveNumberR,
         ui->WMT3WaveNumberRBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3WaveGainBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveGain);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveGain,
         ui->WMT3WaveGainBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT3WaveFXMSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveFXMSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveFXMSwitch,
         ui->WMT3WaveFXMSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT3WaveFXMColorBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveFXMColor);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveFXMColor,
         ui->WMT3WaveFXMColorBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3WaveFXMDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveFXMDepth);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveFXMDepth,
         ui->WMT3WaveFXMDepthBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3WaveTempoSyncBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveTempoSync);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveTempoSync,
         ui->WMT3WaveTempoSyncBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT3WaveCoarseTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveCoarseTune);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveCoarseTune,
         ui->WMT3WaveCoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3WaveFineTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveFineTune);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveFineTune,
         ui->WMT3WaveFineTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3WavePanBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WavePan);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WavePan,
         ui->WMT3WavePanBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3WaveRandomPanSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveRandomPanSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveRandomPanSwitch,
         ui->WMT3WaveRandomPanSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT3WaveAlternatePanSwitchBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveAlternatePanSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveAlternatePanSwitch,
         ui->WMT3WaveAlternatePanSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT3WaveLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveLevel);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3WaveLevel,
         ui->WMT3WaveLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3VelocityRangeLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3VelocityRangeLower);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3VelocityRangeLower,
         ui->WMT3VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3VelocityRangeUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3VelocityRangeUpper);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3VelocityRangeUpper,
         ui->WMT3VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3VelocityFadeWidthLower);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3VelocityFadeWidthLower,
         ui->WMT3VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT3VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3VelocityFadeWidthUpper);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT3VelocityFadeWidthUpper,
         ui->WMT3VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4WaveSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveSwitch,
         ui->WMT4WaveSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT4WaveGroupTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveGroupType);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveGroupType,
         ui->WMT4WaveGroupTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT4WaveGroupIDBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveGroupID);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveGroupID,
         ui->WMT4WaveGroupIDBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4WaveNumberLBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveNumberL);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveNumberL,
         ui->WMT4WaveNumberLBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4WaveNumberRBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveNumberR);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveNumberR,
         ui->WMT4WaveNumberRBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4WaveGainBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveGain);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveGain,
         ui->WMT4WaveGainBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT4WaveFXMSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveFXMSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveFXMSwitch,
         ui->WMT4WaveFXMSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT4WaveFXMColorBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveFXMColor);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveFXMColor,
         ui->WMT4WaveFXMColorBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4WaveFXMDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveFXMDepth);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveFXMDepth,
         ui->WMT4WaveFXMDepthBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4WaveTempoSyncBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveTempoSync);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveTempoSync,
         ui->WMT4WaveTempoSyncBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT4WaveCoarseTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveCoarseTune);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveCoarseTune,
         ui->WMT4WaveCoarseTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4WaveFineTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveFineTune);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveFineTune,
         ui->WMT4WaveFineTuneBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4WavePanBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WavePan);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WavePan,
         ui->WMT4WavePanBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4WaveRandomPanSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveRandomPanSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveRandomPanSwitch,
         ui->WMT4WaveRandomPanSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->WMT4WaveAlternatePanSwitchBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveAlternatePanSwitch);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveAlternatePanSwitch,
         ui->WMT4WaveAlternatePanSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WMT4WaveLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveLevel);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4WaveLevel,
         ui->WMT4WaveLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4VelocityRangeLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4VelocityRangeLower);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4VelocityRangeLower,
         ui->WMT4VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4VelocityRangeUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4VelocityRangeUpper);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4VelocityRangeUpper,
         ui->WMT4VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4VelocityFadeWidthLower);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4VelocityFadeWidthLower,
         ui->WMT4VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::connect(ui->WMT4VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4VelocityFadeWidthUpper);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::WMT4VelocityFadeWidthUpper,
         ui->WMT4VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvDepth);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvDepth,
         ui->PCMDPitchEnvDepthBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvVelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvVelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvVelocitySens,
         ui->PCMDPitchEnvVelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvTime1VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime1VelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime1VelocitySens,
         ui->PCMDPitchEnvTime1VelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvTime4VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime4VelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime4VelocitySens,
         ui->PCMDPitchEnvTime4VelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvTime1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime1);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime1,
         ui->PCMDPitchEnvTime1Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvTime2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime2);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime2,
         ui->PCMDPitchEnvTime2Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvTime3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime3);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime3,
         ui->PCMDPitchEnvTime3Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvTime4Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime4);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime4,
             ui->PCMDPitchEnvTime4Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvLevel0Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvLevel0);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvLevel0,
         ui->PCMDPitchEnvLevel0Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvLevel1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvLevel1);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvLevel1,
         ui->PCMDPitchEnvLevel1Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvLevel2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvLevel2);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvLevel2,
         ui->PCMDPitchEnvLevel2Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvLevel3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvLevel3);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvLevel3,
         ui->PCMDPitchEnvLevel3Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDPitchEnvLevel4Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvLevel4);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::PitchEnvLevel4,
         ui->PCMDPitchEnvLevel4Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFFilterTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFFilterType);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFFilterType,
         ui->PCMDTVFFilterTypeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PCMDTVFCutoffFrequencyBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFCutoffFrequency);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFCutoffFrequency,
         ui->PCMDTVFCutoffFrequencyBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFCutoffVelocityCurveBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFCutoffVelocityCurve);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFCutoffVelocityCurve,
         ui->PCMDTVFCutoffVelocityCurveBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFCutoffVelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFCutoffVelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFCutoffVelocitySens,
         ui->PCMDTVFCutoffVelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFResonanceBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFResonance);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFResonance,
         ui->PCMDTVFResonanceBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFResonanceVelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFResonanceVelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFResonanceVelocitySens,
         ui->PCMDTVFResonanceVelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvDepth);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvDepth,
         ui->PCMDTVFEnvDepthBox,&QSpinBox::setValue);

    QObject::connect(ui->TVFEnvVelocityCurveTypeBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvVelocityCurveType);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvVelocityCurveType,
         ui->TVFEnvVelocityCurveTypeBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvVelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvVelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvVelocitySens,
         ui->PCMDTVFEnvVelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvTime1VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime1VelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime1VelocitySens,
         ui->PCMDTVFEnvTime1VelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvTime4VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime4VelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime4VelocitySens,
         ui->PCMDTVFEnvTime4VelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvTime1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime1);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime1,
         ui->PCMDTVFEnvTime1Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvTime2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime2);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime2,
         ui->PCMDTVFEnvTime2Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvTime3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime3);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime3,
         ui->PCMDTVFEnvTime3Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvTime4Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime4);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime4,
         ui->PCMDTVFEnvTime4Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvLevel0Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvLevel0);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvLevel0,
         ui->PCMDTVFEnvLevel0Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvLevel1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvLevel1);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvLevel1,
         ui->PCMDTVFEnvLevel1Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvLevel2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvLevel2);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvLevel2,
         ui->PCMDTVFEnvLevel2Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvLevel3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvLevel3);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvLevel3,
         ui->PCMDTVFEnvLevel3Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVFEnvLevel4Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvLevel4);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVFEnvLevel4,
         ui->PCMDTVFEnvLevel4Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVALevelVelocityCurveBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVALevelVelocityCurve);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVALevelVelocityCurve,
         ui->PCMDTVALevelVelocityCurveBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVALevelVelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVALevelVelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVALevelVelocitySens,
         ui->PCMDTVALevelVelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVAEnvTime1VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime1VelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime1VelocitySens,
         ui->PCMDTVAEnvTime1VelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVAEnvTime4VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime4VelocitySens);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime4VelocitySens,
         ui->PCMDTVAEnvTime4VelocitySensBox,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVAEnvTime1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime1);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime1,
         ui->PCMDTVAEnvTime1Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVAEnvTime2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime2);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime2,
         ui->PCMDTVAEnvTime2Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVAEnvTime3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime3);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime3,
         ui->PCMDTVAEnvTime3Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVAEnvTime4Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime4);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime4,
         ui->PCMDTVAEnvTime4Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVAEnvLevel1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvLevel1);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVAEnvLevel1,
         ui->PCMDTVAEnvLevel1Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVAEnvLevel2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvLevel2);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVAEnvLevel2,
         ui->PCMDTVAEnvLevel2Box,&QSpinBox::setValue);

    QObject::connect(ui->PCMDTVAEnvLevel3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvLevel3);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::TVAEnvLevel3,
         ui->PCMDTVAEnvLevel3Box,&QSpinBox::setValue);

    QObject::connect(ui->OneShotModeBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setOneShotMode);

    QObject::connect(partial,&Integra7PCMDrumKitPartial::OneShotMode,
         ui->OneShotModeBtn,&QPushButton::setChecked);

}

void integra7MainWindow::DisconnectPCMDrumKit(Integra7Tone *tone)
{
    if (tone == NULL) return;

    QObject::disconnect(ui->KitNameBox,&QLineEdit::textEdited,
         tone->PCMDrumKitCommon,&Integra7PCMDrumKitCommon::setKitName);

    QObject::disconnect(tone->PCMDrumKitCommon,&Integra7PCMDrumKitCommon::KitName,
         ui->KitNameBox,&QLineEdit::setText);

    QObject::disconnect(ui->KitLevelBox,&QSpinBox::valueChanged,
         tone->PCMDrumKitCommon,&Integra7PCMDrumKitCommon::setKitLevel);

    QObject::disconnect(tone->PCMDrumKitCommon,&Integra7PCMDrumKitCommon::KitLevel,
         ui->KitLevelBox,&QSpinBox::setValue);    

    QObject::disconnect(ui->PCMDPhraseNumberBox,&QSpinBox::valueChanged,
         tone->PCMDrumKitCommon2,&Integra7PCMDrumKitCommon2::setPhraseNumber);

    QObject::disconnect(tone->PCMDrumKitCommon2,&Integra7PCMDrumKitCommon2::PhraseNumber,
         ui->PCMDPhraseNumberBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTFXSwitchBtn,&QPushButton::toggled,
         tone->PCMDrumKitCommon2,&Integra7PCMDrumKitCommon2::setTFXSwitch);

    QObject::disconnect(tone->PCMDrumKitCommon2,&Integra7PCMDrumKitCommon2::TFXSwitch,
         ui->PCMDTFXSwitchBtn,&QPushButton::setChecked);
}

void integra7MainWindow::DisconnectPCMDrumKitPartial(Integra7PCMDrumKitPartial *partial)
{
    if (partial == NULL) return;

    QObject::disconnect(ui->AssignTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setAssignType);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::AssignType,
         ui->AssignTypeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MuteGroupBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setMuteGroup);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::MuteGroup,
         ui->MuteGroupBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPartialLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialLevel);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialLevel,
         ui->PCMDPartialLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPartialCoarseTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialCoarseTune);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialCoarseTune,
         ui->PCMDPartialCoarseTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPartialFineTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialFineTune);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialFineTune,
         ui->PCMDPartialFineTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPartialRandomPitchDepthBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialRandomPitchDepth);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialRandomPitchDepth,
         ui->PCMDPartialRandomPitchDepthBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PCMDPartialPanBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialPan);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialPan,
         ui->PCMDPartialPanBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPartialRandomPanDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialRandomPanDepth);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialRandomPanDepth,
         ui->PCMDPartialRandomPanDepthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPartialAlternatePanDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialAlternatePanDepth);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialAlternatePanDepth,
         ui->PCMDPartialAlternatePanDepthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPartialEnvModeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialEnvMode);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialEnvMode,
         ui->PCMDPartialEnvModeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PCMDPartialOutputLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialOutputLevel);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialOutputLevel,
         ui->PCMDPartialOutputLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPartialChorusSendLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialChorusSendLevel);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialChorusSendLevel,
         ui->PCMDPartialChorusSendLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPartialReverbSendLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialReverbSendLevel);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialReverbSendLevel,
         ui->PCMDPartialReverbSendLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PartialOutputAssignBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialOutputAssign);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialOutputAssign,
         ui->PartialOutputAssignBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PartialPitchBendRangeBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPartialPitchBendRange);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialPitchBendRange,
         ui->PartialPitchBendRangeBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPartialReceiveExpressionBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setPartialReceiveExpression);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialReceiveExpression,
         ui->PCMDPartialReceiveExpressionBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PCMDPartialReceiveHoldBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setPartialReceiveHold);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PartialReceiveHold,
         ui->PCMDPartialReceiveHoldBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMTVelocityControlBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMTVelocityControl);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMTVelocityControl,
         ui->WMTVelocityControlBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT1WaveSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveSwitch,
         ui->WMT1WaveSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT1WaveGroupTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveGroupType);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveGroupType,
         ui->WMT1WaveGroupTypeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT1WaveGroupIDBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveGroupID);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveGroupID,
         ui->WMT1WaveGroupIDBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1WaveNumberLBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveNumberL);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveNumberL,
         ui->WMT1WaveNumberLBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1WaveNumberRBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveNumberR);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveNumberR,
         ui->WMT1WaveNumberRBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1WaveGainBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveGain);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveGain,
         ui->WMT1WaveGainBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT1WaveFXMSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveFXMSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveFXMSwitch,
         ui->WMT1WaveFXMSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT1WaveFXMColorBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveFXMColor);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveFXMColor,
         ui->WMT1WaveFXMColorBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1WaveFXMDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveFXMDepth);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveFXMDepth,
         ui->WMT1WaveFXMDepthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1WaveTempoSyncBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveTempoSync);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveTempoSync,
         ui->WMT1WaveTempoSyncBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT1WaveCoarseTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveCoarseTune);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveCoarseTune,
         ui->WMT1WaveCoarseTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1WaveFineTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveFineTune);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveFineTune,
         ui->WMT1WaveFineTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1WavePanBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WavePan);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WavePan,
         ui->WMT1WavePanBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1WaveRandomPanSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveRandomPanSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveRandomPanSwitch,
         ui->WMT1WaveRandomPanSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT1WaveAlternatePanSwitchBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveAlternatePanSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveAlternatePanSwitch,
         ui->WMT1WaveAlternatePanSwitchBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT1WaveLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1WaveLevel);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1WaveLevel,
         ui->WMT1WaveLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1VelocityRangeLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1VelocityRangeLower);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1VelocityRangeLower,
         ui->WMT1VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1VelocityRangeUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1VelocityRangeUpper);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1VelocityRangeUpper,
         ui->WMT1VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1VelocityFadeWidthLower);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1VelocityFadeWidthLower,
         ui->WMT1VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT1VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT1VelocityFadeWidthUpper);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT1VelocityFadeWidthUpper,
         ui->WMT1VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2WaveSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveSwitch,
         ui->WMT2WaveSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT2WaveGroupTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveGroupType);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveGroupType,
         ui->WMT2WaveGroupTypeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT2WaveGroupIDBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveGroupID);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveGroupID,
         ui->WMT2WaveGroupIDBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2WaveNumberLBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveNumberL);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveNumberL,
         ui->WMT2WaveNumberLBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2WaveNumberRBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveNumberR);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveNumberR,
         ui->WMT2WaveNumberRBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2WaveGainBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveGain);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveGain,
         ui->WMT2WaveGainBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT2WaveFXMSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveFXMSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveFXMSwitch,
         ui->WMT2WaveFXMSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT2WaveFXMColorBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveFXMColor);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveFXMColor,
         ui->WMT2WaveFXMColorBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2WaveFXMDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveFXMDepth);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveFXMDepth,
         ui->WMT2WaveFXMDepthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2WaveTempoSyncBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveTempoSync);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveTempoSync,
         ui->WMT2WaveTempoSyncBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT2WaveCoarseTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveCoarseTune);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveCoarseTune,
         ui->WMT2WaveCoarseTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2WaveFineTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveFineTune);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveFineTune,
         ui->WMT2WaveFineTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2WavePanBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WavePan);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WavePan,
         ui->WMT2WavePanBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2WaveRandomPanSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveRandomPanSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveRandomPanSwitch,
         ui->WMT2WaveRandomPanSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT2WaveAlternatePanSwitchBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveAlternatePanSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveAlternatePanSwitch,
         ui->WMT2WaveAlternatePanSwitchBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT2WaveLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2WaveLevel);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2WaveLevel,
         ui->WMT2WaveLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2VelocityRangeLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2VelocityRangeLower);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2VelocityRangeLower,
         ui->WMT2VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2VelocityRangeUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2VelocityRangeUpper);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2VelocityRangeUpper,
         ui->WMT2VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2VelocityFadeWidthLower);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2VelocityFadeWidthLower,
         ui->WMT2VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT2VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT2VelocityFadeWidthUpper);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT2VelocityFadeWidthUpper,
         ui->WMT2VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3WaveSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveSwitch,
         ui->WMT3WaveSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT3WaveGroupTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveGroupType);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveGroupType,
         ui->WMT3WaveGroupTypeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT3WaveGroupIDBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveGroupID);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveGroupID,
         ui->WMT3WaveGroupIDBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3WaveNumberLBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveNumberL);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveNumberL,
         ui->WMT3WaveNumberLBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3WaveNumberRBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveNumberR);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveNumberR,
         ui->WMT3WaveNumberRBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3WaveGainBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveGain);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveGain,
         ui->WMT3WaveGainBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT3WaveFXMSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveFXMSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveFXMSwitch,
         ui->WMT3WaveFXMSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT3WaveFXMColorBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveFXMColor);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveFXMColor,
         ui->WMT3WaveFXMColorBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3WaveFXMDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveFXMDepth);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveFXMDepth,
         ui->WMT3WaveFXMDepthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3WaveTempoSyncBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveTempoSync);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveTempoSync,
         ui->WMT3WaveTempoSyncBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT3WaveCoarseTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveCoarseTune);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveCoarseTune,
         ui->WMT3WaveCoarseTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3WaveFineTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveFineTune);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveFineTune,
         ui->WMT3WaveFineTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3WavePanBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WavePan);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WavePan,
         ui->WMT3WavePanBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3WaveRandomPanSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveRandomPanSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveRandomPanSwitch,
         ui->WMT3WaveRandomPanSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT3WaveAlternatePanSwitchBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveAlternatePanSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveAlternatePanSwitch,
         ui->WMT3WaveAlternatePanSwitchBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT3WaveLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3WaveLevel);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3WaveLevel,
         ui->WMT3WaveLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3VelocityRangeLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3VelocityRangeLower);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3VelocityRangeLower,
         ui->WMT3VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3VelocityRangeUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3VelocityRangeUpper);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3VelocityRangeUpper,
         ui->WMT3VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3VelocityFadeWidthLower);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3VelocityFadeWidthLower,
         ui->WMT3VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT3VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT3VelocityFadeWidthUpper);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT3VelocityFadeWidthUpper,
         ui->WMT3VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4WaveSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveSwitch,
         ui->WMT4WaveSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT4WaveGroupTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveGroupType);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveGroupType,
         ui->WMT4WaveGroupTypeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT4WaveGroupIDBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveGroupID);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveGroupID,
         ui->WMT4WaveGroupIDBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4WaveNumberLBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveNumberL);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveNumberL,
         ui->WMT4WaveNumberLBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4WaveNumberRBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveNumberR);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveNumberR,
         ui->WMT4WaveNumberRBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4WaveGainBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveGain);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveGain,
         ui->WMT4WaveGainBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT4WaveFXMSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveFXMSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveFXMSwitch,
         ui->WMT4WaveFXMSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT4WaveFXMColorBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveFXMColor);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveFXMColor,
         ui->WMT4WaveFXMColorBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4WaveFXMDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveFXMDepth);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveFXMDepth,
         ui->WMT4WaveFXMDepthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4WaveTempoSyncBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveTempoSync);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveTempoSync,
         ui->WMT4WaveTempoSyncBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT4WaveCoarseTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveCoarseTune);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveCoarseTune,
         ui->WMT4WaveCoarseTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4WaveFineTuneBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveFineTune);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveFineTune,
         ui->WMT4WaveFineTuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4WavePanBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WavePan);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WavePan,
         ui->WMT4WavePanBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4WaveRandomPanSwitchBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveRandomPanSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveRandomPanSwitch,
         ui->WMT4WaveRandomPanSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->WMT4WaveAlternatePanSwitchBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveAlternatePanSwitch);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveAlternatePanSwitch,
         ui->WMT4WaveAlternatePanSwitchBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WMT4WaveLevelBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4WaveLevel);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4WaveLevel,
         ui->WMT4WaveLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4VelocityRangeLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4VelocityRangeLower);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4VelocityRangeLower,
         ui->WMT4VelocityRangeLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4VelocityRangeUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4VelocityRangeUpper);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4VelocityRangeUpper,
         ui->WMT4VelocityRangeUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4VelocityFadeWidthLowerBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4VelocityFadeWidthLower);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4VelocityFadeWidthLower,
         ui->WMT4VelocityFadeWidthLowerBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WMT4VelocityFadeWidthUpperBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setWMT4VelocityFadeWidthUpper);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::WMT4VelocityFadeWidthUpper,
         ui->WMT4VelocityFadeWidthUpperBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvDepth);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvDepth,
         ui->PCMDPitchEnvDepthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvVelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvVelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvVelocitySens,
         ui->PCMDPitchEnvVelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvTime1VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime1VelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime1VelocitySens,
         ui->PCMDPitchEnvTime1VelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvTime4VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime4VelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime4VelocitySens,
         ui->PCMDPitchEnvTime4VelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvTime1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime1);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime1,
         ui->PCMDPitchEnvTime1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvTime2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime2);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime2,
         ui->PCMDPitchEnvTime2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvTime3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime3);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime3,
         ui->PCMDPitchEnvTime3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvTime4Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvTime4);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvTime4,
             ui->PCMDPitchEnvTime4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvLevel0Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvLevel0);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvLevel0,
         ui->PCMDPitchEnvLevel0Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvLevel1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvLevel1);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvLevel1,
         ui->PCMDPitchEnvLevel1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvLevel2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvLevel2);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvLevel2,
         ui->PCMDPitchEnvLevel2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvLevel3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvLevel3);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvLevel3,
         ui->PCMDPitchEnvLevel3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDPitchEnvLevel4Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setPitchEnvLevel4);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::PitchEnvLevel4,
         ui->PCMDPitchEnvLevel4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFFilterTypeBox,&QComboBox::currentIndexChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFFilterType);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFFilterType,
         ui->PCMDTVFFilterTypeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PCMDTVFCutoffFrequencyBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFCutoffFrequency);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFCutoffFrequency,
         ui->PCMDTVFCutoffFrequencyBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFCutoffVelocityCurveBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFCutoffVelocityCurve);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFCutoffVelocityCurve,
         ui->PCMDTVFCutoffVelocityCurveBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFCutoffVelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFCutoffVelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFCutoffVelocitySens,
         ui->PCMDTVFCutoffVelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFResonanceBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFResonance);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFResonance,
         ui->PCMDTVFResonanceBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFResonanceVelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFResonanceVelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFResonanceVelocitySens,
         ui->PCMDTVFResonanceVelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvDepthBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvDepth);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvDepth,
         ui->PCMDTVFEnvDepthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->TVFEnvVelocityCurveTypeBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvVelocityCurveType);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvVelocityCurveType,
         ui->TVFEnvVelocityCurveTypeBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvVelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvVelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvVelocitySens,
         ui->PCMDTVFEnvVelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvTime1VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime1VelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime1VelocitySens,
         ui->PCMDTVFEnvTime1VelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvTime4VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime4VelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime4VelocitySens,
         ui->PCMDTVFEnvTime4VelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvTime1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime1);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime1,
         ui->PCMDTVFEnvTime1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvTime2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime2);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime2,
         ui->PCMDTVFEnvTime2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvTime3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime3);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime3,
         ui->PCMDTVFEnvTime3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvTime4Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvTime4);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvTime4,
         ui->PCMDTVFEnvTime4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvLevel0Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvLevel0);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvLevel0,
         ui->PCMDTVFEnvLevel0Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvLevel1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvLevel1);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvLevel1,
         ui->PCMDTVFEnvLevel1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvLevel2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvLevel2);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvLevel2,
         ui->PCMDTVFEnvLevel2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvLevel3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvLevel3);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvLevel3,
         ui->PCMDTVFEnvLevel3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVFEnvLevel4Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVFEnvLevel4);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVFEnvLevel4,
         ui->PCMDTVFEnvLevel4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVALevelVelocityCurveBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVALevelVelocityCurve);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVALevelVelocityCurve,
         ui->PCMDTVALevelVelocityCurveBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVALevelVelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVALevelVelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVALevelVelocitySens,
         ui->PCMDTVALevelVelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVAEnvTime1VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime1VelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime1VelocitySens,
         ui->PCMDTVAEnvTime1VelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVAEnvTime4VelocitySensBox,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime4VelocitySens);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime4VelocitySens,
         ui->PCMDTVAEnvTime4VelocitySensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVAEnvTime1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime1);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime1,
         ui->PCMDTVAEnvTime1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVAEnvTime2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime2);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime2,
         ui->PCMDTVAEnvTime2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVAEnvTime3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime3);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime3,
         ui->PCMDTVAEnvTime3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVAEnvTime4Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvTime4);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVAEnvTime4,
         ui->PCMDTVAEnvTime4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVAEnvLevel1Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvLevel1);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVAEnvLevel1,
         ui->PCMDTVAEnvLevel1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVAEnvLevel2Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvLevel2);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVAEnvLevel2,
         ui->PCMDTVAEnvLevel2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->PCMDTVAEnvLevel3Box,&QSpinBox::valueChanged,
         partial,&Integra7PCMDrumKitPartial::setTVAEnvLevel3);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::TVAEnvLevel3,
         ui->PCMDTVAEnvLevel3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->OneShotModeBtn,&QPushButton::toggled,
         partial,&Integra7PCMDrumKitPartial::setOneShotMode);

    QObject::disconnect(partial,&Integra7PCMDrumKitPartial::OneShotMode,
         ui->OneShotModeBtn,&QPushButton::setChecked);
}

void integra7MainWindow::ConnectSNAcousticTone(Integra7Tone *tone)
{
    if (tone == NULL) return;

    QObject::connect(ui->SNAToneNameBox,&QLineEdit::textEdited,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setToneName);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ToneName,
         ui->SNAToneNameBox,&QLineEdit::setText);

    QObject::connect(ui->SNAToneLevelBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setToneLevel);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ToneLevel,
         ui->SNAToneLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->SNAMonoPolyBox,&QComboBox::currentIndexChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setMonoPoly);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::MonoPoly,
         ui->SNAMonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->PortamentoTimeOffsetBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setPortamentoTimeOffset);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::PortamentoTimeOffset,
         ui->PortamentoTimeOffsetBox,&QSpinBox::setValue);

    QObject::connect(ui->SNACutoffOffsetBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setCutoffOffset);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::CutoffOffset,
         ui->SNACutoffOffsetBox,&QSpinBox::setValue);

    QObject::connect(ui->SNAResonanceOffsetBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setResonanceOffset);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ResonanceOffset,
         ui->SNAResonanceOffsetBox,&QSpinBox::setValue);

    QObject::connect(ui->SNAAttackTimeOffsetBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setAttackTimeOffset);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::AttackTimeOffset,
         ui->SNAAttackTimeOffsetBox,&QSpinBox::setValue);

    QObject::connect(ui->ReleaseTimeOffsetBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setReleaseTimeOffset);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ReleaseTimeOffset,
         ui->ReleaseTimeOffsetBox,&QSpinBox::setValue);

    QObject::connect(ui->VibratoRateBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setVibratoRate);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::VibratoRate,
         ui->VibratoRateBox,&QSpinBox::setValue);

    QObject::connect(ui->VibratoDepthBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setVibratoDepth);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::VibratoDepth,
         ui->VibratoDepthBox,&QSpinBox::setValue);

    QObject::connect(ui->VibratoDelayBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setVibratoDelay);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::VibratoDelay,
         ui->VibratoDelayBox,&QSpinBox::setValue);

    QObject::connect(ui->SNAOctaveShiftBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setOctaveShift);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::OctaveShift,
         ui->SNAOctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(ui->CategoryBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setCategory);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::Category,
         ui->CategoryBox,&QSpinBox::setValue);

    QObject::connect(ui->SNAPhraseNumberBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setPhraseNumber);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::PhraseNumber,
         ui->SNAPhraseNumberBox,&QSpinBox::setValue);

    QObject::connect(ui->SNAPhraseOctaveShiftBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setPhraseOctaveShift);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::PhraseOctaveShift,
         ui->SNAPhraseOctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(ui->SNATFXSwitchBtn,&QPushButton::toggled,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setTFXSwitch);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::TFXSwitch,
         ui->SNATFXSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->InstVariationBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setInstVariation);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::InstVariation,
         ui->InstVariationBox,&QSpinBox::setValue);

    QObject::connect(ui->SNAInstNumberBox,&QComboBox::currentIndexChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setInstNumber);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::InstNumber,
         ui->SNAInstNumberBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->ModifyParameter1Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter1);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter1,
         ui->ModifyParameter1Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter2Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter2);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter2,
         ui->ModifyParameter2Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter3Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter3);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter3,
         ui->ModifyParameter3Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter4Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter4);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter4,
         ui->ModifyParameter4Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter5Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter5);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter5,
         ui->ModifyParameter5Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter6Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter6);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter6,
         ui->ModifyParameter6Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter7Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter7);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter7,
         ui->ModifyParameter7Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter8Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter8);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter8,
         ui->ModifyParameter8Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter9Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter9);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter9,
         ui->ModifyParameter9Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter10Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter10);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter10,
         ui->ModifyParameter10Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter11Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter11);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter11,
         ui->ModifyParameter11Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter12Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter12);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter12,
         ui->ModifyParameter12Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter13Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter13);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter13,
         ui->ModifyParameter13Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter14Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter14);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter14,
         ui->ModifyParameter14Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter15Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter15);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter15,
         ui->ModifyParameter15Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter16Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter16);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter16,
         ui->ModifyParameter16Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter17Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter17);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter17,
         ui->ModifyParameter17Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter18Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter18);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter18,
         ui->ModifyParameter18Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter19Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter19);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter19,
         ui->ModifyParameter19Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter20Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter20);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter20,
         ui->ModifyParameter20Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter21Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter21);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter21,
         ui->ModifyParameter21Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter22Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter22);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter22,
         ui->ModifyParameter22Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter23Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter23);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter23,
         ui->ModifyParameter23Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter24Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter24);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter24,
         ui->ModifyParameter24Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter25Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter25);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter25,
         ui->ModifyParameter25Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter26Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter26);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter26,
         ui->ModifyParameter26Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter27Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter27);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter27,
         ui->ModifyParameter27Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter28Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter28);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter28,
         ui->ModifyParameter28Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter29Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter29);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter29,
         ui->ModifyParameter29Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter30Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter30);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter30,
         ui->ModifyParameter30Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter31Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter31);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter31,
         ui->ModifyParameter31Box,&QSpinBox::setValue);

    QObject::connect(ui->ModifyParameter32Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter32);

    QObject::connect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter32,
         ui->ModifyParameter32Box,&QSpinBox::setValue);    

}

void integra7MainWindow::DisconnectSNAcousticTone(Integra7Tone *tone)
{
    if (tone == NULL) return;

    QObject::disconnect(ui->SNAToneNameBox,&QLineEdit::textEdited,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setToneName);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ToneName,
         ui->SNAToneNameBox,&QLineEdit::setText);

    QObject::disconnect(ui->SNAToneLevelBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setToneLevel);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ToneLevel,
         ui->SNAToneLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNAMonoPolyBox,&QComboBox::currentIndexChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setMonoPoly);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::MonoPoly,
         ui->SNAMonoPolyBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->PortamentoTimeOffsetBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setPortamentoTimeOffset);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::PortamentoTimeOffset,
         ui->PortamentoTimeOffsetBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNACutoffOffsetBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setCutoffOffset);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::CutoffOffset,
         ui->SNACutoffOffsetBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNAResonanceOffsetBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setResonanceOffset);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ResonanceOffset,
         ui->SNAResonanceOffsetBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNAAttackTimeOffsetBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setAttackTimeOffset);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::AttackTimeOffset,
         ui->SNAAttackTimeOffsetBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNAReleaseTimeOffsetBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setReleaseTimeOffset);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ReleaseTimeOffset,
         ui->SNAReleaseTimeOffsetBox,&QSpinBox::setValue);

    QObject::disconnect(ui->VibratoRateBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setVibratoRate);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::VibratoRate,
         ui->VibratoRateBox,&QSpinBox::setValue);

    QObject::disconnect(ui->VibratoDepthBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setVibratoDepth);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::VibratoDepth,
         ui->VibratoDepthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->VibratoDelayBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setVibratoDelay);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::VibratoDelay,
         ui->VibratoDelayBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNAOctaveShiftBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setOctaveShift);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::OctaveShift,
         ui->SNAOctaveShiftBox,&QSpinBox::setValue);

    QObject::disconnect(ui->CategoryBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setCategory);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::Category,
         ui->CategoryBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNAPhraseNumberBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setPhraseNumber);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::PhraseNumber,
         ui->SNAPhraseNumberBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNAPhraseOctaveShiftBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setPhraseOctaveShift);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::PhraseOctaveShift,
         ui->SNAPhraseOctaveShiftBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNATFXSwitchBtn,&QPushButton::toggled,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setTFXSwitch);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::TFXSwitch,
         ui->SNATFXSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->InstVariationBox,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setInstVariation);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::InstVariation,
         ui->InstVariationBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNAInstNumberBox,&QComboBox::currentIndexChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setInstNumber);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::InstNumber,
         ui->SNAInstNumberBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->ModifyParameter1Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter1);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter1,
         ui->ModifyParameter1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter2Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter2);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter2,
         ui->ModifyParameter2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter3Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter3);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter3,
         ui->ModifyParameter3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter4Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter4);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter4,
         ui->ModifyParameter4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter5Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter5);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter5,
         ui->ModifyParameter5Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter6Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter6);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter6,
         ui->ModifyParameter6Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter7Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter7);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter7,
         ui->ModifyParameter7Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter8Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter8);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter8,
         ui->ModifyParameter8Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter9Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter9);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter9,
         ui->ModifyParameter9Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter10Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter10);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter10,
         ui->ModifyParameter10Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter11Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter11);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter11,
         ui->ModifyParameter11Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter12Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter12);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter12,
         ui->ModifyParameter12Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter13Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter13);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter13,
         ui->ModifyParameter13Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter14Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter14);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter14,
         ui->ModifyParameter14Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter15Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter15);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter15,
         ui->ModifyParameter15Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter16Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter16);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter16,
         ui->ModifyParameter16Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter17Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter17);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter17,
         ui->ModifyParameter17Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter18Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter18);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter18,
         ui->ModifyParameter18Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter19Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter19);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter19,
         ui->ModifyParameter19Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter20Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter20);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter20,
         ui->ModifyParameter20Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter21Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter21);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter21,
         ui->ModifyParameter21Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter22Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter22);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter22,
         ui->ModifyParameter22Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter23Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter23);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter23,
         ui->ModifyParameter23Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter24Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter24);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter24,
         ui->ModifyParameter24Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter25Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter25);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter25,
         ui->ModifyParameter25Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter26Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter26);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter26,
         ui->ModifyParameter26Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter27Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter27);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter27,
         ui->ModifyParameter27Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter28Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter28);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter28,
         ui->ModifyParameter28Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter29Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter29);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter29,
         ui->ModifyParameter29Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter30Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter30);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter30,
         ui->ModifyParameter30Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter31Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter31);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter31,
         ui->ModifyParameter31Box,&QSpinBox::setValue);

    QObject::disconnect(ui->ModifyParameter32Box,&QSpinBox::valueChanged,
         tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::setModifyParameter32);

    QObject::disconnect(tone->SNAcousticToneCommon,&Integra7SNAcousticToneCommon::ModifyParameter32,
         ui->ModifyParameter32Box,&QSpinBox::setValue);    
}

void integra7MainWindow::ConnectSNSynthTone(Integra7Tone *tone)
{
    if (tone == NULL) return;

    QObject::connect(ui->ToneNameBox,&QLineEdit::textEdited,
                     tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setToneName);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::ToneName,
                     ui->ToneNameBox,&QLineEdit::setText);

    QObject::connect(ui->SNSToneLevelBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setToneLevel);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::ToneLevel,
         ui->SNSToneLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->SNSPortamentoSwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPortamentoSwitch);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PortamentoSwitch,
         ui->SNSPortamentoSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->SNSPortamentoTimeBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPortamentoTime);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PortamentoTime,
         ui->SNSPortamentoTimeBox,&QSpinBox::setValue);

    QObject::connect(ui->MonoSwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setMonoSwitch);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::MonoSwitch,
         ui->MonoSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->SNSOctaveShiftBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setOctaveShift);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::OctaveShift,
         ui->SNSOctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(ui->SNSPitchBendRangeUpBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPitchBendRangeUp);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PitchBendRangeUp,
         ui->SNSPitchBendRangeUpBox,&QSpinBox::setValue);

    QObject::connect(ui->SNSPitchBendRangeDownBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPitchBendRangeDown);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PitchBendRangeDown,
         ui->SNSPitchBendRangeDownBox,&QSpinBox::setValue);

    QObject::connect(ui->Partial1SwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial1Switch);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial1Switch,
         ui->Partial1SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->Partial1SelectBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial1Select);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial1Select,
         ui->Partial1SelectBtn,&QPushButton::setChecked);

    QObject::connect(ui->Partial2SwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial2Switch);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial2Switch,
         ui->Partial2SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->Partial2SelectBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial2Select);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial2Select,
         ui->Partial2SelectBtn,&QPushButton::setChecked);

    QObject::connect(ui->Partial3SwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial3Switch);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial3Switch,
         ui->Partial3SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->Partial3SelectBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial3Select);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial3Select,
         ui->Partial3SelectBtn,&QPushButton::setChecked);

    QObject::connect(ui->RINGSwitchBox,&QComboBox::currentIndexChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setRINGSwitch);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::RINGSwitch,
         ui->RINGSwitchBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->SNSTFXSwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setTFXSwitch);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::TFXSwitch,
         ui->SNSTFXSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->UnisonSwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setUnisonSwitch);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::UnisonSwitch,
         ui->UnisonSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->SNSPortamentoModeBox,&QComboBox::currentIndexChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPortamentoMode);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PortamentoMode,
         ui->SNSPortamentoModeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->SNSLegatoSwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setLegatoSwitch);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::LegatoSwitch,
         ui->SNSLegatoSwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->SNSAnalogFeelBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setAnalogFeel);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::AnalogFeel,
         ui->SNSAnalogFeelBox,&QSpinBox::setValue);

    QObject::connect(ui->WaveShapeBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setWaveShape);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::WaveShape,
         ui->WaveShapeBox,&QSpinBox::setValue);

    QObject::connect(ui->SNSToneCategoryBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setToneCategory);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::ToneCategory,
         ui->SNSToneCategoryBox,&QSpinBox::setValue);

    QObject::connect(ui->SNSPhraseNumberBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPhraseNumber);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PhraseNumber,
         ui->SNSPhraseNumberBox,&QSpinBox::setValue);

    QObject::connect(ui->SNSPhraseOctaveShiftBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPhraseOctaveShift);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PhraseOctaveShift,
         ui->SNSPhraseOctaveShiftBox,&QSpinBox::setValue);

    QObject::connect(ui->UnisonSizeBox,&QComboBox::currentIndexChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setUnisonSize);

    QObject::connect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::UnisonSize,
         ui->UnisonSizeBox,&QComboBox::setCurrentIndex);    

    QObject::connect(ui->OSCWaveBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCWave);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCWave,
         ui->OSCWaveBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->OSCWaveVariationBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCWaveVariation);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCWaveVariation,
         ui->OSCWaveVariationBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->OSCPitchBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPitch);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPitch,
         ui->OSCPitchBox1,&QSpinBox::setValue);

    QObject::connect(ui->OSCDetuneBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCDetune);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCDetune,
         ui->OSCDetuneBox1,&QSpinBox::setValue);

    QObject::connect(ui->OSCPulseWidthModDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPulseWidthModDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPulseWidthModDepth,
         ui->OSCPulseWidthModDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->OSCPulseWidthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPulseWidth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPulseWidth,
         ui->OSCPulseWidthBox1,&QSpinBox::setValue);

    QObject::connect(ui->OSCPitchEnvAttackTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPitchEnvAttackTime);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPitchEnvAttackTime,
         ui->OSCPitchEnvAttackTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->OSCPitchEnvDecayBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPitchEnvDecay);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPitchEnvDecay,
         ui->OSCPitchEnvDecayBox1,&QSpinBox::setValue);

    QObject::connect(ui->OSCPitchEnvDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPitchEnvDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPitchEnvDepth,
         ui->OSCPitchEnvDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->FILTERModeBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTERMode);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTERMode,
         ui->FILTERModeBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->FILTERSlopeBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTERSlope);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTERSlope,
         ui->FILTERSlopeBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->FILTERCutoffBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTERCutoff);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTERCutoff,
         ui->FILTERCutoffBox1,&QSpinBox::setValue);

    QObject::connect(ui->FILTERCutoffKeyfollowBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTERCutoffKeyfollow);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTERCutoffKeyfollow,
         ui->FILTERCutoffKeyfollowBox1,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvVelocitySensBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvVelocitySens);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvVelocitySens,
         ui->FILTEREnvVelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->FILTERResonanceBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTERResonance);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTERResonance,
         ui->FILTERResonanceBox1,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvAttackTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvAttackTime);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvAttackTime,
         ui->FILTEREnvAttackTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvDecayTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvDecayTime);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvDecayTime,
         ui->FILTEREnvDecayTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvSustainLevelBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvSustainLevel);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvSustainLevel,
         ui->FILTEREnvSustainLevelBox1,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvReleaseTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvReleaseTime);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvReleaseTime,
         ui->FILTEREnvReleaseTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvDepth,
         ui->FILTEREnvDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->AMPLevelBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPLevel);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPLevel,
         ui->AMPLevelBox1,&QSpinBox::setValue);

    QObject::connect(ui->AMPLevelVelocitySensBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPLevelVelocitySens);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPLevelVelocitySens,
         ui->AMPLevelVelocitySensBox1,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvAttackTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPEnvAttackTime);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPEnvAttackTime,
         ui->AMPEnvAttackTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvDecayTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPEnvDecayTime);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPEnvDecayTime,
         ui->AMPEnvDecayTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvSustainLevelBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPEnvSustainLevel);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPEnvSustainLevel,
         ui->AMPEnvSustainLevelBox1,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvReleaseTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPEnvReleaseTime);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPEnvReleaseTime,
         ui->AMPEnvReleaseTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->AMPPanBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPPan);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPPan,
         ui->AMPPanBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFOShapeBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOShape);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOShape,
         ui->LFOShapeBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFORateBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFORate);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFORate,
         ui->LFORateBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFOTempoSyncSwitchBtn1,&QPushButton::toggled,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOTempoSyncSwitch);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOTempoSyncSwitch,
         ui->LFOTempoSyncSwitchBtn1,&QPushButton::setChecked);

    QObject::connect(ui->LFOTempoSyncNoteBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOTempoSyncNote);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOTempoSyncNote,
         ui->LFOTempoSyncNoteBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFOFadeTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOFadeTime);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOFadeTime,
         ui->LFOFadeTimeBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFOKeyTriggerBtn1,&QPushButton::toggled,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOKeyTrigger);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOKeyTrigger,
         ui->LFOKeyTriggerBtn1,&QPushButton::setChecked);

    QObject::connect(ui->LFOPitchDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOPitchDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOPitchDepth,
         ui->LFOPitchDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFOFilterDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOFilterDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOFilterDepth,
         ui->LFOFilterDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFOAmpDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOAmpDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOAmpDepth,
         ui->LFOAmpDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->LFOPanDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOPanDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOPanDepth,
         ui->LFOPanDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOShapeBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOShape);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOShape,
         ui->ModulationLFOShapeBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->ModulationLFORateBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFORate);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFORate,
         ui->ModulationLFORateBox1,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOTempoSyncSwitchBtn1,&QPushButton::toggled,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncSwitch);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncSwitch,
         ui->ModulationLFOTempoSyncSwitchBtn1,&QPushButton::setChecked);

    QObject::connect(ui->ModulationLFOTempoSyncNoteBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncNote);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncNote,
         ui->ModulationLFOTempoSyncNoteBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->OSCPulseWidthShiftBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPulseWidthShift);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPulseWidthShift,
         ui->OSCPulseWidthShiftBox1,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOPitchDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOPitchDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOPitchDepth,
         ui->ModulationLFOPitchDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOFilterDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOFilterDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOFilterDepth,
         ui->ModulationLFOFilterDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOAmpDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOAmpDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOAmpDepth,
         ui->ModulationLFOAmpDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOPanDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOPanDepth);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOPanDepth,
         ui->ModulationLFOPanDepthBox1,&QSpinBox::setValue);

    QObject::connect(ui->CutoffAftertouchSensBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setCutoffAftertouchSens);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::CutoffAftertouchSens,
         ui->CutoffAftertouchSensBox1,&QSpinBox::setValue);

    QObject::connect(ui->LevelAftertouchSensBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLevelAftertouchSens);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LevelAftertouchSens,
         ui->LevelAftertouchSensBox1,&QSpinBox::setValue);

    QObject::connect(ui->WaveGainBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setWaveGain);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::WaveGain,
         ui->WaveGainBox1,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveNumberBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setWaveNumber);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::WaveNumber,
         ui->WaveNumberBox1,&QSpinBox::setValue);

    QObject::connect(ui->HPFCutoffBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setHPFCutoff);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::HPFCutoff,
         ui->HPFCutoffBox1,&QSpinBox::setValue);

    QObject::connect(ui->SuperSawDetuneBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setSuperSawDetune);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::SuperSawDetune,
         ui->SuperSawDetuneBox1,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFORateControlBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFORateControl);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFORateControl,
         ui->ModulationLFORateControlBox1,&QSpinBox::setValue);

    QObject::connect(ui->AMPLevelKeyfollowBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPLevelKeyfollow);

    QObject::connect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPLevelKeyfollow,
         ui->AMPLevelKeyfollowBox1,&QSpinBox::setValue);

    QObject::connect(ui->OSCWaveBox2,&QComboBox::currentIndexChanged,
             tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCWave);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCWave,
         ui->OSCWaveBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->OSCWaveVariationBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCWaveVariation);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCWaveVariation,
         ui->OSCWaveVariationBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->OSCPitchBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPitch);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPitch,
         ui->OSCPitchBox2,&QSpinBox::setValue);

    QObject::connect(ui->OSCDetuneBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCDetune);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCDetune,
         ui->OSCDetuneBox2,&QSpinBox::setValue);

    QObject::connect(ui->OSCPulseWidthModDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPulseWidthModDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPulseWidthModDepth,
         ui->OSCPulseWidthModDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->OSCPulseWidthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPulseWidth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPulseWidth,
         ui->OSCPulseWidthBox2,&QSpinBox::setValue);

    QObject::connect(ui->OSCPitchEnvAttackTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPitchEnvAttackTime);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPitchEnvAttackTime,
         ui->OSCPitchEnvAttackTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->OSCPitchEnvDecayBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPitchEnvDecay);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPitchEnvDecay,
         ui->OSCPitchEnvDecayBox2,&QSpinBox::setValue);

    QObject::connect(ui->OSCPitchEnvDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPitchEnvDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPitchEnvDepth,
         ui->OSCPitchEnvDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->FILTERModeBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTERMode);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTERMode,
         ui->FILTERModeBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->FILTERSlopeBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTERSlope);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTERSlope,
         ui->FILTERSlopeBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->FILTERCutoffBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTERCutoff);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTERCutoff,
         ui->FILTERCutoffBox2,&QSpinBox::setValue);

    QObject::connect(ui->FILTERCutoffKeyfollowBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTERCutoffKeyfollow);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTERCutoffKeyfollow,
         ui->FILTERCutoffKeyfollowBox2,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvVelocitySensBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvVelocitySens);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvVelocitySens,
         ui->FILTEREnvVelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->FILTERResonanceBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTERResonance);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTERResonance,
         ui->FILTERResonanceBox2,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvAttackTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvAttackTime);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvAttackTime,
         ui->FILTEREnvAttackTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvDecayTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvDecayTime);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvDecayTime,
         ui->FILTEREnvDecayTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvSustainLevelBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvSustainLevel);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvSustainLevel,
         ui->FILTEREnvSustainLevelBox2,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvReleaseTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvReleaseTime);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvReleaseTime,
         ui->FILTEREnvReleaseTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvDepth,
         ui->FILTEREnvDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->AMPLevelBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPLevel);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPLevel,
         ui->AMPLevelBox2,&QSpinBox::setValue);

    QObject::connect(ui->AMPLevelVelocitySensBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPLevelVelocitySens);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPLevelVelocitySens,
         ui->AMPLevelVelocitySensBox2,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvAttackTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPEnvAttackTime);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPEnvAttackTime,
         ui->AMPEnvAttackTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvDecayTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPEnvDecayTime);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPEnvDecayTime,
         ui->AMPEnvDecayTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvSustainLevelBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPEnvSustainLevel);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPEnvSustainLevel,
         ui->AMPEnvSustainLevelBox2,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvReleaseTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPEnvReleaseTime);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPEnvReleaseTime,
         ui->AMPEnvReleaseTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->AMPPanBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPPan);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPPan,
         ui->AMPPanBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFOShapeBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOShape);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOShape,
         ui->LFOShapeBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFORateBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFORate);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFORate,
         ui->LFORateBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFOTempoSyncSwitchBtn2,&QPushButton::toggled,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOTempoSyncSwitch);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOTempoSyncSwitch,
         ui->LFOTempoSyncSwitchBtn2,&QPushButton::setChecked);

    QObject::connect(ui->LFOTempoSyncNoteBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOTempoSyncNote);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOTempoSyncNote,
         ui->LFOTempoSyncNoteBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFOFadeTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOFadeTime);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOFadeTime,
         ui->LFOFadeTimeBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFOKeyTriggerBtn2,&QPushButton::toggled,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOKeyTrigger);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOKeyTrigger,
         ui->LFOKeyTriggerBtn2,&QPushButton::setChecked);

    QObject::connect(ui->LFOPitchDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOPitchDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOPitchDepth,
         ui->LFOPitchDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFOFilterDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOFilterDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOFilterDepth,
         ui->LFOFilterDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFOAmpDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOAmpDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOAmpDepth,
         ui->LFOAmpDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->LFOPanDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOPanDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOPanDepth,
         ui->LFOPanDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOShapeBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOShape);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOShape,
         ui->ModulationLFOShapeBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->ModulationLFORateBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFORate);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFORate,
         ui->ModulationLFORateBox2,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOTempoSyncSwitchBtn2,&QPushButton::toggled,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncSwitch);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncSwitch,
         ui->ModulationLFOTempoSyncSwitchBtn2,&QPushButton::setChecked);

    QObject::connect(ui->ModulationLFOTempoSyncNoteBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncNote);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncNote,
         ui->ModulationLFOTempoSyncNoteBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->OSCPulseWidthShiftBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPulseWidthShift);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPulseWidthShift,
         ui->OSCPulseWidthShiftBox2,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOPitchDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOPitchDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOPitchDepth,
         ui->ModulationLFOPitchDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOFilterDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOFilterDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOFilterDepth,
         ui->ModulationLFOFilterDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOAmpDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOAmpDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOAmpDepth,
         ui->ModulationLFOAmpDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOPanDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOPanDepth);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOPanDepth,
         ui->ModulationLFOPanDepthBox2,&QSpinBox::setValue);

    QObject::connect(ui->CutoffAftertouchSensBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setCutoffAftertouchSens);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::CutoffAftertouchSens,
         ui->CutoffAftertouchSensBox2,&QSpinBox::setValue);

    QObject::connect(ui->LevelAftertouchSensBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLevelAftertouchSens);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LevelAftertouchSens,
         ui->LevelAftertouchSensBox2,&QSpinBox::setValue);

    QObject::connect(ui->WaveGainBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setWaveGain);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::WaveGain,
         ui->WaveGainBox2,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveNumberBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setWaveNumber);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::WaveNumber,
         ui->WaveNumberBox2,&QSpinBox::setValue);

    QObject::connect(ui->HPFCutoffBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setHPFCutoff);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::HPFCutoff,
         ui->HPFCutoffBox2,&QSpinBox::setValue);

    QObject::connect(ui->SuperSawDetuneBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setSuperSawDetune);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::SuperSawDetune,
         ui->SuperSawDetuneBox2,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFORateControlBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFORateControl);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFORateControl,
         ui->ModulationLFORateControlBox2,&QSpinBox::setValue);

    QObject::connect(ui->AMPLevelKeyfollowBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPLevelKeyfollow);

    QObject::connect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPLevelKeyfollow,
         ui->AMPLevelKeyfollowBox2,&QSpinBox::setValue);

    QObject::connect(ui->OSCWaveBox3,&QComboBox::currentIndexChanged,
             tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCWave);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCWave,
         ui->OSCWaveBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->OSCWaveVariationBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCWaveVariation);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCWaveVariation,
         ui->OSCWaveVariationBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->OSCPitchBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPitch);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPitch,
         ui->OSCPitchBox3,&QSpinBox::setValue);

    QObject::connect(ui->OSCDetuneBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCDetune);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCDetune,
         ui->OSCDetuneBox3,&QSpinBox::setValue);

    QObject::connect(ui->OSCPulseWidthModDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPulseWidthModDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPulseWidthModDepth,
         ui->OSCPulseWidthModDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->OSCPulseWidthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPulseWidth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPulseWidth,
         ui->OSCPulseWidthBox3,&QSpinBox::setValue);

    QObject::connect(ui->OSCPitchEnvAttackTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPitchEnvAttackTime);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPitchEnvAttackTime,
         ui->OSCPitchEnvAttackTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->OSCPitchEnvDecayBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPitchEnvDecay);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPitchEnvDecay,
         ui->OSCPitchEnvDecayBox3,&QSpinBox::setValue);

    QObject::connect(ui->OSCPitchEnvDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPitchEnvDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPitchEnvDepth,
         ui->OSCPitchEnvDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->FILTERModeBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTERMode);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTERMode,
         ui->FILTERModeBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->FILTERSlopeBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTERSlope);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTERSlope,
         ui->FILTERSlopeBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->FILTERCutoffBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTERCutoff);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTERCutoff,
         ui->FILTERCutoffBox3,&QSpinBox::setValue);

    QObject::connect(ui->FILTERCutoffKeyfollowBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTERCutoffKeyfollow);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTERCutoffKeyfollow,
         ui->FILTERCutoffKeyfollowBox3,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvVelocitySensBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvVelocitySens);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvVelocitySens,
         ui->FILTEREnvVelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->FILTERResonanceBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTERResonance);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTERResonance,
         ui->FILTERResonanceBox3,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvAttackTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvAttackTime);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvAttackTime,
         ui->FILTEREnvAttackTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvDecayTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvDecayTime);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvDecayTime,
         ui->FILTEREnvDecayTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvSustainLevelBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvSustainLevel);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvSustainLevel,
         ui->FILTEREnvSustainLevelBox3,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvReleaseTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvReleaseTime);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvReleaseTime,
         ui->FILTEREnvReleaseTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->FILTEREnvDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvDepth,
         ui->FILTEREnvDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->AMPLevelBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPLevel);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPLevel,
         ui->AMPLevelBox3,&QSpinBox::setValue);

    QObject::connect(ui->AMPLevelVelocitySensBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPLevelVelocitySens);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPLevelVelocitySens,
         ui->AMPLevelVelocitySensBox3,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvAttackTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPEnvAttackTime);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPEnvAttackTime,
         ui->AMPEnvAttackTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvDecayTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPEnvDecayTime);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPEnvDecayTime,
         ui->AMPEnvDecayTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvSustainLevelBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPEnvSustainLevel);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPEnvSustainLevel,
         ui->AMPEnvSustainLevelBox3,&QSpinBox::setValue);

    QObject::connect(ui->AMPEnvReleaseTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPEnvReleaseTime);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPEnvReleaseTime,
         ui->AMPEnvReleaseTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->AMPPanBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPPan);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPPan,
         ui->AMPPanBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFOShapeBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOShape);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOShape,
         ui->LFOShapeBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFORateBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFORate);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFORate,
         ui->LFORateBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFOTempoSyncSwitchBtn3,&QPushButton::toggled,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOTempoSyncSwitch);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOTempoSyncSwitch,
         ui->LFOTempoSyncSwitchBtn3,&QPushButton::setChecked);

    QObject::connect(ui->LFOTempoSyncNoteBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOTempoSyncNote);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOTempoSyncNote,
         ui->LFOTempoSyncNoteBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->LFOFadeTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOFadeTime);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOFadeTime,
         ui->LFOFadeTimeBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFOKeyTriggerBtn3,&QPushButton::toggled,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOKeyTrigger);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOKeyTrigger,
         ui->LFOKeyTriggerBtn3,&QPushButton::setChecked);

    QObject::connect(ui->LFOPitchDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOPitchDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOPitchDepth,
         ui->LFOPitchDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFOFilterDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOFilterDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOFilterDepth,
         ui->LFOFilterDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFOAmpDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOAmpDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOAmpDepth,
         ui->LFOAmpDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->LFOPanDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOPanDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOPanDepth,
         ui->LFOPanDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOShapeBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOShape);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOShape,
         ui->ModulationLFOShapeBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->ModulationLFORateBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFORate);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFORate,
         ui->ModulationLFORateBox3,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOTempoSyncSwitchBtn3,&QPushButton::toggled,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncSwitch);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncSwitch,
         ui->ModulationLFOTempoSyncSwitchBtn3,&QPushButton::setChecked);

    QObject::connect(ui->ModulationLFOTempoSyncNoteBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncNote);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncNote,
         ui->ModulationLFOTempoSyncNoteBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->OSCPulseWidthShiftBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPulseWidthShift);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPulseWidthShift,
         ui->OSCPulseWidthShiftBox3,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOPitchDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOPitchDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOPitchDepth,
         ui->ModulationLFOPitchDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOFilterDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOFilterDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOFilterDepth,
         ui->ModulationLFOFilterDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOAmpDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOAmpDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOAmpDepth,
         ui->ModulationLFOAmpDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFOPanDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOPanDepth);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOPanDepth,
         ui->ModulationLFOPanDepthBox3,&QSpinBox::setValue);

    QObject::connect(ui->CutoffAftertouchSensBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setCutoffAftertouchSens);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::CutoffAftertouchSens,
         ui->CutoffAftertouchSensBox3,&QSpinBox::setValue);

    QObject::connect(ui->LevelAftertouchSensBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLevelAftertouchSens);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LevelAftertouchSens,
         ui->LevelAftertouchSensBox3,&QSpinBox::setValue);

    QObject::connect(ui->WaveGainBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setWaveGain);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::WaveGain,
         ui->WaveGainBox3,&QComboBox::setCurrentIndex);

    QObject::connect(ui->WaveNumberBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setWaveNumber);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::WaveNumber,
         ui->WaveNumberBox3,&QSpinBox::setValue);

    QObject::connect(ui->HPFCutoffBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setHPFCutoff);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::HPFCutoff,
         ui->HPFCutoffBox3,&QSpinBox::setValue);

    QObject::connect(ui->SuperSawDetuneBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setSuperSawDetune);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::SuperSawDetune,
         ui->SuperSawDetuneBox3,&QSpinBox::setValue);

    QObject::connect(ui->ModulationLFORateControlBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFORateControl);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFORateControl,
         ui->ModulationLFORateControlBox3,&QSpinBox::setValue);

    QObject::connect(ui->AMPLevelKeyfollowBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPLevelKeyfollow);

    QObject::connect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPLevelKeyfollow,
         ui->AMPLevelKeyfollowBox3,&QSpinBox::setValue);

}

void integra7MainWindow::DisconnectSNSynthTone(Integra7Tone *tone)
{
    if (tone == NULL) return;

    QObject::disconnect(ui->ToneNameBox,&QLineEdit::textEdited,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setToneName);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::ToneName,
         ui->ToneNameBox,&QLineEdit::setText);

    QObject::disconnect(ui->SNSToneLevelBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setToneLevel);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::ToneLevel,
         ui->SNSToneLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNSPortamentoSwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPortamentoSwitch);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PortamentoSwitch,
         ui->SNSPortamentoSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PortamentoTimeBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPortamentoTime);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PortamentoTime,
         ui->PortamentoTimeBox,&QSpinBox::setValue);

    QObject::disconnect(ui->MonoSwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setMonoSwitch);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::MonoSwitch,
         ui->MonoSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->SNSOctaveShiftBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setOctaveShift);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::OctaveShift,
         ui->SNSOctaveShiftBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchBendRangeUpBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPitchBendRangeUp);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PitchBendRangeUp,
         ui->PitchBendRangeUpBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PitchBendRangeDownBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPitchBendRangeDown);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PitchBendRangeDown,
         ui->PitchBendRangeDownBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Partial1SwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial1Switch);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial1Switch,
         ui->Partial1SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Partial1SelectBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial1Select);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial1Select,
         ui->Partial1SelectBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Partial2SwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial2Switch);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial2Switch,
         ui->Partial2SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Partial2SelectBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial2Select);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial2Select,
         ui->Partial2SelectBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Partial3SwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial3Switch);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial3Switch,
         ui->Partial3SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Partial3SelectBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPartial3Select);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::Partial3Select,
         ui->Partial3SelectBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->RINGSwitchBox,&QComboBox::currentIndexChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setRINGSwitch);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::RINGSwitch,
         ui->RINGSwitchBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->SNSTFXSwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setTFXSwitch);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::TFXSwitch,
         ui->SNSTFXSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->UnisonSwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setUnisonSwitch);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::UnisonSwitch,
         ui->UnisonSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->PortamentoModeBox,&QComboBox::currentIndexChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPortamentoMode);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PortamentoMode,
         ui->PortamentoModeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->SNSLegatoSwitchBtn,&QPushButton::toggled,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setLegatoSwitch);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::LegatoSwitch,
         ui->SNSLegatoSwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->SNSAnalogFeelBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setAnalogFeel);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::AnalogFeel,
         ui->SNSAnalogFeelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveShapeBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setWaveShape);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::WaveShape,
         ui->WaveShapeBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNSToneCategoryBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setToneCategory);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::ToneCategory,
         ui->SNSToneCategoryBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PhraseNumberBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPhraseNumber);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PhraseNumber,
         ui->PhraseNumberBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNSPhraseOctaveShiftBox,&QSpinBox::valueChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setPhraseOctaveShift);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::PhraseOctaveShift,
         ui->SNSPhraseOctaveShiftBox,&QSpinBox::setValue);

    QObject::disconnect(ui->UnisonSizeBox,&QComboBox::currentIndexChanged,
         tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::setUnisonSize);

    QObject::disconnect(tone->SNSynthToneCommon,&Integra7SNSynthToneCommon::UnisonSize,
         ui->UnisonSizeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->OSCWaveBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCWave);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCWave,
         ui->OSCWaveBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->OSCWaveVariationBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCWaveVariation);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCWaveVariation,
         ui->OSCWaveVariationBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->OSCPitchBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPitch);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPitch,
         ui->OSCPitchBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCDetuneBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCDetune);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCDetune,
         ui->OSCDetuneBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPulseWidthModDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPulseWidthModDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPulseWidthModDepth,
         ui->OSCPulseWidthModDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPulseWidthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPulseWidth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPulseWidth,
         ui->OSCPulseWidthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPitchEnvAttackTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPitchEnvAttackTime);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPitchEnvAttackTime,
         ui->OSCPitchEnvAttackTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPitchEnvDecayBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPitchEnvDecay);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPitchEnvDecay,
         ui->OSCPitchEnvDecayBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPitchEnvDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPitchEnvDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPitchEnvDepth,
         ui->OSCPitchEnvDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTERModeBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTERMode);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTERMode,
         ui->FILTERModeBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->FILTERSlopeBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTERSlope);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTERSlope,
         ui->FILTERSlopeBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->FILTERCutoffBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTERCutoff);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTERCutoff,
         ui->FILTERCutoffBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTERCutoffKeyfollowBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTERCutoffKeyfollow);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTERCutoffKeyfollow,
         ui->FILTERCutoffKeyfollowBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvVelocitySensBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvVelocitySens);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvVelocitySens,
         ui->FILTEREnvVelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTERResonanceBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTERResonance);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTERResonance,
         ui->FILTERResonanceBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvAttackTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvAttackTime);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvAttackTime,
         ui->FILTEREnvAttackTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvDecayTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvDecayTime);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvDecayTime,
         ui->FILTEREnvDecayTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvSustainLevelBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvSustainLevel);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvSustainLevel,
         ui->FILTEREnvSustainLevelBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvReleaseTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvReleaseTime);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvReleaseTime,
         ui->FILTEREnvReleaseTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setFILTEREnvDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::FILTEREnvDepth,
         ui->FILTEREnvDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPLevelBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPLevel);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPLevel,
         ui->AMPLevelBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPLevelVelocitySensBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPLevelVelocitySens);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPLevelVelocitySens,
         ui->AMPLevelVelocitySensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvAttackTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPEnvAttackTime);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPEnvAttackTime,
         ui->AMPEnvAttackTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvDecayTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPEnvDecayTime);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPEnvDecayTime,
         ui->AMPEnvDecayTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvSustainLevelBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPEnvSustainLevel);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPEnvSustainLevel,
         ui->AMPEnvSustainLevelBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvReleaseTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPEnvReleaseTime);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPEnvReleaseTime,
         ui->AMPEnvReleaseTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPPanBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPPan);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPPan,
         ui->AMPPanBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOShapeBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOShape);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOShape,
         ui->LFOShapeBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFORateBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFORate);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFORate,
         ui->LFORateBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOTempoSyncSwitchBtn1,&QPushButton::toggled,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOTempoSyncSwitch);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOTempoSyncSwitch,
         ui->LFOTempoSyncSwitchBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->LFOTempoSyncNoteBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOTempoSyncNote);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOTempoSyncNote,
         ui->LFOTempoSyncNoteBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFOFadeTimeBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOFadeTime);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOFadeTime,
         ui->LFOFadeTimeBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOKeyTriggerBtn1,&QPushButton::toggled,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOKeyTrigger);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOKeyTrigger,
         ui->LFOKeyTriggerBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->LFOPitchDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOPitchDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOPitchDepth,
         ui->LFOPitchDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOFilterDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOFilterDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOFilterDepth,
         ui->LFOFilterDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOAmpDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOAmpDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOAmpDepth,
         ui->LFOAmpDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOPanDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLFOPanDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LFOPanDepth,
         ui->LFOPanDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOShapeBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOShape);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOShape,
         ui->ModulationLFOShapeBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->ModulationLFORateBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFORate);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFORate,
         ui->ModulationLFORateBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOTempoSyncSwitchBtn1,&QPushButton::toggled,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncSwitch);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncSwitch,
         ui->ModulationLFOTempoSyncSwitchBtn1,&QPushButton::setChecked);

    QObject::disconnect(ui->ModulationLFOTempoSyncNoteBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncNote);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncNote,
         ui->ModulationLFOTempoSyncNoteBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->OSCPulseWidthShiftBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setOSCPulseWidthShift);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::OSCPulseWidthShift,
         ui->OSCPulseWidthShiftBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOPitchDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOPitchDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOPitchDepth,
         ui->ModulationLFOPitchDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOFilterDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOFilterDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOFilterDepth,
         ui->ModulationLFOFilterDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOAmpDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOAmpDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOAmpDepth,
         ui->ModulationLFOAmpDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOPanDepthBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFOPanDepth);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFOPanDepth,
         ui->ModulationLFOPanDepthBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->CutoffAftertouchSensBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setCutoffAftertouchSens);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::CutoffAftertouchSens,
         ui->CutoffAftertouchSensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->LevelAftertouchSensBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setLevelAftertouchSens);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::LevelAftertouchSens,
         ui->LevelAftertouchSensBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveGainBox1,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setWaveGain);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::WaveGain,
         ui->WaveGainBox1,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveNumberBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setWaveNumber);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::WaveNumber,
         ui->WaveNumberBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->HPFCutoffBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setHPFCutoff);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::HPFCutoff,
         ui->HPFCutoffBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->SuperSawDetuneBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setSuperSawDetune);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::SuperSawDetune,
         ui->SuperSawDetuneBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFORateControlBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setModulationLFORateControl);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::ModulationLFORateControl,
         ui->ModulationLFORateControlBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPLevelKeyfollowBox1,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::setAMPLevelKeyfollow);

    QObject::disconnect(tone->SNSynthTonePartial[0],&Integra7SNSynthTonePartial::AMPLevelKeyfollow,
         ui->AMPLevelKeyfollowBox1,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCWaveBox2,&QComboBox::currentIndexChanged,
             tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCWave);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCWave,
         ui->OSCWaveBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->OSCWaveVariationBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCWaveVariation);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCWaveVariation,
         ui->OSCWaveVariationBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->OSCPitchBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPitch);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPitch,
         ui->OSCPitchBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCDetuneBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCDetune);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCDetune,
         ui->OSCDetuneBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPulseWidthModDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPulseWidthModDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPulseWidthModDepth,
         ui->OSCPulseWidthModDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPulseWidthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPulseWidth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPulseWidth,
         ui->OSCPulseWidthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPitchEnvAttackTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPitchEnvAttackTime);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPitchEnvAttackTime,
         ui->OSCPitchEnvAttackTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPitchEnvDecayBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPitchEnvDecay);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPitchEnvDecay,
         ui->OSCPitchEnvDecayBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPitchEnvDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPitchEnvDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPitchEnvDepth,
         ui->OSCPitchEnvDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTERModeBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTERMode);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTERMode,
         ui->FILTERModeBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->FILTERSlopeBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTERSlope);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTERSlope,
         ui->FILTERSlopeBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->FILTERCutoffBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTERCutoff);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTERCutoff,
         ui->FILTERCutoffBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTERCutoffKeyfollowBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTERCutoffKeyfollow);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTERCutoffKeyfollow,
         ui->FILTERCutoffKeyfollowBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvVelocitySensBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvVelocitySens);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvVelocitySens,
         ui->FILTEREnvVelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTERResonanceBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTERResonance);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTERResonance,
         ui->FILTERResonanceBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvAttackTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvAttackTime);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvAttackTime,
         ui->FILTEREnvAttackTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvDecayTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvDecayTime);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvDecayTime,
         ui->FILTEREnvDecayTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvSustainLevelBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvSustainLevel);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvSustainLevel,
         ui->FILTEREnvSustainLevelBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvReleaseTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvReleaseTime);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvReleaseTime,
         ui->FILTEREnvReleaseTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setFILTEREnvDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::FILTEREnvDepth,
         ui->FILTEREnvDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPLevelBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPLevel);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPLevel,
         ui->AMPLevelBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPLevelVelocitySensBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPLevelVelocitySens);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPLevelVelocitySens,
         ui->AMPLevelVelocitySensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvAttackTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPEnvAttackTime);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPEnvAttackTime,
         ui->AMPEnvAttackTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvDecayTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPEnvDecayTime);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPEnvDecayTime,
         ui->AMPEnvDecayTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvSustainLevelBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPEnvSustainLevel);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPEnvSustainLevel,
         ui->AMPEnvSustainLevelBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvReleaseTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPEnvReleaseTime);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPEnvReleaseTime,
         ui->AMPEnvReleaseTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPPanBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPPan);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPPan,
         ui->AMPPanBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOShapeBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOShape);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOShape,
         ui->LFOShapeBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFORateBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFORate);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFORate,
         ui->LFORateBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOTempoSyncSwitchBtn2,&QPushButton::toggled,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOTempoSyncSwitch);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOTempoSyncSwitch,
         ui->LFOTempoSyncSwitchBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->LFOTempoSyncNoteBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOTempoSyncNote);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOTempoSyncNote,
         ui->LFOTempoSyncNoteBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFOFadeTimeBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOFadeTime);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOFadeTime,
         ui->LFOFadeTimeBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOKeyTriggerBtn2,&QPushButton::toggled,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOKeyTrigger);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOKeyTrigger,
         ui->LFOKeyTriggerBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->LFOPitchDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOPitchDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOPitchDepth,
         ui->LFOPitchDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOFilterDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOFilterDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOFilterDepth,
         ui->LFOFilterDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOAmpDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOAmpDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOAmpDepth,
         ui->LFOAmpDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOPanDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLFOPanDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LFOPanDepth,
         ui->LFOPanDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOShapeBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOShape);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOShape,
         ui->ModulationLFOShapeBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->ModulationLFORateBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFORate);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFORate,
         ui->ModulationLFORateBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOTempoSyncSwitchBtn2,&QPushButton::toggled,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncSwitch);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncSwitch,
         ui->ModulationLFOTempoSyncSwitchBtn2,&QPushButton::setChecked);

    QObject::disconnect(ui->ModulationLFOTempoSyncNoteBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncNote);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncNote,
         ui->ModulationLFOTempoSyncNoteBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->OSCPulseWidthShiftBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setOSCPulseWidthShift);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::OSCPulseWidthShift,
         ui->OSCPulseWidthShiftBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOPitchDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOPitchDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOPitchDepth,
         ui->ModulationLFOPitchDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOFilterDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOFilterDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOFilterDepth,
         ui->ModulationLFOFilterDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOAmpDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOAmpDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOAmpDepth,
         ui->ModulationLFOAmpDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOPanDepthBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFOPanDepth);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFOPanDepth,
         ui->ModulationLFOPanDepthBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->CutoffAftertouchSensBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setCutoffAftertouchSens);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::CutoffAftertouchSens,
         ui->CutoffAftertouchSensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->LevelAftertouchSensBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setLevelAftertouchSens);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::LevelAftertouchSens,
         ui->LevelAftertouchSensBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveGainBox2,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setWaveGain);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::WaveGain,
         ui->WaveGainBox2,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveNumberBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setWaveNumber);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::WaveNumber,
         ui->WaveNumberBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->HPFCutoffBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setHPFCutoff);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::HPFCutoff,
         ui->HPFCutoffBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->SuperSawDetuneBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setSuperSawDetune);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::SuperSawDetune,
         ui->SuperSawDetuneBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFORateControlBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setModulationLFORateControl);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::ModulationLFORateControl,
         ui->ModulationLFORateControlBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPLevelKeyfollowBox2,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::setAMPLevelKeyfollow);

    QObject::disconnect(tone->SNSynthTonePartial[1],&Integra7SNSynthTonePartial::AMPLevelKeyfollow,
         ui->AMPLevelKeyfollowBox2,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCWaveBox3,&QComboBox::currentIndexChanged,
             tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCWave);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCWave,
         ui->OSCWaveBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->OSCWaveVariationBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCWaveVariation);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCWaveVariation,
         ui->OSCWaveVariationBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->OSCPitchBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPitch);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPitch,
         ui->OSCPitchBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCDetuneBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCDetune);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCDetune,
         ui->OSCDetuneBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPulseWidthModDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPulseWidthModDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPulseWidthModDepth,
         ui->OSCPulseWidthModDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPulseWidthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPulseWidth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPulseWidth,
         ui->OSCPulseWidthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPitchEnvAttackTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPitchEnvAttackTime);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPitchEnvAttackTime,
         ui->OSCPitchEnvAttackTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPitchEnvDecayBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPitchEnvDecay);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPitchEnvDecay,
         ui->OSCPitchEnvDecayBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->OSCPitchEnvDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPitchEnvDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPitchEnvDepth,
         ui->OSCPitchEnvDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTERModeBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTERMode);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTERMode,
         ui->FILTERModeBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->FILTERSlopeBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTERSlope);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTERSlope,
         ui->FILTERSlopeBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->FILTERCutoffBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTERCutoff);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTERCutoff,
         ui->FILTERCutoffBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTERCutoffKeyfollowBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTERCutoffKeyfollow);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTERCutoffKeyfollow,
         ui->FILTERCutoffKeyfollowBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvVelocitySensBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvVelocitySens);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvVelocitySens,
         ui->FILTEREnvVelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTERResonanceBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTERResonance);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTERResonance,
         ui->FILTERResonanceBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvAttackTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvAttackTime);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvAttackTime,
         ui->FILTEREnvAttackTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvDecayTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvDecayTime);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvDecayTime,
         ui->FILTEREnvDecayTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvSustainLevelBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvSustainLevel);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvSustainLevel,
         ui->FILTEREnvSustainLevelBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvReleaseTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvReleaseTime);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvReleaseTime,
         ui->FILTEREnvReleaseTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->FILTEREnvDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setFILTEREnvDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::FILTEREnvDepth,
         ui->FILTEREnvDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPLevelBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPLevel);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPLevel,
         ui->AMPLevelBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPLevelVelocitySensBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPLevelVelocitySens);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPLevelVelocitySens,
         ui->AMPLevelVelocitySensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvAttackTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPEnvAttackTime);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPEnvAttackTime,
         ui->AMPEnvAttackTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvDecayTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPEnvDecayTime);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPEnvDecayTime,
         ui->AMPEnvDecayTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvSustainLevelBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPEnvSustainLevel);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPEnvSustainLevel,
         ui->AMPEnvSustainLevelBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPEnvReleaseTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPEnvReleaseTime);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPEnvReleaseTime,
         ui->AMPEnvReleaseTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPPanBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPPan);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPPan,
         ui->AMPPanBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOShapeBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOShape);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOShape,
         ui->LFOShapeBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFORateBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFORate);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFORate,
         ui->LFORateBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOTempoSyncSwitchBtn3,&QPushButton::toggled,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOTempoSyncSwitch);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOTempoSyncSwitch,
         ui->LFOTempoSyncSwitchBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->LFOTempoSyncNoteBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOTempoSyncNote);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOTempoSyncNote,
         ui->LFOTempoSyncNoteBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->LFOFadeTimeBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOFadeTime);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOFadeTime,
         ui->LFOFadeTimeBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOKeyTriggerBtn3,&QPushButton::toggled,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOKeyTrigger);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOKeyTrigger,
         ui->LFOKeyTriggerBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->LFOPitchDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOPitchDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOPitchDepth,
         ui->LFOPitchDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOFilterDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOFilterDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOFilterDepth,
         ui->LFOFilterDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOAmpDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOAmpDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOAmpDepth,
         ui->LFOAmpDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LFOPanDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLFOPanDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LFOPanDepth,
         ui->LFOPanDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOShapeBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOShape);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOShape,
         ui->ModulationLFOShapeBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->ModulationLFORateBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFORate);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFORate,
         ui->ModulationLFORateBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOTempoSyncSwitchBtn3,&QPushButton::toggled,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncSwitch);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncSwitch,
         ui->ModulationLFOTempoSyncSwitchBtn3,&QPushButton::setChecked);

    QObject::disconnect(ui->ModulationLFOTempoSyncNoteBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOTempoSyncNote);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOTempoSyncNote,
         ui->ModulationLFOTempoSyncNoteBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->OSCPulseWidthShiftBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setOSCPulseWidthShift);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::OSCPulseWidthShift,
         ui->OSCPulseWidthShiftBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOPitchDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOPitchDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOPitchDepth,
         ui->ModulationLFOPitchDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOFilterDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOFilterDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOFilterDepth,
         ui->ModulationLFOFilterDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOAmpDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOAmpDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOAmpDepth,
         ui->ModulationLFOAmpDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFOPanDepthBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFOPanDepth);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFOPanDepth,
         ui->ModulationLFOPanDepthBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->CutoffAftertouchSensBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setCutoffAftertouchSens);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::CutoffAftertouchSens,
         ui->CutoffAftertouchSensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->LevelAftertouchSensBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setLevelAftertouchSens);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::LevelAftertouchSens,
         ui->LevelAftertouchSensBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->WaveGainBox3,&QComboBox::currentIndexChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setWaveGain);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::WaveGain,
         ui->WaveGainBox3,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->WaveNumberBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setWaveNumber);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::WaveNumber,
         ui->WaveNumberBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->HPFCutoffBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setHPFCutoff);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::HPFCutoff,
         ui->HPFCutoffBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->SuperSawDetuneBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setSuperSawDetune);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::SuperSawDetune,
         ui->SuperSawDetuneBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->ModulationLFORateControlBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setModulationLFORateControl);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::ModulationLFORateControl,
         ui->ModulationLFORateControlBox3,&QSpinBox::setValue);

    QObject::disconnect(ui->AMPLevelKeyfollowBox3,&QSpinBox::valueChanged,
         tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::setAMPLevelKeyfollow);

    QObject::disconnect(tone->SNSynthTonePartial[2],&Integra7SNSynthTonePartial::AMPLevelKeyfollow,
         ui->AMPLevelKeyfollowBox3,&QSpinBox::setValue);
}

void integra7MainWindow::ConnectSNDrumKit(Integra7Tone *tone)
{
    if (tone == NULL) return;

    QObject::connect(ui->SNDrumKitNameBox,&QLineEdit::textEdited,
         tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::setKitName);

    QObject::connect(tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::KitName,
         ui->SNDrumKitNameBox,&QLineEdit::setText);

    QObject::connect(ui->SNDrumKitLevelBox,&QSpinBox::valueChanged,
         tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::setKitLevel);

    QObject::connect(tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::KitLevel,
         ui->SNDrumKitLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->SNDrumKitAmbienceLevelBox,&QSpinBox::valueChanged,
         tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::setAmbienceLevel);

    QObject::connect(tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::AmbienceLevel,
         ui->SNDrumKitAmbienceLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->SNDrumKitPhraseNumberBox,&QSpinBox::valueChanged,
         tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::setPhraseNumber);

    QObject::connect(tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::PhraseNumber,
         ui->SNDrumKitPhraseNumberBox,&QSpinBox::setValue);

    QObject::connect(ui->SNDrumKitTFXSwitchBtn,&QPushButton::toggled,
         tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::setTFXSwitch);

    QObject::connect(tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::TFXSwitch,
         ui->SNDrumKitTFXSwitchBtn,&QPushButton::setChecked);
}

void integra7MainWindow::ConnectSNDrumKitNote(Integra7SNDrumKitNote *note)
{
    if (note == NULL) return;

    QObject::connect(ui->InstNumberBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setInstNumber);

    QObject::connect(note,&Integra7SNDrumKitNote::InstNumber,
         ui->InstNumberBox,&QSpinBox::setValue);

    QObject::connect(ui->LevelBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setLevel);

    QObject::connect(note,&Integra7SNDrumKitNote::Level,
         ui->LevelBox,&QSpinBox::setValue);

    QObject::connect(ui->PanBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setPan);

    QObject::connect(note,&Integra7SNDrumKitNote::Pan,
         ui->PanBox,&QSpinBox::setValue);

    QObject::connect(ui->ChorusSendLevelBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setChorusSendLevel);

    QObject::connect(note,&Integra7SNDrumKitNote::ChorusSendLevel,
         ui->ChorusSendLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->ReverbSendLevelBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setReverbSendLevel);

    QObject::connect(note,&Integra7SNDrumKitNote::ReverbSendLevel,
         ui->ReverbSendLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->TuneBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setTune);

    QObject::connect(note,&Integra7SNDrumKitNote::Tune,
         ui->TuneBox,&QSpinBox::setValue);

    QObject::connect(ui->AttackBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setAttack);

    QObject::connect(note,&Integra7SNDrumKitNote::Attack,
         ui->AttackBox,&QSpinBox::setValue);

    QObject::connect(ui->DecayBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setDecay);

    QObject::connect(note,&Integra7SNDrumKitNote::Decay,
         ui->DecayBox,&QSpinBox::setValue);

    QObject::connect(ui->BrillianceBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setBrilliance);

    QObject::connect(note,&Integra7SNDrumKitNote::Brilliance,
         ui->BrillianceBox,&QSpinBox::setValue);

    QObject::connect(ui->VariationBox,&QComboBox::currentIndexChanged,
         note,&Integra7SNDrumKitNote::setVariation);

    QObject::connect(note,&Integra7SNDrumKitNote::Variation,
         ui->VariationBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->DynamicRangeBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setDynamicRange);

    QObject::connect(note,&Integra7SNDrumKitNote::DynamicRange,
         ui->DynamicRangeBox,&QSpinBox::setValue);

    QObject::connect(ui->StereoWidthBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setStereoWidth);

    QObject::connect(note,&Integra7SNDrumKitNote::StereoWidth,
         ui->StereoWidthBox,&QSpinBox::setValue);

    QObject::connect(ui->OutputAssignBox,&QComboBox::currentIndexChanged,
         note,&Integra7SNDrumKitNote::setOutputAssign);

    QObject::connect(note,&Integra7SNDrumKitNote::OutputAssign,
         ui->OutputAssignBox,&QComboBox::setCurrentIndex);

}

void integra7MainWindow::DisconnectSNDrumKit(Integra7Tone *tone)
{
    if (tone == NULL) return;

    QObject::disconnect(ui->SNDrumKitNameBox,&QLineEdit::textEdited,
         tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::setKitName);

    QObject::disconnect(tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::KitName,
         ui->SNDrumKitNameBox,&QLineEdit::setText);

    QObject::disconnect(ui->SNDrumKitLevelBox,&QSpinBox::valueChanged,
         tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::setKitLevel);

    QObject::disconnect(tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::KitLevel,
         ui->SNDrumKitLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNDrumKitAmbienceLevelBox,&QSpinBox::valueChanged,
         tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::setAmbienceLevel);

    QObject::disconnect(tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::AmbienceLevel,
         ui->SNDrumKitAmbienceLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNDrumKitPhraseNumberBox,&QSpinBox::valueChanged,
         tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::setPhraseNumber);

    QObject::disconnect(tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::PhraseNumber,
         ui->SNDrumKitPhraseNumberBox,&QSpinBox::setValue);

    QObject::disconnect(ui->SNDrumKitTFXSwitchBtn,&QPushButton::toggled,
         tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::setTFXSwitch);

    QObject::disconnect(tone->SNDrumKitCommon,&Integra7SNDrumKitCommon::TFXSwitch,
         ui->SNDrumKitTFXSwitchBtn,&QPushButton::setChecked);
}

void integra7MainWindow::DisconnectSNDrumKitNote(Integra7SNDrumKitNote *note)
{
    if (note == NULL) return;

    QObject::disconnect(ui->InstNumberBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setInstNumber);

    QObject::disconnect(note,&Integra7SNDrumKitNote::InstNumber,
         ui->InstNumberBox,&QSpinBox::setValue);

    QObject::disconnect(ui->LevelBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setLevel);

    QObject::disconnect(note,&Integra7SNDrumKitNote::Level,
         ui->LevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->PanBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setPan);

    QObject::disconnect(note,&Integra7SNDrumKitNote::Pan,
         ui->PanBox,&QSpinBox::setValue);

    QObject::disconnect(ui->ChorusSendLevelBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setChorusSendLevel);

    QObject::disconnect(note,&Integra7SNDrumKitNote::ChorusSendLevel,
         ui->ChorusSendLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->ReverbSendLevelBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setReverbSendLevel);

    QObject::disconnect(note,&Integra7SNDrumKitNote::ReverbSendLevel,
         ui->ReverbSendLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->TuneBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setTune);

    QObject::disconnect(note,&Integra7SNDrumKitNote::Tune,
         ui->TuneBox,&QSpinBox::setValue);

    QObject::disconnect(ui->AttackBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setAttack);

    QObject::disconnect(note,&Integra7SNDrumKitNote::Attack,
         ui->AttackBox,&QSpinBox::setValue);

    QObject::disconnect(ui->DecayBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setDecay);

    QObject::disconnect(note,&Integra7SNDrumKitNote::Decay,
         ui->DecayBox,&QSpinBox::setValue);

    QObject::disconnect(ui->BrillianceBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setBrilliance);

    QObject::disconnect(note,&Integra7SNDrumKitNote::Brilliance,
         ui->BrillianceBox,&QSpinBox::setValue);

    QObject::disconnect(ui->VariationBox,&QComboBox::currentIndexChanged,
         note,&Integra7SNDrumKitNote::setVariation);

    QObject::disconnect(note,&Integra7SNDrumKitNote::Variation,
         ui->VariationBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->DynamicRangeBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setDynamicRange);

    QObject::disconnect(note,&Integra7SNDrumKitNote::DynamicRange,
         ui->DynamicRangeBox,&QSpinBox::setValue);

    QObject::disconnect(ui->StereoWidthBox,&QSpinBox::valueChanged,
         note,&Integra7SNDrumKitNote::setStereoWidth);

    QObject::disconnect(note,&Integra7SNDrumKitNote::StereoWidth,
         ui->StereoWidthBox,&QSpinBox::setValue);

    QObject::disconnect(ui->OutputAssignBox,&QComboBox::currentIndexChanged,
         note,&Integra7SNDrumKitNote::setOutputAssign);

    QObject::disconnect(note,&Integra7SNDrumKitNote::OutputAssign,
         ui->OutputAssignBox,&QComboBox::setCurrentIndex);
}

void integra7MainWindow::ConnectMFX(Integra7ToneMFX *mfxd)
{
    if (mfxd == NULL) return;

    QObject::connect(ui->MFXTypeBox,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXType);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXType,
                     ui->MFXTypeBox,&QSpinBox::setValue);

    QObject::connect(ui->MFXChorusSendLevelBox,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXChorusSendLevel);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXChorusSendLevel,
                     ui->MFXChorusSendLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->MFXReverbSendLevelBox,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXReverbSendLevel);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXReverbSendLevel,
                     ui->MFXReverbSendLevelBox,&QSpinBox::setValue);

    QObject::connect(ui->MFXControl1SourceBox,&QComboBox::currentIndexChanged,
                     mfxd,&Integra7ToneMFX::setMFXControl1Source);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControl1Source,
                     ui->MFXControl1SourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MFXControl1SensBox,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXControl1Sens);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControl1Sens,
                     ui->MFXControl1SensBox,&QSpinBox::setValue);

    QObject::connect(ui->MFXControl2SourceBox,&QComboBox::currentIndexChanged,
                     mfxd,&Integra7ToneMFX::setMFXControl2Source);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControl2Source,
                     ui->MFXControl2SourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MFXControl2SensBox,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXControl2Sens);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControl2Sens,
                     ui->MFXControl2SensBox,&QSpinBox::setValue);

    QObject::connect(ui->MFXControl3SourceBox,&QComboBox::currentIndexChanged,
                     mfxd,&Integra7ToneMFX::setMFXControl3Source);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControl3Source,
                     ui->MFXControl3SourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MFXControl3SensBox,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXControl3Sens);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControl3Sens,
                     ui->MFXControl3SensBox,&QSpinBox::setValue);

    QObject::connect(ui->MFXControl4SourceBox,&QComboBox::currentIndexChanged,
                     mfxd,&Integra7ToneMFX::setMFXControl4Source);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControl4Source,
                     ui->MFXControl4SourceBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->MFXControl4SensBox,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXControl4Sens);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControl4Sens,
                     ui->MFXControl4SensBox,&QSpinBox::setValue);

    QObject::connect(ui->MFXControlAssign1Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXControlAssign1);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControlAssign1,
                     ui->MFXControlAssign1Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXControlAssign2Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXControlAssign2);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControlAssign2,
                     ui->MFXControlAssign2Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXControlAssign3Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXControlAssign3);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControlAssign3,
                     ui->MFXControlAssign3Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXControlAssign4Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXControlAssign4);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXControlAssign4,
                     ui->MFXControlAssign4Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter1Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter1);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter1,
                     ui->MFXParameter1Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter2Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter2);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter2,
                     ui->MFXParameter2Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter3Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter3);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter3,
                     ui->MFXParameter3Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter4Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter4);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter4,
                     ui->MFXParameter4Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter5Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter5);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter5,
                     ui->MFXParameter5Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter6Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter6);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter6,
                     ui->MFXParameter6Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter7Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter7);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter7,
                     ui->MFXParameter7Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter8Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter8);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter8,
                     ui->MFXParameter8Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter9Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter9);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter9,
                     ui->MFXParameter9Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter10Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter10);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter10,
                     ui->MFXParameter10Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter11Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter11);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter11,
                     ui->MFXParameter11Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter12Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter12);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter12,
                     ui->MFXParameter12Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter13Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter13);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter13,
                     ui->MFXParameter13Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter14Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter14);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter14,
                     ui->MFXParameter14Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter15Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter15);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter15,
                     ui->MFXParameter15Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter16Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter16);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter16,
                     ui->MFXParameter16Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter17Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter17);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter17,
                     ui->MFXParameter17Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter18Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter18);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter18,
                     ui->MFXParameter18Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter19Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter19);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter19,
                     ui->MFXParameter19Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter20Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter20);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter20,
                     ui->MFXParameter20Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter21Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter21);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter21,
                     ui->MFXParameter21Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter22Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter22);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter22,
                     ui->MFXParameter22Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter23Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter23);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter23,
                     ui->MFXParameter23Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter24Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter24);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter24,
                     ui->MFXParameter24Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter25Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter25);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter25,
                     ui->MFXParameter25Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter26Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter26);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter26,
                     ui->MFXParameter26Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter27Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter27);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter27,
                     ui->MFXParameter27Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter28Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter28);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter28,
                     ui->MFXParameter28Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter29Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter29);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter29,
                     ui->MFXParameter29Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter30Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter30);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter30,
                     ui->MFXParameter30Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter31Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter31);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter31,
                     ui->MFXParameter31Box,&QSpinBox::setValue);

    QObject::connect(ui->MFXParameter32Box,&QSpinBox::valueChanged,
                     mfxd,&Integra7ToneMFX::setMFXParameter32);

    QObject::connect(mfxd,&Integra7ToneMFX::MFXParameter32,
                     ui->MFXParameter32Box,&QSpinBox::setValue);
}

void integra7MainWindow::DisconnectMFX(Integra7ToneMFX *mfxd)
{
    if (mfxd == NULL) return;

    QObject::disconnect(ui->MFXTypeBox,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXType);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXType,
                        ui->MFXTypeBox,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXChorusSendLevelBox,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXChorusSendLevel);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXChorusSendLevel,
                        ui->MFXChorusSendLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXReverbSendLevelBox,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXReverbSendLevel);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXReverbSendLevel,
                        ui->MFXReverbSendLevelBox,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXControl1SourceBox,&QComboBox::currentIndexChanged,
                        mfxd,&Integra7ToneMFX::setMFXControl1Source);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControl1Source,
                        ui->MFXControl1SourceBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MFXControl1SensBox,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXControl1Sens);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControl1Sens,
                        ui->MFXControl1SensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXControl2SourceBox,&QComboBox::currentIndexChanged,
                        mfxd,&Integra7ToneMFX::setMFXControl2Source);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControl2Source,
                        ui->MFXControl2SourceBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MFXControl2SensBox,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXControl2Sens);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControl2Sens,
                        ui->MFXControl2SensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXControl3SourceBox,&QComboBox::currentIndexChanged,
                        mfxd,&Integra7ToneMFX::setMFXControl3Source);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControl3Source,
                        ui->MFXControl3SourceBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MFXControl3SensBox,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXControl3Sens);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControl3Sens,
                        ui->MFXControl3SensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXControl4SourceBox,&QComboBox::currentIndexChanged,
                        mfxd,&Integra7ToneMFX::setMFXControl4Source);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControl4Source,
                        ui->MFXControl4SourceBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->MFXControl4SensBox,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXControl4Sens);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControl4Sens,
                        ui->MFXControl4SensBox,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXControlAssign1Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXControlAssign1);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControlAssign1,
                        ui->MFXControlAssign1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXControlAssign2Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXControlAssign2);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControlAssign2,
                        ui->MFXControlAssign2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXControlAssign3Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXControlAssign3);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControlAssign3,
                        ui->MFXControlAssign3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXControlAssign4Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXControlAssign4);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXControlAssign4,
                        ui->MFXControlAssign4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter1Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter1);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter1,
                        ui->MFXParameter1Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter2Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter2);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter2,
                        ui->MFXParameter2Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter3Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter3);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter3,
                        ui->MFXParameter3Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter4Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter4);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter4,
                        ui->MFXParameter4Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter5Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter5);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter5,
                        ui->MFXParameter5Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter6Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter6);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter6,
                        ui->MFXParameter6Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter7Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter7);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter7,
                        ui->MFXParameter7Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter8Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter8);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter8,
                        ui->MFXParameter8Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter9Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter9);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter9,
                        ui->MFXParameter9Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter10Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter10);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter10,
                        ui->MFXParameter10Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter11Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter11);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter11,
                        ui->MFXParameter11Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter12Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter12);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter12,
                        ui->MFXParameter12Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter13Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter13);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter13,
                        ui->MFXParameter13Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter14Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter14);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter14,
                        ui->MFXParameter14Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter15Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter15);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter15,
                        ui->MFXParameter15Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter16Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter16);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter16,
                        ui->MFXParameter16Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter17Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter17);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter17,
                        ui->MFXParameter17Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter18Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter18);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter18,
                        ui->MFXParameter18Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter19Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter19);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter19,
                        ui->MFXParameter19Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter20Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter20);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter20,
                        ui->MFXParameter20Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter21Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter21);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter21,
                        ui->MFXParameter21Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter22Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter22);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter22,
                        ui->MFXParameter22Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter23Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter23);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter23,
                        ui->MFXParameter23Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter24Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter24);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter24,
                        ui->MFXParameter24Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter25Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter25);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter25,
                        ui->MFXParameter25Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter26Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter26);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter26,
                        ui->MFXParameter26Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter27Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter27);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter27,
                        ui->MFXParameter27Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter28Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter28);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter28,
                        ui->MFXParameter28Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter29Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter29);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter29,
                        ui->MFXParameter29Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter30Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter30);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter30,
                        ui->MFXParameter30Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter31Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter31);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter31,
                        ui->MFXParameter31Box,&QSpinBox::setValue);

    QObject::disconnect(ui->MFXParameter32Box,&QSpinBox::valueChanged,
                        mfxd,&Integra7ToneMFX::setMFXParameter32);

    QObject::disconnect(mfxd,&Integra7ToneMFX::MFXParameter32,
                        ui->MFXParameter32Box,&QSpinBox::setValue);
}

void integra7MainWindow::ConnectDrumCompEQ(Integra7DrumCompEQ *compeqd)
{
    if (compeqd == NULL) return;

    QObject::connect(ui->Comp1SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp1Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp1Switch,
         ui->Comp1SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->Comp1AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp1AttackTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp1AttackTime,
         ui->Comp1AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp1ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp1ReleaseTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp1ReleaseTime,
         ui->Comp1ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp1ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp1Threshold);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp1Threshold,
         ui->Comp1ThresholdBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp1RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp1Ratio);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp1Ratio,
         ui->Comp1RatioBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp1OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp1OutputGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp1OutputGain,
         ui->Comp1OutputGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ1SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ1Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ1Switch,
         ui->EQ1SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->EQ1LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1LowFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ1LowFreq,
         ui->EQ1LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ1LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1LowGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ1LowGain,
         ui->EQ1LowGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ1MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1MidFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ1MidFreq,
         ui->EQ1MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ1MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1MidGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ1MidGain,
         ui->EQ1MidGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ1MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1MidQ);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ1MidQ,
         ui->EQ1MidQBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ1HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1HighFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ1HighFreq,
         ui->EQ1HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ1HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1HighGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ1HighGain,
         ui->EQ1HighGainBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp2SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp2Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp2Switch,
         ui->Comp2SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->Comp2AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp2AttackTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp2AttackTime,
         ui->Comp2AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp2ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp2ReleaseTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp2ReleaseTime,
         ui->Comp2ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp2ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp2Threshold);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp2Threshold,
         ui->Comp2ThresholdBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp2RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp2Ratio);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp2Ratio,
         ui->Comp2RatioBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp2OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp2OutputGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp2OutputGain,
         ui->Comp2OutputGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ2SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ2Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ2Switch,
         ui->EQ2SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->EQ2LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2LowFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ2LowFreq,
         ui->EQ2LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ2LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2LowGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ2LowGain,
         ui->EQ2LowGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ2MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2MidFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ2MidFreq,
         ui->EQ2MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ2MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2MidGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ2MidGain,
         ui->EQ2MidGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ2MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2MidQ);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ2MidQ,
         ui->EQ2MidQBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ2HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2HighFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ2HighFreq,
         ui->EQ2HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ2HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2HighGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ2HighGain,
         ui->EQ2HighGainBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp3SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp3Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp3Switch,
         ui->Comp3SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->Comp3AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp3AttackTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp3AttackTime,
         ui->Comp3AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp3ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp3ReleaseTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp3ReleaseTime,
         ui->Comp3ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp3ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp3Threshold);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp3Threshold,
         ui->Comp3ThresholdBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp3RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp3Ratio);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp3Ratio,
         ui->Comp3RatioBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp3OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp3OutputGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp3OutputGain,
         ui->Comp3OutputGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ3SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ3Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ3Switch,
         ui->EQ3SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->EQ3LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3LowFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ3LowFreq,
         ui->EQ3LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ3LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3LowGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ3LowGain,
         ui->EQ3LowGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ3MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3MidFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ3MidFreq,
         ui->EQ3MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ3MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3MidGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ3MidGain,
         ui->EQ3MidGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ3MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3MidQ);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ3MidQ,
         ui->EQ3MidQBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ3HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3HighFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ3HighFreq,
         ui->EQ3HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ3HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3HighGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ3HighGain,
         ui->EQ3HighGainBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp4SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp4Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp4Switch,
         ui->Comp4SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->Comp4AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp4AttackTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp4AttackTime,
         ui->Comp4AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp4ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp4ReleaseTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp4ReleaseTime,
         ui->Comp4ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp4ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp4Threshold);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp4Threshold,
         ui->Comp4ThresholdBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp4RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp4Ratio);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp4Ratio,
         ui->Comp4RatioBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp4OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp4OutputGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp4OutputGain,
         ui->Comp4OutputGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ4SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ4Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ4Switch,
         ui->EQ4SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->EQ4LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4LowFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ4LowFreq,
         ui->EQ4LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ4LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4LowGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ4LowGain,
         ui->EQ4LowGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ4MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4MidFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ4MidFreq,
         ui->EQ4MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ4MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4MidGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ4MidGain,
         ui->EQ4MidGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ4MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4MidQ);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ4MidQ,
         ui->EQ4MidQBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ4HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4HighFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ4HighFreq,
         ui->EQ4HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ4HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4HighGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ4HighGain,
         ui->EQ4HighGainBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp5SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp5Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp5Switch,
         ui->Comp5SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->Comp5AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp5AttackTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp5AttackTime,
         ui->Comp5AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp5ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp5ReleaseTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp5ReleaseTime,
         ui->Comp5ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp5ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp5Threshold);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp5Threshold,
         ui->Comp5ThresholdBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp5RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp5Ratio);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp5Ratio,
         ui->Comp5RatioBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp5OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp5OutputGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp5OutputGain,
         ui->Comp5OutputGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ5SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ5Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ5Switch,
         ui->EQ5SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->EQ5LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5LowFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ5LowFreq,
         ui->EQ5LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ5LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5LowGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ5LowGain,
         ui->EQ5LowGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ5MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5MidFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ5MidFreq,
         ui->EQ5MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ5MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5MidGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ5MidGain,
         ui->EQ5MidGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ5MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5MidQ);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ5MidQ,
         ui->EQ5MidQBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ5HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5HighFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ5HighFreq,
         ui->EQ5HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ5HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5HighGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ5HighGain,
         ui->EQ5HighGainBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp6SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp6Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp6Switch,
         ui->Comp6SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->Comp6AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp6AttackTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp6AttackTime,
         ui->Comp6AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp6ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp6ReleaseTime);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp6ReleaseTime,
         ui->Comp6ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp6ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp6Threshold);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp6Threshold,
         ui->Comp6ThresholdBox,&QSpinBox::setValue);

    QObject::connect(ui->Comp6RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp6Ratio);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp6Ratio,
         ui->Comp6RatioBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->Comp6OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp6OutputGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::Comp6OutputGain,
         ui->Comp6OutputGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ6SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ6Switch);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ6Switch,
         ui->EQ6SwitchBtn,&QPushButton::setChecked);

    QObject::connect(ui->EQ6LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6LowFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ6LowFreq,
         ui->EQ6LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ6LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6LowGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ6LowGain,
         ui->EQ6LowGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ6MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6MidFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ6MidFreq,
         ui->EQ6MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ6MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6MidGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ6MidGain,
         ui->EQ6MidGainBox,&QSpinBox::setValue);

    QObject::connect(ui->EQ6MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6MidQ);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ6MidQ,
         ui->EQ6MidQBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ6HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6HighFreq);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ6HighFreq,
         ui->EQ6HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::connect(ui->EQ6HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6HighGain);

    QObject::connect(compeqd,&Integra7DrumCompEQ::EQ6HighGain,
         ui->EQ6HighGainBox,&QSpinBox::setValue);
}

void integra7MainWindow::DisconnectDrumCompEQ(Integra7DrumCompEQ *compeqd)
{
    if (compeqd == NULL) return;

    QObject::disconnect(ui->Comp1SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp1Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp1Switch,
         ui->Comp1SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Comp1AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp1AttackTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp1AttackTime,
         ui->Comp1AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp1ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp1ReleaseTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp1ReleaseTime,
         ui->Comp1ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp1ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp1Threshold);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp1Threshold,
         ui->Comp1ThresholdBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp1RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp1Ratio);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp1Ratio,
         ui->Comp1RatioBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp1OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp1OutputGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp1OutputGain,
         ui->Comp1OutputGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ1SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ1Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ1Switch,
         ui->EQ1SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->EQ1LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1LowFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ1LowFreq,
         ui->EQ1LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ1LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1LowGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ1LowGain,
         ui->EQ1LowGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ1MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1MidFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ1MidFreq,
         ui->EQ1MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ1MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1MidGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ1MidGain,
         ui->EQ1MidGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ1MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1MidQ);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ1MidQ,
         ui->EQ1MidQBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ1HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1HighFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ1HighFreq,
         ui->EQ1HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ1HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ1HighGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ1HighGain,
         ui->EQ1HighGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp2SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp2Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp2Switch,
         ui->Comp2SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Comp2AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp2AttackTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp2AttackTime,
         ui->Comp2AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp2ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp2ReleaseTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp2ReleaseTime,
         ui->Comp2ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp2ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp2Threshold);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp2Threshold,
         ui->Comp2ThresholdBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp2RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp2Ratio);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp2Ratio,
         ui->Comp2RatioBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp2OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp2OutputGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp2OutputGain,
         ui->Comp2OutputGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ2SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ2Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ2Switch,
         ui->EQ2SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->EQ2LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2LowFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ2LowFreq,
         ui->EQ2LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ2LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2LowGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ2LowGain,
         ui->EQ2LowGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ2MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2MidFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ2MidFreq,
         ui->EQ2MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ2MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2MidGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ2MidGain,
         ui->EQ2MidGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ2MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2MidQ);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ2MidQ,
         ui->EQ2MidQBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ2HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2HighFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ2HighFreq,
         ui->EQ2HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ2HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ2HighGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ2HighGain,
         ui->EQ2HighGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp3SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp3Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp3Switch,
         ui->Comp3SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Comp3AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp3AttackTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp3AttackTime,
         ui->Comp3AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp3ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp3ReleaseTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp3ReleaseTime,
         ui->Comp3ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp3ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp3Threshold);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp3Threshold,
         ui->Comp3ThresholdBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp3RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp3Ratio);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp3Ratio,
         ui->Comp3RatioBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp3OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp3OutputGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp3OutputGain,
         ui->Comp3OutputGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ3SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ3Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ3Switch,
         ui->EQ3SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->EQ3LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3LowFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ3LowFreq,
         ui->EQ3LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ3LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3LowGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ3LowGain,
         ui->EQ3LowGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ3MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3MidFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ3MidFreq,
         ui->EQ3MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ3MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3MidGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ3MidGain,
         ui->EQ3MidGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ3MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3MidQ);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ3MidQ,
         ui->EQ3MidQBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ3HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3HighFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ3HighFreq,
         ui->EQ3HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ3HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ3HighGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ3HighGain,
         ui->EQ3HighGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp4SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp4Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp4Switch,
         ui->Comp4SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Comp4AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp4AttackTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp4AttackTime,
         ui->Comp4AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp4ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp4ReleaseTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp4ReleaseTime,
         ui->Comp4ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp4ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp4Threshold);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp4Threshold,
         ui->Comp4ThresholdBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp4RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp4Ratio);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp4Ratio,
         ui->Comp4RatioBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp4OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp4OutputGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp4OutputGain,
         ui->Comp4OutputGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ4SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ4Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ4Switch,
         ui->EQ4SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->EQ4LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4LowFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ4LowFreq,
         ui->EQ4LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ4LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4LowGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ4LowGain,
         ui->EQ4LowGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ4MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4MidFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ4MidFreq,
         ui->EQ4MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ4MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4MidGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ4MidGain,
         ui->EQ4MidGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ4MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4MidQ);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ4MidQ,
         ui->EQ4MidQBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ4HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4HighFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ4HighFreq,
         ui->EQ4HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ4HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ4HighGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ4HighGain,
         ui->EQ4HighGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp5SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp5Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp5Switch,
         ui->Comp5SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Comp5AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp5AttackTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp5AttackTime,
         ui->Comp5AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp5ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp5ReleaseTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp5ReleaseTime,
         ui->Comp5ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp5ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp5Threshold);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp5Threshold,
         ui->Comp5ThresholdBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp5RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp5Ratio);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp5Ratio,
         ui->Comp5RatioBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp5OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp5OutputGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp5OutputGain,
         ui->Comp5OutputGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ5SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ5Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ5Switch,
         ui->EQ5SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->EQ5LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5LowFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ5LowFreq,
         ui->EQ5LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ5LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5LowGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ5LowGain,
         ui->EQ5LowGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ5MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5MidFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ5MidFreq,
         ui->EQ5MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ5MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5MidGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ5MidGain,
         ui->EQ5MidGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ5MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5MidQ);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ5MidQ,
         ui->EQ5MidQBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ5HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5HighFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ5HighFreq,
         ui->EQ5HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ5HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ5HighGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ5HighGain,
         ui->EQ5HighGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp6SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setComp6Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp6Switch,
         ui->Comp6SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->Comp6AttackTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp6AttackTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp6AttackTime,
         ui->Comp6AttackTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp6ReleaseTimeBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp6ReleaseTime);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp6ReleaseTime,
         ui->Comp6ReleaseTimeBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp6ThresholdBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp6Threshold);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp6Threshold,
         ui->Comp6ThresholdBox,&QSpinBox::setValue);

    QObject::disconnect(ui->Comp6RatioBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setComp6Ratio);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp6Ratio,
         ui->Comp6RatioBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->Comp6OutputGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setComp6OutputGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::Comp6OutputGain,
         ui->Comp6OutputGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ6SwitchBtn,&QPushButton::toggled,
         compeqd,&Integra7DrumCompEQ::setEQ6Switch);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ6Switch,
         ui->EQ6SwitchBtn,&QPushButton::setChecked);

    QObject::disconnect(ui->EQ6LowFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6LowFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ6LowFreq,
         ui->EQ6LowFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ6LowGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6LowGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ6LowGain,
         ui->EQ6LowGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ6MidFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6MidFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ6MidFreq,
         ui->EQ6MidFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ6MidGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6MidGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ6MidGain,
         ui->EQ6MidGainBox,&QSpinBox::setValue);

    QObject::disconnect(ui->EQ6MidQBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6MidQ);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ6MidQ,
         ui->EQ6MidQBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ6HighFreqBox,&QComboBox::currentIndexChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6HighFreq);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ6HighFreq,
         ui->EQ6HighFreqBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(ui->EQ6HighGainBox,&QSpinBox::valueChanged,
         compeqd,&Integra7DrumCompEQ::setEQ6HighGain);

    QObject::disconnect(compeqd,&Integra7DrumCompEQ::EQ6HighGain,
         ui->EQ6HighGainBox,&QSpinBox::setValue);
}
