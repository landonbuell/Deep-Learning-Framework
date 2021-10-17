/*
* 
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor.h
* Author:		Landon Buell
* Date:			October 2021
* Description: 
*/


#pragma once
#include <iostream> 
#include <string>
#include <vector>

class Tensor
{
	// Base Class For All Tensors <float>

protected:

	float* _data;
	int _size;
	std::vector<int> _shape;

public:

	/* Constructors and Destructors */

	// Constructor 
	Tensor(float* data, const int size);

	// Constructor w/ Shape
	Tensor(float* data, const int size, std::vector<int> shape);

	// Copy Constructor
	Tensor(const Tensor& other);

	// Copy Assignment Operator
	Tensor& operator=(const Tensor& other);

	// Move Assignment Operator
	Tensor& operator=(const Tensor&& other);

	// Destructor
	~Tensor();

	/* Getters and Setters */

	// Get Pointer Directly to Data
	float* getData() const;

	// Set Pointer Directly to Data (No Recc. for usage)
	void setData();

	// Get the Full Size of the Tensor
	int getSize() const;

	// Get the Number of Axes in the tensor
	int getRank() const;

	// Get the Tensor's Shape
	std::vector<int> getShape() const;

	// Set the Tensor's Shape
	void setShape(const std::vector<int> newShape);


protected:

	// Helper Function to Perform A Deep Copy
	void constructDeepCopy(float* data, const int size);

	// Helper Function to Perform a Deep Copy w/ Chosen Shape
	void constructDeepCopy(float* data, const int size, std::vector<int> shape);

	// Helper Function to valid slice index
	void validateSliceIndex(const int i);

	// Helper Function to validate new shape
	void validateNewShape(const std::vector<int>& newShape);

	// Helper Destruction Function
	void destructCode();

public:

	/* Operator Overloads */

	// Index Operator
	Tensor virtual operator[] (const int index);

};

