class Solution {
using ll = long long;
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        ll ans = 0;

        for(auto &it : units){
            sort(it.begin() , it.end());

            ans += it[0];
        }
    
        if(n == 1) return ans;

        ll maxi = units[0][1];
        ll mini = units[0][0];
        int idx = 0;
        ans = 0;
        for(int i = 1; i < m; i++){
            if(maxi > units[i][1]){
                maxi = units[i][1];
                idx = i;
            }
            mini = min(mini , 1LL*units[i][0]);
        }   
        cout << idx << endl;
        for(int i = 0; i < m; i++){
            if(i != idx){
                ans += units[i][1];
            }else{
                ans += mini;
            }
        }
        return ans;
    }
};