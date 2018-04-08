#include "tree.h"



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
