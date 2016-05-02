#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include "image.h"
#include "Setting.h"
#include "util.h"
#include "svm.h"

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
using svm::computeHog;
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
	Mat needle = toGrayscale(cv::imread(base + "/car_features/01.jpg"));
	Mat needle64x128;
	cv::resize(needle, needle64x128, Size(64, 128));

	vector<float> hog = computeHog(needle64x128);

	cout << hog.size() << endl;
}

int main() {
//	save_single_frame();
	find_in_image();
	return 0;
}
