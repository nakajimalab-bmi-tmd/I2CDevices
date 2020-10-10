# CMakeList.txt : CMake project for I2C, include source and define
# project specific logic here.
#

# Add source to this project's executable.

set(AS5048B_PUBLIC_HEADS
	"as5048b.h"
)

set(AS5048B_SRCS
	"as5048b.cpp"
)

add_library(AS5048B STATIC)
target_sources(AS5048B PRIVATE "${AS5048B_SRCS}")
set_target_properties(AS5048B PROPERTIES PUBLIC_HEADER "${AS5048B_PUBLIC_HEADS}")
target_link_libraries(AS5048B PRIVATE ftdi::libmpsse-i2c PUBLIC I2C)
target_include_directories(AS5048B PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/I2C>
)
install(TARGETS AS5048B EXPORT AS5048BTargets)
install(EXPORT AS5048BTargets
	FILE AS5048BConfig.cmake
	NAMESPACE I2C::
	DESTINATION share/I2C
)
