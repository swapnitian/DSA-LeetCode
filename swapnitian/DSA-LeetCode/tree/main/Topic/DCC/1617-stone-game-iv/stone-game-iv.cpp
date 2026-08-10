class Solution {
    int dp[2][100001];
    bool recursion(int person, int n){
        if(n == 0){
            return false;
        }

        if(dp[person][n] != -1) return dp[person][n];

        bool ans = false;
        for(int x = 1; x*x <= n; x++){
            ans =  ans | (!recursion(!person, n-x*x));
        }
        return dp[person][n] = ans;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+2, false);

        for(int i = 1; i <= n; i++){
            bool ans = false;
            for(int x = 1; x*x <= i; x++){
                if(!dp[i-x*x]){
                    dp[i] = true;
                    break;
                }
            }
            // dp[i] = false;
        }
        return dp[n];
    }
};