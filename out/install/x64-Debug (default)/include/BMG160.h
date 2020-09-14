#pragma once
#include <I2CSlave.h>

class BMG160 : public I2CSlave<BMG160>
{
public:
	enum class Range : uint8_t
	{
		R2000 = 0,
		R1000 = 1,
		R500 = 2,
		R250 = 3,
		R125 = 4
	};

	enum class Bandwidth : uint8_t
	{
		BW2000_0 = 0,
		BW2000_230,
		BW1000_116,
		BW400_47,
		BW200_23,
		BW100_12,
		BW200_64,
		BW100_32
	};

	BMG160(I2CBus& i2c_bus, uint8_t address);
	void SoftReset();
	void SetPowerMode();
	void SetRange(Range const value = Range::R2000);
	void SetBandwidth(Bandwidth const value = Bandwidth::BW2000_0);
	void Update();

	std::array<int16_t, 3> GetRateXYZ() const;

private:
	std::array<int16_t, 3> rate_xyz;
};
