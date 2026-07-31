class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for(auto trip : trips){
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];
        
            diff[from] += passengers;

            if(to <= 1000) diff[to] -= passengers;
        }
        vector<int> arr(1001, 0);
        arr[0] = diff[0];
        for(int i = 1; i < 1001; i++){
            arr[i] = diff[i] + arr[i-1];
        }

        for(int i = 0; i < 1001; i++){
            if(arr[i] > capacity) return false;
        }

        return true;
    }
};