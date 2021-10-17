/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* Namespace:		Tensors
* File:				Tensor2D.cpp
* Author:			Landon Buell
* Date:				August 2021
*
*/

#pragma once

#include<iostream>

#include "Tensor1D.h"
#include "Tensor2D.h"
#include "Tensor3D.h"
#include "Tensor4D.h"

/* Constructors and Destructors */

Tensor2D::Tensor2D(const int size0, const int size1, float val) :
	Tensor(size0 * size1, val)
{
	// Constructor for Tensor2D
	_shape.push_back(size0);
	_shape.push_back(size1);
}

Tensor2D::Tensor2D(const int size0, const int size1, float* arr) :
	Tensor(size0 * size1, *arr)
{
	// Constructor for Tensor2D
	_shape.push_back(size0);
	_shape.push_back(size1);
}

Tensor2D::~Tensor2D()
{
	// Destructor for Tensor2D
	destructCode();
}