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
int solve( TreeNode* root , int &maxi)
{
    if(root==0)
    return 0;
    int leftsum = max(0, solve(root->left, maxi));   // max for ignoring negative node-val 
    int rightsum = max(0,solve(root->right, maxi));
    maxi = max (maxi, leftsum+rightsum+ root->val);
    return root->val+ max(leftsum, rightsum);
}
    int maxPathSum(TreeNode* root) {
        //extension of diametr of b tree -- longest path 
        // instead of return 1+.. node ->val + ....
        int maxi= INT_MIN;
         int r= solve(root, maxi);
         return maxi;
        
    }
};