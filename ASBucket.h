#ifndef ASBUCKET_H
#define ASBUCKET_H

struct ASBucket {
	int size;
	float* bucket;

	ASBucket();
	void Add(float);
	float operator[](int);
	~ASBucket();
};

#endif 