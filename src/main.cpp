#include <iostream>
#include "keriongl/version.h"

int main() {
    const auto version = kerionGL::getVersion();
    std::cout << "KerionGL " + version << std::endl;
    return 0;
}