class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size() ;
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            string no = to_string(nums[i]) ;

            for(int j = 0 ;  j < no.size() ; j++){
                if(no[j]-'0' == digit) cnt++ ;
            }
        }
        return cnt ;
    }
};