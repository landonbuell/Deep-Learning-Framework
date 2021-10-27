/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	TensorDynamics
* File:			TensorDynamic.cpp
* Author:		Landon Buell
* Date:			October 2021
* Description:
* 
*/

#include "TensorDynamic.h"

/* Constructors and Destructors */

TensorDynamic::TensorDynamic()
{
	// Constructor for TensorDynamic class
	constructShallowCopy(nullptr, 1);
}

TensorDynamic::TensorDynamic(float data)
{
	// Constructor for TensorDynamic class
	float* scalar = new float[1];
	scalar[0] = data;

	constructShallowCopy(scalar, 1);
	scalar = nullptr;
}

TensorDynamic::TensorDynamic(float data, const int size)
{
	// Constructor for TensorDynamic class
	float* scalar = new float[size];
	for (int i = 0; i < size; i++)
		scalar[i] = data;

	constructShallowCopy(scalar, size);
	scalar = nullptr;
}

TensorDynamic::TensorDynamic(float data, const int size, std::vector<int> shape)
{
	// Constructor for TensorDynamic class
	float* scalar = new float[size];
	for (int i = 0; i < size; i++)
		scalar[i] = data;

	constructShallowCopy(scalar, size, shape);
	scalar = nullptr;
}

TensorDynamic::TensorDynamic(float* data, const int size)
{
	// Constructor for TensorDynamic Class
	constructShallowCopy(data, size);
}

TensorDynamic::TensorDynamic(float* data, const int size, std::vector<int> shape)
{
	// Constructor for TensorDynamic Class
	constructShallowCopy(data, size, shape);
}

TensorDynamic::TensorDynamic(const TensorDynamic& other)
{
	// Copy Constructor for TensorDynamic Class
	float* ptrOtherData = other._data.get();
	constructShallowCopy(ptrOtherData, other._size, other._shape);
	_offset = other._offset;
}

TensorDynamic& TensorDynamic::operator=(const TensorDynamic& other)
{
	// Copy Assignment Operator
	float* ptrOtherData = other._data.get();
	constructShallowCopy(ptrOtherData, other._size, other._shape);
	return (*this);
}

TensorDynamic& TensorDynamic::operator=(const TensorDynamic&& other)
{
	// Move Assignment Operator
	float* ptrOtherData = other._data.get();
	constructShallowCopy(ptrOtherData, other._size, other._shape);

	// Destroy this instance
	_data = nullptr;
	destructCode();
	return (*this);
}

TensorDynamic::~TensorDynamic()
{
	// Destructor for TensorDynamic Instance
	destructCode();
}

/* Getters and Setters */

float* TensorDynamic::getData() const
{
	// Get Pointer Directly to Data
	return _data.get();
}

void TensorDynamic::setData(float* data)
{
	// Set Pointer Directly to Data (No Recc. for usage)
	_data = std::shared_ptr<float>(data);
	return;
}

int TensorDynamic::getSize() const
{
	// Get the Full Size of the TensorDynamic
	return _size;
}

int TensorDynamic::getRank() const
{
	// Get the Number of Axes in the TensorDynamic
	return _shape.size();
}

std::vector<int> TensorDynamic::getShape() const
{
	// Get the TensorDynamic's Shape
	return _shape;
}

bool TensorDynamic::setShape(const std::vector<int>& newShape)
{
	// Set the TensorDynamic's Shape (T/F if successful)
	validateReshape(newShape);
	_shape = std::vector<int>(newShape);
	return true;
}

TensorDynamic::TensorDynamicFlags TensorDynamic::getFlags() const
{
	// Get the TensorDynamic's Flags
	return (*_flags);
}

/* Public Interface */

void TensorDynamic::describe(std::ostream& out)
{
	// Describe this TensorDynamic
	out << "TensorDynamic @ " << _data.get() << " w/ offset " << _offset << "\n"
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

void TensorDynamic::constructShallowCopy(float* data, const int size)
{
	// Helper Function to Shallow Copy Dynamically allocated Mem
	_data = std::shared_ptr<float>(data);
	_size = size;
	_offset = 0;
	_shape = std::vector<int> { size };
	_flags = new TensorDynamicFlags();
}

void TensorDynamic::constructShallowCopy(float* data, const int size, std::vector<int> shape)
{
	// Helper Function to Shallow Copy Dynamically allocated Mem
	_data = std::shared_ptr<float>(data);
	_size = size;
	_offset = 0;

	validateReshape(shape);
	_shape = std::vector<int>(shape);	
	_flags = new TensorDynamicFlags();
}

void TensorDynamic::constructDeepCopy(float* data, const int size)
{
	// Helper Function to Shallow Copy Dynamically allocated Mem
	float* tempData = new float[size];
	for (int i = 0; i < size; i++)
		tempData[i] = data[i];

	_data = std::shared_ptr<float>(tempData);
	_size = size;
	_offset = 0;

	_shape = std::vector<int>{ size };
	_flags = new TensorDynamicFlags();

	tempData = nullptr;
}

void TensorDynamic::constructDeepCopy(float* data, const int size, std::vector<int> shape)
{
	// Helper Function to Shallow Copy Dynamically allocated Mem
	float* tempData = new float[size];
	for (int i = 0; i < size; i++)
		tempData[i] = data[i];

	_data = std::shared_ptr<float>(tempData);
	_size = size;
	_offset = 0;

	validateReshape(shape);
	_shape = std::vector<int>(shape);
	_flags = new TensorDynamicFlags();
	
	tempData = nullptr;
}

void TensorDynamic::constructFlags()
{
	// Helper Function to Construct Data Flags
	_flags = new TensorDynamicFlags();
}

bool TensorDynamic::validateSliceIndex(const int index, const int axisSize) const
{
	// Helper Function to valid slice index
	if (index < 0)
		throw "TensorDynamic::validateSliceIndex - Index must be positive";
	if (index >= axisSize)
		throw "TensorDynamic::validateSliceIndex - Index must be smaller than " + axisSize;
	// Otherwise, the index is valid
	return true;
}

bool TensorDynamic::validateReshape(const std::vector<int>& newShape) const
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
		//"TensorDynamic::validateNewShape - New Shape is not equal to the number elements in TensorDynamic";
	}
	else
	{
		// Otherwise, the new shape is valid
		return true;
	}	
}

void TensorDynamic::slice(TensorDynamic* subTensorDynamic, const int index)
{
	// Helper Function for Slice a TensorDynamic
	if (getRank() == 1)
	{
		// Edge-Case 1D TensorDynamic
		subTensorDynamic->_shape = std::vector<int>{ 1 };
		subTensorDynamic->_offset += index;
		return;
	}
	else
	{
		// Other wise, "remove" first Axis
		subTensorDynamic->_shape = std::vector<int>();
		int newSize = 1;
		int sizeAxis0 = _shape[0];
		for (int i = 1; i < _shape.size(); i++)
		{
			newSize *= _shape[i];
			subTensorDynamic->_shape.push_back(_shape[i]);
		}		
		subTensorDynamic->_size = newSize;
		subTensorDynamic->_offset += (sizeAxis0 * index);
	}
	return;
}

void TensorDynamic::destructCode()
{
	// Common code for object destruction
	delete _flags;
}

TensorDynamic::TensorDynamicFlags::TensorDynamicFlags()
{
	// Constructor for TensorDynamicFlags Instance
	_isSubtensor = false;
	_isReadOnly = false;
}

TensorDynamic::TensorDynamicFlags::TensorDynamicFlags(const TensorDynamicFlags& other)
{
	// Copy Constructor for TensorDynamic Flags
	_isSubtensor = other._isSubtensor;
	_isReadOnly = other._isReadOnly;
}

TensorDynamic::TensorDynamicFlags::~TensorDynamicFlags()
{
	// Destructor for TensorDynamicFlags Instance
}

/* Operator Overloads */

float& TensorDynamic::item(const int index)
{
	// Direct Index Operator
	validateSliceIndex(index, _size);
	// Valiation successful (No Error)
	return _data.get()[_offset + index];
}

TensorDynamic TensorDynamic::operator[] (const int index)
{
	// Index/Slice Operator
	validateSliceIndex(index, _shape[0]);
	// Valiation successful (No Error) - Perform Slice
	TensorDynamic subTensorDynamic(*this);
	//subTensorDynamic->describe(std::cout);
	slice(&subTensorDynamic, index);
	// Return de-refrenced TensorDynamic
	return subTensorDynamic;
}