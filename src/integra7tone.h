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
#include "integra7pcmsynthtonecommonmfx.h"
#include "integra7pcmsynthtonepmt.h"
#include "integra7pcmsynthtonepartial.h"
#include "integra7pcmsynthtonecommon2.h"
#include "integra7pcmdrumkitcommon.h"
#include "integra7pcmdrumkitcommonmfx.h"
#include "integra7pcmdrumkitcommoncompeq.h"
#include "integra7pcmdrumkitpartial.h"
#include "integra7pcmdrumkitcommon2.h"
#include "integra7snsynthtonecommon.h"
#include "integra7snsynthtonemfx.h"
#include "integra7snsynthtonepartial.h"
#include "integra7snacoustictonecommon.h"
#include "integra7snacoustictonemfx.h"
#include "integra7sndrumkitcommon.h"
#include "integra7sndrumkitmfx.h"
#include "integra7sndrumkitcommoncompeq.h"
#include "integra7sndrumkitnote.h"

class Integra7Tone
{
public:
    Integra7Tone(Integra7Device *parent,uint8_t a0, uint8_t a1);
    ~Integra7Tone();

    Integra7PCMSynthToneCommon *PCMSynthToneCommon;
    Integra7PCMSynthToneCommonMFX *PCMSynthToneCommonMFX;
    Integra7PCMSynthTonePMT *PCMSynthTonePMT;
    Integra7PCMSynthTonePartial *PCMSynthTonePartial[4];
    Integra7PCMSynthToneCommon2 *PCMSynthToneCommon2;

    Integra7PCMDrumKitCommon *PCMDrumKitCommon;
    Integra7PCMDrumKitCommonMFX *PCMDrumKitCommonMFX;
    Integra7PCMDrumKitCommonCompEQ *PCMDrumKitCommonCompEQ;
    Integra7PCMDrumKitPartial *PCMDrumKitPartial[88];
    Integra7PCMDrumKitCommon2 *PCMDrumKitCommon2;

    Integra7SNSynthToneCommon *SNSynthToneCommon;
    Integra7SNSynthToneMFX *SNSynthToneMFX;
    Integra7SNSynthTonePartial *SNSynthTonePartial[3];

    Integra7SNAcousticToneCommon *SNAcousticToneCommon;
    Integra7SNAcousticToneMFX *SNAcousticToneMFX;

    Integra7SNDrumKitCommon *SNDrumKitCommon;
    Integra7SNDrumKitMFX *SNDrumKitMFX;
    Integra7SNDrumKitCommonCompEQ *SNDrumKitCommonCompEQ;
    Integra7SNDrumKitNote *SNDrumKitNote[62];

    void ReceiveData(const uint8_t *rdata, int len);

private:
    uint8_t address[2];
    Integra7Device *pIntegraDev;

};

#endif // INTEGRA7TONE_H
