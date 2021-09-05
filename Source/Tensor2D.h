/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* File:				Tensor2D.cpp
* Author:			Landon Buell
* Date:				August 2021
*
*/

#pragma once

#include<iostream>

#include "Tensor.h"
#include "Tensor1D.h"

template<class dType>
class Tensor2D : public Tensor<dType>
{

private:

	Tensor1D<dType>* _arr;	// Each Entry is a 1D Tensor
	const int _size1;

	friend class Tensor1D;
	friend class Tensor3D;
	friend class Tensor4D;

public:

	/* Constructors and Destructors */

	Tensor2D(const int size0, const int size1, dType val) :
		Tensor(size0, 2)
	{
		// Constructor for Tensor2D
		_arr = nullptr;
		_size1 = size1;
		constructCode(val);
	}



	Tensor2D(const int size0, const int size1, dType* arr) :
		Tensor(size0, 2)
	{
		// Constructor for Tensor2D
		_arr = nullptr;
		_size1 = size1;
		constructCode(arr);
	}

	Tensor2D(const int size0, const int size1, dType** arr) :
		Tensor(size0, 2)
	{
		// Constructor for Tensor2D
		_arr = nullptr;
		_size1 = size1;
		constructCode(arr);
	}

	~Tensor2D()
	{
		// Destructor for Tensor2D instance
		destructCode();
	}

	/* Getters and Setters */

	override std::vector<int> getShape() const
	{
		// Get Shape of Tensor as Vector
		std::vector<int> result();
		result.push_back(this->_size0);
		result.push_back(this->_size1);
		return result;
	}

private:

	/* Helper Functions */

	override void constructCode(dType val)
	{
		// Helper Function For Instance Construction
		_arr = new Tensor1D<dType>[this->_size0];
		for (int i = 0; i < this->_size0; i++)
		{
			// Each element is a Tensor1D of val
			_arr[i] = new Tensor1D<dType>(_size1,val);
		}
	}

	override void constructCode(dType* arr)
	{
		// Helper Function for Instance Construction
		throw "Not Implemented";
	}

	void constructCode(dType** arr)
	{
		// Helper Function For Instance Construction
		_arr = new Tensor1D<dType>[size0];
		for (int i = 0; i < this->_size0; i++)
		{
			// Each element is a Tensor1D of arr[i]
			_arr[i] = new Tensor1D<dType>(size1, arr[i]);
		}
	}

	void destructCode()
	{
		// Helper Function for Instance Destruction
		if (_arr != nullptr)
		{
			// Delete Each Tensor1D
			for (int i = 0; i < this->_size0)
			{
				delete _arr[i];
			}
			delete[] _arr;
			_arr = nullptr;
		}
	}

public:

	/* Operator Overloads */

	Tensor1D<dType>& operator[] (int index)
	{
		// Index Operator
		if (validateIndex(index) == true)
			return _arr[index];
		else
			throw "Index Out of Bounds";
	}

};