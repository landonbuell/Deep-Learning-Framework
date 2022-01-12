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

Operator::Operator(
	std::string name, 
	std::shared_ptr<TensorOp> operation,
	GraphNode* left,
	GraphNode* right) :
	GraphNode(name,nullptr)
{
	// Constructor
	_operation = std::shared_ptr<TensorOp>(operation);
	_opLeft = left;
	_opRight = right;
}

Operator::Operator(const Operator& opNode)
{
	// Copy Constructor
	_name = opNode.getName();
	_value = nullptr;
	_operation = std::shared_ptr<TensorOp>(opNode._operation);
	_opLeft = opNode.getLeft();
	_opRight = opNode.getRight();

	if (opNode._value != nullptr)
	{
		_value = std::shared_ptr<Tensor>(opNode._value);
	}
}

Operator::~Operator()
{
	// Destructor
	_operation = nullptr;
	destruct();
}

TensorOp* Operator::getOperation() const
{
	// Get to pointer to the Tensor Operation
	return _operation.get();
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

void Operator::describe(std::iostream& out) const
{
	//Describe the current instance
	out << "Operator Node Instance @ " << &*(this) << "\n";
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

void Operator::evaluate()
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
		// Right operand is NOT evaluated
		// Evaluate it (Depth-First recursive)
		_opRight->evaluate();
	}
	// Evaluate the operation on  THIS node + Attatch
	Tensor* result = getOperation()->invoke(
		_opLeft->getValue(),
		_opRight->getValue()
		);
	setValue(result);
	return;
}

void Operator::destruct()
{
	// Helper function for object destruction
	_value = std::shared_ptr<Tensor>(nullptr);
	_operation = std::shared_ptr<TensorOp>(nullptr);
	_opLeft = nullptr;
	_opRight = nullptr;
}

