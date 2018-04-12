#include "tree.h"
#include <memory>



tree::tree()
{
	std::cout << "intree" << std::endl;
}

//tree::tree(std::string passportID, std::string placeOfIssue, std::string SurnameNamePatronymic, int year, std::string address){
//	client(passportID,placeOfIssue,SurnameNamePatronymic,year,address);
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
