class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();

        for(int i = 0; i < n-1; i++){
            int v1 = (s[i]-'0');
            int v2 = (s[i+1]-'0');
        
            int diff = abs(v1- v2);

            if(diff > 2) return false;
        }
        return true;
    }
};