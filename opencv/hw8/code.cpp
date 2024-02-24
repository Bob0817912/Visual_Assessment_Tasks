#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

double distance(Point pt1,Point pt2){
	return sqrt((pt2.x - pt1.x)*(pt2.x - pt1.x)+(pt2.y - pt1.y)*(pt2.y - pt1.y));
}

int main() {
    Mat src = cv::imread("/home/jiang/桌面/hw/Assessment_winter/opencv/hw8/src.jpg",0);
    Mat kernel;
    kernel = getStructuringElement(MORPH_RECT,Size(5,5));
    resize(src,src,Size(0,0),0.2,0.2,INTER_LINEAR);
    imshow("src",src);
    Mat thr;
    threshold(src,thr,150,255,THRESH_BINARY);
    morphologyEx(thr,thr,MORPH_OPEN,kernel);
    imshow("thr",thr);
    vector<vector<Point>> contours;
    findContours(thr, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);    
    vector<vector<Point>>conPoly(contours.size());
	vector<Point>srcPts;
	for (int i = 0; i < contours.size(); i++){
		double area = contourArea(contours[i]);
		if (area > 10000){
			double peri = arcLength(contours[i],true);
			approxPolyDP(contours[i],conPoly[i],0.02*peri, true);
			srcPts = { conPoly[i][0],conPoly[i][1],conPoly[i][2],conPoly[i][3]};
		}
	}
    int x = src.cols / 2;
	int y = src.rows / 2;
	int TL,TR,BR,BL;
	for (int i = 0; i < srcPts.size(); i++){
		if (srcPts[i].x < x && srcPts[i].y < y) TL = i;
		if (srcPts[i].x > x && srcPts[i].y < y) TR = i;
		if (srcPts[i].x > x && srcPts[i].y > y) BR = i;
		if (srcPts[i].x < x && srcPts[i].y > y) BL = i;
	}
    double UpWidth = distance(srcPts[TL], srcPts[TR]);
	double DownWidth = distance(srcPts[BL], srcPts[BR]);
	double MaxWidth = max(UpWidth, DownWidth);
    double LeftHeight = distance(srcPts[TL], srcPts[BL]);
	double RightHeight = distance(srcPts[TR], srcPts[BR]);
	double MaxHeight = max(LeftHeight, RightHeight);
	Point2f SrcAffinePts[4] = { Point2f(srcPts[TL]),Point2f(srcPts[TR]) ,Point2f(srcPts[BR]) ,Point2f(srcPts[BL]) };
	Point2f DstAffinePts[4] = { Point2f(0,0),Point2f(MaxWidth,0),Point2f(MaxWidth,MaxHeight),Point2f(0,MaxHeight) };
	Mat M = getPerspectiveTransform(SrcAffinePts, DstAffinePts);
	Mat DstImg;
	warpPerspective(src, DstImg, M, Point(MaxWidth, MaxHeight));
	imshow("Dst", DstImg);
	waitKey(0);
	return 0;
}