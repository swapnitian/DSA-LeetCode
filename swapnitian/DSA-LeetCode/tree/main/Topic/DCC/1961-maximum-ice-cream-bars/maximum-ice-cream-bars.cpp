class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        long long sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += costs[i];
            if(sum <= coins) ans++;
            else break;
        }

        return ans;
    }
};