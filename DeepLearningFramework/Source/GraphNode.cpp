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
	_value = value;
}

GraphNode::GraphNode(const GraphNode& graphNode)
{
	// Constructor for GraphNode Instance (Copy)
	_name = graphNode.getName();
	_value = graphNode.getValue();
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
	return _value;
}

bool GraphNode::isEvaluated() const
{
	// Get the Evaluation Status of this Node
	return !(_value == nullptr);
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
	_value = value;
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
	if (_value != nullptr)
	{
		// Destroy
		delete _value;
		_value = nullptr;
	}
	return;
}