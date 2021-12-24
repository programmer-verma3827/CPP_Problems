/*

Inorder Traversal
Given a binary tree, your task is to print the inorder traversal of the tree.

Note - You have to complete inOrderTraversal() function, no need to implement the tree.

Input format
Root of the tree is passed to the inOrderTraversal()
And the tree is constructed in level order format.

Output format
Print inOrder traversal.

Constraints
1
<=
N
<=
20

Example
Input
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Note : Level order traversal of input tree, where 
−
1
 represents null nodes.

Output
4 2 5 1 6 3 7

*/

// Complete the inOrderTraversal function below.
/* For your reference:
struct node
{
    long long value;
    node *left;
    node *right;
};
*/

void inOrderTraversal(node *t)
{
    //write your code here;
    
    if(t==NULL)
    {
      return;
    }
    
    inOrderTraversal(t->left);
    cout<<t->value<<" ";
    inOrderTraversal(t->right);
}
