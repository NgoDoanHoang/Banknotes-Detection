#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;


void angle()
{
	Mat img1 = imread("500k.jpg", IMREAD_COLOR);
	Mat img2 = imread("500k_afterGF.jpg", IMREAD_COLOR);

	// Detect keypoints and compute descriptors
	Ptr<AKAZE> detector = AKAZE::create();

	vector<KeyPoint> keypoints1, keypoints2;
	Mat descriptors1, descriptors2;

	detector->detectAndCompute(img1, noArray(), keypoints1, descriptors1);
	detector->detectAndCompute(img2, noArray(), keypoints2, descriptors2);

	// Match descriptors using brute force matcher
	Ptr<BFMatcher> matcher = BFMatcher::create(NORM_HAMMING);

	vector<DMatch> matches;
	matcher->match(descriptors1, descriptors2, matches);

	// Find homography between matched keypoints
	vector<Point2f> matchedPoints1, matchedPoints2;
	for (int i = 0; i < matches.size(); i++)
	{
		matchedPoints1.push_back(keypoints1[matches[i].queryIdx].pt);
		matchedPoints2.push_back(keypoints2[matches[i].trainIdx].pt);
	}

	Mat H = findHomography(matchedPoints2, matchedPoints1, RANSAC);

	// Compute rotation angle from homography
	double angle = atan2(H.at<double>(1, 0), H.at<double>(0, 0)) * 180.0 / CV_PI;

	cout << "Goc lech so voi anh mac dinh: " << angle;

	rotate(img2, (-1) * angle);
}