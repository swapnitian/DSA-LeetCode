class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size() ; 
        unordered_map<string,int> mp ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(words[i].size() < k) continue ;

            string word = words[i].substr(0 , k) ;
            cout << word  << endl;
            mp[word]++ ;
            if(mp[word] == 2) ans++ ;
        }
        return ans ;
    }
};