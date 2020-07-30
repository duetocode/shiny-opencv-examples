#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>



int main(int, char**) {
    std::cout << "Hello, world!\n";

    int i = 0;
    std::mutex m;

    std::thread t([&]{
        while (i < 100)
        {
            {
                std::unique_lock<std::mutex> _m(m);
                i += 1;
                std::cout << i << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    while (i < 100)
    {
        {
            std::unique_lock<std::mutex> _m(m);
            i += 1;
            std::cout << i << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    t.join();

    return 0;
}
