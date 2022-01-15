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

#pragma once

#include<iostream>
#include<string>

#include "Tensor.h"
#include "Tensor0D.h"
#include "Tensor1D.h"
#include "Tensor2D.h"
#include "Tensor3D.h"
#include "Tensor4D.h"

class TensorOp
{

public:

	/* Generic Tensor Operations */

	// Get A pointer to this instance
	static const TensorOp* instance();

	// Generalized Invoke Method for Arbitary rank Tensors (Returns Tensor if not overloaded)
	virtual Tensor* invoke(
		const Tensor* op1, 
		const Tensor* op2);

	// Generalized Derivative for Arbitrary Tensor (Returns Tensor if not overloaded)
	virtual Tensor* derivative(
		const Tensor* op1, 
		const Tensor* op2);


protected:

	/* Helpers to Ensure Shape or Size or Rank */

	class EnforcersBool
	{
		// Boolean Enforcer Methods return T/F if evaluation is successful

	public:

		// Enforce operands have the Same Number of Elements
		static bool sameSize(
			const Tensor* op1, 
			const Tensor* op2);

		// Enforce operands have the Same Rank
		static bool sameRank(
			const Tensor* op1,
			const Tensor* op2);

		// Enforce operands have the same shape
		static bool sameShape(
			const Tensor* op1,
			const Tensor* op2);

		// Enforce operand has particular size
		static bool isSize(
			const Tensor* op1,
			const int targetSize);

		// Enforce operand has particular rank
		static bool isRank(
			const Tensor* op1,
			const int targetRank);

		// Enforce operand has particular shape
		static bool isShape(
			const Tensor* op1,
			const TensorShape shape);

		// Enforce Tensors are correct for Matrix Multplication
		static bool validMatrixMultiply(
			const Tensor* op1, 
			const Tensor* op2);

		// Enforce Tensors are correct for Dot Product
		static bool validDotProduct(
			const Tensor* op1, 
			const Tensor* op2);
	};

	class EnforcersFatal
	{
		// Fatal Enforcers throw Runtime Errors if evaluation is not sucessful
	};

	// Private Constructor - Does nothing!
	TensorOp();

	// Static Memeber - Shared Ptr
	static std::shared_ptr<TensorOp> _instance;

};

