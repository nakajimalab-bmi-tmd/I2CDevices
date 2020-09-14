#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "I2C::BMX055" for configuration "Debug"
set_property(TARGET I2C::BMX055 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(I2C::BMX055 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/BMX055.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS I2C::BMX055 )
list(APPEND _IMPORT_CHECK_FILES_FOR_I2C::BMX055 "${_IMPORT_PREFIX}/lib/BMX055.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
