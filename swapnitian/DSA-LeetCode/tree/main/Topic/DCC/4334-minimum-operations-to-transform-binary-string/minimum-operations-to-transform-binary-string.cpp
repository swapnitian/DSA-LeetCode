class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();

        if(n == 1){
            if(s1[0] == '1' && s2[0] == '0') return -1;
            else if(s1[0] == '0' && s2[0] == '1') return 1;
            else return 0;
        }
        int operations = 0;
        for(int i = 0; i < n-1; i++){
            if(s1[i] == s2[i]) continue;

            if(s1[i] == '0' && s2[i] == '1'){
                s1[i] = '1';
                operations++;
            }else{
                if(s1[i+1] == '1'){
                    if(s2[i] == '0' && s2[i+1] == '0'){
                        s1[i] = '0';
                        s1[i+1] = '0';
                        operations++;
                    }else{
                        s1[i] = '1';
                        operations += 2;
                    }
                }else{
                    if(s2[i] == '0' && s2[i+1] == '0'){
                        s1[i] = '0';
                        operations += 2;
                    }else{
                        s1[i] = '0';
                        s1[i+1] = '1';
                        operations += 3;
                    }
                }
            }
        }

        if(s1[n-1] != s2[n-1]){
            if(s1[n-1] == '0' && s2[n-1] == '1'){
                operations++;
            }else{
                operations += 2;
            }
        }
        return operations;
    }
};