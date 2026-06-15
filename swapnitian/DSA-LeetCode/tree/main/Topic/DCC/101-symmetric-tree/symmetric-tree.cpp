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
    bool recursion(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL || root2 == NULL) return (root1 == root2);
        
        if(root1->val != root2->val) return false;

        bool left = recursion(root1->left, root2->right);
        bool right = recursion(root1->right, root2->left);
    
        return (left && right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return recursion(root, root);
    }
};