/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	None
* File:			TensorOps.cpp
* Author:		Landon Buell
* Date:			December 2021
* Description:
*
*/

#include "TensorOperation.h"

Tensor* TensorOperation::null(Tensor& op1, Tensor& op2)
{
	// Return Null Tensor (Scaler w/ entry 0)
	// Operands do NOT Affect Outcome
	return new Tensor();
}

Tensor* TensorOperation::tensorAdd(Tensor& op1, Tensor& op2)
{
	// Add Tensor + Tensor
	if (op2.getRank() == 0 || op2.getSize() == 1)
	{
		// Operand 2 is a scalar
		return add(op1, op2.item());
	}
	else
	{
		// Add Element-wise
		EnforcersBool::sameShape(op1, op2);
		Tensor* result = new Tensor(op1);
		const int numElems = result->getSize();
		for (int i = 0; i < numElems; i++)
			result->item(i) += op2.item(i);
		return result;
	}
}

Tensor* TensorOperation::multiply(Tensor& op1, Tensor& op2)
{
	// Multiply Tensor x Tensor (Element-Wise)
	if (op2.getRank() == 0 || op2.getSize() == 1)
	{
		// Operand 2 is a scalar
		return multiply(op1, op2.item());
	}
	else
	{
		// Add Element-wise
		EnforcersBool::sameShape(op1, op2);
		Tensor* result = new Tensor(op1);
		const int numElems = result->getSize();
		for (int i = 0; i < numElems; i++)
			result->item(i) *= op2.item(i);
		return result;
	}
}

Tensor* TensorOperation::matrixProduct(Tensor& op1, Tensor& op2)
{
	// Compute Matrix Product
	EnforcersBool::validMatrixMultiply(op1, op2);
	const TensorShape resultShape{ op1.getShape()[0],  op2.getShape()[1] };
	const int commonAxis = op1.getShape()[1];

	// Make the result + the indexer objs for each matrix
	Tensor* result = new Tensor(0.0f, resultShape);
	Indexer idxRes{ 0,0 };
	Indexer idxOp1{ 0,0 };
	Indexer idxOp2{ 0,0 };

	// Iterate through rows + cols
	for (int i = 0; i < resultShape[0]; i++)
	{
		idxRes[0] = i;
		idxOp1[0] = i;
		for (int j = 0; j < resultShape[1]; j++)
		{
			idxRes[1] = j;
			idxOp2[1] = j;
			for (int k = 0; k < commonAxis; k++)
			{
				// Add result[i,j] += a[i,k] * b[k,j]
				idxOp1[0] = k;
				idxOp2[0] = k;
				(*result)[idxRes] += op1[idxOp1] * op2[idxOp2];
			}
		}
	} 
	// Return the resuling 2D array
	return result;
}

Tensor* TensorOperation::dotProduct(Tensor& op1, Tensor& op2)
{
	// Compute Dot Product
	EnforcersBool::sameSize(op1, op2);
	Tensor* result = new Tensor0D(0.0f);
	// Calculate
	const int numElems = op1.getSize();
	for (int i = 0; i < numElems; i++)
	{
		result->item() += (op1.item(i) * op2.item(i));
	}
	return result;
}

Tensor* TensorOperation::add(Tensor& op1, float op2)
{
	// Add Tensor + Scaler
	Tensor* result = new Tensor(op1);
	const int numElems = result->getSize();
	for (int i = 0; i < numElems; i++)
		result->item(i) += op2;
	return result;
}

Tensor* TensorOperation::multiply(Tensor& op1, float op2)
{
	// Mulitply Tensor x Scaler
	Tensor* result = new Tensor(op1);
	const int numElems = result->getSize();
	for (int i = 0; i < numElems; i++)
		result->item(i) *= op2;
	return result;
}

	/* Helpers to Ensure Shape or Size or Rank */

bool TensorOperation::EnforcersBool::sameSize(Tensor& op1, Tensor& op2)
{
	// Enforce operands have the Same Number of Elements
	if (op1.getSize() != op2.getSize())
	{
		// Sizes not equal
		return false;
	}
	return true;
}

bool TensorOperation::EnforcersBool::sameRank(Tensor& op1, Tensor& op2)
{
	// Enforce operands have the Same Number of Elements
	if (op1.getRank() != op2.getRank())
	{
		// Sizes not equal
		return false;
	}
	return true;
}

bool TensorOperation::EnforcersBool::sameShape(Tensor& op1, Tensor& op2)
{
	// Enforce operands have the same shape
	if (sameRank(op1,op2) == false)
	{
		// Different Ranks => Difference Shapes
		return false;
	}
	if (op1.getShape() != op2.getShape())
	{
		// Shapes not equal
		return false;
	}
	return true;
}

bool TensorOperation::EnforcersBool::isSize(Tensor& op, const int size)
{
	// Enforce operand has particular size
	return (op.getSize() == size);
}

bool TensorOperation::EnforcersBool::isRank(Tensor& op, const int size)
{
	// Enforce operand has particular rank
	return (op.getRank() == size);
}

bool TensorOperation::EnforcersBool::isShape(Tensor& op, const TensorShape shape)
{
	// Enforce operand has particular shape
	return (op.getShape() == shape);
}

bool TensorOperation::EnforcersBool::validMatrixMultiply(Tensor& op1, Tensor& op2)
{
	// Enforce Tensors are correct for Matrix Multplication
	if (op1.getRank() != 2) { return false; }
	if (op2.getRank() != 2) { return false; }
	// Make sure inner dimesions match
	const int commonAxisSize = op1.getShape()[1];
	if (op2.getShape()[0] != commonAxisSize) { return false; }
	return true;
}

bool TensorOperation::EnforcersBool::validDotProduct(Tensor& op1, Tensor& op2)
{
	// Enforce Tensors are correct for Dot Product
	if (op1.getRank() != 1) { return false; }
	if (op2.getRank() != 1) { return false; }
	sameSize(op1, op2);
	return true;
}




