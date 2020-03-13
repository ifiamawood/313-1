// 313 1.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include "stdafx.h"
#include<opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);
	double scale = 0.5;
	double i_minH = 0, i_maxH = 20, i_minS = 43, i_maxS = 255, i_minV = 55, i_maxV = 255;
	while (1) {
		Mat frame;
		Mat hsvMat;
		Mat detectMat;
		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);
		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);
		rFrame.copyTo(detectMat);
			cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);
		imshow("whie:in the range", detectMat);
		imshow("frame", rFrame);
		waitKey(30);
	}

    return 0;
}

