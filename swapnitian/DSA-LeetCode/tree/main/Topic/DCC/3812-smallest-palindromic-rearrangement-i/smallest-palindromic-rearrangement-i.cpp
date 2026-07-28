class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        string st = "";
        string mid = "";
        
        for(auto it : s){
            freq[it-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) continue;

            if(!(freq[i]&1)){
                int no = freq[i]/2;
                st.append(no, i+'a');
            }else{
                int no = freq[i]/2;
                st.append(no, i+'a');
                mid.push_back(i+'a');
            }
        }
        string ans = st + mid;
        reverse(st.begin(), st.end());
        ans = ans + st;
        return ans;
    }
};