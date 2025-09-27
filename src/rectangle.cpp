#include "keriongl/rectangle.h"
#include <GL/gl.h>

namespace kerionGL {
    Rectangle::Rectangle(float x, float y, float width, float height, const Color& color)
        : x(x), y(y), width(width), height(height), color(color) {}

    void Rectangle::draw() const {
        glColor4f(color.r, color.g, color.b, color.a);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
    }
}

