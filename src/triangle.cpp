#include "keriongl/triangle.h"

#include <GL/gl.h>

kerionGL::Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3, const Color& color)
    : m_vertex1X(x1), m_vertex1Y(y1), m_vertex2X(x2), m_vertex2Y(y2), m_vertex3X(x3), m_vertex3Y(y3), m_color(color) {}

void kerionGL::Triangle::draw() const {
    glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);
    glBegin(GL_TRIANGLES);
    glVertex2f(m_vertex1X, m_vertex1Y);
    glVertex2f(m_vertex2X, m_vertex2Y);
    glVertex2f(m_vertex3X, m_vertex3Y);
    glEnd();
}
