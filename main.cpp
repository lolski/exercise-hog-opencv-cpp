#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include "image.h"
#include "util.h"
#include "svm.h"

using cv::Mat;
using cv::Size;
using image::toGrayscale;
using image::save;
using image::extract;
using std::cout;
using std::endl;
using std::string;
using svm::computeHog;

int main() {
  string base = "/Users/lolski/Playground/hello-opencv-cpp/res/cities"; // 1:11
  string vid1 = base + "/Travel by Drone- Gang Depot Es, Pasar Minggu, Jakarta 12560, Indonesia (1-59).mp4";
  cv::Mat img  = extract(vid1, 1659);
  cv::Mat gray = toGrayscale(img);
  auto res = computeHog(gray, Size(32, 16), Size(8, 8), Size(4, 4), Size(4, 4), 9, Size(0, 0), Size(0, 0));
  cout << res.size() << endl;
  save(img, base + "/out.jpg");
  return 0;
}