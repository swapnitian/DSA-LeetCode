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
    TreeNode* Make_BST(vector<int>&nodes , int l , int r){
        if(l > r) return NULL ;

        int mid = (l+r)/2 ;

        TreeNode* root = new TreeNode(nodes[mid]) ;

        root->left = Make_BST(nodes , l , mid-1)  ;
        root->right = Make_BST(nodes , mid+1 , r) ;

        return root ;
    }
    void solve(TreeNode* root , vector<int>&nodes){
        if(root == NULL) return ;
    
        solve(root->left , nodes) ;
        nodes.push_back(root->val) ;
        solve(root->right , nodes) ;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes; 
        solve(root , nodes) ;
        int n = nodes.size() ;
        return Make_BST(nodes , 0 , n-1) ;
    }
};