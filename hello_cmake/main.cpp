#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

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

    cv::Size size = image.size();

    std::cout << "Image" << std::endl;
    std::cout << "\tSize: " << size.width << "x" << size.height << std::endl;
    std::cout << "\tChannels: " << image.channels() << std::endl;
    
    return 0;
}
