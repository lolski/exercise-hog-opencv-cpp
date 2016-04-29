#include <opencv/cv.h>
#include <opencv2/opencv.hpp>

cv::Mat read(const std::string& path);
void save(const cv::Mat& in, const std::string& out);
cv::Mat extract(const std::string& vidFile, long frame);
cv::Mat extract(cv::VideoCapture& vid, long frame);
cv::Mat toGrayscale(const cv::Mat& img);
std::vector<float> computeHog(cv::Mat img, cv::Size winSize, cv::Size blockSize, cv::Size blockStride, cv::Size cellSize,
                              int nbins, cv::Size winStride, cv::Size padding);
std::string toString(const std::vector<float>& v);

int main() {
    std::string base = "/Users/ganeshwara/Downloads/cities/"; // 1:11
    std::string vid1 = base + "/Travel by Drone- Gang Depot Es, Pasar Minggu, Jakarta 12560, Indonesia (1-59).mp4";
    cv::Mat img  = extract(vid1, 1659);
    cv::Mat gray = toGrayscale(img);
    auto res = computeHog(gray, cv::Size(32, 16), cv::Size(8, 8), cv::Size(4, 4), cv::Size(4, 4), 9, cv::Size(0, 0), cv::Size(0, 0));
    std::cout << res.size() << std::endl;
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

cv::Mat toGrayscale(const cv::Mat& img) {
    cv::Mat grey(img.rows, img.cols, CV_8U);
    cv::cvtColor(img, grey, cv::COLOR_BGR2GRAY, 1);
    return grey;
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

std::vector<float> computeHog(cv::Mat img, cv::Size winSize, cv::Size blockSize, cv::Size blockStride, cv::Size cellSize,
                             int nbins, cv::Size winStride, cv::Size padding) {
    cv::HOGDescriptor hog(winSize, blockSize, blockStride, cellSize, nbins);
    std::vector<float> descriptor;
    hog.compute(img, descriptor, winStride, padding);
    return descriptor;
}

std::string toString(const std::vector<float>& v) {
    std::stringstream accumulator;

    for (auto it = v.begin(); it != v.end(); ++it)  {
        accumulator << (*it);
    }

    return accumulator.str();
}