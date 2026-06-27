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
    TreeNode* Prev;
    TreeNode* middle;
    TreeNode* first;
    TreeNode* last;
private:
    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if(Prev != NULL && (root->val < Prev->val)){
            if(first == NULL){// this is for 1st violations
                first = Prev;
                middle = root;
            }else{ // this is for 2nd violation
                last = root;
            }
        }
        Prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        middle = first = last = NULL;
        Prev = new TreeNode(INT_MIN);

        inorder(root);
        if(first && last) swap(first->val, last->val);
        else swap(first->val, middle->val);

    }
};