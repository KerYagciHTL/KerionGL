#include <iostream>
#include "keriongl/version.h"
#include "keriongl/window.h"
#include "keriongl/rectangle.h"

int main() {
    std::cout << "KerionGL Version: " << kerionGL::getVersion() << std::endl;

    try {
        kerionGL::Window window(800, 600, "KerionGL " + kerionGL::getVersion());
        window.makeContextCurrent();

        window.setColor(kerionGL::Color::White());
        window.addShape(std::make_shared<kerionGL::Rectangle>(
            100, 100, 200, 150, kerionGL::Color::Green()));

        while (!window.shouldClose()) {
            window.clear();
            window.drawShapes();
            window.swapBuffers();
            window.pollEvents();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
