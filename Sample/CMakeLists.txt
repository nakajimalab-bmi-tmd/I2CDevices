# CMakeList.txt : CMake project for I2C, include source and define
# project specific logic here.
#

# Add source to this project's executable.

add_executable(BMX055test)
target_sources(BMX055test PRIVATE "BMX055test.cpp")
target_link_libraries(BMX055test PRIVATE ftdi::libmpsse-i2c PUBLIC I2C BMX055)
target_include_directories(BMX055test PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/I2C>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/BMX055>
)
