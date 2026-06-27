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
    // simply follow the idea of range for the left tree and right tree
    TreeNode* BuildBST(vector<int>& arr, int &idx, int bound){
        if(idx == arr.size() || arr[idx] > bound) return NULL;

        TreeNode* root = new TreeNode(arr[idx++]);

        root->left = BuildBST(arr, idx, root->val);
        root->right = BuildBST(arr, idx, bound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder){  
        int idx = 0;
        return BuildBST(preorder, idx, INT_MAX);
    }
};