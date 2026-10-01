class Solution {
public:
    bool isValid(string s) {
        stack <char> st ;

        for(char ch : s){
            if( ch == '[' || ch == '{' || ch == '(') { // store all the open brackets 
                st.push(ch) ;
            } else {// closing brackets 
                if( st.size() == 0) return false ;

                if( ch == ']' && st.top() == '['
                    || ch == '}' && st.top() == '{'
                     || ch == ')' && st.top() == '(') {
                    st.pop() ;
                } else {
                    return false ;
                }
            }
        }
        return st.empty() ;
    }
};