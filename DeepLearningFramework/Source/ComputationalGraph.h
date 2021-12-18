/*
*
* Repository:	Deep-Learning-Framework
* Solution:		DeepLearingFramework
* Project:		Source
* Namespace:	ComputationalGraphs
* File:			ComputationalGraph.h
* Author:		Landon Buell
* Date:			October 2021
* Description:
*
*/

#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<stack>

#include "GraphNode.h"
#include "Variable.h"
#include "Operator.h"

class ComputationalGraph
{
	// Contains all Info for a Computational Graph

private:

	std::string _graphName;
	std::vector<GraphNode*> _graphNodes;
	std::stack<GraphNode*> _evaluationStack;
	
	Variable _headNode;


};

