#include "BinaryTree.h"




BinaryTree::BinaryTree()
{
}

bool BinaryTree::Search(std::string input){
	std::shared_ptr<tree> fake;
	//input.erase(input.begin() + 4);
	int pasnum = fake->ClientPassIdToNum(input);
	bool b = 0;
	Rec(head, pasnum, b);
	if (!b) {
		std::cout << "no such man" << std::endl;
		return 0;
	}
	else return 1;
}

void BinaryTree::TestData(){
	//tree(std::string passportID, std::string placeOfIssue, std::string SurnameNamePatronymic, int year, std::string address);

	std::string passportID = "9412-220765";
	std::string placeOfIssue = "МО уфмс г Москва";
	std::string SurnameNamePatronymic = "Гараев/Максим/Ильдарович";
	int year = 1998;
	std::string address = "Сорочинск";
	std::shared_ptr<tree> temp(new tree(passportID, placeOfIssue, SurnameNamePatronymic,year,address));
	Add(head, temp, current);

	passportID = "1245-458333";
	placeOfIssue = "МО уфмс г Санкт-Петербург";
	SurnameNamePatronymic = "Гришин/Сергей/Александрович";
	year = 2000;
	address = "Псков";
	 std::shared_ptr<tree> temp1(new tree(passportID, placeOfIssue, SurnameNamePatronymic, year, address));
	 Add(head, temp1, current);

	 passportID = "1919-458333";
	 placeOfIssue = "МО уфмс г Сочи";
	 SurnameNamePatronymic = "Килин/Даниил/Викторович";
	 year = 2010;
	 address = "Сарапул";
	std::shared_ptr<tree> temp2(new tree(passportID, placeOfIssue, SurnameNamePatronymic, year, address));
	Add(head, temp2, current);

}

void BinaryTree::Rec(std::shared_ptr<tree> Current, int num, bool & b){
	if (num == Current->ClientPassIdToNum(Current->GetPassId())) {

		std::cout << "detected" << std::endl;
		b = 1;
	}
	else {
		if (num < Current->ClientPassIdToNum(Current->GetPassId())) {
			if (Current->GetLeft() == nullptr) {
				std::cout << "disappeard" << std::endl;
			}
			else {
				Current = Current->GetLeft();
				Rec(Current, num, b);

			}
		}


		if (num >Current->ClientPassIdToNum(Current->GetPassId())) {
			if (Current->GetRight() == nullptr) {
				std::cout << "disappeard" << std::endl;
			}
			else {
				Current = Current->GetRight();
				Rec(Current, num, b);
			}
		}
	}
}

void BinaryTree::PreStraight(){
	StraightPrint(head);
}

void BinaryTree::StraightPrint(std::shared_ptr<tree> head){

	if (head == nullptr) {
		return;
	}
	StraightPrint(head->GetLeft());
	StraightPrint(head->GetRight());

	std::cout << head->GetPassId() << " ";
}

std::shared_ptr<tree> BinaryTree::removemin(std::shared_ptr<tree>& p)
{
	if (p->GetLeft() == 0)return p->GetRight();

	//p->left = removemin(p->left);
	p->SetLeft(removemin(p->GetLeft()));
	Balance(p);
	return p;
}

std::shared_ptr<tree> BinaryTree::FindMin(std::shared_ptr<tree>& p){
	return p->GetLeft() ? FindMin(p->GetLeft()) : p;

}

void BinaryTree::Preremove(){
	std::string input;
	std::cout << std::endl << "num of passport \n like this 1234-123456" << std::endl;
	std::cin >> input;
	std::shared_ptr<tree> fake;
	input.erase(input.begin() + 4);
	int pasnum = fake->ClientPassIdToNum(input);
	//std::cout << "from inp to num" << std::endl;
	bool b=0;
	Rec(head, pasnum, b);
	if (!b) {
		std::cout << "no such man" << std::endl;
		return;
	}
	else {
		fake = remove(head, pasnum);
		Balance(fake);
		head = fake;
	}
}

std::shared_ptr<tree> BinaryTree::remove(std::shared_ptr<tree> p, int pasnum){
	if (!p) return 0;
	if (pasnum < p->ClientPassIdToNum(p->GetPassId()))
		p->SetLeft(remove(head->GetLeft(), pasnum));
	//p->left = remove(p->left, k);
	else if (pasnum > p->ClientPassIdToNum(p->GetPassId()))
		p->SetRight(remove(p->GetRight(), pasnum));
		//p->right = remove(p->right, k);
	else //  k == p->key 
	{
		std::shared_ptr<tree> q = p->GetLeft();
		std::shared_ptr<tree> r = p->GetRight();
		//delete p;
		if (!r) return q;
		std::shared_ptr<tree> min = FindMin(r);
		//min->right = removemin(r);
		min->SetRight(removemin(r));
		//min->left = q;
		min->SetLeft(q);
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

void BinaryTree::PreFragmentalSearch(){
	std::string str2;
	
	bool dontfound = 1;
	int choise=0;
	while (1) {
		std::cout << "enter point of search" << std::endl;
		std::cout << "(1)By segment of Name" << std::endl;
		std::cout << "(2)By segment of address" << std::endl;
		std::cout << "(3)exit" << std::endl;
		std::cin >> choise;
		switch (choise) {
		case 1:
			std::cout << "write segment" << std::endl;
		
			std::cin >> str2;
			StraightSearchBySNP(head, str2,dontfound);
			if (dontfound) std::cout << "do not found" << std::endl;
			break;
		case 2:
			std::cout << "write segment" << std::endl;
			std::cin >> str2;
			StraightSearchByAddress(head, str2,dontfound);
			if (dontfound) std::cout << "do not found" << std::endl;
			break;
		case 3:
			return;
		default:
			std::cout << "incorrect expression try again" << std::endl;
		}
	}
	
}

bool BinaryTree::FragmentalSearch(std::string str1, std::string str2){
	int count = 0;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == str2[0]) {
			count++;
			for (int j=1; j < str2.length(); j++) {
				if (str1[j + i] == str2[j]) {
					count++;
				}
				else break;
		
			}
		}
		if (count == str2.length()) return true;
		count = 0;
	}
	return false;
}

void BinaryTree::StraightSearchBySNP(std::shared_ptr<tree> head, std::string str2, bool &dontfound){
	if (head == nullptr) {
		return;
	}
	StraightPrint(head->GetLeft());
	StraightPrint(head->GetRight());
	bool b=FragmentalSearch(head->GetSNP(),str2);
	if (b) {
		head->ClientShow();
		dontfound = 0;
	}
	
	
}

void BinaryTree::StraightSearchByAddress(std::shared_ptr<tree> head, std::string str2, bool &dontfound){
	if (head == nullptr) {
		return;
	}
	StraightPrint(head->GetLeft());
	StraightPrint(head->GetRight());
	bool b = FragmentalSearch(head->GetAddress(), str2);
	if (b) {
		head->ClientShow();
		dontfound = 0;
	}



}

BinaryTree::~BinaryTree()
{
}
