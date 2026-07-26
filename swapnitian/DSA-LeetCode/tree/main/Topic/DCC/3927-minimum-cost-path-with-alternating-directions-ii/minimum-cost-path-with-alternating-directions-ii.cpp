class Solution {
using ll = long long;
    ll recursion(int r, int c, int m, int n, vector<vector<int>>& waitCost,
                    int odd, vector<vector<vector<ll>>>& dp){
        if(r >= m || c >= n) return LLONG_MAX;

        if(r == m-1 && c == n-1){
            return (r+1)*(c+1);
        }

        if(dp[r][c][odd] != -1) return dp[r][c][odd];

        ll ans = LLONG_MAX;
        if(odd){
            ll right = LLONG_MAX;
            if(c+1 < n){
                right = (r+1)*(c+1) + recursion(r, c+1, m, n, waitCost, 0,dp);
            }
            ll down = LLONG_MAX;
            if(r+1 < m){
                down = (r+1)*(c+1) + recursion(r+1, c, m, n, waitCost, 0,dp);
            }
            ans = min(down, right);
        }else{
            ans = waitCost[r][c] + recursion(r, c, m, n, waitCost, 1,dp);
        }
        return dp[r][c][odd] = ans;
    }
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        // vector<vector<vector<ll>>> dp(m+1, vector<vector<ll>>(n+1, vector<ll>(2, -1)));
        
        // return recursion(0, 0, m, n, waitCost, 1,dp);
    
        //   T A B U L A T I O N 
        vector<vector<vector<ll>>> dp(m+1, vector<vector<ll>>(n+1, vector<ll>(2, LLONG_MAX)));

        dp[m-1][n-1][1] = m*n;
        dp[m-1][n-1][0] = m*n;

        for(int r = m-1; r >= 0; r--){
            for(int c = n-1; c >= 0; c--){
                if(r == m-1 && c == n-1) continue;

                for(int odd = 1; odd >= 0; odd--){
                    ll ans = LLONG_MAX;
                    if(odd){
                        ll right = LLONG_MAX;
                        if(c+1 < n) right = (r+1)*(c+1) + dp[r][c+1][0];
                        ll down = LLONG_MAX;
                        if(r+1 < m) down = (r+1)*(c+1) + dp[r+1][c][0];

                        ans = min(right, down);
                    }else{
                        ans = waitCost[r][c] + dp[r][c][1];
                    }

                    dp[r][c][odd] = ans;
                }
            }
        }
        return dp[0][0][1];
    }
};