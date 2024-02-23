#include<opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat src;
    src = imread("/home/jiang/桌面/hw/Assessment_winter/opencv/hw7/img1.png",0);
    imshow("src",src);
    Mat gama;
    float gamma = 2.2;
    gama.create(src.size(),src.type());
    int height = src.rows;
    int width = src.cols;
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            float gray = src.at<uchar>(i,j);
            gray = (gray + 0.5) / 256;
            gray = pow(gray,1/gamma);
            gama.at<uchar>(i,j) =(int)(gray * 256 -0.5);
        }
    }
    imshow("dst",gama);
    waitKey(0);
    return 0;
}