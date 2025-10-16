cmake_minimum_required(VERSION 3.10.0)
project(try-vcpkg VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(ZLIB REQUIRED)

set(targetname demo)
add_executable(${targetname} main.cpp)
target_link_libraries(${targetname} PRIVATE ZLIB::ZLIB)


