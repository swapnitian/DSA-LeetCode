class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;

        for(auto it : nums){
            if(it > maxi1){
                maxi2 = maxi1;
                maxi1 = it;
            }else if(it > maxi2){
                maxi2 = it;
            }
        }

        return (maxi1-1)*(maxi2-1);
    }
};