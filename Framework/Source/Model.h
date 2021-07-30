#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "ComputationalGraph.h"
#include "Layer.h"
#include "TensorND.h"

class Model
{
	// Parent Class For All Model 

#pragma region Feilds

private:

	std::string _name;
	std::string _type;

	ComputationalGraph* _graph;

#pragma endregion

#pragma region Constructors and Destructors

public: 

	// Constructor for Model Istance
	Model(std::string name);

	// Constructor for Model Instance
	Model(std::string name, std::vector<Layer&> inputs, Layer& output);

	Model(const Model& rhs);

	// Destructor for Model Instance
	~Model();

#pragma endregion

#pragma region Getters and Setters

public:

	std::string getName() const;
	std::string getType() const;

	ComputationalGraph* getGraph() const;

protected:

	void setName(std::string name);
	void setType(std::string type);

#pragma endregion

#pragma region Execution Methods

public:

	void Train(TensorND<float>& X, TensorND<float>& Y, int epochs);

	void Predict(TensorND<float>& X);

protected:

	void Call()

#pragma endregion






};

