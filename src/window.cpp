#include "keriongl/window.h"
#include <stdexcept>
#include <iostream>
#if defined(_WIN32)
  #include <windows.h>
  #include <GL/gl.h>
#elif defined(__APPLE__)
  #include <OpenGL/gl.h>
#else
  #include <GL/gl.h>
#endif

namespace kerionGL {

std::atomic<bool> Window::m_glfwInitialized{false};
std::atomic<int>  Window::m_windowCount{0};

Window::Window(int width, int height, const std::string& title, const Color& color)
    : m_width(width), m_height(height), m_title(title), m_color(color) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Width and height must be positive integers");
    }

    bool expected = false;
    if (m_glfwInitialized.compare_exchange_strong(expected, true)) {
        if (!glfwInit()) {
            m_glfwInitialized = false;
            throw std::runtime_error("Failed to initialize GLFW");
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    }

    m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!m_window) {
        throw std::runtime_error("Failed to create GLFW window");
    }

    ++m_windowCount;
    makeContextCurrent();
    glfwSwapInterval(1);

    int fbw, fbh;
    glfwGetFramebufferSize(m_window, &fbw, &fbh);
    glViewport(0, 0, fbw, fbh);
    glfwSetFramebufferSizeCallback(m_window,
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
    if (m_window) {
        glfwDestroyWindow(m_window);
        if (--m_windowCount == 0 && m_glfwInitialized) {
            glfwTerminate();
            m_glfwInitialized = false;
        }
    }
}

void Window::makeContextCurrent() {
    if (m_window) glfwMakeContextCurrent(m_window);
}

void Window::swapBuffers() {
    if (m_window) glfwSwapBuffers(m_window);
}

bool Window::shouldClose() {
    return m_window ? glfwWindowShouldClose(m_window) : true;
}

void Window::pollEvents() { glfwPollEvents(); }

int  Window::getWidth()  const { return m_width; }
int  Window::getHeight() const { return m_height; }
std::string Window::getTitle() const { return m_title; }

void Window::clear() {
    makeContextCurrent();
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::setColor(const Color& newColor) {
    m_color = newColor;
    makeContextCurrent();
    glClearColor(m_color.r, m_color.g, m_color.b, m_color.a);
}

void Window::addShape(std::shared_ptr<Shape> shape) {
    m_shapes.push_back(shape);
}

void Window::drawShapes() const {
    for (const auto& s : m_shapes) s->draw();
}

} //
