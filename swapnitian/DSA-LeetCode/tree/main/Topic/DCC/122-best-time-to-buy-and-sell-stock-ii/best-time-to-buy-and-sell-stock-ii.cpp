class Solution {
    int dp[30001][2];
    int recursion(vector<int>& prices, int idx, int buy, int val){
        int n = prices.size();
        if(idx >= n) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;
        if(buy){ // buy -> 1 means we have to buy
            profit += max(recursion(prices, idx+1, 1, val), recursion(prices, idx+1, 0, prices[idx]));
        }else{
            profit += max(recursion(prices, idx+1, 0, val),
                         prices[idx]-val + recursion(prices, idx, 1, 0));
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return recursion(prices, 0, 1, 0);
    }
};