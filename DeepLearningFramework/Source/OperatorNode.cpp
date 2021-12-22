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

OperatorNode::OperatorNode(std::string name, TensorOp operation,
	Tensor* value, GraphNode* left, GraphNode* right) :
	GraphNode(name,value)
{
	// Constructor
	_operation = operation;
	_opLeft = left;
	_opRight = right;
}

OperatorNode::OperatorNode(Tensor* value, GraphNode* left, GraphNode* right) :
	GraphNode("-1",value)
{
	// Constructor
	_operation = TensorOperation::null;
	_opLeft = left;
	_opRight = right;
}

OperatorNode::OperatorNode(const OperatorNode& opNode)
{
	// Copy Constructor
	_name = opNode.getName();
	_value = nullptr;
	_operation = opNode.getOperation();
	_opLeft = opNode.getLeft();
	_opRight = opNode.getRight();

	// Copy Value, if opNode is evaluated
	if (opNode.isEvaluated() == true)
	{
		_value = opNode.getValue();
	}

}

OperatorNode::~OperatorNode()
{
	// Destructor
	_operation = nullptr;
	destruct();
}

TensorOp OperatorNode::getOperation() const
{
	// Get to pointer to the Tensor Operation
	return _operation;
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

void OperatorNode::evaluate()
{
	// Evaluate this Tensor
	if (isEvaluated() == true)
	{
		// Node is already evaluated
		return;
	}
	// Make sure that the left + right operands have been evaluated
	if (_opLeft->isEvaluated() == false)
	{
		// Left operand is NOT evaluated
		// Evaluate it (Depth-First recursive)
		_opLeft->evaluate();
	}
	if (_opRight->isEvaluated() == false)
	{
		// Eight operand is NOT evaluated
		// Evaluate it (Depth-First recursive)
		_opRight->evaluate();
	}
	// Evaluate the operation on  THIS node + Attatch
	Tensor result = _operation(
		*(_opLeft->getValue()),
		*(_opRight->getValue()) );
	_value = &(result);
	return;
}