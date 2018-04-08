#pragma once
#include "client.h"
class tree: public client
{
public:
	tree();
	~tree();	
private:

	unsigned int height = 0;
	tree* left = nullptr;
	tree* right = nullptr;
};

