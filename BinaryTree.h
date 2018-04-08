#pragma once
#include "tree.h"
class BinaryTree:public tree

{
public:
	BinaryTree();

	void Show(BinaryTree* head, int up);

	~BinaryTree();

private:
		int up = 0;
		tree* current = nullptr;
		tree* head = nullptr;
};

