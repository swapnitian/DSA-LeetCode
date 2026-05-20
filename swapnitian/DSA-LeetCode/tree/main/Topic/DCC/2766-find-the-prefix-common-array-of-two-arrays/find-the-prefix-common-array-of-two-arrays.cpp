class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int>st;
        vector<int> C(n);

        int cnt = 0;
        for(int i = 0; i < n; i++){

            if(st.count(A[i]))cnt++;
            else st.insert(A[i]);

            if(st.count(B[i]))cnt++;
            else st.insert(B[i]);   
            
            C[i] = cnt;
        }   

        return C ;
    }
};