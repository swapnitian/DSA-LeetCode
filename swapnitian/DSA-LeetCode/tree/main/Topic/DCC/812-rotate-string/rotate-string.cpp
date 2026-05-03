class Solution {
    bool check(int idx , string goal , string &s){
        reverse(goal.begin()+idx , goal.end());
        reverse(goal.begin() , goal.begin()+idx);

        reverse(goal.begin() , goal.end());
    
        return s == goal;
    }
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        if(n != goal.size()) return false;

        int idx ;
        for(int i = 0 ; i < n ; i++){
            if(goal[i] == s[0]){
                if(check(i , goal , s)) return true; 
            }
        }
        return false;
    }
};