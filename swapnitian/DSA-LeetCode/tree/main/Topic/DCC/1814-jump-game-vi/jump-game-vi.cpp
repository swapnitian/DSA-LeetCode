class Solution {
    int recursion(vector<int>&nums, int idx, int k, int n){
        if(idx >= n) return 0;

        if(idx == n-1) return nums[idx];

        int ans = -1e9;

        for(int i = 1; i <= min(k , n-1); i++){
            if(idx+i <  n){
                int jump = nums[idx] + recursion(nums, idx+i, k , n);
                ans = max(ans , jump); 
            }
        }
        return ans;
    }
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1 , 0);
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for(int idx = 1; idx < n; idx++){
            if(!dq.empty() && dq.front() < idx-k){
                dq.pop_front();
            }
            dp[idx] = nums[idx] + dp[dq.front()];

            
            while(!dq.empty() && dp[dq.back()] <= dp[idx]){
                dq.pop_back();
            }
            
            dq.push_back(idx);
        }
        return dp[n-1];
    }
};