//#include <iostream>
#include "client.h"
#include <windows.h>
#include "tree.h"
#include <memory>
using namespace std;

tree *head = nullptr;
tree *current = nullptr;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	shared_ptr<tree> temp(new tree());
	
	temp->add(head,current);

	head->StraightTreeShow(head);

	system("pause");
	return 0;
}