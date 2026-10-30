class Solution {
    using ll = long long;
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n == 1) return 0;

        vector<vector<pair<int,int>>> adjlist(n);
        for(auto it : edges){
            adjlist[it[0]].push_back({it[1], it[2]});
        }

        vector<vector<ll>> dist(n+1, vector<ll>(k+1, LLONG_MAX));
        dist[0][0] = 0;

        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
        pq.push({0, 0, 1});

        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();

            ll d = val[0];
            ll node = val[1];
            ll cnt = val[2];
            // if(dist[node][cnt] )

            if(node == n-1) break;

            for(auto it : adjlist[node]){
                int adjnode = it.first;
                int wt = it.second;

                int ncnt = (labels[adjnode] == labels[node]) ? cnt+1 : 1;

                if(ncnt > k) continue;

                int ndist = wt + d;

                if(ndist < dist[adjnode][ncnt]){
                    dist[adjnode][ncnt] = ndist;
                    pq.push({ndist, adjnode, ncnt});
                }
            }
        }

        ll ans = LLONG_MAX;
        for(int i = 1; i <= k; i++){
            ans = min(ans, dist[n-1][i]);
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};