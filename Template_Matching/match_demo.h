#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;
Point getNextLoaction(Mat &result,double &maxValue, Point &maxLoc, int temp_width, int temp_height);//获取下一个匹配点
Mat CalculateNcc(Mat src, Mat temp);//计算ncc中的result
/*
缺少个寻找金字塔匹配的最佳层数getOptimalLevels();
*/
int getOptimalLevels(Mat temp);
//金字塔加速的匹配，返回超过阈值的所有点
vector<Point> pyramidMatch(Mat src, Mat temp, int nLevels,double thresh);
/*
1.这里暂时只定义单独的数据类型Point 后续可以自定义struct更改vector当中的类型，在绘制时候应该包含角度信息或者模板尺度信息
*/
void DrawMatchResult(vector<Point> pt,Mat display,int width,int height);
vector<Mat> pyramidImg(Mat src, int nLevels);//计算图像的金字塔
/*
这里后续可以更改一下贪婪度，随着层度的升高对阈值可以降低
*/
vector<Point> getMulMatchPoint(Mat &result, double thresh,int temp_width,int temp_height);//获取每层大于阈值的最佳匹配点
//计算匹配的点的下层附近区域点的ncc,找到满足该层阈值的点的集合
vector<Point> SearchArea(vector<Point> pt, Size area,int level,double thresh, Mat pyr_src, Mat pyr_temp);