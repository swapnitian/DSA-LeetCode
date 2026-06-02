class Solution {
public:
    int earliestFinishTime(vector<int>& l1, vector<int>& l2, vector<int>& w1, vector<int>& w2) {
        
        int sum1 = INT_MAX ; int sum2 = INT_MAX ;
        for(int i = 0 ; i < l1.size() ; i++){
            sum1 = min(sum1 , (l1[i]+l2[i])) ;
        }
        for(int i = 0 ; i < w1.size() ; i++){
            sum2 = min(sum2 , (w1[i]+w2[i])) ;
        }
        int ans = INT_MAX ;

        for(int i = 0 ; i < w1.size() ; i++){

            if(sum1 >= w1[i]){
                ans = min(ans , sum1+w2[i]) ;
            }else{
                ans = min(ans , sum1 + w1[i] - sum1 + w2[i]) ;
            }
        }

        for(int i = 0 ; i < l1.size() ; i++){

            if(sum2 >= l1[i]){
                ans = min(ans , sum2+l2[i]) ;
            }else{
                ans = min(ans , sum2+ l1[i] - sum2 + l2[i]) ;
            }
        }
        return ans ;

    }
};