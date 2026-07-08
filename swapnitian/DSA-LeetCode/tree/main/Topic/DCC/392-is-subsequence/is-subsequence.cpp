class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        int j = 0;
        for(int i = 0; i < n1; i++){
            bool ok = false;

            while(j < n2){
                if(t[j] == s[i]){
                    j++;
                    ok = true;
                    break;
                }
                j++;
            }
            if(!ok) return false;
        }
       
        return true;
    }
};