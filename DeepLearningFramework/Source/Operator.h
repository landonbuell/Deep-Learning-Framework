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

// Create a Typedef for a Tensor Operation
typedef Tensor* (*TensorOp) (Tensor&, Tensor&);

class Operator : public GraphNode
{
	
private:

	TensorOp _operation;
	GraphNode* _opLeft;
	GraphNode* _opRight;
	
public:

	// Empty Constructor
	Operator();

	// Constructor
	Operator(
		std::string name, 
		TensorOp operation, 
		GraphNode* left = nullptr, 
		GraphNode* right = nullptr);

	// Copy Constructor
	Operator(
		const Operator& op);

	// Destructor
	~Operator();

	/* Getters and Setters */

	// Get to pointer to the Tensor Operation
	TensorOp getOperation() const;

	// Left Left Operand
	GraphNode* getLeft() const;

	// Get Right Operand
	GraphNode* getRight() const;

	// Set Left Operand
	void setLeft(GraphNode* left);

	// Set Right Operand
	void setRight(GraphNode* right);

	/* Operation Methods */

	//Describe the current instance
	void describe(std::iostream& out) const override;

	// Get T/F If is Operator Node
	bool isOperator() const;

	// Get T/F If Is Operand Node
	bool isOperand() const;

	// Evaluate this Node (Abstract)
	// If a VariableNode, Make sure we are not nullptr
	// If a Operator, evaluate the operator using the children and return pointer to freshly allocated 
	void evaluate();

};

