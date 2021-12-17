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
	Tensor(size0 * size1)
{
	// Constructor (See Base)
	_shape = std::vector<int>{ size0, size1 };
}

Tensor2D::Tensor2D(float data, const int size0, const int size1) :
	Tensor(data, size0 * size1)
{
	// Constructor (See Base)
	_shape = std::vector<int>{ size0, size1 };
}

Tensor2D::Tensor2D(float* data, const int size0, const int size1) :
	Tensor(data, size0 * size1)
{
	// Constructor (See Base)
	_shape = std::vector<int>{ size0, size1 };
}

Tensor2D::~Tensor2D()
{
	// Destructor
}

/* Public Interface */

float& Tensor2D::item(const int ii, const int jj)
{
	// 2D Indexer - Raises Error
	const int index = ii * _shape[0] + jj;
	validateIndex(index);
	return _data.get()[index];
}