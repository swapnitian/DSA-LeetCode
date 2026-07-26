class Solution {
public:
    int largestInteger(int n, int s) {
        int lt;
        if(n == 1) lt = 9;
        if(n == 2) lt = 99;
        if(n == 3) lt = 999;
        if(n == 4) lt = 9999;
        if(n == 5) lt = 99999;

        int maxi = -1;
        for(int num = 0; num <= lt; num++){
            int dig_sum = 0;
            int val = num;
            while(val > 0){
                dig_sum += val%10;
                val /= 10;
            }
            if(dig_sum == s){
                maxi = max(maxi, num);
            }
        }

        return maxi;
    }
};