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
	// Constructor 
	float* arr = new float [1] ;
	arr[0] = 0.0f;
	constructShallowCopy(arr, 1);
	arr = nullptr;
}

Tensor::Tensor(const int size)
{
	// Constructor 
	float* arr = new float[size];
	constructShallowCopy(arr, size);
	arr = nullptr;
}

Tensor::Tensor(const int size, const std::vector<int>& shape)
{
	// Constructor for Tensor (From Value)
	float* arr = new float[size];
	constructShallowCopy(arr, size, shape);
	arr = nullptr;
}

Tensor::Tensor(float data)
{
	// Constructor for 0-Tensor (From Value) 
	float* arr = new float[1];
	arr[0] = data;
	constructShallowCopy(arr, 1);
	arr = nullptr;
}

Tensor::Tensor(float data, const int size)
{
	// Constructor for Tensor (From Value)
	float* arr = new float[size];
	for (int i = 0; i < size; i++)
		arr[i] = data;
	constructShallowCopy(arr, size);
	arr = nullptr;
}

Tensor::Tensor(float data, const int size, const std::vector<int>& shape)
{
	// Constructor for Tensor (From Value)
	float* arr = new float[size];
	for (int i = 0; i < size; i++)
		arr[i] = data;
	constructShallowCopy(arr, size, shape);
	arr = nullptr;
}

Tensor::Tensor(float* data)
{
	// Constructor for 0-Tensor (From Pointer)
	constructShallowCopy(data, 1);
}

Tensor::Tensor(float* data, const int size)
{
	// Constructor for Tensor (From Pointer)
	constructShallowCopy(data, size);
}

Tensor::Tensor(float* data, const int size, const std::vector<int>& shape)
{
	// Constructor for Tensor (From Pointer)
	constructShallowCopy(data, size, shape);
}

Tensor::~Tensor()
{
	// Destructor for Tensor
	destructCode();
}

	/* Getters and Setters */

float* Tensor::getData() const
{
	// Get Pointer Directly to Data
	return (_data.get());
}

int Tensor::getSize() const
{
	// Get the Full Size of the Tensor
	return _size;
}

int Tensor::getRank() const
{
	// Get the Number of Axes in the tensor
	return _rank;
}

std::vector<int> Tensor::getShape() const
{
	// Get the Tensor's Shape
	return _shape;
}

void Tensor::setData(float* data)
{
	// Set Pointer Directly to Data (No Recc. for usage)
	_data = std::shared_ptr<float>(data);
	return;
}

void Tensor::setSize(const int size)
{
	// Set the Size of this Tensor
	if (size <= _size)
		_size = size;
	else
		throw "Cannot Increase Size, may cause seg-faults!";
	return;
}

bool Tensor::setShape(const std::vector<int>& newShape)
{
	// Set the Tensor's Shape (T/F if successful)
	validateReshape(newShape);
	_shape = std::vector<int>(newShape);
	return true;
}

void Tensor::setRank(const int rank)
{
	// Set the Tensor's Rank
	_rank = rank;
	return;
}

	/* Public Interface */

void Tensor::describe(std::ostream& out)
{
	// Describe this Tensor
	out << "Tensor @ " << _data.get() << "\n"
		<< "size: " << _size << " "
		<< "shape: (";
	for (int i = 0; i < _shape.size(); i++)
		out << _shape[i] << ",";
	out << ") ";

	out << "\n";
	for (int i = 0; i < _size; i++)
		out << _data.get()[i] << " ";
	out << "\n" << std::endl;
	return;
}

	/* Protected Interface */

void Tensor::constructShallowCopy(float* data, const int size)
{
	// Helper Function to Shallow Copy Dynamically allocated Mem
	_data = std::shared_ptr<float>(data);
	_size = size;

	_shape = std::vector<int>{ size };
	_rank = 1;

}

void Tensor::constructShallowCopy(float* data, const int size, const std::vector<int>& shape)
{
	// Helper Function to Shallow Copy Dynamically allocated Mem
	_data = std::shared_ptr<float>(data);
	_size = size;

	_shape = std::vector<int>(shape);
	_rank = 1;

}

void Tensor::constructDeepCopy(float* data, const int size)
{
	// Helper Function to Deep Copy Dynamically allocated Mem
	float* arr = new float[size];
	for (int i = 0; i < size; i++)
		arr[i] = data[i];

	// Shallow Copy the *NEW* Memory
	constructShallowCopy(arr, size);
	arr = nullptr;
}

void Tensor::constructDeepCopy(float* data, const int size, std::vector<int> shape)
{
	// Helper Function to Deep Copy Dynamically allocated Mem
	float* arr = new float[size];
	for (int i = 0; i < size; i++)
		arr[i] = data[i];

	// Shallow Copy the *NEW* Memory
	constructShallowCopy(arr, size, shape);
	arr = nullptr;
}

bool Tensor::validateIndex(const int index) const
{
	// Helper Function to valid slice index
	if (index < 0)
		throw "Tensor::validateSliceIndex - Index must be positive";
	if (index >= _size)
		throw "Tensor::validateSliceIndex - Index must be smaller than " + _size;
	// Otherwise, the index is valid
	return true;
}

bool Tensor::validateReshape(const std::vector<int>& newShape) const
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

void Tensor::destructCode()
{
	// Common code for object destruction
	
}

/* Operator Overloads */

float& Tensor::operator[] (const int index)
{
	// Index/Slice Operator
	validateIndex(index);
	return (_data.get()[index]);
}