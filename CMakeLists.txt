cmake_minimum_required(VERSION 3.22)
project(vk)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
set(CONAN_DISABLE_CHECK_COMPILER True)
conan_basic_setup()

add_executable(vk main.cpp FirstNRepeatingStream.h)


include(CTest)
enable_testing()
add_subdirectory(test)
