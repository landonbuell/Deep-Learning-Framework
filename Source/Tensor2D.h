/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* Namespace:		Tensors
* File:				Tensor2D.h
* Author:			Landon Buell
* Date:				August 2021
*
*/

#pragma once

#include<iostream>

#include "Tensor.h"
#include "Tensor1D.h"
#include "Tensor3D.h"
#include "Tensor4D.h"

class Tensor2D : public Tensor
{

public:

	/* Constructors and Destructors */

	// Constructor for Tensor2D
	Tensor2D(const int size0, const int size1, float val = 0);

	// Constructor for Tensor2D
	Tensor2D(const int size0, const int size1, float* arr);

	// Destructor for Tensor1D
	~Tensor2D();

public:

	/* Operator Overloads */

	// 1D Access operator
	float& operator() (const int ii) = 0;

	// 2D Access operator
	float& operator() (const int ii, const int jj) = 0;

	// 3D Access operator 
	float& operator() (const int ii, const int jj, const int kk) = 0;

	// 4D Access operator
	float& operator() (const int ii, const int jj, const int kk, const int ll) = 0;

};
