# CMakeList.txt : CMake project for I2C, include source and define
# project specific logic here.
#

# Add source to this project's executable.

set(BMX055_PUBLIC_HEADS
	"BMG160.h"
	"BMG160_def.h"
)

set(BMX055_SRCS
	"BMG160.cpp"
)

add_library(BMX055)
target_sources(BMX055 PRIVATE "${BMX055_SRCS}")
set_target_properties(BMX055 PROPERTIES PUBLIC_HEADER "${BMX055_PUBLIC_HEADS}")
target_link_libraries(BMX055 PRIVATE ftdi::libmpsse-i2c PUBLIC I2C)
target_include_directories(BMX055 PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/I2C>
)
install(TARGETS BMX055 EXPORT BMX055Targets)
install(EXPORT BMX055Targets
	FILE BMX055Config.cmake
	NAMESPACE I2C::
	DESTINATION share/I2C
)
