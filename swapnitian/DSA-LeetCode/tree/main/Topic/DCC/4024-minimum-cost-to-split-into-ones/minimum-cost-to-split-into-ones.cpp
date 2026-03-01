class Solution {
public:
    int minCost(int n) {
        int cost = 0 ;
        while(n > 1){
            int a = 1 ;
            int b = n-a ; 

            cost += a*b ;
            n-- ;
        }
        return cost ;
    }
};