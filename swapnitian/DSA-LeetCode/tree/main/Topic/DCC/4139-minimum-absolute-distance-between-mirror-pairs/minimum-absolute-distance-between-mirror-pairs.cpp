class Solution {

private:

    int reverse_integer(int num){
        string s = to_string(num) ;
        reverse(s.begin() , s.end()) ;

        return stoi(s) ;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int,int> m ;

        int ans = INT_MAX ;

        for(int i = n-1 ; i >= 0 ; i--){
            int rev_val = reverse_integer(nums[i]) ;

            if(m.find(rev_val) != m.end()){
                ans = min(ans , abs(i - m[rev_val])) ;
            }
            m[nums[i]] = i ;
        }
        return ans == INT_MAX ? -1 : ans ;
    }
};