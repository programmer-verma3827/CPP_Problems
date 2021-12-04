/*

Reverse a Linked List
Next question will test how comfortable you are with Linked Lists. The problem statement is simple "Reverse a singly linked list".

Input Format
The first line contains an integer 
T
, number of test cases. Then follows 
T
 test cases.
Each test case consists of two lines. The first line contains 
N
, size of the list.
The second line contains 
N
 space-separated integers denoting elements of the list.

Output Format
The output contains 
T
 lines, each line containing the modified list.
Note - You only need to implement reverseLinkedList(), and return the head of the linked list.

Constraints
1
<=
T
<=
10

1
<=
N
<=
100

1
<=
A
i
<=
100

Time Limit
1 second

Example
Input
2
4
1 2 3 4
5
10 20 30 40 50

Output
4 3 2 1
50 40 30 20 10

*/

// Complete the reverseLinkedList function below.
/*
For your reference:

SinglyLinkedListNode {
int data;
SinglyLinkedListNode* next;
};
To create a new node use below constructor
SinglyLinkedListNode(int node_data)
*/

SinglyLinkedListNode *reverseLinkedList(SinglyLinkedListNode *head)
{
  
//write your code here

if(head == NULL)
{
  return head;
}

reverseLinkedList(head->next);
cout<<head->data<<" ";

}
