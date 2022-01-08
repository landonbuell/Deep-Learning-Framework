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

#include "GraphNode.h"
#include "Variable.h"
#include "Operator.h"

int main(int argc, char** argv)
{
	int EXIT_STATUS = 0;

	// Create a 4 x 4 Tensor
	Tensor x(2, TensorShape{ 1,4 });

	// Create a 4 x 2 Tensor
	Tensor w(4, TensorShape{ 4, 2 });

	// Create a 2 x Tensor
	Tensor b(-6, TensorShape{ 1,2 });

	// Wrap the tensors in variable nodes
	Variable inputs("x", &x);
	Variable weights("w", &w);
	Variable biases("b", &b);

	// Exit
	std::cout << "=)" << std::endl;
	return EXIT_STATUS;
	
}