#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
    Mat src = cv::imread("/home/jiang/桌面/hw/Assessment_winter/opencv/hw4/img.png",0);
    Mat dil,ero,open,close,kernel;
    kernel = getStructuringElement(MORPH_RECT,Size(5,5));
    dilate(src,dil,kernel);
    erode(src,ero,kernel);
    morphologyEx(src,open,MORPH_OPEN,kernel);
    morphologyEx(src,close,MORPH_CLOSE,kernel);
    imshow("src",src);
    imshow("dilate",dil);
    imshow("erode",ero);
    imshow("open",open);
    imshow("close",close);
    waitKey(0);
    return 0;
}