class Solution {
    void recursion(string s , int idx , vector<string>&v){
        if(idx < 0){
            v.push_back(s) ;
            return ;
        }

        // choice 1 ;
        s[idx] = '0' ;
        recursion(s , idx-1 , v) ;
        // choice 2 ;
        s[idx] = '1' ;
        recursion(s , idx-1 , v) ;
        
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size() ;
        string s = "" ;
        s.append(n , '0') ;
        vector<string>v ;
        recursion(s , n-1 , v) ;

        for(auto it : v){
            if(count(nums.begin() , nums.end() , it) == 0) return it ;
        }
        // cout << endl;

        return "" ;
    }
};