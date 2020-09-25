#include <conio.h>
#include <iomanip>
#include <iostream>
#include <boost/math/constants/constants.hpp>
#include <as5048b.h>
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
	bus.set_fast_transfer(true);
	bus.open(1);
	bus.set_configuration(i2c::bus::clock_rate::STANDARD_MODE);

	std::array<as5048b, 3> pots = 
	{ 
		as5048b{bus, 0x43},
		as5048b{bus, 0x41},
		as5048b{bus, 0x40}
	};

	pots[2].set_polarity(false);

	uint8_t buf;
	pots[0].read(0x15, &buf);
	std::cout << std::hex << (uint16_t)(0x1F & buf) << std::endl;
	pots[1].read(0x15, &buf);
	std::cout << std::hex << (uint16_t)(0x1F & buf) << std::endl;
	pots[2].read(0x15, &buf);
	std::cout << std::hex << (uint16_t)(0x1F & buf) << std::endl;
	std::ofstream ofs{ "pot.csv" };
	::system("PAUSE");
	bool run = true;
	do
	{
		//pots[2].update();
		//std::cout << std::setw(10) << rad2deg(pots[2].get_angle()) << "\t";

		auto now = chrono::steady_clock::now();
		ofs << std::setw(10) << chrono::duration_cast<chrono::microseconds>(now.time_since_epoch()).count();
		for (auto& pot : pots)
		{
			try
			{
				pot.update();
				ofs << ", " << std::setw(10) << rad2deg(pot.get_angle());
				//std::cout << std::setw(10) << rad2deg(pot.get_angle()) << "\t";
			}
			catch (std::system_error)
			{
				ofs << ", error";
			}
		}
		
		ofs << std::endl;

		if (_kbhit() && _getch()) run = false;

	} while (run);

	return 0;
}
