// By Jason Favero
//This program demonstrates a simple linked list

//#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Define the stuct that will be the nodes in the linked list
struct nodeType {
	string name;  //stores a string
	nodeType* next; //pointer to the next link in the node, which is of type nodeType
};

//nodeType* headNode;

//function prototypes
void insert(string, nodeType*);
void printList(nodeType*);
void wipeList(nodeType*);
int remove(string, nodeType*);

int main()
{

	string studentName;
	

	//create the first node and initialize it to an empty string
	nodeType *headNode;
	headNode = new nodeType;
	headNode->name = " ";
	headNode->next = nullptr;
	int cont;
	int removeValue;

	do
	{
		cout << "Please choose one of the following: \n1. Enter a new student. \n2. Print the list. \n3. Remove a student. \n4. Wipe the list \n5. Exit" << endl;
		cin >> cont;

		switch (cont)
		{

		case 1:

			cin.ignore();
			cout << "Enter the student name" << endl;
			getline(cin, studentName);
			insert(studentName, headNode);

			break;

		case 2:

			printList(headNode);

			break;

		case 3:
			cin.ignore();
			cout << "Enter the student's name" << endl;
			getline(cin, studentName);
			removeValue = remove(studentName, headNode);
			switch (removeValue)
			{
			case 1:
				cout << "The node containing " << studentName << " has been removed";
				break;
			case 2:
				cout << "The node containing " << studentName << " has been removed. The list is now empty.";
					break;
			case 3:
				cout << "Remove failed because the list is empty." << endl;
				break;
			case 4:
				cout << "Remove failed a student named " << studentName << " does not exist.";
				break;
			}
			break;

		case 4:

			wipeList(headNode);

			break;
		}
	} while (cont != 5);

	system("pause");
	return 0;
}

int remove(string studentName, nodeType* head) 
{
	nodeType* temp, * traverse;
	
	if (head->name == " ")
	{
		//cout << "There is nothing in the list" << endl;
		return 3;
	}
	else if (head->name == studentName && head->next == nullptr)
	{
		head->name = " ";
		return 2;
	}

	else if (head->name == studentName && head->next != nullptr)
	{
		temp = head->next;
		head->name = temp->name;
		head->next = temp->next;
		delete temp;
		return 1;
	}

	else if (head->next == nullptr)
	{

		if (head->name != studentName)
		return 4;
	}
	temp = head->next;
	traverse = head;

	while (true)
	{
		if (temp->name == studentName)
		{
			traverse->next = temp->next;
			delete temp;
			return 1;
		}
		else if (temp->next == nullptr)
		{
			return 4;
		}

		traverse = traverse->next;
		temp = temp->next;
	}



	
	 
}




       

//insert() adds a string onto the end of the list
void insert(string studentName, nodeType* head) {
	nodeType* temp, * traverse;

	if (head->name == " ")
	{
		//if the name field in the head of the list is empty then this is the first name entered
		head->name = studentName;
	}
	else
	{
		temp = new nodeType; //allocate the memory
		temp->name = studentName;
		temp->next = nullptr;

		traverse = head;
		while (traverse->next != nullptr)
			traverse = traverse->next;

		traverse->next = temp;
	}
}


//printList() traverses the list and outputs the string in each node to the output device
void printList(nodeType* head) {
	nodeType* traverse;
	traverse = head;

	if (traverse->name == " ")
		cout << "The list is empty" << endl;
	else
	{
		while (true)
		{
			cout << traverse->name << endl;
			if (traverse->next != nullptr)
				traverse = traverse->next;
			else break;
		}
	}
}

//wipeList() will traverse the linked list and delete all items in the list, freeing the memory
void wipeList(nodeType* head) {
	nodeType* traverse1, * traverse2, *temp;  //pointers used to traverse the linked list

	while (true)
	{
		if (head->next != nullptr)
		{
			traverse1 = head;  //point to head of the linked list
			traverse2 = traverse1->next; //point to the next item in the list
		}
		else
		{
			//if head->next is null then the head is the only node in the list
			cout << "Deleting the head node " << head->name << endl;
			head->name = " ";
			head->next = nullptr;
			//delete head;	
			break;
		}

		while (traverse2->next != nullptr)
		{
			//cycle through to the end of the list
			//keep traverse1 one link behind traverse2
			traverse1 = traverse2;
			traverse2 = traverse2->next;
		}

		//now traverse2 is at the end of the list
		cout << "Deleting " << traverse2->name << endl;


		delete traverse2; //delete the item
		traverse1->next = nullptr; //make this is the end of the list now
	}
}
