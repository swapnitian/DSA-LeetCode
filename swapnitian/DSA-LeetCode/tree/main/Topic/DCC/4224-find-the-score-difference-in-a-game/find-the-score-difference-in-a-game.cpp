class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size() ;
        int p1 = 0 ; int p2 = 0 ;
        bool status = false ; // false will tell player 2 is inactive ;
        for(int i = 0 ; i <n  ; i++){
            if((nums[i]&1)){
                if(!status){
                    status = true ;
                }else{
                    status = false ;
                }
            }
            if((i+1)%6 == 0){
                if(!status){
                    status = true ;
                }else{
                    status = false ;
                }
            }
            if(status) p2 += nums[i] ;
            else p1 += nums[i] ;
        }
        return p1-p2 ;
    }
};