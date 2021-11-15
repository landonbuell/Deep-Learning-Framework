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
	Tensor(size)
{
	// Constructor (See Base)
}

Tensor1D::Tensor1D(float data, const int size) :
	Tensor(data, size)
{
	// Constructor (See Base)
}

Tensor1D::Tensor1D(float* data, const int size) :
	Tensor(data,size)
{
	// Constructor (See Base)
}

Tensor1D::~Tensor1D()
{
	// Destructor
}

/* Public Interface */

float& Tensor1D::item(const int ii)
{
	// 1D Indexer
	validateIndex(ii);
	return _data.get()[ii];
}

float& Tensor1D::item(const int ii, const int jj)
{
	// 2D Indexer - Raises Error
	throw "Tensor1D::item - Cannot use 2D indexer on 1D Tensor";
	return;
}

float& Tensor1D::item(const int ii, const int jj, const int kk)
{
	// 3D Indexer - Raises Error
	throw "Tensor1D::item - Cannot use 3D indexer on 1D Tensor";
	return;
}

float& Tensor1D::item(const int ii, const int jj, const int kk, const int ll)
{
	// 3D Indexer - Raises Error
	throw "Tensor1D::item - Cannot use 4D indexer on 1D Tensor";
	return;
}