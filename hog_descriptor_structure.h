//
// Created by Ganeshwara Putra on 6/9/16.
//

#ifndef HELLO_OPENCV_CPP_HOG_DESCRIPTOR_STRUCTURE_H
#define HELLO_OPENCV_CPP_HOG_DESCRIPTOR_STRUCTURE_H

#include <vector>

using std::vector;

template< typename T >
	using RowCell = vector< T >;

template< typename T >
	using ColumnCell = vector< T >;

class HogDescriptorStructure {
public:
	HogDescriptorStructure(int rowCellCount, int columnCellCount, vector<float> descriptor) {
		this->rowCellCount = rowCellCount;
		this->columnCellCount = columnCellCount;
		this->bins = openCvDescriptorTo(descriptor);
	}

	Bin getBin(int rowCellIndex, int columnCellIndex) {
		if (rowCellIndex > rowCellCount) throw new std::runtime_error("rowCellIndex must be smaller than rowCellCount");
		if (columnCellIndex > columnCellCount) throw new std::runtime_error("columnCellIndex must be smaller than columnCellCount");

		return bins[rowCellIndex][columnCellIndex];
	}

private:
	RowCell < ColumnCell <Bin> > openCvDescriptorTo(vector<float> descriptor) {
		// TODO: implement
	}

	int rowCellCount;
	int columnCellCount;
	RowCell < ColumnCell <Bin> > bins;
};

class Bin {
public:
	Bin(int binCount) {
		this->binCount = binCount;
	}

	float get(int index) {
		if (index > binCount) throw new std::runtime_error("index must be smaller than binCount");

		return binValues[index];
	}

	int binCount;
	vector<float> binValues;
};

#endif //HELLO_OPENCV_CPP_HOG_DESCRIPTOR_STRUCTURE_H
