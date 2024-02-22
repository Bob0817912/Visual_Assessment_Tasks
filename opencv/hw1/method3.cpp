#include<opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat src = cv::imread("/home/jiang/桌面/hw/Assessment_winter/opencv/hw1/img.jpg",0);
    imshow("src",src);
    MatIterator_<uchar>p,q;
    p=src.begin<uchar>();
    q=src.end<uchar>();
    int standard = 100;
    while(++p != q){
        if(*p > standard){
            *p = 255;
        }
        else *p = 0;
    }
    imshow("dst",src);
    waitKey(0);
    return 0;
}
