#include "BinaryTree.h"




BinaryTree::BinaryTree()
{
}

void BinaryTree::Preremove(){
	std::string input;
	std::cout << std::endl << "num of passport \n like this 1234-123456" << std::endl;
	std::cin >> input;
	std::shared_ptr<tree> fake;
	input.erase(input.begin() + 4);
	int pasnum = fake->ClientPassIdToNum(input);
	std::cout << "from inp to num" << std::endl;
	remove(head, pasnum);
}

std::shared_ptr<tree> BinaryTree::remove(std::shared_ptr<tree>& head, int pasnum){
	if (!head) return 0;
	if (pasnum < head->ClientPassIdToNum(head->GetPassId()))
		head->SetLeft(remove(head->GetLeft(), pasnum));
	//p->left = remove(p->left, k);
	else if (pasnum > head->ClientPassIdToNum(head->GetPassId()))
		head->SetRight(remove(head->GetRight(), pasnum));
		//p->right = remove(p->right, k);
	else //  k == p->key 
	{
		std::shared_ptr<tree> q = head->GetLeft();
		std::shared_ptr<tree> r = head->GetRight();
		delete p;
		if (!r) return q;
		node* min = FindMin(r);
		min->right = removemin(r);
		min->left = q;
		// Balance(min);
		return min;
	}
	//Balance(p);
	return p;

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

void BinaryTree::Add(std::shared_ptr<tree> &head, std::shared_ptr<tree> temp, std::shared_ptr<tree> &current) {

	if (head == nullptr) {
		head = temp;
		current = head;
		//head->key = temp->key;
		return;
	}
	//std::cout << temp->ClientPassIdToNum(temp->GetPassId());
	//std::cout << temp->ClientPassIdToNum(temp->GetPassId());

	else {
		if (temp->ClientPassIdToNum(temp->GetPassId())<head->ClientPassIdToNum(head->GetPassId())) {
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
