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

GraphNode::GraphNode(std::string name)
{
	// Constructor for GraphNode Instance
	_nodeName = name;
	_children = std::vector<GraphNode*>();

	_value = nullptr;
	_evaluated = false;
}

GraphNode::GraphNode(const GraphNode& graphNode)
{
	// Constructor for GraphNode Instance (Copy)
	_nodeName = graphNode.getName();
	_children = graphNode.getChildren();

	_value = graphNode._value;
	_evaluated = graphNode.getEvalStatus();
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
	return _nodeName;
}

std::vector<GraphNode*> GraphNode::getChildren() const
{
	// Get all of the Children of this Node
	return _children;
}

const Tensor* GraphNode::getValue() const
{
	// Get the Value of this Node
	if (_evaluated == true)
	{
		return _value;
	}
	else
	{
		return nullptr;
	}
}

bool GraphNode::getEvalStatus() const
{
	// Get the Evaluation Status of this Node
	return _evaluated;
}

void GraphNode::setValue(Tensor* value)
{
	// Set the Value of this Node
	_value = value;
	if (_value != nullptr)
		_evaluated = true;
	else
		_evaluated = false;
}

void GraphNode::setEvalStatus(bool status)
{
	// Set the Evaluation Status
	_evaluated = status;
	return;
}

/* Operational Methods */

bool GraphNode::add(GraphNode* node)
{
	// Add Child Node to this Node
	_children.insert(node);
	return true;
}

bool GraphNode::remove(GraphNode* node)
{
	// Remove Child Node from this Node
	_children.erase(node);
	return true;
}

void GraphNode::clearChildren()
{
	// Clear All Children of this Graph
	_children.clear();
	return;
}

void GraphNode::clearValue()
{
	// Clear the Value of This Node
	_value = nullptr;
	_evaluated = false;
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
	// TODO: Implement this
	return;
}