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
#include "Tensor2D.h"

int main(int argc, char** argv)
{
	int EXIT_STATUS = 0;

	// Create a 4 x 4 Tensor
	//Tensor tensorA(2, 16, TensorShape{ 4,4 });

	// Create a 4 x4 Identity Tensor
	Tensor2D tensorB = Tensor2D::identity(1.0f, 4);

	// Print the Tensors
	//tensorA.describe(std::cout);
	tensorB.describe(std::cout);

	// Free Memory (handled by shared ptr)
	std::cout << "=)" << std::endl;

}