class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        int cnt0 = 0; int cnt1 = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') cnt1++;
            if(s[i] == '0') cnt0++;

            if(cnt1 == cnt0){
                ans++;
            }else if(abs(cnt1 - cnt0) == 1){
                ans++;
            }
        }

        return ans;
    }
};