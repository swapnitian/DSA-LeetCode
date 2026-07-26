class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n1 = series1.size();
        int n2 = series2.size();
    
        int pt1 = 0; int pt2 = 0;

        vector<vector<int>> ans;
        while(pt1 < n1 && pt2 < n2){
            if(series1[pt1][0] == series2[pt2][0]){
                ans.push_back({series1[pt1][0], series1[pt1][1] + series2[pt2][1]});
                pt1++; 
                pt2++;
            }else if(series1[pt1][0] < series2[pt2][0]){
                ans.push_back({series1[pt1][0], series1[pt1][1] + series2[pt2][1]});
                pt1++;
            }else {
                ans.push_back({series2[pt2][0], series1[pt1][1] + series2[pt2][1]});
                pt2++;
            }
        }

        while(pt1 < n1) {
            ans.push_back({series1[pt1][0], series1[pt1][1]});
            pt1++;
        }
        while(pt2 < n2) {
            ans.push_back({series2[pt2][0], series2[pt2][1]});
            pt2++;
        }

        return ans;
    }
};