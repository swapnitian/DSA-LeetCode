class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n);

        for(auto it : bookings){
            int lt = it[0]-1;
            int rt = it[1]-1;
            int seat = it[2];

            diff[lt] += seat;

            if(rt + 1  < n) diff[rt+1] -= seat;
        }
        vector<int> seats(n, 0);
        seats[0] = diff[0];

        for(int i = 1; i < n; i++){
            seats[i] = diff[i] + seats[i-1];
        }
        return seats;
    }
};