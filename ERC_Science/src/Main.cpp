#include <iostream>
#include <opencv2/opencv.hpp> // import OpenCV library.
#include "SobelandDisplay.hpp" // import Sobel display header


int main(int argc, char const *argv[])
{   std::string video = "src/videos/1.mp4"; // video frame path string 
    cv::VideoCapture cap(video); // video capture           

    std::cout << "Ready..." << std::endl; // print ready

    if(!cap.isOpened()) // check can OpenCV find video path file if not program terminated.
    {
        std::cout << "--Error unable to find video stream or file." << std::endl;
        return -1;
    }

    std::cout << "Capturing the video..." << std::endl;
    std::cout << "Video shown..." << std::endl;

    while (true)
    {
        cv::Mat frame; 
        cap >> frame; // over load frame
        if (frame.empty()) // check if frame is empty or not
        {
            break;
        }
        sobel_and_display(frame); // sobel filter and displaying frame.
        
        char c = (char)cv::waitKey(25); // When ESC key pressed program closed

        if(c == 27)
        {
            break;
        }
    }
    
    cap.release(); // cap release
    cv::destroyAllWindows(); // destroying all windows

    return 0;
}
