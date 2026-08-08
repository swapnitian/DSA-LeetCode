class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
    
        // we should to take care of the Suffix count match characters how many we are having for that we will create an array

        vector<int> RightMatch(n1, 0);
        int idx2 = n2-1;
        int rightcnt = 0;
        for(int idx1 = n1-1; idx1 >= 0; idx1--){
            if(idx2 > 0 && word1[idx1] == word2[idx2]){
                rightcnt++;
                idx2--;
            }
            RightMatch[idx1] = rightcnt;
        }
        
        // Now we have the suffix cnt so we will move from left -> right to find where we are getting same char
        //  --> it can be on same idx so we will use definitely
        //  --> or we can use change power on that idx by checking suff cnt
        //  --> just move forward if both two condition not satisfied;

        vector<int> ans(n2, n1);
        idx2 = 0;
        bool used = false;

        for(int idx1 = 0; idx1 < n1; idx1++){
            if(idx2 < n2 && word1[idx1] == word2[idx2]){
                ans[idx2] = idx1;
                idx2++;
            }else if(idx2 < n2 && used == false){
                if(idx1+1 < n1 && RightMatch[idx1+1] >= n2-idx2-1){
                    ans[idx2] = idx1;
                    idx2++;
                    used = true;
                }else if(idx1 == n1){
                    ans[idx2] = idx1;
                    idx2++;
                }
            }
        }

        for(int i = 0; i < n2; i++){
            if(ans[i] == n1) return {};
        }
        return ans;
    }
};