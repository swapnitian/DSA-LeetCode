class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int mini =*min_element(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += (nums[i] - mini);
        }

        return sum;
    }
};