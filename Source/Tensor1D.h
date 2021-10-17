/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* Namespace:		Tensors
* File:				Tensor1D.h
* Author:			Landon Buell
* Date:				August 2021
*
*/

#pragma once

#include<iostream>

#include "Tensor.h"
#include "Tensor2D.h"
#include "Tensor3D.h"
#include "Tensor4D.h"

class Tensor1D : public Tensor
{

public:

	/* Constructors and Destructors */

	// Constructor for Tensor1D
	Tensor1D(const int size0, float val = 0);

	// Constructor for Tensor1D
	Tensor1D(const int size0, float* arr);

	// Destructor for Tensor1D
	~Tensor1D();

protected:




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
