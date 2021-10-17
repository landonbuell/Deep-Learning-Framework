/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* File:				Tensor.cpp
* Author:			Landon Buell
* Date:				August 2021
*
*/

#include<iostream>
#include<vector>

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
		size = size * _shape[i];
	}
	return (size);
}

/* Helper Functions */

bool Tensor::validateAccess(const int index)
{
	// Validate Direct Access
	const int totalSize = getSize();
	if (_data == nullptr)
		return false;
	else if (index < 0 || index >= totalSize)
		return false;
	else
		return true;
}

bool Tensor::validateIndex(const int index)
{
	// Validate Index
	if (_data == nullptr)
		return false;
	else if (index < 0 || index >= _shape[0])
		return false;
	else
		return true;
}

float& Tensor::item(const int index)
{
	// Direct Access
	if (validateAccess(index) == true)
		return _data[index];
	else
		throw "Could not acces element";

}

void Tensor::constructCode(float val)
{
	// Helper Constructor
	const int totalSize = getSize();
	_data = new float[totalSize];
	for (int i = 0; i < totalSize; i++)
		_data[i] = val;
	return;
}

void Tensor::constructCode(float* arr)
{
	// Helper Constructor
	const int totalSize = getSize();
	_data = new float[totalSize];
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