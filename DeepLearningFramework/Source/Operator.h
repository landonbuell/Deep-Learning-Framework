/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	ComputationalGraphs
* File:			Operator.h
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

class Operator : public GraphNode
{

private:

	GraphNode* _opLeft;
	GraphNode* _opRight;

public: 

	// Constructor
	Operator(std::string name, Tensor* value = nullptr,
		GraphNode* left = nullptr, GraphNode* right = nullptr);

	// Copy Constructor
	Operator(const Operator& op);

	// Destructor
	~Operator();

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

