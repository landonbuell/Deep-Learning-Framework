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
}

/* Public Interface */

float& Tensor4D::item(const int ii)
{
	// 1D Indexer - Raises Error
	throw "Tensor4D::item - Cannot use 1D indexer on 4D Tensor";
	return _data.get()[0];
}

float& Tensor4D::item(const int ii, const int jj)
{
	// 2D Indexer - Raises Error
	throw "Tensor4D::item - Cannot use 2D indexer on 4D Tensor";
	return _data.get()[0];
}

float& Tensor4D::item(const int ii, const int jj, const int kk)
{
	// 3D Indexer - Raises Error
	throw "Tensor4D::item - Cannot use 3D indexer on 4D Tensor";
	return _data.get()[0];
}

float& Tensor4D::item(const int ii, const int jj, const int kk, const int ll)
{
	// 4D Indexer
	const int index = (ii * _shape[0]) * (jj * _shape[1]) * (kk * _shape[2]) + ll;
	validateIndex(index);
	return _data.get()[index];
}
