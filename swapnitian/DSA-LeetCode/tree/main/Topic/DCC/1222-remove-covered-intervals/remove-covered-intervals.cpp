class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        set<pair<int,int>> s;
        
        for(int i = 0; i < n-1; i++){
            int a = intervals[i][0]; int b = intervals[i][1];

            for(int j = i+1; j < n; j++){
                int c = intervals[j][0]; int d = intervals[j][1];

                if(a == c && b <= d){
                    s.insert({a,b});
                }else if(d <= b){
                    s.insert({c,d});
                }
            }
        }
        return n - s.size();
    }
};