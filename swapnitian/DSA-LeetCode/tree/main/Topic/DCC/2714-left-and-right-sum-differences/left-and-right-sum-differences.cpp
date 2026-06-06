class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightsum(n);
        vector<int> ans(n);

        rightsum[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            rightsum[i] = rightsum[i+1] + nums[i+1];
        }
        int leftsum = 0;
        for(int i = 0; i < n; i++){

            ans[i] = abs(rightsum[i]-leftsum);

            leftsum += nums[i];
        }

        return ans;
    }
};