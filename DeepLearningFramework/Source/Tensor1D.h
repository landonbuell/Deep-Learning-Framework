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
    Tensor1D(const int size);

    // Constructor
    Tensor1D(float data, const int size);

    // Constructor
    Tensor1D(float* data, const int size);

    // Destructor
    ~Tensor1D();

    /* Public Interface */

    // 1D Indexer 
    float& item(const int ii) override;

    // 2D Indexer - Raises Error
    float& item(const int ii, const int jj) override;

    // 3D Indexer - Raises Error
    float& item(const int ii, const int jj, const int kk) override;

    // 4D Indexer - Raises Error
    float& item(const int ii, const int jj, const int kk, const int ll) override;


};
