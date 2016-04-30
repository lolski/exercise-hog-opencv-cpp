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
using std::vector;

namespace svm {
	vector<float> computeHog(Mat img, Size winSize, Size blockSize,
	                         Size blockStride, Size cellSize,
	                         int nbins, Size winStride, Size padding) {
		HOGDescriptor hog(winSize, blockSize, blockStride, cellSize, nbins);
		vector<float> descriptor;
		hog.compute(img, descriptor, winStride, padding);
		return descriptor;
	}
}


#endif //HELLO_OPENCV_CPP_SVM_H
