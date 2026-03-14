class Solution {
private:
    bool check(string &s){
        for(int i = 0 ; i < s.size()-1 ; i++){
            if(s[i] == s[i+1]) return false ;
        }
        return true ;
    }
    void solve(int n, int idx , string &s , vector<string>&st){
        if(idx > n) return ;
        if(idx == n){
            st.push_back(s) ;
            return ;
        }
        for(char c = 'a' ; c <= 'c' ; c++){
            s += c ;
            if(check(s)){
                solve(n , idx+1 , s , st) ;
            }
            s.pop_back() ;
        }
    }   
public:
    string getHappyString(int n, int k) {
        vector<string> st ;
        string s = "" ;
        solve(n,0,s,st); 

        // for(auto it : st){
        //     cout << it << " " ;
        // }
        // cout << endl;
        sort(st.begin() , st.end()) ;
        if(st.size() < k) return "" ;
        return st.size() == 0 ? "" : st[k-1] ;
    }
};