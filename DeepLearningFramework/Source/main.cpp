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
#include "OperatorNode.h"

int main(int argc, char** argv)
{
	int EXIT_STATUS = 0;

	// Create a 4 x 4 Tensor
	Tensor tensorA(2, TensorShape{ 5,4 });

	// Create a 4 x4 Identity Tensor
	Tensor tensorB(4, TensorShape{ 4, 2 });

	// Print the Tensors
	//tensorA.describe(std::cout);
	//tensorB.describe(std::cout);

	/* Create the Graph */
	Variable* A = new Variable("A", &(tensorA));
	Variable* B = new Variable("B", &(tensorB));
	OperatorNode* matmul =
		new OperatorNode("matmul", TensorOperation::matrixProduct, nullptr, A, B);

	// Evaluatethe Node
	matmul->evaluate();
	Tensor* result = matmul->getValue();
	result->describe(std::cout);

	// Free Memory
	delete A;
	delete B;
	return EXIT_STATUS;
}