class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        long long maxk = INT_MAX;
    
        for(int i = 0; i < n; i++){
            if(nums[i] != i) maxk = maxk&i;
        }

        return (maxk == INT_MAX) ? 0 : maxk;
    }   
};