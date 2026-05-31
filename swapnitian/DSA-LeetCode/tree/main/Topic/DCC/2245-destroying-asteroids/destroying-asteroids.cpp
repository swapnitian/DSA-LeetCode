class Solution {
using ll = long long;
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        ll pmass = mass*1LL;
        sort(asteroids.begin() , asteroids.end());

        for(int i = 0; i < n; i++){
            if(pmass < asteroids[i]) return false;
        
            pmass += asteroids[i];
        }

        return true;
    }
};