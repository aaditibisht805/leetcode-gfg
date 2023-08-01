/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         queue<TreeNode*>q; 
        vector<int>v;
        if (root== NULL)
            return v;
        q.push(root);
      
        while(!q.empty())
        {  int size = q.size();
            vector<int>row(size);
          
            for(int i=0;i<size; i++ )
            {
                TreeNode*  x= q.front();
                q.pop();
                row[i]= x->val;
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                
            }  
            v.push_back(row[size-1]);            
            
        }
        return v;
         
    }
};