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
    bool hasCycle(ListNode *head) {
         ListNode * temp, * r;
        temp = head;
        r= head;
        if(head==0)
            return false;
        if(head->next==0)
        {
            return false ;
        }
        while(r!=0 && r->next!=0)
        {
            r= r->next->next ;
            temp = temp ->next ;
            if(r== temp)
                return true ;
                
        }
        return false ;
        
    }
};