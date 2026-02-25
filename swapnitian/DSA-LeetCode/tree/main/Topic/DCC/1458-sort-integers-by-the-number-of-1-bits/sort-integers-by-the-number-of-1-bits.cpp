class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size() ;
        vector<vector<int>>v(32) ;
        for(int i = 0 ;i < n ; i++){
            int bits = __builtin_popcount(arr[i]) ;
            v[bits].push_back(arr[i]) ;
        }
        for(auto &vector : v){
            sort(vector.begin() , vector.end()) ;
        }
        vector<int> ans ;
        for(int i = 0 ; i < v.size() ; i++){
            for(int j = 0 ; j < v[i].size() ; j++){
                cout << v[i][j] << " " ;
            }
            cout << endl;
        }
        for(int i = 0 ; i < v.size() ; i++){
            for(int j = 0 ; j < v[i].size() ; j++){
                ans.push_back(v[i][j]) ;
            }
        }
        return ans ;
    }
};