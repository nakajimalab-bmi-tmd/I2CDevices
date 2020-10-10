# CMakeList.txt : CMake project for I2C, include source and define
# project specific logic here.
#

# Add source to this project's executable.
set(I2C_PUBLIC_HEADS
	"I2CBus.h"
	"I2CSlave.h"
)

add_library(I2C STATIC)
target_sources(I2C PRIVATE "I2CBus.cpp")
set_target_properties(I2C PROPERTIES PUBLIC_HEADER "${I2C_PUBLIC_HEADS}")
target_link_libraries(I2C PRIVATE ftdi::libmpsse-i2c)

install(TARGETS I2C EXPORT I2CTargets)
install(EXPORT I2CTargets
	FILE I2CConfig.cmake
	NAMESPACE I2C::
	DESTINATION share/I2C
)
