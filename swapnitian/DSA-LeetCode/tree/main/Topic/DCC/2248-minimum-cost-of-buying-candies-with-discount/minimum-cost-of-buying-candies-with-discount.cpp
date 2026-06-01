class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin() , cost.end());
        int ans = 0;

        if(n == 1) return cost[0];
        if(n == 2) return cost[0] + cost[1];

        for(int i = n-1; i >= 0; i = i-3){
            if(i > 0) ans += cost[i] + cost[i-1];
            else ans += cost[i];
        }
        return ans;
    }  
};