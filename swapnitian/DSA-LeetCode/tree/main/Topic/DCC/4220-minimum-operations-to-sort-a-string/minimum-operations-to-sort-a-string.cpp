class Solution {
public:
    int minOperations(string s) {
        int n = s.size() ;
        string copy = s ;
        sort(copy.begin() , copy.end()) ;

        if(s == copy) return 0 ;
        if(n == 2) return -1 ;

        if(s[0] == copy[0] || s[n-1] == copy[n-1]) return 1 ;

        string s2 = s ;
        
        sort(s.begin() , s.end()-1) ;
        sort(s.begin()+1 , s.end()) ;

        sort(s2.begin()+1 , s2.end()) ;
        sort(s2.begin() , s2.end()-1) ;
        
        if(s == copy || s2 == copy) return 2 ;
        
        return 3 ;
    }
};