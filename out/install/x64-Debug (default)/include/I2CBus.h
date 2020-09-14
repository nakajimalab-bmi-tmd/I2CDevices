#pragma once
#include <stdint.h>
#include <array>
#include <thread>
#include <vector>


class I2CBus
{
public:
	enum ClockRate
	{
		STANDARD_MODE = 100000,						/* 100kb/sec */
		FAST_MODE = 400000,							/* 400kb/sec */
		FAST_MODE_PLUS = 1000000, 					/* 1000kb/sec */
		HIGH_SPEED_MODE = 3400000 					/* 3.4Mb/sec */
	};

	I2CBus();
	~I2CBus();


	void Open(uint8_t channel);
	void SetConfiguration(ClockRate val = FAST_MODE);

	void WriteToReg(uint8_t slave_address, uint8_t register_address, uint8_t data);
	void WriteToReg(uint8_t slave_address, uint8_t register_address, uint8_t* data, uint32_t length);
	void ReadFromReg(uint8_t slave_address, uint8_t register_address, uint8_t* data);
	void ReadFromReg(uint8_t slave_address, uint8_t register_address, uint8_t* data, uint32_t length);

	//void Start();
	//void Stop();

private:

	void* Handle;
	std::thread th;
	bool threading = true;
};

