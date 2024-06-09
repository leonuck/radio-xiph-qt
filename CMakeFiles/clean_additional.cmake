# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/radio_xiph_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/radio_xiph_autogen.dir/ParseCache.txt"
  "radio_xiph_autogen"
  )
endif()
