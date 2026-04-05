class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.size() ;
        unordered_map<char ,int> m ;
        
        for(int i = 0 ; i < n ; i++){
            m[s[i]]++ ;
        }
        set<pair<char,char>> st ;
        int ans = 0 ; 
            
        for(int i = 0 ; i < n ; i++){
            char c ;
            if(islower(s[i])) c = (26 - (s[i]-'a' + 1))%26 + 'a' ;
            else c = (10 - (s[i]-'0' + 1))%10 + '0' ;
            
            if(st.find({c , s[i]}) == st.end()){
                st.insert({c , s[i]}) ;
                st.insert({s[i] , c}) ;
                
                ans += abs(m[c] - m[s[i]]) ;
            }
        }
        // char c = (10 - ('3'-'0' + 1))%10 + '0' ;
        // cout << c << endl;
        return ans ;
    }
};