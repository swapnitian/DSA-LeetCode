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
    vector<string> ans;
    bool isLeaf(TreeNode* root){
        return (root->left == NULL && root->right == NULL);
    }
    void solve(TreeNode* root, string s){
        if(isLeaf(root)){
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }
        s += to_string(root->val);
        if(root->left != NULL){
            solve(root->left, s + "->");
            // s.pop_back();
        }
        if(root->right != NULL){
            solve(root->right, s + "->");
            // s.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");

        return ans;
    }
};