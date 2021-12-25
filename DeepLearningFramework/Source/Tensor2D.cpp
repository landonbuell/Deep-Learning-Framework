/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor2D.cpp
* Author:		Landon Buell
* Date:			October 2021
* Description:
* 
*/

#include "Tensor2D.h"

Tensor2D::Tensor2D(const int size0, const int size1) :
	Tensor(TensorShape{size0,size1})
{
	// Constructor (See Base)
}

Tensor2D::Tensor2D(float data, const int size0, const int size1) :
	Tensor(data, TensorShape{ size0,size1 })
{
	// Constructor (See Base)
}

Tensor2D::Tensor2D(float* data, const int size0, const int size1, bool ownsData) :
	Tensor(data, TensorShape{ size0,size1 }, ownsData)
{
	// Constructor (See Base)
}

Tensor2D::~Tensor2D()
{
	// Destructor
	destruct();
}

/* Public Interface */

Tensor2D Tensor2D::identity(float value, const int size)
{
	// Construct and Return an Indentity Matrix
	Tensor2D result(0.0f, size, size);
	Indexer idx{ 0,0 };
	for (int i = 0; i < size; i++)
	{
		idx[0] = i;
		idx[1] = i;
		result[idx] = value;
	}
	return result;
}

bool Tensor2D::reshape(const TensorShape& newShape)
{
	// Reshape This Tensor
	if (newShape.size() != 2)
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

float& Tensor2D::item(const int ii, const int jj)
{
	// 2D Indexer 
	int idx = 0;
	idx += ii* _sliceSizes[0];
	idx += jj;
	validateIndex(idx);
	return _data[idx];
}
