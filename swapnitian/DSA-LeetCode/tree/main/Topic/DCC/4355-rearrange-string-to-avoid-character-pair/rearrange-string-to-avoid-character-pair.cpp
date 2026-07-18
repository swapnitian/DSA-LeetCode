class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.size();
        int cnty = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == y) cnty++;
        }
        if(cnty == 0) return s;

        string ans = "";
        ans.append(cnty, y);

        for(int i = 0; i < n; i++){
            if(s[i] != y) ans.push_back(s[i]);
        }

        return ans;
    }
};