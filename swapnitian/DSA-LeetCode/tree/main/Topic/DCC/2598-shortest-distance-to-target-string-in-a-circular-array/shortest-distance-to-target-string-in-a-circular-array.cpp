class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        // will go once forward and backward 
        int k = n;
        int idx = startIndex;
        while(k--){
            if(words[idx] == target) ans = min(ans , (n-startIndex+idx)%n);

            if(idx == n-1) idx = -1;
            idx++;
        }
        idx = startIndex;
        k = n;
        while(k--){
            if(words[idx] == target) ans = min(ans , (startIndex-idx+n)%n);
            
            if(idx == 0) idx = n;
            idx-- ;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};