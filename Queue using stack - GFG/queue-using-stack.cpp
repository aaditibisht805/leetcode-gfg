//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> s1, s2;
public:

    void enqueue(int x) {
        
        if(!s2.empty())
        {
            while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
            }
        }
    
        
        s1.push(x);
        
        
    }

    int dequeue() {
       while(!s1.empty())
        { int x= s1.top();
          s1.pop();
            s2.push(x);
        }
        
        if(s2.empty())
        return -1;
        
        int val = s2.top();
        s2.pop();
      
        return val;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends