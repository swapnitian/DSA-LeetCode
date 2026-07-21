class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> zero;
        int cnt1 = 0;
        for(int i = 0; i < n; i++){
            int cnt0 = 0;
            while(i < n && s[i] == '0'){
                i++;
                cnt0++;
            }
            if(s[i] == '1') cnt1++;
            if(cnt0 > 0) zero.push_back(cnt0);
        }
        int ans = 0;
        for(int i = 1; i < (int)zero.size(); i++){
            ans = max(ans, zero[i-1]+zero[i]);
            // cout << zero[i] << " ";
        }

        return ans+cnt1;
    }
};