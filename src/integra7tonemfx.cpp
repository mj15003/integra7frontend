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
:Integra7ParameterSet{parent,o1,o2,o3}
{
    /* Put correct initialization value into certain fields which does not allow zero */
    data[0x00] = 0;
    data[0x02] = 0;
    data[0x03] = 0;
    data[0x05] = 0;
    data[0x06] = 64;
    data[0x07] = 0;
    data[0x08] = 64;
    data[0x09] = 0;
    data[0x0A] = 64;
    data[0x0B] = 0;
    data[0x0C] = 64;
    data[0x0D] = 0;
    data[0x0E] = 0;
    data[0x0F] = 0;
    data[0x10] = 0;
    data[0x11] = 8;
    data[0x12] = 0;
    data[0x13] = 0;
    data[0x14] = 0;
    data[0x15] = 8;
    data[0x16] = 0;
    data[0x17] = 0;
    data[0x18] = 0;
    data[0x19] = 8;
    data[0x1A] = 0;
    data[0x1B] = 0;
    data[0x1C] = 0;
    data[0x1D] = 8;
    data[0x1E] = 0;
    data[0x1F] = 0;
    data[0x20] = 0;
    data[0x21] = 8;
    data[0x22] = 0;
    data[0x23] = 0;
    data[0x24] = 0;
    data[0x25] = 8;
    data[0x26] = 0;
    data[0x27] = 0;
    data[0x28] = 0;
    data[0x29] = 8;
    data[0x2A] = 0;
    data[0x2B] = 0;
    data[0x2C] = 0;
    data[0x2D] = 8;
    data[0x2E] = 0;
    data[0x2F] = 0;
    data[0x30] = 0;
    data[0x31] = 8;
    data[0x32] = 0;
    data[0x33] = 0;
    data[0x34] = 0;
    data[0x35] = 8;
    data[0x36] = 0;
    data[0x37] = 0;
    data[0x38] = 0;
    data[0x39] = 8;
    data[0x3A] = 0;
    data[0x3B] = 0;
    data[0x3C] = 0;
    data[0x3D] = 8;
    data[0x3E] = 0;
    data[0x3F] = 0;
    data[0x40] = 0;
    data[0x41] = 8;
    data[0x42] = 0;
    data[0x43] = 0;
    data[0x44] = 0;
    data[0x45] = 8;
    data[0x46] = 0;
    data[0x47] = 0;
    data[0x48] = 0;
    data[0x49] = 8;
    data[0x4A] = 0;
    data[0x4B] = 0;
    data[0x4C] = 0;
    data[0x4D] = 8;
    data[0x4E] = 0;
    data[0x4F] = 0;
    data[0x50] = 0;
    data[0x51] = 8;
    data[0x52] = 0;
    data[0x53] = 0;
    data[0x54] = 0;
    data[0x55] = 8;
    data[0x56] = 0;
    data[0x57] = 0;
    data[0x58] = 0;
    data[0x59] = 8;
    data[0x5A] = 0;
    data[0x5B] = 0;
    data[0x5C] = 0;
    data[0x5D] = 8;
    data[0x5E] = 0;
    data[0x5F] = 0;
    data[0x60] = 0;
    data[0x61] = 8;
    data[0x62] = 0;
    data[0x63] = 0;
    data[0x64] = 0;
    data[0x65] = 8;
    data[0x66] = 0;
    data[0x67] = 0;
    data[0x68] = 0;
    data[0x69] = 8;
    data[0x6A] = 0;
    data[0x6B] = 0;
    data[0x6C] = 0;
    data[0x6D] = 8;
    data[0x6E] = 0;
    data[0x6F] = 0;
    data[0x70] = 0;
    data[0x71] = 8;
    data[0x72] = 0;
    data[0x73] = 0;
    data[0x74] = 0;
    data[0x75] = 8;
    data[0x76] = 0;
    data[0x77] = 0;
    data[0x78] = 0;
    data[0x79] = 8;
    data[0x7A] = 0;
    data[0x7B] = 0;
    data[0x7C] = 0;
    data[0x7D] = 8;
    data[0x7E] = 0;
    data[0x7F] = 0;
    data[0x80] = 0;
    data[0x81] = 8;
    data[0x82] = 0;
    data[0x83] = 0;
    data[0x84] = 0;
    data[0x85] = 8;
    data[0x86] = 0;
    data[0x87] = 0;
    data[0x88] = 0;
    data[0x89] = 8;
    data[0x8A] = 0;
    data[0x8B] = 0;
    data[0x8C] = 0;
    data[0x8D] = 8;
    data[0x8E] = 0;
    data[0x8F] = 0;
    data[0x90] = 0;
}

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
        emit MFXControl1Sens(getMFXControl1Sens());
        break;
    case 0x07:
        emit MFXControl2Source(v);
        break;
    case 0x08:
        emit MFXControl2Sens(getMFXControl2Sens());
        break;
    case 0x09:
        emit MFXControl3Source(v);
        break;
    case 0x0A:
        emit MFXControl3Sens(getMFXControl3Sens());
        break;
    case 0x0B:
        emit MFXControl4Source(v);
        break;
    case 0x0C:
        emit MFXControl4Sens(getMFXControl4Sens());
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
        if (a == 0x11) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x11,getMFXParameter1());
        } else if (a == 0x15) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x15,getMFXParameter2());
        } else if (a == 0x19) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x19,getMFXParameter3());
        } else if (a == 0x1D) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x1D,getMFXParameter4());
        } else if (a == 0x21) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x21,getMFXParameter5());
        } else if (a == 0x25) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x25,getMFXParameter6());
        } else if (a == 0x29) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x29,getMFXParameter7());
        } else if (a == 0x2D) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x2D,getMFXParameter8());
        } else if (a == 0x31) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x31,getMFXParameter9());
        } else if (a == 0x35) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x35,getMFXParameter10());
        } else if (a == 0x39) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x39,getMFXParameter11());
        } else if (a == 0x3D) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x3D,getMFXParameter12());
        } else if (a == 0x41) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x41,getMFXParameter13());
        } else if (a == 0x45) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x45,getMFXParameter14());
        } else if (a == 0x49) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x49,getMFXParameter15());
        } else if (a == 0x4D) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x4D,getMFXParameter16());
        } else if (a == 0x51) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x51,getMFXParameter17());
        } else if (a == 0x55) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x55,getMFXParameter18());
        } else if (a == 0x59) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x59,getMFXParameter19());
        } else if (a == 0x5D) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x5D,getMFXParameter20());
        } else if (a == 0x61) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x61,getMFXParameter21());
        } else if (a == 0x65) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x65,getMFXParameter22());
        } else if (a == 0x69) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x69,getMFXParameter23());
        } else if (a == 0x6D) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x6D,getMFXParameter24());
        } else if (a == 0x71) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x71,getMFXParameter25());
        } else if (a == 0x75) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x75,getMFXParameter26());
        } else if (a == 0x79) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x79,getMFXParameter27());
        } else if (a == 0x7D) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x7D,getMFXParameter28());
        } else if (a == 0x81) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x81,getMFXParameter29());
        } else if (a == 0x85) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x85,getMFXParameter30());
        } else if (a == 0x89) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x89,getMFXParameter31());
        } else if (a == 0x8D) {
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            data[a++] = rdata[r++];
            EmitSignal(0x8D,getMFXParameter32());
        } else {
            data[a] = rdata[r++];
            EmitSignal(a,data[a]);
            ++a;
        }
    }
}
