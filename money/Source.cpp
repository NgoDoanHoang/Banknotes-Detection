#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>
#include "rotate.h"
#include "showOrigin.h"
#include "angle.h"
#include "substract.h"
#include "gaussianFilter.h"

using namespace cv;
using namespace std;


int main()
{	
	//showOrigin();			//xem 2 anh ban dau
	gaussian();				//loc guass
	angle();				//tinh goc lech va xoay lai (tao 1 anh moi la kq xoay)
	substract();			//tru 2 anh de tim vet ban, khoanh vung vet ban

	return 0;
}
