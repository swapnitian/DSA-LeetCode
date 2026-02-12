class Solution {
private:
    bool balance(vector<int> &freq){

        int MIN = INT_MAX ; int MAX = 0 ;

        for(auto it : freq){
            if(it != 0){
                MIN = min(MIN , it) ;
                MAX = max(MAX , it) ;
            }
        }
        return MIN == MAX ;
    }

public:

    int longestBalanced(string s) {
        int n = s.size() ;
        int max_length = 0 ;

        for(int i = 0 ; i <n ; i++){
            vector<int>freq(26 ,0) ;
            for(int j = i ; j < n ; j++){
                freq[s[j]-'a']++ ;
                if(balance(freq)){
                    max_length = max(max_length, j-i+1) ;
                }
            }
        }

        return max_length ;
    }
};