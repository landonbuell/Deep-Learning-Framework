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
		arr[i] = i;

	// Create the Initial Tensor
	std::vector<int> shapeA{ 4,2,2 };
	Tensor tensorA(arr, size);
	tensorA.setShape(shapeA);
	tensorA.describe(std::cout);

	// Slice Tensor B
	Tensor tensorB = tensorA[2];
	tensorB.describe(std::cout);


	std::cout << "=)" << std::endl;

}