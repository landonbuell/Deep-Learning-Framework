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

class TensorDynamic
{
	// Base Class For All Tensors <float>

protected:

	struct TensorDynamicFlags;

	std::shared_ptr<float> _data;
	int _size;
	int _offset;
	std::vector<int> _shape;
	TensorDynamicFlags* _flags;

public:

	/* Constructors and Destructors */

	// Constructor 
	TensorDynamic();

	// Constructor
	TensorDynamic(float data);

	// Constructor
	TensorDynamic(float data, const int size);

	// Constructor
	TensorDynamic(float data, const int size, std::vector<int> shape);

	// Constructor 
	TensorDynamic(float* data, const int size);

	// Constructor w/ Shape
	TensorDynamic(float* data, const int size, std::vector<int> shape);

	// Copy Constructor
	TensorDynamic(const TensorDynamic& other);

	// Copy Assignment Operator
	TensorDynamic& operator=(const TensorDynamic& other);

	// Move Assignment Operator
	TensorDynamic& operator=(const TensorDynamic&& other);

	// Destructor
	~TensorDynamic();

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

	// Get the Tensor's Flags
	TensorDynamicFlags getFlags() const;

	/* Public Interface */

	// Describe this Tensor
	void describe(std::ostream& out);

protected:

	/* Protected Interface */

	// HelperFunction to Perform a Shallow Copy
	void constructShallowCopy(float* data, const int size);

	// HelperFunction to Perform a Shallow Copy
	void constructShallowCopy(float* data, const int size, std::vector<int> shape);

	// HelperFunction to Perform a Deep Copy
	void constructDeepCopy(float* data, const int size);

	// HelperFunction to Perform a Deep Copy
	void constructDeepCopy(float* data, const int size, std::vector<int> shape);

	// Helper Function to Construct Data Flags
	void constructFlags();

	// Helper Function to valid slice index
	bool validateSliceIndex(const int index, const int axisSize) const;

	// Helper Function to validate new shape
	bool virtual validateReshape(const std::vector<int>& newShape) const;

	// Helper Function for Slice a Sub-Tensor
	void virtual slice(TensorDynamic* subTensor, const int index);

	// Helper Destruction Function
	void destructCode();

	/* Protected Structure - Flags*/

	struct TensorDynamicFlags
	{
		// Class to Hold Additional Tensor data
		bool _isSubtensor;
		bool _isReadOnly;

		// Constructor for TensorFlags;
		TensorDynamicFlags();

		// Copy Constructor for Tensor Flags
		TensorDynamicFlags(const TensorDynamicFlags& other);

		// Destructor for TensorFlags
		~TensorDynamicFlags();

	};

public:

	/* Operator Overloads */

	// Direct Index Operator
	float& item(const int index);

	// Index/Slice Operator
	TensorDynamic virtual operator[] (const int index);

};

