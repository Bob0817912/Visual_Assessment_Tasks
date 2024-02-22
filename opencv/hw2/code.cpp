#include<opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat src = cv::imread("/home/jiang/桌面/hw/Assessment_winter/opencv/hw2/img.jpg",0);
    Mat dst;
    Canny(src,dst,50,150);
    imshow("src",src);
    imshow("dst",dst);
    waitKey(0);
    return 0;
}