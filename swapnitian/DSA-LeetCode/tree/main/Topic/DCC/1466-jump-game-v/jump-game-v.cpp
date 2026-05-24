class Solution {
int recursion(vector<int>& arr, int idx, int d, int n,vector<int>&dp){
    int jump1 = 0;
    int jump2 = 0;

    if(dp[idx] != -1) return dp[idx];

    // choice 1 (to move i + x)
    // choice 2 (to move i - x)
    bool f1 = true;
    bool f2 = true;

    for(int i = 1; i <= d; i++){
        if(idx+i < n){
            if(f1 && (arr[idx] > arr[idx+i])){
                jump1 = max(jump1 , 1 + recursion(arr, idx+i, d, n,dp));
            }else{
                f1 = false;
            }
        }
    }
    for(int i = 1; i <= d; i++){
        if(idx-i >= 0){
            if((f2) && (arr[idx] > arr[idx-i])){
                jump2 = max(jump2 ,1 + recursion(arr, idx-i, d, n,dp));
            }else{
                f2 = false;
            }
        }
    }
    return dp[idx] = max(jump1 , jump2);
}
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 0;
        vector<int> dp(n+1 , -1);

        for(int i = 0; i < n; i++){
            ans = max(ans , recursion(arr,i,d,n,dp));
        }

        return ans+1;
    }
};