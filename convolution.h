//
// Created by Ganeshwara Putra on 5/21/16.
//

#ifndef HELLO_OPENCV_CPP_CONVOLUTION_H
#define HELLO_OPENCV_CPP_CONVOLUTION_H

#include <opencv/cv.h>

using cv::Mat;

Mat copy(Mat& orig) {
	assert(orig.type() != CV_8U);

	Mat result(orig.rows, orig.cols, CV_8U); // todo: if CV_8U always what we want?
	for (int row = 0; row < result.rows; ++row) {
		for (int col = 0; col < result.cols; ++col) {
			result.at<uchar>(col, row) = orig.at<uchar>(col, row);
		}
	}

	return result;
}

#endif //HELLO_OPENCV_CPP_CONVOLUTION_H
