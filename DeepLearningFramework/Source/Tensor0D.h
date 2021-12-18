/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor0D.h
* Author:		Landon Buell
* Date:			December 2021
* Description:
*/

#pragma once
#include "Tensor.h"

class Tensor0D : public Tensor
{

    // Constructor
    Tensor0D(const float data);

    // Destructor
    ~Tensor0D();

    /* Public Interface */

    // Reshape This Tensor
    bool reshape(const TensorShape& newShape) override;

    // 0D Indexer 
    float& item();
};

