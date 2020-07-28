#include <iostream>
#include <chrono>
#include <thread>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

int main(int, char**) {
    cv::VideoCapture cap;
    cap.open(0);

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

    cv::namedWindow("Preview", cv::WINDOW_AUTOSIZE);
    cv::imshow("Preview", frameReference);

    cv::waitKey(0);
    return 0;
}
