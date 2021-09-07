/*
*
* Repository:		Deep-Learning-Framework
* Solution:			DeepLearningFramework
* Project:			Source
* File:				Tensor1D.h
* Author:			Landon Buell
* Date:				August 2021
*
*/

#pragma once

#include<iostream>

#include "Tensor.h"
#include "Tensor2D.h"
#include "Tensor3D.h"
#include "Tensor4D.h"

class Tensor1D : public Tensor
{

public:

	float& operator[] (const int index);

};
