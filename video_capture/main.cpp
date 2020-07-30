#include <iostream>
#include <chrono>
#include <thread>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>

int main(int, char**) {
    cv::VideoCapture cap;
    cap.open(0);

    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1920);

    if (!cap.isOpened())
    {
        std::cerr << "Failed to open camera" << std::endl;
        return -1;
    }

    std::cout << "Wait one seconds to let the camera warm up" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    cv::Mat frameReference;
    while (!cap.grab())
    {
        std::cout << '.';
    }
    std::cout << std::endl;

    cap >> frameReference;

    if (frameReference.empty())
    {
        std::cerr << "Failed to retrive the frame from camera" << std::endl;
        return -2;
    }

    cv::imwrite("capture.jpg", frameReference);
    
    return 0;
}
