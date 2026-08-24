class Solution {
    long long dp[10001];
    long long recursion(vector<long long>&pref, int idx, int n,vector<long long>&dp){
        if(idx == n-1) return pref[idx];
        
        if(dp[idx] != LLONG_MIN) return dp[idx];

        long long take = pref[idx] - recursion(pref, idx+1, n, dp);

        long long skip = recursion(pref, idx+1, n, dp);

        return dp[idx] = max(take, skip);
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> dp(n+1, LLONG_MIN);
        vector<long long> pref(n);
        pref[0] = stones[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] + stones[i];
        }

        return recursion(pref, 1, n, dp);
    }
};