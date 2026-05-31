class Solution {
    vector<string> ans;
private:
    void recursion(string &s, vector<string>&nums, int idx, int n, 
    string letter){

        if(idx == n){
            cout << letter << endl;
            ans.push_back(letter);
            return ;
        }
        int no = s[idx]-'0';
        
        for(int i = 0; i < (int)nums[no].size(); i++){
            recursion(s, nums, idx+1, n, letter + nums[no][i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> nums(10) ;

        nums[2] = "abc";
        nums[3] = "def";
        nums[4] = "ghi";
        nums[5] = "jkl";
        nums[6] = "mno";
        nums[7] = "pqrs";
        nums[8] = "tuv";
        nums[9] = "wxyz";

        string letter = "";
        recursion(digits, nums, 0, n, letter);
        return ans;
    }
};