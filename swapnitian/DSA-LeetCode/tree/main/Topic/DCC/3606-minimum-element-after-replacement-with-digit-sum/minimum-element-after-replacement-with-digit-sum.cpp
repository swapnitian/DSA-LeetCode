class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int sum = 0;
            while(num > 0){
                int dig = num%10;
                sum += dig;

                num = num/10;
            }
            ans = min(sum, ans);
        }
        return ans;
    }
};