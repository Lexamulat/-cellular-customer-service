#pragma once
#include "client.h"
#include <memory>
class tree: public client
{
public:
	
	tree(std::string ipassportID, std::string iplaceOfIssue, std::string iSurnameNamePatronymic, int iyear, std::string iaddress) : client(ipassportID, iplaceOfIssue, iSurnameNamePatronymic, iyear, iaddress) {
		SurnameNamePatronymic = iSurnameNamePatronymic;
		placeOfIssue = iplaceOfIssue;
		passportID = ipassportID;
		address = iaddress;
	};
	tree();
	~tree();	
	std::shared_ptr<tree> GetLeft();
	std::shared_ptr<tree> GetRight();
	void SetLeft(std::shared_ptr<tree> set);
	void SetRight(std::shared_ptr<tree> set);
	unsigned int GetHeight();
	void SetHeight(unsigned int setH);
private:

	unsigned int height = 0;
	std::shared_ptr<tree> left = nullptr;
	std::shared_ptr<tree> right = nullptr;
};

