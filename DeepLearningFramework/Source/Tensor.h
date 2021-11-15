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

	std::shared_ptr<float> _data;
	int _size;
	std::vector<int> _shape;
	int _rank;

protected:

	/* Constructors and Destructors */

	// Generic Constructor 
	Tensor();

	// Generic Constructor 
	Tensor(const int size);

	// Generic Constructor 
	Tensor(const int size, const std::vector<int>& shape);

	// Constructor for 0-Tensor (From Value)
	Tensor(float data);

	// Constructor for Tensor (From Value)
	Tensor(float data, const int size);

	// Constructor for Tensor (From Value)
	Tensor(float data, const int size, const std::vector<int>& shape);

	// Constructor for 0-Tensor (From Pointer)
	Tensor(float* data);

	// Constructor for Tensor (From Pointer)
	Tensor(float* data, const int size);

	// Constructor for Tensor (From Pointer)
	Tensor(float* data, const int size, const std::vector<int>& shape);
	

public:

	// Copy Constructor
	Tensor(const Tensor& other);

	// Copy Assignment Operator
	Tensor& operator=(const Tensor& other);

	// Move Assignment Operator
	Tensor& operator=(const Tensor&& other);

	// Destructor
	~Tensor();

public:

	/* Getters and Setters */

	// Get Pointer Directly to Data
	float* getData() const;

	// Get the Full Size of the Tensor
	int getSize() const;

	// Get the Number of Axes in the tensor
	int getRank() const;

	// Get the Tensor's Shape
	std::vector<int> getShape() const;

protected:

	// Set Pointer Directly to Data (No Recc. for usage)
	void setData(float* data);

	// Set the Size of this Tensor
	void setSize(int size);

	// Set the Tensor's Shape (T/F if successful)
	bool setShape(const std::vector<int>& newShape);

	// Set the Tensor's Rank
	void setRank(const int ranks);

public:

	/* Public Interface */

	// Describe this Tensor
	void describe(std::ostream& out);

	// Slice This Tensor (Get Sub-Tensor w. Shared Mem)
	virtual Tensor slice(const int index) = 0;

	// 1D Indexer 
	virtual float& item(const int ii) = 0;

	// 2D Indexer 
	virtual float& item(const int ii, const int jj) = 0;

	// 3D Indexer 
	virtual float& item(const int ii, const int jj, const int kk) = 0;

	// 4D Indexer 
	virtual float& item(const int ii, const int jj, const int kk, const int ll) = 0;

	
protected:

	/* Protected Interface */

	// HelperFunction to Perform a Shallow Copy
	void constructShallowCopy(float* data, const int size);

	// HelperFunction to Perform a Shallow Copy
	void constructShallowCopy(float* data, const int size, const std::vector<int>& shape);

	// HelperFunction to Perform a Deep Copy
	void constructDeepCopy(float* data, const int size);

	// HelperFunction to Perform a Deep Copy
	void constructDeepCopy(float* data, const int size, std::vector<int> shape);

	// Helper Function to validate Direct index
	bool validateIndex(const int index) const;

	// Helper Function to valid slice index
	bool validateSliceIndex(const int index, const int axisSize) const;

	// Helper Function to validate new shape
	bool virtual validateReshape(const std::vector<int>& newShape) const;

	// Helper Destruction Function
	void destructCode();

public:

	/* Operator Overloads */
	
	// Direct Index Operator
	float& operator[] (const int index);

};



