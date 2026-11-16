class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        while(n > k){
            string ans = "";
            for(int i = 0; i < n; i = i+k){
                int sum = 0;
                for(int j = i; j < min(n, i+k); j++){
                    sum += (s[j]-'0');
                }
                ans += to_string(sum);
            }
            n = ans.size();
            s = ans;
        }

        return s;
    }
};