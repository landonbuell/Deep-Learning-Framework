#pragma once

#include<iostream>
#include<string>
#include<vector>

#include "Tensor.h"
#include "Tensor1D.h"
#include "Tensor2D.h"

class Layer
{

#pragma region Feilds

private: /* Private Interface */

	std::string _name;
	std::string _type;

	std::vector<int> _shapeInput;
	std::vector<int> _shapeOutput;

	int _batchSize;
	bool _initialized;

	bool _useWeights0;
	bool _useWeights1;

	bool _trainWeights0;
	bool _trainWeights1;

	Tensor<float>* _weights0;	
	Tensor<float>* _weights1;

	bool _useActivations;
	Tensor<float>* _activations;

#pragma endregion

#pragma region Constructors and Destructors

public:

	// Constructor for Layer Instance
	Layer(std::string name);

	// Copy-Constructor for Layer Instance
	Layer(const Layer& rhs);

	// Destructor for Layer Instance
	~Layer();

#pragma endregion



#pragma region Helper Functions

protected:

	// Common-Code for Object Construction
	void constructCode();

	// Common-Code for Object Destruction
	void destructCode();

	// Determine if InputShape is valid
	bool validateInputShape(const std::vector<int>& inShape);

#pragma endregion

#pragma region Getter and Setter Methods

public:

	std::string getName() const;
	std::string getType() const;

	std::vector<int> getShapeInput() const;
	std::vector<int> getShapeOutput() const;

	int getBatchSize() const;
	bool getIsInitialized() const;

	bool getUseBaises() const;
	bool getUseWeights() const;

	bool getTrainBaises() const;
	bool getTrainWeights() const;

	Tensor<float>* getBaises() const;
	Tensor<float>* getWeights() const;

	bool getUseActivations() const;
	Tensor<float>* getActivations() const;

protected:

	void setName(std::string name);
	void setType(std::string type);

	void setUseBiases(bool useBias);
	void setUseWeights(bool useWeights);

	void setTrainBiases(bool trainBias);
	void setTrainWeights(bool trainWeghts);


	void setUseActivations(bool useActivs);
	void setActivations(bool newActivs);

public:

	bool setShapeInput(std::vector<int> newShape);
	bool setShapeOutput(std::vector<int> newShape);

	void setBatchSize(int newSize);
	void setIsInitialized(bool init);

	bool setBiases(Tensor<float>* newBias);
	bool setWeights(Tensor<float>* newWeights);

#pragma endregion

#pragma region Execution Methods

public:

	// Construct Layer
	bool buildLayer();

	// Construct Layer, Given input shape
	bool buildLayer(std::vector<int>& inputShape);

	// Call Forward-Pass on layer
	void callLayer();

	// Call Forward-Pass on layer
	void callLayer(Tensor<float>* X);

	// Update Bias Vector
	void updateBiases(Tensor<float>* diffBias, float rate);

	// Update Weight Vector
	void updateWeights(Tensor<float>* diffWeight, float rate);

	// Describe the model at a chosen verbosity level
	void describe(int level);

#pragma endregion

};

