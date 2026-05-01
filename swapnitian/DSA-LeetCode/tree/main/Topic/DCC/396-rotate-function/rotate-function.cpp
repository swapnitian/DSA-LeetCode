class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        // in this problem we solve the equation and then we got the answers 

        // precalculate the sum and F ;
        int sum = 0 ; int F = 0 ;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        
            F = F + (i*nums[i]);
        }
        int ans = INT_MIN;
        for(int k = 0; k < n; k++){
            int newF = F + sum - (n*nums[n-1-k]) ;
        
            ans = max(ans , newF);
        
            F = newF ;
        }

        return ans;
    }
};