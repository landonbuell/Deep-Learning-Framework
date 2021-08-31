/*
Author:		Landon Buell
Date:		July 2021
Repo:		Deep-Learning-Application
Solution:	DeepLearningFramework
Project:	Source
File:		Tensor.h
Description:
	TODO: Write Description
*/

#pragma once

#include <string>
#include <vector>
#include <iostream>

template<class dType>
class Tensor
{
protected:

	std::vector<int> _shape;
	int _size;
	dType* _arr;

#pragma region Constructors and Destructors

public:

	Tensor(const int size)
	{
		// Constructor for Tensor (given size)
		_shape = std::vector<int>();
		_shape.push_back(size);

		_size = size;
		_arr = new dType[_size];
	}

	Tensor(const int size, dType val)
	{
		// Constructor for Tensor (given size + value)
		_shape = std::vector<int>();
		_shape.push_back(size);

		_size = size;
		_arr = new dType[size];
		for (int i = 0; i < _size; i++)
			_arr[i] = val;
	}

	Tensor(const int size, dType* arr)
	{
		// Constructor for Tensor (give size + array)
		_shape = std::vector<int>();
		_shape.push_back(size);
		constructCode(arr, size);
	}

	Tensor(const int size, dType* arr, std::vector<int>& shape)
	{
		// Constructor for Tensor (given shape)
		_shape = std::vector<int>(shape);
		constructCode(arr, size);
	}


	Tensor(const Tensor<dType>& rhs)
	{
		// Copy Constructor for Tensor
		_shape = std::vector<int>(rhs._shape);
		constructCode(rhs._arr, rhs._size);
	}

	Tensor& operator=(const Tensor<dType>& rhs)
	{
		// Copy Assignment Operator for Tensor
		if (this == rhs)
			return this;

		// Construct
		_shape = std::vector<int>(rhs._shape);
		constructCode(rhs._arr, rhs._size);
		
	}

	Tensor& operator=(const Tensor<dType>&& rhs)
	{
		// Move Assignment Operator for Tensor
		if (this == rhs)
			return this;

		// Construct as normal
		_shape = std::vector<int>(rhs._shape);
		constructCode(rhs._arr, rhs._size);
		delete[] rhs._arr;
	}

	~Tensor()
	{
		// Destructor for Tensor Instance
		destructCode();
	}

#pragma endregion

#pragma region Getters and Setters

public:

	std::vector<int> getShape() const
	{
		// Return the Shape of this Array
		return _shape;
	}

	bool virtual setShape(const std::vector<int>& newShape)
	{
		bool validShape = testReshape(newShape);
		if (validShape == true)
		{
			// Can reshape - Do it!
			_shape = std::vector<int>(newShape);
		}
		return validShape;
	}

	int getSize() const
	{
		// Return the Size of this Array
		return _size;
	}

	dType* getData() const
	{
		// Return Pointer To Data
		return _arr;
	}

	int getRank() const
	{
		// Return the Rank of this Array
		return _shape.size();
	}

	dType& getItem(int i) const
	{
		// Directly Index Item
		validateIndex(i);
		return _arr[i];
	}

#pragma endregion

#pragma region  Helper Functions

protected:

	void constructCode(dType* arr, const int size)
	{
		// Common Code for Object Construction
		_arr = new dType[size];
		_size = size;
		for (int i = 0; i < size; i++)
		{
			// Copy Contents
			_arr[i] = arr[i];
		}
	}

	void destructCode()
	{
		// Common Code of Object Destruction
		delete[] _arr;
	}

	bool validateIndex(int idx)
	{
		// Verify Index is within range
		if (idx >= _size)
		{
			// Over index
			//throw "Over Index on Direct Access";
			return false;
		}
		else if (idx < 0)
		{
			// Under Index
			//throw "Under Index on Direct Access";
			return false;
		}
		else
		{
			// Index is Valid
			return true;
		}
	}

	bool validateIndex(const std::vector<int>& idxVec)
	{
		// Validate Index of Vector
		if (idxVec.size() >= getRank())
		{
			// Index exceeds Rank
			throw "Indexer size Exceeds Rank";
			return false;
		}
		for (int i = 0; i < idxVec.size(); i++)
		{
			if (idxVec[i] >= _shape[i] || idxVec[i] < 0)
			{
				// Index too large for shape
				throw "Over/Under Index for Axis";
				return false;
			}
		}
		return true;
	}

	int fromSlice(const std::vector<int>& idxVec)
	{
		// Compute Indexer from vector
		
		int idxSize = idxVec.size();
		// Handle Special Case - single Index
		if (idxSize == 1)
			return this[idxVec[0]];
		// Handle Special Case - No Index given
		else if (idxSize == 0)
			throw "Indexer must have more than 0 elementes";
		else if (idxSize > getRank)
			throw "Indexer size must not exceed rank";
		else
		{
			// More than One index
			int idx = 0;
			for (int i = 0; i < idxSize - 1; i++)
			{
				// Increment Index
				idx *= idxVec[0];;
			}
			idx += idxVec[idxSize - 1];
			return idx;
		}
	}

	int vectorProduct(const std::vector<int>& intVec)
	{
		// Return the product of every element in the vector
		int result = 1;
		for (int i = 0; i < intVec.size(); i++)
		{
			result *= intVec[i];
		}
		return result;
	}

	bool virtual testReshape(const std::vector<int>& newShape)
	{
		// Reshape This Array
		if (vectorProduct(newShape) != _size)
		{
			// Cannot Reshape to size
			return false;
		}
		else
		{
			// Can Reshape to Size
			return true;
		}
	}

#pragma endregion

#pragma region Utilties

public:

	bool virtual flatten()
	{
		// Flatten to 1D Array
		std::vector<int> newShape;
		newShape.push_back(_size);
		return setShape(newShape);
	}

	bool virtual squeeze()
	{
		// Remove any Axis w/ size == 1
		std::vector<int> newShape;
		for (int i = 0; i < getRank(); i++)
		{
			if (_shape[i] != 1)
				newShape.push_back(_shape[i]);
		}
		// Set as new Shape		
		return setShape(newShape);
	}

	bool virtual addAxis()
	{
		// Add Axis of Shape 1 to Tensor
		_shape.push_back(1);
		return setShape(_shape);
	}

	void describe(std::ostream& out)
	{
		// Describe this Tensor
		out << "Shape: ";
		for (int i = 0; i < getRank(); i++)
			out << _shape[i] << " ";
		out << std::endl;
		out << "Size: " << _size;
		out << std::endl;
	}

#pragma endregion

#pragma region Operator Overloads

public:

	void printData(std::ostream& out)
	{
		// Export Data to ostream
		for (int i = 0; i < _size; i++)
		{
			// Dump to Output Stream
			out << _arr[i] << " ";
		}
		out << std::endl;
		return;
	}

	dType& operator[](const int idx)
	{
		// Index Via Axes
		validateIndex(idx);
		return _arr[idx];
	}

	dType& operator[](const std::vector<int>& idxVect)
	{
		// Index Via Axes
		validateIndex(idxVect);
		int index = fromSlice(idxVect);
		return _arr[index];
	}

#pragma endregion

};
