class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int diff1 = abs(target[0]-start[0]);
        int diff2 = abs(target[1]-start[1]);
    
        if(diff1%2 == 0 && diff2%2 == 0) return true;
        if(diff1&1 && diff2&1) return true;

        return false;
    }
};