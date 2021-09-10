/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* Namespace:		Mathematics
* File:				Tensor1D.h
* Author:			Landon Buell
* Date:				August 2021
*
*/

#pragma once

#include<iostream>

#include "Tensor1D.h"
#include "Tensor2D.h"
#include "Tensor3D.h"
#include "Tensor4D.h"

/* Constructors and Destructors*/

Tensor1D::Tensor1D(const int size0, float val = 0) : 
	Tensor(size0, val)
{
	// Constructor for Tensor1D
	_shape.push_back(size0);
}

Tensor1D::Tensor1D(const int size0, float* arr) :
	Tensor(size0,arr)
{
	// Constructor for Tensor2D
	_shape.push_back(size0);
}

Tensor1D::~Tensor1D()
{
	// Destructor for Tensor1D
	this->destructCode();
}

/* Operator Overloads */

float& Tensor1D::operator()(const int ii)
{
	// 1D Access Operator
	return this->operator()(ii);
}

float& Tensor1D::operator()(const int ii, const int jj)
{
	// 1D Access Operator
	std::string errMsg;
	errMsg += "Tensor1D::operator() (const int, const int)";
	errMsg += " - Cannot 2D index a 1D tensor";
	throw errMsg;
}

float& Tensor1D::operator()(const int ii, const int jj, const int kk)
{
	// 1D Access Operator
	std::string errMsg;
	errMsg += "Tensor1D::operator() (const int, const int, const int)";
	errMsg += " - Cannot 3D index a 1D tensor";
	throw errMsg;
}

float& Tensor1D::operator()(const int ii, const int jj, const int kk, const int ll)
{
	// 1D Access Operator
	std::string errMsg;
	errMsg += "Tensor1D::operator() (const int, const int, const int, const int)";
	errMsg += " - Cannot 4D index a 1D tensor";
	throw errMsg;
}
