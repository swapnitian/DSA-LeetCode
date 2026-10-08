class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int cntO = 0;
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cntO++;

                if(cntO > 1) ans.push_back('(');
            }else{
                cntO--;

                if(cntO > 0) ans.push_back(')');
            }
        }

        return ans;
    }
};