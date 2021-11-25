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
    Tensor3D(const int size0, const int size1, const int size2);

    // Constructor
    Tensor3D(float data, const int size0, const int size1, const int size2);

    // Constructor
    Tensor3D(float* data, const int size0, const int size1, const int size2);

    // Destructor
    ~Tensor3D();

    /* Public Interface */

    // 1D Indexer - Raises Error
    float& item(const int ii) override;

    // 2D Indexer - Raises Error
    float& item(const int ii, const int jj) override;

    // 3D Indexer 
    float& item(const int ii, const int jj, const int kk) override;

    // 4D Indexer - Raises Error
    float& item(const int ii, const int jj, const int kk, const int ll) override;


};

