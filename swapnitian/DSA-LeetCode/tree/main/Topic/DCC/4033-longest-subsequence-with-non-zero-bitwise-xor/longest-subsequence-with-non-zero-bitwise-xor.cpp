class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        bool f1 = true;
        for(int i = 0; i < n; i++){
            x ^= nums[i];
            if(nums[i] > 0) f1 =false;
        }

        if(x > 0) return n;

        return f1 ? 0 : n-1;
    }
};