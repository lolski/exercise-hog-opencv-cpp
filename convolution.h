//
// Created by Ganeshwara Putra on 5/21/16.
//

#ifndef HELLO_OPENCV_CPP_CONVOLUTION_H
#define HELLO_OPENCV_CPP_CONVOLUTION_H

#include <opencv/cv.h>

namespace convolution {
	using cv::Mat;

	int a(int original, int count) {
		int extended;
		if (original < 0) extended = 0; // top edge
		else if (original > count - 1) extended = count - 1; // bottom edge
		else extended = original;

		return extended;
	}

	uint convolutePixel(Mat original, Mat kernel, int rorig, int corig) {
		auto rhalved = (kernel.rows-1 / 2);
		auto chalved = (kernel.cols-1 / 2);

		auto rfrom = rorig - rhalved;
		auto rto   = rorig + rhalved;
		auto cfrom = corig - chalved;
		auto cto   = corig + chalved;

		uint accum = 0;
		for (int i = rfrom; i <= rto; ++i) {
			for (int j = cfrom; j <= cto; ++j) {
				int row = a(rorig, original.rows);
				int col = a(corig, original.cols);
				auto res = original.at<uint>(row, col) * kernel.at<uint>(row, col);
				accum += res;
			}
		}

		return accum;
	}

	Mat convolute(Mat orig, Mat kernel) {
		if (orig.type() != CV_8UC3) throw std::runtime_error("orig must be of type CV_8UC3");

		Mat result(orig.rows, orig.cols, orig.type());
		for (int row = 0; row < result.rows; ++row) {
			for (int col = 0; col < result.cols; ++col) {
				result.at<uint>(row, col) = convolutePixel(orig, kernel, row, col);
			}
		}
		std::cout<< "finished" << std::endl;

		return result;
	}
}

#endif //HELLO_OPENCV_CPP_CONVOLUTION_H
