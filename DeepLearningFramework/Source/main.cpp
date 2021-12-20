/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	None
* File:			main.cpp
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

	// Create a Local Array
	const int size = 16;
	float* arr = new float[size];
	for (int i = 0; i < size; i++)
		arr[i] = (float)i;
	
	// Create Initial Tensor
	Tensor alpha(arr, size);
	alpha[Indexer{ 0 }] = 4.0f;
	alpha.describe(std::cout);

	alpha.reshape(TensorShape{ 2,2,4 });
	alpha[Indexer{ 1,0,1 }] = 70.0f;
	alpha.describe(std::cout);


	// Free Memory (handled by shared ptr)
	std::cout << "=)" << std::endl;

}