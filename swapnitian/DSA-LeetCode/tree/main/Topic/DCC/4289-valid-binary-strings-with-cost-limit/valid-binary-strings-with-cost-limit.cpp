class Solution {
    vector<string>ans;
    void recursion(int idx, int k, int n, string s, int cost,int prev){
        if(idx == n){
            ans.push_back(s);
            return;
        }
        // we have two choice either place 1 or 0  according k cost
        if(cost+idx <= k && !prev){
            recursion(idx+1, k, n, s + '1', cost + idx, 1);
        }
        recursion(idx+1, k, n, s + '0', cost, 0);
    }
    
public:
    vector<string> generateValidStrings(int n, int k) {
        recursion(0,k,n,"",0,0);

        return ans;
    }
};