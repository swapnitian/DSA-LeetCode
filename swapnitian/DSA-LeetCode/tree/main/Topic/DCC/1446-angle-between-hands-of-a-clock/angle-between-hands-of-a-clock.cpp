class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourangle = (hour % 12) * 30 + minutes * 0.5;

        double minangle = (minutes* 6);

        double diff = abs(hourangle - minangle);

        return min(diff , 360 - diff);
    }
};