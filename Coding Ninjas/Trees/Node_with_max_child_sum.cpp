/*

Node with maximum child sum
Send Feedback
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 
Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1

*/

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};


// template <typename T>

// class Pair
// {
//     public:
    
//     TreeNode<T>* greaterNode;
//     T sum;
// };

// Pair<int> helpermaxNode(TreeNode<int>* root)
// {
//     Pair<int> ans;
//     int childSum = root -> data;
//     for(int i=0;i<root->children.size();i++)
//     {
//         childSum = childSum + root->children[i] -> data;
//     }
    
//     ans.greaterNode = root;
//     ans.sum = childSum;
    
//     for(int i=0;i<root->children.size();i++)
//     {
//         Pair<int> smallAns = helpermaxNode(root->children[i]);
        
//         if(smallAns.sum > ans.sum)
//         {
//             ans = smallAns;
//         }
//     }
//     return ans;
// }

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    
    // Write your code here
    
    if(root == NULL)
    {
        return root;
    }
    
    // 1st method
    // return helpermaxNode(root).greaterNode;
    
    
    
    // 2nd Method
    
    queue<TreeNode<int>*> q;
    stack<TreeNode<int>*> s;
    
    int large = 0;
    q.push(root);
    
    while(!q.empty())
    {
        int maxSum = q.front() -> data;
        for(int i=0;i<root->children.size();i++)
        {
            q.push(root->children[i]);
            maxSum = maxSum + root->children[i]->data;
        }
        
        if(maxSum > large)
        {
            s.push(q.front());
            large = maxSum;
        }
        q.pop();
        root = q.front();
    }
    return s.top();
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}