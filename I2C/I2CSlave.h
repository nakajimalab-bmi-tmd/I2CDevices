#pragma once
#include "i2cbus.h"

namespace i2c
{
	template <typename Derived>
	class slave
	{
	public:
		slave(bus& i2c_bus, uint8_t address) : Bus(i2c_bus), Address(address) {}

		void write(uint8_t register_address, uint8_t data)
		{
			this->Bus.write(this->Address, register_address, data);
		}

		void write(uint8_t register_address, uint8_t* data, uint32_t length)
		{
			this->Bus.write(this->Address, register_address, data, length);
		}

		void read(uint8_t register_address, uint8_t* data)
		{
			return this->Bus.read(this->Address, register_address, data);
		}

		void read(uint8_t register_address, uint8_t* data, uint32_t length)
		{
			this->Bus.read(this->Address, register_address, data, length);
		}

		void update()
		{
			static_cast<Derived*>(this)->update();
		};

	private:
		bus& Bus;
		uint8_t Address;
	};
}
