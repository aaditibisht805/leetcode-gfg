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
   
    ListNode* reverseKGroup(ListNode* head, int k) {
    if(head== 0)
    return 0;
    ListNode* cur= head;
    ListNode* prev = 0;
    ListNode* r=0;
    int c=0;
    while(cur!=0 && c <k)
    {
        cur=cur->next;
        c++;
    }
    if(c<k)
    return head;
    cur=head;
    c=0;

    while(cur!=0 && c< k)
    {  
        r= cur->next;
        cur->next = prev;
        prev= cur;
        cur= r;
        c++;

    } 
    if(r!=0)
    {
        head->next =  reverseKGroup(r, k);
    }  
    return prev;     
        
        
    }
};