/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor0D.h
* Author:		Landon Buell
* Date:			December 2021
* Description:
*/

#include "Tensor0D.h"

Tensor0D::Tensor0D(const float data) :
	Tensor(data)
{
	// Constructor for Tensor0D Instance
}

Tensor0D::~Tensor0D()
{
	// Destructor for Tensor0D Instance
	destruct();
}

bool Tensor0D::reshape(const TensorShape& newShape)
{
	// Reshape This Tensor - Cannot reshape 0D Tesnor
	return false;
}

float& Tensor0D::item()
{
	// 0D Indexer
	return _data[0];
}
