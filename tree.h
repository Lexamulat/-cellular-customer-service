#pragma once
#include "client.h"
class tree
{
public:
	tree();


	~tree();
private:

	client cli;
	unsigned int height = 0;
	tree* left = nullptr;
	tree* right = nullptr;
};

