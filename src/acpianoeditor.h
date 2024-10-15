#ifndef ACPIANOEDITOR_H
#define ACPIANOEDITOR_H

#include <QFrame>
#include <integra7tone.h>

namespace Ui {
class AcPianoEditor;
}

class AcPianoEditor : public QFrame
{
    Q_OBJECT

public:
    explicit AcPianoEditor(QWidget *parent = nullptr);
    ~AcPianoEditor();

    void ConnectSignals(Integra7Tone *tone);
    void DisconnectSignals(Integra7Tone *tone);

private:
    Ui::AcPianoEditor *ui;
};

#endif // ACPIANOEDITOR_H
