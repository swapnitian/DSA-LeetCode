class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int cnt = 1;
        for(int i = 0; i < n-1; i++){
            if(nums[i] < nums[i+1])cnt++;
            else cnt = 1;

            ans = max(cnt, ans);
        }
        cnt = 1;
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1])cnt++;
            else cnt = 1;

            ans = max(cnt, ans);
        }

        return ans;
    }
};