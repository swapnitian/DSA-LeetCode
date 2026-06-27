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
class BSTIterator{
private:
    stack<TreeNode*> st;
    // i assume reverse -> true -> means we are following the befoe that is right root left
    // reverse -> false -> means we are following next that is lrft , root , right
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isreverse){
        reverse = isreverse;
        pushALL(root); // it will pushes the elements according to the condition
    }
    int next(){
        TreeNode* node = st.top();
        st.pop();
        // this means follow the before
        if(reverse) pushALL(node->left);
        else pushALL(node->right);

        return node->val;
    }
private:
    void pushALL(TreeNode* node){
        while(node != NULL){
            st.push(node);
            if(reverse){
                node = node->right;
            }else{
                node = node->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        BSTIterator l(root , false);
        BSTIterator r(root , true);

        int st = l.next(); // this will work as pointer to the starting of BST
        int end = r.next(); // this will work as pointer from the end of BST 

        while(st < end){
            if(st + end == k) return true;
            else if(st + end > k) end = r.next();
            else st = l.next();
        }

        return false;
    }
};