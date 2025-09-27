#include "keriongl/window.h"

#include <thread>
#include <vector>
#include <iostream>

void createAndDestroyWindow(int id) {
    try {
        kerionGL::Window window(800, 600, "KerionGL Window " + std::to_string(id));
        window.makeContextCurrent();
        std::cout << "Window " << id << " created." << std::endl;
        // Simulate some work with the window
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } catch (const std::exception& e) {
        std::cerr << "Error in window " << id << ": " << e.what() << std::endl;
    }
}

int main() {
    const int numThreads = 10;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(createAndDestroyWindow, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All windows created and destroyed successfully." << std::endl;
    return 0;
}