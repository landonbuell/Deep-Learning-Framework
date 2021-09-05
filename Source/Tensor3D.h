/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* File:				Tensor3D.cpp
* Author:			Landon Buell
* Date:				August 2021
*
*/

#pragma once

#include "Tensor.h"
#include "Tensor1D.h"
#include "Tensor2D.h"

template<class dType>
class Tensor3D : public Tensor<dType>
{

private:

	Tensor2D<dType>* _arr;
	const int _size1;
	const int _size2;

	friend class Tensor1D;
	friend class Tensor2D;
	friend class Tensor4D;

public:

	/* Constructors and Destructions */

	Tensor3D(const int size0, const int size1, const int size2, dType val)
		
	{
		// Constructor for Tensor3D
		_arr = nullptr;
	}

	Tensor


private:

	/* Helper Functions */

	void constructCode(const int size0, const int size1, const int size2, dType val)
	{
		// Helper Function For Instance Construction
		_arr = new Tensor2D<dType>[size0];
		for (int i = 0; i < size0; i++)
		{
			// Each Element is a Tensor2D of va;
			_arr[i] = new Tensor2D<dType>(size1, size2, val);
		}
	}

	void constructCode(const int size0, const int size1, const int size2, dType*** arr)
	{
		//Helper Function for Instance Construction
		_arr = new Tensor2D<dType>[this->_size0];
		for (int i = 0; i < this->_size0l i++)
		{
			// Each Element is a Tensor2D of arr[i]
			_arr[i] = new Tensor2D<dType>(size1, size2, arr[i]);
		}
	}

	void destructCode()
	{
		// Helper Function for Institue
		if (_arr != nullptr)
		{
			// Delete each Tensor2D
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

	Tensor2D<dType>& operator[] (int index)
	{
		// Index Operator
		if (validateIndex(index) == true)
			return _arr[index];
		else
			throw "Index Out of Bounds";
	}

};