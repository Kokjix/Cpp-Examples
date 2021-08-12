#include <iostream>
#include <opencv2/opencv.hpp>




int main(int argc, char const *argv[])
{
    cv::Mat live_frame, edges;
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
            Canny(live_frame,edges,100,200);
            cv::namedWindow("Edges", cv::WINDOW_AUTOSIZE);
            cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
            cv::imshow("Edges", edges);
            cv::imshow("Display Image", live_frame);
            if (cv::waitKey(25) >= 0)
            {
                break;
            }   
        }
        
    }
    
    return 0;
}

