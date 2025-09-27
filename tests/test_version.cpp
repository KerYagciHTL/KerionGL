#include <cassert>
#include "keriongl/version.h"

int main() {
    const auto version = kerionGL::getVersion();
    assert(version == "0.1.0");
    return 0;
}
