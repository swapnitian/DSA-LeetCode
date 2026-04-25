class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);

        if(s[0]-'0' == x || n < 10) return false;

        for(int i = 1; i < (int)s.size(); i++){
            if(s[i]-'0' == x) return true;
        }
        return false;
    }
};