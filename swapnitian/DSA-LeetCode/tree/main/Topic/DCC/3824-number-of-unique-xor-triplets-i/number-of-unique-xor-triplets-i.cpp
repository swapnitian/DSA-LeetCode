class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return n;

        int val = 2;

        while(val <= n){
            val *= 2;
        }

        return val;
    }
};