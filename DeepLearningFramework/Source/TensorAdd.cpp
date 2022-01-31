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
#include "TensorAdd.h"

Tensor* TensorAdd::invoke(
	const Tensor* op1,
	const Tensor* op2)
{
	// Add Two Tensors Together
	if (EnforcersBool::sameShape(op1, op2) == true)
	{
		// Same Shape - Add element-wise
		Tensor* result = new Tensor(*op1);
		elementWise(op1, op2, result);
		return result;
	}
	else
	{
		// Different Shapes - Handle Accordingly
		return nullptr;
	}
}


void TensorAdd::elementWise(
	const Tensor* op1,
	const Tensor* op2,
	Tensor* result)
{
	// Add Items Element-wise
	for (int ii = 0; ii < result->getSize(); ii++)
	{
		result->item(ii) += op2->item(ii);
	}
	return;
}
