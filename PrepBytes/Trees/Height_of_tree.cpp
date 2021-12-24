/*

Height of Tree
Given a binary tree, your task is to print the height of the tree. Consider root node height as 
1
.

Note - You have to complete calculateHeight() function, no need to implement the tree.

Input format
Root of the tree is passed to the calculateHeight()
And the tree is constructed in level order format.

Output format
Return height of the tree.

Constraints
1
<=
N
<=
64

Time Limit
1 second

Example
Input
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Note : Level order traversal of input tree, where 
−
1
 represents null nodes.

Output
3

*/

// Complete the calculateHeight function below.
/* For your reference
struct node
{
    long long value;
    node *left;
    node *right;
};
*/

int calculateHeight(node* node)
{
    //write your code here
    
    if(node == NULL)
    {
      return 0;
    }
    
    return max(calculateHeight(node->left), calculateHeight(node->right)) + 1;
    
}
