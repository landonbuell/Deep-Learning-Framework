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

template<class dType>
class Tensor
{

protected:

	Tensor(const int size0, const int rank)
	{
		// Empty Constructor for Tensor
		_size0 = size0;
		_rank = rank;
	}
	
	int _size0;
	int _rank;

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
	std::vector<int> getShape() const = 0;

};