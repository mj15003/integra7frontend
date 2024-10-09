#include "integra7pcmsynthtonepmt.h"

Integra7PCMSynthTonePMT::Integra7PCMSynthTonePMT(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}
{
    data[0x00] = 0;
    data[0x01] = 0;
    data[0x02] = 0;
    data[0x03] = 0;
    data[0x04] = 0;
    data[0x05] = 0;
    data[0x06] = 0;
    data[0x07] = 0;
    data[0x08] = 0;
    data[0x09] = 0;
    data[0x0A] = 64;
    data[0x0B] = 64;
    data[0x0C] = 0;
    data[0x0D] = 0;
    data[0x0E] = 0;
    data[0x0F] = 0;
    data[0x10] = 0;
    data[0x11] = 0;
    data[0x12] = 0;
    data[0x13] = 64;
    data[0x14] = 64;
    data[0x15] = 0;
    data[0x16] = 0;
    data[0x17] = 0;
    data[0x18] = 0;
    data[0x19] = 0;
    data[0x1A] = 0;
    data[0x1B] = 0;
    data[0x1C] = 64;
    data[0x1D] = 64;
    data[0x1E] = 0;
    data[0x1F] = 0;
    data[0x20] = 0;
    data[0x21] = 0;
    data[0x22] = 0;
    data[0x23] = 0;
    data[0x24] = 0;
    data[0x25] = 64;
    data[0x26] = 64;
    data[0x27] = 0;
    data[0x28] = 0;
}

void Integra7PCMSynthTonePMT::EmitSignal(uint8_t a, int v)
{
    switch (a) {
    case 0x00:
        emit StructureType12(v);
        break;
    case 0x01:
        emit Booster12(v);
        break;
    case 0x02:
        emit StructureType34(v);
        break;
    case 0x03:
        emit Booster34(v);
        break;
    case 0x04:
        emit PMTVelocityControl(v);
        break;
    case 0x05:
        emit PMT1PartialSwitch(v);
        break;
    case 0x06:
        emit PMT1KeyboardRangeLower(v);
        break;
    case 0x07:
        emit PMT1KeyboardRangeUpper(v);
        break;
    case 0x08:
        emit PMT1KeyboardFadeWidthLower(v);
        break;
    case 0x09:
        emit PMT1KeyboardFadeWidthUpper(v);
        break;
    case 0x0A:
        emit PMT1VelocityRangeLower(v);
        break;
    case 0x0B:
        emit PMT1VelocityRangeUpper(v);
        break;
    case 0x0C:
        emit PMT1VelocityFadeWidthLower(v);
        break;
    case 0x0D:
        emit PMT1VelocityFadeWidthUpper(v);
        break;
    case 0x0E:
        emit PMT2PartialSwitch(v);
        break;
    case 0x0F:
        emit PMT2KeyboardRangeLower(v);
        break;
    case 0x10:
        emit PMT2KeyboardRangeUpper(v);
        break;
    case 0x11:
        emit PMT2KeyboardFadeWidthLower(v);
        break;
    case 0x12:
        emit PMT2KeyboardFadeWidthUpper(v);
        break;
    case 0x13:
        emit PMT2VelocityRangeLower(v);
        break;
    case 0x14:
        emit PMT2VelocityRangeUpper(v);
        break;
    case 0x15:
        emit PMT2VelocityFadeWidthLower(v);
        break;
    case 0x16:
        emit PMT2VelocityFadeWidthUpper(v);
        break;
    case 0x17:
        emit PMT3PartialSwitch(v);
        break;
    case 0x18:
        emit PMT3KeyboardRangeLower(v);
        break;
    case 0x19:
        emit PMT3KeyboardRangeUpper(v);
        break;
    case 0x1A:
        emit PMT3KeyboardFadeWidthLower(v);
        break;
    case 0x1B:
        emit PMT3KeyboardFadeWidthUpper(v);
        break;
    case 0x1C:
        emit PMT3VelocityRangeLower(v);
        break;
    case 0x1D:
        emit PMT3VelocityRangeUpper(v);
        break;
    case 0x1E:
        emit PMT3VelocityFadeWidthLower(v);
        break;
    case 0x1F:
        emit PMT3VelocityFadeWidthUpper(v);
        break;
    case 0x20:
        emit PMT4PartialSwitch(v);
        break;
    case 0x21:
        emit PMT4KeyboardRangeLower(v);
        break;
    case 0x22:
        emit PMT4KeyboardRangeUpper(v);
        break;
    case 0x23:
        emit PMT4KeyboardFadeWidthLower(v);
        break;
    case 0x24:
        emit PMT4KeyboardFadeWidthUpper(v);
        break;
    case 0x25:
        emit PMT4VelocityRangeLower(v);
        break;
    case 0x26:
        emit PMT4VelocityRangeUpper(v);
        break;
    case 0x27:
        emit PMT4VelocityFadeWidthLower(v);
        break;
    case 0x28:
        emit PMT4VelocityFadeWidthUpper(v);
        break;
    default:
        break;
    }
}

void Integra7PCMSynthTonePMT::DataReceive(const uint8_t *rdata, uint8_t a, int len)
{
    uint8_t a2 = a + len;
    uint8_t r = 0;

    while (a < a2) {
        data[a] = rdata[r++];
        EmitSignal(a,data[a]);
        ++a;
    }
}
