class Solution {
bool recursion(vector<int>& arr,int idx,vector<int>&vis , int n){

    if(idx < 0 || idx >= n) return false;

    vis[idx] = 1;
    if(arr[idx] == 0) return true;

    // left we will check
    int lt = idx-arr[idx]; 
    bool left = false;
    if(lt >= 0 && vis[lt] == 0){
        left = recursion(arr, lt , vis , n);
    }
    int rt = idx + arr[idx];
    bool right = false;

    if(rt < n && vis[rt] == 0){
        right = recursion(arr , rt , vis , n);
    }
    return (right || left);
}
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n , 0);

        return recursion(arr , start , vis , n);
    }
};