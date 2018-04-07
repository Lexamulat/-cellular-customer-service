#pragma once
#include "client.h"
class tree: public client
{
public:
	tree();
	void add(tree *&head, tree*& current);
	void StraightTreeShow(tree *head);
	~tree();
private:

	//client* Treeclient;
	unsigned int height = 0;
	tree* left = nullptr;
	tree* right = nullptr;
};

