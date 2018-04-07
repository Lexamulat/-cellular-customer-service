//#include <iostream>
#include "client.h"
#include <windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	client * cl = new client();
	//cl->ClientShow();
	
	system("pause");
	return 0;
}