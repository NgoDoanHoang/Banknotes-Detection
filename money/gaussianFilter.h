#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void gaussian()
{
	Mat img = imread("noisy_500k.jpg");
	int rows = img.rows;
	int cols = img.cols;

	for (int i = 0; i < rows; i++)
	{
		Vec3b* ptr = img.ptr<Vec3b>(i);
		for (int j = 0; j < cols; j++)
		{
			Vec3b pixel = ptr[j];
		}
	}
//	imshow("Truoc Gaussian Filter", img);

	Mat image_Gauss = img.clone();

	GaussianBlur(img, image_Gauss, Size(1.9, 1.9), 0, 0);


	for (int i = 0; i < rows; i++)
	{
		Vec3b* ptr = image_Gauss.ptr<Vec3b>(i);
		for (int j = 0; j < cols; j++)
		{
			Vec3b pixel = ptr[j];
		}
	}
//	imshow("Sau Gaussian Filter:", image_Gauss);
	imwrite("500k_afterGF.jpg", image_Gauss);

	waitKey(0);
}

