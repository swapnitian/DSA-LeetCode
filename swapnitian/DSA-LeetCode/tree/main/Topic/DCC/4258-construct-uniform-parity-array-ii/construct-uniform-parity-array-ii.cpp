class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size() ;
        vector<int> odd;
        
        for(int i = 0 ; i < n ; i++){
            if(nums1[i]&1)odd.push_back(nums1[i]) ;
        }

        // making all even
        sort(odd.begin() , odd.end()) ;        
        bool flag = true ;
        for(int i = 0 ; i < n ; i++){
            if(!(nums1[i]&1)){
                if(odd.size() > 0 && nums1[i] <= odd[0]){
                    flag = false ;
                    break ;
                }
            }
        }
        // making all odd
        
        bool flag2 = true ;
        for(int i = 0 ; i < n ; i++){
            if(nums1[i]&1){
                if(odd.size() > 0 && nums1[i] <= odd[0]){
                    flag2 = false ;
                    break ;
                }
            }
        }
        
        return (flag|flag2) ;
    }
};