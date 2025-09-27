#include <iostream>
#include "keriongl/version.h"
#include "keriongl/window.h"

int main() {
    std::cout << "KerionGL Version: " << kerionGL::getVersion() << std::endl;

    try {
        kerionGL::Window window(800, 600, "KerionGL " + kerionGL::getVersion());
        window.makeContextCurrent();

        window.setColor(kerionGL::Color::Blue());
        window.clear();

        while (!window.shouldClose()) {
            // Render here (if needed)

            window.swapBuffers();
            window.pollEvents();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}