class Solution {
    bool check(string &s, int k){
        int cnt = 0;
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == s[i+1]) cnt++;
        }
        return (cnt == k);
    }       
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            string opr = s.substr(i, n-i) + s.substr(0, i) ;

            if(check(opr, k)) cnt++;
        }

        return cnt;
    }
};