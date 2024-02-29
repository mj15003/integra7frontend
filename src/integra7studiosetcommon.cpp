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

#include "integra7studiosetcommon.h"

Integra7StudioSetCommon::Integra7StudioSetCommon(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}
{

}

QLatin1StringView Integra7StudioSetCommon::getStudioSetName()
{
    return QLatin1StringView((char*)&data[0],(char*)&data[0x0F]);
}

void Integra7StudioSetCommon::setStudioSetName(const QString name)
{
    uint8_t c = 0;
    while (c < name.length() && c < 16){
        data[c] = name.at(c).toLatin1();
        c++;
    }
}

void Integra7StudioSetCommon::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x18:
        emit VoiceReserve1(v);
        break;
    case 0x19:
        emit VoiceReserve2(v);
        break;
    case 0x1A:
        emit VoiceReserve3(v);
        break;
    case 0x1B:
        emit VoiceReserve4(v);
        break;
    case 0x1C:
        emit VoiceReserve5(v);
        break;
    case 0x1D:
        emit VoiceReserve6(v);
        break;
    case 0x1E:
        emit VoiceReserve7(v);
        break;
    case 0x1F:
        emit VoiceReserve8(v);
        break;
    case 0x20:
        emit VoiceReserve9(v);
        break;
    case 0x21:
        emit VoiceReserve10(v);
        break;
    case 0x22:
        emit VoiceReserve11(v);
        break;
    case 0x23:
        emit VoiceReserve12(v);
        break;
    case 0x24:
        emit VoiceReserve13(v);
        break;
    case 0x25:
        emit VoiceReserve14(v);
        break;
    case 0x26:
        emit VoiceReserve15(v);
        break;
    case 0x27:
        emit VoiceReserve16(v);
        break;
    case 0x39:
        emit ToneControl1Source(v);
        break;
    case 0x3A:
        emit ToneControl2Source(v);
        break;
    case 0x3B:
        emit ToneControl3Source(v);
        break;
    case 0x3C:
        emit ToneControl4Source(v);
        break;
    case 0x3D:
        emit StudioSetTempo(v);
        break;
    case 0x3F:
        emit SoloPart(v);
        break;
    case 0x40:
        emit ReverbSwitch(v);
        break;
    case 0x41:
        emit ChorusSwitch(v);
        break;
    case 0x42:
        emit MasterEQSwitch(v);
        break;
    case 0x43:
        emit DrumCompEQSwitch(v);
        break;
    case 0x44:
        emit DrumCompEQPart(v);
        break;
    case 0x45:
        emit DrumCompEQ1OutputAssign(v);
        break;
    case 0x46:
        emit DrumCompEQ2OutputAssign(v);
        break;
    case 0x47:
        emit DrumCompEQ3OutputAssign(v);
        break;
    case 0x48:
        emit DrumCompEQ4OutputAssign(v);
        break;
    case 0x49:
        emit DrumCompEQ5OutputAssign(v);
        break;
    case 0x4A:
        emit DrumCompEQ6OutputAssign(v);
        break;
    case 0x4C:
        emit ExtPartLevel(v);
        break;
    case 0x4D:
        emit ExtPartChorusSendLevel(v);
        break;
    case 0x4E:
        emit ExtPartReverbSendLevel(v);
        break;
    case 0x4F:
        emit ExtPartMuteSwitch(v);
        break;
    default:
        break;
    }
}
