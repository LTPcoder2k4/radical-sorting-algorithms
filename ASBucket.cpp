#include "ASBucket.h"

ASBucket::ASBucket() {
	this->size = 0;
	this->bucket = 0;
}

void ASBucket::Add(float data) {
	float* newBucket = new float[this->size + 1];

	bool isAdded = false;
	int k = 0;
	for (int i = 0; i < this->size; i++) {
		if (this->bucket[k] > data) {
			newBucket[i] = data;
			isAdded = true;
		}
		else newBucket[i] = this->bucket[k++];
	}

	if (isAdded) newBucket[this->size] = this->bucket[this->size - 1];
	else newBucket[this->size] = data;

	
	this->size++;

	delete[] this->bucket;
	this->bucket = newBucket;
}

float ASBucket::operator[](int index) {
	return this->bucket[index];
}

ASBucket::~ASBucket() {
	this->size = 0;

	delete[] this->bucket;
	this->bucket = 0;
}
