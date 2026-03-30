class Solution {
public:
    bool checkStrings(string s1, string s2) {
        multiset<char> odd1 , odd2 ;
        multiset<char> even1 , even2 ;
        int n = s1.size() ;
        
        for(int i = 0 ; i < n ; i++){
            if(i&1){
                odd1.insert(s1[i]) ;
                odd2.insert(s2[i]) ;
            }else{
                even1.insert(s1[i]) ;
                even2.insert(s2[i]) ;
            }
        }

        return ((odd1 == odd2) && (even1 == even2)) ;
    }
};