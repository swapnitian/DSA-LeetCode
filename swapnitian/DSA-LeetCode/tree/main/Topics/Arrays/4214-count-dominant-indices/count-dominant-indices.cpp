class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size() ;
        int total_sum = 0 ;
        for(auto it : nums) total_sum += it ;
        int rem = n ; int ans = 0 ;
        for(int i = 0 ; i < n-1 ; i++){
            total_sum -= nums[i] ;
            rem-- ;
            if(nums[i] > total_sum/rem) ans++ ;
        }
        return ans ;
    }
};