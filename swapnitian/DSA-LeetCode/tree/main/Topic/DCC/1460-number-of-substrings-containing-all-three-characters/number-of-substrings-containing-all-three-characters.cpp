class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int pos[3] = {-1, -1, -1};
        // 0idx -> 'a' , 1idx -> 'b , idx2 -> 'c' ;
        int ans = 0;
        // for(int i = 0; i < n; i++){
        //     if(s[i] == 'a') pos[0] = i;
        //     else if(s[i] == 'b') pos[1] = i;
        //     else pos[2] = i;

        //     if(pos[0] != -1 && pos[1] != -1 && pos[2] != -1){
        //         int mini = min({pos[0], pos[1], pos[2]});
        //         ans += 1 + mini;
        //     }
        // }


        // 2nd Approach ->>  S L I D I N G __ W I N D O W -
        int cnt = 0;
        int freq[3] = {0};
        int len = s.size();
        int left = 0; int right = 0;

        while(right < len){
            freq[s[right] - 'a']++;

            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                cnt += len-right;

                freq[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        return cnt;
    }
};