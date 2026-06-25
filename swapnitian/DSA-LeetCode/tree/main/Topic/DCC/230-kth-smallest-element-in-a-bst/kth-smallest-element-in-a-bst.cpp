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
    int ans = 0;
    void inorder(TreeNode*root, int k, int &cnt){
        if(root == NULL) return;
        inorder(root->left, k, cnt);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        inorder(root->right, k, cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        inorder(root, k, cnt);
        return ans;
    }
};