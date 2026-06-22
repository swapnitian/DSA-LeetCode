class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mp;
        for(auto it : s){
            mp[it]++;
        }
        int ans = 0;
        while(true){
            int len = 0;
            for(int i = 0; i < (int)target.size(); i++){
                mp[target[i]]--;
                len++;
                if(mp[target[i]] < 0) return ans;

            }
            if(len == (int)target.size()) ans++;
        }
        
        return 0;
    }
};