/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	Tensors
* File:			Tensor.cpp
* Author:		Landon Buell
* Date:			October 2021
* Description:
*
*/

#include <iostream> 
#include <string>
#include <vector>

#include "Tensor.h"
#include "Tensor1D.h"
#include "Tensor2D.h"
#include "Tensor3D.h"
#include "Tensor4D.h"

int main(int argc, char** argv)
{
	int EXIT_STATUS = 0;

	const int size = 16;
	float* arr = new float[size];
	for (int i = 0; i < size; i++)
		arr[i] = i;
	
	// Create Initial Tensor


	std::cout << "=)" << std::endl;

}