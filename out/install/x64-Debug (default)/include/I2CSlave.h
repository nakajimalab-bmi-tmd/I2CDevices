#pragma once
#include "I2CBus.h"

template <typename Derived>
class I2CSlave
{
public:
	I2CSlave(I2CBus& i2c_bus, uint8_t address) : Bus(i2c_bus), Address(address) {}

	void WriteToReg(uint8_t register_address, uint8_t data)
	{
		this->Bus.WriteToReg(this->Address, register_address, data);
	}

	void WriteToReg(uint8_t register_address, uint8_t* data, uint32_t length)
	{
		this->Bus.WriteToReg(this->Address, register_address, data, length);
	}

	void ReadFromReg(uint8_t register_address, uint8_t* data)
	{
		return this->Bus.ReadFromReg(this->Address, register_address, data);
	}

	void ReadFromReg(uint8_t register_address, uint8_t* data, uint32_t length)
	{
		this->Bus.ReadFromReg(this->Address, register_address, data, length);
	}

	void Update() 
	{
		static_cast<Derived*>(this)->Update();
	};

private:
	I2CBus& Bus;
	uint8_t Address;
};
