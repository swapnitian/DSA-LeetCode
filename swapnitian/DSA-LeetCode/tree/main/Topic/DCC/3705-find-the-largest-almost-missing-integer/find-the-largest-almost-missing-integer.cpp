class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        unordered_map < int , int > m ;

        int n = nums.size() ;
        int l = n-k ;
        int s = k ;
        for(int i = 0 ; i <= l ; i++){
            int j = i ;

            while( j < k && k <= n){
                m[nums[j]]++ ;
                j++ ;
            }
            k++;
        }

        int Min = INT_MAX ;
        int Max = INT_MIN ;
        for( auto v : m){
            Min = min(v.second , Min) ;

        }

        sort(nums.begin() , nums.end()) ;
        
        if( n == s){
            n--;
            return nums[n] ;
        }
        n--;
        while( n >= 0 ){

            if((m.at(nums[n]) == Min && Min == 1)){
                return nums[n] ;
                break ;
            }
            n--;
        }
        return -1 ;
    }
};