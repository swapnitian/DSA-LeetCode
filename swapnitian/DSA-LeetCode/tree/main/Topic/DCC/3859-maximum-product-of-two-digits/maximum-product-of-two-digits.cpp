class Solution {
public:
    int maxProduct(int n) {
        vector<int> dig(10, 0);
        while(n > 0){
            dig[n%10]++;
            n /= 10;
        }
        int cnt = 2;
        int maxi = 1;
        for(int i = 9; i >= 0; i--){
            if(dig[i] > 0 && cnt){
                if(dig[i] > 1 && cnt == 2){
                    maxi = i*i;
                    cnt -= 2;
                }else{
                    maxi *= i;
                    cnt--;
                }
            }
        }
        
        return maxi;
    }
};