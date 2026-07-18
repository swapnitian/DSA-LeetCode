class Solution {
using ll = long long;
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;

        ll even_pos = n/2;
        ll odd_pos = (n-2)/2;

        ll ans = s + (even_pos*m) - (odd_pos);
        return ans;
    }
};