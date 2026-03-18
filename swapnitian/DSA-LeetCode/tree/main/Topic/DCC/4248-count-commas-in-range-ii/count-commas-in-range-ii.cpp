class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0 ;

        if(n >= 1000 && n < 1e6) return n-1000 +1 ;
        else if(n >= 1e6 && n < 1e9) return 2*(n-1e6)+(1e6-1000)+2 ;
        else if(n >= 1e9 && n < 1e12) return 3*(n-1e9)+2*(1e9-1e6)+(1e6-1000)+3 ;
        else if(n >= 1e12 && n < 1e15) return 4*(n-1e12)+3*(1e12-1e9)+2*(1e9-1e6)+(1e6-1000) + 4 ;
        
        return  4*(n-1e12)+3*(1e12-1e9)+2*(1e9-1e6)+(1e6-1000) + 5 ;
    }
};