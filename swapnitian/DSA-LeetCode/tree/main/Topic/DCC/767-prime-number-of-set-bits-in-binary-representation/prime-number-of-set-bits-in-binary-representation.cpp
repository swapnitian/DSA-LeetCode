class Solution {
private:
    bool prime(int n){
        if(n == 1 || n ==0) return false;
        if(n == 2) return true ;

        for(int i = 2 ; i*i<=n ; i++){
            if(n%i == 0) return false;
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0 ;
        while(left <= right){
            int bits = __builtin_popcount(left);
            
            if(prime(bits))ans++ ;

            left++ ;
        }
        return ans ;
    }
};