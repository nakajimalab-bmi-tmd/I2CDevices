#include <boost/math/constants/constants.hpp>
#include <map>
#include "BMG160.h"
#include "BMG160_def.h"

namespace i2c
{

	inline double deg2rad(double const deg)
	{
		return deg / 180. * boost::math::constants::pi<double>();
	}

	//auto GyroScale = [](int16_t const raw) -> float
	//{ return raw * gyro_scale; };
	std::map<BMG160::Range, double> range_value{
		{BMG160::Range::R2000, deg2rad(2000) / 32767.},
		{BMG160::Range::R1000, deg2rad(1000) / 32767.},
		{BMG160::Range::R500, deg2rad(500) / 32767.},
		{BMG160::Range::R250, deg2rad(250) / 32767.},
		{BMG160::Range::R125, deg2rad(125) / 32767.}
	};

	BMG160::BMG160(bus& i2c_bus, uint8_t address) : slave{ i2c_bus, address }, range{ Range::R2000 }
	{
		soft_reset();
		set_power_mode();
		set_range(range);
		set_bandwidth();
	}

	void BMG160::soft_reset()
	{
		this->write(BMG160_BGW_SOFT_RST_ADDR, 0xB6);
	}

	void BMG160::set_power_mode()
	{
		this->write(BMG160_MODE_LPM1_ADDR, 0);
		this->write(BMG160_MODE_LPM2_ADDR, 0);
	}

	void BMG160::set_range(Range const value)
	{
		this->write(BMG160_RANGE_ADDR, static_cast<uint8_t>(value));
	}

	void BMG160::set_bandwidth(Bandwidth const value)
	{
		this->write(BMG160_BW_ADDR, static_cast<uint8_t>(value));
	}

	void BMG160::update()
	{
		auto buf = reinterpret_cast<uint8_t*>(this->rate_xyz.data());
		this->read(BMG160_RATE_X_LSB_ADDR, buf, 6);
	}

	std::array<double, 3> BMG160::get_angular_rate() const
	{
		return std::array<double, 3>{
			rate_xyz[0] * range_value[range],
			rate_xyz[1] * range_value[range],
			rate_xyz[2] * range_value[range]		
		};
	}
}
