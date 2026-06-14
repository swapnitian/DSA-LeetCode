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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        bool lefttoright = true;
        while(!q.empty()){
            int sz = q.size();
            vector<int>helper(sz);
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();

                int idx = (lefttoright) ? i : (sz - i -1);

                helper[idx] = node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            lefttoright = !lefttoright;

            ans.push_back(helper);
        }
        return ans;
    }
};