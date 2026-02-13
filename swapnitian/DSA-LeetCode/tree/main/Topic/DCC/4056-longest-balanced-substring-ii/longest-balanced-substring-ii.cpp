class Solution {
private:
    void helper(string &s , char x , char y , int &maxi){
        int n = s.size() ;

        unordered_map<int,int> m;
        m[0] = -1 ;
        int sum = 0 ; // this sum will help to find  2 distinct balanced subarray 

        for(int i =0 ; i < n ; i++){
            if(s[i] == x){
                sum += 1 ;
            }else if(s[i] == y){
                sum -= 1 ; 
            }else{
                m.clear() ;
                m[0] = i ;
                sum = 0 ;

                continue ;
            }

            if(m.find(sum) != m.end()){
                maxi = max(maxi , i -m[sum]) ;
            }else{
                m[sum] = i ;
            }
        }
    }
public:
    int longestBalanced(string s) {
        // this problem is good for implementation we will solve as the hint says to solve it 
        int n = s.size() ;
        int maxi = -1 ;
        int curr = 1 ;
        
        // case -> 1 -- IF ALL THE CHARACTERS ARE SAME 
        for(int i = 1 ; i < n ; i++){
            if(s[i] == s[i-1]){
                curr++ ;
            }else{
                maxi = max(maxi , curr) ;
                curr = 1 ;
            }
        }
        maxi = max(maxi , curr) ; // edge case

        // Case -> 2 -- IF THEY HAVE 2 DISTINCT CHARACTERS FOR THAT WE WILL MAKE AN FUNCTION
        helper(s , 'a' , 'b' , maxi) ;
        helper(s , 'a' , 'c' , maxi) ;
        helper(s , 'b' , 'c' , maxi) ;


        // Case -> 3 -- IF THE ALL FREQUENCY ARE SAME --
        map<pair<int,int>,int> m ;
        m[{0,0}] = -1 ; // this is when all three freq are same from starting ;
        vector<int> freq(3 , 0) ;
        for(int i = 0 ; i < n ; i++){
            freq[s[i]-'a']++ ;

            int countAB = freq[0] - freq[1] ;
            int countBC = freq[0] - freq[2] ;

            if(m.find({countAB , countBC}) != m.end()){
                maxi = max(maxi , i - m[{countAB , countBC}]) ;
            }else{
                m[{countAB , countBC}] = i ;
            }
        }
        return maxi ;
    }
};