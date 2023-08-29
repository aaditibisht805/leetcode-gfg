//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
   /* Node *compute(Node *head)
    {
      /*  Node* temp , * r, *p;
        temp= head;
        p=head;
        r=temp->next;
        while(temp!=0 && r!=0)
        {  
            if(r->data> temp->data)
            {
                if(temp==head)
                {
                    head=head->next;
                    temp=head;
                    p=head;
                    r=temp->next;
                    
                }
                else
                {
                    p->next= temp->next ;
                   temp=p->next;
                   
                   
                }
            }
             else  if(r->data<=temp->data)
            {
               r=r->next;
            }
             if(temp==0|| r==0)
            break;
            if(r->next==0)
            {  if(temp->data< r->data)
               {
                   if(temp==head)
                   head=head->next;
                   temp=head;
                   p=head;
               }
               else
               
               
               { p=temp;
                temp=temp->next;
                r=temp->next;
               }
                
            }
             
          
         
        }
        return head;*/
     


   /* Node* temp = head;
    Node* p = nullptr;

    while (temp != nullptr && temp->next != nullptr) {
        Node* r = temp->next;

        if (r->data > temp->data) {
            if (temp == head) {
                head = head->next;
                temp = head;
                p = head;
            } else {
                p->next = temp->next;
                temp = p->next;
            }
        } else {
            p = temp;
            temp = temp->next;
        }
    }

    return head;


    }
    struct Node {
    int data;
    Node* next;
};*/

Node* compute(Node* head) {
    Node* current = head;
    Node* prev = nullptr;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        bool removeCurrent = false;

        Node* temp = nextNode;
        while (temp != nullptr) {
            if (temp->data > current->data) {
                removeCurrent = true;
                break;
            }
            temp = temp->next;
        }

        if (removeCurrent) {
            if (prev == nullptr) {
                head = nextNode;
            } else {
                prev->next = nextNode;
            }
            delete current;
        } else {
            prev = current;
        }

        current = nextNode;
    }

    return head;
}

    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends