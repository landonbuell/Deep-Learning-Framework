/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor2D.h
* Author:		Landon Buell
* Date:			October 2021
* Description:
*/

#pragma once
#include "Tensor.h"

class Tensor2D :
    public Tensor
{

public:

    // Constructor
    Tensor2D(const int size0, const int size1);

    // Constructor
    Tensor2D(float data, const int size0, const int size1);

    // Constructor
    Tensor2D(float* data, const int size0, const int size1);

    // Destructor
    ~Tensor2D();

    /* Public Interface */

    // 1D Indexer - Raises Error
    float& item(const int ii) override;

    // 2D Indexer
    float& item(const int ii, const int jj) override;

    // 3D Indexer - Raises Error
    float& item(const int ii, const int jj, const int kk) override;

    // 4D Indexer - Raises Error
    float& item(const int ii, const int jj, const int kk, const int ll) override;


};



