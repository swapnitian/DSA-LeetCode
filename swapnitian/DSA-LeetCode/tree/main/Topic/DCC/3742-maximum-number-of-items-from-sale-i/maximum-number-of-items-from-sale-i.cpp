class Solution {
int dp[1001][1501][2];
int recursion(vector<vector<int>>&nums, int b, int idx, int n, int f1){
    if(idx >= n) return 0;

    if(dp[idx][b][f1] != -1) return dp[idx][b][f1];
    
    int div = nums[idx][0];
    int cost = nums[idx][1];
    
    int take = 0;
    
    if(cost <= b){
        if(!f1){
            take = max(take , 1 + div + recursion(nums,b-cost,idx,n,1));
        }else{
            take = max(take ,1 + recursion(nums,b-cost,idx,n,1));
        }
    }
    int not_take = recursion(nums,b,idx+1,n,0);   

    return dp[idx][b][f1] = max(take , not_take);
}
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<vector<int>> nums = items;
        for(int i = 0; i < n; i++){
            int cnt  = 0;
            for(int j = 0; j < n; j++){
                if(i == j) continue;

                if((items[j][0]%items[i][0]) == 0){
                    cnt++;
                }
            }
            nums[i][0] = cnt;
        }
        memset(dp , -1 , sizeof(dp));
        return recursion(nums,budget,0,n,0);
    }
};