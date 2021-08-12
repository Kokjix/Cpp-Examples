#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char** argv )
{
    Mat image, detected_edges;
    image = imread("img/lena.jpg", 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    Canny(image,detected_edges,100,200);
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Edges", detected_edges);
    waitKey(0);
    return 0;
}