class Solution {
    int min_score = INT_MAX;
    void dfs(int n, vector<vector<pair<int,int>>>& adjlist, int node,
                vector<int>&vis){
        // if(node == n){
        //     return;
        // }
        vis[node] = 1;
        for(auto it : adjlist[node]){
            int v = it.first;
            int wt = it.second;

            min_score = min(min_score , wt);

            if(vis[v] == 0) dfs(n, adjlist, v, vis);
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjlist(n+1);

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
        
            adjlist[u].push_back({v, wt});
            adjlist[v].push_back({u, wt});
        }
        vector<int> vis(n+1, 0);
        dfs(n, adjlist, 1, vis);
    
        return min_score;
    }
};