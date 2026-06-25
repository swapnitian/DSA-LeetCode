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
    bool solve(TreeNode* root, long long mini, long long maxi){
        if(root->val <= mini || root->val >= maxi) return false;

        bool ans = true;
        if(root->left != NULL){
            ans = ans & solve(root->left, mini, root->val);
        }
        if(root->right != NULL){
            ans = ans & solve(root->right, root->val, maxi);
        }
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return false;

        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};