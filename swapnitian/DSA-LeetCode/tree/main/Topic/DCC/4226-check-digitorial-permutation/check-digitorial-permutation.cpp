class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> factorials = {1 , 1 , 2, 6 , 24 , 120 , 720 , 5040 , 40320 , 362880} ;
        vector<int> dig1(10 , 0) , dig2(10 , 0) ;
        long long sum = 0 ;
        int orgn = n ;
        while(n > 0){
            int digit = n%10 ;
            n = n/10 ;
            sum += factorials[digit] ;
            dig1[digit] += 1 ;
        }
        cout << sum << endl ;
        while(sum > 0){
            int digit = sum%10 ;
            sum = sum/10 ;
            dig2[digit] += 1 ;
        }
        return (dig1 == dig2) ;
    }       
};