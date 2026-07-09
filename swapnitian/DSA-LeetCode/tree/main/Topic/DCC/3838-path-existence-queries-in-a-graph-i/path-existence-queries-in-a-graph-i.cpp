class Disjoint_Set{
    vector<int> rank, parent, size;
public:
    Disjoint_Set(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUltimateParent(int u){
        if(u == parent[u]) return u;

        return parent[u] = findUltimateParent(parent[u]);
    }

    void Union_by_Rank(int u, int v){
        int ul_u = findUltimateParent(u);
        int ul_v = findUltimateParent(v);

        if(ul_u == ul_v) return;

        if(rank[ul_u] < rank[ul_v]){
            parent[ul_u] = ul_v;
        }else if(rank[ul_v] < rank[ul_u]){
            parent[ul_v] = ul_u;
        }else{
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        }
    }
    void Union_by_Size(int u, int v){
        int ul_u = findUltimateParent(u);
        int ul_v = findUltimateParent(v);

        if(ul_u == ul_v) return;

        if(size[ul_u] < size[ul_v]){
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }else{
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        Disjoint_Set ds(n);

        for(int i = 1; i < n; i++){
            if(abs(nums[i]-nums[i-1]) <= maxDiff){
                ds.Union_by_Size(i, i-1);
            }
        }

        vector<bool> res;
    
        for(auto it : queries){
            int u = it[0];
            int v = it[1];

            if(ds.findUltimateParent(u) == ds.findUltimateParent(v)){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};