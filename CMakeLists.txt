PROJECT (easyqrpng)
cmake_minimum_required(VERSION 2.8)

SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

SET (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

set(CMAKE_DEBUG_POSTFIX "d")

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
include_directories(${CMAKE_SOURCE_DIR}/include)


FIND_PACKAGE(QREncodeWin REQUIRED)
include_directories(${QREncodeWin_INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(sample)
