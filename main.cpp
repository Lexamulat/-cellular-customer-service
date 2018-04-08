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
		
		//Bitree->Create();
		//Bitree->Create();
		//Bitree->Create();
		//Bitree->Create();
		//Bitree->Preshow();
		/*int up = 0;
		Bitree->Show(Bitree->GetHead(), up);*/

		Bitree->Preshow();
		cout <<endl<< "----------------" << endl;
		Bitree->Preremove();
		cout <<endl<< "----------------" << endl;
		Bitree->Preshow();

		//have straight view
		Bitree->PreStraight();

	system("pause");
	return 0;
}