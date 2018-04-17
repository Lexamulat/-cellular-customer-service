//#include <iostream>
#include "client.h"
#include <windows.h>
#include "tree.h"
#include <memory>
#include "BinaryTree.h"
#include "hashtable.h"
#include "list.h"
using namespace std;

shared_ptr<BinaryTree> Bitree(new BinaryTree());
shared_ptr<hashtable> table(new hashtable());
shared_ptr<list> clientSimList(new list(Bitree, table));
static tree *head;
static tree *current;


void SimMenu() {
	bool b = 1;
	while (b) {

		cout << endl << "Sim menu" << endl;
		cout << "(1)Add new simcard" << endl;
		cout << "(2)Delete simcard" << endl;
		cout << "(3)View all simcards" << endl;
		cout << "(4)Search by rate" << endl;
		cout << "(5)hashtable" << endl;
		cout << "(6)Back" << endl;
		int choiñe;
		cin >> choiñe;
		switch (choiñe) {
		case 1: {
			table->preAdd();
			break; }
		case 2: {
			table->DelfromTable();
			break; }
		case 3: {
			table->ShowSimData();
			break; }

		case 4: {
			table->rateSearch();
			break; }
		case 5: {
			table->show();
			break; }
		case 6: {
			b = 0;
			break; }
		default: {
			cout << "incorrect expression try again" << endl;
			break;
		}
		}



	}
}

void ClientMenu() {
	bool b = 1;
	while (b) {
	
		cout <<endl<< "Client menu" << endl;
		cout << "(1)Register a new user" << endl;
		cout << "(2)Remove user" << endl;
		cout << "(3)View all users" << endl;
		cout << "(4)Search by num of passport" << endl;
		cout << "(5)Fragmental search" << endl;
		cout << "(6)Íàçàä" << endl;
		int choiñe;
		cin >> choiñe;
		switch (choiñe) {
		case 1: {
			Bitree->Create();
			break; }
		case 2: {
			Bitree->Preremove();
			break; }
		case 3: {
			//Bitree->Preshow();
			Bitree->PreStraight();
			break; }

		case 4: {
			bool wrong = 1;
			std::string input;
			while (wrong) {
				std::cout << std::endl << "num of passport \n like this 1234-123456" << std::endl;
				std::cin >> input;
				if (input.length() != 11) {
					wrong = 1;
					continue;
				}
				for (int i = 0; i < 4; i++) {
					if (((int)input[i] < 48) || ((int)input[i] > 57)) {
						wrong = 1;
						break;
					}
				}
				if (input[4] != '-') {
					wrong = 1;
					continue;
				}
				for (int i = 5; i < 11; i++) {
					if (((int)input[i] < 48) || ((int)input[i] > 57)) {
						wrong = 1;
						break;
					}
				}
				wrong = 0;
			}
			Bitree->Search(input);
			break; }
		case 5: {
			Bitree->PreFragmentalSearch();
			break; }
		case 6: {
			b = 0;
			break; }
		default: {
			cout << "incorrect expression try again" << endl;
			break;
		}
		}

	
	
	}
}

void ClientSimmenu() {
	bool b = 1;
	while (b) {
		cout <<endl <<"Client - Sim menu" << endl;
		cout << "(1)Connect sim with user" << endl;
		cout << "(2)Return of the SIM-card from the client" << endl;
		cout << "(3)Serch by num of sim" << endl;
		cout << "(4)Show list" << endl;
		cout << "(5)Back" << endl;
		int choiñe;
		cin >> choiñe;
		switch (choiñe) {
		case 1:
			clientSimList->CreateNewInList();
			break;
		case 2:
			clientSimList->DelFromList();
			break;
		case 3:
			clientSimList->Search();
			break;
		case 4:
			clientSimList->ShowList();
			break;
		case 5:
			b = 0;
		default: {
			cout << "incorrect expression try again" << endl;
		}
		}
	}
}


void Mainmenu() {
	while (1) {
		cout << "Main menu" << endl;
		cout << "(1)Work with customers" << endl;
		cout << "(2)Work with sim cards" << endl;
		cout << "(3)Issuing sim cards to customers" << endl;
		cout << "(4)Exit" << endl;
		int choiñe;
		cin >> choiñe;
		switch (choiñe) {
		case 1:
			ClientMenu();
			break;
		case 2:
			SimMenu();
			break;
		case 3:
			ClientSimmenu();
			break;
		case 4:
			exit(0);
		default: {
			cout << "incorrect expression try again" << endl;
		}
		}
	}
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Bitree->TestData();
	table->TestDataForTable();
	clientSimList->TestData();

	Mainmenu();

	
	
	

	//shared_ptr<BinaryTree> Bitree(new BinaryTree());
	

	Bitree->Preshow();



	//shared_ptr<hashtable> table(new hashtable());

	
	table->show();

	cout << "--------------------" << endl;

	//shared_ptr<list> clientSimList(new list(Bitree, table));

	/*clientSimList->CreateNewInList();
	clientSimList->CreateNewInList();
	clientSimList->CreateNewInList();*/
	clientSimList->TestData();
	clientSimList->ShowList();
	cout << "--------------------" << endl;

	clientSimList->SortList();
	clientSimList->ShowList();
	cout << "--------------------" << endl;
	clientSimList->Search();
	////clientSimList->CreateNewInList();

	//clientSimList->ShowList();

	//clientSimList->DelFromList();
	//
	//clientSimList->ShowList();
	//cout << (int)'0' << endl;//48

	//cout << (int)'9';//57
	/*shared_ptr<BinaryTree> Bitree(new BinaryTree());
	Bitree->Create();
	Bitree->PreFragmentalSearch();
*/
		/*shared_ptr<BinaryTree> Bitree(new BinaryTree());
		Bitree->Create();*/
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

	//shared_ptr<hashtable> table(new hashtable());
	/*table->preAdd();

	table->show();

	
	table->DelfromTable();

	table->show();*/







	system("pause");
	return 0;
}