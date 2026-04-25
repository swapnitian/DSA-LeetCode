class Solution {
public:
    int compareBitonicSums(vector<int>& arr) {
        int n = arr.size();
        long long sum1 = 0 , sum2 = 0;
        bool f1 = true;

        for(int i = 0; i < n-1; i++){
            if(f1 && arr[i] < arr[i+1]){
                sum1 += arr[i];
            }else if(arr[i] > arr[i+1]){
                if(f1) sum1 += arr[i];

                sum2 += arr[i];
                f1 = false;
            }
        }
        sum2 += arr[n-1];

        cout << sum1 << " " <<  sum2 << endl;
        if(sum1 > sum2) return 0;
        else if(sum1 < sum2) return 1;

        return -1;
    }
};