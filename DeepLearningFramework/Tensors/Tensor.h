/*
	
	Repository:		Deep-Learning-Framework
	Solution:		DeepLearningFramework
	Project:		Tensors
	Namespace:		N/A
	File:			Tensor.h
	Author:			Landon Buell
	Date:			February 2023
*/

#ifndef TENSOR
#define TENSOR

#include<vector>
#include<memory>


typedef std::vector<int> TensorShape;

typedef std::vector<int> TensorIndex;

template<typename T>
class Tensor
{
	// Base Class for All Tensors
private:

	unsigned int _size;
	std::shared_ptr<T> _data;
	TensorShape _shape;

	unsigned int _capacity;
	unsigned int _offset;

	bool _readonly;

public:

	Tensor(
		unsigned int size)
	{
		// constructor
		_size = size;
		
	}

	Tensor(
		TensorShape shape)
	{
		// Constructor
	}

	Tensor(
		const Tensor& other)
	{
		// Copy Constructor
		
	}

	~Tensor()
	{
		// Destructor
		
	}

	//// Getters and Setters ////

	unsigned int getSize() const
	{
		// Return the number of items in the tensor
		return _size;
	}

	TensorShape getShape() const
	{
		// Return the Shape of the Tensor
		return _shape;
	}

	unsigned int getRank() const
	{
		// Return the number of Axes in the Tensor
		return _shape.size();
	}

	unsigned int getCapacity() const
	{
		// Return the Capacity of this Tensor
		return _capacity;
	}

	bool isUnique() const
	{
		// Return T/F if this is the only Tensor that points to the supplied Data block 
		return _data.unique()
	}

	//// Public Interface ////

	const T& item() const
	{
		// Get the item at the 0-th index (const)
		return _data[_offset];
	}

	T& item()
	{
		// Get the item at the 0-th index
		return _data[_offset]
	}

	const Tensor operator[](unsigned int ii) const
	{
		// Index Operator (Const)
		unsigned int sliceOffset = (ii * _shape[0]);
		const Tensor sliceTensor()

	}

	//// Private Interface ////

protected:

	unsigned int sizeFromShape(
		TensorShape& shape)
	{
		// Determine the number of elements from the shape of the supplied vector
		result = 1;
		for (unsigned int ii = 0; ii < shape.size(); ii++)
		{
			result *= shape[ii];
		}
		return result;
	}


};


#endif // !TENSOR