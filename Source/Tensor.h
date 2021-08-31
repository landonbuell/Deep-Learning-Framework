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

	Tensor(const int size, const int rank)
	{
		// Empty Constructor for Tensor
		_size = size;
		_rank = rank;
	}
	
	int _size;
	int _rank;

	/* Helper Functions */

public:

	/* Getters and Setters */

	const int getSize() const
	{
		// Get the Size of this Tensor
		return _size;
	}

	const int getRank() const
	{
		// Get the Rank of this Tensor
	}

	// Pure virutal getShape() method
	std::vector<int> getShape() const = 0;

};