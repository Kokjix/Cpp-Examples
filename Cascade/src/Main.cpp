#include <iostream>
#include <opencv2/opencv.hpp>
#include "DetectandDisplay.hpp"



int main(int argc, char const *argv[])
{
    cv::Mat live_frame;
    cv::VideoCapture cap;
    int deviceID = 0;            
    int apiID = cv::CAP_ANY;
    cap.open(deviceID,apiID);

    if(!cap.isOpened())
    {
        std::cout << "Unable to open camera." << std::endl;
        return -1;
    }
    std::cout << "Capturing the image..." << std::endl;
    
    while(cap.isOpened())
    {
        cap.read(live_frame);
        if(live_frame.empty())
        {
            std::cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        
        while (cap.read(live_frame))
        {
            detect_and_display(live_frame);
            if (cv::waitKey(25) >= 0)
            {
                break;
            }    
            
        }
    }
    return 0;
}
