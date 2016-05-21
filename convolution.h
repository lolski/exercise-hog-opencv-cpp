//
// Created by Ganeshwara Putra on 5/21/16.
//

#ifndef HELLO_OPENCV_CPP_CONVOLUTION_H
#define HELLO_OPENCV_CPP_CONVOLUTION_H

#include <opencv/cv.h>
#include "util.h"

namespace convolution {
	using cv::Mat;
	using cv::Vec3b;
	using std::cout;
	using std::endl;

	int bound(int original, int count) {
		int extended;
		if (original < 0) extended = 0; // top edge
		else if (original > count - 1) extended = count - 1; // bottom edge
		else extended = original;

		return extended;
	}

	Vec3b convolutePixel(Mat original, Mat kernel, int rorig, int corig) {
		if (original.type() != CV_8UC3 && kernel.type() != CV_32F) throw std::runtime_error("original and kernel must be of type CV_8UC3 and CV_32F");

		Vec3b accumulator(0, 0, 0);

		int hrkern = (kernel.rows-1) / 2;
		int hckern = (kernel.cols-1) / 2;

//		cout << "orig(" << rorig << "," << corig << ") = ";

		for (int rkern = 0; rkern < kernel.rows; ++rkern) {
			for (int ckern = 0; ckern < kernel.cols; ++ckern) {
				int rdelta = bound(rorig-hrkern+rkern, original.rows);
				int cdelta = bound(corig-hckern+ckern, original.cols);
//				cout << "(kern(" << rkern << "," << ckern << ") * ";
//				cout <<  "orig(" << rdelta << ", " << cdelta << ") + ";

				Vec3b vorig = original.at<Vec3b>(rdelta, cdelta);
				float vkern = kernel.at<float>(rkern, ckern);

				accumulator[0] += (uchar)(vorig[0] * vkern);
				accumulator[1] += (uchar)(vorig[1] * vkern);
				accumulator[2] += (uchar)(vorig[2] * vkern);
			}
		}

//		cout << endl;

		return accumulator;
	}

	Mat convolute(Mat original, Mat kernel) {
		if (original.type() != CV_8UC3) throw std::runtime_error("orig must be of type CV_8UC3");

		Mat result(original.rows, original.cols, original.type());

		for (int row = 0; row < result.rows; ++row) {
			for (int col = 0; col < result.cols; ++col) {
				result.at<Vec3b>(row, col) = convolutePixel(original, kernel, row, col);
			}
		}

		return result;
	}
}

#endif //HELLO_OPENCV_CPP_CONVOLUTION_H
