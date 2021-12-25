/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor1D.h
* Author:		Landon Buell
* Date:			October 2021
* Description:
*/

#include "Tensor1D.h"

Tensor1D::Tensor1D(const int size) :
	Tensor(TensorShape{size})
{
	// Constructor (See Base)
}

Tensor1D::Tensor1D(float data, const int size) :
	Tensor(data, TensorShape{size})
{
	// Constructor (See Base)
}

Tensor1D::Tensor1D(float* data, const int size, bool ownsData) :
	Tensor(data,TensorShape{size}, ownsData)
{
	// Constructor (See Base)
}

Tensor1D::~Tensor1D()
{
	// Destructor
	destruct();
}

/* Public Interface */

bool Tensor1D::reshape(const TensorShape& newShape)
{
	// Reshape This Tensor - Cannot Reshape 1D Tensor
	return false;
}

float& Tensor1D::item(const int ii)
{
	// 1D Indexer
	validateIndex(ii);
	return _data[ii];
}
