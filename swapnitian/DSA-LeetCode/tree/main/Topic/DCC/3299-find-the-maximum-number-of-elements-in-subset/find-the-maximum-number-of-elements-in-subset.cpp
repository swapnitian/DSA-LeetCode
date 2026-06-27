class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        int ans = (mp[1]&1) ? mp[1] : mp[1]-1;
        mp.erase(1);

        // in this problem we are solving like in increasing we will the squre of  previous number 
        for(auto it : mp){
            long long x = it.first;
            int cnt = 0;

            while(mp.contains(x) && mp[x] > 1){
                cnt += 2;
                x *= x;
            }

            ans = max(ans , cnt + (mp.contains(x) ? 1 : -1));
        }
        return ans;
    }
};