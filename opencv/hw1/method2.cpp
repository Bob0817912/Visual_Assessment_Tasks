#include<opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat src = cv::imread("/home/jiang/桌面/hw/Assessment_winter/opencv/hw1/img.jpg",0);
    int Rows = src.rows;
    int Cols = src.cols;
    imshow("src",src);
    uchar *p;
    int standard = 100;
    for(int i=0;i<Rows;i++){
        p = src.ptr<uchar>(i);
        for(int j = 0;j < Cols;j++){
            if(p[j] > standard){
                p[j] = 255;
            }
            else 
                p[j] = 0;
        }
    }
    imshow("dst",src);
    waitKey(0);
    return 0;
}    