class Solution {
    int digsum(int num){
        int sum = 0;
        while(num > 0){
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> copy = nums;

        for(int i = 0; i < n; i++){
            mp[nums[i]] = i;
        }
        sort(nums.begin(), nums.end(), [this](int num1, int num2){
            int dgsum1 = digsum(num1);
            int dgsum2 = digsum(num2);

            if(dgsum1 != dgsum2){
                return dgsum1 < dgsum2;
            }

            return num1 < num2;
        });


        int swap = 0;
        for(int i = 0; i < n; i++){
            int expval  = nums[i];
            int currval = copy[i];

            if(expval == currval) continue;

            int idx = mp[expval];

            copy[i] = expval;
            copy[idx] = currval;

            mp[expval] = i;
            mp[currval] = idx;
            swap++;
        }

        return swap;
    }
};