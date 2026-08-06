class Solution {
public:
    int smallestNumber(int n, int t) {
        int lt = n+10;
        int ans = INT_MAX;
        while(n <= lt){
            int num = n;
            int prod = 1;
            while(num > 0){
                prod *= (num)%10;
                num /= 10;
            }
            if(prod%t == 0) ans = min(ans, n);

            n++;
        }

        return ans;
    }
};