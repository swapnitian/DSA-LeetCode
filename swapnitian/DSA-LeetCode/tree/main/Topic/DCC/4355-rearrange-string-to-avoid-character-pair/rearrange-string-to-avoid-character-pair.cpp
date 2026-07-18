class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string s1 = "", s2 = "";

        for(auto it : s){
            if(it == y){
                s1 += it;
            }else{
                s2 += it;
            }
        }

        return s1 + s2;
    }
};