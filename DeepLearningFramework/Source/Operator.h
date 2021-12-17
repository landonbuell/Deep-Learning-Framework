/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	ComputationalGraphs
* File:			Operator.h
* Author:		Landon Buell
* Date:			October 2021
* Description:
*
*/

#pragma once

#include<iostream>
#include<string>
#include<vector>

#include "GraphNode.h"

class Operator : public GraphNode
{

private:

	


public:

	// Constructor
	Operator(std::string name);

	// Constructor
	Operator(std::string name, Tensor* value);

	// Copy Constructor
	Operator(const Operator& variable);

	// Destructor
	~Operator();

	/* Operation Methods */

	// Get T/F If is Operator Node
	bool isOperator() const;

	// Get T/F If Is Operand Node
	bool isOperand() const;

	// Evaluate this Node (Abstract)
	// If a VariableNode, Make sure we are not nullptr
	// If a OperatorNode, evaluate the operator using the children and return pointer to freshly allocated 
	void evaluate();
};

