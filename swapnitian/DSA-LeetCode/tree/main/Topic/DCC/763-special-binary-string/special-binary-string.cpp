class Solution {
// this is best recursion problem as no need of base case 
public:
    string makeLargestSpecial(string s) {
        int sum = 0 ;
        int start = 0 ; // this will track the idx -- 

        vector<string> specials ;

        for(int i = 0 ; i < (int)s.length() ; i++){
            sum += s[i] == '1' ? 1 : -1 ;

            if(sum == 0){ // means we found the special we need to find another spec. str. in this 
                string inner = s.substr(start+1 , i - start - 1) ;
                specials.push_back("1"+makeLargestSpecial(inner)+"0") ;
                start = i+1 ; // update as we will start from next ;
            }
        }
        sort(specials.rbegin() , specials.rend()) ;
        string ans = "" ;
        for(auto str : specials){
            ans += str ;
        }
        return ans ; // best special strring which is largest lexico...
    }
};