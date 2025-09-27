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
        float x, y, width, height;
        Color color;
    };
}

#endif //KERIONGL_RECTANGLE_H

