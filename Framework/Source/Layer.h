#pragma once

#include<iostream>
#include<string>
#include<vector>

#include "TensorND.h"

class Layer
{

private: /* Private Interface */

	std::string _name;
	std::string _type;

	std::vector<int> _shapeInput;
	std::vector<int> _shapeOutput;

	int _batchSize;
	bool _trainable;
	bool _initialized;

	bool _useWeights0;
	TensorND<float>* _weights0;

	bool _useWeights1;
	TensorND<float>* _weights1;

	bool _useActivations;
	TensorND<float>* _activations;

public:

#pragma region Constructors and Destructors

	// Constructor for Layer Instance
	Layer();

	// Copy-Constructor for Layer Instance
	Layer(const Layer& rhs);

	// Destructor for Layer Instance
	~Layer();

#pragma endregion

protected:

#pragma region Helper Functions

	// Common-Code for Object Construction
	void constructCode();

	// Common-Code for Object Destruction
	void destructCode();

	// Determine if InputShape is valid
	bool validateInputShape(const std::vector<int>& inShape);

#pragma endregion


public:

#pragma region Getter Methods

	std::string getName() const;
	std::string getType() const;

	std::vector<int> getShapeInput() const;
	std::vector<int> getShapeOutput() const;

	int getBatchSize() const;
	bool getIsTrainable() const;
	bool getIsInit() const;

	bool getUseBias() const;
	TensorND<float>* getBiases() const;

	bool getUseWeights() const;
	TensorND<float>* getWeights() const;

	bool getUseActivations() const;
	TensorND<float>* getActivations() const;

#pragma endregion

#pragma region Execution Methods

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

#pragma endregion

protected:

#pragma region Setter Methods

#pragma endregion





};

