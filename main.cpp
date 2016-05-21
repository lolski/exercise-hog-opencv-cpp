#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include "convolution.h"
#include "hog.h"
#include "image.h"
#include "Setting.h"
#include "util.h"

using convolution::a;
using convolution::convolute;
using cv::Mat;
using cv::Size;
using image::extract;
using image::read;
using image::save;
using image::dimension;
using image::toGrayscale;
using std::cout;
using std::endl;
using std::string;
using hog::computeHog;
using hog::visualizeHog;
using util::copy;
using util::toString;

void save_single_frame() {
  Setting conf("application.cfg");
  string base = conf.getString("application.res_dir");
  string vid1 = base + "/cities/Travel by Drone- Gang Depot Es, Pasar Minggu, Jakarta 12560, Indonesia (1-59).mp4";
  Mat img  = extract(vid1, 1659);
  save(img, base + "/out.jpg");
}

void find_in_image() {
	Setting conf("application.cfg");
	string base = conf.getString("application.res_dir");
	Mat haystack = read(base + "/car_features/01.jpg");
	Mat needle = toGrayscale(imread(base + "/car_features/01.jpg"));
	Mat needle64x128;
	cv::resize(needle, needle64x128, Size(64, 128));

	vector<float> hog = computeHog(needle64x128);

	cout << hog.size() << endl;

	Mat visual = visualizeHog(needle64x128, hog, Size(64, 128));
	save(visual, base + "/car_features/01-visual.jpg");
}

void copy_image() {
	Setting conf("application.cfg");
	string base = conf.getString("application.res_dir");
	Mat original = read(base + "/car_features/01.jpg");
	Mat copy_ = copy(original);
	save(copy_, base + "/car_features/01-copy.jpg");
}

void convolute_image() {
//	Mat m(3, 3, CV_8U);
//	cout << a(-1, 3) << ", " << a(0, 3) << ", " << a(2, 3) << ", " <<
//					a(4, 3) << endl;

	Setting conf("application.cfg");
	string base = conf.getString("application.res_dir");
	Mat original = read(base + "/cities/out.jpg");
	cout << "1" <<endl;
	Mat identity = Mat::zeros(3, 3, CV_8UC3);;

	cout << "2" <<endl;
	Mat convoluted = convolute(original, identity);
	cout << "3" <<endl;
	save(convoluted, base + "/cities/out-conv.jpg");
	cout << "4" <<endl;
}

int main() {
//	save_single_frame();
//	find_in_image();
	convolute_image();
	return 0;
}
