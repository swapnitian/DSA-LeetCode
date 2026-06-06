class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long bulb = 0;
        
        bulb = brightness/3;
        brightness = brightness%3;
        
        if(brightness > 0) bulb++;
        
        // now to handle the overlapping the interval 
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;

        for(auto it : intervals){
            if(v.size() == 0){
                v.push_back({it[0] , it[1]});
                continue;
            }
            int sz = v.size();
            int l = v[sz-1][0]; int r = v[sz-1][1];
            if((it[0] <= r && it[0] >= l) || (it[1] >= l && it[1] <= r)){
                v[sz-1][0] = min(l , it[0]);
                v[sz-1][1] = max(r , it[1]);
            }else{
                v.push_back({it[0], it[1]});
            }
        }
        long long ans = 0;
        for(auto it : v){
            ans += bulb*(it[1]-it[0]+1);
        }

        return ans;
    }
};