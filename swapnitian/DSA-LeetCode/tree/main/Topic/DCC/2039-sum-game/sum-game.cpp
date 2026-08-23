class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int qmark1 = 0;
        int qmark2 = 0;
        int sum1 = 0; int sum2 = 0;

        for(int i = 0; i < n; i++){
            if(i < n/2){
                if(num[i] == '?') qmark1++;
                else sum1 += num[i] -'0';
            }
            else {
                if(num[i] == '?') qmark2++;
                else sum2 += num[i] -'0';
            }
        }
        if((qmark1+qmark2)& 1) return true;

        cout << sum1 << " " << qmark1 << endl;
        cout << sum2 << " " << qmark2 << endl;

        // now for bob we will check whether we can make leftsum == rightsum
        //  how we derive the eqn -> (2*leftsum + 9*qmark1) == (2*rightsum + 9*mark2) then always the bob win 
        
        return !(2*sum1 + 9*qmark1 == 2*sum2 + 9*qmark2);

    }
};