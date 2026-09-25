class Solution {
public:
    int countRotations(string s, int k) {
        // observation based 
        int n = s.size();

        int cnt_pair = (s[n-1] == s[0] ? 1 : 0);
        for(int i = 0; i < n; i++){
            if(s[i] == s[i+1]) cnt_pair++;
        }

        if(cnt_pair == k) return n - cnt_pair;
        else if(cnt_pair-1 == k) return cnt_pair;

        return 0;
    }
};