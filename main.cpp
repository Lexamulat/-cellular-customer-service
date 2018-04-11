//#include <iostream>
#include "client.h"
#include <windows.h>
#include "tree.h"
#include <memory>
#include "BinaryTree.h"
#include "hashtable.h"
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

	//cout << (int)'0' << endl;//48

	//cout << (int)'9';//57


		shared_ptr<BinaryTree> Bitree(new BinaryTree());
		Bitree->Create();
		//
		////Bitree->Create();
		////Bitree->Create();
		////Bitree->Create();
		////Bitree->Create();
		////Bitree->Preshow();
		///*int up = 0;
		//Bitree->Show(Bitree->GetHead(), up);*/

		//Bitree->Preshow();
		//cout <<endl<< "----------------" << endl;
		//Bitree->Preremove();
		//cout <<endl<< "----------------" << endl;
		//Bitree->Preshow();

		////have straight view
		//Bitree->PreStraight();

		////////////////////////////////////
		//sim

	/*shared_ptr<hashtable> table(new hashtable());
	table->preAdd();

	table->show();

	table->tablesearch();*/

	system("pause");
	return 0;
}