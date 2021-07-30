#pragma once

#include<iostream>
#include<string>
#include<vector>

#include "TensorND.h"

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

	TensorND<float>* _weights0;	
	TensorND<float>* _weights1;

	bool _useActivations;
	TensorND<float>* _activations;

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

	TensorND<float>* getBaises() const;
	TensorND<float>* getWeights() const;

	bool getUseActivations() const;
	TensorND<float>* getActivations() const;

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

	bool setBiases(TensorND<float>* newBias);
	bool setWeights(TensorND<float>* newWeights);

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
	void callLayer(TensorND<float>* X);

	// Update Bias Vector
	void updateBiases(TensorND<float>* diffBias, float rate);

	// Update Weight Vector
	void updateWeights(TensorND<float>* diffWeight, float rate);

	// Describe the model at a chosen verbosity level
	void describe(int level);

#pragma endregion

};

