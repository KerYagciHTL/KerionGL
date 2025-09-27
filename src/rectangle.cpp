#include "keriongl/rectangle.h"
#if defined(_WIN32)
  #include <windows.h>
  #include <GL/gl.h>
#elif defined(__APPLE__)
  #include <OpenGL/gl.h>
#else
  #include <GL/gl.h>
#endif

namespace kerionGL {
    Rectangle::Rectangle(float x, float y, float width, float height, const Color& color)
        : m_vertex1X(x), m_vertex1Y(y), m_width(width), m_height(height), m_color(color) {}

    void Rectangle::draw() const {
        glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);
        glBegin(GL_QUADS);
        glVertex2f(m_vertex1X, m_vertex1Y);
        glVertex2f(m_vertex1X + m_width, m_vertex1Y);
        glVertex2f(m_vertex1X + m_width, m_vertex1Y + m_height);
        glVertex2f(m_vertex1X, m_vertex1Y + m_height);
        glEnd();
    }
}

