using ll = long long;
class Solution {
bool check(ll mid , int k , ll lt){
    ll ans = 1;

    for(int i = 0; i < k; i++){
        if(ans > lt/mid){
            return false;
        }
        ans *= mid;
    }
    return (ans <= lt) ? true : false;
}
ll helper(int n , int k){
    ll st = 1;
    ll end = n;
    ll ans = 0;
    
    while(st <= end){
        ll mid = st + (end-st)/2;

        // here we need to chekc the nu,ber if it's fit in the kth power 
        
        if(check(mid , k , n)){
            ans = mid;
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}
public:
    int countKthRoots(int l, int r, int k) {
        // what if we apply binary search --

        ll left = helper(l-1 , k);
        ll right = helper(r , k);

        ll ans = right - left;
        if(l == 0) ans++;
        
        return ans ;
    }
};