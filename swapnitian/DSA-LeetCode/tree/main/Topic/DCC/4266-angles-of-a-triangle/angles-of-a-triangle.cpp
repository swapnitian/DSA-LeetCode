class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin() , sides.end());

        double a = sides[0] ; double b = sides[1] ; double c = sides[2]; 

        if(a + b <= c) return {};

        double A = acos((b*b + c*c - a*a)/(2*b*c));
        double B = acos((c*c + a*a - b*b)/(2*a*c));
        double C = acos((b*b + a*a - c*c)/(2*b*a));

        cout << A << " " << B <<  " " << C ;

        A = A * 180/M_PI;
        B = B * 180/M_PI;
        C = C * 180/M_PI;

        return {A , B , C};
    } 
};