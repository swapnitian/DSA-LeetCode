class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.size();

        vector<pair<char,int>> st; // will use as a stack

        for(int i = 0; i < n; i++){
            if(!st.empty() && st.back().first == s[i]){
                st.back().second += 1;
            }else{
                st.push_back({s[i] , 1});
            }
            int sz = st.size();

            if(sz >= 2 && st[sz-1].first == ')' && st[sz-1].second >= k && 
                st[sz-2].first == '(' && st[sz-2].second >= k){

                st[sz-2].second -= k;

                st.pop_back();

                if(st[sz-2].second == 0){
                    st.pop_back();
                }
            }
        }
        string ans = "";
        for(int i = 0; i < (int)st.size(); i++){
            ans = ans.append(st[i].second,st[i].first);
        }

        return ans;
    }
};