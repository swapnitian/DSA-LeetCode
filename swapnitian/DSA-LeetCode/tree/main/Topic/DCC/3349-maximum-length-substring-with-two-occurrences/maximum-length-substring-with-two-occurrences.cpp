class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int l = 0;
        int maxi = 0;
        for(int r = 0; r < n; r++){
            mp[s[r]]++;
            
            while(mp[s[r]] > 2){
                mp[s[l]]--;

                if(mp[s[r]] == 0) mp.erase(s[r]);

                l++;
            }

            maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};