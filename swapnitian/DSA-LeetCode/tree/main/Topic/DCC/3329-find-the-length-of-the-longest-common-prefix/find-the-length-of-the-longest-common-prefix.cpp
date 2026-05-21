class Solution {
void solve(vector<int>&arr , set<string>&st){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        string num = to_string(arr[i]); 

        for(int i = 1; i <= (int)num.size(); i++){
            string val = (num.substr(0 , i));
            st.insert(val);
        }
    }
}
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        set<string> st1 , st2;

        solve(arr1 , st1);
        solve(arr2 , st2);

        int ans = 0;

        for(auto it : st1){
            if(st2.find(it) != st2.end()){
                ans = max(ans , (int)it.size());
            }
        }
        return ans;
    }
};