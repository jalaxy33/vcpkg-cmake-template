#include <iostream>
#include <zlib.h> // Include the zlib header

int main(int, char**){
    std::cout << "Hello, from try-vcpkg!\n";
    std::cout << "ZLIB_VERSION=" << ZLIB_VERSION << "\n";
    return 0;
}
