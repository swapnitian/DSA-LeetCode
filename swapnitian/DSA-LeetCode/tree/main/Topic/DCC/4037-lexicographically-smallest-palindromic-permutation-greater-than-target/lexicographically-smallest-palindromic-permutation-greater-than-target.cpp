class Solution {
public:
    string ans = "";
    int len = 0;
    char mid  = '.';
    bool solve(string curr, string &target, int idx, bool greater, vector<int> &freq){
        if(idx == len){
            string check = curr;
            if(mid != '.') check.push_back(mid);
            reverse(curr.begin(), curr.end());
            check += curr;

            if(check > target){
                ans = check;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(freq[ch-'a'] == 0) continue;

            if(greater == false && ch < target[idx]) continue;

            curr.push_back(ch);
            freq[ch-'a']--;

            bool isgreater = (greater) || (ch > target[idx]);

            if(solve(curr, target, idx+1, isgreater, freq)) return true;

            curr.pop_back();
            freq[ch-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++){
            freq[s[i]-'a']++;
        }

        int cntodd = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i]&1){
                cntodd++;
                mid = i+'a';
            }
        }
        if(cntodd > 1) return "";

        len = target.size()/2;

        for(int i = 0; i < 26; i++){
            freq[i] /= 2;
        }
        return (solve("", target, 0, false, freq)) ? ans : "";
    }
};