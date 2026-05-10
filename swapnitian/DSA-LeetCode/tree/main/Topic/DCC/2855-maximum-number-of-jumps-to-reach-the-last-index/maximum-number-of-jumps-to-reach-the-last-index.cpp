class Solution {
private:
    int recursion(vector<int> &nums , int new_idx , int prev_idx , int target , int n,
                    vector<vector<int>> &dp){
    
        if(new_idx >= n) return INT_MIN;    
        int val = nums[new_idx] - nums[prev_idx] ;

        if(dp[new_idx][prev_idx] != -1) return dp[new_idx][prev_idx];

        if(new_idx == n-1){
            if(val < -target || val > target){
                return INT_MIN ;
            }

            return 1;
        }   

        int jump1 = INT_MIN ; 

        if(val >= - target && val <= target){
            jump1 = 1 + recursion(nums , new_idx+1 , new_idx , target , n ,dp);
        }

        int jump2 = recursion(nums , new_idx+1 , prev_idx , target , n ,dp);

        return dp[new_idx][prev_idx] = max(jump1 , jump2) ;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        int ans = recursion(nums , 0 , 0 , target , n , dp) -1 ;

        return ans < 0 ? -1 : ans;
    }
};