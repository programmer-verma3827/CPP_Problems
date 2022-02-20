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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

int findNode(Node *head, int n){
    
    // Write your code here.
	
	
	// 1st Method
    
//     Node* curr = head;
//     int count=0;
    
//     while(curr != NULL && n != curr->data)
//     {
//         curr = curr -> next;
//         count++;
//     }
    
//     if(curr == NULL)
//     {
//         return -1;
//     }
    
//     return count;
	
	
	// 2nd Method
	
	int pos = 0;
	while(head != NULL)
	{
		if(head -> data == n)
		{
			return pos;
		}
		
		pos++;
		head = head->next;
	}
	
	return -1;	
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}
