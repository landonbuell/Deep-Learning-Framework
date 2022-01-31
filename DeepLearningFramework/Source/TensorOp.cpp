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

#include "TensorOp.h"


void TensorOp::add(
	const Tensor* op1,
	const Tensor* op2,
	Tensor* out)
{
	// Compute the Element-wise addition of two operands
	
	TensorAdd::in
}


Tensor* TensorOp::invoke(
	const Tensor* op1,
	const Tensor* op2)
{
	// Invoke this Operation
	if (op1 == nullptr)
	{
		throw "TensorOp::invoke() - got nullptr for left operand";
	}
	if (op2 == nullptr)
	{
		throw "TensorOp::invoke() - got nullptr for right operand";
	}
	return nullptr;
}

Tensor* TensorOp::derivative(
	const Tensor* op1, 
	const Tensor* op2)
{
	// Invoke the Derivate of this operation
	if(op1 == nullptr)
	{
		throw "TensorOp::invoke() - got nullptr for left operand";
	}
	if (op2 == nullptr)
	{
		throw "TensorOp::invoke() - got nullptr for right operand";
	}
	return nullptr;
}


	/* Helpers to Ensure Shape or Size or Rank */

bool TensorOp::EnforcersBool::sameSize(
	const Tensor* op1,
	const Tensor* op2)
{
	// Enforce operands have the Same Number of Elements
	if (op1->getSize() != op2->getSize())
	{
		// Sizes not equal
		return false;
	}
	return true;
}

bool TensorOp::EnforcersBool::sameRank(
	const Tensor* op1,
	const Tensor* op2)
{
	// Enforce operands have the Same Number of Elements
	if (op1->getRank() != op2->getRank())
	{
		// Sizes not equal
		return false;
	}
	return true;
}

bool TensorOp::EnforcersBool::sameShape(
	const Tensor* op1,
	const Tensor* op2)
{
	// Enforce operands have the same shape
	if (sameRank(op1,op2) == false)
	{
		// Different Ranks => Difference Shapes
		return false;
	}
	if (op1->getShape() != op2->getShape())
	{
		// Shapes not equal
		return false;
	}
	return true;
}

bool TensorOp::EnforcersBool::isSize(
	const Tensor* op1,
	const int targetSize)
{
	// Enforce operand has particular size
	return (op1->getSize() == targetSize);
}

bool TensorOp::EnforcersBool::isRank(
	const Tensor* op1,
	const int targetRank)
{
	// Enforce operand has particular rank
	return (op1->getRank() == targetRank);
}

bool TensorOp::EnforcersBool::isShape(
	const Tensor* op1,
	const TensorShape shape)
{
	// Enforce operand has particular shape
	return (op1->getShape() == shape);
}

bool TensorOp::EnforcersBool::validMatrixMultiply(
	const Tensor* op1,
	const Tensor* op2)
{
	// Enforce Tensors are correct for Matrix Multplication
	if (op1->getRank() != 2) { return false; }
	if (op2->getRank() != 2) { return false; }
	// Make sure inner dimesions match
	const int commonAxisSize = op1->getShape()[1];
	if (op2->getShape()[0] != commonAxisSize) { return false; }
	return true;
}

bool TensorOp::EnforcersBool::validDotProduct(
	const Tensor* op1,
	const Tensor* op2)
{
	// Enforce Tensors are correct for Dot Product
	if (op1->getRank() != 1) { return false; }
	if (op2->getRank() != 1) { return false; }
	return sameSize(op1, op2);
}




