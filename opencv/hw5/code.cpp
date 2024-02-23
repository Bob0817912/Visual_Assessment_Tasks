#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
    Mat src = cv::imread("/home/jiang/桌面/hw/Assessment_winter/opencv/hw5/img.png",1);
    imshow("src",src);
    Mat hsv,img;
    cvtColor(src,hsv,COLOR_BGR2HSV);
    imshow("hsv",hsv);
    vector<Mat> channels;
    split(hsv,channels);
    channels[2]=255;
    merge(channels,hsv);
    imshow("change",hsv);
    waitKey(0);
    return 0;
}