class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        // two solution one is dp and second one is greeeyd
        int ans = INT_MIN;
        for(int i = n-k; i < n; i++){
            int sum = 0;
            for(int j = i; j >= 0; j = j-k){
                sum += energy[j];
                ans = max(sum , ans);
            }
        }
        return ans;
    }
};