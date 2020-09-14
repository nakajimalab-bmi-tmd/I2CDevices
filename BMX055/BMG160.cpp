#include "BMG160.h"
#include "BMG160_def.h"

BMG160::BMG160(I2CBus& i2c_bus, uint8_t address) : I2CSlave{ i2c_bus, address}
{
    SoftReset();
    SetPowerMode();
    SetRange();
    SetBandwidth();
}

void BMG160::SoftReset()
{
    this->WriteToReg(BMG160_BGW_SOFT_RST_ADDR, 0xB6);
}

void BMG160::SetPowerMode()
{
    this->WriteToReg(BMG160_MODE_LPM1_ADDR, 0);
    this->WriteToReg(BMG160_MODE_LPM2_ADDR, 0);
}

void BMG160::SetRange(Range const value)
{
    this->WriteToReg(BMG160_RANGE_ADDR, static_cast<uint8_t>(value));
}

void BMG160::SetBandwidth(Bandwidth const value)
{
    this->WriteToReg(BMG160_BW_ADDR, static_cast<uint8_t>(value));
}

void BMG160::Update()
{
    auto buf = reinterpret_cast<uint8_t*>(this->rate_xyz.data());
    this->ReadFromReg(BMG160_RATE_X_LSB_ADDR, buf, 6);
}

std::array<int16_t, 3> BMG160::GetRateXYZ() const
{
    return this->rate_xyz;
}

