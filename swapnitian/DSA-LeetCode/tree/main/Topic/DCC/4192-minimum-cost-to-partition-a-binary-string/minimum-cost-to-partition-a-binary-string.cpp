class Solution {
private:
    long long recursion(vector<long long>&prefsum , int &ecost , int &fcost ,int st , int end){
        
        int len = end-st ;
        int cnt1 = prefsum[end]-prefsum[st]  ; 
        long long cost ;

        // if(dp.count({st ,end})) return dp[{st , end}] ;

        if(cnt1 > 0){
            cost = 1LL*ecost*len*cnt1*1LL ;
        }else{
            cost = fcost*1LL ;
        }

        if(len%2 == 0){
            int mid = (st+end)/2 ;
        
            cost = min(cost , recursion(prefsum,ecost ,fcost , st ,mid)+
                                recursion(prefsum,ecost , fcost ,mid , end)) ;
        }
        return cost ;
    }
public:
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size() ; 
        // what will prefix sum will help ? let think about it ---
        vector<long long>prefsum(n+1 , 0) ;
        for(int i = 1 ; i <= n ; i++){
            prefsum[i] = prefsum[i-1]+(s[i-1]-'0') ;
        }
        // for(auto it : prefsum){
        //     cout << it << " " ;
        // }
        // vector<vector<long long>>dp(n+2 , vector<long long>(n+2 , -1)) ;
        // map<pair<int,int>,long long> dp ;
        return recursion(prefsum , encCost , flatCost , 0 , n);
    }
};