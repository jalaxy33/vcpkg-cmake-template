# VCPKG CMake Template

A minimal CMake project template that uses [vcpkg](https://github.com/microsoft/vcpkg) for dependency management.


## Prerequisites

- A C/C++ compiler (e.g., GCC, Clang, MSVC)
- [CMake](https://cmake.org/download/): C/C++ build system generator.
- [vcpkg](https://vcpkg.io/en/index.html): C/C++ package manager.


## Usage

1. Configure and build the project using CMake:

    ```bash
    cmake -B build  && cmake -B build   # Debug build
    cmake -B build  && cmake -B build --config Release  # Release build
    ```

2. Run the executable:

    ```bash
    ./build/Debug/demo.exe   # Debug build
    ./build/Release/demo.exe  # Release build
    ```

## Notes


### 1. Manage Dependencies with vcpkg

To manage dependencies, you can use vcpkg to install libraries. For example, to install `zlib` and `fmt`, run:
```bash
# Note: run the following commands in project root directory

# 1. generate manifest `vcpkg.json`
vcpkg new --application

# 2. install dependencies
vcpkg add port zlib fmt
```

This command will update your vcpkg.json file to include the specified port in the dependencies array. 

> Note: You can also manually edit the `vcpkg.json` file to add dependencies. The file should look like this:

```json
{
  "dependencies": [
    "zlib",
    "fmt"
  ]
}
```


### 2. Integrate vcpkg with CMake

To integrate vcpkg with CMake, ensure that the `CMAKE_TOOLCHAIN_FILE` is set to the vcpkg toolchain file. This is typically done by adding the following line to your `CMakeLists.txt` before the `project()` command:

```cmake
# vcpkg integration 
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# before the `project()` command
```

Then you can use the `find_package()` command to locate and link against the installed libraries in your CMake project. For example:

```cmake
find_package(ZLIB REQUIRED)
find_package(fmt CONFIG REQUIRED)

link_libraries(ZLIB::ZLIB)
link_libraries(fmt::fmt)
```

