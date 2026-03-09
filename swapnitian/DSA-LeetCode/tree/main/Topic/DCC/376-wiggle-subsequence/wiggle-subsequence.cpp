class Solution {
private:
    int recursion(vector<int>&nums , int idx , int prev , vector<vector<int>>&dp){
        if(idx >= nums.size()-1) return 0  ;
    
        if(dp[idx][prev] != -1) return dp[idx][prev] ;

        int take = 0 ;
        int diff = nums[idx+1]-nums[idx] ;
        if(prev == 0){
            if(diff > 0){
                take = 1 + recursion(nums , idx+1 , 1 ,dp) ;
            }
        }else{
            if(diff < 0){
                take = 1 + recursion(nums , idx+1 , 0 ,dp) ;
            }
        }
        int not_take = recursion(nums , idx+1 , prev ,dp) ;

        return dp[idx][prev] = max(take , not_take) ;
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n+1 , vector<int>(2 ,-1)) ; // in this case i consider prev = 0 as a negative value ;
        return 1 + max(recursion(nums , 0 , 0 ,dp) , recursion(nums , 0 , 1 ,dp)) ;
    }
};