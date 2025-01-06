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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* curr= ans;
        ListNode* h1 = list1;
        ListNode* h2 = list2;

        while(h1!=nullptr && h2!=nullptr)
        {
            if(h1->val < h2->val )
            {
                curr->next=h1;
                h1 = h1->next;
            }
            else{
                curr->next=h2;
                h2=h2->next;
            }
            curr=curr->next;
        }
        if(h1!=nullptr)
        {
            curr->next=h1;
        }
        else if(h2!=nullptr)
        {
            curr->next=h2;
        }
    return ans->next;      
    }
};