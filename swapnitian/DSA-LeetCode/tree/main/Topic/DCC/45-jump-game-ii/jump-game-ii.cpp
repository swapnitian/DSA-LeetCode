class Solution {
long long dp[10001];
    int recursion(vector<int>& nums, int idx, int n){

        if(idx == n-1) return 1;

        if(dp[idx] != -1) return dp[idx];

        int ans = 1e7;

        for(int i = 1; i <= min(n-1 ,nums[idx]); i++){
            // int j = idx+i+1;
            if(idx+i < n && i <= nums[idx]){
                int jump = 1 + recursion(nums, idx+i,n);
                ans = min(ans, jump);
            }
        }
        return dp[idx] = ans;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return recursion(nums,0,n)-1;
    }
};