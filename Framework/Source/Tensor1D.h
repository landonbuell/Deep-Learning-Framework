#pragma once

#include "Tensor.h"

template<class dType>
class Tensor1D : public Tensor<dType>
{

public:

#pragma region Constructors and Destructors

	Tensor1D(const int size) : Tensor<dType>{ size }
	{ 
		// Constructor for Tensor1D (given size)
		// See Base Constructor
	}

	Tensor1D(const int size, dType val) : Tensor<dType> {size,val}
	{
		// Constructor for Tensor1D (given size + value)
		// See Base Constructor
	}
	
	Tensor1D(const int size, dType* arr) : Tensor<dType> {size,arr}
	{
		// Constructor for Tensor (give size + array)
		// See Base Constructor
	}

	Tensor1D(const Tensor1D<dType>& rhs)
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
		// Cannot Reshape 1D Array!
		return false;
	}

#pragma endregion

#pragma region Utilties

public:

	bool override flatten()
	{
		// Cannot Flatten Tensor1D
		return false;
	}

	bool override squeeze()
	{
		// Cannot Squeeze Tensor1D
		return false;
	}

	bool override addAxis()
	{
		// Cannot Add Axis to Tensor1D
		return false;
	}

#pragma endregion

};
