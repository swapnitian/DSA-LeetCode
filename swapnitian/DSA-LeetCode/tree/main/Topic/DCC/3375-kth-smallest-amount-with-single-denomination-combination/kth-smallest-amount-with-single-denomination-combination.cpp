class Solution {
    using ll = long long;
    ll CountLeftSmallest(vector<int> &coins, ll mid){
        int n = coins.size();
        ll totalcount = 0;
        // in this we are finding the set theory using the formula
        // to find the remaining element to its left simple divide the mid 
        for(int term = 1; term <= (1 << n) - 1; term++){
            ll lcm = 0; 
            ll order = 0; // it will help us to add or subtract

            for(int i = 0; i < n; i++){
                if(term & (1 << i)){ // this find the ith count
                    order++;

                    if(lcm == 0) lcm = coins[i];
                    else lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                }
            }
            if(order & 1) totalcount += mid/lcm;
            else totalcount -= mid/lcm;
        }

        return totalcount;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        ll st = 1;
        ll end = 1LL*(*max_element(coins.begin(), coins.end()))* k;

        ll ans = -1;    
        while(st <= end){
            ll mid = st + (end-st)/2;

            if(CountLeftSmallest(coins, mid) >= k){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return ans;
    }
};