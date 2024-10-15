#include "acpianoeditor.h"
#include "ui_acpianoeditor.h"

AcPianoEditor::AcPianoEditor(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::AcPianoEditor)
{
    ui->setupUi(this);

    ui->HammerNoiseBox->addItems(Integra7SNAcousticToneCommon::AcPianoHammerNoiseList());
    ui->NuanceBox->addItems(Integra7SNAcousticToneCommon::AcPianoNuanceList());
    ui->ToneCharacterBox->addItems(Integra7SNAcousticToneCommon::AcPianoToneCharacterList());
}

AcPianoEditor::~AcPianoEditor()
{
    delete ui;
}

void AcPianoEditor::ConnectSignals(Integra7Tone *tone)
{
    if (tone == NULL) return;

    Integra7SNAcousticToneCommon *snat = tone->SNAcousticToneCommon;

    QObject::connect(ui->StringResonanceBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter1);

    QObject::connect(ui->KeyOffResonanceBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter2);

    QObject::connect(ui->HammerNoiseBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter3);

    QObject::connect(ui->StereoWidthBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter4);

    QObject::connect(ui->NuanceBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter5);

    QObject::connect(ui->ToneCharacterBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setModifyParameter6);

    /* Reverse Connections*/

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter1,
                     ui->StringResonanceBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter2,
                     ui->KeyOffResonanceBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter3,
                     ui->HammerNoiseBox,&QComboBox::setCurrentIndex);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter4,
                     ui->StereoWidthBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter5,
                     ui->NuanceBox,&QComboBox::setCurrentIndex);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::ModifyParameter6,
                     ui->ToneCharacterBox,&QComboBox::setCurrentIndex);
}

void AcPianoEditor::DisconnectSignals(Integra7Tone *tone)
{
    if (tone == NULL) return;

    Integra7SNAcousticToneCommon *snat = tone->SNAcousticToneCommon;

    QObject::disconnect(ui->StringResonanceBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter1);

    QObject::disconnect(ui->KeyOffResonanceBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter2);

    QObject::disconnect(ui->HammerNoiseBox,&QComboBox::currentIndexChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter3);

    QObject::disconnect(ui->StereoWidthBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter4);

    QObject::disconnect(ui->NuanceBox,&QComboBox::currentIndexChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter5);

    QObject::disconnect(ui->ToneCharacterBox,&QComboBox::currentIndexChanged,
                        snat,&Integra7SNAcousticToneCommon::setModifyParameter6);

    /* Reverse Connections*/

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter1,
                        ui->StringResonanceBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter2,
                        ui->KeyOffResonanceBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter3,
                        ui->HammerNoiseBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter4,
                        ui->StereoWidthBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter5,
                        ui->NuanceBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::ModifyParameter6,
                        ui->ToneCharacterBox,&QComboBox::setCurrentIndex);
}
