class Solution {
public:
    int mirrorDistance(int n) {
        int n1 = n;
        int n2 = 0;
        while(n > 0) {
            int dig = n%10;
            n2 = n2*10 + dig;
            n /= 10;
        }
        return abs(n1-n2) ;
    }
};