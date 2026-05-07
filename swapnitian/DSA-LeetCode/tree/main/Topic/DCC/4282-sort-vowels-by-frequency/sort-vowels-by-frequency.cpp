class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<vector<int>> v(26, vector<int>(3 , 0));

        for(int i = 0; i < 26; i++){
            v[i][0] = 0;
            v[i][1] = -1;
            v[i][2] = i;
        }

        for(int i = 0; i < n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
                   || s[i] == 'o' || s[i] == 'u'){
                        int val = s[i]-'a';
                        if(v[val][1] == -1) v[val][1] = i;

                        v[val][0]++;
            }
        }   
        sort(v.begin() , v.end() , [] (vector<int> &a , vector<int> &b){
            if(a[0] != b[0]) return a[0] > b[0];

            return a[1] < b[1] ;
        });

        int j = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
                   || s[i] == 'o' || s[i] == 'u'){
                    
                    if(v[j][0] == 0) j++;

                    s[i] = 'a'+ v[j][2];
                    v[j][0]--;
            }
        }

        return s ;
    }
};