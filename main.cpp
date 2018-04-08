//#include <iostream>
#include "client.h"
#include <windows.h>
#include "tree.h"
#include <memory>
#include "BinaryTree.h"
using namespace std;


static tree *head;
static tree *current;

void Mainmenu() {
	cout << "Main menu" << endl;


}

int main() {
	//void Mainmenu()

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);



		shared_ptr<BinaryTree> temp(new BinaryTree());



	system("pause");
	return 0;
}