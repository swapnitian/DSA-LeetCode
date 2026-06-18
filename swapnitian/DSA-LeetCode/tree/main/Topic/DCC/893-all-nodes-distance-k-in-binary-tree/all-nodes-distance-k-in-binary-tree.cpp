/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void Mark_Parents(TreeNode* root, map<TreeNode*,TreeNode*>&mp){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                TreeNode* Curr_node = q.front();
                q.pop();

                if(Curr_node->left){
                    q.push(Curr_node->left);
                    mp[Curr_node->left] = Curr_node;
                }
                if(Curr_node->right){
                    q.push(Curr_node->right);
                    mp[Curr_node->right] = Curr_node;
                }
            }
        }
    }
    vector<int> res;
    void dfs(TreeNode* root,int k, int dist
                ,map<TreeNode*,TreeNode*>&parent_track,map<TreeNode*,int>&vis){
        if(root == NULL) return;

        if(dist == k){
            res.push_back(root->val);
            return; 
        }
        // left
        if(root->left && vis[root->left] == 0){
            vis[root->left] = 1;
            dfs(root->left,k,dist+1, parent_track, vis);
        }
        // right
        if(root->right && vis[root->right] == 0){
            vis[root->right] = 1;
            dfs(root->right,k, dist+1, parent_track, vis);
        }
        // parent node
        if(parent_track[root] && vis[parent_track[root]] == 0){
            vis[parent_track[root]] = 1;
            dfs(parent_track[root], k, dist+1, parent_track, vis);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent_track;
        Mark_Parents(root, parent_track);

        map<TreeNode*,int> vis;
        vis[target] = 1;
        dfs(target, k, 0, parent_track, vis);
        // queue<TreeNode*> q;
        // q.push(target);
        // vis[target] = 1;

        // int level = 0;
        // while(!q.empty()){
        //     int sz = q.size();
        //     if(level == k) break;
        //     level++;

        //     for(int i = 0; i < sz; i++){
        //         TreeNode* node = q.front();
        //         q.pop();

        //         if(node->left && vis[node->left] == 0){
        //             q.push(node->left);
        //             vis[node->left] = 1;
        //         }
        //         if(node->right && vis[node->right] == 0){
        //             q.push(node->right);
        //             vis[node->right] = 1;
        //         }
        //         if(parent_track[node] && vis[parent_track[node]] == 0){
        //             q.push(parent_track[node]);
        //             vis[parent_track[node]] = 1;
        //         }
        //     }
        // }
        // vector<int> ans;
        // while(!q.empty()){
        //     TreeNode* node = q.front();
        //     q.pop();
        //     ans.push_back(node->val);
        // }
        // return ans;

        return res;
    }
};