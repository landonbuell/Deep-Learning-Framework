/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor.cpp
* Author:		Landon Buell
* Date:			October 2021
* Description:
* 
*/

#include "Tensor.h"

/* Constructors and Destructors */

Tensor::Tensor()
{
	// Constructor for Tensor class
	_data = nullptr;
	_size = 0;
	_shape = std::vector<int>();
	_flags = new TensorFlags();
}

Tensor::Tensor(float* data, const int size)
{
	// Constructor for Tensor Class
	_data = data;
	_size = size;
	_shape = std::vector<int>{ size, };
	_flags = new TensorFlags();
}

Tensor::Tensor(float* data, const int size, std::vector<int> shape)
{
	// Constructor for Tensor Class
	_data = data;
	_size = size;
	_shape = std::vector<int>(shape);
	_flags = new TensorFlags();
}

Tensor::Tensor(const Tensor& other)
{
	// Copy Constructor for Tensor Class
	_data = nullptr;
	_size = other._size;
	_shape = std::vector<int>(other._shape);
	_flags = new TensorFlags(*other._flags);
	if (_flags->_isSubtensor)
		constructShallowCopy(other._data, other._size);
	else
		constructDeepCopy(other._data,other._size);
	return;
}

Tensor& Tensor::operator=(const Tensor& other)
{
	// Copy Assignment Operator
	throw "Not Implemented!";
}

Tensor& Tensor::operator=(const Tensor&& other)
{
	// Move Assignment Operator
	throw "Not Implemented!";
}

Tensor::~Tensor()
{
	// Destructor for Tensor Instance
	destructCode();
}

/* Getters and Setters */

float* Tensor::getData() const
{
	// Get Pointer Directly to Data
	return _data;
}

void Tensor::setData(float* data)
{
	// Set Pointer Directly to Data (No Recc. for usage)
	_data = data;
	return;
}

int Tensor::getSize() const
{
	// Get the Full Size of the Tensor
	return _size;
}

int Tensor::getRank() const
{
	// Get the Number of Axes in the tensor
	return _shape.size();
}

std::vector<int> Tensor::getShape() const
{
	// Get the Tensor's Shape
	return _shape;
}

bool Tensor::setShape(const std::vector<int>& newShape)
{
	// Set the Tensor's Shape (T/F if successful)
	validateNewShape(newShape);
	_shape = std::vector<int>(newShape);
	return true;
}

Tensor::TensorFlags Tensor::getFlags() const
{
	// Get the Tensor's Flags
	return *(_flags);
}

/* Public Interface */

void Tensor::describe(std::ostream& out)
{
	// Describe this Tensor
	out << "Tensor @ " << &_data << " ";
	out << "size: " << _size << " ";
	out << "shape: ";
	for (int i = 0; i < _shape.size(); i++)
		out << _shape[i] << " ";
	out << "data: ";
	for (int i = 0; i < _size; i++)
		out << _data[i] << " ";
	out << "\n";
	return;
}

/* Protected Interface */

void Tensor::constructDeepCopy(float* data, const int size)
{
	// Helper Function to Perform A Deep Copy
	_data = new float[size];
	_size = size;
	for (int i = 0; i < size; i++)
	{
		_data[i] = data[i];
	}
	return;
}

void Tensor::constructDeepCopy(float* data, const int size, std::vector<int>& shape)
{
	// Helper Function to Perform A Deep Copy
	_data = new float[size];
	_size = size;
	_shape = std::vector<int>(shape);
	for (int i = 0; i < size; i++)
	{
		_data[i] = data[i];
	}
	return;
}

void Tensor::constructFlags()
{
	// Helper Function to Construct Data Flags
	_flags = new TensorFlags();
}

bool Tensor::validateSliceIndex(const int index, const int axisSize) const
{
	// Helper Function to valid slice index
	if (index < 0)
		throw "Tensor::validateSliceIndex - Index must be positive";
	if (index >= axisSize)
		throw "Tensor::validateSliceIndex - Index must be smaller than " + axisSize;
	// Otherwise, the index is valid
	return true;
}

bool Tensor::validateNewShape(const std::vector<int>& newShape) const
{
	// Helper Function to validate new shape
	int size = 1;
	for (int i = 0; i < newShape.size(); i++)
	{
		size *= newShape[i];
	}
	if (size != _size)
	{
		// Sizes not equal
		throw "Tensor::validateNewShape - New Shape is not equal to the number elements in Tensor";
	}
	// Otherwise, the new shape is valid
	return true;
}

void Tensor::slice(Tensor* subTensor, const int index)
{
	// Helper Function for Slice a Sub-Tensor
	std::vector<int> shapeSubtensor;
	int sizeSubtensor = 1;
	int pointerOffset = _shape[0] * index;
	float* ptrSubtensor = &_data[pointerOffset];
	if (getRank() == 1)
	{
		// Edge Case: Rank-1 Tensor -> use Get item
		
	}
	// All other cases
	for (int i = 1; i < _shape.size(); i++)
	{
		shapeSubtensor.push_back(_shape[i]);
		sizeSubtensor *= _shape[i];
	}
	// Set the Data to to sub-Tensor
	subTensor->_data = ptrSubtensor;
	subTensor->_size = sizeSubtensor;
	subTensor->_shape = shapeSubtensor;
	subTensor->_flags->_isSubtensor = true;
	return;
}

void Tensor::destructCode()
{
	// Common code for object destruction
	if (_data != nullptr || !(_flags->_isSubtensor))
	{
		delete[] _data;
		_data = nullptr;
	}
	_size = 0;
	_shape = std::vector<int>();
	delete _flags;
	return;
}

Tensor::TensorFlags::TensorFlags()
{
	// Constructor for TensorFlags Instance
	_isSubtensor = false;
	_subTensors = std::vector<Tensor*>();
	_usesSharedMem = true;
	_isReadOnly = false;
}

Tensor::TensorFlags::TensorFlags(const TensorFlags& other)
{
	// Copy Constructor for Tensor Flags
	_isSubtensor = other._isSubtensor;
	_subTensors = std::vector<Tensor*>();
	_usesSharedMem = other._usesSharedMem;
	_isReadOnly = other._isReadOnly;
}

Tensor::TensorFlags::~TensorFlags()
{
	// Destructor for TensorFlags Instance
}

/* Operator Overloads */

float& Tensor::item(const int index)
{
	// Direct Index Operator
	validateSliceIndex(index, _size);
	// Valiation successful (No Error)
	return _data[index];
}

Tensor Tensor::operator[] (const int index)
{
	// Index/Slice Operator
	validateSliceIndex(index, _shape[0]);
	// Valiation successful (No Error)
	Tensor slicedTensor;
	slice(&slicedTensor,index);
	return slicedTensor;
}