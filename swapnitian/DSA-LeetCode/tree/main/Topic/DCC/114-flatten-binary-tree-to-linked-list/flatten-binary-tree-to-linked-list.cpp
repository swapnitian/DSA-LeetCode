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
    // TreeNode* Prev = NULL;
    void flatten(TreeNode* root) {
        // if(root == NULL) return ;

        // flatten(root->right);
        // flatten(root->left);

        // root->right = Prev;
        // root->left = NULL;

        // Prev = root;


        // 2nd Approach -->

        // [M O R R I S - -  T R A V E R S A L]--

        TreeNode* Curr = root;

        while(Curr != NULL){
            if(Curr->left != NULL){
                TreeNode* Prev = Curr->left;
                while(Prev->right != NULL){
                    Prev = Prev->right;
                }

                Prev->right = Curr->right;
                Curr->right = Curr->left;
                Curr->left = NULL;
            }
            Curr = Curr->right;
        }
    } 
};