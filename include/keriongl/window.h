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
        GLFWwindow* m_window = nullptr;
        int m_width;
        int m_height;
        std::string m_title;
        Color m_color;

        std::vector<std::shared_ptr<Shape>> m_shapes;

        static std::atomic<bool> m_glfwInitialized;
        static std::atomic<int> m_windowCount;
    };

} // namespace kerionGL

#endif // KERIONGL_WINDOW_H
