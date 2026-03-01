class Solution {
public:
    string mergeCharacters(string s, int k) {

        for(int i = 0 ; i < (int)s.size() ; i++){
            int shift = 0 ;
            for(int j = i+1 ; j < (int)s.size() ; j++){
                if(s[i] == s[j]){
                    if((j-shift)-i <= k){
                        s[j] = '.' ;
                        shift++ ;
                        i = 0 ;
                    }
                }
            }
            string help ; 
            for(int k = 0 ; k < (int)s.size() ; k++){
                if(s[k] != '.') help.push_back(s[k]) ;
            }
            s = help ;
        }
        return s ;
    }
};