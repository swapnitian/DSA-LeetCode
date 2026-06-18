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
    int findlfthgt(TreeNode* root){
        int hgt = 0;
        while(root){
            hgt++;
            root = root->left;
        }
        return hgt;
    }
    int findrgthgt(TreeNode* root){
        int hgt = 0;
        while(root){
            hgt++;
            root = root->right;
        }
        return hgt;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
            
        int left = findlfthgt(root);
        int right = findrgthgt(root);

        if(left == right) return (1 << left) -1;

        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};