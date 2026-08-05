class Solution {
    void DFS(int node, vector<vector<int>> &adjlist, vector<int> &vis){
        
        vis[node] = 1;
        
        for(auto it : adjlist[node]){
            if(vis[it] == 0) {
                DFS(it, adjlist, vis);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> vis(n, 0);
        vector<vector<int>> adjlist(n);

        for(auto it : invocations){
            adjlist[it[0]].push_back(it[1]);
        }
        DFS(k, adjlist, vis);
    
        for(auto it : vis) cout << it << " ";
 
        vector<int> ans;

        for(int i = 0; i < n; i++) ans.push_back(i);

        for(int i = 0; i < n; i++){
            if(vis[i] == 1) continue;

            for(auto it : adjlist[i]){
                if(vis[it] == 1) return ans;
            } 
        }
        ans.clear();

        for(int i = 0; i < n; i++){
            if(vis[i] == 1) continue;

            ans.push_back(i);
        }

        return ans;
    }
};