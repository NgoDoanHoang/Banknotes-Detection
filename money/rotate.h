#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void rotate(Mat img, double angle)
{
	Mat image;
	double scale = 1.0;
	Mat rotMat = getRotationMatrix2D(Point2f(img.cols / 2, img.rows / 2), angle, scale);

	// Calculate the size of the output image
	Rect bbox = RotatedRect(Point2f(), img.size(), angle).boundingRect();
	rotMat.at<double>(0, 2) += bbox.width / 2.0 - img.cols / 2.0;
	rotMat.at<double>(1, 2) += bbox.height / 2.0 - img.rows / 2.0;

	warpAffine(img, image, rotMat, bbox.size());

	imwrite("rotateBack.jpg", image);
	imshow("rotateBack", image);
}
