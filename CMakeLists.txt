# =============================================================================
# Preamble
# =============================================================================

cmake_minimum_required(VERSION 3.10.0)

# vcpkg integration
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_INSTALLED_DIR "$ENV{VCPKG_ROOT}/installed")   # use system-wide vcpkg installation

# generate `compile_commands.json` for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# =============================================================================
# Project Configuration
# =============================================================================

project(try-vcpkg VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

# =============================================================================
# Find Packages
# =============================================================================

find_package(ZLIB REQUIRED)
find_package(fmt CONFIG REQUIRED)

link_libraries(ZLIB::ZLIB)
link_libraries(fmt::fmt)

# =============================================================================
# Target Configuration
# =============================================================================

set(targetname demo)
add_executable(${targetname} main.cpp)
