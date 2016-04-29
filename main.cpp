#include <opencv/cv.h>
#include <opencv2/highgui.hpp>
#include <iostream>

cv::Mat read(const std::string& path);
void save(const cv::Mat& in, const std::string& out);
cv::Mat extract(const std::string& vidFile, long frame);
cv::Mat extract(cv::VideoCapture& vid, long frame);

int main() {
    std::string base = "/Users/ganeshwara/Downloads/cities/"; // 1:11
    std::string vid1 = base + "/Travel by Drone- Gang Depot Es, Pasar Minggu, Jakarta 12560, Indonesia (1-59).mp4";
    cv::Mat img = extract(vid1, 1659);
    save(img, base + "/out.jpg");

    return 0;
}

cv::Mat read(const std::string& path) {
    cv::Mat res = cv::imread(path);
    return res;
}

void save(const cv::Mat& in, const std::string& out) {
    cv::imwrite(out, in);
    return;
}

cv::Mat extract(const std::string& vidFile, long frame) {
    cv::VideoCapture vid(vidFile);
    cv::Mat img = extract(vid, frame);
    return img;
}

cv::Mat extract(cv::VideoCapture& vid, long frame) {
    cv::Mat img;
    vid.set(cv::CAP_PROP_POS_FRAMES, frame);
    vid.read(img);
    return img;
}