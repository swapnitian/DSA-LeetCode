class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // APPROACH -1 -> (Use the extra space and act as stack)
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),[] (vector<int>&a , vector<int>&b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        ans.push_back({intervals[0][0], intervals[0][1]});

        // APPROACH -2 -> since the data is sorted so we can compare the max value of right range 
        int maxi = intervals[0][1];
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(maxi >= intervals[i][1]) cnt++;
            else{
                maxi = intervals[i][1];
            }
        }
        return (n-cnt);
    }
};