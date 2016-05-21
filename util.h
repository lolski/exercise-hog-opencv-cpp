//
// Created by Ganeshwara Putra on 5/1/16.
//

#ifndef HELLO_OPENCV_CPP_UTIL_H
#define HELLO_OPENCV_CPP_UTIL_H

#include <opencv/cv.h>

using cv::Mat;
using cv::Vec3b;
using std::string;
using std::stringstream;
using std::vector;

namespace util {
	string toString(const Vec3b v) {
		stringstream accumulator;

		accumulator << "Vec3b(" << (int)v[0] << ", " << (int)v[1] << ", " << (int)v[2];

		return accumulator.str();
	}
	string toString(const vector<float>& v) {
		stringstream accumulator;

		for (auto it = v.begin(); it != v.end(); ++it)  {
			accumulator << (*it);
		}

		return accumulator.str();
	}

	// caveat: this method needs to call result.at<T> differently, according to the value returned by orig.type()
	Mat copy(Mat& orig) {
		if (orig.type() != CV_8UC3) throw std::runtime_error("orig must be of type CV_8UC3");

		Mat result(orig.rows, orig.cols, orig.type());
		for (int row = 0; row < result.rows; ++row) {
			for (int col = 0; col < result.cols; ++col) {
				result.at<uint>(row, col) = orig.at<uint>(row, col);
			}
		}
		return result;
	}

}

#endif //HELLO_OPENCV_CPP_UTIL_H
