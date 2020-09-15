#include <boost/math/constants/constants.hpp>
#include "as5048b.h"

namespace i2c
{
	as5048b::as5048b(bus& i2c_bus, uint8_t address) : slave{ i2c_bus, address }, Polarity(1.), Angle(0.)
	{

	}

	void as5048b::set_polarity(bool polarity)
	{
		this->Polarity = polarity ? 1. : -1.;
	}

	void as5048b::update()
	{
		using namespace boost::math::double_constants;
		static uint8_t const register_address = 0xFE;		
		uint8_t buffer[2];
		this->read(register_address, buffer, 2);
		this->RawAngle = (static_cast<uint16_t>(buffer[0]) << 6) + static_cast<uint16_t>((buffer[1] & 0x3F));
		this->Angle = Polarity * static_cast<double>(this->RawAngle) / 16384. * two_pi;
	}

	double as5048b::get_angle() const
	{
		return this->Angle;
	}
}
