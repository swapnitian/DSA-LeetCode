class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        int cnt0 = count(s.begin(), s.end(), '0');
        int cnt1 = n - cnt0; 

        // since we know to make the same string we have to ensure that is cnt0 and cnt1 should be same in both string also 0 can be shift to right but 1 can never so seeing this ovservation we solve the problem
 
        vector<bool> ans;

        for(auto &it : strs){
            int cnt0_it = count(it.begin(), it.end(), '0');
            int cnt1_it = count(it.begin(), it.end(), '1');

            bool check = true;
            for(int i = 0; i < n; i++){
                if(it[i] == '?'){
                    if(cnt0_it < cnt0){
                        it[i] = '0';
                        cnt0_it++;
                    }
                    else if(cnt1_it < cnt1){
                        it[i] = '1';
                        cnt1_it++;
                    }
                }
            }

            // now we will check the prefix of cnt1 in both string,
            // as we know we can shift the 0 to left and 1 to right
            // but we never shift the 1 to left using sort operations 
            // therfor, when we found cnt1s > cnt1it return false;

            if((cnt1_it != cnt1) || (cnt0 != cnt0_it)){
                ans.push_back(false);
                continue;
            }
            cout << it << endl;
            int pref_cnt1_s = 0;
            int pref_cnt1_it = 0;

            for(int j = 0; j < n; j++){
                if(s[j] == '1') pref_cnt1_s++;
                if(it[j] == '1') pref_cnt1_it++;

                if(pref_cnt1_s < pref_cnt1_it){
                    ans.push_back(false);
                    check = false;
                    break;
                }
            }
            if(check) ans.push_back(true);
        }

        return ans;
    }
};