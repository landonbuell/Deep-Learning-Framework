#pragma once

#include "Tensor.h"

template<class dType>
class Tensor2D : public Tensor<dType>
{

public:

#pragma region Constructors and Destructors

	Tensor2D(const int size0, const int size1) : Tensor<dType>{ size0 * size1 }
	{
		// Constructor for Tensor2D (given size)
		std::vector<int> newShape{size0, size1};
		setShape(newShape);
	}

	Tensor2D(const int size0, const int size1, dType val) : Tensor<dType>{ size0 * size1 , val }
	{
		// Constructor for Tensor2D (given size + value)
		std::vector<int> newShape{ size0, size1 };
		setShape(newShape);
	}

	Tensor2D(const int size0, const int size1, dType val, dType* arr) : Tensor<dType>{ size0 * size1,arr }
	{
		// Constructor for Tensor (give size + array)
		std::vector<int> newShape{ size0, size1 };
		setShape(newShape);
	}

	Tensor2D(const Tensor2D<dType>& rhs)
	{
		// Copy Constructor for Tensor
		_shape = std::vector<int>{ rhs._size };
		constructCode(rhs._arr, rhs._size);
	}

#pragma endregion

#pragma region Getters and Setters

public:

	bool override setShape(const std::vector<int>& newShape)
	{
		// Reshape 2D Array
		if (newShape.size() != 2)
			return false;
		else
			return Tensor<dType>.reshape(newShape);
	}

#pragma endregion

#pragma region Utilties

public:

	bool override flatten()
	{
		// Cannot Flatten Tensor2D
		return false;
	}

	bool override squeeze()
	{
		// Cannot Squeeze Tensor2D
		return false;
	}

	bool override addAxis()
	{
		// Cannot Add Axis to Tensor2D
		return false;
	}

#pragma endregion

#pragma region Operator Overloads

	dType& operator[](const int idx0, const int idx1)
	{
		// Index Via Axes
		int idx = idx0 * _shape[0] + idx1;
		return _arr[idx];
	}

#pragma endregion

};

