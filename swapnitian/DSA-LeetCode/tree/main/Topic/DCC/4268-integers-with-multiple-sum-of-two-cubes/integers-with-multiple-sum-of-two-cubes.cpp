class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int>ans ;
        map<long long,long long > m ;
       
        for(long long a = 1 ; a <= 1000 ; a++){
            for(long long b = 1 ; b <= 1000 ; b++){
                long long x = a*a*a + b*b*b ; 
            
                if(x <= n) m[x]++ ;
            }
        }
        for(auto it : m){
            if(it.second > 2){
                cout << it.first << endl;
                ans.push_back(it.first) ;
            }
        }
        return ans ;
    }
};