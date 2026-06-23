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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        TreeNode* Curr = root;

        while(Curr != NULL){
            if(Curr->val < val){
                if(Curr->right != NULL){
                    Curr = Curr->right;
                }else{
                    TreeNode* node = new TreeNode(val);
                    Curr->right = node;
                    break;
                }
            }else{
                if(Curr->left != NULL){
                    Curr = Curr->left;
                }else{
                    TreeNode* node = new TreeNode(val);
                    Curr->left = node;
                    break;
                }
            }
        }
        return root;
    }
};