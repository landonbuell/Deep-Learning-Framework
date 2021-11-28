/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	ComputationalGraphs
* File:			GraphNode.h
* Author:		Landon Buell
* Date:			October 2021
* Description:
*
*/

#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<set>

#include "Tensor.h"

class GraphNode
{
	// Parent Class for All GraphNodes

private:

	// Members for Identification + Flow
	std::string _nodeName;
	std::set<GraphNode*> _children;

	Tensor* _value;
	bool _evaluated;

public:

	/* Constructors and Destructors */

	// Constructor
	GraphNode(std::string name);

	// Copy-Constructor
	GraphNode(const GraphNode& graphNode);
	
	// Destructor
	~GraphNode();

public:

	/* Getters and Setters */

	// Get the Name of this Node
	std::string getName() const;

	// Get all Children of this Node
	std::vector<GraphNode*> getChildren() const;

	// Get The Value of this Node
	const Tensor* getValue() const;

	// Get if this Node has been Evaluated
	bool getEvalStatus() const;

	// Set the Value of this Node
	void setValue(Tensor* value);

	// Set the Evaluation Status
	void setEvalStatus(bool status);

public:

	/* Operational Methods */

	// Add Child Node to this Node
	bool add(GraphNode* node);

	// Remove Child Node from this Node
	bool remove(GraphNode* node);

	// Clear All Children of this Graph
	void clearChildren();

	// Clear the Value of this Node
	void clearValue();

	// Evaluate this Node (Abstract)
	// If a VariableNode, Return Variable (self)
	// If a OperatorNode, evaluate the operator using the children and return pointer to freshly allocated node 
	void virtual evaluate() = 0;

protected:

	// Common Code for construction
	void virtual construct();

	// Common Code for destruction
	void virtual destruct();

};

