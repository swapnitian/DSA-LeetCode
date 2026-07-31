class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(auto it : word){
            freq[it-'a']++;
        }
        sort(freq.rbegin(), freq.rend());

        int no = 1;
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) break;

            if(i != 0 && i%8 == 0) no++;
            
            ans += freq[i]*no;
        }

        return ans;
    }
};