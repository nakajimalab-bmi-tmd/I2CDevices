#include <iostream>
#include <memory>
#include <system_error>
#include <libMPSSE_i2c.h>
#include "i2cbus.h"

namespace i2c
{

	bus::bus() : Handle(nullptr), FastTransfer(true)
	{
	}

	bus::~bus()
	{
		if (this->Handle)
		{
			I2C_CloseChannel(this->Handle);
			this->Handle = nullptr;
		}
	}

	void bus::open(uint8_t ch)
	{
		if (this->Handle)
		{
			I2C_CloseChannel(this->Handle);
			this->Handle = nullptr;
		}
		I2C_OpenChannel(ch, &this->Handle);
	}

	void bus::set_configuration(clock_rate const val)
	{
		ChannelConfig param;
		param.ClockRate = (I2C_ClockRate_t)val;
		param.LatencyTimer = 1;
		param.Options = I2C_ENABLE_DRIVE_ONLY_ZERO;
		I2C_InitChannel(this->Handle, &param);
	}

	void bus::set_fast_transfer(bool fast_transfer_on)
	{
		FastTransfer = fast_transfer_on;
	}

	void bus::write(uint8_t slave_address, uint8_t register_address, uint8_t data)
	{
		if (this->Handle)
		{
			uint32 transfered = 0;
			FT_STATUS stat;
			uint8_t buffer[2];
			buffer[0] = register_address;
			buffer[1] = data;
			stat = I2C_DeviceWrite(
				this->Handle,
				slave_address,
				2,
				buffer,
				&transfered,
				I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_STOP_BIT);
		}
	}

	void bus::write(uint8_t slave_address, uint8_t register_address, uint8_t* data, uint32_t length)
	{
		if (this->Handle)
		{
			uint32 transfered = 0;
			FT_STATUS stat;
			uint8_t buffer[255] = { 0 };
			buffer[0] = register_address;
			std::memcpy(buffer + 1, data, length);
			stat = I2C_DeviceWrite(
				this->Handle,
				slave_address,
				length,
				buffer,
				&transfered,
				I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_STOP_BIT);
		}
	}

	void bus::read(uint8_t slave_address, uint8_t register_address, uint8_t* data)
	{
		if (this->Handle)
		{
			uint32 transfered = 0;
			FT_STATUS stat_read, stat_write;
			stat_write = I2C_DeviceWrite(this->Handle, slave_address, 1, &register_address, &transfered, I2C_TRANSFER_OPTIONS_START_BIT | (FastTransfer ? I2C_TRANSFER_OPTIONS_FAST_TRANSFER : 0));
			stat_read = I2C_DeviceRead(this->Handle, slave_address, 1, data, &transfered, I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_STOP_BIT | I2C_TRANSFER_OPTIONS_NACK_LAST_BYTE | (FastTransfer ? I2C_TRANSFER_OPTIONS_FAST_TRANSFER : 0));
			//printf("I2C_DeviceWrite: %d\n", stat_write);
			//printf("I2C_DeviceRead: %d\n", stat_read);
		}
	}

	void bus::read(uint8_t slave_address, uint8_t register_address, uint8_t* data, uint32_t length)
	{
		if (this->Handle)
		{
			uint32 transfered = 0;
			FT_STATUS stat = -1;
			size_t retry = 0;
			do
			{
				stat = I2C_DeviceWrite(this->Handle, slave_address, 1, &register_address, &transfered, I2C_TRANSFER_OPTIONS_START_BIT | (FastTransfer ? I2C_TRANSFER_OPTIONS_FAST_TRANSFER : 0));
				if (++retry > 10) throw std::system_error{ (int)stat, std::generic_category() };
			} while (stat != FT_OK && transfered != 1);

			stat = I2C_DeviceRead(this->Handle, slave_address, length, data, &transfered, I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_STOP_BIT | I2C_TRANSFER_OPTIONS_NACK_LAST_BYTE | (FastTransfer ? I2C_TRANSFER_OPTIONS_FAST_TRANSFER : 0));
			if (stat != FT_OK)
			{
				throw std::system_error((int)stat, std::generic_category());
			}
		}
	}
}
