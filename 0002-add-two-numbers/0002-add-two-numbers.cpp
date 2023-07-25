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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= 0;ListNode *p=0; int carry =0;
        


        while(l1!=0||l2!=0||carry==1)
        {  
            int d = (l1? l1->val: 0) + (l2 ?l2->val :0)+ carry;
            if(d>9)
            {
                d= d%10;
                carry=1;

            }
            else
            {
                carry =0;
            }
            ListNode* temp= new ListNode(d);
            temp->next=0;
            if(head==0)
            {
                head=temp;
                p=temp;

            }
            else
            {
               p->next=temp;
               p=temp;
            }
            if(l1!=0)
            l1=l1->next;
            if(l2!=0)
            l2=l2->next;
          


        }
        
         p->next=0;
         return head;

        
        
        
    }
};