#pragma once
#include "sim.h"
#include <memory>

class hashtable
{
public:
	hashtable();
	~hashtable();
	bool IsTableFull();
	void DelfromTable();
	void tablesearch(bool callWithString = 0,std::string input="_" ,bool CallFromDel = 0);
	void show();
	int hashFunc(std::string simnum);
	void preAdd();
	void addInTable(std::shared_ptr<sim> obj);
private:
	 
	std::shared_ptr<sim> mas[4]{};
};

