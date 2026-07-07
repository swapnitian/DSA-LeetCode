class Solution {
    using ll = long long;
public:
    long long sumAndMultiply(int n) {
        ll pow = 1;
        ll num = 0; ll sum = 0;
        while(n > 0){
            ll dig = n%10;
            n /= 10;

            if(dig == 0) continue;
            
            sum += dig;
            num = (pow*dig) + num;
            pow *= 10;
        }
        return (num*sum);
    }
};