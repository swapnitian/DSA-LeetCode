class Solution {
    int dp[501][501];
    int recursion(int st, int end, vector<int> &piles){
        if(st == end) return piles[st];

        if(dp[st][end] != -1) return dp[st][end];

        return dp[st][end] = max(piles[st] - recursion(st+1, end, piles), 
                    piles[end] - recursion(st, end-1, piles));
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return recursion(0, n-1, piles) >= 0;
    }
};