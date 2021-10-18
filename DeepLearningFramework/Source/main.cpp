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

int main(int argc, char** argv)
{
	int EXIT_STATUS = 0;

	const int size = 16;
	float* arr = new float[size];
	for (int i = 0; i < size; i++)
		arr[i] = 2.0f * i - 8;

	// Create the Initial Tensor
	Tensor tensorA(arr, size);
	tensorA.describe(std::cout);

	// Create a similar Tensor, But reshape
	Tensor tensorB(arr, size);
	std::vector<int> shapeB{ 4,2,2 };
	tensorB.setShape(shapeB);
	tensorB.describe(std::cout);

	// Get 0-th Item in TensorN
	Tensor tensorC = tensorB[1];
	tensorC.describe(std::cout);

	return EXIT_STATUS;
}