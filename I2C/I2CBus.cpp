#include <iostream>
#include <memory>
#include <system_error>
#include <libMPSSE_i2c.h>
#include "I2CBus.h"
#include "I2CSlave.h"

I2CBus::I2CBus() : Handle(nullptr)
{
}

I2CBus::~I2CBus()
{
	if (this->Handle)
	{
		I2C_CloseChannel(this->Handle);
		this->Handle = nullptr;
	}
}

void I2CBus::Open(uint8_t ch)
{
	if (this->Handle)
	{
		I2C_CloseChannel(this->Handle);
		this->Handle = nullptr;
	}
	I2C_OpenChannel(ch, &this->Handle);
}

void I2CBus::SetConfiguration(ClockRate val)
{
	ChannelConfig param;
	param.ClockRate = (I2C_ClockRate_t)val;
	param.LatencyTimer = 1;
	param.Options = I2C_ENABLE_DRIVE_ONLY_ZERO;
	I2C_InitChannel(this->Handle, &param);

	FT_DEVICE_LIST_INFO_NODE devList;
	I2C_GetChannelInfo(0, &devList);
	/*print the dev info*/
	//printf(" Flags=0x%x\n", devList.Flags);
	//printf(" Type=0x%x\n", devList.Type);
	//printf(" ID=0x%x\n", devList.ID);
	//printf(" LocId=0x%x\n", devList.LocId);
	//printf(" SerialNumber=%s\n", devList.SerialNumber);
	//printf(" Description=%s\n", devList.Description);
	//printf(" ftHandle=0x%x\n", devList.ftHandle);/*is 0 unless open*/

	//DWORD transfered;
	//uint8 buffer = 0x96;/* MPSSE command */
	//auto status = FT_Write(this->Handle, &buffer, 1, &transfered);

}

void I2CBus::WriteToReg(uint8_t slave_address, uint8_t register_address, uint8_t data)
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

void I2CBus::WriteToReg(uint8_t slave_address, uint8_t register_address, uint8_t* data, uint32_t length)
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

void I2CBus::ReadFromReg(uint8_t slave_address, uint8_t register_address, uint8_t* data)
{
	if (this->Handle)
	{
		uint32 transfered = 0;
		FT_STATUS stat_read, stat_write;
		stat_write = I2C_DeviceWrite(this->Handle, slave_address, 1, &register_address, &transfered, I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_FAST_TRANSFER);
		stat_read = I2C_DeviceRead(this->Handle, slave_address, 1, data, &transfered, I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_STOP_BIT | I2C_TRANSFER_OPTIONS_NACK_LAST_BYTE | I2C_TRANSFER_OPTIONS_FAST_TRANSFER);
		//printf("I2C_DeviceWrite: %d\n", stat_write);
		//printf("I2C_DeviceRead: %d\n", stat_read);
	}
}

void I2CBus::ReadFromReg(uint8_t slave_address, uint8_t register_address, uint8_t* data, uint32_t length)
{
	if (this->Handle)
	{
		uint32 transfered = 0;
		FT_STATUS stat = -1;
		size_t retry = 0;
		do
		{
			stat = I2C_DeviceWrite(this->Handle, slave_address, 1, &register_address, &transfered, I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_FAST_TRANSFER);
			if (++retry > 10) throw std::system_error{ (int)stat, std::generic_category() };
		} while (stat != FT_OK && transfered != 1);

		stat = I2C_DeviceRead(this->Handle, slave_address, length, data, &transfered, I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_STOP_BIT | I2C_TRANSFER_OPTIONS_NACK_LAST_BYTE | I2C_TRANSFER_OPTIONS_FAST_TRANSFER);
		if (stat != FT_OK)
		{
			throw std::system_error((int)stat, std::generic_category());
		}
	}
}

//void I2CBus::Start()
//{
//	if (this->th.get_id() != std::thread::id()) return;
//	this->threading = true;
//	this->th = std::thread(&I2CBus::UpdateThread, this);
//}
//
//void I2CBus::Stop()
//{
//	this->threading = false;
//	this->th.join();
//}
