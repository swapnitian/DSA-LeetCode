class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGcd(n,0);
        
        long long maxi = -1;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]*1LL);

            prefixGcd[i] = gcd(maxi, 1ll*nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        for(int i = 0; i < n/2; i++){
            sum += gcd(prefixGcd[i], prefixGcd[n-i-1]);
        }

        return sum;
    }
};