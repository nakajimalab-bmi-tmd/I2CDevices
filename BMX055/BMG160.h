#pragma once
#include <I2CSlave.h>

namespace i2c
{
	class BMG160 : public slave<BMG160>
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

		BMG160(bus& i2c_bus, uint8_t address);
		void soft_reset();
		void set_power_mode();
		void set_range(Range const value = Range::R2000);
		void set_bandwidth(Bandwidth const value = Bandwidth::BW2000_0);
		void update();

		std::array<double, 3> get_angular_rate() const;

	private:
		Range range;
		std::array<int16_t, 3> rate_xyz;
	};
}
