#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "I2C::I2C" for configuration "Debug"
set_property(TARGET I2C::I2C APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(I2C::I2C PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/I2C.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS I2C::I2C )
list(APPEND _IMPORT_CHECK_FILES_FOR_I2C::I2C "${_IMPORT_PREFIX}/lib/I2C.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
