#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

const std::string filename = "assets/ada-lovelace.jpeg";
const std::string windowName = "Preview";

int main()
{
    
    cv::Mat image;
    image = cv::imread(filename, cv::IMREAD_COLOR);

    if (!image.data)
    {
        std::cerr << "Failed to load image: " << filename << std::endl;
        return -1;
    }

    cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
    cv::imshow(windowName, image);

    cv::waitKey(0);
    
    return 0;
}