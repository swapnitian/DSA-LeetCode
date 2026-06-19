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
    TreeNode* Solve(vector<int>&preorder, vector<int>&inorder, int prestart, int preend,
                    int instart, int inend, unordered_map<int,int>&mp){
        if(prestart > preend || instart > inend) return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);
        
        int inroot = mp[root->val];
        int numsleft = inroot-instart;

        root->left = Solve(preorder, inorder, prestart+1, prestart+numsleft,
                            instart, inroot-1, mp);
        root->right = Solve(preorder, inorder, prestart+numsleft+1, preend,
                            inroot+1, inend, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = Solve(preorder,inorder,0,n-1,0,n-1,mp);

        return root;
    }
};