class Solution {
private:
    bool check (string &s){
        int n = s.size() ;
        for(int i = 0 ; i < n-1 ; i++){
            if(s[i] == s[i+1]) return false ;
        }
        return true ;
    }
    int solve(string s , char c){
        int n = s.size() ;
        int operations = 0 ;
        if(s[0] != c){
            operations = 1 ;
        }
        s[0] = c ;
        for(int i = 1 ; i < n ; i++){
            if(s[i] == s[i-1]){
                if(s[i-1] == '0') s[i] = '1' ;
                else s[i] = '0' ;

                operations++ ;
            }
        }
        cout << s << " " << operations << endl;
        return operations ;
    }
public:
    int minOperations(string s) {
        if(check(s)) return 0 ;
        
        return min(solve(s , '0') , solve(s ,'1')) ;
    }
};