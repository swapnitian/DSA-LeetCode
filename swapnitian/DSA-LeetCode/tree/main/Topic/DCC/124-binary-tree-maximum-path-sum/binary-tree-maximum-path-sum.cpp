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
    int maxi;
    int solve(TreeNode* root){
        if(root == NULL) return 0;

        int leftsum = max(0 , solve(root->left));
        int rightsum = max(0 , solve(root->right));

        maxi = max(maxi , leftsum + rightsum + root->val);
    
        return (root->val + max(leftsum , rightsum));
    }
public:
    int maxPathSum(TreeNode* root) {
        maxi = -1e9;
        solve(root);
        return maxi;
    }
};