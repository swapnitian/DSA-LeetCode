class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(auto it : text){
            if(it == 'b' || it == 'a' || it == 'l' || it == 'o' || it == 'n'){
                mp[it]++;
            }
        }
        if(mp.size() != 5) return 0;

        int ans = 0;
        while(true){
            string word = "balloon";
            int len = 0;
            for(int i = 0; i < 7; i++){
                mp[word[i]]--;
                len++;
                if(mp[word[i]] < 0) return ans;

            }
            if(len == 7) ans++;
        }
        
        return 0;
    }
};