//
// Created by Ganeshwara Putra on 5/1/16.
//

#ifndef HELLO_OPENCV_CPP_IMAGE_H
#define HELLO_OPENCV_CPP_IMAGE_H


#include <opencv/cv.h>
#include <opencv2/opencv.hpp>

using cv::CAP_PROP_POS_FRAMES;
using cv::COLOR_BGR2GRAY;
using cv::HOGDescriptor;
using cv::imread;
using cv::imwrite;
using cv::Mat;
using cv::Size;
using cv::VideoCapture;
using std::string;

namespace image {
	Mat read(const string& path) {
		Mat res = imread(path);
		return res;
	}

	void save(const Mat& in, const string& out) {
		imwrite(out, in);
		return;
	}

	Mat toGrayscale(const Mat& img) {
		Mat grey(img.rows, img.cols, CV_8U);
		cvtColor(img, grey, COLOR_BGR2GRAY, 1);
		return grey;
	}

	Mat extract(VideoCapture& vid, long frame) {
		Mat img;
		vid.set(CAP_PROP_POS_FRAMES, frame);
		vid.read(img);
		return img;
	}

	Mat extract(const string& vidFile, long frame) {
		VideoCapture vid(vidFile);
		auto img = extract(vid, frame);
		return img;
	}

	Size dimension(const Mat &img) {
		auto sz = Size(img.cols, img.rows);
		return sz;
	}

	Size size(const string& path) {
		auto img = read(path);
		auto sz = dimension(img);
		return sz;
	}
}

#endif //HELLO_OPENCV_CPP_IMAGE_H
