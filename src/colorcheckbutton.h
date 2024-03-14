#ifndef COLORCHECKBUTTON_H
#define COLORCHECKBUTTON_H

#include <QPushButton>

class ColorCheckButton : public QPushButton
{
public:
    ColorCheckButton(QWidget *parent = nullptr);

public slots:
    void toggle(bool checked);

protected:
    QPalette OnBtnPalette;
    QPalette OffBtnPalette;

};

#endif // COLORCHECKBUTTON_H
