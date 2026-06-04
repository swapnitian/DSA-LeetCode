class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness = 0;
        while(num1 <= num2){
            string s = to_string(num1);
            int n = s.size();

            for(int i = 1; i < n-1; i++){
                if(s[i] > s[i-1] && s[i] > s[i+1]){
                    waviness++;
                }else if(s[i] < s[i-1] && s[i] < s[i+1]){
                    waviness++;
                }
            }
            num1++;
        }

        return waviness;
    }
};