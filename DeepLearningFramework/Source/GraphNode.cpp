/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	ComputationalGraphs
* File:			GraphNode.cpp
* Author:		Landon Buell
* Date:			October 2021
* Description:
*
*/

#include "GraphNode.h"

/* Constructors and Destructors */

GraphNode::GraphNode()
{
	// Empty Constructor for GraphNode Instance
	_name = "-1";
	_value = nullptr;
}

GraphNode::GraphNode(std::string name, Tensor* value)
{
	// Constructor for GraphNode Instance
	_name = name;
	_value = std::shared_ptr<Tensor>(value);
}

GraphNode::GraphNode(const GraphNode& graphNode)
{
	// Constructor for GraphNode Instance (Copy)
	_name = graphNode.getName();
	_value = std::shared_ptr<Tensor>(graphNode._value);
}

GraphNode::~GraphNode()
{
	// Destructor for GraphNode Instance
	destruct();
}

/* Getters and Setters */

std::string GraphNode::getName() const
{
	// Get the Name of this Node
	return _name;
}

Tensor* GraphNode::getValue() const
{
	// Get the Value of this Node
	return _value.get();
}

bool GraphNode::isEvaluated() const
{
	// Get the Evaluation Status of this Node
	return !(_value.get() == nullptr);
}

void GraphNode::clearValue()
{
	// Clear the Value of This Node
	_value = nullptr;
	return;
}

void GraphNode::setName(std::string name)
{
	// Set the Name of this Node
	_name = name;
	return;
}

void GraphNode::setValue(Tensor* value)
{
	// Set the Value of this Node
	_value = std::shared_ptr<Tensor>(value);
	return;
}

void GraphNode::construct()
{
	// Common Code for construction
	// TODO: Implement this
	return;
}

void GraphNode::destruct()
{
	// Common Code for destruction
	_value = std::shared_ptr<Tensor>(nullptr);
	return;
}