/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor.cpp
* Author:		Landon Buell
* Date:			October 2021
* Description:
*
*/

#include "Tensor.h"

	/* Constructors and Destructors */

Tensor::Tensor()
{
	// Constructor 
	_size = 1;
	_rank = 0;
	_data = std::shared_ptr<float>(new float[1]);;
	_shape = TensorShape{ 1 };
	_sliceSizes = sliceSizes();
}

Tensor::Tensor(const int size)
{
	// Constructor 
	float* dataPtr = new float[size];
	TensorShape shape{ 1 };
	copyShallow(dataPtr, size, shape);
	dataPtr = nullptr;
}

Tensor::Tensor(const int size, const TensorShape& shape)
{
	// Constructor for Tensor (From Value)
	float* dataPtr = new float[size];
	copyShallow(dataPtr, size, shape);
	dataPtr = nullptr;
}

Tensor::Tensor(float data)
{
	// Constructor for 0-Tensor (From Value) 
	_size = 1;
	_rank = 0;
	_data = std::shared_ptr<float>(new float[1]);;
	_shape = TensorShape{ 1 };
	_sliceSizes = sliceSizes();

	// Set Scalar to Values
	_data.get()[0] = data;
}

Tensor::Tensor(float data, const int size)
{
	// Constructor for Tensor (From Value)
	TensorShape shape{ size };
	copyShallow(data, size, shape);
}

Tensor::Tensor(float data, const int size, const TensorShape& shape)
{
	// Constructor for Tensor
	copyShallow(data, size, shape);
}

Tensor::Tensor(float* data)
{
	// Constructor for 0-Tensor (From Pointer)
	_size = 1;
	_rank = 0;
	_data = std::shared_ptr<float>(data);;
	_shape = TensorShape{ 1 };
	_sliceSizes = sliceSizes();
}

Tensor::Tensor(float* data, const int size)
{
	// Constructor for Tensor (From Pointer)
	TensorShape shape{ size };
	copyShallow(data, size, shape);
}

Tensor::Tensor(float* data, const int size, const TensorShape& shape)
{
	// Constructor for Tensor (From Pointer)
	copyShallow(data, size, shape);
}

Tensor::~Tensor()
{
	// Destructor for Tensor
	destructCode();
}

Tensor::Tensor(const Tensor& other)
{
	// Copy Constructor
	_size = other.getSize();
	_rank = other.getRank();
	_data = std::shared_ptr<float>(other._data);
	_shape = TensorShape(other.getShape());
	_sliceSizes = TensorShape(other._sliceSizes);
}


	/* Getters and Setters */

float* Tensor::getData() const
{
	// Get Pointer Directly to Data
	return (_data.get());
}

int Tensor::getSize() const
{
	// Get the Full Size of the Tensor
	return _size;
}

int Tensor::getRank() const
{
	// Get the Number of Axes in the tensor
	if (_size == 1)
	{
		// Only 1 element, it's a 0-Rank Tensor
		return 0;
	}
	return _shape.size();
}

TensorShape Tensor::getShape() const
{
	// Get the Tensor's Shape
	return _shape;
}

void Tensor::setSize(const int size)
{
	// Set the Size of this Tensor
	if (size <= _size)
		_size = size;
	else
		throw "Cannot Increase Size, may cause seg-faults!";
	return;
}

void Tensor::setRank(const int rank)
{
	// Set the Rank of this Tensor
	_rank = rank;
}

bool Tensor::setData(float* data)
{
	// Set Pointer Directly to Data (No Recc. for usage)
	_data = nullptr;
	_data = std::shared_ptr<float>(data);
	return true;
}

bool Tensor::setShape(const TensorShape& newShape)
{
	// Set the Tensor's Shape (T/F if successful)
	bool success = false;
	if (validateReshape(newShape))
	{
		_rank = newShape.size();
		_shape = std::vector<int>(newShape);
		_sliceSizes = sliceSizes();
		success = true;
	}
	return success;
}

	/* Public Interface */

Tensor Tensor::copyDeep() const
{
	// Make a Deep Copy of this Tensor
	Tensor result(_size, _shape);
	float* dataPtr = _data.get();
	for (int i = 0; i < _size; i++)
		result[i] = dataPtr[i];
	dataPtr = nullptr;
	return result;
}

void Tensor::describe(std::ostream& out)
{
	// Describe this Tensor
	float* dataPtr = _data.get();
	out << "Tensor @ " << dataPtr << "\n"
		<< "size: " << _size << " "
		<< "rank: " << _rank << " "

	// Show the Shape
		<< "shape: (";
	for (int i = 0; i < _rank; i++)
		out << _shape[i] << ",";
	out << ") ";

	// Show the Underlying Data
	out << "\n";
	for (int i = 0; i < _size; i++)
		out << dataPtr[i] << " ";
	out << "\n\n";
	return;
}

bool Tensor::reshape(const TensorShape& newShape)
{
	// Reshape This Tensor
	bool success = setShape(newShape);
	return success;
}

void Tensor::flatten()
{
	// Flatten thid tensor
	setShape(TensorShape{ _size });
	return;
}

	/* Protected Interface */

void Tensor::copyShallow(float data, const int size, const TensorShape& shape)
{
	// HelperFunction to Perform a Shallow Copy
	_size = size;
	_rank = shape.size();
	_data = std::shared_ptr<float>(new float[size]);
	_shape = shape;
	_sliceSizes = sliceSizes();

	// Copy Value into Data
	float* dataPtr = _data.get();
	for (int i = 0; i < _size; i++)
		dataPtr[i] = data;
	dataPtr = nullptr;
	return;
}

void Tensor::copyShallow(float* data, const int size, const TensorShape& shape)
{
	// HelperFunction to Perform a Shallow Copy
	_size = size;
	_rank = shape.size();
	_data = std::shared_ptr<float>(data);
	_shape = shape;
	_sliceSizes = sliceSizes();

	return;
}

bool Tensor::validateIndex(const int index) const
{
	// Helper Function to valid slice index
	if (index < 0)
		throw "Tensor::validateSliceIndex - Index must be positive";
	if (index >= _size)
		throw "Tensor::validateSliceIndex - Index must be smaller than " + _size;
	// Otherwise, the index is valid
	return true;
}

const int Tensor::indexFromIndexer(const Indexer& indexer) const
{
	// Helper Function to get index from indexer	
	int idx = 0;
	if (indexer.size() == 1)
	{
		// 1D Indexer
		idx = indexer[0];
	}
	else
	{
		// Compute High Dimensional index
		for (int i = 0; i < _rank - 1; i++)
		{
			// Increment based on axis sizes
			idx += (indexer[i] * _sliceSizes[i]);
		}
		idx += indexer[_rank - 1];
	}
	const int result = idx;
	return result;
}

TensorShape Tensor::sliceSizes() const
{
	// Find size of "pseudo-slices" when indexing	
	if (_rank > 1)
	{
		TensorShape result(_rank - 1, 0);
		int sliceSize = 1;
		for (int i = _rank - 1; i > 0; i--)
		{
			sliceSize *= _shape[i];
			result[i - 1] = sliceSize;
		}
		return result;
	}
	else
	{
		TensorShape result{ 1 };
		return result;
	}	
	

}

bool Tensor::validateReshape(const TensorShape& newShape) const
{
	// Helper Function to validate new shape
	int size = 1;
	for (int i = 0; i < newShape.size(); i++)
	{
		size *= newShape[i];
	}
	// Check Shape
	if (size != _size)
	{
		// Sizes not equal
		return false;
	}
	else
	{
		// Otherwise, the new shape is valid
		return true;
	}
}

void Tensor::destructCode()
{
	// Common code for object destruction
	_data.reset();
}

/* Operator Overloads */

float& Tensor::item()
{
	// Get a Refrence to the 0-th item (for scalars)
	return (_data.get()[0]);
}

float& Tensor::operator[] (const int index)
{
	// Index Slice Operator
	validateIndex(index);
	return (_data.get()[index]);
}

float& Tensor::operator[] (const Indexer& index)
{
	// Multi-dimensional Indexer
	if (_rank == 0)
	{
		// Rank-0 Tensor?
		throw "Tensor::operator[] - Cannot Index Scalar Tensor";
	}
	else if (index.size() != _rank )
	{
		// Indexer must be the same size as Rank
		throw "Tensor::operator[] - Indexer size must match rank";
	}
	// Check that The Index is Valid
	const int idx = indexFromIndexer(index);
	validateIndex(idx);
	return _data.get()[idx];
}