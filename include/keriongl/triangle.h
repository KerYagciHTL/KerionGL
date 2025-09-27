#ifndef KERIONGL_TRIANGLE_H
#define KERIONGL_TRIANGLE_H

#include "shape.h"
#include "color.h"

namespace kerionGL {
    class Triangle : public Shape {
    public:
        Triangle(float x1, float y1, float x2, float y2, float x3, float y3, const Color& color);
        void draw() const override;
    private:
        float m_vertex1X, m_vertex1Y, m_vertex2X, m_vertex2Y, m_vertex3X, m_vertex3Y;
        Color color;
    };
}

#endif //KERIONGL_TRIANGLE_H