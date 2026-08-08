class Solution {
    using ll = long long;
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end());

        for(int i = n-2; i >= 0; i--){
            maximumHeight[i] = min(maximumHeight[i], maximumHeight[i+1]-1);
        }
        ll sum = 0;
        for(int i = 0; i < n-1; i++){
            if(maximumHeight[i] == 0||maximumHeight[i] == maximumHeight[i+1]) return -1;

            cout << maximumHeight[i] << " ";
            sum += maximumHeight[i];
        }

        cout << maximumHeight.back() << endl;
        sum += maximumHeight.back();
        return sum;
    }
};