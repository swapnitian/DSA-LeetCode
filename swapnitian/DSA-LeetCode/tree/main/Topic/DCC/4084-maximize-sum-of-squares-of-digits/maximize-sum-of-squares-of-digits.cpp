class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        for(int i = 0; i < num; i++){
            if(9 <= sum){
                ans.push_back('9');
                sum -= 9;
            }else{
                ans.push_back(sum + '0');
                sum -= sum;
            }
        }
        return (sum != 0) ? "" : ans;
    }
};