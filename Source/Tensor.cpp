/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* Namespace:		Mathematics
* File:				Tensor.cpp
* Author:			Landon Buell
* Date:				August 2021
*
*/

#include<iostream>
#include<vector>
#include<string>

#include "Tensor.h"
#include "Tensor1D.h"
#include "Tensor2D.h"
#include "Tensor3D.h"
#include "Tensor4D.h"

/* Constructors and Destructors */

Tensor::Tensor(const int size, float val)
{
	// Constructor given value
	_data = nullptr;
	_shape.push_back(size);
	constructCode(val);
}

Tensor::Tensor(const int size, float* arr)
{
	// Constructor given Array
	_data = nullptr;
	_shape.push_back(size);
	constructCode(arr);
}

Tensor::Tensor(const Tensor& rhs)
{
	// Copy Constructor
	_data = nullptr;
	_shape = rhs._shape;
	constructCode(rhs._data);
}

Tensor::Tensor(Tensor&& rhs)
{
	// Move Constructor
	_data = rhs._data;
	_shape = rhs._shape;	
	rhs._data = nullptr;
}

Tensor& Tensor::operator= (Tensor&& rhs)
{
	// Move Assignment Operator
	if (this != &rhs)
	{
		_data = rhs._data;
		_shape = rhs._shape;
		rhs._data = nullptr;
	}
	return *this;
	
}

Tensor::~Tensor()
{
	// Destructor
	destructCode();
}

/* Getters and Setters */

std::vector<int> Tensor::getShape() const
{
	// Get Shape of the Tensor
	return (_shape);
}

const int Tensor::getRank() const
{
	// Get Rank of the Tensor
	return (_shape.size());
}

const int Tensor::getSize() const
{
	// Get Total Size of Tensor
	int size = 1;
	for (int i = 0; i < _shape.size(); i++)
	{
		// Compute Total Size
		size = size * _shape[i];
	}
	return (size);
}

/* Helper Functions */

bool Tensor::validateAccess(const int& index)
{
	// Validate Direct Access
	if (_data == nullptr)
	{
		// Don't Access Nullptr
		std::string errMsg;
		errMsg += "Tensor::validateIndex(const int)";
		errMsg += " - member _data is nullptr";
		throw errMsg;
	}
	else if (index < 0 || index >= getSize())
	{
		// Over or Under indexed
		std::string errMsg;
		errMsg += "Tensor::validateIndex(const int)";
		errMsg += " - Index is out of bounds";
		throw errMsg;
	}
	else
	{
		// No Index Issues
		return true;
	}
}

bool Tensor::validateIndex(const int& index)
{
	// Validate Index
	if (_data == nullptr)
	{
		// Don't Access Nullptr
		std::string errMsg;
		errMsg += "Tensor::validateIndex(const int)";
		errMsg += " - member _data is nullptr";
		throw errMsg;
	}
	else if (index < 0 || index >= _shape[0])
	{
		// Over or Under indexed
		std::string errMsg;
		errMsg += "Tensor::validateIndex(const int)";
		errMsg += " - Index is out of bounds";
		throw errMsg;
	}
	else
	{
		// No Index Issues
		return true;
	}	
}

void Tensor::constructCode(float val)
{
	// Helper Constructor
	const int totalSize = getSize();
	_data = new float[totalSize];
	// Copy value into each element _data
	for (int i = 0; i < totalSize; i++)
		_data[i] = val;
	return;
}

void Tensor::constructCode(float* arr)
{
	// Helper Constructor
	const int totalSize = getSize();
	_data = new float[totalSize];
	// Copy contents of arr into data
	for (int i = 0; i < totalSize; i++)
		_data[i] = arr[i];
	return;
}

void Tensor::destructCode()
{
	// Helper Destructor
	if (_data != nullptr)
	{
		delete[] _data;
		_data = nullptr;
	}
}

float& Tensor::operator[] (const int& index)
{
	// Direct Index Access Operator
	if (validateAccess(index) == true)
	{
		// Index is valid
		return _data[index];
	}
	else
	{
		// Index is invalid
		throw "Invalid Access!";
	}

}