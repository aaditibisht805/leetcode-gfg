//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
/*void SortedStack :: sort()
{
   //Your code here
   vector<int> v;
   while(!s.empty())
   {
       int x= s.top();
       v.push_back(x);
       s.pop();
   }
   sort(v.begin(),v.end(),greater<int>());
   for(int i=0;i<v.size();i++)
   {
       cout<< v[i]<<" ";
   }
}*/
void SortedStack::sort() {
    stack<int> tempStack;

    while (!s.empty()) {
        int currentElement = s.top();
        s.pop();

        while (!tempStack.empty() && tempStack.top() < currentElement) {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(currentElement);
    }

    // Copy elements back to the original stack to have them in sorted order.
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}
