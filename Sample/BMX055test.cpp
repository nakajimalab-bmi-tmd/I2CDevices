#include <conio.h>
#include <iomanip>
#include <iostream>
#include <boost/math/constants/constants.hpp>
#include <BMG160.h>
#include <chrono>
#include <fstream>

inline double rad2deg(double const rad)
{
	return (rad * boost::math::constants::one_div_pi<double>()) * 180.;
}

int main()
{
	using namespace i2c;
	namespace chrono = std::chrono;
	i2c::bus bus;
	bus.open(0);
	bus.set_configuration(bus::clock_rate::FAST_MODE);
	BMG160 gyro{ bus, 0x69 };

	std::ofstream ofs("gyro.csv");
	bool run = true;
	do
	{
		gyro.update();
		auto now = chrono::steady_clock::now();
		auto rate = gyro.get_angular_rate();

		ofs << std::setw(10) << chrono::duration_cast<chrono::microseconds>(now.time_since_epoch()).count() << ", ";
		ofs << std::setw(10) << rad2deg(rate[0]) << ", ";
		ofs << std::setw(10) << rad2deg(rate[1]) << ", ";
		ofs << std::setw(10) << rad2deg(rate[2]) << std::endl;

		//std::cout << std::setw(10) << chrono::duration_cast<chrono::microseconds>(now.time_since_epoch()).count() << "\t";
		//std::cout << std::setw(10) << rad2deg(rate[0]) << "\t";
		//std::cout << std::setw(10) << rad2deg(rate[1]) << "\t";
		//std::cout << std::setw(10) << rad2deg(rate[2]) << std::endl;

		if (_kbhit() && _getch()) run = false;

	} while (run);

	return 0;
}
