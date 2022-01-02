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

#include "GraphNode.h"
#include "Variable.h"
#include "Operator.h"

int main(int argc, char** argv)
{
	int EXIT_STATUS = 0;

	// Create a 4 x 4 Tensor
	Tensor p(2, TensorShape{ 1,4 });

	// Create a 4 x 2 Tensor
	Tensor q(4, TensorShape{ 4, 2 });

	// Create a 2 x Tensor
	Tensor r(-6, TensorShape{ 1,2 });

	// Wrap the tensors in variable nodes
	Variable inputs("x", &p);
	Variable weights("w", &q);
	Variable biases("b", &r);

	// Join th variables with operator nodes
	Operator matmul("u", TensorOperation::matrixProduct,
		&inputs, &weights);
	Operator add("v",TensorOperation::tensorAdd,
		&matmul, &biases);

	// the Output Node is the add node.
	GraphNode* output = &add;
	output->evaluate();
	output->getValue()->describe(std::cout);

	// Exit
	std::cout << "=)" << std::endl;
	return EXIT_STATUS;
	
}