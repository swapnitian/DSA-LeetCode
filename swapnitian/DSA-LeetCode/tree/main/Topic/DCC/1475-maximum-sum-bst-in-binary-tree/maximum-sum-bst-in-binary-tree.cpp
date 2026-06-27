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
class Nodevalue{
public:
    int MinNode, MaxNode, Sum;
    Nodevalue (int MinNode, int MaxNode, int Sum){
        this->Sum = Sum;
        this->MinNode = MinNode;
        this->MaxNode = MaxNode;
    }
};
class Solution {
    int ans = 0;
    Nodevalue maxSumBSTSubtreeHelper(TreeNode* root){
        if(root == NULL) return Nodevalue(INT_MAX, INT_MIN, 0);

        auto left = maxSumBSTSubtreeHelper(root->left);
        auto right = maxSumBSTSubtreeHelper(root->right);

        if(root->val > left.MaxNode && root->val < right.MinNode){
            int Curr_sum = left.Sum + right.Sum + root->val;
            ans = max(ans , Curr_sum);
            return Nodevalue(min(root->val, left.MinNode),
                     max(root->val, right.MaxNode), Curr_sum);
        }
        return Nodevalue(INT_MIN, INT_MAX, 0);
    }   
public:
    int maxSumBST(TreeNode* root) {
        maxSumBSTSubtreeHelper(root);
        return ans;
    }
};