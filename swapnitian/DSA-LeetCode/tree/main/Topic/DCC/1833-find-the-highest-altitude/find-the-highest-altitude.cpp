class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int altitude = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            altitude = altitude + gain[i];

            ans = max(altitude , ans);
        }
        return ans;
    }
};