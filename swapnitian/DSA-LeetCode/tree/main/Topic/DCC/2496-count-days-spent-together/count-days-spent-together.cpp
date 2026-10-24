class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        
        int stdaysA  = days[stoi(arriveAlice.substr(0,2))-1] + stoi(arriveAlice.substr(3,2));
        int lastdaysA = days[stoi(leaveAlice.substr(0,2))-1] + stoi(leaveAlice.substr(3,2));
        int stdaysB  = days[stoi(arriveBob.substr(0,2))-1] + stoi(arriveBob.substr(3,2));
        int lastdaysB = days[stoi(leaveBob.substr(0,2))-1] + stoi(leaveBob.substr(3,2));

        if(lastdaysB < stdaysA || stdaysB > lastdaysA) return 0;

        int ans = min(lastdaysB, lastdaysA) - max(stdaysB, stdaysA) + 1;
        return ans;
    }
};