/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	None
* File:			TensorAdd.cpp
* Author:		Landon Buell
* Date:			December 2021
* Description:
*
*/

#pragma once

#include<iostream>
#include<string>

#include "Tensor.h"
#include "TensorOp.h"


class TensorAdd :
    public TensorOp
{

public:

	/* Generic Tensor Operations */

	// Generalized Invoke Method for Arbitary rank Tensors (Returns Tensor if not overloaded)
	Tensor* invoke(
		const Tensor* op1,
		const Tensor* op2) override;

	void invoke(
		const Tensor* op1,
		const Tensor* op2,
		Tensor* out) override;

	// Generalized Derivative for Arbitrary Tensor (Returns Tensor if not overloaded)
	virtual Tensor* derivative(
		const Tensor* op1, 
		const Tensor* op2);

protected:

	// Add Items Element-wise
	void elementWise(
		const Tensor* op1,
		const Tensor* op2,
		Tensor* result);
	
};

