#include "tree.h"
#include <memory>



tree::tree()
{
	
}
//void tree::HeadAndCurrentIntoNullptr() {
//	head = nullptr;
//	current = nullptr;
//}
//void tree::add(tree *& current) {
//
//	if (head == nullptr) {
//		head = this;
//	}
//	
//	else {
//		tree *current = head;
//		if (this->ClientPassIdToNum(GetPassId()) < current->ClientPassIdToNum(GetPassId())) {
//			if (current->left == nullptr) {
//				current->left = this;
//				return;
//			}
//			else {
//				current = current->left;
//				add(current);
//			}
//			
//		}
//	
//	}
//}
//
//void tree::StraightTreeShow(tree *head) {
//	if (head == nullptr) {
//		return;
//	}
//	
//		StraightTreeShow(head->left);
//		StraightTreeShow(head->right);
//
//		std::cout << head->ClientPassIdToNum(head->GetPassId()) << " ";
//		
//	
//}

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
