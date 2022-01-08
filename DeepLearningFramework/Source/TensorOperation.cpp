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

const TensorOperation* TensorOperation::instance()
{
	// Get A pointer to this instance
	if (_instance.get() == nullptr)
	{
		// No Instance - Make it
		_instance = std::shared_ptr<TensorOperation>(new TensorOperation);
	}
	return _instance.get();
}

Tensor* TensorOperation::nullOp(const Tensor& op1, const Tensor& op2)
{
	// Always return Nullptr
	return nullptr;
}

Tensor* TensorOperation::invoke(const Tensor& op1, const Tensor& op2)
{
	// Generalize Invoke Method for Arbitary rank Tensors (Returns size1 Tensor if not overloaded)
	return new Tensor(TensorShape{1});
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




