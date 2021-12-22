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
#include "OperatorNode.h"

class ComputationalGraph
{
	// Contains all Info for a Computational Graph

private:

	std::string _graphName;
	std::vector<GraphNode*> _graphNodes;
	std::vector<GraphNode*> _evalQueue;

};

