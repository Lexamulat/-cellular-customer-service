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



		shared_ptr<BinaryTree> Bitree(new BinaryTree());
		Bitree->Create();
		Bitree->Preshow();
		/*int up = 0;
		Bitree->Show(Bitree->GetHead(), up);*/

	system("pause");
	return 0;
}