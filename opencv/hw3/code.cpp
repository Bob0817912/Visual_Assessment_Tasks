#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
    Mat src = cv::imread("/home/jiang/桌面/hw/Assessment_winter/opencv/hw3/img.png",0);
    imshow("src",src);
    Mat thr,labels,stats,centroids,img;
    threshold(src,thr,100,255,THRESH_BINARY_INV);
    img = cv::imread("/home/jiang/桌面/hw/Assessment_winter/opencv/hw3/img.png",1);
    int num = connectedComponentsWithStats(thr,labels,stats,centroids);
    for(int i = 1;i < num;++i){
        Rect rect(
            stats.at<int>(i,CC_STAT_LEFT),
            stats.at<int>(i,CC_STAT_TOP),
            stats.at<int>(i,CC_STAT_WIDTH),
            stats.at<int>(i,CC_STAT_HEIGHT)
        );
        rectangle(img,rect,Scalar(0,0,0),2);
        putText(img,to_string(i),Point(stats.at<int>(i,CC_STAT_LEFT),stats.at<int>(i,CC_STAT_TOP)+20),FONT_HERSHEY_SIMPLEX,1,Scalar(0,0,0),2);
    }
    char text[10];
    sprintf(text,"%s%d","Total:",num-1);
    putText(img,text,Point(10,30),FONT_HERSHEY_SIMPLEX,1,Scalar(0,0,0),2);
    imshow("dst",img);
    waitKey(0);
    return 0;
}