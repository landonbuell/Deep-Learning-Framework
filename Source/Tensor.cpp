/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* Namespace:		Tensors
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
	constructCode(val);
}

Tensor::Tensor(const int size, float* arr)
{
	// Constructor given Array
	_data = nullptr;
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

bool Tensor::setShape(std::vector<int> newShape)
{
	// Set the Shape of the Tensor (Must keep rank)
	if (newShape.size() != getRank())
	{
		// Different Ranks - throw Error
		std::string errMsg;
		errMsg += "Tensor::setShape( std::vector<int> ) ";
		errMsg += " - When reShaping, a tensor must retain it's current rank";
		throw errMsg;
	}
	else if (getSize() != getSize(newShape))
	{
		// New Sizes do not match
		std::string errMsg;
		errMsg += "Tensor::setShape( std::vector<int> ) ";
		errMsg += " - When reShaping, a tensor must retain it's current rank";
		throw errMsg;
	}
	else
	{
		// Otherwise, we're good.
		//TODO:
		return true;
	}
	
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

bool Tensor::validateIndex(const int& index, const int& axis)
{
	// Validate Index
	if (axis < 0 || axis >= getRank())
	{
		// Axis index too Big
		std::string errMsg;
		errMsg += "Tensor::validateIndex(const int& const int&)";
		errMsg += " - axis must be > 0 and < getRank()";
		throw errMsg;
	}
	else if (_data == nullptr)
	{
		// Don't Access Nullptr
		std::string errMsg;
		errMsg += "Tensor::validateIndex(const int&, const int &)";
		errMsg += " - member _data is nullptr";
		throw errMsg;
	}
	else if (index < 0 || index >= _shape[axis])
	{
		// Over or Under indexed
		std::string errMsg;
		errMsg += "Tensor::validateIndex(const int&, const int&)";
		errMsg += " - Index is out of bounds";
		throw errMsg;
	}
	else
	{
		// No Index Issues
		return true;
	}	
}

const int Tensor::getSize(std::vector<int>& newShape) const
{
	// Get Total Size of new intended shaped Tensor
	int size = 1;
	for (int i = 0; i < newShape.size(); i++)
	{
		// Compute Total Size
		size = size * newShape[i];
	}
	return (size);
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

/* Operator Overloads */

float& Tensor::operator[] (const int& index)
{
	// Direct Index Access Operator
	if (validateAccess(index) == true)
	{
		// Index is valid
		return (_data[index]);
	}
	else
	{
		// Index is invalid
		throw "Invalid Access!";
	}

}

float& Tensor::operator() (const int ii)
{
	// 1D Access operator	
	validateIndex(ii, 0);
	const int index = ii;
	return _data[index];
}

float& Tensor::operator() (const int ii, const int jj)
{
	// 2D Access operator
	validateIndex(ii, 0);
	validateIndex(jj, 1);
	const int index = (ii * _shape[0]) +  jj;
	return this->operator[](index);
}

float& Tensor::operator() (const int ii, const int jj, const int kk)
{
	// 3D Access operator
	validateIndex(ii, 0);
	validateIndex(jj, 1);
	validateIndex(kk, 2);
	const int index = (ii * _shape[0]) + (jj * _shape[1]) + kk;
	return this->operator[](index);
}

float& Tensor::operator() (const int ii, const int jj, const int kk, const int ll)
{
	// 4D Access operator
	validateIndex(ii, 0);
	validateIndex(jj, 1);
	validateIndex(kk, 2);
	validateIndex(ll, 3);
	const int index = ii * jj * kk *ll;
	return this->operator[](index);
}