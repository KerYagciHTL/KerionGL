#include "keriongl/window.h"
#include <stdexcept>
#include <iostream>
#include <GL/gl.h>

namespace kerionGL {

std::atomic<bool> Window::glfwInitialized{false};
std::atomic<int>  Window::windowCount{0};

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
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    }

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        throw std::runtime_error("Failed to create GLFW window");
    }

    ++windowCount;
    makeContextCurrent();
    glfwSwapInterval(1);

    int fbw, fbh;
    glfwGetFramebufferSize(window, &fbw, &fbh);
    glViewport(0, 0, fbw, fbh);
    glfwSetFramebufferSizeCallback(window,
        [](GLFWwindow*, int w, int h){ glViewport(0, 0, w, h); });

    // 2D-Orthoprojektion: Pixelkoordinaten, Ursprung links-oben
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, static_cast<GLdouble>(width),
            static_cast<GLdouble>(height), 0.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

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
    if (window) glfwMakeContextCurrent(window);
}

void Window::swapBuffers() {
    if (window) glfwSwapBuffers(window);
}

bool Window::shouldClose() {
    return window ? glfwWindowShouldClose(window) : true;
}

void Window::pollEvents() { glfwPollEvents(); }

int  Window::getWidth()  const { return width; }
int  Window::getHeight() const { return height; }
std::string Window::getTitle() const { return title; }

void Window::clear() {
    makeContextCurrent();
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::setColor(const Color& newColor) {
    color = newColor;
    makeContextCurrent();
    glClearColor(color.r, color.g, color.b, color.a);
}

void Window::addShape(std::shared_ptr<Shape> shape) {
    shapes.push_back(shape);
}

void Window::drawShapes() const {
    for (const auto& s : shapes) s->draw();
}

} //
