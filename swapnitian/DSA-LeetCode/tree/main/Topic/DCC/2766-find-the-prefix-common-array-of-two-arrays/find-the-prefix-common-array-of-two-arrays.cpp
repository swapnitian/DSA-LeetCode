class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int,int> mp;
        vector<int> C(n);

        for(int i = 0; i < n; i++){
            mp[A[i]]++;
            mp[B[i]]++;
            int cnt = 0;
            for(auto it : mp){
                if(it.second == 2)cnt++;
            }

            C[i] = cnt;
        }   

        return C ;
    }
};