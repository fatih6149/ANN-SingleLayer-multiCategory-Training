#include "pch.h"
#include "Process.h"
#include <cmath>

float* Add_Data(float* sample, int Size, float* x, int Dim) {
	float* temp;
	temp = new float[Size * Dim];
	for (int i = 0; i < (Size - 1) * Dim; i++)
		temp[i] = sample[i];
	for (int i = 0; i < Dim; i++)
		temp[(Size - 1) * Dim + i] = x[i];
	//Deallocate memory
	delete[] sample;
	return temp;
}//Add_data
float* Add_Labels(float* Labels, int Size, int label) {
	float* temp;
	temp = new float[Size];
	for (int i = 0; i < Size - 1; i++)
		temp[i] = Labels[i];
	temp[Size - 1] = float(label);
	//Deallocate memory
	delete[] Labels;
	return temp;
}

int YPoint(int x, float* w, int Carpan) {
	return (int)((double)(-1 * (double)Carpan * w[2] - 1 * (w[0] * x)) / (double)(w[1]));
}

int sgn(float net) {
	if (net >= 0)
		return 1;
	else
		return -1;
}

float sigmoid(float net) {
	return (1.0 / (1.0 + pow(euler, -net)));
}

float sigmoid_bipolar(float net) {
	return ((2 / (1 + pow(euler, -net))) - 1);
}
