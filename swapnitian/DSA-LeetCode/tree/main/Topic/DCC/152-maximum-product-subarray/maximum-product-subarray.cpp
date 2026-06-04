class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int p1 = 1;
        int p2 = 1; 
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            p1 *= nums[i];
            p2 *= nums[i];

            ans = max(p1, ans);
            ans = max(p2, ans);

            if(p1 == 0){
                p1 = 1;
            }
            if(p2 <= 0){
                p2 = 1;
            }
        }
        p1 = 1; p2 = 1;
        for(int i = n-1; i >= 0; i--){
            p1 *= nums[i];
            p2 *= nums[i];

            ans = max(p1, ans);
            ans = max(p2, ans);

            if(p1 == 0){
                p1 = 1;
            }
            if(p2 <= 0){
                p2 = 1;
            }
        }
        return ans;
    }
};