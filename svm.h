//
// Created by Ganeshwara Putra on 5/1/16.
//

#ifndef HELLO_OPENCV_CPP_SVM_H
#define HELLO_OPENCV_CPP_SVM_H

#include <opencv/cv.h>
#include <opencv2/opencv.hpp>

using cv::HOGDescriptor;
using cv::Mat;
using cv::Size;
using image::dimension;
using std::vector;

namespace svm {
	bool minimumDimensionSatisfied(const Mat &img) {
		auto sz = dimension(img);
		return (sz.width >= 64 && sz.height >= 128);
	}

	// TODO: this function does not work yet
	vector<float> computeHog(Mat img, const Size& winSize, const Size& blockSize,
	                         const Size& blockStride, const Size& cellSize,
	                         int nbins, const Size& winStride, const Size& padding) {
		HOGDescriptor hog(winSize, blockSize, blockStride, cellSize, nbins);
		vector<float> descriptor;
		hog.compute(img, descriptor, winStride, padding);
		return descriptor;
	}

	vector<float> computeHog(Mat img) {
		assert(minimumDimensionSatisfied(img));

		HOGDescriptor hog;
		vector<float> descriptor;
		hog.compute(img, descriptor);
		return descriptor;
	}
}


#endif //HELLO_OPENCV_CPP_SVM_H
