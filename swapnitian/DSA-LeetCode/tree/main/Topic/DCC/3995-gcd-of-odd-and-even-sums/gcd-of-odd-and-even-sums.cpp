class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum = (n*(2 + 2*(n-1)))/2;
        int evensum = (n*(4 + 2*(n-1)))/2;

        return gcd(evensum, oddsum);
    }
};