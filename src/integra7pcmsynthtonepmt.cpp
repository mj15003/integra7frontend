#include "integra7pcmsynthtonepmt.h"

Integra7PCMSynthTonePMT::Integra7PCMSynthTonePMT(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3)
: Integra7ParameterSet{parent,o1,o2,o3}{}

void Integra7PCMSynthTonePMT::EmitSignal(uint8_t a, int v)
{


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
