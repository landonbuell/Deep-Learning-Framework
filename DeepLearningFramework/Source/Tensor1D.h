/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor1D.h
* Author:		Landon Buell
* Date:			October 2021
* Description:
*/

#pragma once
#include "Tensor.h"

class Tensor1D :
    public Tensor
{

public:

    // Constructor
    Tensor1D(
        const int size);

    // Constructor
    Tensor1D(
        float data, 
        const int size);

    // Constructor
    Tensor1D(
        float* data, 
        const int size, 
        bool ownsData = true);

    // Destructor
    ~Tensor1D();

    /* Public Interface */

    // Reshape This Tensor
    bool reshape(const TensorShape& newShape) override;

    // 1D Indexer 
    float& item(const int ii);

};

