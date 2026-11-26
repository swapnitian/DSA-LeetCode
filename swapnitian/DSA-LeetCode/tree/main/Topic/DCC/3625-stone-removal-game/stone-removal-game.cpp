class Solution {
public:
    bool canAliceWin(int n) {
        int stone = 10;
        while(n >= stone){
            n -= stone;

            stone--;
        }
        return (stone&1) ? true : false;
    }
};