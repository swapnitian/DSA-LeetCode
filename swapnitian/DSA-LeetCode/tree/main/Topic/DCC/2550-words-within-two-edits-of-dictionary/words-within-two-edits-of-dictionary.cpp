class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = queries[0].size();

        // will use brute force
        vector<string>ans;

        for(int i = 0; i < n; i++) {
            string word = queries[i];
            for(int j = 0; j < (int)dictionary.size(); j++) {
                int cnt = 0;
                for(int k = 0; k < m; k++){
                    if(word[k] != dictionary[j][k]) cnt++;
                }

                if(cnt <= 2) {
                    ans.push_back(word);
                    break;
                }
            }
        }

        return ans;
    }
};