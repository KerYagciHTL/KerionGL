#include <cassert>
#include "keriongl/version.h"

int main() {
    const auto version = kerionGL::getVersion();
    assert(version == "0.2.3");
    return 0;
}
