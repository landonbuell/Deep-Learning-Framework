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
	float* _data;
	bool _ownsData;
	TensorShape _shape;
	TensorShape _sliceSizes;

public:

	/* Constructors and Destructors */

	// Generic Constructor 
	Tensor();

	// Constructor for Tensor
	Tensor(
		const TensorShape& shape);

	// Constructor for Tensor
	Tensor(
		float data);

	// Constructor for Tensor 
	Tensor(
		float data, 
		const TensorShape& shape);

	// Constructor for Tensor
	Tensor(
		float* data,
		const int size, 
		bool ownsData = true);

	// Constructor for Tensor 
	Tensor(
		float* data, 
		const TensorShape& shape, 
		bool ownsData = true);

	// Copy Constructor
	Tensor(
		const Tensor& other);

	// Copy Assignment Operator
	Tensor& operator=(
		const Tensor& other);

	// Move Assignment Operator
	Tensor& operator=(
		const Tensor&& other);

	// Destructor for Tensor
	~Tensor();

public:

	// Get the Full Size of the Tensor
	int getSize() const;

	// Get the Rank of the Tensor
	int getRank() const;

	// Get Pointer Directly to Data
	float* getData() const;

	// Get T/F if Tensor Owns it's underlying array
	bool getOwnsData() const;

	// Get the Tensor's Shape
	TensorShape getShape() const;

	// Set T/F if Tensor Owns it's underlying array
	void setOwnsData(bool ownsMem);
	
protected:

	// Set the Size of this Tensor
	void setSize(const int size);

	// Set the Rank of this Tensor
	void setRank(const int Rank);

	// Set Pointer Directly to Data (No Recc. for usage)
	bool setData(float* data, const int size = -1, bool ownsData = true);

	// Set the Tensor's Shape (T/F if successful)
	bool setShape(const TensorShape& newShape);

public:

	/* Public Interface */

	// Describe this Tensor
	void describe(std::ostream& out);

	// Reshape This Tensor
	bool virtual reshape(const TensorShape& newShape);

	// Flatten this Tensor
	void virtual flatten();
	
protected:

	// Helper for Instance construction
	void construct(float* data, const TensorShape& shape, bool ownsData);

	// Helper for Instance construction
	void construct(float val, const TensorShape& shape);

	// Helper for Instance destruction
	void destruct();

	// Helper to copy underlying array
	float* copyUnderlying() const;

	// Find size of "pseudo-slices" when indexing
	TensorShape sliceSizes() const;

	// Get size from vector of axis shapes
	const int sizeFromShape(const TensorShape& shape) const;

	// Helper Function to get index from indexer
	const int indexFromIndexer(const Indexer& indexer) const;

	// Helper Function to validate Direct index
	bool validateIndex(const int index) const;

	// Helper Function to validate new shape
	bool virtual validateReshape(const TensorShape& newShape) const;

public:

	// Direct-Index Operator
	float& item(const int index = 0);
	
	// Multi-Dimensional Indexer Operator
	float& operator[] (const Indexer& index);
};



