class Solution {
private:
    long long recursion(vector<int>&nums , int XOR , int target, int idx ,
                         vector<vector<long long>>&dp){
        if(idx < 0) {
            if (XOR == target) return 0;
            else return 1e8 ;
        }
        if(dp[idx][XOR] != -1) return dp[idx][XOR] ;
        
        int take =   recursion(nums , XOR^nums[idx] , target , idx-1 , dp) ; 
        int not_take = 1 + recursion(nums , XOR , target , idx-1 , dp) ;

        return dp[idx][XOR] = min(take , not_take) ;
    }
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size() ;
        long long sum = 0 ;
        
        for(int i = 0 ; i< n ; i++) sum += nums[i] ;
        
        vector<vector<long long>> dp(n+1 , vector<long long>(sum+1, -1)) ;
        long long ans = recursion(nums , 0 , target , n-1 , dp) ; 
        return ans == 1e8 ? -1 : ans ;
    }
};