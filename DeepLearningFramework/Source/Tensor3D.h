/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor3D.h
* Author:		Landon Buell
* Date:			October 2021
* Description:
*/

#pragma once
#include "Tensor.h"

class Tensor3D : public Tensor
{

public:

    // Constructor
    Tensor3D(
        const int size0, 
        const int size1, 
        const int size2);

    // Constructor
    Tensor3D(
        float data, 
        const int size0, 
        const int size1, 
        const int size2);

    // Constructor
    Tensor3D(
        float* data, 
        const int size0, 
        const int size1, 
        const int size2, 
        bool ownsData = true);

    // Destructor
    ~Tensor3D();

    /* Public Interface */

    // Reshape This Tensor
    bool reshape(const TensorShape& newShape) override;

    // 3D Indexer 
    float& item(const int ii, const int jj, const int kk);

};

