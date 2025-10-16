#include <iostream>
#include <zlib.h> 
#include <fmt/core.h>

int main(int, char**){
    std::cout << "Hello, from try-vcpkg!\n";
    std::cout << "ZLIB_VERSION=" << ZLIB_VERSION << "\n";
    std::cout << "FMT_VERSION=" << FMT_VERSION << "\n";
    return 0;
}
