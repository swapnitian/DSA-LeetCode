class Solution {
long long dp[10001];
    int recursion(vector<int>& nums, int idx, int n){

        if(idx == n-1) return 0;

        if(dp[idx] != -1) return dp[idx];

        int ans = 1e7;

        for(int i = 1; i <= min(n-1 ,nums[idx]); i++){
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
        // int n = arr.size();


        // GREDDY APPROACH
        if(n == 1) return 0;
        int curr = 0;
        int maxi = 0;
        int ans  = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi , i + nums[i]);
            
            if(maxi >= n-1) return ans+1;
            
            if(i == curr){
                if(i == maxi) return -1;
                
                ans++;
                
                curr = maxi;
            }
        }
        return ans+1;
    }
};