#include <iostream>
#include <opencv2/opencv.hpp> // import OpenCV Header file



void sobel_and_display(cv::Mat src) // sobel_and_display function
{   int WIDTH, HEIGHT; // frame width and height variables
    WIDTH = 640;
    HEIGHT = 480;
    cv::Mat frame, gray_frame; // frame and gray_frame declaration

    cv::namedWindow("Original Image", CV_WINDOW_NORMAL); // create "Original Image" window created with CV_WINDOW_NORMAL therefore window can be resizable 
    cv::resizeWindow("Original Image", WIDTH, HEIGHT); // resize frame
    cv::imshow("Original Image",src); // show original frame
    cv::GaussianBlur(src,frame, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT); // make gaussian blur filter
    cv::cvtColor(frame,gray_frame,cv::COLOR_BGR2GRAY); // make gray filter on image
    cv::Mat sobely; // sobely gradiant
    cv::Sobel(gray_frame, sobely, -CV_16U, 0, 1,5); //get frames sobely gradient //-CV_16U veya -CV_64F beğenildi.

    double min_value, max_value; // max and min value for sobel filter
    cv::minMaxLoc(sobely, &min_value, &max_value); // Sobel Y filter
    std::cout << "Min value: " << min_value << " Max value: " << max_value << std::endl; // print max and min value

    cv::Mat draw; // draw matrix
    sobely.convertTo(draw, CV_8U, 255.0/(max_value - min_value), -min_value * 255.0/(max_value - min_value)); // convert sobel matrix to draw matrix
    
    cv::namedWindow("Sobel Y", CV_WINDOW_NORMAL); // create "Sobel Y" window created with CV_WINDOW_NORMAL therefore window can be resizable 
    cv::resizeWindow("Sobel Y", WIDTH, HEIGHT); // resize frame
    cv::imshow("Sobel Y", draw); // show original frame

}