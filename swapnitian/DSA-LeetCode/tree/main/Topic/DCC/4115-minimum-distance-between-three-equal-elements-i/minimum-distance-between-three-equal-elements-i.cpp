class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>> list(101) ;

        for(int i = 0 ; i < nums.size() ; i++){
            list[nums[i]].push_back(i) ;
        }
        int min_distance = INT_MAX ;
        for(int i =1 ; i <= 100 ; i++){
            if(list[i].size() < 3) continue ;
            for(int j = 0 ; j < list[i].size()-2 ; j++){
                int a = list[i][j] ;
                int b = list[i][j+1] ;
                int c = list[i][j+2] ;

                int distance = abs(a-b) + abs(b-c) + abs(c-a) ;
                min_distance = min(min_distance , distance) ;
            }

        }
        return min_distance == INT_MAX ? -1 : min_distance ;
    }
};