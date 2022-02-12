#include "Training_rules.h"
#include <cmath>
#include "pch.h"
#include <math.h>
#include "Process.h"


float perceptron_Train(float* Sample, int numSample, float* weights, int bias, float* target, int numClass, int inputDim) {

	float* Net = new float[numClass];
	float* output = new float[numClass];
	float* desired_output = new float[numClass];
	float Error = 0.0;
	float learning_rate = 1.0;

	int* result = new int[numSample * numClass + 1];


	for (int step = 0; step < numSample; step++) {

		for (int j = 0; j < numClass; j++)
			Net[j] = 0.0;

		for (int k = 0; k < numClass; k++) {//* compute Net
			for (int j = 0; j < inputDim; j++)
				Net[k] += weights[k * (inputDim + 1) + j] * Sample[step * inputDim + j];
			Net[k] += weights[k * (inputDim + 1) + inputDim] * bias;
		}

		for (int k = 0; k < numClass; k++) {
			output[k] = sgn(Net[k]);
		}

		for (int k = 0; k < numClass; k++) {
			if (k == target[step])
				desired_output[k] = 1.0;
			else
				desired_output[k] = -1.0;
		}

		for (int k = 0; k < numClass; k++)
			result[numClass * step + k] = desired_output[k] - output[k];

		for (int k = 0; k < numClass; k++) {
			for (int j = 0; j < inputDim; j++)
				weights[k * (inputDim + 1) + j] += ((learning_rate * (desired_output[k] - output[k]) * Sample[step * inputDim + j]));
			weights[k * (inputDim + 1) + inputDim] += ((learning_rate * (desired_output[k] - output[k]) * bias));
		}
	}

	for (int k = 0; k < numSample * numClass; k++) {
		if (result[k] != 0) {
			Error = 1.0;//continue training
			break;
		}
		else
			Error = 0.0;//Training Done
	}
	return Error;
}