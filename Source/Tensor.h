/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* File:				Tensor.h
* Author:			Landon Buell
* Date:				August 2021
*
*/

#pragma once

#include<iostream>
#include<vector>

#include "Tensor1D.h"
#include "Tensor2D.h"
#include "Tensor3D.h"
#include "Tensor4D.h"

class Tensor
{

protected:

	float* _data;
	std::vector<int> _shape;

	/* Constructors and Destructors */

	// Constructor given value
	Tensor(const int size, float val);

	// Constructor given array
	Tensor(const int size, float* arr);

	// Copy Constructor
	Tensor(const Tensor& rhs);

	// Move Constructor
	Tensor(Tensor&& rhs);

	// Move Assignment Operator
	Tensor& operator= (Tensor&& rhs);

	// Destructor
	~Tensor();
	

public:

	/* Getters and Setters */

	// Get Shape of the Tensor
	std::vector<int> getShape() const;

	// Get Rank of the Tensor
	const int getRank() const;

	// Get Total Size of Tensor
	const int getSize() const;
	
protected:

	/* Helper Functions */

	// Validate Direct Access
	bool validateAccess(const int index);

	// Validate Index
	virtual bool validateIndex(const int index);

	// Direct Acces
	float& item(const int index);

	// Helper Constructor
	virtual void constructCode(float val);

	// Helper Constructor
	virtual void constructCode(float* arr);

	// Helper Destructor
	virtual void destructCode();

public:

	/* Operator Overloads */



};