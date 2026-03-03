class Solution {
private:
    void invert(string &s){
        int n = s.size();
        for(int i= 0 ; i<n ; i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0' ;
        }
    }
public:
    char findKthBit(int n, int k) {
        // if( k == 1) return '0' ;

        string s = "0" ;

        for(int i = 1 ; i < n ; i++){
            string help = s ;
            invert(help) ; 
            reverse(help.begin() , help.end()) ;
            s += '1' + help ;
        }
        return s[k-1];
    }
};