/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	ComputationalGraphs
* File:			OperatorNode.cpp
* Author:		Landon Buell
* Date:			December 2021
* Description:
*
*/

#include "OperatorNode.h"

OperatorNode::OperatorNode(std::string name, Tensor* value = nullptr,
	GraphNode* left = nullptr, GraphNode* right = nullptr) :
	GraphNode(name,value)
{
	// Constructor
	_opLeft = left;
	_opRight = right;
}

OperatorNode::OperatorNode(const OperatorNode& op)
{
	// Copy Constructor
	_name = op.getName();
	_value = op.getValue();
	_opLeft = op.getLeft();
	_opRight = op.getRight();
}

OperatorNode::~OperatorNode()
{
	// Destructor
}

GraphNode* OperatorNode::getLeft() const
{
	// Get Left Node
	return _opLeft;
}

GraphNode* OperatorNode::getRight() const
{
	// Get Right Node
	return _opRight;
}

void OperatorNode::setLeft(GraphNode* left)
{
	// Set Left Node
	_opLeft = left;
	return;
}

void OperatorNode::setRight(GraphNode* right)
{
	// Set Left Node
	_opRight = right;
	return;
}

bool OperatorNode::isOperator() const
{
	// Get T/F If is Operator Node
	return true;
}

bool OperatorNode::isOperand() const
{
	// Get T/F If is Operand Node
	return false;
}