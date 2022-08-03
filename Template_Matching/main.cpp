#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include <math.h>
#include "match_demo.h"
/*
@@@@本项目期望实现基于ncc的多模板多角度的模板匹配，并且使用金字塔加速
1.当前实现多模板金字塔加速的匹配
*/
using namespace std;
using namespace cv;
int main()
{
	/*Mat src = imread("D:/opencv/pictures/num_src_4.png",0);
	Mat temp = imread("D:/opencv/pictures/num_4.png", 0);*/
	/*Mat src = imread("D:/opencv/pictures/2.jpg",0);
	Mat temp = imread("D:/opencv/pictures/2_temp.png", 0);*/
	Mat src = imread("D:/opencv/pictures/pcb_gray.png", 0);
	Mat temp = imread("D:/opencv/pictures/pcb_templ4.png", 0);
	/*Mat src = imread("D:/opencv/pictures/src_bear.png");
	Mat temp = imread("D:/opencv/pictures/temp_bear.png");*/
	/*Mat src = imread("D:/opencv/pictures/mask.png",0);
	Mat temp = imread("D:/opencv/pictures/mask_temp.png",0);*/
	//imshow("源图像", src);
	/*Mat PCB = imread("D:/opencv/pictures/PCB.jpeg");
	cvtColor(PCB, PCB, COLOR_BGR2GRAY);*/
	/*Rect rect(272, 962,2000 ,1850);
	Mat src1 = src(rect);*/
	//Mat templ = src(Rect(Point(1940, 1036),Point( 1987,1111)));
	imshow("模板图像", temp);
	//imshow("原图", src);
	Mat display = src.clone();//draw-matchrect
	//cvtColor(src, src, COLOR_BGR2GRAY);
	vector<Point> pt;
	int temp_width = temp.cols;
	int temp_height = temp.rows;
	int nLevels = 1;
	int maxnLevels = getOptimalLevels(temp);
	cout << "最大的金字塔层数"<<maxnLevels << endl;
	double thresh = 0.58;//bear：thresh 0.9,nLevels 2；

	cout << "start template_match with pyramid" << endl;
	int64 s_t = cv::getTickCount();
	pt = pyramidMatch(src, temp, nLevels, thresh);
	DrawMatchResult(pt, display, temp_width, temp_height);
	int64 e_t = cv::getTickCount();
	cout << "end match:" << "耗时" << double((e_t - s_t)*1000.0 / cv::getTickFrequency()) << "ms" << endl;
	imshow("display",display);
	waitKey(0);
	return 0;
}

