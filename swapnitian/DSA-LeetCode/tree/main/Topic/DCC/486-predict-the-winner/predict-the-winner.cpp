class Solution {
    int recursion(vector<int> &nums, int st, int end){
        if(st == end) return nums[st];

        return max(nums[st] - recursion(nums, st+1, end), nums[end] - recursion(nums, st, end-1));
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return recursion(nums, 0, n-1) >= 0;
    }
};