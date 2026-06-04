class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int p1 = nums[0]; int p2 = nums[0]; 
        int ans = nums[0];

        for(int i = 1; i < n; i++){
            int val = max({nums[i], p1*nums[i], p2*nums[i]});

            p2 = min({nums[i], p1*nums[i], p2*nums[i]});

            p1 = val;
            cout << i << " " << p1 << " " << p2 << endl;
            ans = max(ans , p1);
        }
        return ans;
    }
};