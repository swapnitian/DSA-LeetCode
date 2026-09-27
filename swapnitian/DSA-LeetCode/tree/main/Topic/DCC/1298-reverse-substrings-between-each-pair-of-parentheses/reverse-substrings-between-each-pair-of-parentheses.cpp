class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        string ans = "";
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push(ans.size());
            else if(s[i] == ')'){
                int len = (st.size() == 0) ? 0 : st.top();
                if(!st.empty()) st.pop();

                reverse(ans.begin() + len, ans.end());
            }else{
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};