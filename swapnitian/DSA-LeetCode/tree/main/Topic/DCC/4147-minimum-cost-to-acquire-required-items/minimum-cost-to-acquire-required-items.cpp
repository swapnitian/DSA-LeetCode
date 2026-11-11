class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long maxboth = max(need1 , need2)*1LL * costBoth*1LL ;
        long long noboth = (long long)need1*cost1*1LL + (long long)need2*cost2*1LL ;
        long long overlap = min(need1 , need2) ;

        long long totalcost = overlap * costBoth + (need1-overlap)*cost1*1LL + 
                                    (need2-overlap)*cost2*1LL ;

        long long onlyboth = (long long)max(need1 , need2) * costBoth ;
        return min({noboth , totalcost , onlyboth}) ;
    }
};