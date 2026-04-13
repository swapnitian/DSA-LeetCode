class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX ;
        int st = 0 ; int end = nums.size()-1 ;
        
        while(st <= end){
            if(nums[st] == target) ans = min(ans , abs(st - start)) ;

            if(nums[end] == target) ans = min(ans , abs(end - start)) ;
        
            st++ ; end-- ;
        }

        return ans;
    }
};