#include "keriongl/window.h"
#include <stdexcept>

namespace kerionGL {

    Window::Window(int width, int height, const std::string& title)
        : width(width), height(height), title(title) {
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!window) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }
    }

    Window::~Window() {
        if (window) {
            glfwDestroyWindow(window);
        }
        glfwTerminate();
    }

    void Window::makeContextCurrent() {
        if (window) {
            glfwMakeContextCurrent(window);
        }
    }

    void Window::swapBuffers() {
        if (window) {
            glfwSwapBuffers(window);
        }
    }

    bool Window::shouldClose() {
        return window ? glfwWindowShouldClose(window) : true;
    }

    void Window::pollEvents() {
        glfwPollEvents();
    }

    int Window::getWidth() const {
        return width;
    }

    int Window::getHeight() const {
        return height;
    }

    std::string Window::getTitle() const {
        return title;
    }

} // namespace kerionGL