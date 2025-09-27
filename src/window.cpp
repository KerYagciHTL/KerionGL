#include "keriongl/window.h"
#include <stdexcept>
#include <atomic>
#include <GL/gl.h>

namespace kerionGL {
    // Static member definitions
    std::atomic<bool> Window::glfwInitialized{false};
    std::atomic<int> Window::windowCount{0};

    Window::Window(int width, int height, const std::string& title, const Color& color)
        : width(width), height(height), title(title), color(color) {
        if (width <= 0 || height <= 0) {
            throw std::invalid_argument("Width and height must be positive integers");
        }
        bool expected = false;
        if (glfwInitialized.compare_exchange_strong(expected, true)) {
            if (!glfwInit()) {
                glfwInitialized = false;
                throw std::runtime_error("Failed to initialize GLFW");
            }
        }
        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!window) {
            throw std::runtime_error("Failed to create GLFW window");
        }
        ++windowCount;
        makeContextCurrent();
        glClearColor(color.r, color.g, color.b, color.a);
    }

    Window::~Window() {
        if (window) {
            glfwDestroyWindow(window);
            if (--windowCount == 0 && glfwInitialized) {
                glfwTerminate();
                glfwInitialized = false;
            }
        }
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

    void Window::clear() {
        makeContextCurrent();
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

} // namespace kerionGL