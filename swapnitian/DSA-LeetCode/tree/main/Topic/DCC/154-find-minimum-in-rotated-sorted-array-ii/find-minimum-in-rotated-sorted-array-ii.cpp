class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0; int end = nums.size()-1;
        int ans = 1e9;

        while(st <= end){
            // just skip the duplicate values 
            while(st < end && nums[st] == nums[st+1]){
                st++;
            }
            while(end > st && nums[end] == nums[end-1]){
                end--;
            }

            int mid = st + (end-st)/2;

            ans = min(ans , nums[mid]);

            if(nums[end] < nums[mid]){
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};