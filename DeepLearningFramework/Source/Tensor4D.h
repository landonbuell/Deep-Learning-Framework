/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor4D.h
* Author:		Landon Buell
* Date:			October 2021
* Description:
*
*/

#pragma once
#include "Tensor.h"

class Tensor4D : public Tensor
{

    // Constructor
    Tensor4D(
        const int size0, 
        const int size1, 
        const int size2, 
        const int size3);

    // Constructor
    Tensor4D(
        float data, 
        const int size0, 
        const int size1, 
        const int size2, 
        const int size3);

    // Constructor
    Tensor4D(
        float* data, 
        const int size0, 
        const int size1, 
        const int size2, 
        const int size3,
        bool ownsData = true);

    // Destructor
    ~Tensor4D();

    /* Public Interface */

    // Reshape This Tensor
    bool reshape(const TensorShape& newShape) override;

    // 4D Indexer
    float& item(const int ii, const int jj, const int kk, const int ll);


};

