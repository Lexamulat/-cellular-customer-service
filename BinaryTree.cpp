#include "BinaryTree.h"




BinaryTree::BinaryTree()
{
}

void BinaryTree::Preshow(){
	int up = 0;
	ShowTree(this->head, up);
}

void BinaryTree::ShowTree(std::shared_ptr<tree> head, int up){

	if (head)
	{

		ShowTree(head->GetRight(), up + 1);
		for (int i = 0; i< up; i++) std::cout << "     ";
		std::cout << head->GetPassId() << std::endl;
		ShowTree(head->GetLeft(), up + 1);
	}
}

void BinaryTree::Balance(std::shared_ptr<tree> &head) {

	int bfactor = 0;
	if (head == nullptr)   // Базовый случай
	{
		return;
	}
	Balance(head->GetLeft());
	Balance(head->GetRight());
	fixheight(head);
	
	bfactor = height(head->GetRight()) - height(head->GetLeft());
	

	if (bfactor == 2) {
		if (height(head->GetRight()->GetLeft()) <= height(head->GetRight()->GetRight())) {
			LeftRotate(head);

			return;
		}
		else {
			RightRotate(head->GetRight());

			LeftRotate(head);

			return;
		}
	}
	if (bfactor == -2) {
		if (height(head->GetLeft()->GetLeft()) > height(head->GetLeft()->GetRight())) {
			RightRotate(head);

			return;
		}
		else {
			LeftRotate(head->GetLeft());

			RightRotate(head);

			return;
		}
	}


}

void BinaryTree::fixheight(std::shared_ptr<tree>& head){
	unsigned int hl, hr;
	hl = height(head->GetLeft());
	hr = height(head->GetRight());
	head->SetHeight((hl>hr ? hl : hr) + 1);
	//head->GetHeight() = (hl>hr ? hl : hr) + 1;
}

unsigned int BinaryTree::height(std::shared_ptr<tree>& head){
	return head ? head->GetHeight() : 0;
}

void BinaryTree::Add(std::shared_ptr<tree> head, std::shared_ptr<tree> temp, std::shared_ptr<tree>current) {

	if (head == nullptr) {
		head = temp;
		current = head;
		//head->key = temp->key;
		return;
	}
	else {
		if (temp->ClientPassIdToNum(temp->GetPassId())<head->ClientPassIdToNum(temp->GetPassId())) {
			if (current->GetLeft() == nullptr) {
				current->SetLeft(temp);
				
				Balance(head);
			
				current = head;

			
				return;
			}
			else {
				current = current->GetLeft();
				Add(head, temp, current);
			}
		}
		else {
			if (current->GetRight() == nullptr) {
				current->SetRight(temp);

			
				Balance(head);
			
				current = head;

	
				return;
			}
			else {
				current = current->GetRight();
				Add(head, temp, current);
			}
		}

	}


}

void BinaryTree::Create() {

	std::shared_ptr<tree> temp(new tree());
	Add(head, temp, current);


}


std::shared_ptr<tree> BinaryTree::GetHead() {
	return this->head;

}

void BinaryTree::LeftRotate(std::shared_ptr<tree>& head){
	std::shared_ptr<tree> p = head->GetRight();
	if (p == nullptr)head->SetRight(nullptr);
	head->SetRight(p->GetLeft());
	//head->right = p->left;

	//p->left = head;
	p->SetLeft(head);

	fixheight(head);
	fixheight(p);

	head = p;
}

void BinaryTree::RightRotate(std::shared_ptr<tree>& head){
	std::shared_ptr<tree> q = head->GetLeft();
	if (q == nullptr)head->SetLeft(nullptr);
	//head->left = q->right;
	head->SetLeft(q->GetRight());
	//q->right = head;
	q->SetRight(head);
	fixheight(head);
	fixheight(q);

	head = q;

}

BinaryTree::~BinaryTree()
{
}
