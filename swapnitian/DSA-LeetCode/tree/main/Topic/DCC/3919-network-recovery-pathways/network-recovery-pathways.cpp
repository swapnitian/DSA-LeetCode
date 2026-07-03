class Solution {
    using ll = long long;
    bool check(int mid, int n, ll k, vector<vector<pair<int,int>>>&adjlist){
        vector<ll> dist(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        pq.push({0LL, 0}); // {dist, node}

        while(!pq.empty()){
            ll d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > k) return false;

            if(node == n-1) return true;

            if(d > dist[node]) continue;

            for(auto it : adjlist[node]){
                int adjnode = it.first;
                int cost    = it.second;

                if(cost < mid) continue;

                if(d + cost < dist[adjnode]){
                    dist[adjnode] = d + cost;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        return false;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        // totak nodes -- 
        int n = online.size();
        int st = INT_MAX; int end = 0;
        // adjlist -> {{dist, node}};

        vector<vector<pair<int,int>>> adjlist(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(!online[u] || !online[v]) continue;

            adjlist[u].push_back({v, wt});
            st = min(st, wt);
            end = max(end, wt);
        }

        int ans = -1;
        // Apply the binary search on the cost 
        while(st <= end){
            int mid = st + (end-st)/2;

            if(check(mid, n, k, adjlist)){
                ans = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }

        return ans;
    }
};