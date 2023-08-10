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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp= head; ListNode* r=0;
        while(temp!=0)
        {
            while(temp->next!=0&& temp->val==temp->next->val)
            {
                r= temp->next;
                temp->next = r->next;
            
                
            }
            temp=temp->next;
        }
        return head;
        
    }
};