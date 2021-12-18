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

#include "Tensor.h"

class GraphNode
{
	// Parent Class for All GraphNodes

private:

	// Members for Identification + Flow
	std::string _name;
	Tensor* _value;

public:

	/* Constructors and Destructors */

	// Constructor
	GraphNode(std::string name);

	// Constructor
	GraphNode(std::string name, Tensor* value);

	// Copy-Constructor
	GraphNode(const GraphNode& graphNode);
	
	// Destructor
	~GraphNode();

	/* Getters and Setters */

	// Get the Name of this Node
	std::string getName() const;

	// Get The Value of this Node
	Tensor* getValue() const;

	// Get if this Node has been Evaluated
	bool isEvaluated() const;

	// Clear the Value of this Node
	void clearValue();

	/* Operational Methods */

	// Get T/F If is Operator Node
	bool virtual isOperator() const = 0;

	// Get T/F If Is Operand Node
	bool virtual isOperand() const = 0;

	// Evaluate this Node (Abstract)
	// If a VariableNode, Make sure we are not nullptr
	// If a OperatorNode, evaluate the operator using the children and return pointer to freshly allocated node 
	void virtual evaluate() = 0;

protected:

	// Set the Name of this Node
	void setName(std::string name);

	// Set the Value of this Node
	void setValue(Tensor* value);

	// Common Code for construction
	void virtual construct();

	// Common Code for destruction
	void virtual destruct();


};

