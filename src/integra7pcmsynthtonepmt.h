#ifndef INTEGRA7PCMSYNTHTONEPMT_H
#define INTEGRA7PCMSYNTHTONEPMT_H

#include <QObject>
#include "integra7parameterset.h"

class Integra7PCMSynthTonePMT : public Integra7ParameterSet
{
    Q_OBJECT
public:
    explicit Integra7PCMSynthTonePMT(Integra7Device *parent, uint8_t o1, uint8_t o2, uint8_t o3);

    int getStructureType12() {return data[0x00];}
    int getBooster12() {return data[0x01];}
    int getStructureType34() {return data[0x02];}
    int getBooster34() {return data[0x03];}
    int getPMTVelocityControl() {return data[0x04];}
    int getPMT1PartialSwitch() {return data[0x05];}
    int getPMT1KeyboardRangeLower() {return data[0x06];}
    int getPMT1KeyboardRangeUpper() {return data[0x07];}
    int getPMT1KeyboardFadeWidthLower() {return data[0x08];}
    int getPMT1KeyboardFadeWidthUpper() {return data[0x09];}
    int getPMT1VelocityRangeLower() {return data[0x0A];}
    int getPMT1VelocityRangeUpper() {return data[0x0B];}
    int getPMT1VelocityFadeWidthLower() {return data[0x0C];}
    int getPMT1VelocityFadeWidthUpper() {return data[0x0D];}
    int getPMT2PartialSwitch() {return data[0x0E];}
    int getPMT2KeyboardRangeLower() {return data[0x0F];}
    int getPMT2KeyboardRangeUpper() {return data[0x10];}
    int getPMT2KeyboardFadeWidthLower() {return data[0x11];}
    int getPMT2KeyboardFadeWidthUpper() {return data[0x12];}
    int getPMT2VelocityRangeLower() {return data[0x13];}
    int getPMT2VelocityRangeUpper() {return data[0x14];}
    int getPMT2VelocityFadeWidthLower() {return data[0x15];}
    int getPMT2VelocityFadeWidthUpper() {return data[0x16];}
    int getPMT3PartialSwitch() {return data[0x17];}
    int getPMT3KeyboardRangeLower() {return data[0x18];}
    int getPMT3KeyboardRangeUpper() {return data[0x19];}
    int getPMT3KeyboardFadeWidthLower() {return data[0x1A];}
    int getPMT3KeyboardFadeWidthUpper() {return data[0x1B];}
    int getPMT3VelocityRangeLower() {return data[0x1C];}
    int getPMT3VelocityRangeUpper() {return data[0x1D];}
    int getPMT3VelocityFadeWidthLower() {return data[0x1E];}
    int getPMT3VelocityFadeWidthUpper() {return data[0x1F];}
    int getPMT4PartialSwitch() {return data[0x20];}
    int getPMT4KeyboardRangeLower() {return data[0x21];}
    int getPMT4KeyboardRangeUpper() {return data[0x22];}
    int getPMT4KeyboardFadeWidthLower() {return data[0x23];}
    int getPMT4KeyboardFadeWidthUpper() {return data[0x24];}
    int getPMT4VelocityRangeLower() {return data[0x25];}
    int getPMT4VelocityRangeUpper() {return data[0x26];}
    int getPMT4VelocityFadeWidthLower() {return data[0x27];}
    int getPMT4VelocityFadeWidthUpper() {return data[0x28];}

    void DataReceive(const uint8_t *rdata, uint8_t a, int len);    

    int GetLength() {return 0x29;}
    int GetItemsNumber() {return 0x29;}

public slots:

    void setStructureType12(int v) {DataSet(0x00,v);}
    void setBooster12(int v) {DataSet(0x01,v);}
    void setStructureType34(int v) {DataSet(0x02,v);}
    void setBooster34(int v) {DataSet(0x03,v);}
    void setPMTVelocityControl(int v) {DataSet(0x04,v);}
    void setPMT1PartialSwitch(int v) {DataSet(0x05,v);}
    void setPMT1KeyboardRangeLower(int v) {DataSet(0x06,v);}
    void setPMT1KeyboardRangeUpper(int v) {DataSet(0x07,v);}
    void setPMT1KeyboardFadeWidthLower(int v) {DataSet(0x08,v);}
    void setPMT1KeyboardFadeWidthUpper(int v) {DataSet(0x09,v);}
    void setPMT1VelocityRangeLower(int v) {DataSet(0x0A,v);}
    void setPMT1VelocityRangeUpper(int v) {DataSet(0x0B,v);}
    void setPMT1VelocityFadeWidthLower(int v) {DataSet(0x0C,v);}
    void setPMT1VelocityFadeWidthUpper(int v) {DataSet(0x0D,v);}
    void setPMT2PartialSwitch(int v) {DataSet(0x0E,v);}
    void setPMT2KeyboardRangeLower(int v) {DataSet(0x0F,v);}
    void setPMT2KeyboardRangeUpper(int v) {DataSet(0x10,v);}
    void setPMT2KeyboardFadeWidthLower(int v) {DataSet(0x11,v);}
    void setPMT2KeyboardFadeWidthUpper(int v) {DataSet(0x12,v);}
    void setPMT2VelocityRangeLower(int v) {DataSet(0x13,v);}
    void setPMT2VelocityRangeUpper(int v) {DataSet(0x14,v);}
    void setPMT2VelocityFadeWidthLower(int v) {DataSet(0x15,v);}
    void setPMT2VelocityFadeWidthUpper(int v) {DataSet(0x16,v);}
    void setPMT3PartialSwitch(int v) {DataSet(0x17,v);}
    void setPMT3KeyboardRangeLower(int v) {DataSet(0x18,v);}
    void setPMT3KeyboardRangeUpper(int v) {DataSet(0x19,v);}
    void setPMT3KeyboardFadeWidthLower(int v) {DataSet(0x1A,v);}
    void setPMT3KeyboardFadeWidthUpper(int v) {DataSet(0x1B,v);}
    void setPMT3VelocityRangeLower(int v) {DataSet(0x1C,v);}
    void setPMT3VelocityRangeUpper(int v) {DataSet(0x1D,v);}
    void setPMT3VelocityFadeWidthLower(int v) {DataSet(0x1E,v);}
    void setPMT3VelocityFadeWidthUpper(int v) {DataSet(0x1F,v);}
    void setPMT4PartialSwitch(int v) {DataSet(0x20,v);}
    void setPMT4KeyboardRangeLower(int v) {DataSet(0x21,v);}
    void setPMT4KeyboardRangeUpper(int v) {DataSet(0x22,v);}
    void setPMT4KeyboardFadeWidthLower(int v) {DataSet(0x23,v);}
    void setPMT4KeyboardFadeWidthUpper(int v) {DataSet(0x24,v);}
    void setPMT4VelocityRangeLower(int v) {DataSet(0x25,v);}
    void setPMT4VelocityRangeUpper(int v) {DataSet(0x26,v);}
    void setPMT4VelocityFadeWidthLower(int v) {DataSet(0x27,v);}
    void setPMT4VelocityFadeWidthUpper(int v) {DataSet(0x28,v);}

signals:

    void StructureType12(int v);
    void Booster12(int v);
    void StructureType34(int v);
    void Booster34(int v);
    void PMTVelocityControl(int v);
    void PMT1PartialSwitch(int v);
    void PMT1KeyboardRangeLower(int v);
    void PMT1KeyboardRangeUpper(int v);
    void PMT1KeyboardFadeWidthLower(int v);
    void PMT1KeyboardFadeWidthUpper(int v);
    void PMT1VelocityRangeLower(int v);
    void PMT1VelocityRangeUpper(int v);
    void PMT1VelocityFadeWidthLower(int v);
    void PMT1VelocityFadeWidthUpper(int v);
    void PMT2PartialSwitch(int v);
    void PMT2KeyboardRangeLower(int v);
    void PMT2KeyboardRangeUpper(int v);
    void PMT2KeyboardFadeWidthLower(int v);
    void PMT2KeyboardFadeWidthUpper(int v);
    void PMT2VelocityRangeLower(int v);
    void PMT2VelocityRangeUpper(int v);
    void PMT2VelocityFadeWidthLower(int v);
    void PMT2VelocityFadeWidthUpper(int v);
    void PMT3PartialSwitch(int v);
    void PMT3KeyboardRangeLower(int v);
    void PMT3KeyboardRangeUpper(int v);
    void PMT3KeyboardFadeWidthLower(int v);
    void PMT3KeyboardFadeWidthUpper(int v);
    void PMT3VelocityRangeLower(int v);
    void PMT3VelocityRangeUpper(int v);
    void PMT3VelocityFadeWidthLower(int v);
    void PMT3VelocityFadeWidthUpper(int v);
    void PMT4PartialSwitch(int v);
    void PMT4KeyboardRangeLower(int v);
    void PMT4KeyboardRangeUpper(int v);
    void PMT4KeyboardFadeWidthLower(int v);
    void PMT4KeyboardFadeWidthUpper(int v);
    void PMT4VelocityRangeLower(int v);
    void PMT4VelocityRangeUpper(int v);
    void PMT4VelocityFadeWidthLower(int v);
    void PMT4VelocityFadeWidthUpper(int v);

private:
    void EmitSignal(uint8_t a, int v);
};

#endif // INTEGRA7PCMSYNTHTONEPMT_H
