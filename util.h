//
// Created by Ganeshwara Putra on 5/1/16.
//

#ifndef HELLO_OPENCV_CPP_UTIL_H
#define HELLO_OPENCV_CPP_UTIL_H

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
}

#endif //HELLO_OPENCV_CPP_UTIL_H
