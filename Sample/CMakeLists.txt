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

add_executable(AS5048Btest)
target_sources(AS5048Btest PRIVATE "AS5048Btest.cpp")
target_link_libraries(AS5048Btest PRIVATE ftdi::libmpsse-i2c PUBLIC I2C AS5048B)
target_include_directories(AS5048Btest PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/I2C>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/AS5048B>
)
