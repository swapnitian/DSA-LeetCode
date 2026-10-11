class Solution {
public:
    int minRotations(int n, string s) {
        int prev = 0;
        int ans =  0;
        for(int i = 0; i < n; i++){
            int dig = s[i] - '0';
            ans += min({10 - prev + dig, 10 - dig + prev, abs(prev - dig)});
            prev = dig;
        }
        // calculate by applying reverse operation
        int val = ans;
        for(int i = 0; i < n; i++){
            int dig = s[i] - '0';

            if(i == n-1){
                ans = min({val - min(10 - (s[0] -'0'), s[0]-'0') + min(10-dig, dig),ans});
                continue;
            }

            int curr = min({10 - dig + (s[i+1]-'0'), 10 - (s[i+1]-'0') + dig, abs(dig - (s[i+1] - '0'))});
        
            int New = min({10 - dig + s[n-1] - '0', 10 - (s[n-1] -'0') + dig, abs(dig - (s[n-1] - '0'))});
        
            ans = min(val - curr + New, ans);
        }

        return ans;
    }
};