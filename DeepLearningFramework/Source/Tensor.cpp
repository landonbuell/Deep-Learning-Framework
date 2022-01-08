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
	_data = new float[1];
	_ownsData = true;
	_shape = TensorShape{ 1 };
	_sliceSizes = sliceSizes();
}


Tensor::Tensor(const TensorShape& shape)
{
	// Constructor for Tensor
	_size = sizeFromShape(shape);
	_rank = shape.size();
	_data = new float[_size];
	_ownsData = true;
	_shape = TensorShape(shape);
	_sliceSizes = sliceSizes();
}

Tensor::Tensor(float data)
{
	// Constructor for Tensor
	TensorShape shape{ 1, };
	construct(data, shape);
	_rank = 0;
}

Tensor::Tensor(float data, const TensorShape& shape)
{
	// Constructor for Tensor
	construct(data, shape);
}

Tensor::Tensor(float* data, const int size, bool ownsData)
{
	// Constructor for Tensor
	TensorShape shape{ size, };
	construct(data, shape, ownsData);
}

Tensor::Tensor(float* data, const TensorShape& shape, bool ownsData)
{
	// Constructor for Tensor
	construct(data, shape, ownsData);
}

Tensor::Tensor(const Tensor& other)
{
	// Copy Constructor
	_size = other.getSize();
	_rank = other.getRank();
	_data = other.copyUnderlying();
	_ownsData = true;
	_shape = TensorShape(other.getShape());
	_sliceSizes = TensorShape(other._sliceSizes);
}

Tensor& Tensor::operator=(const Tensor& other)
{
	if (this == &other) { return *this; }
	_size = sizeFromShape(other._shape);
	_rank = other._rank;
	_data = other._data;
	_ownsData = true;
	_shape = TensorShape(other._shape);
	_sliceSizes = sliceSizes();
	return *this;
}

Tensor::~Tensor()
{
	// Destructor for Tensr
	destruct();
}

	/* Getters and Setters */

float* Tensor::getData() const
{
	// Get Pointer Directly to Data
	return _data;
}

bool Tensor::getOwnsData() const
{
	// Get T/F if Tensor Owns it's underlying array
	return _ownsData;
}

int Tensor::getSize() const
{
	// Get the Full Size of the Tensor
	return _size;
}

int Tensor::getRank() const
{
	// Get the Number of Axes in the tensor
	return _rank;
}

TensorShape Tensor::getShape() const
{
	// Get the Tensor's Shape
	return _shape;
}

void Tensor::setOwnsData(bool ownsMem)
{
	// Set T/F if Tensor Owns it's underlying array
	_ownsData = ownsMem;
	return;
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

bool Tensor::setData(float* data, const int size, bool ownsData)
{
	// Set Pointer Directly to Data (No Recc. for usage)
	destruct();
	if (size != -1) { _size = size; }
	_ownsData = ownsData;
	_data = data;
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


void Tensor::describe(std::ostream& out)
{
	// Describe this Tensor
	out << "Tensor @ " << _data << "\n"
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
		out << _data[i] << " ";
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
	// Flatten this tensor
	setShape(TensorShape{ _size });
	return;
}

	/* Protected Interface */

void Tensor::construct(float* data, const TensorShape& shape, bool ownsData)
{
	// Helper for Instance construction
	_size = sizeFromShape(shape);
	_rank = shape.size();
	_data = data;
	_ownsData = ownsData;
	_shape = TensorShape(shape);
	_sliceSizes = sliceSizes();
	return;
}

void Tensor::construct(float val,const TensorShape& shape)
{
	// Helper for Instance construction
	_size = sizeFromShape(shape);
	_rank = shape.size();
	_data = new float[_size];
	_ownsData = true;
	_shape = TensorShape(shape);
	_sliceSizes = sliceSizes();

	// Set Each element of data to the value
	for (int i = 0; i < _size; i++)
	{
		_data[i] = val;
	}
	return;
}

void Tensor::destruct()
{
	// Helper for Instance destruction
	if (_ownsData == true && _data != nullptr)
	{
		// We own the data, and it's not nullptr
		delete[] _data;
	}
	_data = nullptr;
	return;
}

float* Tensor::copyUnderlying() const
{
	// Helper to copy underlying array
	float* newData = new float[_size];
	for (int i = 0; i < _size; i++)
	{
		newData[i] = _data[i];
	}
	return newData;
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

const int Tensor::sizeFromShape(const TensorShape& shape) const
{
	// Get size from vector of axis shapes
	int result = 1;
	for (int i = 0; i < shape.size(); i++)
	{
		result *= shape[i];
	}
	return result;
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
			// Check in index of Axis is valid
			if (indexer[i] >= _shape[i])
			{
				// Over indexed this axis
				throw "Tensor::validateAxes(). Invalid index for axis";
			}
			// Increment based on axis sizes
			idx += (indexer[i] * _sliceSizes[i]);
		}
		idx += indexer[_rank - 1];
	}
	const int result = idx;
	return result;
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

/* Operator Overloads */

float& Tensor::item(const int index)
{
	// Get a Refrence to the 0-th item (for scalars)
	validateIndex(index);
	return _data[index];
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
	return _data[idx];
}