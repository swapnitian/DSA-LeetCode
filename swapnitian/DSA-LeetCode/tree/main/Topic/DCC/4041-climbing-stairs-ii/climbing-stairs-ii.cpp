class Solution {
    int dp[100002];
    int recursion(int idx, vector<int> &costs, int n){
        if(idx == n-1){
            return 0;
        }
        if(dp[idx+1] != -1) return dp[idx+1];
        
        int cost = 1e9;
        
        if(idx+1 < n){
            cost = min(cost, costs[idx+1] + 1 + recursion(idx+1, costs, n));
        }
        if(idx+2 < n){
            cost = min(cost, costs[idx+2] + 4 + recursion(idx+2, costs, n));
        }
        if(idx+3 < n){
            cost = min(cost, costs[idx+3] + 9 + recursion(idx+3, costs, n));
        }

        return dp[idx+1] = cost;
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return recursion(-1, costs, n); 
    }
};