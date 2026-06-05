class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans = "";
        ans.push_back(num[0]);
        
        for(int i = 1; i < n; i++){
            while(ans.size() > 0 && k > 0 && ans.back() > num[i]){
                k--;
                ans.pop_back();
            }
            ans.push_back(num[i]);
        }
        reverse(ans.begin(), ans.end());
        int idx = ans.size()-1;
        
        while(idx >= 0 && ans[idx] == '0'){
            ans.pop_back();
            idx--;
        }
        reverse(ans.begin(), ans.end());

        while(ans.size() > 0 && k--){
            ans.pop_back();
        }
        
        return (ans.size() == 0) ? "0" : ans;
    }
};