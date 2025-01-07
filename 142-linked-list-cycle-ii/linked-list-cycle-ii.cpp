/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head==nullptr)
        {
            return NULL;
        }
        ListNode *fast= head;
        ListNode *slow= head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                ListNode *st= head;
                while(st!=slow)
                {
                    st=st->next;
                    slow=slow->next;
                }
                return st;
                
            }
        }
        return NULL;
        
    }
};