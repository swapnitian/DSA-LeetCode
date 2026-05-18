class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
       
        vector<int> dist(n+1 , INT_MAX);
        dist[0] = 0;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int node = q.front();     
            q.pop();

            if(node == n-1){
                return dist[n-1];
            }

            // forward 
            if(node < n-1 && dist[node] + 1 < dist[node+1]){
                dist[node+1] = dist[node] + 1;
                q.push(node+1);
            }

            // backward
            if(node >= 1 && dist[node] + 1 < dist[node-1]){
                dist[node-1] = dist[node] + 1;
                q.push(node-1);
            }

            // jump 

            for(auto it : mp[arr[node]]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }   
            }
            mp[arr[node]].clear(); // this prevents us to create duplicate travel
        }
        return -1;
    }
};