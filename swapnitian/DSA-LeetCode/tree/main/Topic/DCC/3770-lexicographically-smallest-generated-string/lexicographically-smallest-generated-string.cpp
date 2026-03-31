class Solution {
private:
    bool isSame(string &word , string &str2 , int i , int m){

        for(int j = 0 ; j < m ; j++){
            if(word[i] != str2[j]){
                return false ;
            }
            i++ ;
        }
        return true ;
    }
public:
    string generateString(string str1, string str2) {
        // in this problem we divide the process to solve as when we have T means we have
        // to make the word from that idx same as str2 of m size -- 

        // 2. As we have to make the word lexicographically smaller then we are just filling with everything with a (temporary) in future we can change this if need -- 

        // 3. Now we will deal with F in that we have that is we can change or if 
        //    clashes with word existing then we are not able to make 

        int n = str1.size();
        int m = str2.size();

        int N = n + m - 1;

        string word(N , '.') ; // initializes with random word

        vector<bool> canChange(N , false) ; // this will tell whether i am able to change it or not

        // 1. Processing the T 
        for(int i = 0 ; i < n ; i++){
            if(str1[i] == 'T'){
                // here we fill with str2 
                int idx = i;
                for(int j = 0 ; j < m; j++){
                    if(word[idx] != '.' && word[idx] != str2[j]){
                        return "" ;
                    }
                    word[idx] = str2[j] ;
                    idx++ ;
                }
            }
        }

        // 2. we will fill the empty spaces with a and this can be change in future 
        for(int i = 0 ; i < N ; i++) {
            if(word[i] == '.'){
                word[i] = 'a' ;
                canChange[i] = true ;
            }
        }

        // 3. Processing the F 

        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                if(isSame(word , str2 , i , m)){

                    bool changed = false ;
                    for(int k = i+m-1 ; k >= i ; k--){
                        if(canChange[k] == true) {
                            word[k] = 'b' ;
                            changed = true ;
                            break ;
                        }
                    }
                    if(changed == false){
                        return ""; 
                    }
                }
            }
        }    
        return word ;    
    }
};