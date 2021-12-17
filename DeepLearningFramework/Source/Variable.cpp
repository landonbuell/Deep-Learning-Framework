/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	ComputationalGraphs
* File:			Variable.cpp
* Author:		Landon Buell
* Date:			October 2021
* Description:
*
*/

#include "Variable.h"

/* Constructors and Destructors */

Variable::Variable(std::string name) :
	GraphNode(name)
{
	// Constructor for Variable Instance
}

Variable::Variable(std::string name, Tensor* value) :
	GraphNode(name, value)
{
	// Constructor for Variable Instance
}

Variable::Variable(const Variable& variable) :
	GraphNode(variable)
{
	// Copy Constructor
}

bool Variable::isOperator() const
{
	// Get T/F If is Operator Node
	return false;
}

bool Variable::isOperand() const
{
	// Get T/F if is Operand Node
	return true;
}

void Variable::evaluate()
{
	// Evaluate this node
	// Variable Nodes are already evaluated
	return;
}