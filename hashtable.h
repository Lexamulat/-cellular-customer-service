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
	void rateSearch();
	void tablesearch(bool CallFromDel = 0);
	void show();
	void ShowSimData();
	int hashFunc(std::string simnum);
	void preAdd();
	bool TableSearchWithInputString(std::string input,bool CallFromClientListAdd=0);
	void addInTable(std::shared_ptr<sim> obj);
	void TestDataForTable();
private:
	
	std::shared_ptr<sim> mas[4]{};
};

