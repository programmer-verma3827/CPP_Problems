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
    
    ListNode *midPoint(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode *mergeTwoLL(ListNode *head1, ListNode *head2)
    {
        if(head1 == NULL)
        {
            return head2;
        }
        
        if(head2 == NULL)
        {
            return head1;
        }
        
        if(head1->val < head2->val)
        {
            head1->next = mergeTwoLL(head1->next, head2);
            return head1;
        }
        
        else
        {
            head2->next = mergeTwoLL(head1, head2->next);
            return head2;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode *head1 = head;
        ListNode *temp = midPoint(head);
        ListNode *head2 = temp->next;
        temp->next = NULL;
        
        ListNode *h1 = sortList(head1);
        ListNode *h2 = sortList(head2);
        
        ListNode *firstHead = mergeTwoLL(h1, h2);
        return firstHead;
        
    }
};