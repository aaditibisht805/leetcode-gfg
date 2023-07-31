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
 class comp
 {
     public:
     bool operator()(ListNode* a, ListNode* b)
     {
          return a->val > b->val;

     }
 };
class Solution {
public:
   
    ListNode* mergeKLists(vector<ListNode*>& A){
        priority_queue<ListNode* , vector<ListNode*>,comp>pq;
        for(ListNode* s :A )
        {
            if(s!=0)
            pq.push(s);


        }
        ListNode* head=0;
         ListNode* tail =0;
         while(!pq.empty())
         {
            ListNode* x=pq.top();
             pq.pop();
             if(head==0)
             {
                 head= x;
                 tail= head;

             }
             else
             {
                tail->next= x;
                tail = x;
             }
             if(x->next)
             pq.push(x->next);
         }
        
         return head;

        
    }
};