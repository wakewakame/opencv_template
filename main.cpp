#include "opencv2/opencv.hpp"
#include "empty.h"

int main()
{
	cv::Mat image = cv::Mat(256, 512, CV_8UC3);

	for (int i = 0; i < image.size().height; i++) {
		for (int j = 0; j < image.size().width; j++) {
			image.at<cv::Vec3b>(i, j)[0] = 255 * i / image.size().height;
			image.at<cv::Vec3b>(i, j)[1] = 0;
			image.at<cv::Vec3b>(i, j)[2] = 255 * j / image.size().width;
		}
	}

	cv::imshow("result", image);
	cv::waitKey(0);

	return 0;
}
