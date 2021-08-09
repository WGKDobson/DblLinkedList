// assign5vs.cpp : 
/***********************
VGP240 Assignment 5 
W Dobson 11-5-17   v0

Main program inline test code for doubly linked list class in local dlinkedlist.h header file.

************************/

#include "stdafx.h"
#include "dlinkedlist.h"

int main()
{
	int i = 0;
	DLinkedList DLL;
	//string name, value;


	NodeType n1;  // create a data node for read/write

	for (i = 0; i < 3; i++) {
		n1.name = "Alice";
		n1.value = 88 + i;

		//cout << n1.name << "added" << endl;

		DLL.pushtail(&n1);
		cout << "Length = " << DLL.length() << endl;

		n1.name = "Bill";
		n1.value = 84 + i;
		//cout << n1.name << "added" << endl;

		DLL.pushhead(&n1);
		cout << "Length = " << DLL.length() << endl;

		n1.name = "Carol";
		n1.value = 95 + i;
		//cout << n1.name << "added" << endl;


		DLL.pushtail(&n1);
		cout << "Length = " << DLL.length() << endl;

		n1.name = "Denise";
		n1.value = 90 + i;
		//cout << n1.name << "added" << endl;


		DLL.pushhead(&n1);
		cout << "Length = " << DLL.length() << endl;

		DLL.displaylist();

		n1.name = "xxx";
		n1.value = 0;

		while (DLL.poptail(&n1)) {
			cout << "Popped tail data = " << n1.name << " " << n1.value << endl;
			cout << "Length = " << DLL.length() << endl;
			DLL.displaylist();
		}
	}
	system("pause");
	return 0;
}
