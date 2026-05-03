class Solution {
public:
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin() , s.end());

        int r = stoi(s);
    
        // will generate the prime number;

        vector<int> prime;
        prime.push_back(2) ;
        for(int i = 3 ; i <= 2000 ; i++){
            bool f1 = true;
            for(int j = 2 ; j*j <= i ; j++){
                if(i%j == 0){
                    f1 = false;
                    break;
                }
            }
            if(f1) prime.push_back(i);
        }

        int mini = min(n , r);
        int maxi = max(n , r);

        int idx = lower_bound(prime.begin() , prime.end() , mini) - prime.begin();
        int idx2 = upper_bound(prime.begin() , prime.end() , maxi) - prime.begin(); 
        cout << idx << endl;

        long long sum = 0 ;
            
        while(idx < idx2){
            sum += prime[idx];
            idx++ ;
        }
        
        return sum ;
    }
};