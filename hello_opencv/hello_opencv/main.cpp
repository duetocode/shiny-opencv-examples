//
//  main.cpp
//  hello_opencv
//
//  Created by Zhao Liang on 2020/7/28.
//  Copyright © 2020 Rocinante. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
        
    cv::Mat image;
    image = cv::imread("assets/ada-lovelace.jpeg", cv::IMREAD_COLOR);
    
    if (!image.data)
    {
        std::cerr << "Failed to load the image" << std::endl;
        return -1;
    }
    
    cv::namedWindow("Image Preview");
    cv::imshow("Image Preview", image);
    
    cv::waitKey(0);
    
    return 0;
}
