#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

// 1
struct Student
{
	string id;
	string name;
	double mark;
	double total_mark;
};
struct Node
{
	Student data;
	Node* next;
};
void addTail(Node*& head, Node* newNode)
{
	if (head == NULL)
		head = newNode;
	else {
		Node* cur = head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = newNode;
	}
}
Node* loadListOfStudent(string filename)
{
	ifstream infile(filename);
	Node* head = NULL; Student data; int n;
	infile >> n;
	for (int i = 0; i < n; i++)
	{
		infile.ignore();
		getline(infile, data.id, '\n');
		getline(infile, data.name, '\n');
		infile >> data.mark;
		infile >> data.total_mark;

		Node* newNode = new Node{ data, NULL };
		addTail(head, newNode);
	}
	infile.close();
	return head;
}
void printListStudent(Node* head)
{
	if (head == NULL)
		return;
	Node* cur = head;
	while (cur != NULL)
	{
		cout << cur->data.id << "," << cur->data.name << "," << cur->data.mark << "," << cur->data.total_mark << '\n';
		cur = cur->next;
	}
}
// 2
void removeStudent(Node*& head)
{
	if (head == NULL) return;

	while (head != NULL && head->data.mark < 0 && head->data.mark > 10 && head->data.total_mark < 0 && head->data.total_mark > 10)
	{
		Node* del = head;
		head = head->next;
		delete del;
	}
	if (head == NULL) return;

	Node* pre = head;
	Node* cur = head->next;
	while (cur != NULL)
	{
		if (cur->data.mark < 0 || cur->data.mark > 10 || cur->data.total_mark < 0 || cur->data.total_mark > 10)
		{
			Node* del = cur;
			cur = cur->next;
			pre->next = cur;
			delete del;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}

}
// 3
void removeNode(Node*& head, Node* node)
{
	if (head == NULL) return;

	if (head == node) 
	{
		Node* del = head;
		head = head->next;
		delete del;
	}
	else 
	{
		Node* cur = head;
		while (cur != NULL && cur->next != node)
			cur = cur->next;

		if (cur != NULL) 
		{
			cur->next = node->next;
			delete node;
		}
	}
}
bool isRemove(Node* node) 
{
	Node* cur = node->next;
	while (cur != NULL) 
	{
		if (cur->data.id == node->data.id)
			return true;
		cur = cur->next;
	}
	return false;
}
void removeDuplicateCourses(Node*& head) 
{
	if (head == NULL) return;

	Node* cur = head;
	while (cur != NULL) 
	{
		Node* pre = cur->next;
		if (isRemove(cur))
			removeNode(head, cur);
		cur = pre;
	}
}
// 4
void sortListStudentID(Node*& head)
{
	Node* cur = head;
	while (cur != NULL)
	{
		Node* pre = cur->next;
		while (pre != NULL)
		{
			if (pre->data.id < cur->data.id)
				swap(pre->data, cur->data);
			pre = pre->next;
		}
		cur = cur->next;
	}
}
void saveFileStudent(string filename, Node* head)
{
	ofstream outfile(filename);
	Node* cur = head;
	while (cur != NULL)
	{
		outfile << cur->data.id << "," << cur->data.name << "," << cur->data.mark << "," << cur->data.total_mark << '\n';
		cur = cur->next;
	}
	outfile.close();
}
void removeList(Node*& head) 
{
	while (head != NULL) 
	{
		Node* del = head;
		head = head->next;
		delete del;
	}
}
int main()
{
	Node* head = loadListOfStudent("Data.txt");
	printListStudent(head);

	cout << '\n';
	removeStudent(head);
	printListStudent(head);

	cout << '\n';
	removeDuplicateCourses(head);
	printListStudent(head);

	cout << '\n';
	sortListStudentID(head);
	saveFileStudent("Save.txt", head);

	removeList(head);
}