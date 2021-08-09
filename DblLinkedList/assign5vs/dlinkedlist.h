// dlinkedlist.h : 
/************************
VGP240 Assignment 5
W Dobson 11-5-17   v0

Header file containing a doubly linked list class and associated functions

****************************/
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/***************
Node structure definition (could be a class) for doubly linked list class.
***************/
struct NodeType {
	string name;
	int value;
	NodeType *prev;
	NodeType *next;
};


class DLinkedList {      // node struct def
public:

	DLinkedList();  // required for constructor


	/*************
	pushhead() - pushes a node onto the top of the linked list
	*************/
	void pushhead(NodeType *nptr) {
		NodeType *n = new NodeType();
		
		//cout << nptr->name << "pushed" << endl; //debug
		n->name = nptr->name;  // copy data to new node
		n->value = nptr->value;
		n->prev = NULL;
		n->next = listhead;

		if (listhead != NULL)  // if list is not empty set prev pointer to new head node
			listhead->prev = n;
		listhead = n;			// update list head ptr

		++listlength;		// increment list length
	}


	/*************
	pophead() - pops a node from the top of the linked list
	*************/
	int pophead(NodeType *nptr) {
		NodeType *n = listhead;            // set ptr to head

		if (listhead == NULL) {
			return 0;            // if list is empty return a 0
		}
		else {
			nptr->name = n->name;   // copy the node data to the nptr
			nptr->value = n->value;
			nptr->next = n->next;
			nptr->prev = n->prev;

			if(listhead->next != NULL)   // not the last node in list move head ptr
				listhead = n->next;
			else {						// otherwise it is empty so reset both
				listhead = NULL;
				listtail = NULL;
			}

			delete n;               // remove popped node from mem
			--listlength;			// decrement list length
		}

		return 1;
	}

/****************
 pushtail for doubly linked list - a bit complicated due to search - removed from assignm4nt 4
*****************/
	void pushtail(NodeType *nptr) {
		NodeType *n = new NodeType();
		         
		//cout << nptr->name << "pushed" << endl; //debug

		n->name = nptr->name;  // copy data to new node
		n->value = nptr->value;
		n->prev = listtail;
		n->next = NULL;

		if (listtail == NULL) {		    
			listhead = n;        // if list is empty make this node the head
		}
		else {
			listtail->next = n;	// update next to last node next ptr	
		}
		listtail = n;			// let new node be the tail

		++listlength;
	}

	/****************
	poptail for doubly linked list - a bit complicated due to search - removed from assignment 4
	*****************/

	int poptail(NodeType *nptr) {
		NodeType *n = listtail;

		if (listtail == NULL) {
			return 0;            // if list is empty return a 0
		}
		else {
			nptr->name = n->name;   // copy the node data to the nptr
			nptr->value = n->value;
			nptr->prev = n->prev;
			nptr->next = n->next;

			if (n != listhead) {           // *** Very Important too check if the last element
				n->prev->next = NULL;      // if not update tail pointers for prev node
				listtail = n->prev;
			}
			else {
				listhead = NULL;        // if head element set head ptr to null
				listtail = NULL;
			}
		
			delete n;               // remove last node from mem
			--listlength;
		}

		return 1;
	}

	/***********
	displaylist() lists out the data in the linked list - moved outside the class for assignment 5
	************/
	void displaylist() {
		int i = 1;
		bool flag = true;
		int maxsize = 1000;

		NodeType *nptr = listhead;

		if (nptr == NULL) { // check for empty list
			flag = false;
			cout << "List Empty!" << endl;
		}

		while (flag && i < maxsize) {

			cout << "Node " << i << " " << nptr->name << " " << nptr->value << endl;
			++i;
			nptr = nptr->next;
			if (nptr == NULL)
				flag = false;
		}
		//cout << "Node " << i << " " << nptr->name << " " << nptr->value << endl;
	}


	/************
	length() returns length of list. More efficiently handled via a private variable.
	************/
	int length() {	
		return listlength;
	}

	/***************
	tail() returns pointer to tail node
	***************/
	NodeType * tail() {
		return listtail;
	}

	/**************
	head() returns point to list head node
	*************/
	NodeType * head() {
		return listhead;
	}

/****************
search() searches for input string in name field for nodes returning ptr to the node.
This should be moved outside the class in assignment 5
******************/
	NodeType * search(string s1) {       // needs testing *********
		NodeType *nptr = listhead;
		while (nptr->name != s1) {
			nptr = nptr->next;
		}
		return nptr;
	}

// Private pointers for use by class functions only
private:
	NodeType *listhead;
	NodeType *listtail;
	int listlength;

};

// **** Constructor to initialize the private pointers in the class to NULL
DLinkedList::DLinkedList() {    // constructor to initialize pointers in new list
	listhead = NULL;
	listtail = NULL;
	listlength = 0;
}



