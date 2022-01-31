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

	// Create Some Tensors to work with
	Tensor* alpha = new Tensor(TensorShape{ 2,4 });
	Tensor* beta = new Tensor(TensorShape{ 4,3 });
	Tensor* gamma = new Tensor(TensorShape{ 2,4 });
	Tensor* delta = new Tensor();

	// Wrap with Nodes
	Tensor* eta = *alpha + *gamma;



	// Deallocate
	delete alpha;
	delete beta;
	delete gamma;
	delete delta;

	// Exit
	std::cout << "=)" << std::endl;
	return EXIT_STATUS;
	
}