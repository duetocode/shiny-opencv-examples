#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

int main(int, char **)
{
    cv::VideoCapture cap;
    bool opened = cap.open(0, cv::CAP_AVFOUNDATION);
    cv::Size frameSize;
    int fps;

    if (opened)
    {
        cap.set(cv::CAP_PROP_FPS, 30);
        frameSize = cv::Size(cap.get(cv::CAP_PROP_FRAME_WIDTH), cap.get(cv::CAP_PROP_FRAME_HEIGHT));
        fps = cap.get(cv::CAP_PROP_FPS);
        std::cout << "Camera #0 has been successfully opened." << std::endl;
        std::cout << "\tFrame Size: "
                  << frameSize.width
                  << "x"
                  << frameSize.height
                  << std::endl;
        std::cout << "\tFPS: " << fps << std::endl;
    }
    else
    {
        std::cout << "Failed to open Camera #0." << std::endl;
        return -1;
    }

    cv::VideoWriter writer;
    opened = writer.open("appsrc ! videoconvert ! vtenc_h264_hw realtime=true max-keyframe-interval=30 ! queue ! mp4mux ! filesink location=sample.mp4",
                        cv::CAP_GSTREAMER,
                        0,
                        cap.get(cv::CAP_PROP_FPS),
                        frameSize);
    if (opened)
        std::cout << "Output file opened." << std::endl;
    else
    {
        std::cout << "Failed to open output file." << std::endl;
        return -2;
    }

    cv::Mat frame;
    for (int i = 0; i < fps * 5; i++)
    {
        cap >> frame;
        if (frame.empty()){
            std::cout << "Failed to capture frame." << std::endl;
            return -3;
        }

        writer << frame;
    }

    std::cout << "Job done." << std::endl;

    cap.release();
    writer.release();
    std::cout << "Bye" << std::endl;

    return 0;
}
