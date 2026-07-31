class Solution {
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int Count_Subarrays(string &word, int k){
        int n = word.size();
        unordered_map<char,int> mp;
        int l = 0;
        int Cnt_Subarrays = 0;

        for(int r = 0; r < n; r++){
            if(!isVowel(word[r])){
                l = r+1;
                mp.clear();
                continue;
            }
            mp[word[r]]++;

            while(mp.size() > k){
                mp[word[l]]--;

                if(mp[word[l]] == 0) mp.erase(word[l]);

                l++;
            }

            Cnt_Subarrays += (r - l + 1);
        }
        return Cnt_Subarrays;
    }
public:
    int countVowelSubstrings(string word) {
        return Count_Subarrays(word, 5) - Count_Subarrays(word, 4);
    }
};