class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size() ;
        int cnt1 = 0 ;
        for(int i = 0 ; i < n ; i++)if(s[i] == '1') cnt1++ ;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0' && cnt1 != 0) return false ;
            if(cnt1 == 0) break ;

            cnt1-- ;
        }
        return true ;
    }
};