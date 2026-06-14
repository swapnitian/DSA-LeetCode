class Solution {
using ll = long long;
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        ll ans = 0;

        ll mini_max = 1e18; 
        ll mini = 1e18;
        for(auto &it : units){
            sort(it.begin() , it.end());
            
            if(n == 1) ans += it[0];
            else{
                ans += it[1];
                mini_max = min(mini_max , 1LL*it[1]);
                mini = min(mini , 1LL*it[0]);
            }
        }
        if(n == 1) return ans;

        ans = ans - mini_max + mini;

        return ans;
    }
};