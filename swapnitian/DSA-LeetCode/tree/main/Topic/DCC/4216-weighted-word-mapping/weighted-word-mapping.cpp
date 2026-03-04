class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size() ;
        string ans = "" ;
        for(int i = 0 ; i < n ; i++){
            int wt = 0 ;
            for(int j = 0 ; j < words[i].size() ; j++){
                wt += weights[words[i][j]-'a'] ;
            }
            wt = wt%26 ;
            ans += char((25-wt) + 'a') ;
        }
        return ans ;
    }
};