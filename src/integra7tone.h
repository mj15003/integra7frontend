/*************************************************************************
   Copyright (C) 2024 Miroslav Kovac

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

#ifndef INTEGRA7TONE_H
#define INTEGRA7TONE_H

#include "integra7device.h"
#include "integra7pcmsynthtonecommon.h"
#include "integra7pcmsynthtonepmt.h"
#include "integra7pcmsynthtonepartial.h"
#include "integra7pcmsynthtonecommon2.h"
#include "integra7pcmdrumkitcommon.h"
#include "integra7drumcompeq.h"
#include "integra7pcmdrumkitpartial.h"
#include "integra7pcmdrumkitcommon2.h"
#include "integra7snsynthtonecommon.h"
#include "integra7snsynthtonepartial.h"
#include "integra7snacoustictonecommon.h"
#include "integra7sndrumkitcommon.h"
#include "integra7sndrumkitnote.h"
#include "integra7tonemfx.h"

class Integra7Tone : public QObject
{
    Q_OBJECT
public:
    Integra7Tone(Integra7Device *parent,uint8_t a0, uint8_t a1);
    ~Integra7Tone();

    QString ToneType = "GS";

    Integra7PCMSynthToneCommon *PCMSynthToneCommon;
    Integra7ToneMFX *PCMSynthToneCommonMFX;
    Integra7PCMSynthTonePMT *PCMSynthTonePMT;
    Integra7PCMSynthTonePartial *PCMSynthTonePartial[4];
    Integra7PCMSynthToneCommon2 *PCMSynthToneCommon2;

    Integra7PCMDrumKitCommon *PCMDrumKitCommon;
    Integra7ToneMFX *PCMDrumKitCommonMFX;
    Integra7DrumCompEQ *PCMDrumKitCommonCompEQ;
    Integra7PCMDrumKitPartial *PCMDrumKitPartial[88];
    Integra7PCMDrumKitCommon2 *PCMDrumKitCommon2;

    Integra7SNSynthToneCommon *SNSynthToneCommon;
    Integra7ToneMFX *SNSynthToneCommonMFX;
    Integra7SNSynthTonePartial *SNSynthTonePartial[3];

    Integra7SNAcousticToneCommon *SNAcousticToneCommon;
    Integra7ToneMFX *SNAcousticToneMFX;

    Integra7SNDrumKitCommon *SNDrumKitCommon;
    Integra7ToneMFX *SNDrumKitMFX;
    Integra7DrumCompEQ *SNDrumKitCommonCompEQ;
    Integra7SNDrumKitNote *SNDrumKitNote[62];

    void ReceiveData(const uint8_t *rdata, int len);
    int OutputDump(uint8_t *data,int *len);
    void TriggerSignals(const QString &type, int drumnote);
    void RequestData();

public slots:
    void setToneType(const QString &ts);

private:
    uint8_t address[2];
    Integra7Device *pIntegraDev;
    int outcnt = 0;

};

#endif // INTEGRA7TONE_H
