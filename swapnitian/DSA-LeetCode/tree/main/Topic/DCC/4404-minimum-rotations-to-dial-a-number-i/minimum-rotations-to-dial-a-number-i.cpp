class Solution {
public:
    int minRotations(string s) {
        int prev = 0;
        int ans =  0;
        for(int i = 0; i < 10; i++){
            int dig = s[i] - '0';
            ans += min({10 - prev + dig, 10 - dig + prev, abs(prev - dig)});
            prev = dig;
        }
        return ans;
    }
};