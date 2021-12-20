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

class TensorOperation
{

public:

	/* Generic Tensor Operations */

	// Add Tensor + Scalar
	static Tensor add(const Tensor& op1, const Tensor& op2);

	// Multiply Tensor x Scalar
	static Tensor scale(const Tensor& op1, const Tensor& op2);

	// Compute Matrix Product
	static Tensor matrixProduct(const Tensor& op1, const Tensor& op2);

	// Computer Hadamard Product
	static Tensor hadamardProduct(const Tensor& op1, const Tensor& op2);

	// Compute Dot Product
	static Tensor dotProduct(const Tensor& op1, const Tensor& op2);

	// Compute Matrix Product
	static Tensor matrixProduct(const Tensor& op1, const Tensor& op2);

	/* Helpers to Optimizer Scalar Cases */

	// Add Tensor + Scalar
	static Tensor add(const Tensor& op1, const float op2);

	// Multiply Tensor x Scalar
	static Tensor scale(const Tensor& op1, const float op2);

private:

	/* Helpers to Ensure Shape or Size or Rank */

	// Enforce operands have the Same Number of Elements
	static void enforceSameSize(Tensor& op1, Tensor& op2);

	// Enforce operands have the Same Rank
	static void enforceSameRank(Tensor& op1, Tensor& op2);

	// Enforce operands have the same shape
	static void enforceSameShape(Tensor& op1, Tensor& op2);

	// Enforce operand has particular size
	static void enforceSize(Tensor& op1, const int size);

	// Enforce operand has particular rank
	static void enforceRank(Tensor& op1, const int size);

	// Enforce operand has particular shape
	static void enforceShape(Tensor& op1, const TensorShape shape);

};

