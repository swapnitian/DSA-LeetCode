class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i] > nums[i+1]){
                ans += abs(nums[i]-(nums[i+1]));   
            }
        }
        return ans;
    }
};