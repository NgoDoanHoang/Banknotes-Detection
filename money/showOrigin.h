#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void showOrigin()
{
	Mat origin = imread("500k.jpg", IMREAD_COLOR);
	Mat modify = imread("noisy_500k.jpg", IMREAD_COLOR);
	imshow("origin", origin);
	imshow("inked", modify);
}
