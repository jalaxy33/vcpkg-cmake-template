# VCPKG CMake Template

A minimal CMake project template that uses [vcpkg](https://github.com/microsoft/vcpkg) for dependency management.


## Prerequisites

- A C/C++ compiler (e.g., GCC, Clang, MSVC)
- [CMake](https://cmake.org/download/): C/C++ build system generator.
- [vcpkg](https://vcpkg.io/en/index.html): C/C++ package manager.


## Usage

1. Configure the project with CMake using the provided presets in [`CMakePresets.json`](./CMakePresets.json):

   ```bash
   cmake --preset vcpkg-debug   # For debug build
   cmake --preset vcpkg-release # For release build
   ```

2. Build the project:

    ```bash
    cmake --build build
    ```

3. Run the executable:

    ```bash
    ./build/demo.exe   # On Windows
    ./build/demo      # On Linux/macOS
    ```


## Notes

### 1. Manage Dependencies with vcpkg

To manage dependencies, you can use vcpkg to install libraries. For example, to install OpenCV and ZLIB, run:

```bash
vcpkg add port zlib fmt
```

This command will automatically modified the dependency list in [`vcpkg.json`](./vcpkg.json) to trigger automatic installation when configuring the project with CMake.


Then link the libraries in your [`CMakeLists.txt`](./CMakeLists.txt):

```cmake
set(OpenCV_DIR "${VCPKG_INSTALLED_DIR}/x64-windows/share/opencv4")

find_package(ZLIB REQUIRED)
find_package(fmt CONFIG REQUIRED)

target_link_libraries(${targetname} PRIVATE ZLIB::ZLIB)
target_link_libraries(${targetname} PRIVATE fmt::fmt)
```



### 2. Integrate vcpkg with CMake

To use vcpkg with CMake, ensure that the `CMAKE_TOOLCHAIN_FILE` variable is set to the vcpkg toolchain file. The easiest way to do this is to use a [`CMakePresets.json`](./CMakePresets.json) file:

```json
{
  "version": 2,
  "configurePresets": [
    {
      "name": "vcpkg",
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/build",
      "cacheVariables": {
        "CMAKE_TOOLCHAIN_FILE": "$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake",
        "CMAKE_BUILD_TYPE": "Debug"
      }
    },
    {
      "name": "vcpkg-release",
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/build",
      "cacheVariables": {
        "CMAKE_TOOLCHAIN_FILE": "$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake",
        "CMAKE_BUILD_TYPE": "Release"
      }
    }
  ]
}
```
> Modified from the Microsoft `CMakePresets.json` [example](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-powershell#4---build-and-run-the-project)

Then you can use the `vcpkg` preset to configure your project with vcpkg:
```bash
cmake --preset vcpkg
cmake --preset vcpkg-release
```
