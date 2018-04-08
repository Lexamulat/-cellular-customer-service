#include "tree.h"
#include <memory>



tree::tree()
{
	
}

tree::~tree()
{
}

std::shared_ptr<tree> tree::GetLeft()
{
	return this->left;
}

std::shared_ptr<tree> tree::GetRight()
{
	return this->right;
}

void tree::SetLeft(std::shared_ptr<tree> set)
{
	this->left=set;
	
}
void tree::SetRight(std::shared_ptr<tree> set)
{
	this->right = set;
}

unsigned int tree::GetHeight()
{
	return this->height;
}

void tree::SetHeight(unsigned int setH)
{
	this->height = setH;
}
