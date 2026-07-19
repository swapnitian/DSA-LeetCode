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
    int cnt = 0;
    int postorder(TreeNode* root){
        if(root == NULL) return 0;

        int left = postorder(root->left);
        int right = postorder(root->right);

        int maxi = max({root->val, left, right});

        if(maxi == root->val) cnt++;

        return maxi;
    }
public:
    int countDominantNodes(TreeNode* root) {
        postorder(root);

        return cnt;
    }
};