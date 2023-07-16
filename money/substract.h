#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void substract()
{
	Mat im = imread("500k.jpg", IMREAD_COLOR);
	Mat im2 = imread("rotateBack.jpg", IMREAD_COLOR);
	///*cout << "im size: " << im.size() << endl;
	//cout << "im2 size: " << im2.size() << endl;*/
	resize(im2, im2, im.size());
	Mat subtracted;
	subtract(im2, im, subtracted);
	imshow("subtracted", subtracted);



	Mat image = imread("500k.jpg", IMREAD_GRAYSCALE);
	Mat image2 = imread("rotateBack.jpg", IMREAD_GRAYSCALE);
	resize(image2, image2, image.size());
	Mat subtracted2;
	subtract(image2, image, subtracted2);

	Mat binaryImg;
	threshold(subtracted2, binaryImg, 30, 255, THRESH_BINARY);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	erode(binaryImg, binaryImg, kernel);
	dilate(binaryImg, binaryImg, kernel);

	vector<vector<Point>> contours;
	findContours(binaryImg, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	// ve hinh quanh vien
	for (int i = 0; i < contours.size(); i++)
	{
		Rect bbox = boundingRect(contours[i]);
		rectangle(image2, bbox, Scalar(0, 0, 25), 0.1);
	}

	imshow("zoneOD", image2);
	waitKey(0);
}