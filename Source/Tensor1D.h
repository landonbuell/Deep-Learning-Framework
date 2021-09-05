/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* File:				Tensor1D.cpp
* Author:			Landon Buell
* Date:				August 2021
*
*/

#pragma once

#include<iostream>

#include "Tensor.h"
#include "Tensor2D.h"
#include "Tensor3D.h"
#include "Tensor4D.h"

template<class dType>
class Tensor1D : public Tensor<dType>
{

private:

	dType* _arr;

	friend class Tensor2D;
	friend class Tensor3D;
	friend class Tensor4D;

public:

	/* Constructors and Destructors */

	Tensor1D(const int size, dType val) : 
		Tensor(size, 1)
	{
		// Constructor for Tensor1D
		_arr = nullptr;
		constructCode(val);
	}

	Tensor1D(const int size, dType* arr) :
		Tensor(size, 1)
	{
		// Constructor for Tensor1D
		_arr = nullptr;
		constructCode(size, arr);
	}

	Tensor1D(const Tensor1D& rhs) :
		Tensor(rhs._size, 1)
	{
		// Copy Constructor for Tensor1D
		_arr = nullptr;
		constructCode(rhs._size, rhs._arr);
	}

	Tensor1D(const Tensor1D&& rhs) :
		Tensor(rhs._size, 1)
	{
		// Move Constructor for Tensor1D
		_arr = nullptr;
		constructCode(rhs._size, rhs._arr);
	}

	Tensor1D& operator=(const Tensor1D&& rhs)
	{
		// Move Assignment for Tensor1D
		if (this == rhs)
			return this;

		_arr = rhs._arr;
		rhs._arr = nullptr;
	}

	~Tensor1D()
	{
		// Destructor for Tensor1D
		destructCode();
	}


	/* Getters and Setters */

	override std::vector<int> getShape() const
	{
		// Get Shape of Tensor as Vector
		std::vector<int> result();
		result.push_back(this->_size);
		return result;
	}


private:

	/* Helper Functions */

	override void constructCode(dType val)
	{
		// Helper Function for Instance Construction
		_arr = new dType[this->_size0];
		for (int i = 0; i < this->_size0; i++)
		{
			// Fill Each Entry w/ val
			_arr[i] = val;
		}
	}

	override void constructCode(dType* arr)
	{
		// Helper Function For Instance Construction
		_arr = new dType[this->_size0];
		for (int i = 0; i < this->_size0; i++)
		{
			// Copy an Array
			_arr[i] = arr[i];
		}
	}

	override void destructCode()
	{
		// Helper Function for Instance Destruction
		if (_arr != nullptr)
		{
			for (int = 0; i < this->_size0; i++)
			{
				delete _arr[i];
			}
			delete[] _arr;
			_arr = nullptr;
		}			
	}

public:

	/* Operator Overloads */

	dType& operator[] (int index)
	{
		// Index Operator
		if (validateIndex(index) == true)
			return _arr[index];
		else
			throw "Index Out of Bounds";
	}
};
