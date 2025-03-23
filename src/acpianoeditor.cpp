#include "acpianoeditor.h"
#include "ui_acpianoeditor.h"

AcPianoEditor::AcPianoEditor(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::AcPianoEditor)
{
    ui->setupUi(this);

    ui->NuanceBox->addItems(Integra7SNAcousticToneCommon::AcPianoNuanceList());    
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
                     snat,&Integra7SNAcousticToneCommon::setAcPianoStringResonance);

    QObject::connect(ui->KeyOffResonanceBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setAcPianoKeyOffResonance);

    QObject::connect(ui->HammerNoiseBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setAcPianoHammerNoise);

    QObject::connect(ui->StereoWidthBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setAcPianoStereoWidth);

    QObject::connect(ui->NuanceBox,&QComboBox::currentIndexChanged,
                     snat,&Integra7SNAcousticToneCommon::setAcPianoNuance);

    QObject::connect(ui->ToneCharacterBox,&QSpinBox::valueChanged,
                     snat,&Integra7SNAcousticToneCommon::setAcPianoToneCharacter);

    /* Reverse Connections*/

    QObject::connect(snat,&Integra7SNAcousticToneCommon::AcPianoStringResonance,
                     ui->StringResonanceBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::AcPianoKeyOffResonance,
                     ui->KeyOffResonanceBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::AcPianoHammerNoise,
                     ui->HammerNoiseBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::AcPianoStereoWidth,
                     ui->StereoWidthBox,&QSpinBox::setValue);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::AcPianoNuance,
                     ui->NuanceBox,&QComboBox::setCurrentIndex);

    QObject::connect(snat,&Integra7SNAcousticToneCommon::AcPianoToneCharacter,
                     ui->ToneCharacterBox,&QSpinBox::setValue);
}

void AcPianoEditor::DisconnectSignals(Integra7Tone *tone)
{
    if (tone == NULL) return;

    Integra7SNAcousticToneCommon *snat = tone->SNAcousticToneCommon;

    QObject::disconnect(ui->StringResonanceBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setAcPianoStringResonance);

    QObject::disconnect(ui->KeyOffResonanceBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setAcPianoKeyOffResonance);

    QObject::disconnect(ui->HammerNoiseBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setAcPianoHammerNoise);

    QObject::disconnect(ui->StereoWidthBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setAcPianoStereoWidth);

    QObject::disconnect(ui->NuanceBox,&QComboBox::currentIndexChanged,
                        snat,&Integra7SNAcousticToneCommon::setAcPianoNuance);

    QObject::disconnect(ui->ToneCharacterBox,&QSpinBox::valueChanged,
                        snat,&Integra7SNAcousticToneCommon::setAcPianoToneCharacter);

    /* Reverse Connections*/

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::AcPianoStringResonance,
                        ui->StringResonanceBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::AcPianoKeyOffResonance,
                        ui->KeyOffResonanceBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::AcPianoHammerNoise,
                        ui->HammerNoiseBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::AcPianoStereoWidth,
                        ui->StereoWidthBox,&QSpinBox::setValue);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::AcPianoNuance,
                        ui->NuanceBox,&QComboBox::setCurrentIndex);

    QObject::disconnect(snat,&Integra7SNAcousticToneCommon::AcPianoToneCharacter,
                        ui->ToneCharacterBox,&QSpinBox::setValue);
}
