class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        vector<int> last_idx(26, 0);
        vector<bool> taken(26, 0);

        for(int i = 0; i < n; i++){
            last_idx[s[i]-'a'] = i;
        }

        for(auto it : last_idx){
            cout << it << " ";
        }
        cout << endl;
        string ans = "";
        ans.push_back(s[0]);
        taken[s[0]-'a'] = true;
        for(int i = 1; i < n; i++){
            if(ans.back() > s[i] && taken[s[i]-'a'] == false){
                char c = ans.back();
                while(ans.size() > 0 && ans.back() > s[i] && last_idx[ans.back()-'a'] > i){
                    taken[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                if(!taken[s[i]-'a']){
                    ans.push_back(s[i]);
                    taken[s[i]-'a'] = true;
                }
            }else if(!taken[s[i]-'a']){
                taken[s[i]-'a'] = true;
                ans.push_back(s[i]);
            }
        }
        // cout << ans.back() << endl;
        return ans;
    }
};