//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
       /* Node* LCA(Node *root, int n1, int n2)
        { /* if(root==NULL)
         return root;
           map<Node*, pair<Node*,Node*>>m;
           queue<Node*>q; vector<Node*>v;
           m[root]={root, 0};
           q.push(root);
           while(!q.empty())
           {   int size= q.size();
               
               for(int i=0;i<size;i++)
               {
                    Node* node=q.front();
                   q.pop();
                   if(node->left)
                   {
                       q.push(node->left);
                       m[node->left]={node->left, node};
                       
                   }
                    if(node->right)
                   {
                       q.push(node->right);
                       m[node->right]={node->right, node};
                       
                   }
               }
               
               
           }
           for(auto x: m)
           {
               if(x.first->data==n1||x.first->data==n2)
               {
                   v.push_back(x.second.first);
                   v.push_back(x.second.second);
                   
               }
           }
           map<Node*,int>mp;
           for(int i=0;i<v.size();i++)
           {
              mp[v[i]]++;
   
           }
           for(auto x: mp)
           {
               if(x.second==2)
               return x.first;
          
           
               
           }
           //return root;
        }*/
        Node* LCA(Node* root, int n1, int n2)
{
   /* if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;*/
    while (root)
                if (n1<root->data && n2<root->data)
                    root=root->left;
                else if (n1>root->data && n2>root->data)
                    root=root->right;
                else return root;
            //return NULL;
}

  
};


//{ Driver Code Starts.

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends