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

	struct TensorFlags;

	float* _data;
	int _size;
	std::vector<int> _shape;
	TensorFlags* _flags;

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
	void setData(float* data);

	// Get the Full Size of the Tensor
	int getSize() const;

	// Get the Number of Axes in the tensor
	int getRank() const;

	// Get the Tensor's Shape
	std::vector<int> getShape() const;

	// Set the Tensor's Shape (T/F if successful)
	bool setShape(const std::vector<int>& newShape);

	/* Public Interface */

	// Describe this Tensor
	void describe(std::ostream& out);

protected:

	/* Protected Interface */

	// Helper Function to Perform A Deep Copy
	void constructDeepCopy(float* data, const int size);

	// Helper Function to Perform a Deep Copy w/ Chosen Shape
	void constructDeepCopy(float* data, const int size, std::vector<int>& shape);

	// Helper Function to Construct Data Flags
	void constructFlags();

	// Helper Function to valid slice index
	bool validateSliceIndex(const int index, const int axisSize) const;

	// Helper Function to validate new shape
	bool virtual validateNewShape(const std::vector<int>& newShape) const;

	// Helper Function for Slice a Sub-Tensor
	Tensor* virtual slice(const int index);

	// Helper Destruction Function
	void destructCode();

	/* Protected Structure - Flags*/

	struct TensorFlags
	{
		// Class to Hold Additional Tensor data
		bool _isSubtensor;
		std::vector<Tensor*> _subTensors;
		bool _usesSharedMem;
		bool _isReadOnly;

		// Constructor for TensorFlags;
		TensorFlags();

		// Destructor for TensorFlags
		~TensorFlags();

	};

public:

	/* Operator Overloads */

	// Direct Index Operator
	float& item(const int index);

	// Index/Slice Operator
	Tensor virtual operator[] (const int index);

};

