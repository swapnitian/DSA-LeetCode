class Solution {
private:
    int countwalls(vector<int>& walls , int left , int right) {
        // in this we use binary_search -- -- >

        int count = upper_bound(walls.begin() , walls.end() , right) - 
                    lower_bound(walls.begin() , walls.end() , left) ;

        return count ;
    }

    int solve(vector<int>& walls , vector<pair<int,int>>&robodist ,vector<pair<int,int>>& range , int idx , int prevdir , vector<vector<int>>& dp){
        
        if(idx == robodist.size()) return 0;

        if(dp[idx][prevdir] != -1) return dp[idx][prevdir] ;

        int left_start = range[idx].first ; // default left range ;

        if(prevdir == 1){ // means prev ones fired to right direction so our left maychange
            left_start = max(left_start , range[idx-1].second + 1) ;
        }

        int left_take = countwalls(walls , left_start , robodist[idx].first) 
                            + solve(walls , robodist , range , idx+1 , 0 ,dp);

        // same we will find for right_start ;

        int right_take = countwalls(walls , robodist[idx].first , range[idx].second) 
                            + solve(walls , robodist , range , idx+1 , 1 ,dp) ;

        return dp[idx][prevdir] = max(left_take , right_take) ;
    }
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size() ;

        // this question is hard but when we breakdown all the path seems connected 
        // at first draw the line and placed the rob and wall on there and then we see
        // the obervation who can destroy or not from that sorting clicks in the mind

        // then we find the range of each query , left and right robot how much can go

        // then we got a choice whether we should fire the bullet to left or right!! 

        // so simply in our mind comes that is recursion

        // for that we will make the robotdist and range 

        vector<pair<int,int>> robodist(n) ;
        vector<pair<int,int>> range(n) ;

        for(int i = 0 ; i < n ; i++){
            robodist[i] = {robots[i] , distance[i]} ;
        }

        sort(robodist.begin() , robodist.end()) ;
        sort(walls.begin() , walls.end()) ;

        for(int i = 0 ; i < n ; i++){
            int pos = robodist[i].first ;
            int d   = robodist[i].second ;

            int left_limit  = (i == 0)   ? 1 : robodist[i-1].first + 1 ; 
            int right_limit = (i == n-1) ? 1e9 : robodist[i+1].first - 1 ;

            left_limit  = max(left_limit  , pos-d) ;
            right_limit = min(right_limit , pos+d) ;

            range[i] = {left_limit , right_limit} ;
        }
        // here we are assuming the 0 -> fire from left and 1 -> fire from right 
        
        // memoization -- 

        vector<vector<int>> dp(n+1 , vector<int>(2 , -1)) ;

        return solve(walls , robodist , range , 0 , 0 , dp) ;
    }
};