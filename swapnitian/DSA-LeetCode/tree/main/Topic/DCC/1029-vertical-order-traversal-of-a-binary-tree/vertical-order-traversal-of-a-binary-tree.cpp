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
    void solve(TreeNode* root,int r, int c,map<int,map<int,multiset<int>>> &mp){
        if(root == NULL) return;

        mp[c][r].insert(root->val);

        solve(root->left,r+1, c-1, mp);
        solve(root->right,r+1, c+1, mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        solve(root ,0 , 0 , mp);
        vector<vector<int>> ans;
    
        for(auto it : mp){
            vector<int> temp;
            for(auto q : it.second){
                temp.insert(temp.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};