/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor3D.cpp
* Author:		Landon Buell
* Date:			October 2021
* Description:
*/

#include "Tensor3D.h"

Tensor3D::Tensor3D(const int size0, const int size1, const int size2) :
	Tensor(TensorShape{ size0,size1,size2 })
{
	// Constructor (See base)
}

Tensor3D::Tensor3D(float data, const int size0, const int size1, const int size2) :
	Tensor(data, TensorShape{ size0,size1,size2 })
{
	// Constructor (See base)
}

Tensor3D::Tensor3D(float* data, const int size0, const int size1, const int size2, bool ownsData) :
	Tensor(data, TensorShape{ size0,size1,size2 }, ownsData)
{
	// Constructor (See Base)
}

Tensor3D::~Tensor3D()
{
	// Destructor
	destruct();
}

/* Public Interface */

bool Tensor3D::reshape(const TensorShape& newShape)
{
	// Reshape This Tensor
	if (newShape.size() != 3)
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

float& Tensor3D::item(const int ii, const int jj, const int kk)
{
	// 3D Indexer 
	int idx = 0;
	idx += ii * _sliceSizes[0];
	idx += jj * _sliceSizes[1];
	idx += kk;
	validateIndex(idx);
	return _data[idx];
}
