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
#include "TensorOp.h"

#include "GraphNode.h"
#include "Variable.h"
#include "Operator.h"

int main(int argc, char** argv)
{
	int EXIT_STATUS = 0;

	// Create a 4 x 4 Tensor
	Tensor* x = new Tensor(2, TensorShape{ 1,4 });

	// Create a 4 x 2 Tensor
	Tensor* w = new Tensor(4, TensorShape{ 4, 2 });

	// Create a 4 x 2 Tensor
	Tensor* b = new Tensor(-6, TensorShape{ 4, 2 });

	// Create a 4 x 2 Tensor
	Tensor* z = new Tensor(TensorShape{ 4, 2 });

	// Add Tensors Together
	TensorOp::add(w, b, z);


	// De-Allocate
	delete x;
	delete w;
	delete b;
	delete z;


	// Exit
	std::cout << "=)" << std::endl;
	return EXIT_STATUS;
	
}