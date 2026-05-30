class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> v;

        for(auto it : intervals){
            if(v.size() == 0){
                v.push_back({it[0],it[1]});
                continue;
            }
            int sz = v.size();
            int l = v[sz-1][0]; int r = v[sz-1][1];

            if((it[0] >= l && it[0] <= r) || (it[1] >= l && it[1] <= r)){
                v[sz-1][0] = min(l , it[0]);
                v[sz-1][1] = max(r , it[1]);
            }else{
                v.push_back({it[0], it[1]});
            }
        }
        return v;
    }
};