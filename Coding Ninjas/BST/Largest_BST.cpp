/*

Largest BST
Send Feedback
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2

*/

#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

#include <climits>

// 2nd Method

// class LargestBST
// {
//     public:
    
//     int min;
//     int max;
//     int height;
//     bool isBST;
// };

// LargestBST largestBSTSubtreeHelper(BinaryTreeNode<int> *root)
// {
//     if(root == NULL)
//     {
//         LargestBST output;
//         output.min = INT_MAX;
//         output.max = INT_MIN;
//         output.height = 0;
//         output.isBST = true;
//         return output;
//     }
    
//     LargestBST leftSub = largestBSTSubtreeHelper(root->left);
//     LargestBST rightSub = largestBSTSubtreeHelper(root->right);
    
//     if(!(leftSub.isBST && leftSub.max < root->data))
//     {
//         leftSub.isBST = false;
//     }
//     if(!(rightSub.isBST && rightSub.min > root->data))
//     {
//         rightSub.isBST = false;
//     }
    
//     LargestBST output;
    
//     if(!leftSub.isBST || !rightSub.isBST || root->data < leftSub.max || root->data > rightSub.min)
//     {
//         if(leftSub.height > rightSub.height)
//         {
//             leftSub.isBST = false;
//             return leftSub;
//         }
//         else
//         {
//             rightSub.isBST = false;
//             return rightSub;
//         }
//     }
    
//     output.isBST = true;
//     output.min = min(leftSub.min, min(rightSub.min, root->data));
//     output.max = max(leftSub.max, max(rightSub.max, root->data));
//     output.height = max(leftSub.height, rightSub.height) + 1;
//     return output;
    
// }


// 1st Method

bool isBST(BinaryTreeNode<int> *root, int minima, int maxima)
{
    if(root == NULL)
    {
        return true;
    }
    
    if(root->data < minima || root->data > maxima)
    {
        return false;
    }
    
    bool left = isBST(root->left, minima, root->data);
    bool right = isBST(root->right, root->data, maxima);
    
    return left && right;
}

int height(BinaryTreeNode<int> *root) {
    
    if(root == NULL)
    {
        return 0;
    }
    
    return max(height(root->left), height(root->right)) + 1;
    
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    
    // Write your code here
    
    // 1st Method
    
    if(isBST(root, INT_MIN, INT_MAX))
    {
        return height(root);
    }
    else
    {
        int left = largestBSTSubtree(root->left);
        int right = largestBSTSubtree(root->right);
        
        return max(left, right);
    }
    
    
    // 2nd Method
    
//     return largestBSTSubtreeHelper(root).height;
    
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
       
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
