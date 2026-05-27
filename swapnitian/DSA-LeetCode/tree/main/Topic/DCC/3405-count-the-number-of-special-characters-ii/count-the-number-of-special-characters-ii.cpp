class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        
        vector<int> freq1(26, 0);
        vector<int> curr(26 , 0) , ismarked(26 , 0);

        for(int i = 0; i < n; i++){
            if(word[i] >= 'a' && word[i] <= 'z') freq1[word[i] - 'a']++;
        }

        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                int idx = word[i]-'A';

                if(freq1[idx] == 0) continue;

                if(!ismarked[idx] && curr[idx] == freq1[idx]){
                    ismarked[idx] = 1;
                    ans++;
                }else{
                    ismarked[idx] = 1;
                }
            }else{
                curr[word[i]-'a']++;
            }
        }
        
        return ans;
    }
};