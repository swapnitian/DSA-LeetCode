class Solution {
    long long dp[2][101][101];
    long long recursion(vector<int> &piles, int idx, int n, int M, int person){
        if(idx >= n) return 0;

        if(dp[person][idx][M] != -1) return dp[person][idx][M];

        long long ans = (person == 1) ? -1 : INT_MAX;
        long long sum = 0;
        for(int x = 1; idx + x <= n && x <= 2*M; x++){
            sum += piles[idx+x-1];

            if(person == 1){
                ans = max(ans, sum + recursion(piles, idx+x, n, max(M, x), 0));
            }else{
                ans = min(ans, recursion(piles, idx+x, n, max(M,x), 1));
            }
        }

        return dp[person][idx][M] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return recursion(piles, 0, n, 1, 1);
    }
};