#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *removeDuplicates(Node *head)
{
    //Write your code here

    
    Node* t1 = NULL;
    Node* t2 = NULL;
    Node* temp = head;
    
    while(temp!=NULL && temp->next != NULL)
    {
        t1 = temp -> next;
        temp -> next = NULL;
        
    while(t1 != NULL && temp->data == t1->data)
    {
        t2 = t1;
        t1 = t1 -> next;
        t2 -> next = NULL;
        delete(t2);
    }
    temp -> next = t1;
    temp = t1;
    }
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}
