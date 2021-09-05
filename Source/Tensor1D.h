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
		constructCode(size, val);
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
	
	void constructCode(const int size, dType val)
	{
		// Helper Function For Instance Construction
		_arr = new dType[size];
		for (int i = 0; i < size; i++)
		{
			// Each element is val
			_arr[i] = val;
		}
	}

	void constructCode(const int size, dType* arr)
	{
		// Helper Function For Instance Construction
		_arr = new dType[size];
		for (int i = 0; i < size; i++)
		{
			// Copy an Array
			_arr[i] = arr[i];
		}
	}

	void destructCode()
	{
		// Helper Function for Instance Destruction
		if (_arr != nullptr)
		{
			delete[] _arr;
			_arr = nullptr;
		}			
	}

	void destructCode()
	{
		// Helper Function for Intance Destruction

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
