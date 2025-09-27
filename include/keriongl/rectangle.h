#ifndef KERIONGL_RECTANGLE_H
#define KERIONGL_RECTANGLE_H

#include "shape.h"
#include "color.h"

namespace kerionGL {
    class Rectangle : public Shape {
    public:
        Rectangle(float x, float y, float width, float height, const Color& color);
        void draw() const override;
    private:
        float m_vertex1X, m_vertex1Y, m_width, m_height;
        Color m_color;
    };
}

#endif //KERIONGL_RECTANGLE_H

