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

#include "TensorAdd.h"

typedef void (*TensorOpCallback)(
	const Tensor* op1, 
	const Tensor* op2,
	Tensor* out);

class TensorOp
{

public:

	////////////////////////////////////////////////
	// Static Callbacks to Invoke Tensor Methods
	// All Callbacks accepts 3 arguments:
	//		const Tensor* op1 - Left Operand
	//		const Tensor* op2 - Right Operand
	//		Tensor* out - output array. In null, fresh array is allocated
	////////////////////////////////////////////////

	// Compute the Element-wise addition of two operands
	static void add(
		const Tensor* op1,
		const Tensor* op2,
		Tensor* out);

	// Compute the Element-wise subtraction of two operands
	static void subtract(
		const Tensor* op1,
		const Tensor* op2,
		Tensor* out);
	
	// Compute the Element-wise multiplication of two operands
	static void multiply(
		const Tensor* op1,
		const Tensor* op2,
		Tensor* out);

	// Compute the Element-wise division of two operands
	static void divide(
		const Tensor* op1,
		const Tensor* op2,
		Tensor* out);

	// Compute the scalar product of two operands
	static void dotProduct(
		const Tensor* op1,
		const Tensor* op2,
		Tensor* out);

	// Compute the matrix product of two operands
	static void matrixProduct(
		const Tensor* op1,
		const Tensor* op2,
		Tensor* out);

protected:
	/* Generic Tensor Operations */

	


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


};

