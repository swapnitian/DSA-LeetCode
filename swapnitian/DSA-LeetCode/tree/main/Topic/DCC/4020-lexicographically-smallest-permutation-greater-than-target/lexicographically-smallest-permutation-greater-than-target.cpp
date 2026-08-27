class Solution {
    string ans = "";
    bool solve(string curr, vector<int>& freq, string &target, int idx, bool greater){
        if(idx == target.size()){
            if(greater){
                ans = curr;
                return true;
            }
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(freq[ch-'a'] == 0) continue;

            if(greater == false && ch < target[idx]) continue;

            curr.push_back(ch);
            freq[ch-'a']--;

            bool isgreater = (greater) || (ch > target[idx]);

            if(solve(curr, freq, target, idx+1, isgreater)) return true;

            curr.pop_back();
            freq[ch-'a']++;
        }

        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26,0);
        int n = s.size();
        for(int i = 0; i < n; i++){
            freq[s[i]-'a']++;
        }

        return (solve("", freq, target, 0, false)) ? ans : "";
    }
};