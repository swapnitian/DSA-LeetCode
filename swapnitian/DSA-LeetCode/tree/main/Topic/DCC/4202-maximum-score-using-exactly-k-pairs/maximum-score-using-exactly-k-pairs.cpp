class Solution {
private:
    long long recursion(vector<int>& nums1, vector<int>& nums2, int k , 
                int n , int m ,int idx1 , int idx2 ,vector<vector<vector<long long>>> &dp){
        if(k == 0) return 0 ;            
        if(idx1 == n || idx2 == m) return -1e17;

        if(dp[idx1][idx2][k] != -1e18) return dp[idx1][idx2][k] ;

        long long take = 1LL*nums1[idx1]*1LL*nums2[idx2] 
                            + recursion(nums1,nums2,k-1,n,m,idx1+1,idx2+1,dp); 

        long long not_take = max(recursion(nums1,nums2,k,n,m,idx1+1,idx2,dp) , 
                                    recursion(nums1,nums2,k, n , m , idx1 , idx2+1 ,dp)) ;

        return dp[idx1][idx2][k] = max(take , not_take);
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size() ;
        int m = nums2.size() ;
        // vector<vector<vector<long long>>> dp(n+1 , vector<vector<long long>>(m+1 , vector<long long>(k+1 , -1e18))) ;
        // return recursion(nums1 , nums2 , k , n , m , 0 , 0 , dp) ;
        
        
        // now try to do by tabulation that top to bottom ;

        vector<vector<vector<long long>>> dp(n+1 , vector<vector<long long>>(m+1 , vector<long long>(k+1 , -1e18))) ;
        // for n 
        for(int j = 0 ; j <= m ; j++){
            for(int t = 1 ; t <= k ; t++){
                dp[n][j][t] = -1e17 ;
            } 
        }
        // for m
        for(int i = 0 ; i <= n ; i++){
            for(int t = 1 ; t <= k ; t++){
                dp[i][m][t] = -1e17 ;
            } 
        }
        // for k = 0 ;
        for(int i = 0 ; i <= n; i++){
            for(int j = 0 ; j <= m ; j++){
                dp[i][j][0] = 0 ;
            }
        }

        //  T A B U L A T I O N _  P A R T - -

        for(int idx1 = n-1 ; idx1 >= 0 ; idx1--){
            for(int idx2 = m-1 ; idx2 >= 0 ; idx2--){
                for(int t = k ; t > 0 ; t--){
                    long long take = 1LL*nums1[idx1]*nums2[idx2] + dp[idx1+1][idx2+1][t-1] ;

                    long long not_take = max(dp[idx1+1][idx2][t] , dp[idx1][idx2+1][t]) ;

                    dp[idx1][idx2][t] = max(take , not_take) ;
                }
            }
        }   
        return dp[0][0][k] ;
    }
};