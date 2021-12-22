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

Tensor TensorOperation::add(Tensor& op1, Tensor& op2)
{
	// Add Tensor + Tensor
	if (op2.getRank() == 0 || op2.getSize() == 1)
	{
		// Operand 2 is a scalar
		return add(op1,op2.item())
	}
	else
	{
		// Add Element-wise
		enforceSameShape(op1, op2);
		Tensor result = op1.copyDeep();
		for (int i = 0; i < result.getSize(); i++)
			result[i] += op2[i];
		return result;
	}
}

Tensor TensorOperation::elementProduct(Tensor& op1, Tensor& op2)
{
	// Multiply Tensor x Tensor
	if (op2.getRank() == 0 || op2.getSize() == 1)
	{
		// Operand 2 is a scalar
		return multiply(op1, op2.item())
	}
	else
	{
		// Add Element-wise
		enforceSameShape(op1, op2);
		Tensor result = op1.copyDeep();
		for (int i = 0; i < result.getSize(); i++)
			result[i] *= op2[i];
		return result;
	}
}

Tensor TensorOperation::matrixProduct(Tensor& op1, Tensor& op2)
{
	// Compute Matrix Product
	enforceValidMatrixMultiply(op1, op2);
	const TensorShape resultShape{ op1.getShape()[0],  op2.getShape()[1] };
	const int resultSize = resultShape[0] * resultShape[1];
	const int commonAxis = op1.getShape()[1];

	// Make the result + the indexer obj
	Tensor result(0.0f, resultSize, resultShape);
	Indexer idx{ 0,0 };

	// Iterate through rows + cols
	for (int i = 0; i < resultShape[0]; i++)
	{
		idx[0] = i;
		for (int j = 0; j < resultShape[1]; j++)
		{
			idx[1] = j;
			for (int k = 0; k < commonAxis; k++)
			{
				// Add result[i,j] += a[i,k] * b[k,j]
				result[idx] += op1[Indexer{ i,k }] * op2[Indexer{ k,j }];
			}
		}
	}
	// Return the resuling 2D array
	return result;
}

Tensor TensorOperation::dotProduct(Tensor& op1, Tensor& op2)
{
	// Compute Dot Product
	enforceValidDotProduct(op1, op2);
	Tensor result(0.0f);

	// Calculate
	for (int i = 0; i < op1.getSize(); i++)
	{
		result.item() += (op1[i] * op2[i]);
	}
	return result;
}