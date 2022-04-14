/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode *start = head;
        ListNode *end = head;
        ListNode *temp = head;
        int count = 1;
        
        while(temp != NULL)
        {
            if(count < k)
            {
                start = start->next;
            }
            
            if(count > k)
            {
                end = end->next;
            }
            
            temp = temp->next;
            count++;
        }
        
        int curr = start->val;
        start->val = end->val;
        end->val = curr;
        
        return head;
        
    }
};