class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0; int end = nums.size()-1;
        int ans = 1e9;

        while(st <= end){
            int mid = st + (end-st)/2;

            ans = min(ans , nums[mid]);

            if(nums[st] < nums[mid]){
                if(nums[st] < nums[end] && nums[mid] < nums[end]){
                    end = mid-1;
                }else{
                    st = mid+1;
                }
            }else{
                if(nums[st] > nums[end] && nums[mid] > nums[end]){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        return ans;
    }
};