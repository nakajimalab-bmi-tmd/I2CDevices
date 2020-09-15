#include <conio.h>
#include <iomanip>
#include <iostream>
#include <boost/math/constants/constants.hpp>
#include <BMG160.h>


inline double rad2deg(double const rad)
{
	return (rad * boost::math::constants::one_div_pi<double>()) * 180.;
}

int main()
{
	using namespace i2c;
	i2c::bus bus;
	bus.open(0);
	bus.set_configuration();
	BMG160 gyro{ bus, 0x69 };

	bool run = true;
	do
	{
		gyro.update();
		auto rate = gyro.get_angular_rate();
		std::cout << std::setw(10) << rad2deg(rate[0]) << "\t";
		std::cout << std::setw(10) << rad2deg(rate[1]) << "\t";
		std::cout << std::setw(10) << rad2deg(rate[2]) << std::endl;

		if (_kbhit() && _getch()) run = false;

	} while (run);

	return 0;
}
