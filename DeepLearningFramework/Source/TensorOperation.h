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

class TensorOperation
{

public:

	/* Generic Tensor Operations */

	// Return Null Tensor
	static Tensor* null(Tensor& op1, Tensor& op2);

	// Add Tensor + Tensor
	static Tensor* tensorAdd(Tensor& op1, Tensor& op2);

	// Multiply Tensor x Tensor
	static Tensor* multiply(Tensor& op1, Tensor& op2);

	// Compute Matrix Product
	static Tensor* matrixProduct(Tensor& op1, Tensor& op2);

	// Compute Dot Product
	static Tensor* dotProduct(Tensor& op1, Tensor& op2);

	/* Helpers to Optimizer Scalar Cases */

	// Add Tensor + Scalar
	static Tensor* add(Tensor& op1, float op2);

	// Multiply Tensor x Scalar
	static Tensor* multiply(Tensor& op1, float op2);

private:

	/* Helpers to Operate by Rank */

	static Tensor* matrixProduct(Tensor2D& op1, Tensor2D& op2);


	/* Helpers to Ensure Shape or Size or Rank */

	class EnforcersBool
	{
		// Boolean Enforcer Methods return T/F if evaluation is successful

	public:

		// Enforce operands have the Same Number of Elements
		static bool sameSize(Tensor& op1, Tensor& op2);

		// Enforce operands have the Same Rank
		static bool sameRank(Tensor& op1, Tensor& op2);

		// Enforce operands have the same shape
		static bool sameShape(Tensor& op1, Tensor& op2);

		// Enforce operand has particular size
		static bool isSize(Tensor& op, const int size);

		// Enforce operand has particular rank
		static bool isRank(Tensor& op, const int size);

		// Enforce operand has particular shape
		static bool isShape(Tensor& op, const TensorShape shape);

		// Enforce Tensors are correct for Matrix Multplication
		static bool validMatrixMultiply(Tensor& op1, Tensor& op2);

		// Enforce Tensors are correct for Dot Product
		static bool validDotProduct(Tensor& op1, Tensor& op2);
	};

	class EnforcersFatal
	{
		// Fatal Enforcers throw Runtime Errors if evaluation is not sucessful
	};

	

};

