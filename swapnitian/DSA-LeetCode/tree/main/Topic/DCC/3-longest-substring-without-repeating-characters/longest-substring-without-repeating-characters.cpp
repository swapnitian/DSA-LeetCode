class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        int n = s.size();
        unordered_map<int,int> mp;

        int l = 0; int ans = 0;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;

            while(mp[s[i]] > 1){
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, i-l+1);
        }
        return ans;
   }
};