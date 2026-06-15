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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return{};
        queue<pair<int,TreeNode*>> q;
        map<int,int> mp;
        
        q.push({0 , root});
        
        while(!q.empty()){
            TreeNode* Tnode = q.front().second;
            int Hline = q.front().first;
            
            q.pop();
            
            mp[Hline] = Tnode->val;
            
            if(Tnode->left){
                q.push({Hline+1 , Tnode->left});
            }
            if(Tnode->right){
                q.push({Hline+1 , Tnode->right});
            }
        }
        vector<int> ans;
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};