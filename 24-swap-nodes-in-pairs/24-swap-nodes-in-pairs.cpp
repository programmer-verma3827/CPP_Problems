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
    ListNode* swapPairs(ListNode* head) {
        
        // 1st Method (Recursive)
        
//         if(head == NULL || head->next == NULL)
//         {
//             return head;
//         }
        
//         ListNode *temp = head->next;
//         head->next = swapPairs(head->next->next);
//         temp->next = head;
        
//         return temp;
        
        
        // 2nd Method Iterative
        
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        queue<ListNode *> q;
        
        while(head)
        {
            q.push(head);
            head = head->next;
        }
        
        while(q.size() >= 2)
        {
            ListNode *first = q.front();
            q.pop();
            ListNode *second = q.front();
            q.pop();
            
            temp->next = second;
            temp = temp->next;
            temp->next = first;
            temp = temp->next;
        }
        
        if(!q.empty())
        {
            temp->next = q.front();
            temp = temp->next;
        }
        
        temp->next = NULL;
        return dummy->next;
        
    }
};