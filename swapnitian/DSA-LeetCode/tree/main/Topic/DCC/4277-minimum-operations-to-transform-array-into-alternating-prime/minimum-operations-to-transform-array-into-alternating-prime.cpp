class Solution {
public:
using ll = long long ;
    int minOperations(vector<int>& nums) {
        vector<bool> isprime(5e5+1 , true);
        isprime[0] = isprime[1] = false ;
        vector<int> prime ;
        for(ll i = 2 ; i <= 5e5 ; i++){
            if(isprime[i]){
                for(ll j = i*i ; j <= 5e5 ; j += i){
                    isprime[j] = false ;
                }
            }
        }
        for(int i = 0 ; i < isprime.size() ; i++){
            if(isprime[i]){
                prime.push_back(i) ;
            }
        }
        int n = nums.size(); 
        int operations = 0; 

        for(int i = 0; i < n; i++){
            if(i%2 == 0){
                if(!isprime[nums[i]]){
                    auto it = lower_bound(prime.begin() , prime.end() , nums[i]) ;

                    operations += (*it -nums[i]) ;
                }
            }else{
                if(isprime[nums[i]]){
                    operations++ ;

                    if(nums[i] == 2) operations++ ;
                }
            }
        }

        return operations ;
    }
};