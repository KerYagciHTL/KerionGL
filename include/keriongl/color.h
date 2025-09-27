#ifndef KERIONGL_COLOR_H
#define KERIONGL_COLOR_H

namespace kerionGL {
    struct Color {
        float r;
        float g;
        float b;
        float a;

        Color() : r(0), g(0), b(0), a(1) {}
        Color(float red, float green, float blue, float alpha = 1.0f)
            : r(red), g(green), b(blue), a(alpha) {}

        static Color Red() { return {1.0f, 0.0f, 0.0f}; }
        static Color Green() { return {0.0f, 1.0f, 0.0f}; }
        static Color Blue() { return {0.0f, 0.0f, 1.0f}; }
        static Color White() { return {1.0f, 1.0f, 1.0f}; }
        static Color Black() { return {0.0f, 0.0f, 0.0f}; }
        static Color Transparent() { return {0.0f, 0.0f, 0.0f, 0.0f}; }
    };
}
#endif //KERIONGL_COLOR_H