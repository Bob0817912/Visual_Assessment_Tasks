#include<opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat src = cv::imread("/home/jiang/桌面/hw/Assessment_winter/opencv/hw1/img.jpg",0);
    int Rows = src.rows;
    int Cols = src.cols;
    imshow("src",src);
    int standard = 100;
    for(int i = 0;i < Rows;i++){
        for(int j = 0;j < Cols;j++){
            if(src.at<uchar>(i,j) > standard){
                src.at<uchar>(i,j) = 255;
            }
            else
                src.at<uchar>(i,j) = 0;
        }
    }
    imshow("dst",src);
    waitKey(0);
    return 0;
}