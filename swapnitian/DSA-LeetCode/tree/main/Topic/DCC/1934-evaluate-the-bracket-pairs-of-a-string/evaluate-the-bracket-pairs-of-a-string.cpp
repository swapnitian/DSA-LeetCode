class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        string ans = "";
        unordered_map<string,string> mp;
        
        for(auto it : knowledge){
            mp[it[0]] = it[1];
        }

        for(int i = 0; i < n; i++){
            if(s[i] != '(') ans.push_back(s[i]);
            else{
                string help = "";
                i++;
                while(i < n && s[i] != ')'){
                    help.push_back(s[i]);
                    i++;
                }
                if(mp.count(help)) ans += mp[help];
                else ans.push_back('?'); 
            }
        }
        return ans;
    }
};