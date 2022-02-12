#pragma once
#include "Form1.h"
#include "Process.h"
#include <cmath>



float perceptron_Train(float* Sample, int numSample, float* weights, int bias, float* target, int numClass, int inputDim);


float delta_train(float* Sample, int numSample, float* weights, int bias, float* target, int numClass, int inputDim);