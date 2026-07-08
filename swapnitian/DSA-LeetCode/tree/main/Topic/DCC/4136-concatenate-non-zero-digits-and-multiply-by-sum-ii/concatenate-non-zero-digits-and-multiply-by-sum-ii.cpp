class Solution {
public:
    using ll = long long;
    int mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> digitSum(n+1, 0);
        vector<ll> numbers(n+1, 0);
        vector<ll> cntNonZero(n+1, 0);
        vector<ll> pow10(n+1, 1);

        // building digit sum which is similar as prefix sum
        for(int i = 1; i <= n; i++){
            // digitsum ->
            digitSum[i] = (digitSum[i-1] + (s[i-1]-'0'))%mod;
        
            // NonZeroDigit->
            cntNonZero[i] = cntNonZero[i-1] + (((s[i-1]-'0') != 0) ? 1 : 0);

            // Making the pow10 in which we will store the power of 10
            pow10[i] = (pow10[i-1]*10)%mod;
        }

        // building numbers that will represenet number to idx required from 0idx
        for(int i = 1; i <= n; i++){
            ll dig = s[i-1]-'0';
            if(dig == 0){
                numbers[i] = numbers[i-1];
                continue;
            }
            numbers[i] = (numbers[i-1]*10 + dig)%mod;
        }
        vector<int>res;

        for(auto it : queries){
            int l = it[0]; int r = it[1];
            int k = cntNonZero[r+1] - cntNonZero[l];

            ll x = (numbers[r+1] - numbers[l]*pow10[k]%mod + mod)%mod;

            ll sum = (digitSum[r+1] - digitSum[l]);

            res.push_back((x*sum)%mod);
        }

        return res;
    }
};