class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // will try to solve this by two pointer 

        int n = nums.size() ;

        for(int i = 0 ; i <n; i++){
            if(nums[i] < 0){
                nums[i] = -(nums[i]) ;
            }
        }
        sort(nums.begin() , nums.end()) ;

        int lt = 0 ; int rt ;
        if(n%2 == 0)rt = n-1 ;
        else rt = n-2 ;
        
        while(lt < rt){
            swap(nums[lt] , nums[rt]) ;
            lt = lt + 2 ;
            rt = rt - 2 ;
        }
        // now calculate alternating sum 
        long long sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(i%2 == 0) sum += nums[i]*nums[i] ;
            else sum = sum - (nums[i]*nums[i]) ;
        }
        return sum ;
    }
};