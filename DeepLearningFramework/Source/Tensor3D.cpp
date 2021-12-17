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
	Tensor(size0 * size1 * size2)
{
	// Constructor (See base)
	_shape = std::vector<int>{ size0,size1,size2 };
}

Tensor3D::Tensor3D(float data, const int size0, const int size1, const int size2) :
	Tensor(data, size0* size1* size2)
{
	// Constructor (See base)
	_shape = std::vector<int>{ size0,size1,size2 };
}

Tensor3D::Tensor3D(float* data, const int size0, const int size1, const int size2) :
	Tensor(data, size0* size1* size2)
{
	// Constructor (See Base)
	_shape = std::vector<int>{ size0,size1,size2 };
}

Tensor3D::~Tensor3D()
{
	// Destructor
}

/* Public Interface */

float& Tensor3D::item(const int ii, const int jj, const int kk)
{
	// 3D Indexer 
	const int index = (ii * _shape[0]) * (jj *_shape[1]) + kk;
	validateIndex(index);
	return _data.get()[index];
}
