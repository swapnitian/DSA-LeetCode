class Solution {
    int recursion(vector<int> &piles, int idx, int n, vector<int>&dp){

        if(idx >= n) return 0;

        if(dp[idx] != INT_MIN) return dp[idx];

        int ans = INT_MIN;
        int sum = 0;
        for(int i = idx; i < min(n, idx+3); i++){
            sum += piles[i];
            ans = max(ans, sum - recursion(piles, i+1, n, dp));
        }
        return dp[idx] = ans ;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1, INT_MIN);
        int ans = recursion(stoneValue, 0, n, dp);
        
        if(ans > 0) return "Alice";
        else if(ans == 0) return "Tie";

        return "Bob";
    }
};