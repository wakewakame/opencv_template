#include "opencv2/opencv.hpp"

int main()
{
	cv::Mat image = cv::imread("test.png");
	cv::imshow("result", image);
	cv::waitKey(0);
	return 0;
}
