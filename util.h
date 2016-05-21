//
// Created by Ganeshwara Putra on 5/1/16.
//

#ifndef HELLO_OPENCV_CPP_UTIL_H
#define HELLO_OPENCV_CPP_UTIL_H

#include <opencv/cv.h>

using cv::Mat;
using std::string;
using std::stringstream;
using std::vector;

namespace util {
	string toString(const vector<float>& v) {
		stringstream accumulator;

		for (auto it = v.begin(); it != v.end(); ++it)  {
			accumulator << (*it);
		}

		return accumulator.str();
	}

	// caveat: this method needs to call result.at<T> differently, according to the value returned by orig.type()
	Mat copy(Mat& orig) {
		Mat result(orig.rows, orig.cols, orig.type());
		int row, col;
		for (row = 0; row < result.rows; ++row) {
			for (col = 0; col < result.cols; ++col) {
				result.at<int>(row, col) = orig.at<int>(row, col);
			}
		}
		return result;
	}


}

#endif //HELLO_OPENCV_CPP_UTIL_H
