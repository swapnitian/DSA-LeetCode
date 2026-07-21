class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = 0;

        int prevcnt = -1;
        int max_cnt = 0;
        for(int i = 0; i < n; i++){
            int cnt0 = 0;
            while(i < n && s[i] == '0'){
                cnt0++;
                i++;
            }   
            if(s[i] == '1') cnt1++;

            if(cnt0 == 0) continue;

            if(prevcnt != -1 )max_cnt = max(max_cnt, cnt0+prevcnt);
            
            prevcnt = cnt0;
        }
        
        return max_cnt+cnt1;
    }
};