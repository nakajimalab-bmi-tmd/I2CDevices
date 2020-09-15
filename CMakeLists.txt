# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("I2CDevices")

find_package(libmpsse-i2c CONFIG REQUIRED)

# Include sub-projects.
add_subdirectory ("I2C")
add_subdirectory("BMX055")
add_subdirectory("AS5048B")
add_subdirectory("Sample")