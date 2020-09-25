#pragma once
#include <stdint.h>
#include <array>
#include <thread>
#include <vector>

namespace i2c
{
	class bus
	{
	public:
		enum class clock_rate 
		{
			STANDARD_MODE = 100000,						/* 100kb/sec */
			FAST_MODE = 400000,							/* 400kb/sec */
			FAST_MODE_PLUS = 1000000, 					/* 1000kb/sec */
			HIGH_SPEED_MODE = 3400000 					/* 3.4Mb/sec */
		};

		bus();
		~bus();


		void open(uint8_t channel);
		void set_configuration(clock_rate const val = clock_rate::FAST_MODE);
		void set_fast_transfer(bool fast_transfer_on = true);
		void write(uint8_t slave_address, uint8_t register_address, uint8_t data);
		void write(uint8_t slave_address, uint8_t register_address, uint8_t* data, uint32_t length);
		void read(uint8_t slave_address, uint8_t register_address, uint8_t* data);
		void read(uint8_t slave_address, uint8_t register_address, uint8_t* data, uint32_t length);

	private:
		void* Handle;
		bool FastTransfer;
	};
}

