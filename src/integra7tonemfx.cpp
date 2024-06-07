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

#include "integra7tonemfx.h"

Integra7ToneMFX::Integra7ToneMFX(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
:Integra7ParameterSet{parent,o1,o2,o3}{}

void Integra7ToneMFX::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit MFXType(v);
        break;
    case 0x02:
        emit MFXChorusSendLevel(v);
        break;
    case 0x03:
        emit MFXReverbSendLevel(v);
        break;
    case 0x05:
        emit MFXControl1Source(v);
        break;
    case 0x06:
        emit MFXControl1Sens(v);
        break;
    case 0x07:
        emit MFXControl2Source(v);
        break;
    case 0x08:
        emit MFXControl2Sens(v);
        break;
    case 0x09:
        emit MFXControl3Source(v);
        break;
    case 0x0A:
        emit MFXControl3Sens(v);
        break;
    case 0x0B:
        emit MFXControl4Source(v);
        break;
    case 0x0C:
        emit MFXControl4Sens(v);
        break;
    case 0x0D:
        emit MFXControlAssign1(v);
        break;
    case 0x0E:
        emit MFXControlAssign2(v);
        break;
    case 0x0F:
        emit MFXControlAssign3(v);
        break;
    case 0x10:
        emit MFXControlAssign4(v);
        break;
    case 0x11:
        emit MFXParameter1(getMFXParameter1());
        break;
    case 0x15:
        emit MFXParameter2(getMFXParameter2());
        break;
    case 0x19:
        emit MFXParameter3(getMFXParameter3());
        break;
    case 0x1D:
        emit MFXParameter4(getMFXParameter4());
        break;
    case 0x21:
        emit MFXParameter5(getMFXParameter5());
        break;
    case 0x25:
        emit MFXParameter6(getMFXParameter6());
        break;
    case 0x29:
        emit MFXParameter7(getMFXParameter7());
        break;
    case 0x2D:
        emit MFXParameter8(getMFXParameter8());
        break;
    case 0x31:
        emit MFXParameter9(getMFXParameter9());
        break;
    case 0x35:
        emit MFXParameter10(getMFXParameter10());
        break;
    case 0x39:
        emit MFXParameter11(getMFXParameter11());
        break;
    case 0x3D:
        emit MFXParameter12(getMFXParameter12());
        break;
    case 0x41:
        emit MFXParameter13(getMFXParameter13());
        break;
    case 0x45:
        emit MFXParameter14(getMFXParameter14());
        break;
    case 0x49:
        emit MFXParameter15(getMFXParameter15());
        break;
    case 0x4D:
        emit MFXParameter16(getMFXParameter16());
        break;
    case 0x51:
        emit MFXParameter17(getMFXParameter17());
        break;
    case 0x55:
        emit MFXParameter18(getMFXParameter18());
        break;
    case 0x59:
        emit MFXParameter19(getMFXParameter19());
        break;
    case 0x5D:
        emit MFXParameter20(getMFXParameter20());
        break;
    case 0x61:
        emit MFXParameter21(getMFXParameter21());
        break;
    case 0x65:
        emit MFXParameter22(getMFXParameter22());
        break;
    case 0x69:
        emit MFXParameter23(getMFXParameter23());
        break;
    case 0x6D:
        emit MFXParameter24(getMFXParameter24());
        break;
    case 0x71:
        emit MFXParameter25(getMFXParameter25());
        break;
    case 0x75:
        emit MFXParameter26(getMFXParameter26());
        break;
    case 0x79:
        emit MFXParameter27(getMFXParameter27());
        break;
    case 0x7D:
        emit MFXParameter28(getMFXParameter28());
        break;
    case 0x81:
        emit MFXParameter29(getMFXParameter29());
        break;
    case 0x85:
        emit MFXParameter30(getMFXParameter30());
        break;
    case 0x89:
        emit MFXParameter31(getMFXParameter31());
        break;
    case 0x8D:
        emit MFXParameter32(getMFXParameter32());
        break;
    default:
        break;
    }
}

void Integra7ToneMFX::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        data[a] = rdata[r++];
        EmitSignal(a,data[a]);
        ++a;
    }
}
