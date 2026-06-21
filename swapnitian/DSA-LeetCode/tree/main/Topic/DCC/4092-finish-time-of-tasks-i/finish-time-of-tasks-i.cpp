class Solution {
using ll = long long;
    ll dfs(vector<vector<int>>&adjlist,vector<int>& baseTime, int node){
        if(adjlist[node].size() == 0) return baseTime[node];

        ll latest = 0; ll earliest = 1e15;
        for(auto it : adjlist[node]){
            ll val = dfs(adjlist, baseTime, it);
            latest = max(latest , val);
            earliest = min(earliest , val);
        }

        ll time = 2*latest - earliest + baseTime[node];

        return time; 
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adjlist(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adjlist[u].push_back(v);
            // adjlist[v].push_back(u);
        }
        ll ans = dfs(adjlist, baseTime, 0);
        return ans;
    }
};