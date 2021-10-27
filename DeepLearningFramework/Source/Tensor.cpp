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
	constructShallowCopy(nullptr, 1);
}

Tensor::Tensor(float data)
{
	// Constructor for Tensor class
	float* scalar = new float[1];
	scalar[0] = data;

	constructShallowCopy(scalar, 1);
	scalar = nullptr;
}

Tensor::Tensor(float data, const int size)
{
	// Constructor for Tensor class
	float* scalar = new float[size];
	for (int i = 0; i < size; i++)
		scalar[i] = data;

	constructShallowCopy(scalar, size);
	scalar = nullptr;
}

Tensor::Tensor(float data, const int size, std::vector<int> shape)
{
	// Constructor for Tensor class
	float* scalar = new float[size];
	for (int i = 0; i < size; i++)
		scalar[i] = data;

	constructShallowCopy(scalar, size, shape);
	scalar = nullptr;
}

Tensor::Tensor(float* data, const int size)
{
	// Constructor for Tensor Class
	constructShallowCopy(data, size);
}

Tensor::Tensor(float* data, const int size, std::vector<int> shape)
{
	// Constructor for Tensor Class
	constructShallowCopy(data, size, shape);
}

Tensor::Tensor(const Tensor& other)
{
	// Copy Constructor for Tensor Class
	float* ptrOtherData = other._data.get();
	constructShallowCopy(ptrOtherData, other._size, other._shape);
	_offset = other._offset;
}

Tensor& Tensor::operator=(const Tensor& other)
{
	// Copy Assignment Operator
	float* ptrOtherData = other._data.get();
	constructShallowCopy(ptrOtherData, other._size, other._shape);
	return (*this);
}

Tensor& Tensor::operator=(const Tensor&& other)
{
	// Move Assignment Operator
	float* ptrOtherData = other._data.get();
	constructShallowCopy(ptrOtherData, other._size, other._shape);

	// Destroy this instance
	_data = nullptr;
	destructCode();
	return (*this);
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
	return _data.get();
}

void Tensor::setData(float* data)
{
	// Set Pointer Directly to Data (No Recc. for usage)
	_data = std::shared_ptr<float>(data);
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
	out << "Tensor @ " << _data.get() << " w/ offset " << _offset << "\n"
		<< "size: " << _size << " "
		<< "shape: ";
	for (int i = 0; i < _shape.size(); i++)
		out << _shape[i] << " ";

	out << "\n";
	for (int i = 0; i < _size; i++)
		out << _data.get()[_offset + i] << " ";
	out << "\n" << std::endl;
	return;
}

/* Protected Interface */

void Tensor::constructShallowCopy(float* data, const int size)
{
	// Helper Function to Shallow Copy Dynamically allocated Mem
	_data = std::shared_ptr<float>(data);
	_size = size;
	_offset = 0;
	_shape = std::vector<int> { size };
	_flags = new TensorFlags();
}

void Tensor::constructShallowCopy(float* data, const int size, std::vector<int> shape)
{
	// Helper Function to Shallow Copy Dynamically allocated Mem
	_data = std::shared_ptr<float>(data);
	_size = size;
	_offset = 0;

	validateNewShape(shape);
	_shape = std::vector<int>(shape);	
	_flags = new TensorFlags();
}

void Tensor::constructDeepCopy(float* data, const int size)
{
	// Helper Function to Shallow Copy Dynamically allocated Mem
	float* tempData = new float[size];
	for (int i = 0; i < size; i++)
		tempData[i] = data[i];

	_data = std::shared_ptr<float>(tempData);
	_size = size;
	_offset = 0;

	_shape = std::vector<int>{ size };
	_flags = new TensorFlags();

	tempData = nullptr;
}

void Tensor::constructDeepCopy(float* data, const int size, std::vector<int> shape)
{
	// Helper Function to Shallow Copy Dynamically allocated Mem
	float* tempData = new float[size];
	for (int i = 0; i < size; i++)
		tempData[i] = data[i];

	_data = std::shared_ptr<float>(tempData);
	_size = size;
	_offset = 0;

	validateNewShape(shape);
	_shape = std::vector<int>(shape);
	_flags = new TensorFlags();
	
	tempData = nullptr;
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
	// Check Shape
	if (size != _size)
	{
		// Sizes not equal
		return false;
		//"Tensor::validateNewShape - New Shape is not equal to the number elements in Tensor";
	}
	else
	{
		// Otherwise, the new shape is valid
		return true;
	}	
}

void Tensor::slice(Tensor* subTensor, const int index)
{
	// Helper Function for Slice a Tensor
	if (getRank() == 1)
	{
		// Edge-Case 1D Tensor
		subTensor->_shape = std::vector<int>{ 1 };
		subTensor->_offset += index;
		return;
	}
	else
	{
		// Other wise, "remove" first Axis
		subTensor->_shape = std::vector<int>();
		int newSize = 1;
		int sizeAxis0 = _shape[0];
		for (int i = 1; i < _shape.size(); i++)
		{
			newSize *= _shape[i];
			subTensor->_shape.push_back(_shape[i]);
		}		
		subTensor->_size = newSize;
		subTensor->_offset += (sizeAxis0 * index);
	}
	return;
}

void Tensor::destructCode()
{
	// Common code for object destruction
	delete _flags;
}

Tensor::TensorFlags::TensorFlags()
{
	// Constructor for TensorFlags Instance
	_isSubtensor = false;
	_isReadOnly = false;
}

Tensor::TensorFlags::TensorFlags(const TensorFlags& other)
{
	// Copy Constructor for Tensor Flags
	_isSubtensor = other._isSubtensor;
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
	return _data.get()[_offset + index];
}

Tensor Tensor::operator[] (const int index)
{
	// Index/Slice Operator
	validateSliceIndex(index, _shape[0]);
	// Valiation successful (No Error) - Perform Slice
	Tensor* subTensor = new Tensor(*this);
	subTensor->describe(std::cout);
	slice(subTensor, index);
	// Return de-refrenced tensor
	return (*subTensor);
}