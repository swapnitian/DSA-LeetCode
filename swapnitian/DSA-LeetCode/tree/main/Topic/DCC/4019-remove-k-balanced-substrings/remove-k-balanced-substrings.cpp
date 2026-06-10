class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.size();
        string ans = "";

        // in this we will solve by stack and we will immediately remove the group as we found 

        for(int i = 0; i < n; i++){
            ans += s[i];
            int sz = ans.size();

            if(sz >= 2*k){
                // now check the last group of k size should be ) and from starting it would be (
                bool f1 = true;
                for(int j = 0; j < k; j++){
                    if(ans[sz-2*k + j] != '('){
                        f1 = false;
                        break;
                    }
                }
                for(int j = sz-1; j >= sz-k; j--){
                    if(ans[j] != ')'){
                        f1 = false;
                        break;
                    }
                }
                if(f1){
                    ans.resize(sz-2*k);
                }
            }
        }
        return ans;
    }   
};