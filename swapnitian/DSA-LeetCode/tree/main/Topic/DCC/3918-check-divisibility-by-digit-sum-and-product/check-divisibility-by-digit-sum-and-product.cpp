class Solution {
public:
    bool checkDivisibility(int n) {
        int prod = 1;
        int sum = 0;
        int orgn = n;

        while(n > 0){
            int dig = n%10;
            sum += dig;
            prod *= dig;
            n /= 10;
        }

        return (orgn % (sum + prod) == 0);
    }
};