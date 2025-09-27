#ifndef KERIONGL_WINDOW_H
#define KERIONGL_WINDOW_H

#include <string>
#include <vector>
#include <memory>
#include <atomic>
#include <GLFW/glfw3.h>
#include "keriongl/color.h"
#include "keriongl/shape.h"

namespace kerionGL {

    class Window {
    public:
        Window(int width, int height, const std::string& title,
               const Color& color = Color::Black());
        ~Window();

        void makeContextCurrent();
        void swapBuffers();
        bool shouldClose();
        void pollEvents();

        int getWidth() const;
        int getHeight() const;
        std::string getTitle() const;

        void clear();
        void setColor(const Color& newColor);

        void addShape(std::shared_ptr<Shape> shape);
        void drawShapes() const;

    private:
        GLFWwindow* window = nullptr;
        int width;
        int height;
        std::string title;
        Color color;

        std::vector<std::shared_ptr<Shape>> shapes;

        static std::atomic<bool> glfwInitialized;
        static std::atomic<int> windowCount;
    };

} // namespace kerionGL

#endif // KERIONGL_WINDOW_H
