class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size() ;
        stack<int> help ;
        int max_area = INT_MIN ;
        help.push(0) ;

        for(int i = 1 ; i < n ; i++){
            if(nums[i] < nums[help.top()]){
                while(!help.empty() && nums[i] < nums[help.top()]){
                    int val = nums[help.top()] ;
                    help.pop() ;
                    int pse = help.empty() ? -1 : help.top(); // previous smaller element

                    int area = val * (i - pse - 1) ;
                    max_area = max(area , max_area) ;
                }
                help.push(i) ;
            }else{
                help.push(i) ;
            }
        }
        while(!help.empty()){
            int val = nums[help.top()] ;
            help.pop() ;
            int pse = !help.empty() ? help.top() : -1 ;
            int area = val * (n - pse - 1) ;
            max_area = max(area , max_area) ;
        }
        return max_area ;
    }
};