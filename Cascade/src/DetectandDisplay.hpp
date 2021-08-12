#include <iostream>
#include <opencv2/opencv.hpp>




cv::CascadeClassifier face_cascade;

void detect_and_display(cv::Mat frame)
{   int thickness = 2;
    std::string face_classifier = "src/haarcascade_frontalface_alt.xml";
    if(!face_cascade.load(face_classifier))
    {
        std::cout << "--Error loading cascade classifier!." << std::endl;
    }
    cv::Mat gray_frame;
    cv::cvtColor(frame,gray_frame,cv::COLOR_BGR2GRAY);

    std::vector<cv::Rect> faces;
    
    face_cascade.detectMultiScale(gray_frame, faces, 1.1, 4);
    for (size_t i = 0; i < faces.size(); i++)
    {
        cv::rectangle(frame, cv::Point(faces[i].x,faces[i].y), cv::Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),cv::Scalar(0,255,0), thickness);
        

    }
    cv::imshow("Faces", frame);

}