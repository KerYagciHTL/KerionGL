#ifndef KERIONGL_WINDOW_H
#define KERIONGL_WINDOW_H

#include <string>
#include <GLFW/glfw3.h>
#include <atomic>

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
        GLFWwindow* window = nullptr;
        int width;
        int height;
        std::string title;
        //Thread-safe singelton pattern for GLFW initialization
        static std::atomic<bool> glfwInitialized;
        static std::atomic<int> windowCount;
    };
}
#endif //KERIONGL_WINDOW_H