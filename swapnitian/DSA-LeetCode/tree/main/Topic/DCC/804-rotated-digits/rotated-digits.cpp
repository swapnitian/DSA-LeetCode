class Solution {
private:
    int solve(int k) {
        string s = to_string(k);

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '3' || s[i] == '4' || s[i] == '7'){
                return k;
            }else if(s[i] == '6'){
                s[i] = '9';
            }else if(s[i] == '9'){
                s[i] = '6';
            }else if(s[i] == '2'){
                s[i] = '5';
            }else if(s[i] == '5'){
                s[i] = '2';
            }
        }
        return stoi(s);
    }
public:
    int rotatedDigits(int n) {
        
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(solve(i) != i){
                cnt++;
            }
        }

        return cnt;
    }
};