class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill5 = 0;
        int bill10 = 0;

        for(auto val : bills){
            if(val == 5) bill5++;
            else if(val == 10){
                if(bill5 > 0){
                    bill5--;
                    bill10++;
                }else return false;
            }else{
                if(bill10 == 0){
                    if(bill5 > 2){
                        bill5 -= 3;
                    }else{
                        return false;
                    }
                }else{
                    bill10--;
                    if(bill5 > 0) bill5--;
                    else return false;
                }
            }
        }

        return true;
    }   
};