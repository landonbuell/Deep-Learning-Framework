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

	Tensor1D<dType>* _arr;
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
		constructCode(size0, size1, val);
	}

	~Tensor2D(const int size0, const int size1, dType** arr)
	{
		// Destructor for Tensor2D
		_arr = nullptr;
		constructCode(size0, size1, arr);
	}

	/* Getters and Setters */

	std::vector<int> getShape() const
	{
		// Get Shape of Tensor as Vector
		std::vector<int> result();
		result.push_back(this->_size0);
		result.push_back(this->_size1);
		return result;
	}

private:

	/* Helper Functions */

	void constructCode(const int size0, const int size1, dType val)
	{
		// Helper Function For Instance Construction
		_arr = new Tensor1D<dType>[size0];
		for (int i = 0; i < size0; i++)
		{
			// Each element is a Tensor1D of val
			_arr[i] = new Tensor1D<dType>(size1,val);
		}
	}

	void constructCode(const int size0, const int size1, dType** arr)
	{
		// Helper Function For Instance Construction
		_arr = new Tensor1D<dType>[size0];
		for (int i = 0; i < size0; i++)
		{
			// Each element is a Tensor1D of val
			_arr[i] = new Tensor1D<dType>(size1, arr[i]);
		}
	}

	void destructCode()
	{
		// Helper Function for Instance Destruction
		if (_arr != nullptr)
		{
			// Delete Each Tensor1D
			for (int i = 0; i < _size)
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