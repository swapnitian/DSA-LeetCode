class Solution {
vector<string> ans;
void recursion(string s, int cntO, int cntC, int n){
    if(cntO > n || cntC > n) return;

    if(cntO == n && cntC == n){
        ans.push_back(s);
        return;
    }

    if(cntO < n){
        recursion(s+'(' , cntO+1, cntC, n);
    }

    if(cntO > cntC && cntC < n){
        recursion(s+')' , cntO, cntC+1, n);
    }
}
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        recursion(s , 0 , 0 , n);
        
        return ans;
    }
};