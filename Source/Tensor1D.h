/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* Namespace:		Mathematics
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
	Tensor1D(const int size, float val);

	// Constructor for Tensor1D
	Tensor1D(const int size0, float* arr);

	// Copy Constructor for Tensor1D
	Tensor1D(const Tensor1D& other);

	// Destructor for Tensor1D
	~Tensor1D();

protected:

	


public:

};
