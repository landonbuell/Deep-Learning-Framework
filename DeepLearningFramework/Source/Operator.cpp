/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	ComputationalGraphs
* File:			Operator.cpp
* Author:		Landon Buell
* Date:			December 2021
* Description:
*
*/

#include "Operator.h"

Operator::Operator(std::string name, Tensor* value = nullptr,
	GraphNode* left = nullptr, GraphNode* right = nullptr) :
	GraphNode(name,value)
{
	// Constructor
	_opLeft = left;
	_opRight = right;
}

Operator::Operator(const Operator& op)
{
	// Copy Constructor
	_name = op.getName();
	_value = op.getValue();
	_opLeft = op.getLeft();
	_opRight = op.getRight();
}

Operator::~Operator()
{
	// Destructor
}

GraphNode* Operator::getLeft() const
{
	// Get Left Node
	return _opLeft;
}

GraphNode* Operator::getRight() const
{
	// Get Right Node
	return _opRight;
}

void Operator::setLeft(GraphNode* left)
{
	// Set Left Node
	_opLeft = left;
	return;
}

void Operator::setRight(GraphNode* right)
{
	// Set Left Node
	_opRight = right;
	return;
}

bool Operator::isOperator() const
{
	// Get T/F If is Operator Node
	return true;
}

bool Operator::isOperand() const
{
	// Get T/F If is Operand Node
	return false;
}