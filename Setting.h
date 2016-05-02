//
// Created by Ganeshwara Putra on 5/1/16.
//

#ifndef HELLO_OPENCV_CPP_SETTING_H
#define HELLO_OPENCV_CPP_SETTING_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using std::string;

class Setting {
	ptree pt;
public:
	Setting(const string& file) {
		read_json(file, pt);
	}

	~Setting() {
		// TODO: call pt.clear()?
	}

	string getString(const string &conf) {
		return pt.get<string>(conf);
	}
};

#endif //HELLO_OPENCV_CPP_SETTING_H
