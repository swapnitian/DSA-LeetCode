class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> Leftmax(n);
        vector<int> Rightmin(n);

        Leftmax[0] = nums[0];
        Rightmin[n-1] = nums[n-1];

        for(int i = 1; i < n; i++){
            Leftmax[i] = max(Leftmax[i-1] , nums[i]);
        }
        
        for(int i = n-2; i >= 0; i--){
            Rightmin[i] = min(Rightmin[i+1] , nums[i]);
        }
        // Trarverse from the right to left to tackle the 2nd Case--
        vector<int> ans(n);
        ans[n-1] = Leftmax[n-1];

        for(int i = n-2; i >= 0; i--){
            if(Leftmax[i] <= Rightmin[i+1]) {
                ans[i] = Leftmax[i];
            }else {
                ans[i] = ans[i+1];
            }
        }
        return ans;
    }
};