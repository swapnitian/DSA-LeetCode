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
private:
    int dfs(TreeNode*root , int bin){
        if(root == NULL){
            return 0 ;
        }
        bin = 2*bin + root->val ;

        if(root->left == NULL && root ->right == NULL){
            return bin ;
        }

        int left = dfs(root->left , bin) ;
        int right = dfs(root->right , bin) ;
    
        return (left + right) ;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        // cout << bin << endl;
        return dfs(root , 0) ; ;
    }   
};