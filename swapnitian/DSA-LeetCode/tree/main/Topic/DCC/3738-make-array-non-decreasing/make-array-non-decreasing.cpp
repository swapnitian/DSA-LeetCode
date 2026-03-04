class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size() ;
        int prev = -1 ;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] >= prev){
                prev = nums[i] ;
                ans++ ;
            }
        }
        return ans ;
    }
};