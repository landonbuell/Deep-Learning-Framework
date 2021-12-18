/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor4D.cpp
* Author:		Landon Buell
* Date:			October 2021
* Description:
*
*/

#include "Tensor4D.h"

Tensor4D::Tensor4D(const int size0, const int size1, const int size2, const int size3) :
	Tensor(size0* size1* size2 * size3)
{
	// Constructor (See base)
	_shape = std::vector<int>{ size0,size1,size2,size3 };
}

Tensor4D::Tensor4D(float data, const int size0, const int size1, const int size2, const int size3) :
	Tensor(data, size0* size1* size2 * size3)
{
	// Constructor (See base)
	_shape = std::vector<int>{ size0,size1,size2,size3 };
}

Tensor4D::Tensor4D(float* data, const int size0, const int size1, const int size2, const int size3) :
	Tensor(data, size0* size1* size2 * size3)
{
	// Constructor (See Base)
	_shape = std::vector<int>{ size0,size1,size2,size3 };
}

Tensor4D::~Tensor4D()
{
	// Destructor
	destructCode();
}

/* Public Interface */

bool Tensor4D::reshape(const TensorShape& newShape)
{
	// Reshape This Tensor
	if (newShape.size() != 4)
	{
		// Cannot Reshape to different rank
		return false;
	}
	else
	{
		// Shape Rank - try to reshape
		return Tensor::validateReshape(newShape);
	}
}

float& Tensor4D::item(const int ii, const int jj, const int kk, const int ll)
{
	// 4D Indexer
	int idx = 0;
	idx += ii * _sliceSizes[0];
	idx += jj * _sliceSizes[1];
	idx += kk * _sliceSizes[2];
	idx += ll;
	validateIndex(idx);
	return _data.get()[idx];
}
