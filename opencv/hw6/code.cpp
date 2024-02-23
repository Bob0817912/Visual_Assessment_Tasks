#include<opencv2/opencv.hpp>
using namespace cv;

int main() {
    VideoCapture cap;
    cap.open(0);
    Mat src;
    while(true){
        cap >> src;
        imshow("video",src);
        if (waitKey(30) == 'q'){
            break;
        }
    }
    cap.release();
    destroyAllWindows;
    return 0;
}