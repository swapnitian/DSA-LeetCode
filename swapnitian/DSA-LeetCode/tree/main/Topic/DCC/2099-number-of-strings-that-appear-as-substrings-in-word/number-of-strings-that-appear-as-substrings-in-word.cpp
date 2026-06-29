class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();
        set<string> st;
        int ans = 0;
        for(int i = 0; i < n; i++){
            string s = "";
            for(int j = i; j < n; j++){
                s += word[j];
                st.insert(s);
            }
        }
        for(auto it : patterns){
            if(st.find(it) != st.end()) ans++;
        }
        return ans;
    }
};