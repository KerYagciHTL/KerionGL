#ifndef KERIONGL_SHAPE_H
#define KERIONGL_SHAPE_H

namespace kerionGL {
    class Shape {
    public:
        virtual ~Shape() = default;
        virtual void draw() const = 0;
    };
}

#endif //KERIONGL_SHAPE_H

