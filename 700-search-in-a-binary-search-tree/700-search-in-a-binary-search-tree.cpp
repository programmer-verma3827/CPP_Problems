/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        // 1st Method using Recursion (DFS)
        
//         if(root == NULL)
//         {
//             return NULL;
//         }
        
//         TreeNode* node = new TreeNode(val);
//         if(root->val > val)
//         {
//             node = searchBST(root->left, val);
//         }
        
//         else if(root->val < val)
//         {
//             node = searchBST(root->right, val);
//         }
        
//         else
//         {
//             node = root;
//         }
        
//         return node;
        
        // 2nd Method using Iterative
        
//         while(root != nullptr && root->val != val)
//         {
//             root = (root->val > val) ? root->left : root->right;
//         }
        
//         return root;
        
        // 3rd Method using BFS
        
//         if(root == NULL)
//         {
//             return NULL;
//         }
        
//         queue<TreeNode *> q;
//         q.push(root);
//         while(!q.empty())
//         {
//             int n = q.size();
//             for(int i=0;i<n;i++)
//             {
//                 TreeNode *front = q.front();
//                 q.pop();
                
//                 if(front->val == val)
//                 {
//                     return front;
//                 }
                
//                 if(front->left)
//                 {
//                     q.push(front->left);
//                 }
                
//                 if(front->right)
//                 {
//                     q.push(front->right);
//                 }
//             }
//         }
        
//         return NULL;
        
        // 4th Method using Binary Search
        
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->val == val)
        {
            return root;
        }
        
        if(root->val > val)
        {
            return searchBST(root->left, val);
        }
        
        if(root->val < val)
        {
            return searchBST(root->right, val);
        }
        
        return NULL;
    }
};