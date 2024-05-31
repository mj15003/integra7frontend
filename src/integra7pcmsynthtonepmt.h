#ifndef INTEGRA7PCMSYNTHTONEPMT_H
#define INTEGRA7PCMSYNTHTONEPMT_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7PCMSynthTonePMT : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7PCMSynthTonePMT(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);

    int GetLength() {return 0x29;}
    int GetItemsNumber() {return 0x29;}

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7PCMSYNTHTONEPMT_H
