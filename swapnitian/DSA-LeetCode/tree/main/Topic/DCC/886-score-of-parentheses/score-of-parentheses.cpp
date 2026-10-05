class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> st;
        int n = s.size();

        int score = 0;
        st.push_back(0);
        for(int i = 1; i < n; i++){
            if(s[i] == '('){
                st.push_back(score);
                score = 0;
            }else{
                if(s[i-1] == '('){
                    score = st.back() + 1;
                }else{
                    score = st.back() + 2*score;
                }
                st.pop_back();
            }
        }

        return score;
    }
};