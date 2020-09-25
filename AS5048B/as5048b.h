#pragma once
#include <I2CSlave.h>

namespace i2c
{
	class as5048b : public slave<as5048b>
	{
	public:
		as5048b(bus& i2c_bus, uint8_t address);
		void set_polarity(bool polarity);
		double get_angle() const;
		void update();

	private:
		double Polarity;
		double Angle;
	};
}
