#pragma once
#include "sim.h"
#include <memory>

class hashtable
{
public:
	hashtable();
	~hashtable();
	int hashFunc(std::string simnum);
	void preAdd();
	void addInTable(std::shared_ptr<sim> obj);
private:
	 
	std::shared_ptr<sim> mas[4]{};
};

