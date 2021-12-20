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

typedef std::vector<int> Indexer;

typedef std::vector<int> TensorShape;



class Tensor
{
	// Base Class For All Tensors <float>

protected:

	int _size;
	int _rank;
	std::shared_ptr<float> _data;	
	TensorShape _shape;
	TensorShape _sliceSizes;


public:

	/* Constructors and Destructors */

	// Generic Constructor 
	Tensor();

	// Generic Constructor 
	Tensor(const int size);

	// Generic Constructor 
	Tensor(const int size, const TensorShape& shape);

	// Constructor for 0-Tensor (From Value)
	Tensor(float data);

	// Constructor for Tensor (From Value)
	Tensor(float data, const int size);

	// Constructor for Tensor (From Value)
	Tensor(float data, const int size, const TensorShape& shape);

	// Constructor for 0-Tensor (From Pointer)
	Tensor(float* data);

	// Constructor for Tensor (From Pointer)
	Tensor(float* data, const int size);

	// Constructor for Tensor (From Pointer)
	Tensor(float* data, const int size, const TensorShape& shape);
	
	// Destructor for Tensor
	~Tensor();

public:

	// Copy Constructor
	Tensor(const Tensor& other);

	// Copy Assignment Operator
	Tensor& operator=(const Tensor& other);

	// Move Assignment Operator
	Tensor& operator=(const Tensor&& other);

public:

	/* Getters and Setters */

	// Get the Full Size of the Tensor
	int getSize() const;

	// Get the Rank of the Tensor
	int getRank() const;

	// Get Pointer Directly to Data
	float* getData() const;

	// Get the Tensor's Shape
	TensorShape getShape() const;

protected:

	// Set the Size of this Tensor
	void setSize(const int size);

	// Set the Rank of this Tensor
	void setRank(const int Rank);

	// Set Pointer Directly to Data (No Recc. for usage)
	bool setData(float* data);

	// Set the Tensor's Shape (T/F if successful)
	bool setShape(const TensorShape& newShape);

public:

	/* Public Interface */

	// Make a Deep Copy of this tensor
	Tensor copyDeep() const;

	// Describe this Tensor
	void describe(std::ostream& out);

	// Reshape This Tensor
	bool virtual reshape(const TensorShape& newShape);

	// Flatten this Tensor
	void virtual flatten();
	
protected:

	/* Protected Interface */

	// HelperFunction to Perform a Shallow Copy
	void copyShallow(float data, const int size, const TensorShape& shape);

	// HelperFunction to Perform a Shallow Copy
	void copyShallow(float* data, const int size, const TensorShape& shape);

	// Helper Function to validate Direct index
	bool validateIndex(const int index) const;

	// Helper Function to get index from indexer
	const int indexFromIndexer(const Indexer& indexer) const;

	// Find size of "pseudo-slices" when indexing
	TensorShape sliceSizes() const;

	// Helper Function to validate new shape
	bool virtual validateReshape(const TensorShape& newShape) const;

	// Helper Destruction Function
	void destructCode();

public:

	/* Operator Overloads */

	// Get 0-th Item of Array (best fo 0-D Tensors)
	float& item();
	
	// Direct Index Operator
	float& operator[] (const int index);

	// Multi-Dimensional Indexer Operator
	float& operator[] (const Indexer& index);

};



