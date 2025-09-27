#ifndef KERIONGL_WINDOW_H
#define KERIONGL_WINDOW_H

#include <string>
#include <GLFW/glfw3.h>

namespace kerionGL {
    class Window {
    public:
        Window(int width, int height, const std::string& title);
        ~Window();

        void makeContextCurrent();
        void swapBuffers();
        bool shouldClose();
        void pollEvents();
        int getWidth() const;
        int getHeight() const;
        [[nodiscard]] std::string getTitle() const;

    private:
        GLFWwindow* window;
        int width;
        int height;
        std::string title;
    };
}
#endif //KERIONGL_WINDOW_H