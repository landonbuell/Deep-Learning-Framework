/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* File:				Tensor.cpp
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

template<class dType>
class Tensor
{

protected:
	
	int _size0;
	int _rank;

	Tensor(const int size0, const int rank)
	{
		// Basic Constructor for Tensor
		_size0 = size0;
		_rank = rank;
	}

	/* Helper Functions */

	bool validateIndex(const int index)
	{
		// Return T/F if Index is valid
		if (index < 0 || index >= this->_size0)
			return false;
		else
			return true;
	}

public:

	/* Getters and Setters */

	const int getSize() const
	{
		// Get the Size of this Tensor
		return _size0;
	}

	const int getRank() const
	{
		// Get the Rank of this Tensor
	}

	// Pure virutal getShape() method
	virtual std::vector<int> getShape() const = 0;

protected:

	/* Helper Functions */

	// Helper Function for Instance Construction
	virtual void constructCode(dType val) = 0;

	// Helper Function for Instance Construction
	virtual void constructCode(dType* val) = 0;

	// Helper Function for Instance Destruction
	virtual void destructCode() = 0;

};