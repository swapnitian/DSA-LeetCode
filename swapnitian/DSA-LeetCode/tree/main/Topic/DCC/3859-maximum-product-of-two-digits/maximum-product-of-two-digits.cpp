class Solution {
public:
    int maxProduct(int n) {
        int dig1 = -1; int dig2 = -1;
        while(n > 0){
            int currdig = n%10;
            if(currdig > dig1){
                dig2 = dig1;
                dig1 = currdig;
            }else if(currdig > dig2){
                dig2 = currdig;
            }
            n /= 10;
        }
        return dig1*dig2;
    }
};