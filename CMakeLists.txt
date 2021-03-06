cmake_minimum_required(VERSION 3.0.0)
project(possamp)

set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)

set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  )

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE MinSizeRel) 
endif()

# Find current version from source code.
file(
  STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/src/Version.h"
  VERSION_DATA REGEX "define.+_VERSION.+[0-9]+$"
  )
set(VERSION_NUMBER "")
foreach (ver IN LISTS VERSION_DATA)
  string(REGEX MATCH "[0-9]+" number ${ver})
  set(VERSION_NUMBER "${VERSION_NUMBER}${number}.")
endforeach()
string(LENGTH ${VERSION_NUMBER} length)
math(EXPR length "${length}-1")
string(SUBSTRING ${VERSION_NUMBER} 0 ${length} VERSION_NUMBER)

include(platform)
include(target)

add_subdirectory(src)

message(STATUS "--------------------------------------------------")
message(STATUS "BUILD: ${CMAKE_BUILD_TYPE}")
message(STATUS "VERSION: ${VERSION_NUMBER}")
message(STATUS "Using C++11 features")
message(STATUS "--------------------------------------------------")
