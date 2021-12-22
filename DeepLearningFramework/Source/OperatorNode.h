/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	ComputationalGraphs
* File:			OperatorNode.h
* Author:		Landon Buell
* Date:			October 2021
* Description:
*
*/

#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<array>

#include "GraphNode.h"
#include "TensorOperation.h"

class OperatorNode : public GraphNode
{

private:

	GraphNode* _opLeft;
	GraphNode* _opRight;
	Tensor(*_operation)(Tensor&, Tensor&);

public: 

	// Constructor
	OperatorNode(std::string name, Tensor* value = nullptr,
		GraphNode* left = nullptr, GraphNode* right = nullptr);

	// Copy Constructor
	OperatorNode(const OperatorNode& op);

	// Destructor
	~OperatorNode();

	/* Getters and Setters */

	// Left Left Operand
	GraphNode* getLeft() const;

	// Get Right Operand
	GraphNode* getRight() const;

	// Set Left Operand
	void setLeft(GraphNode* left);

	// Set Right Operand
	void setRight(GraphNode* right);

	/* Operation Methods */

	// Get T/F If is Operator Node
	bool isOperator() const;

	// Get T/F If Is Operand Node
	bool isOperand() const;

	// Evaluate this Node (Abstract)
	// If a VariableNode, Make sure we are not nullptr
	// If a OperatorNode, evaluate the operator using the children and return pointer to freshly allocated 
	void evaluate() = 0;
};

