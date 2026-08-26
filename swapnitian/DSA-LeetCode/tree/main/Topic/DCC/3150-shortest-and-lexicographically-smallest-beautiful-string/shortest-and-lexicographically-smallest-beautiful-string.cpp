class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i <= n-k; i++){
            int cnt1 = 0;
            while(s[i] == '0') i++;

            for(int j = i; j < n; j++){
                if(s[j] == '1') cnt1++;

                if(cnt1 > k) break;

                if(cnt1 == k){
                    string t = s.substr(i, j-i+1);
                    cout << i << " : " << t << endl;

                    if(ans.size() == 0) ans = t;
                    else if(ans.size() == t.size()){
                        if(ans > t) ans = t;
                    }else if(ans.size() > t.size()){
                        ans = t;
                    }
                }
            }
        }
        return ans;
    }
};